#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Filesys.h"

using namespace std;

Filesys::Filesys(string diskname) : Sdisk(diskname) {
    
    //check if disk exists with that file name already
    // open disk and read in contents of fat and root into vectors using sstream
    
    rootsize = getblocksize() / 12;
    
    if (getnumberofblocks() * 6 % getblocksize() == 0)
        fatsize = getnumberofblocks() * 6 / getblocksize();
    else
        fatsize = getnumberofblocks() * 6 / getblocksize() + 1;
    
    // Check if Filesystem exists on disk already
    
    string buffer;
    Sdisk::getblock(1,buffer);
    istringstream instream;
    instream.str(buffer);
 
    if (buffer[0] == '#') { 
 
        // create root from scratch
        
        for (int i = 0; i < rootsize; i++) {
            filename.push_back("?????");
            firstblock.push_back(0);
        }

        // create FAT from scratch
        
        for (int i = 0; i < getnumberofblocks(); i++)
            fat.push_back(0);
        
        fat[1] = 0; //root
        int i = 0;
        
        for (; i < fatsize; i++) // set 0 in each fat block
            fat[i + 2] = 0;
        
        fat[0] = i + 2; // set beginning of free list
        
        for (int j = i + 2; j < fat.size(); j++) // sets up free list
            fat[j] = j + 1;
        
        fat[fat.size() - 1] = 0; // end of free list
        
        fssynch();     
    }
    else {
     
        // read in FAT from disk
        
        string buffer;
        string sbuffer;
        
        for (int i = 0; i < fatsize; i++) {
            Sdisk::getblock(i + 2,sbuffer);
            buffer += sbuffer;
        }
        
        istringstream instream;
        instream.str(buffer);
        
        for (int i = 0; i < getnumberofblocks(); i++) {
            int x;
            instream >> x;
            fat.push_back(x);
        }
        
        // read in root from disk
        
        string rootbuffer;
        
        Sdisk::getblock(1,rootbuffer);
        
        istringstream rootstream;
        rootstream.str(rootbuffer);
        
        for (int i = 0; i < rootsize; i++) {
            string x;
            int y;
            rootstream >> x;
            filename.push_back(x);
            rootstream >> y;
            firstblock.push_back(y);
        }
       
        fssynch();      
    }
}

Filesys::~Filesys() {
    
    
}

int Filesys::fsclose() {
    fssynch();
}

int Filesys::fssynch() {
    
    // write root to disk
    
    string rootbuffer;
    ostringstream rootstream;
    
    for (int i = 0; i < filename.size(); i++) 
        rootstream << filename[i] << " " << firstblock[i] << " ";
    
    rootbuffer = rootstream.str();
    
    int padding = getblocksize() - rootbuffer.length();
    
    if (rootbuffer.length() < getblocksize()) 
        for (int i = 0; i < padding; i++) 
            rootbuffer += "#";
        
    Sdisk::putblock(1,rootbuffer);
        
    // write fat to disk
    
    vector<string> blocks;
    string fatbuffer;
    int b = getblocksize();
    
    ostringstream outstream;
    
    for (int i = 0; i < fat.size(); i++) 
        outstream << fat[i] << " ";
    
    fatbuffer = outstream.str();
    
    blocks = block(fatbuffer,b);
    
    for (int i = 0; i < blocks.size(); i++) 
        Sdisk::putblock(i + 2, blocks[i]);   
}

int Filesys::newfile(string file) {
    
    // check if file is in fat already
    // if not, find next blank spot, looking for ????
    // check if full
    
    // put file name in fat
    
    //write fat to disk using fssynch()
    
    for (int i = 0; i < filename.size(); i++)
        if (filename[i] == file)
            return 0;
    
    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == "?????") {
            filename[i] = file;
            
            fssynch();
            return 1;
        }
    }
    
    fssynch();
    
    return 0; 
}

int Filesys::rmfile(string file) {
    
    //check if file exists
    //check if file is empty by looking at first block for 0
    
    // if file empty and exists, change file name in fat to ????
    
    //write fat to disk using fssynch()
    
    
    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == file) {
            if (firstblock[i] == 0) {
                filename[i] == "????";
                fssynch();
                return 1;
            }
        }
    }
    return 0;
}

int Filesys::getfirstblock(string file) {
    //check if file exists
    //check if first block of file exists or if 0
    
    //iterate through file blocks and return block number
    
    for (int i = 0; i < filename.size(); i++)
        if (filename[i] == file) 
            return firstblock[i];

    return -1;
}

int Filesys::addblock(string file, string buffer) {
    
    //block the buffer passed in
    
    vector<string> temp = block(buffer,getblocksize());
    
    string tempbuffer = temp[0];
    
    // check if enough room
    
    int allocate = fat[0];
    
    if (allocate == 0) // no more room
        return -1;
    
    // check if file exists
    
    bool fileexists = false;

    int block;
    
    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == file) {
            fileexists = true;
            block = firstblock[i];
        }
    }
    
    if (!fileexists) 
        return 0;
    
    // check if file empty or already has blocks
    
    if (block == 0) {
        for (int i = 0; i < filename.size(); i++) {
            if (filename[i] == file) {
                firstblock[i] = allocate;
                break;
            }
        }
    }
    else {
        while (fat[block] != 0) 
            block = fat[block];
    
        fat[block] = allocate;
    }
    
    fat[0] = fat[fat[0]];
    fat[allocate] = 0;
    
    Sdisk::putblock(allocate,tempbuffer);
    
    fssynch();
    
    return allocate;  // was return allocate;
    
}

int Filesys::delblock(string file, int blocknumber) {
    
    int block = getfirstblock(file);
   
    bool flag = false;
    
    if (block == blocknumber) {
        for (int i = 0; i < filename.size(); i++) {
            if (filename[i] == file) {
                firstblock[i] = fat[block];
                flag = true;
                break;
            }
        }   
    }
    else {
        while (fat[block] != blocknumber && fat[block] != 0) 
            block = fat[block];
        
        if (fat[block] == 0) {
            return 0;
        }
        else {
            fat[block] = fat[fat[block]];
            flag = true;
        }
    }
    
    // update free list
    
    if (flag) {
        fat[blocknumber] = fat[0];
        fat[0] = blocknumber;
        fssynch();
        return 1;
    }
    return 0;  
}

int Filesys::getblock(string file, int blocknumber, string & buffer) {
    
    //check if file exists and blocknumber is in range of file
    
    //return to buffer specific blocknumber requested
    
    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == file) {
            if (belongstofile(file,blocknumber)) {
                Sdisk::getblock(blocknumber, buffer);
		
                // get rid of # signs at end of buffer

                for (int i = 0; i < buffer.length(); i++) {
                    if (buffer[i] == '#') {			
                        string temp = buffer.substr(0,i);
                        buffer = temp;
                        return 1;         
                    }
                }
                return 1;
            }
        }
    }  
    return 0;
}

int Filesys::putblock(string file, int blocknumber, string buffer) {
    
    //check if file exists and blocknumber is in range of file
    
    //put buffer on disk at blocknumber
    
    
    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == file) {
            if (belongstofile(file,blocknumber)) {
                Sdisk::putblock(blocknumber, buffer);
                return 1;
            }
        }
    }
    return 0;
}

int Filesys::nextblock(string file, int blocknumber) {
    
    // check if file exists
    
    for (int i = 0; i < filename.size(); i++) {
        
        if (filename[i] == file) {
            if (belongstofile(file, blocknumber)) {
                if (blocknumber == 0) {
                    return 0;
                }
               
                return fat[blocknumber]; 
            }
        }   
    }
    
    return -1;   
}

bool Filesys::belongstofile(string file, int blocknumber) {

    for (int i = 0; i < filename.size(); i++) {
        if (filename[i] == file) {
            int nextblock = firstblock[i];
            
            while (nextblock != 0) {
                if (nextblock == blocknumber) 
                    return true;
                nextblock = fat[nextblock];
            }
        }
    }  
    return false;
}

vector<string> Filesys::block(string s, int b) {
    
    vector<string> blocks;
    int numberofblocks = 0;
    
    if (s.size() % b == 0) 
        numberofblocks = s.size() / b;
    else
        numberofblocks = s.size() / b + 1;
    
    
    
    string tempblock;
    
    for (int i = 0; i < numberofblocks; i++) {
        tempblock = s.substr(i * b, b);
        blocks.push_back(tempblock);
    }
    
    
    
    int lastblock = blocks.size() - 1;
    
    for (int i = blocks[lastblock].size(); i < b; i++) 
        blocks[lastblock] += "#";
    
    

    return blocks;
}

void Filesys::outputtest() {

    cout << "\n\nPrint Fat\n\n";
   
    for (int i = 0; i < fat.size(); i++)
        cout << i << " " << fat[i] << endl;

    cout << "\n\nPrint Root\n\n";

    for (int i = 0; i < filename.size(); i++)
        cout << filename[i] << " " << firstblock[i] << endl;
}


