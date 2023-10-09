Algorithm unsortedArray(array, n)
{
  // Calculate the range of an unsorted array.
  // input: array - array; n - number of elements in array
  // ouput: range of set
	
	if n == 0 then return
		// if set is empty (has no elements), then there is no range
	
	// these will store the minimum/maximum values' location
	minValue = array[0] // initializing the minValue variable as 0.
	maxValue = array[0] // initializing the maxValue variable as 0.

	// do the loop from the start to last value
	for i = 1 to n - 1 do
	{
		if array[i] < minValue then minValue = array[i]
			// Check EACH value in the array.
			// If the value at array location is less than minimum,
			// then THAT is the new lowest value.
		else if array[i] > maxValue then maxValue = array[i]
			// if current value is higher than max, make current the new max.
	}

	return maxValue - minValue
		// returns the range between the max and min values.
}
