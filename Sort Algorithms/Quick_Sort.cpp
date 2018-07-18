/*
	Example of Quick Sort
*/

#include <iostream>

using namespace std;
                                                            //Takes a middle element and run trhough all the elements
                                                            //from both sides until it reaches the middle, swaping the
                                                            //pair of elements containing on the left a element greater
                                                            //than the middle one and on the right a smaller one.
void quick_sort(int *arr, int begin, int end){
                                                            //This recursive method ends when the begin idex is greater 
                                                            //or equal to the end index.
	if(begin>=end) return;
                                                            //The following to varaibles are the indexes to run through
                                                            //both half of the array.
	int left=begin;
	int right=end;

	int middle = (end - begin)/2 + begin;

	while(left<right)
	{
                                                            //Finds an element from the left side that is bigger than
                                                            //the middle element, if it fails the left index ends as 
                                                            //the middle index.
		while(left<right && arr[left]<arr[middle])
			++left;
                                                            //Finds an element from the right side that is bigger than
                                                            //the middle element, if it fails the right index ends as 
                                                            //the middle index.
		while(left<right && arr[right]>arr[middle])
			--right;
                                                            //Swaps the pair of elements and addvance the left and
                                                            //right indexes.
		if(left<right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			++left;
			--right;
		}
	}
                                                            //Calls the recursive method for the left and right halfs.
	quick_sort(arr, begin, middle);
	quick_sort(arr, middle+1, end);
}

int main()
{
	int array[6] = {2,3,1,4,6,7};
	quick_sort(array, 0, sizeof(array)/sizeof(int));
	cout << "Ordered array: ";
	for(int h:array)
		cout << h << " ";
	return 0;
}