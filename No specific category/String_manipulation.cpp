#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string str = "This is the string";
	stringstream ss(str);

	do{
		string temp;
		ss>>temp;
                                                            //We validate ss because without it the last string would
                                                            //be printed twice.
		if(ss)
			cout << temp << endl;
                                                            //Output:
                                                            //This
                                                            //is
                                                            //the
                                                            //string
	}while(ss);


	str = "We modified the string";
	stringstream sss(str);
	std::vector<string> myVec;
	do{
		string temp;
		sss>>temp;
		if(sss)
			myVec.push_back(temp);
	}while(sss);

	for(vector<string>::iterator d = myVec.begin(); d!=myVec.end(); d++)
		cout << *d << endl;
	return 0;
}