// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "node.h"
#include "map.h"

using namespace std;

class deli  // delivery list
{
	public:
		deli();    // constructor
		~deli();   // destructor
		deli(const deli & to_copy); //copy constructor
		deli(char * new_ori, node * new_pack); //copy constructor
	        void add_p(int new_weight, char * new_des,char * new_name); //add a package
		void add_o(char * toadd); //add origin
		void display(city list[20], int num); //display the list
		void display1(city list[20], int num); //display the list
		int displayw(node * head, city list[20], int num); //warpper function
		int displayw1(node * head, city list[20], int num); //warpper function
	protected:
		char * origin;    //point of origination
		node * packlist;  // package list
};

class stard: public deli
{
	public:
		stard(); // constructor
		stard(char * in_ori, node * in_pack, int in_vol); // copy constructor
		

		int vol;
};

class express: public deli
{
	public:
		express(); // constructor
		express(char * in_ori, node * in_pack, int in_vol); // copy constructor
		int vol;
};

class drone: public deli
{
	public:
		drone(); //constructor
		drone(char * in_ori, node * in_pack); // copy constructor
};


// int locate(int num, city tofind[20], char * match) //find the place
