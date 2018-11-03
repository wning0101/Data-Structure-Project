// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee

#include "map.h"

city::city()  //constructor
{
	name =NULL;
	co_list = NULL;
}

city::~city() //destructor
{
	delete [] name;
	node2 * temp;
	while(co_list)
	{
		temp = co_list;
		co_list = co_list->next;
		delete temp;
	}
	temp = NULL;
	co_list = NULL;
}
	
int find(char * tofind)  //find the location of city
{
	return int(toupper(tofind[0]))-64;
}

void city::add() // add a city
{
	char toadd[100];
	cout << "What's the name of the city? " << endl;
	cin.get(toadd, 100, '\n');
	cin.ignore(100, '\n');
	name = new char[strlen(toadd)+1];
	strcpy(name, toadd);
}

void city::adda(city  toadd[20]) // add connection
{
	int yn =0;
	int con2;
	while(yn != 1)
	{
	node2 * temp = new node2;	
	temp->next = co_list;
	co_list = temp;
	cout << "Please enter the type of road. 1-freeway 2-main road 3-short cut" << endl;
	cin >> temp->road;
	cin.ignore();
	if(temp->road == 1)
		temp->speed = 60;
	else if(temp->road == 2)
		temp->speed = 45;
	else
		temp->speed = 40;
	cout << "Please enter the length of road. " << endl;
	cin >> temp->length;
	cin.ignore();
	temp->status = rand() % 2;		
	
	cout << "Which city do you want to connect? enter the number in the list of cities. " << endl;
	cin >> con2;
	cin.ignore();

	temp->adj = &toadd[con2];
	cout << "Are you done? 1-yes 2-no" << endl;
	cin >> yn;
	cin.ignore();
	}
}		

void city::display() //display the connections
{
	displayw(co_list);
}

int city::displayw(node2 * root) //wrap function
{
	if(!root)
		return 0;
	cout << root->adj->name << endl;
	return displayw(root->next);
}
