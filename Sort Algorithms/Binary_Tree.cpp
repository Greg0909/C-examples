/*
	Example of a Tree structure
*/
# include <iostream>

using namespace std;
                                                            //A tree has one root and can have 2 children and those 
                                                            //children can have each of one 2 children and this goes
                                                            //on and on.
struct Tree_Node
{
                                                            //The two children, left and right.
	Tree_Node *left, *right;
	int data;

	Tree_Node(int data)
	{
		left=NULL;
		right=NULL;
		this->data = data;
	}

                                                            //Recursive method that inserts the data with the lagic: 
                                                            //when it is bigger than the actual data it goes to the
                                                            //right branch and when is smaller goes to the left branch,
                                                            //then when there is no more nodes it creates a new node 
                                                            //with the data, if there is a node it keeps going down the 
                                                            //tree following the logic mentioned above.
	void insert(int d)
	{
		if(d<data)
		{
			if(left==NULL)
				left = new Tree_Node(d);
			else
				left->insert(d);
		}
		else
		{
			if(right==NULL)
				right=new Tree_Node(d);
			else
				right->insert(d);
		}
	}

                                                            //Search for the left node and goes all the way down recursively 
                                                            //until it reaches a dead end, then it prints the data and 
                                                            //goes to the right always having a left preference and prints 
                                                            //the data when there is no way to the left, visited nodes 
                                                            //dosent count as a way to the left. When there is no way down it
                                                            //returns up. 
	void inorder()
	{
		if(left!=NULL)
			left->inorder();
		cout << data << " ";
		if(right!=NULL)
			right->inorder();
	}
} ;

int main()
{
	int data;
	cout << "Enter the tree elements: ";
	cin>>data;
	Tree_Node root(data);

	while(data!=-1)
	{
		cin>>data;
		if(data!=-1)
			root.insert(data);
	}

	root.inorder();
	return 0;
}