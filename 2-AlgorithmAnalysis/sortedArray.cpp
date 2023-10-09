Algorithm sortedArray(array, n)
{
  // Calculate the range of a sorted array.
  // input: array - array; n - number of elements in array
  // ouput: range of set

	if n == 0 then return 0
		// if set is empty (has no elements), then there is no range
	
	else return array[n - 1] - array[0]
		// array[n - 1] : last element in array
		// array[0] : first element
		// subtracting the last from first gives the range.
}
