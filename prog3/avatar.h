//Ching-Wei Lin 
//#987563037
//This program is about creating an avatar with many features and records all the information about the avatar


#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class chac	//characters
{
	public:
		chac();			//constructor
		~chac();		//destructor
		chac(const chac & copy);	//copy constructor
		chac(char * copy);		//copy constructor
		virtual void add() = 0;
		virtual void display() = 0;
		virtual void remove() = 0;
	protected:
		char * des;		//describe
};

class nick : public chac	//nick name
{
	public:
		nick();			//constructor
		~nick();		//destructor
		void add();
		void display();
		void remove();
	protected:
		char * n_name;		//nick name
};

class contact : public chac	//contact
{
	public:
		contact();		//constructor
		~contact();		//destructor
		void add();
		void display();
		void remove();
	protected:
		char * con;		//contact
};

class website : public chac	//website
{
	public:
		website();		//constructor
		~website();		//destrcutor
		void add();
		void display();
		void remove();
	protected:
		char * web;		//website
};

class p_num : public chac 	//phone number
{
	public:
		p_num();		//constructor
		~p_num();		//destrctor
		void add();
		void display();
		void remove();
	protected:
		int num;		//phone number
};

class cloth : public chac	//dress style
{
	public:
		cloth();		//constructor
		~cloth();		//destructor
		void add();
		void display();
		void remove();
	protected:
		char * style;		//dressing style
};

class tool			//tool
{
	public:
		tool();			//constructor
		~tool();		//destructor
		tool(const tool & copy);	//copy constructor
		tool(int copy);		//copy constructor
		virtual void add() = 0;
		virtual void display() = 0;
		virtual void remove() = 0;
	protected:
		int level;		// the level of the tool
};

class weapon : public tool	// weapon
{
	public:
		weapon();		//constructor
		~weapon();		//destructor
		void add();
		void display();
		void remove();
	protected:
		int damage;		//damage
		int range;		//reange
};

class supply : public tool
{
	public:
		supply();		//constructor
		~supply();		//destructor
		void add();
		void display();
		void remove();
	protected:
		int recover;		//the amount of the recovery
};

class hint : public tool
{
	public:
		hint();			//constructor
		~hint();		//destructor
		void add();
		void display();
		void remove();
	protected:
		char * advice;		//the advice for hint
};

struct node		//the 2-3 tree for characters
{
	node * parent; //parent pointer
	int pri[2];	//priority
	node * ptr[3];  // pointers
	chac * data[2];	// the characters
};

struct node1		//the 2-3 tree for tools
{	
	node1 * parent; //parent pointer
	int pri[2];	//priority
	node1 * ptr[3]; // pointers
	tool * data[2];	// the tools
};
class avatar		//avatar object
{
	public:
		avatar();	//constrctor
		~avatar();	//destructor
		int remove_all(node *& tar);  // remove all
		int remove_all(node1 *& tar); // remove all
		int remove_all();	//remove all
		int reset(node *& tar);		//reset
		int reset(node1 *& tar);	//reset
		int add();		//add
		int display();		//display
		int disw(node * tar);		//wrapper function
		int disw(node1 * tar);		//wrapper function
		int addw(node *& tar, int prii);	//wrapper function
		int addw(node1 *& tar, int prii);	//wrapper function
		int writein(chac *& tar); //write in
		int writein(tool *& tar); //write in
		int num(int & tar);	//enter number
		avatar & operator += (int p);
		avatar operator + (int p);
		avatar & operator == (int p);

		void history();

	private:
		node * root;	//the list for characters
		node1 * root1;	// the list for tools
		char * his;	//history
};


