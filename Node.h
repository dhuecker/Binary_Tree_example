#ifndef Node_H
#define Node_H
class node
{
public:
	int data;
	node *left_child;
	node *right_child;

	node(int val) // normal constructor used that nulls the right and left childs
	{
		data = val;
		left_child = nullptr;
		right_child = nullptr; 

	}
	node() //default constructor
	{
		data = 0;
		left_child = nullptr;
		right_child = nullptr;
	}
};

#endif // !Node_H

