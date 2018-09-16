
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "simulation.h"
#include "queueAsArray.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival);

void runSimulation();

int main()
{
	runSimulation();

	return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival)
{
	cout << "Enter the simulation time: " << flush;
	cin >> sTime;
	cout << endl;

	cout << "Enter the number of servers: " << flush;
	cin >> numOfServers;
	cout << endl;

	cout << "Enter the transaction time: " << flush;
	cin >> transTime;
	cout << endl;

	cout << "Enter the time between customers arrival: " << flush;
	cin >> tBetweenCArrival;
	cout << endl;
}

void runSimulation()
{
	cout << "Write the definition of the function runSimulation." << endl;
	cout << "See programming Exercise 14." << endl;
}

