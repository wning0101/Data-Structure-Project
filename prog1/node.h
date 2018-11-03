// Ching-Wei Lin
// 987563037
// This is a delivery system that can assign the way to deliver and 
// estimate the delivery time and fee

class pack     // package
{
	public:
		pack(); //constructor
		~pack(); //destructor
		int weight;   //weight of package
		char * des;   //destination
		char * name; //name
};

class node    //collection of package list
{
	public:
		pack data;    //package data
		node * next; 
};
