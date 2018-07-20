/*
	Example of Linked List structure
*/

#include <iostream>

using namespace std;
                                                            //A list contains nodes that are conected in one way 
                                                            //direction. Theh have a head node that conectes to the 
                                                            //next node and that one to the next and so on. We can go
                                                            //from the first to the second but not from the second to
                                                            //the first.
struct Node
{
	Node *next;
	int data;

	Node(int dat)
	{
		next = NULL;
		data = dat;
	}
};

class Linked_List
{
	Node *head;
	public: 
	Linked_List(int dat)
	{
		head = new Node(dat);
	}
                                                            //The last node of the list connects/points to NULL, thats
	                                                        //why the process of adding a node at the end is runing 
                                                            //through all the list until the next node is NULL, thats
                                                            //where we create the new node.
	void add(int dat)
	{
		Node *current = head;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = new Node(dat);
	}
                                                            //Place the data from the parameter as the new head.
	void add_head(int dat)
	{
		Node *temp = new Node(dat); // dat |(head)3->6->9
		temp->next = head;          // dat->(head)3->6->9
		head = temp;                // (head)dat->3->6->9
	}
                                                            //Search for the first node (The target node) with the 
                                                            //data==dat and delete it by pointing the previous node
                                                            //to the next node of the target node.
	bool delete_Value(int dat)
	{
		if(head->data == dat)
		{
			head = head->next;
			return true;
		}

		Node *current = head;
		while(current->next != NULL)
		{
			if(current->next->data==dat)
			{
				current->next = current->next->next;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void print(){
		Node *current = head;
		cout<< current->data << " ";
		while(current->next != NULL)
		{
			current = current->next;
			cout<< current->data << " ";
		}
	}
};

int main()
{
	int num;
	cout << "Enter elements, to stop enter -1: ";
	cin>>num;
	Linked_List list(num);
	while(num!=-1){
		cin>>num;
		list.add(num);
	}
	cout <<"\nThe list: ";
	list.print();
	list.add_head(99);
	list.delete_Value(23);
	cout <<"\nThe new list: ";
	list.print();
	return 0;
}