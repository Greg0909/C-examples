/*
	Example of a Merge sort algorithm
*/
#include <iostream>

using namespace std;

void order(int *arr, int begin, int end);

void merge_sort(int *arr, int begin, int end){
	if(begin == end) return;
	int middle = ((end - begin)/2) +begin;
	merge_sort(arr, begin, middle);
	merge_sort(arr, middle+1, end);
	order(arr, begin, end);
	
}

                                                            //Takes an array and a range of its elements, divides the
                                                            //array in two halfs and order its numbers from smallest
                                                            //to bigest. This new order is inserted on the parameter 
                                                            //array in the corresponding range of index.
void order(int *arr, int begin, int end){
                                                            //In temp, the elements in the range are stred in order so
															//they can be copied in the original array.
	int temp[end-begin+1];
                                                            //The array has 2 halfs, the right and the left.
	int rightEnd = (end - begin)/2 + begin;
	int leftBegin = rightEnd+1;
                                                            //Right and left are the indexes that will be used to 
                                                            //run through both halfs.
	int left = leftBegin;
	int right = begin;
                                                            //The temp array should be completely filled thats why h 
                                                            //will increase until it pases end-begin which is the 
                                                            //number of elements on the desired range. 
	for(int h=0; h<=end-begin; ++h)
	{
                                                            //If the [left index has surpase the range limit (left>end)
                                                            //or the element on the right side is smaller than the one
                                                            //int the left] and [we are sure that the right index is 
                                                            //still in range of its half] the numer on the right half 
                                                            //is added to temp nad the right index advances.
		if((left>end || arr[right]<arr[left]) && right <= rightEnd)
		{
			temp[h] = arr[right];
			++right;
		}
                                                            //If the left number is smaller than the right one or the
                                                            //right index is out of limit.
		else
		{
			temp[h] = arr[left];
			++left;
		}
	}
	
                                                            //After the temp array is filled with the ordered range of 
                                                            //elements they are pased to the original array.
	int index=0;
	for(int h=begin; h<=end; ++h)
	{
		arr[h] = temp[index];
		index++;
	}
}

int main(){
	int array[12] = {4,6,7,1,3,10,8, 200, 2, 3, 90, 199};

	cout << "Unordered array: ";

	for(int h:array)
		cout << h << " ";
	merge_sort(array, 0, sizeof(array)/sizeof(int)-1);

	cout << "\nOrdered array: ";

	for(int h:array)
		cout << h << " ";
	return 0;
}