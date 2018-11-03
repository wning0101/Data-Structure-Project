// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee

#include "deli.h"


int locate(int num, city tofind[20], char * match) //find the place
	{
	for(int i=0; i<num; ++i)
	{
		if(strcmp(tofind[i].name, match) == 0)
			return i;
	}
	return 100;
	}
int main()
{
	city * c_list;		//the map
	c_list = new city[20];  //allocate cities
	express ecar;		//the car for express delivery, assume that we have only one express car
	stard scar;		//the car for standard delivery, assume that we have only one standard car
	drone dcar;		//the car for drone delivery, assume that there is no limit for drone	
	int yn = 0;		//confirmation 
	int num;		//number of cities
	int con1;		//the city be connected
	int con2;		//the city to connect
	int ans;		//type of deliver
	char des[100];		//temporary variables
	char ori[100];		
	char name[100];
	int weig;
	int org;	
	node2 * temp;
	cout << "How many cities are there in the map?" << endl;
	cin >> num;
	cin.ignore();
	for(int i=0; i<num; ++i) //enter city information
	{
		c_list[i].add();
	}
	for(int i=0; i<num; ++i) //display cities
	{
		cout << i << " - " << c_list[i].name << endl;
	}		
	for(int i=0; i<num; ++i) //connecting
	{
		cout << "Now we are doing the connection of " << c_list[i].name << endl;
		c_list[i].adda(c_list);
	}
	cout << "Here is the list of city." << endl; //display the cities and the connections
	for(int i=0; i<num; ++i)
	{		
		cout << i << " - " << c_list[i].name << endl;
		cout << "Here's the list of its connection." << endl;
		c_list[i].display();
	}
	cout << "Let's assign the packages to the delivery lists. " << endl;	
	
	cout << "Where is the point of origination? " << endl;
	cin.get(ori, 100, '\n');
	cin.ignore(100, '\n');
	
	ecar.add_o(ori);
	scar.add_o(ori);
	dcar.add_o(ori);	
	while(yn != 1)			// add a package to the express list, standard list or drone list
	{
		cout << "what type of delivery do you want for this package?  1-express 2-standard 3-drone" << endl;
		cin >> ans;
		cin.ignore();
		if(ans == 1)
		{
			if(ecar.vol >= 3)
			{
				cout << "The express car is full." << endl;
			}
			else
			{
				cout << "What is the name of package? " << endl;
				cin.get(name, 100, '\n');
				cin.ignore(100, '\n');
			
				cout << "What is the weight? " << endl;
				cin >> weig;
				cin.ignore();
				
				cout <<	"What's the destination? " << endl;
				cin.get(des, 100, '\n');
				cin.ignore(100, '\n');
				if(locate(num, c_list, des) == 100)
					cout << "There is no such place." << endl;
				else
				{
					ecar.add_p(weig, des, name);
					ecar.vol += 1;
				}
			}
		}
		if(ans == 2)
		{
			if(scar.vol >= 100)
			{
				cout << "The standard car is full. " << endl;
			}
			else
			{
				cout << "What is the name of package? " << endl;
				cin.get(name, 100, '\n');
				cin.ignore(100, '\n');
				cout << "What is the weight? " << endl;
				cin >> weig;
				cin.ignore();
				
				cout <<	"What's the destination? " << endl;
				cin.get(des, 100, '\n');
				cin.ignore(100, '\n');
				if(locate(num, c_list, des) == 100)
					cout << "There is no such place." << endl;
				else
				{
					scar.add_p(weig, des, name);
					scar.vol += weig;
				}
			}
		}
		if(ans == 3)
		{
				cout << "What is the name of package? " << endl;
				cin.get(name, 100, '\n');
				cin.ignore(100, '\n');
				cout << "What is the weight? " << endl;
				cin >> weig;
				cin.ignore();
				
				cout <<	"What's the destination? " << endl;
				cin.get(des, 100, '\n');
				cin.ignore(100, '\n');

				if(locate(num, c_list, des) == 100)
					cout << "There is no such place." << endl;
				else
				{
					dcar.add_p(weig, des, name);
				}
		}
		cout << "Are you done adding ?  1-yes 2-no" << endl;
		cin >> yn;
		cin.ignore();
	}
	
	cout << "Here's the express list. " << endl;
	ecar.display1(c_list, num);
	cout << "Here's the standard list. " <<endl;
	scar.display(c_list, num);
	cout << "Here's the drone list. " << endl;
	dcar.display(c_list, num);
	
	return 0;
}
