#include "Node.h"
#include "Btree.h"
#include <iostream>

int main() {
	Btree mytree;
	int choice;
	int arrData[] = { 5,10,4,19,6 };//populates the binary tree, so user doesn't have to constantly input values
	for (int i = 0; i < 5; i++) {
		node *temp = new node(arrData[i]);
		mytree.insert(temp); //inserts the array values into the tree
	}
	
	mytree.menu();
	cout << endl << "Please enter your choice ";
	cin >> choice;
	do {
		switch (choice) //while the user doesn't enter 0 the program will continue to run 
		{
		case 0: break;
		case 1:mytree.graphics(); break; //displays the tree
		case 2: mytree.LNR(); break; //displays tree in LNR format
		case 3: mytree.NLR(); break;//displays tree in NLR format
		case 4: mytree.LRN(); break;//displays tree in LRN format
		case 5: {
			int val;
			cout << "Please enter the value you would like to add " << endl;
			cin >> val; //reads value the user wants to input
			node *temp2 = new node(val); //creates new node to hold value
			mytree.insert(temp2); // calls insert fuction
			cout <<endl <<"The tree printed is now " << endl;
			mytree.graphics(); // displays tree with new value
			//delete(temp2); // deletes temp node
			break;
		}
		case 6: //very similar to insert case but calls delete fuction after reading the value from user
		{
			int val2;
			cout << "Please enter the value you would like to delete " << endl;
			cin >> val2;
			mytree.remove(val2);
			cout << endl << "The tree printed is now " << endl;
			mytree.graphics();
			break; }
		default: cout << "You entered an invalid choice "; //Incase user inputs an option that isn't listed

		}
		cout << endl << endl<< "Enter another choice or 0 to end the program "; //Promps user for another choice
		cin >> choice;
		cout << endl;
	} while (choice != 0);

	if (choice == 0) //Displays when the user wants to leave the program
	{
		cout << "Thank you Goodbye";
	}


	cin.get();
	cin.ignore();
}
