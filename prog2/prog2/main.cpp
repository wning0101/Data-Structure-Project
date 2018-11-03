// Ching-Wei Lin
// 987563037
// This program is used to manage the material for studying in course.

#include "course.h"


main()
{
	list info;			//DLL for study material
	int yn=0;			//temp variables
	int type=0;
	char match[100];
	while(yn!=5)
	{
		cout << "What do you want to do with the list? 1-add material  2-display  3-remove one material  4-remove all  5-quit" << endl;
		cin >> yn;
		cin.ignore();
		if(yn==1)
		{
			cout << "What type is the material? 1-reading 2-exercise 3-lab " << endl;
			cin >> type;
			cin.ignore();
		
			if(type==1)
			{
				info.add();
				info.head->data = new read;
				info.head->data->add();
			}
			if(type==2)
			{
				info.add();
				info.head->data = new exer;
				info.head->data->add();
			}
			if(type==3)
			{
				info.add();
				info.head->data = new lab;
				info.head->data->add();
			}
		}
		if(yn==2)
		{
			info.display();
		}
		if(yn==3)
		{
			cout << "Which material do you want to remove? enter the name " << endl;
			cin.get(match, 100, '\n');
			cin.ignore(100, '\n');
			
			info.remove(match);
		}
		if(yn==4)
		{
			info.clear_all();
		}
	}
	
			
			
	return 0;
}
