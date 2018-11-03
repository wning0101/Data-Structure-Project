// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

int find(char * name);
class node2
{	
	public:
	
	int road; //type of road
	int speed; // limitation of speed
	int length; //length of road
	int status; // status of the road
	struct city * adj;
	node2 * next;
};

class city
{
	public:

	city(); //constructor
	~city(); //destructor
	void add();   // add city
	void adda(city toadd[20]);  // add connection
	void display(); //display the connections
	int displayw(node2 * root); //wrap function
	char * name;
	node2 * co_list;
};

class node1
{
	city * data;   //data for city
	node1 * next;
};

