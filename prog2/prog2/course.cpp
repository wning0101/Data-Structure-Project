// Ching-Wei Lin
// 987563037
// This program is used to manage the material for studying in course.

#include "course.h"

list::list()				//constructor
{
	head = NULL;
	tail = NULL;
}

list::~list()				//destructor
{
	remove_all(head, tail);	
}
int list::clear_all()			// remove all
{
	remove_all(head, tail);
}
int list::remove_all(node * & he, node * & ta) //warpper function
{
	if(!he)
		return 0;
	if(he == ta)
	{
		he->data->remove();
		delete he;
		he = NULL;
		ta = NULL;
		return 0;
	}
	node * temp = he;
	he = he->next;
	if(he)
	{
	he->prv = NULL;
	}
	temp->data->remove();
	delete temp;
	return remove_all(he, ta);
}

int list::remove(char * match)		//remove one
{
	removew(head, match);
}

int list::removew(node *& tar, char * match)	//wrapper function
{
	if(!tar)
	{	
		cout << "Not found. " << endl;
		return 0;
	}
	if(tar->data->nameout(match))
	{
		node * temp = tar;
		tar = tar->next;
		temp->data->remove();
		temp = NULL;
		return 1;
	}
	return removew(tar->next, match);
}
int list::add()	//add a material
{
	if(!head)
	{
		head = new node;
		head->prv = NULL;
		head->next = NULL;
		return 0;
	}
	node * temp = new node;
	temp->next = head;
	head->prv = temp;
	temp->prv =NULL;
	head = temp;
	return 1;
}
int list::display()		//display
{
	displayw(head);	
}

int list::displayw(node * play)		//wrapper function
{
	if(!play)
		return 0;
	play->data->display();
	return displayw(play->next);
}
study::study()		//constructor
{
	name = NULL;
	level = 0;
}

study::~study()
{
	delete [] name;		//destructor
}

bool study::nameout(char * match)	//check if equal
{
	if(strcmp(name, match) == 0)
		return true;
	return false;
}
void study::remove()		//remove
{
}
void study::add()	//add
{
}
void study::display()		//display
{
}
study::study(const study & copy)	//copy constructor
{
	if(!copy.name)
		name = NULL;
	else
	{
		name = new char[strlen(copy.name)+1];
		strcpy(name, copy.name);
	}
	level = copy.level;
}
study::study(char * copyn, int copyl)	//copy constructor
{
	if(!copyn)
		name = NULL;
	else
	{
		name = new char[strlen(copyn)+1];
		strcpy(name, copyn);
	}
	level = copyl;
}

read::read(): study(NULL, 0), title(NULL), author(NULL), chap(0), page(0)				//constructor
{}

read::~read()	//destructor
{
	delete [] title;
	delete [] author;
}

void read::add()	 //add
{
	char t[100];
	char a[100];
	char n[100];
	int l;
	int c;
	int p;
	cout << "What is the name of the material?" << endl;
	cin.get(n, 100, '\n');
	cin.ignore(100, '\n'); 		

	cout << "What's the level of the material?" << endl;	
	cin >> l;
	cin.ignore();

	cout << "What's the title of the book?" << endl;
	cin.get(t, 100, '\n');
	cin.ignore(100, '\n');

	cout << "What's the author of the book? " << endl;
	cin.get(a, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Which chapter? (number)" << endl;
	cin >> c;
	cin.ignore();

	cout << "What page? (number)" << endl;
	cin >> p;
	cin.ignore();
	name = new char[strlen(n)+1];
	strcpy(name, n);
	title = new char[strlen(t)+1];
	strcpy(title, t);
	author = new char[strlen(a)+1];
	strcpy(author, a);
	chap = c;
	page = p;
	level = l;
}
void read::remove()		//remove
{
	delete [] title;
	delete [] author;
}

void read::display()		//display
{
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Chapter: " << chap << endl;
	cout << "Page: " << page << endl;
}


exer::exer(): study(NULL, 0), rear(NULL)		//constructor
{}

exer::~exer()		//destructor
{
	delete_all(rear);	
}
void exer::display()		//display
{
	cout <<"Name: " << name << endl;
	cout <<"Level: " << level << endl;
	displayw(rear->next, rear);		
}

int exer::displayw(node1 * play, node1 * tar)	//wrapper function
{
	if(!play)
		return 0;
	if(play == tar)
	{
		cout << "Q: " << play->name << endl;
		cout << "Question: " << play->qes << endl;
		if(play->done)
			cout << "Complete. " << endl;
		else
			cout << "Uncomplete. " << endl;
		return 1;
	}	
	cout << "Q: " << play->name << endl;
	cout << "Question: " << play->qes << endl;
	if(play->done)
		cout << "Complete. " << endl;
	else
		cout << "Uncomplete. " << endl;
	return displayw(play->next, tar);
}

void exer::remove()		//remove
{
	delete_all(rear);
}

int exer::delete_all(node1 * & del)	//delete all
{
	if(!del)
		return 0;
	if(del == del->next)
	{
		delete [] del->name;
		delete [] del->qes;
		delete del;
		del = NULL;
		del->next = NULL;
		return 0;
	}
	node1 * temp = del->next;
	del->next = del->next->next;
	delete [] temp->name;
	delete [] temp->qes;
	delete temp;
	return delete_all(del);
}		

void exer::add()		//add
{
	char n[100];
	int l;
	char na[100];
	char qe[200];
	int yn;
	int yn1;
	cout << "What is the name of the material?" << endl;
	cin.get(n, 100, '\n');
	cin.ignore(100, '\n'); 		

	cout << "What's the level of the material?" << endl;	
	cin >> l;
	cin.ignore();
	name = new char[strlen(n)+1];
	strcpy(name, n);
	level = l;
	while(yn1!=2)
	{	
		if(!rear)
		{
			rear = new node1;
			rear->next = rear;
			cout << "What's the name of the question? " << endl;
			cin.get(na, 100, '\n');
			cin.ignore(100, '\n');
			rear->name = new char[strlen(na)+1];
			strcpy(rear->name, na);

			cout << "Please enter the question. " << endl;
			cin.get(qe, 200, '\n');
			cin.ignore(200, '\n');
			rear->qes = new char[strlen(qe)+1];
			strcpy(rear->qes, qe);

			cout << "Are you done with it? 1-yes 2-no " << endl;
			cin >> yn;
			if(yn == 1)
				rear->done = true;
			else
				rear->done = false;
		}
		else
		{
			node1 * temp = new node1;
			temp->next = rear->next;
			rear->next = temp;

			cout << "What's the name of the question? " << endl;
			cin.get(na, 100, '\n');
			cin.ignore(100, '\n');
			temp->name = new char[strlen(na)+1];
			strcpy(temp->name, na);

			cout << "Please enter the question. " << endl;
			cin.get(qe, 200, '\n');
			cin.ignore(200, '\n');
			temp->qes = new char[strlen(qe)+1];
			strcpy(temp->qes, qe);

			cout << "Are you done with it? 1-yes 2-no " << endl;
			cin >> yn;
			if(yn == 1)
				temp->done = true;
			else
				temp->done = false;
		}
		cout << "Add more? 1-yes 2-no" << endl;
		cin >> yn1;
		cin.ignore();
	}
}

lab::lab(): study(NULL, 0), num(0),  feedback(NULL) //constructor
{
} 

lab::~lab()		//destructor
{
	delete [] feedback;
}
void lab::add()		//add
{

	char n[100];
	int l;
	cout << "What is the name of the material?" << endl;
	cin.get(n, 100, '\n');
	cin.ignore(100, '\n'); 		

	cout << "What's the level of the material?" << endl;	
	cin >> l;
	cin.ignore();
	name = new char[strlen(n)+1];
	strcpy(name, n);
	level = l;
	int nn;
	char f[200];
	cout <<"What number is the lab? " << endl;
	cin >> nn;
	cin.ignore();

	cout <<"Please enter the feedback. " << endl;
	cin.get(f, 200, '\n');
	cin.ignore(200, '\n');

	num = nn;
	feedback = new char[strlen(f)+1];
	strcpy(feedback, f);
}

void lab::display()		//display
{
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Lab# " << num << endl;
	cout << "Feedback: " << feedback << endl;
}
void lab::remove()		//remove
{
	delete [] feedback;
}
