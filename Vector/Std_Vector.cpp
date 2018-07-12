/*
	Demonstrates some functions of the class vector from the standard library
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	std::vector<int> vec(10, 20);

	for(vector<int>::iterator h=vec.begin(); h!=vec.end(); h++)
		cout<< *h<< endl;

	return 0;
}