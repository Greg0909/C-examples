#include <iostream>

using namespace std;
struct Node
{
	Node *next;
	int data;
};

class stack
{
	Node *top;
public:
	stack(int h)
	{
		top=new Node();
		top->data = h;
		top->next = NULL;
	}

	void push(int data)
	{
		if(top==NULL)
		{
			top=new Node();
		        top->data = data;
			top->next = NULL;
		}
		else
		{
			Node *n = new Node();
			n->data = data;
			n->next = top;
			top=n;
		}
	}

	bool isEmpty(){return top==NULL;}

	int peek(){return top->data;}
	
	void pop()
	{
		if(top!=NULL)
		{
			top=top->next;
		}
	}
};

int main()
{
	stack s(3);
	s.push(1);
	s.push(9);
	while(!s.isEmpty())
	{
		cout<< s.peek()<< " ";
		s.pop();
	}
	return 0;
}