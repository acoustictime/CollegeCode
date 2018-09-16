
class pointerDataClass
{
public:
    void print() const;
      //Function to output the value of x and
      //the value of the array p.
    void setData();
      //Function to input data into x and
      //into the array p.
    void destroyP();
      //Function to deallocates the memory space 
      //occupied by the array p.

    pointerDataClass(int sizeP = 10);
      //constructor 
      //Creates an array of the size specified by the
      //parameter sizeP; the default array size is 10.

    ~pointerDataClass();
      //destructor
      //deallocates the memory space occupied by the array p.

    pointerDataClass (const pointerDataClass& otherObject);
      //copy constructor

private:
    int x;
    int lenP;
    int *p;       //pointer to an int array
};

