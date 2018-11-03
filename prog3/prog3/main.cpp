//Ching-Wei Lin 
//#987563037
//This program is about creating an avatar with many features and records all the information about the avatar


#include "avatar.h"

main()
{
	avatar model;		//the avatar
	int yn;			//temp variable
	
	model.history();	//enter history

	while(yn!=4)
	{
		cout <<"What do you like to do with the avatar? 1-add 2-display 3-remove all 4-quit " << endl;
		cin >> yn;
		cin.ignore();

		if(yn == 1)
		{
			model += 1;
		}
		if(yn == 2)
		{
			model + 1;
		}
		if(yn == 3)
		{
			model == 1;
		}
	}

	return 0;
}
