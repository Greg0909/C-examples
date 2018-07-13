/*
	Demonstrates some methods of the class vector from the standard library
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;
															//Pre-declaration of the method printVectorMethod_1 so it
															//can be used on the main method but declared after it.
template <typename T>
void printVectorMethod_1(std::vector<T> v);
															
															//This method has the same result of the method 
															//printVectorMethod_1 but a diferent procedure
template <typename T>
void printVectorMethod_2(const std::vector<T> v);

template <typename T>
void addToVector(std::vector<T> &v);

//=====================================================================================================================

int main() 
{
/*TASK-BEGIN*/												
															//The first parameter is the n objects that will be 
															//contained on the vector and the secondc is the value that
															//will be asigned to all the n objects.
	vector<int> first(10, 20);
	cout << "First vector:" << endl;
	printVectorMethod_1<int>(first);														
															//Output: 20 20 20 20 20 20 20 20 20 20
/*TASK-END*/	

/*TASK-BEGIN*/
	cout << "Second vector:" << endl;
															//Empty constructor which creates an empty vector
	vector<double> second;
	addToVector(second);
	printVectorMethod_2<double>(second);														
															//Output: depends on the given input of fillVector(second)
/*TASK-END*/

/*TASK-BEGIN*/
	cout << "Third vector:" << endl;
															//This constructor can also be writen as 
															//vector<double> third(second.begin(), second.end())
	vector<double> third(second);
	addToVector(third);
	printVectorMethod_1(third);
/*TASK-END*/

/*TASK-BEGIN*/
	cout << "Fourth vector:" << endl;
	string array[3];
	array[0] = "a";
	array[1] = "b";
	array[2] = "c";
															//Recives iterators, the first parameter is the iterator
															//that marks the begining and the second is the iterator 
															//which marks the end, so all the data between the begining
															//and ending is stored in the vector.
	vector<string> forth(array, array + sizeof(array)/sizeof(string));
	addToVector<string>(forth);
	printVectorMethod_2<string>(forth);
/*TASK-END*/

/*TASK-BEGIN*/
	cout<< "New first vector after insertion of the second vector" << endl;
															//Obtains the iterator that points to the next element 
															//after the middle of the first vector.
	vector<int>::iterator middle = first.begin() + (first.size()/2);
															//Inserts the data between the second and third parameters
															//(which are iterators) on the space before the first 
															//parameter, which is also an iterator.
	first.insert(middle, second.begin(), second.end());
	printVectorMethod_2(first);
/*TASK-END*/

/*TASK-BEGIN*/
	cout<< "New first vector after erasing some elements" << endl;
															//Deletes the element pointed by the iterator, in this case
															//its the first one.
	first.erase(first.begin());
															//Deletes the elements between the first iterator and the
															//last one.
	first.erase(first.end() -3, first.end());
	printVectorMethod_2(first);
/*TASK-END*/
	
	return 0;
}

//=====================================================================================================================

template <typename T>
															//The parameter cannot be declared as constant because
															//v.begin() and v.end() return a iterator who can cause a
															//change on the vector.
void printVectorMethod_1( std::vector<T> v)
{
	cout<<"Method 1: ";
															//Using an iterator we can go though all the objects on the
															//vector by initializing it on the begining of the vector
															//and aumenting its value while its diferent from the end 
															//of the vector.
	for(typename vector<T>::iterator h=v.begin(); h!=v.end(); h++)
															//The value of the iterator is the value of the pointed
															//object.
		cout<< "[" << *h<< "] ";

	cout<<endl<<endl;;
}

//---------------------------------------------------------------------------------------------------------------------

template <typename T>
void printVectorMethod_2(const vector<T> v)
{
	cout<<"Method 2: ";
															//The method .size() returns an usigned int with the number
															//of elemets contained on the vector.
	for(unsigned int h=0; h<v.size(); h++)
															//.at(h) returns the value of the object on the h position.
		cout<< "[" << v.at(h) << "] ";

	cout<<endl<<endl;;
}

//---------------------------------------------------------------------------------------------------------------------

template <typename T>
															//Ask for elements to add them to the vector, the procedure
															//finishes when you write esc.
void addToVector(std::vector<T> &v)
{
	cout << "Write an element and hit enter, repeat this process for every element you wanna add. \n(to finish write esc and hit enter)" << endl;
	T tTemp;
	string sTemp;
	while(sTemp != "esc")
	{
															//The following 3 lines make make posible to store the
															//input of cin in two variables (sTemp and tTemp).
		cin >> sTemp;
		istringstream s(sTemp);
		s >> tTemp;

		if(sTemp != "esc")
			v.push_back(tTemp); //Adds tTemp at the end of the vector.
	}
}