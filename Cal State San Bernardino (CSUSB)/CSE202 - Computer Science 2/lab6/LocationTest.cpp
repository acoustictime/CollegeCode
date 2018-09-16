 #include "Location.h"
    #include <iostream>
    #include <string>
    using namespace std;
    
    int main()
    {
        Location t("4690 Sierra St", "42", "54");
    
        cout << "Address " << t.getLocationAddress() << endl;
        cout << "Building " << t.getLocationBuilding() << endl;
        cout << "Room " << t.getLocationRoom() << endl;
    }
