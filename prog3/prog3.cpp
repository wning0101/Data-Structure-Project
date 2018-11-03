//Ching-Wei Lin 
//#987563037
//This program is about creating an avatar with many features and records all the information about the avatar

#include "avatar.h"


chac::chac()		//constructor
{
	des = NULL;
}

chac::~chac()		//destructor
{
	delete [] des;
}

chac::chac(const chac & copy)	//copy constructor
{
	if(!copy.des)
		des = NULL;
	else
	{
		des = new char[strlen(copy.des)+1];
		strcpy(des, copy.des);
	}
}

chac::chac(char * copy)		//copy constructor
{
	if(!copy)
		des = NULL;
	else
	{
		des = new char[strlen(copy)+1];
		strcpy(des, copy);
	}
}
	
void chac::add()
{
}

void chac::display()
{
}

void chac::remove()
{
}

nick::nick(): chac(NULL), n_name(NULL)		//contructor
{
}

nick::~nick()			//destructor
{
	delete [] n_name;
}

void nick::add()		//add
{
	char ans[200];
	char nname[100];
	cout << "What's the description of the character? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	des = new char[strlen(ans)+1];
	strcpy(des, ans);

	cout << "What's the nick name? " << endl;
	cin.get(nname, 100, '\n');
	cin.ignore(100, '\n');

	n_name = new char[strlen(nname)+1];
	strcpy(n_name, nname);
}

void nick::display()		//display
{
	cout << "The description : " << des << endl;
	cout << "The nick name : " << n_name << endl;
}

void nick::remove()		//remove
{
	delete [] n_name;
	delete [] des;
}

contact::contact() : chac(NULL), con(NULL) 	//constructor
{
}

contact::~contact()			//destructor
{
	delete [] con;
}

void contact::add()		//add
{
	char ans[200];
	char ans1[200];
	cout << "What's the description of the character? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	des = new char[strlen(ans)+1];
	strcpy(des, ans);
	
	cout << "What's the contact? " << endl;
	cin.get(ans1, 200, '\n');
	cin.ignore(200, '\n');

	con = new char[strlen(ans1)+1];
	strcpy(con, ans1);
}

void contact::display()		//display
{
	cout << "The description : " << des << endl;
	cout << "The contact : " << con << endl;
}

void contact::remove()		//remove
{
	delete [] des;
	delete [] con;
}

website::website() : chac(NULL), web(NULL)	//constructor
{
}

website::~website()		//destructor
{
	delete [] des;
	delete [] web;
}

void website::add()		// add
{
	char ans[200];
	char ans1[200];
	cout << "What's the description of the character? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	des = new char[strlen(ans)+1];
	strcpy(des, ans);
	
	cout << "What's the contact? " << endl;
	cin.get(ans1, 200, '\n');
	cin.ignore(200, '\n');

	web = new char[strlen(ans1)+1];
	strcpy(web, ans1);
}

void website::display()		//display
{
	cout << "The description : " << des << endl;
	cout << "The website : " << web << endl;
}

void website::remove() 		//remove
{
	delete [] des;
	delete [] web;
}

p_num::p_num() : chac(NULL), num(0)
{
}

p_num::~p_num()
{
}

void p_num::add()		//add
{

	char ans[200];
	cout << "What's the description of the character? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	des = new char[strlen(ans)+1];
	strcpy(des, ans);

	cout << "What's the phone number? " << endl;
	cin >> num;
	cin.ignore();
}

void p_num::display()		//display
{
	cout << "The description : " << des << endl;
	cout << "The phone number : " << num << endl;
}

void p_num::remove()
{
	delete [] des;
}

cloth::cloth() : chac(NULL),style(NULL) 	//constructor
{
}

cloth::~cloth()				//destructor
{
	delete [] des;
	delete [] style;
}

void cloth::add()			//add
{
	char ans[200];
	char ans1[200];
	cout << "What's the description of the character? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	des = new char[strlen(ans)+1];
	strcpy(des, ans);
	
	cout << "What's the dressing style? " << endl;
	cin.get(ans1, 200, '\n');
	cin.ignore(200, '\n');

	style = new char[strlen(ans1)+1];
	strcpy(style, ans1);
}
	
void cloth::display()			//display
{
	cout << "The description : " << des << endl;
	cout << "The dressing style : " << style << endl;
}

void cloth::remove()			//remove
{
	delete [] des;
	delete [] style;
}


tool::tool()		//constructor
{
	level = 0;
}

tool::~tool()		//destructor
{
}

tool::tool(const tool & copy)	//copy constructor
{
	if(!copy.level)
		level = 0;
	else
	{
		level = copy.level;
	}
}

tool::tool(int copy)		//copy constructor
{
	if(!copy)
		level = 0;
	else
	{
		level = copy;
	}
}
	
void tool::add()
{
}

void tool::display()
{
}

void tool::remove()
{
}

weapon::weapon() : tool(0), damage(0), range(0)		//constructor
{
}

weapon::~weapon()			//destructor
{
}

void weapon::add()		//add
{
	cout << "What's the level of tool? " << endl;
	cin >> level;
	cin.ignore();

	cout << "What's the damage of the weapon? " << endl;
	cin >> damage;
	cin.ignore();

	cout << "What's the range of the weapon? " << endl;
	cin >> range;
	cin.ignore();
}

void weapon::display()		//display
{
	cout <<"Level : " << level << endl;
	cout <<"Damage : " << damage << endl;
	cout <<"Range : " << range << endl;
}

void weapon::remove()		//remove
{
	level = 0;
	damage = 0;
	range = 0;
}

supply::supply() : tool(0), recover(0)		//constructor
{
}

supply::~supply()		//destructor
{
}

void supply::add()		//add
{
	cout << "What's the level of tool? " << endl;
	cin >> level;
	cin.ignore();

	cout << "What's the amount of recovery? " << endl;
	cin >> recover;
	cin.ignore();
}

void supply::display()		//display
{
	cout << "Level : " << level << endl;
	cout << "Recovery : " << recover << endl;
}

void supply::remove()		//remove
{
	level = 0;
	recover = 0;
}

hint::hint() : tool(0), advice(NULL)	//constructor
{
}

hint::~hint()		//destructor 
{
	if(advice)
		delete [] advice;
}

void hint::add()		//add
{	
	char ans[200];
	cout << "What's the level of the tool? " << endl;
	cin >> level;
	cin.ignore();
	
	cout << "What's the advice? " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');

	advice = new char[strlen(ans)+1];
	strcpy(advice, ans);
}
	
void hint::display()		//display
{
	cout << "Level : " << level << endl;
	cout << "Advice : " << advice << endl;
}
void hint::remove()		//remove
{
	if(advice)
		delete [] advice;
}

avatar::avatar()		//constructor
{
	root = NULL;
	root1 = NULL;
	his = NULL;
}

avatar::~avatar()		//destructor
{
	remove_all(root);
	remove_all(root1);
	delete [] his;
}

int avatar::remove_all()		//remove all
{
	remove_all(root);
	remove_all(root1);
}

int avatar::remove_all(node *& tar)	//remove all
{
	if(!tar)
		return 0;
	if(tar->data[0])
		tar->data[0]->remove();
	if(tar->data[1])
		tar->data[1]->remove();
		
	remove_all(tar->ptr[0]);
	remove_all(tar->ptr[1]);
	remove_all(tar->ptr[2]);
	
	if(tar->ptr[0])
	{
		delete tar->ptr[0];
		tar->ptr[0] = NULL;
	}

	if(tar->ptr[1])
	{
		delete tar->ptr[1];
		tar->ptr[1] = NULL;
	}

	if(tar->ptr[2])
	{
		delete tar->ptr[2];
		tar->ptr[2] = NULL;
	}
}

int avatar::remove_all(node1 *& tar)	//remove all
{
	if(!tar)
		return 0;
	if(tar->data[0])
		tar->data[0]->remove();
	if(tar->data[1])
		tar->data[1]->remove();
		
	remove_all(tar->ptr[0]);
	remove_all(tar->ptr[1]);
	remove_all(tar->ptr[2]);
	
	if(tar->ptr[0])
	{
		delete tar->ptr[0];
		tar->ptr[0] = NULL;
	}

	if(tar->ptr[1])
	{
		delete tar->ptr[1];
		tar->ptr[1] = NULL;
	}

	if(tar->ptr[2])
	{
		delete tar->ptr[2];
		tar->ptr[2] = NULL;
	}
}
void avatar::history()			//enter history
{
	char ans[200];
	cout << "Please enter the history. " << endl;
	cin.get(ans, 200, '\n');
	cin.ignore(200, '\n');
	
	his = new char[strlen(ans)+1];
	strcpy(his, ans);
}
int avatar::display()	//display
{
	cout << "History : " << his << endl;
	cout << "Character : " << endl;
	if(root)
		disw(root);
	else
		cout << "There is no character. " << endl;
	cout << "Tool : " << endl;
	if(root1)
		disw(root1);
	else
		cout << "There is no tool. " << endl;
}

int avatar::disw(node * tar)		//wrapper function
{
	if(!tar)
		return 0;
	if(tar->data[0])
		tar->data[0]->display();
	if(tar->data[1])
		tar->data[1]->display();
	disw(tar->ptr[0]);
	disw(tar->ptr[1]);
	disw(tar->ptr[2]);
	return 1;
}

int avatar::disw(node1 * tar)		//wrapper function
{
	if(!tar)
		return 0;
	if(tar->data[0])
		tar->data[0]->display();
	if(tar->data[1])
		tar->data[1]->display();
	disw(tar->ptr[0]);
	disw(tar->ptr[1]);
	disw(tar->ptr[2]);
	return 1;
}

int avatar::add()	//add
{
	int yn;
	int yn1;
	int prii;

	cout << "What kind of item do you want to add?  1-character  2-tool " << endl;
	cin >> yn;
	cin.ignore();

	cout <<"What's the priority? " << endl;
	cin >> prii;
	cin.ignore();

	if(yn == 1)
	{	
		if(!root)
		{
			root = new node;
			root->pri[0] = prii;	
			writein(root->data[0]);	
		}
		else
		{
			addw(root, prii);
			reset(root);
		}
	}

	else
	{
		if(!root1)
		{
			root1 = new node1;
			root1->pri[0] = prii;
			writein(root1->data[0]);
		}
		else
		{
			addw(root1, prii);
			reset(root1);
		}
	}
}
int avatar::reset(node *& tar)			//reset the root
{
	if(!tar->parent)
		return 1;
	tar = tar->parent;
	return reset(tar);
}
	
int avatar::reset(node1 *& tar)			//reset the root
{
	if(!tar->parent)
		return 1;
	tar = tar->parent;
	return reset(tar);
}
int avatar::addw(node *& tar, int prii)		//wrapper
{
	if(!tar->ptr[0] && !tar->ptr[1] && !tar->ptr[2])
	{
		if(!tar->pri[1])
		{
			if(prii > tar->pri[0])
			{	
			tar->pri[1] = prii;
			writein(tar->data[1]);
			return 1;
			}
			else
			{
			tar->pri[1] = tar->pri[0];
			tar->data[1] = tar->data[0];
			tar->pri[0] = prii;
			writein(tar->data[0]);
			return 1;
			}
		}	
		else
		{
			if(!tar->parent)
			{
				if(prii > tar->pri[1])
				{
					tar->parent = new node;
					tar->parent->data[0] = tar->data[1];
					tar->parent->pri[0] = tar->pri[1];
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node;
					tar->parent->ptr[2]->pri[0] = prii;
					writein(tar->parent->ptr[2]->data[0]);
					tar->parent->ptr[2]->parent = tar->parent;
					return 1;
				}
				else if(prii > tar->pri[0])
				{
					tar->parent = new node;
					writein(tar->parent->data[0]);
					tar->parent->pri[0] = prii;
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node;
					tar->parent->ptr[2]->data[0] = tar->data[1];
					tar->parent->ptr[2]->pri[0] = tar->pri[1];
					tar->parent->ptr[2]->parent = tar->parent;
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					return 1;
				}
				else
				{
					tar->parent = new node;
					tar->parent->data[0] = tar->data[0];
					tar->parent->pri[0] = tar->pri[0];
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node;
					tar->parent->ptr[2]->data[0] = tar->data[1];
					tar->parent->ptr[2]->pri[0] = tar->pri[1];
					tar->parent->ptr[2]->parent = tar->parent;
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					writein(tar->data[0]);
					tar->pri[0] = prii;
					return 1;
				}

			}
			else
			{
					if(!tar->parent->ptr[1])
					{
						if(prii > tar->pri[1])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->data[0] = tar->data[1];
							tar->parent->pri[0] = tar->pri[1];
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = tar->pri[0];
							tar->parent->ptr[1]->data[0] = tar->data[0];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->pri[1];
							tar->parent->data[1] = tar->data[1];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
						}
						else if(prii > tar->pri[0])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = prii;
							writein(tar->parent->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = tar->pri[0];
							tar->parent->ptr[1]->data[0] = tar->data[0];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							tar->parent->pri[1] = prii;
							writein(tar->parent->data[1]);
							return 1;
							}
						}

						else
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = tar->pri[0];
							tar->parent->data[0] = tar->data[0];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}	
							else
							{
							tar->parent->ptr[1] = new node;
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->pri[0];
							tar->parent->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}
						}
							
					}
					else
					{
						if(prii > tar->pri[1])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->data[0] = tar->data[1];
							tar->parent->pri[0] = tar->pri[1];
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1]->pri[1] = tar->pri[0];
							tar->parent->ptr[1]->data[1] = tar->data[0];
							tar->parent->pri[1] = tar->pri[1];
							tar->parent->data[1] = tar->data[1];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
						}
						else if(prii > tar->pri[0])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = prii;
							writein(tar->parent->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1]->pri[1] = tar->pri[0];
							tar->parent->ptr[1]->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							tar->parent->pri[1] = prii;
							writein(tar->parent->data[1]);
							return 1;
							}
						}

						else
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = tar->pri[0];
							tar->parent->data[0] = tar->data[0];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}	
							else
							{
							tar->parent->ptr[1]->pri[1] = prii;
							writein(tar->parent->ptr[1]->data[1]);
							tar->parent->pri[1] = tar->pri[0];
							tar->parent->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}
						}
						
						
					}
			}
		}	
	}
	else
	{
		if(!tar->pri[1])
		{
			if(prii > tar->pri[0])
			{
				return addw(tar->ptr[2], prii);
			}
			else
			{
				return addw(tar->ptr[0], prii);
			}
		}
		else
		{
			if(prii > tar->pri[1])
			{
				return addw(tar->ptr[2], prii);
			}
			else if(prii > tar->pri[0])
			{
				return addw(tar->ptr[1], prii);
			}
			else
			{
				return addw(tar->ptr[0], prii);
			}
		}
	}
}

int avatar::addw(node1 *& tar, int prii)		//wrapper
{
	if(!tar->ptr[0] && !tar->ptr[1] && !tar->ptr[2])
	{
		if(!tar->pri[1])
		{
			if(prii > tar->pri[0])
			{	
			tar->pri[1] = prii;
			writein(tar->data[1]);
			return 1;
			}
			else
			{
			tar->pri[1] = tar->pri[0];
			tar->data[1] = tar->data[0];
			tar->pri[0] = prii;
			writein(tar->data[0]);
			return 1;
			}
		}	
		else
		{
			if(!tar->parent)
			{
				if(prii > tar->pri[1])
				{
					tar->parent = new node1;
					tar->parent->data[0] = tar->data[1];
					tar->parent->pri[0] = tar->pri[1];
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node1;
					tar->parent->ptr[2]->pri[0] = prii;
					writein(tar->parent->ptr[2]->data[0]);
					tar->parent->ptr[2]->parent = tar->parent;
					return 1;
				}
				else if(prii > tar->pri[0])
				{
					tar->parent = new node1;
					writein(tar->parent->data[0]);
					tar->parent->pri[0] = prii;
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node1;
					tar->parent->ptr[2]->data[0] = tar->data[1];
					tar->parent->ptr[2]->pri[0] = tar->pri[1];
					tar->parent->ptr[2]->parent = tar->parent;
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					return 1;
				}
				else
				{
					tar->parent = new node1;
					tar->parent->data[0] = tar->data[0];
					tar->parent->pri[0] = tar->pri[0];
					tar->parent->ptr[0] = tar;
					tar->parent->ptr[2] = new node1;
					tar->parent->ptr[2]->data[0] = tar->data[1];
					tar->parent->ptr[2]->pri[0] = tar->pri[1];
					tar->parent->ptr[2]->parent = tar->parent;
					tar->data[1] = NULL;
					tar->pri[1] = 0;
					writein(tar->data[0]);
					tar->pri[0] = prii;
					return 1;
				}

			}
			else
			{
					if(!tar->parent->ptr[1])
					{
						if(prii > tar->pri[1])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->data[0] = tar->data[1];
							tar->parent->pri[0] = tar->pri[1];
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = tar->pri[0];
							tar->parent->ptr[1]->data[0] = tar->data[0];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->pri[1];
							tar->parent->data[1] = tar->data[1];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
						}
						else if(prii > tar->pri[0])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = prii;
							writein(tar->parent->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = tar->pri[0];
							tar->parent->ptr[1]->data[0] = tar->data[0];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							tar->parent->pri[1] = prii;
							writein(tar->parent->data[1]);
							return 1;
							}
						}

						else
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = tar->pri[0];
							tar->parent->data[0] = tar->data[0];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}	
							else
							{
							tar->parent->ptr[1] = new node1;
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->ptr[1]->parent = tar->parent;
							tar->parent->pri[1] = tar->pri[0];
							tar->parent->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}
						}
							
					}
					else
					{
						if(prii > tar->pri[1])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = prii;
							writein(tar->parent->ptr[1]->data[0]);
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->data[0] = tar->data[1];
							tar->parent->pri[0] = tar->pri[1];
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1]->pri[1] = tar->pri[0];
							tar->parent->ptr[1]->data[1] = tar->data[0];
							tar->parent->pri[1] = tar->pri[1];
							tar->parent->data[1] = tar->data[1];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
						}
						else if(prii > tar->pri[0])
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = prii;
							writein(tar->parent->data[0]);
							tar->data[1] = NULL;
							tar->pri[1] = 0;
							return 1;
							}
							else
							{
							tar->parent->ptr[1]->pri[1] = tar->pri[0];
							tar->parent->ptr[1]->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							tar->parent->pri[1] = prii;
							writein(tar->parent->data[1]);
							return 1;
							}
						}

						else
						{
							if(tar == tar->parent->ptr[0])
							{
							tar->parent->ptr[1]->pri[1] = tar->parent->ptr[1]->pri[0];
							tar->parent->ptr[1]->data[1] = tar->parent->ptr[1]->data[0];
							tar->parent->ptr[1]->pri[0] = tar->pri[1];
							tar->parent->ptr[1]->data[0] = tar->data[1];
							tar->parent->pri[1] = tar->parent->pri[0];
							tar->parent->data[1] = tar->parent->data[0];
							tar->parent->pri[0] = tar->pri[0];
							tar->parent->data[0] = tar->data[0];
							tar->pri[0] = prii;
							writein(tar->data[0]);
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}	
							else
							{
							tar->parent->ptr[1]->pri[1] = prii;
							writein(tar->parent->ptr[1]->data[1]);
							tar->parent->pri[1] = tar->pri[0];
							tar->parent->data[1] = tar->data[0];
							tar->pri[0] = tar->pri[1];
							tar->data[0] = tar->data[1];
							tar->pri[1] = 0;
							tar->data[1] = NULL;
							return 1;
							}
						}
						
						
					}
			}
		}	
	}
	else
	{
		if(!tar->pri[1])
		{
			if(prii > tar->pri[0])
			{
				return addw(tar->ptr[2], prii);
			}
			else
			{
				return addw(tar->ptr[0], prii);
			}
		}
		else
		{
			if(prii > tar->pri[1])
			{
				return addw(tar->ptr[2], prii);
			}
			else if(prii > tar->pri[0])
			{
				return addw(tar->ptr[1], prii);
			}
			else
			{
				return addw(tar->ptr[0], prii);
			}
		}
	}
}

int avatar::writein(chac *& tar)
{
	int yn1;
	
	cout << "What kind of character it is? 1-nick name 2-contact 3-website 4-phone number 5-cloth " << endl;
	cin >> yn1;
	cin.ignore();
	
	if(yn1==1)
	{
		tar = new nick;
		tar->add();
	}
	if(yn1==2)
	{
		tar = new contact;
		tar->add();
	}
	if(yn1==3)
	{
		tar = new website;
		tar->add();
	}
	if(yn1==4)
	{
		tar = new p_num;
		tar->add();
	}	
	if(yn1==5)
	{
		tar = new cloth;
		tar->add();
	}
	return 1;
}
	

int avatar::writein(tool *& tar)
{
	int yn1;
	
	cout << "What kind of tool it is? 1-weapon 2-supply 3-hint " << endl;
	cin >> yn1;
	if(yn1==1)
	{
		tar = new weapon;
		tar->add();
	}
	if(yn1==2)
	{
		tar = new supply;
		tar->add();
	}
	if(yn1==3)
	{
		tar = new hint;
		tar->add();
	}
	return 1;
}




avatar & avatar::operator += (int p)
{
	this->add();
	return *this;
}

avatar avatar::operator + (int p) 
{
	this->display();
	return *this;
}

avatar & avatar::operator == (int p)
{
	this->remove_all();
	return *this;
}
