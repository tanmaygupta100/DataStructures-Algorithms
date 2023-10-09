Algorithm FindMissingInteger(A)
{
	// Find the missing integer in an array, in BigTheta(log n)
	// Input: A - increasing sorted array of integers from 1 to n,
		// 1 integer is missing.
	// Output: Missing integer.

	// Initializing the smallest/largers integers in the array:
	low = 0 // first value
	high = length(A) - 1 // last value

	while low < high do:
	{
		middle = (low + high) / 2 // the mean/average value

		//Checking the RIGHT half to see if the missing integer is there:
		if A[middle] - middle == A[low] - low then:
			// statement verifies if middle value is in lower half.
			// 'A[middle] - middle' checks if middle value is in middle spot.
			// 'A[low] - low' checks if lowest value is in lowest spot/index.
		{
			low = middle + 1
			// lowest space/index moves up with each loop.
		}
		//Checking the LEFT half now:
		else:
		{
			high = middle - 1
			// highest space/index moves down with each loop.
		}
	}

	// Missing integer is at the lowest index,
		// (aka furthest valid number from middle).
	return A[low] - 1
}
