#ifndef Btree_H
#define Btree_H
#include "Node.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

class Btree {
private:
	node *root = nullptr; //intializes root to null

	void insert(node *userinput, node *& startpos)
	{
		if (startpos == nullptr) // runs if the tree is empty
		{
			startpos = userinput;
		}
		else {
			if (userinput->data < startpos->data) //determins if the value entered is greater or less than the root/other values. Then calls insert again recursively

			{ 
				insert(userinput, startpos->left_child);
			}
			else {
				insert(userinput, startpos->right_child);
			}
		}
	}
	void NLR(node*& startpos) {
		if (startpos == nullptr) {
			return;
		}
		cout << startpos->data << " ";
		NLR(startpos->left_child);
		NLR(startpos->right_child);

	}
	void LNR(node*& startpos) {
		if (startpos == nullptr) {
			return;
		}
		LNR(startpos->left_child);
		cout << startpos->data << " ";
		LNR(startpos->right_child);

	}
	void LRN(node*& startpos) {
		if (startpos == nullptr) {
			return;
		}
		LRN(startpos->left_child); //travels all the way to left first
		LRN(startpos->right_child); // then right
		cout << startpos->data << " "; // displays output
	}

	void graphics(node* starpos, int indent) //displays tree graphically having problems running incertain cases after delete fuction
	{
		if (starpos != NULL) {
			if (indent) {
				cout << setw(indent) << ' ';
			}
			cout <<starpos->data << endl ;
			if (starpos->left_child) graphics(starpos->left_child, indent - 4);
			if (starpos->right_child) graphics(starpos->right_child, indent + 4);
			
			
		}

	}
	
	void remove(node *&starpos, int val) {

		node* curr;
		node* parent = nullptr;
		curr = root;
		bool found = false;

		while (curr != nullptr)
		{
			if (curr->data == val)
			{
				found = true;
				break;
			}
			else
			{
				parent = curr;
				if (val>curr->data) curr = curr->right_child;
				else curr = curr->left_child;
			}
		}
		if (!found)
		{
			cout << " Data not found! " << endl;
			return;
		}

		// Node with single child
		if ((curr->left_child == nullptr && curr->right_child != nullptr) || (curr->left_child != nullptr && curr->right_child == nullptr))
		{
			if (curr->left_child == nullptr && curr->right_child != nullptr)
			{
				if (parent->left_child == curr)
				{
					parent->left_child = curr->right_child;
					delete curr;
				}
				else
				{
					parent->right_child = curr->left_child;
					delete curr;
				}
			}
			return;
		}

		//We're looking at a leaf node
		if (curr->left_child == nullptr && curr->right_child == nullptr)
		{
			if (parent->left_child == curr)
			{
				parent->left_child = nullptr;
			}
			else
			{
				parent->right_child = nullptr;
			}
			delete curr;
			return;
		}


		//Node with 2 children
		// replace node with smallest value in right subtree
		if (curr->left_child != nullptr && curr->right_child != nullptr)
		{
			node* chkr;
			chkr = curr->right_child;
			if ((chkr->left_child == nullptr) && (chkr->right_child == nullptr))
			{
				curr = chkr;
				delete chkr;
				curr->right_child = nullptr;
			}
			else // right child has children
			{
				//if the node's right child has a left child
				// Move all the way down left to locate smallest element

				if ((curr->right_child)->left_child != nullptr)
				{
					node* lcurr;
					node* lcurrp;
					lcurrp = curr->right_child;
					lcurr = (curr->right_child)->left_child;
					while (lcurr->left_child != nullptr)
					{
						lcurrp = lcurr;
						lcurr = lcurr->left_child;
					}
					curr->data = lcurr->data;
					delete lcurr;
					lcurrp->left_child = nullptr;
				}
				else
				{
					node* tmp;
					tmp = curr->right_child;
					curr->data = tmp->data;
					curr->right_child = tmp->right_child;
					delete tmp;
				}

			}
			return;
		}

	}
	
public:
	//must fuctions in public are overloaded and call their own private verison to gain access to root. Which is a private data type
	void remove(int val) {
		remove(root, val);
	}
	void graphics() {
		int indent = 30;
		node *curr = root;
		graphics(curr, indent);
	}
	void NLR() {
		NLR(root);
	}
	void LNR() {
		LNR(root);
	}
	void LRN() {
		LRN(root);
	}
	void insert(node *userinput) {
		insert(userinput, root);
	}
	void menu() //contains multiple cout statements that can be written in a function, instead of main
	{
		cout << "Student Name: \tDavid Huecker" << endl;
		cout << "Student ID: \t900657339" << endl << endl;
		cout << "\t\tWelcome to the Binary Tree Program" << endl << endl;
		cout << setw(30)<<"Menu" << endl << endl << "Enter 1 to display the current tree..." << endl;
		cout << "Enter 2 to see the tree printed in LNR..." << endl;
		cout << "Enter 3 to see the tree printed in NLR..." << endl;
		cout << "Enter 4 to see the tree printed in LRN..." << endl;
		cout << "Enter 5 to add a node to the tree..." << endl;
		cout << "Enter 6 to remove a node from the tree..." << endl;
		cout << "Enter 0 to end the program..." << endl;
	}

	
};
#endif // !Btree_H

