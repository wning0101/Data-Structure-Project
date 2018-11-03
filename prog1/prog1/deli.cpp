// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee
#include "deli.h"

deli::deli():origin(NULL), packlist(NULL) //constructor
{
}

deli::~deli() //destructor
{
	if(origin)
		delete [] origin;
	node * temp;
	while(packlist)
	{
		temp = packlist;
		packlist = packlist->next;
		delete [] temp->data.des;
		delete [] temp->data.name;
		delete temp;
	}
	temp = NULL;
	packlist = NULL;
}

deli::deli(const deli & to_copy) //copy constructor
{
	if(to_copy.origin)
	{
		origin = new char[strlen(to_copy.origin)+1];
		strcpy(origin, to_copy.origin);
	}
	else
		origin = NULL;
	if(to_copy.packlist)
	{
		node * temp = to_copy.packlist;
		node * temp1;
		packlist = new node;
		temp1 = packlist;
		temp1->data.des = new char[strlen(temp->data.des)+1];
		strcpy(temp1->data.des, temp->data.des);
		temp1->data.name = new char[strlen(temp->data.name)+1];
		strcpy(temp1->data.name, temp->data.name);
		temp1->data.weight = temp->data.weight;
		temp1 = temp1->next;
		temp = temp->next;
		while(temp)
		{	
		temp1 = new node;
		temp1->data.des = new char[strlen(temp->data.des)+1];
		strcpy(temp1->data.des, temp->data.des);
		temp1->data.name = new char[strlen(temp->data.name)+1];
		strcpy(temp1->data.name, temp->data.name);
		temp1->data.weight = temp->data.weight;
		temp1 = temp1->next;
		temp = temp->next;
		}
		temp1 = NULL;
	}
	else
		packlist = NULL;
}

deli::deli(char * new_ori, node * new_pack) //copy constructor
{
	if(new_ori)
	{
		origin = new char[strlen(new_ori)+1];
		strcpy(origin, new_ori);
	}
	else
		new_ori = NULL;
	if(new_pack)
	{	
		node * temp = new_pack;
		node * temp1;
		packlist = new node;
		temp1 = packlist;
		temp1->data.des = new char[strlen(temp->data.des)+1];
		strcpy(temp1->data.des, temp->data.des);
		
		temp1->data.name = new char[strlen(temp->data.name)+1];
		strcpy(temp1->data.name, temp->data.name);
		temp1->data.weight = temp->data.weight;
		temp1 = temp1->next;
		temp = temp->next;
		while(temp)
		{	
		temp1 = new node;
		temp1->data.des = new char[strlen(temp->data.des)+1];
		strcpy(temp1->data.des, temp->data.des);
		temp1->data.weight = temp->data.weight;
		temp1->data.name = new char[strlen(temp->data.name)+1];
		strcpy(temp1->data.name, temp->data.name);
		temp1 = temp1->next;
		temp = temp->next;
		}
		temp1 = NULL;
	}
	else
		packlist = NULL;
}

void deli::add_p(int new_weight, char * new_des, char * new_name) //add a package
{
	node * temp = new node;
	temp->next = packlist;
	packlist = temp;
	temp->data.weight = new_weight;
	temp->data.des = new char[strlen(new_des)+1];
	strcpy(temp->data.des, new_des);
	temp->data.name = new char[strlen(new_name)+1];
	strcpy(temp->data.name, new_name);
	
} 

void deli::add_o(char * toadd) // add origin
{
	origin = new char[strlen(toadd)+1];
	strcpy(origin, toadd);
}

void deli::display(city list[20],int num) //display
{
	cout << " From: " << origin << endl;
	displayw(packlist, list, num);
}

int deli::displayw(node * head, city list[20], int num) //warpper function
{
	if(!head)
		return 0;
	int ori;
	int des;
	int time;
	cout << "Name: " << head->data.name << endl;
	cout << "Weight: " << head->data.weight << endl;
	cout << "Destination: " << head->data.des << endl;
	
	for(int i=0; i<num; ++i)
	{
		if(strcmp(list[i].name, origin) == 0)
			ori = i;
		
		if(strcmp(list[i].name, head->data.des) == 0)
			des = i;
	}
	if(ori < des)
	{
		for(int i=ori; i<des+1; i++)
		{
			time += ((list[i].co_list->length/list[i].co_list->speed)+list[i].co_list->status*50);
		}
	}
	else
	{
		for(int i=des; i<ori+1; i++)
		{
			time += ((list[i].co_list->length/list[i].co_list->speed)+list[i].co_list->status*50);
		}
	}
	cout << "Estimate time: " << time << endl;
	return displayw(head->next, list, num);
}

void deli::display1(city list[20],int num) //display
{
	cout << " From: " << origin << endl;
	displayw1(packlist, list, num);
}

int deli::displayw1(node * head, city list[20], int num) //warpper function
{
	if(!head)
		return 0;
	int ori;
	int des;
	int money;
	cout << "Name: " << head->data.name << endl;
	cout << "Weight: " << head->data.weight << endl;
	cout << "Destination: " << head->data.des << endl;
	
	for(int i=0; i<num; ++i)
	{
		if(strcmp(list[i].name, origin) == 0)
			ori = i;
		
		if(strcmp(list[i].name, head->data.des) == 0)
			des = i;
	}
	if(ori < des)
	{
		for(int i=ori; i<des+1; i++)
		{
			money += (list[i].co_list->length)*10;
		}
	}
	else
	{
		for(int i=des; i<ori+1; i++)
		{
			money += (list[i].co_list->length)*10;
		}
	}
	money += head->data.weight*5;
	cout << "Estimate price: " << money << endl;
	return displayw1(head->next, list, num);
}
stard::stard() // constructor
{	vol = 0;
}

stard::stard(char * in_ori, node * in_pack, int in_vol): deli(in_ori, in_pack), vol(in_vol) //copy constructor
{}

express::express() // constructor
{	vol = 0;
}

express::express(char * in_ori, node * in_pack, int in_vol): deli(in_ori, in_pack), vol(in_vol) //copy constructor
{}

drone::drone() // constructor
{}

drone::drone(char * in_ori, node * in_pack): deli(in_ori, in_pack) //copy constructor
{}

pack::pack():weight(0), des(NULL), name(NULL) //constructor
{}

pack::~pack() //destructor
{
	if(des)
	{
		delete [] des;
		delete [] name;
		name = NULL;
		des = NULL;
	}
}

