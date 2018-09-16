#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int noOfCandidates = 6;
const int noOfRegions = 4;

void printHeading();
void initialize(int vbRegion[][noOfRegions], int tVotes[],
				int noOfRows);
void getCandidatesName(ifstream& inp, string cNames[], 
						int noOfRows);
void sortCandidatesName(string cNames[], int noOfRows);
int binSearch(string cNames[], int noOfRows, string name);
void processVotes(ifstream& inp, string cNames[],
				  int vbRegion[][noOfRegions], int noOfRows);
void addRegionsVote(int vbRegion[][noOfRegions], int tVotes[], 
     			    int noOfRows);

void printResults(string cNames[], int vbRegion[][noOfRegions],
				  int tVotes[], int noOfRows);

int main()
{
		//Declare variables; Step 1
	string candidatesName[noOfCandidates];
	int votesByRegion[noOfCandidates][noOfRegions];
	int totalVotes[noOfCandidates];
	ifstream infile;

	infile.open("a:\\candData.txt");							//Step 2
	if (!infile)												//Step 3
	{
		cout << "Input file (candData.txt) does not exit." << endl;
		return 1;
	}

	getCandidatesName(infile, candidatesName, 
                      noOfCandidates);  						//Step 4
	sortCandidatesName(candidatesName, noOfCandidates);			//Step 5

	infile.close();												//Step 6
	infile.clear();												//Step 6

	infile.open("a:\\voteData.txt");							//Step 7
	if (!infile)												//Step 8
	{
		cout << "Input file (voteData.txt) does not exit." << endl;
		return 1;
	}

	initialize(votesByRegion, totalVotes, noOfCandidates);		//Step 9
	processVotes(infile, candidatesName, votesByRegion,
				 noOfCandidates);								//Step 10
	addRegionsVote(votesByRegion, totalVotes,
       			   noOfCandidates); 							//Step 11

	printHeading();												//Step 12
	printResults(candidatesName,votesByRegion,
				totalVotes,noOfCandidates);						//Step 13

	return 0;
}

void initialize(int vbRegion[][noOfRegions], int tVotes[],
                int noOfRows)
{
	int i,j;

	for (i = 0; i < noOfRows; i++)
		for (j = 0; j < noOfRegions; j++)
			vbRegion[i][j] = 0;

	for (i = 0; i < noOfRows; i++)
		tVotes[i] = 0;
}

void getCandidatesName(ifstream& inp, string cNames[], int noOfRows)
{
	int i;
	
	for (i = 0; i < noOfRows; i++)
		inp >> cNames[i];
}

void sortCandidatesName(string cNames[], int noOfRows)
{
	int i, j;
	int min;

		//selection sort
	for (i = 0; i < noOfRows - 1; i++)
	{
		min = i;

		for (j = i + 1; j < noOfRows; j++)
			if (cNames[j] < cNames[min])
				min = j;

		cNames[i].swap(cNames[min]);
	}
}

int binSearch(string cNames[], int noOfRows, string name)
{
	int first, last, mid;
	bool found;
	first = 0;
	last = noOfRows - 1;
	found = false;

	while(!found && first <= last)
	{
		mid = (first + last) / 2;

		if (cNames[mid] == name)
			found = true;
		else 
			if (cNames[mid] > name)
				last = mid - 1;
			else
				first = mid + 1;
	}

	if (found)
   	    return mid;
    else
        return -1;
}
void processVotes(ifstream& inp, string cNames[],
				  int vbRegion[][noOfRegions], int noOfRows)
{
	string candName;
	int region;
	int noOfVotes;
	int loc;
	
	inp >> candName >> region >> noOfVotes;

	while(inp)
	{
		loc =  binSearch(cNames, noOfRows, candName);

		if (loc != -1)
     	   vbRegion[loc][region - 1] = vbRegion[loc][region - 1] 
   										+ noOfVotes;
		inp >> candName >> region >> noOfVotes;
	}
}

void addRegionsVote(int vbRegion[][noOfRegions], int tVotes[], 
					int noOfRows)
{
	int i, j;

	for (i = 0; i < noOfRows; i ++)
		for (j = 0; j < noOfRegions; j++)
			tVotes[i] = tVotes[i] + vbRegion[i][j];
}


void printHeading()
{
	cout << "      --------------Election Results--------------"
		 << endl << endl;
	cout << "Candidate		        Votes" << endl;
	cout << "Name        Region1   Region2   Region3   "
		 << "Region4    Total" << endl;
	cout << "---------   -------   -------   -------   -------   "
		 << "------" << endl;
}

void printResults(string cNames[], int vbRegion[][noOfRegions], 
				  int tVotes[], int noOfRows)
{
	int i, j;
	int largestVotes = 0;
	int winLoc = 0;
	int sumVotes = 0;

	for (i = 0; i < noOfRows; i++)
	{
		if (largestVotes < tVotes[i])
		{
			largestVotes = tVotes[i];
			winLoc = i;
		}

		sumVotes = sumVotes + tVotes[i];

		cout << left;
		cout << setw(9) << cNames[i] << "  ";
		cout << right;
		for (j = 0; j < noOfRegions; j++)
			cout << setw(8) << vbRegion[i][j] << "  ";
		cout << setw(6) << tVotes[i] << endl;
	}

	cout << endl << endl << "Winner: " << cNames[winLoc]
	     << ",  Votes Received: " << tVotes[winLoc] << endl << endl;
	cout << "Total votes polled: " << sumVotes << endl;
}
