#include "Sdisk.h"
#include "Filesys.h"

int main()
{
    
    Filesys fsys("disk");
    fsys.newfile("pizza");
    int next = fsys.getfirstblock("pizza");
    string buffer = "Pizza is so fucking good";
    
    fsys.addblock("pizza", buffer);
    
    next = fsys.getfirstblock("pizza");
    buffer = "But you shouldn't eat it all the time unfortunately!!";
    
    fsys.addblock("pizza", buffer);
    
}
