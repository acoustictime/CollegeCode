 #ifndef LOCATION_H
    #define LOCATION_H
    #include <string>
    using namespace std; 

    class Location
    {
    public:
        Location();
        Location(string addr, string bldg, string rm);
        string getLocationAddress();
        string getLocationBuilding();
        string getLocationRoom();
    private:
        string address;
        string building;
        string room;
    }; // Location
    #endif
