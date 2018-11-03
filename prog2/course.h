// Ching-Wei Lin
// 987563037
// This program is used to manage the material for studying in course.

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;



struct node		//DLL for material
{
	node * next;
	node * prv;
	class study * data;
};

struct node1		//CLL for exercise
{
	node1 * next;
	char * name;		//name of the question	
	char * qes;		//question
	bool done;		//Is it done?
};

class list
{
	public:
		list();
		~list();
		int clear_all();			//remove all
		int remove_all(node * & he, node * & ta);   //remove all
		int add();				//add
		int display();				//display
		int displayw(node * play);		//wrapper function
		int remove(char * match);		//remove one
		int removew(node *& tar, char * match);	//wrapper function
		node * head;
		node * tail;
};
class study
{
	public:
		study();			//constructor
		~study();			//destructor
		study(const study & copy);	//copy constructor
		study(char * copyn, int copyl);	//copy constructor
		virtual void display() = 0;	//display
		virtual void remove() = 0;		//remove
		virtual void add() = 0;		//add
		bool nameout(char * match);	//check if equal
	protected:
		char * name;			//name of the material
		int level;			//level of the material
};
		
class read : public study
{
	public:
		read();				//constructor
		~read();			//destructor
		void display();			//dsiplay
		void remove();			//remove
		void add(); 			//add
	protected:
		char * title;			//title of the book
		char * author;			//author of the book
		int chap;			//chapter of the book
		int page;			//page of the book
};

class exer : public study
{
	public:
		exer();				//constructor
		~exer();			//destructor
		void display();			//display
		void remove();			//remove
		void add();			//add
		int delete_all(node1 * & del);	//delete all
		int displayw(node1 * play, node1 * tar);	//wrapper function
	protected:
		node1 * rear;			//CLL
};		

class lab : public study
{
	public:
		lab();				//constructor
		~lab();				//destructor
		void display();			//display
		void remove();			//remove
		void add();			//add
	protected:
		int num;			//number of lab
		char * feedback;			//feedback of lab
};
