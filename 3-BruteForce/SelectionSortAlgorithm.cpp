Algorithm selectionSort(A)
{
  // Taking the smallest element in an unsorted array and bringing it to the front.
    // Go through each item (from left to right) until you find the smallest one.
  // Input: A - list of sortable elements
  // Output: Sorted list in order

  n = length(A) // Size of array A assigned to variable n. Determines how many elements there are.

  // Iterates over each element in the array except the last one (so start to 2nd last).
  for i from 0 to n-2
  {
    // Keeps track of the index of the smallest element found in the inner loop:
    minIndex = i

    // Finds the smallest element in the unsorted part of the array:
    for j from i+1 to n-1
    {
      // Compares elements to find the smallest one:
      if A[j] < A[minIndex]
      {
        minIndex = j
      }
    }

    // Swaps the smallest element found with the first unsorted element:
    temp = A[i]
    A[i] = A[minIndex]
    A[minIndex] = temp
  }
}
