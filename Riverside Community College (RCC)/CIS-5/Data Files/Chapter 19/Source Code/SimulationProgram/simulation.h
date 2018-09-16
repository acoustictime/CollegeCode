
#include <fstream>
#include <string>
#include "queueAsArray.h"

using namespace std;


  //**************** customerType  ****************
class customerType
{
public:
    customerType(int cN = 0, int arrvTime = 0, int wTime = 0, 
                 int tTime = 0);
      //constructor to initialize the data members 
      //according to the parameters
      //If no value is specified in the object declaration, 
      //the default values are assigned.
      //Postcondition: customerNumber = cN;
      //               arrivalTime.clock = arrvTime;
      //               waitingTime.clock = wTime;
      //               transactionTime.clock = tTime
    void setCustomerInfo(int customerN = 0, int inTime = 0, 
                         int wTime = 0, int tTime = 0);
      //Data members are set according to the parameters.
      //Postcondition: customerNumber = customerN;
      //               arrivalTime.clock = arrvTime;
      //               waitingTime.clock = wTime;
      //               transactionTime.clock = tTime
    int getWaitingTime() const;
      //Function to return the waiting time of a customer.
      //Postcondition: The value of waitingTime is returned.
    void setWaitingTime(int time);
      //Function to set the waiting time of a customer.
      //Postcondition: waitingTime = time
    void incrementWaitingTime();
      //Function to increment the waiting time by one time unit.
      //Postcondition: waitingTime++
    int getArrivalTime() const;
      //Function to return the arrival time of a customer.
      //Postcondition: The value of arrivalTime is returned.
    int getTransactionTime() const;
      //Function to return the transaction time of a customer.
      //Postcondition: The value of transactionTime is returned.
    int getCustomerNumber() const;
      //Function to return the customer number.
      //Postcondition: The value of customerNumber is returned.

private:
    int customerNumber;
    int arrivalTime;
    int waitingTime; 
    int transactionTime;
};


	//*************  serverType  ****************
class serverType
{
public:
    serverType();
      //default constructor
      //Sets the values of the data members to their default
      //values.
      //Postcondition: currentCustomer is initialized by its
      //               default constructor; status = "free";
      //               the transaction time is initialized to 0.
    bool isFree() const;
      //Function to determine if the server is free.
      //Postcondition: Returns true if the server is free, 
      //               otherwise returns false.
    void setBusy();
      //Function to set the status of the server to busy.
      //Postcondition: status = "busy"
    void setFree();
      //Function to set the status of the server to "free."
      //Postcondition: status = "free"
    void setTransactionTime(int t);
      //Function to set the transaction time according to the 
      //parameter t.
      //Postcondition: transactionTime = t
    void setTransactionTime();
      //Function to set the transaction time according to 
      //the transaction time of the current customer.
      //Postcondition: 
      //   transactionTime = currentCustomer.transactionTime;
    int getRemainingTransactionTime() const;
      //Function to return the remaining transaction time.
      //Postcindition: The value of the data member 
      //                transactionTime is returned.
    void decreaseTransactionTime();
      //Function to decrease the transactionTime by 1 unit.
      //Postcondition: transactionTime--
    void setCurrentCustomer(customerType cCustomer);
      //Function to set the info of the current customer 
      //according to the parameter cCustomer.
      //Postcondition: currentCustomer = cCustomer
    int getCurrentCustomerNumber() const;
      //Function to return the customer number of the current
      //customer.
      //Postcondition: The value of the data member 
      //               customerNumber of the current customer
      //               is returned.

    int getCurrentCustomerArrivalTime() const;
      //Function to return the arrival time of the current 
      //customer.
      //Postcondition: The value of the data member 
      //               arrivalTime of the current customer
      //               is returned.
    int getCurrentCustomerWaitingTime() const;
      //Function to return the current waiting time of the 
      //current customer.
      //Postcondition: The value of the data member 
      //               transactionTime is returned.
    int getCurrentCustomerTransactionTime() const;
      //Function to return the transaction time of the 
      //current customer. 
      //Postcondition: The value of the data member 
      //               transactionTime of the current customer
      //               is returned.

private:
    customerType currentCustomer;
    string status;
    int transactionTime; 
};


//*************  serverListType  ****************
class serverListType
{
public:
    serverListType(int num = 1);
      //constructor to initialize a list of servers
      //Postcondition: numOfServers = num
      //   A list of servers, specified by num, is created
      //   and each server is initialized to "free".
    ~serverListType();
      //destructor
      //Postcondition: The list of servers is destroyed.
    int getFreeServerID() const;
      //Function to search the list of servers. 
      //Postcondition: If a free server is found, returns 
      //               its ID; otherwise, returns -1.
    int getNumberOfBusyServers() const;
      //Function to return the number of busy servers.
      //Postcondition: The value of busy servers is returned.
    void setServerBusy(int serverID, customerType cCustomer,
                        int tTime);
      //Function to set the server specified by serverID to "busy". 
      //To serve the customer specified by cCustomer, the
      //transaction time is set according to the 
      //parameter tTime.
    void setServerBusy(int serverID, customerType cCustomer);
      //Function to set the server specified by serverID to "busy". 
      //To serve the customer specified by cCustomer, the
      //transaction time is set according to the
      //customer’s transaction time. 
    void updateServers(ostream& outFile);
      //The transaction time of each busy server is decremented
      //by one unit.
      //Postcondition: If the transaction time of a busy server
      //   is reduced to zero, the server is set to "free". 
      //   Moreover, if the actual parameter corresponding to 
      //   outFile is cout, a message indicating which customer
      //   has been served is printed on the screen, together 
      //   with the customer's departing time. Otherwise, the
      //   output is sent to a file specified by the user.

private:
    int numOfServers;
    serverType *servers;
};


//**************** waitQueue  *************

class waitingCustomerQueueType: public queueType<customerType>
{
public:
    waitingCustomerQueueType(int size = 100);
      //The queue is initialized according to the
      //parameter size.
      //The value of size is passed to the constructor
      //of queueType.
    void updateWaitingQueue();
      //Function to increment the waiting time of each 
      //customer in the queue by one time unit.
};

