/*
	Example of a recursive method of Binary search
*/
#include <iostream>

using namespace std;
                                                            //Takes the middle element and if it is the target returns
                                                            //the index, if not decides to search in the left when the
                                                            //middle element is bigger than the target and if it is 
                                                            //shorter it search in the right side.
int binary_search(int *arr, int begin, int end, int target)
{
	int middle = (end - begin)/2 +begin;

                                                            //The search ends when the target is find (arr[middle]==target)
                                                            //or the index begin gets bigger than index end, this means
                                                            //that the target couldnt be found in the array.
	while(begin<end)
	{
		if(arr[middle]==target) return middle;
                                                            //If the middle element is shorter than the target index 
                                                            //begin becomes the middle index +1 to search on the
                                                            //right side.
		if(arr[middle]<target)
			begin=middle+1;
                                                            //Else it search in the left side by updating the end index
                                                            //with middle -1.
		else
			end=middle-1;
		middle = (end - begin)/2 +begin;
	}
	return -1;
}

int main(){
	int array[12] = {1,1,1,2,2,2,3,4,5,6,7,8};
	int target = 8;
	cout << "The position of " << target << " is: " << binary_search(array,0 ,sizeof(array)/sizeof(int),target);
}