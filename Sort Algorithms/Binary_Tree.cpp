/*
	Example of a Tree structure
*/
# include <iostream>
#include <queue>

using namespace std;
                                                            //A tree has one root and can have 2 children and those 
                                                            //children can have each of one 2 children and this goes
                                                            //on and on.
struct Tree_Node
{
public:
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

	void print()
	{
		Tree_Node cn = *this;
		queue<Tree_Node> st;
		queue<Tree_Node> temp;
		st.push(cn);
		temp.push(cn);
		int level=0;
		int count=0;
		while(!st.empty())
		{
			cout << cn.data << " ";
			if(count>=level*4)
			{
				count=0;
				++level;
				cout<<endl;
			}
			if(cn.left!=NULL)
			{
				if(cn.data!=-1){
					st.push(*cn.left);
					temp.push(*cn.left);
				}
			}
			else{
				if(cn.data!=-1){
				Tree_Node dum(-1);
				st.push(dum);
				temp.push(dum);
			}
			}

			if(cn.right!=NULL)
			{
				if(cn.data!=-1){
					st.push(*cn.right);
					temp.push(*cn.right);
				}
			}
			else{
				if(cn.data!=-1){
				Tree_Node dum(-1);
				st.push(dum);
				temp.push(dum);
			}
			}
			count+=2;
			st.pop();
			cn = st.front();
		}

/*

		int max_level = level;
		cout<<max_level<<endl;
		level =0;
		count =0;
		int espacios = 6*power(2,max_level);
		while(!temp.empty())
		{
			for(int h=0; h<espacios/power(2,level+1)/2 -5 ; h++)
					cout<<" ";
			do
			{
				cout << temp.front().data;
				temp.pop();
				++count;
				for(int h=0; h<espacios/power(2,level)/2 -1; h++)
					cout<<" ";
			}while(count < level*2);
			++level;
			cout<<endl;
			count=0;
		}
*/
	}

	int power (int x, int pow) 
	{ 
		int temp=x;
		for(int h=1; h<pow; h++)
			temp*=temp;
		return temp;
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
	cout << "\n\n";
	root.print();
	return 0;
}