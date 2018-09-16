#include "Sdisk.h"
#include "Filesys.h"
#include <string>
#include <iostream>
#include "Indexrec.h"
#include "Table.h"

using namespace std;

int main() {
    
    string diskname = "disk";
    string inputfile = "inputfile";
    string flatfile = "flat";
    string indexfile = "index";
    
    Table table(diskname,flatfile,indexfile);
    
    int error = table.Build_Table(inputfile);
      
    string selection;
    
    cout << "Enter value to search for: ";
    
    cin >> selection;
       
    while (selection != "0") {
        error = table.Search(selection);
        
        cout << "\nEnter value to search for: ";
        cin >> selection;
    } 
}