// Selection sort algorithm implementation:

#include <bits/stdc++.h>
using namespace std;

// Function for Selection sort
void selectionSort(int arrary[], int n)
{
	int i, j, min_index;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in
		// unsorted array
		min_index = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] < arr[min_index])
				min_idx = j;
		}

		// Swap the found minimum element
		// with the first element
		if (min_index != i)
			swap(arr[min_index], array[i]);
	}
}

// Function to print an array
void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << array[i] << " ";
		cout << endl;
	}
}

// Driver program
int main()
{
	int array[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(array) / sizeof(array[0]);

	// Function Call
	selectionSort(array, n);
	cout << "Sorted array: \n";
	printArray(array, n);
	return 0;
}

/* SAMPLE OUTPUT:
__________________
Sorted array:
11 12 22 25 64
__________________
*/
