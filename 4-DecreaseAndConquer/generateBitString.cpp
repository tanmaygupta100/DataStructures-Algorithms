Algorithm generateBitString(n, curString)
{
	// Generate all 2^n bit strings of legnth n, recursively.
	// input: n - integer, length of bit strings
		// curString - array, current bit string, contains all bit strings
	// output: array of all 2^n bit strings

	//If we've generated all bits (aka n is less than 1) then do this.
		// We count down from n to 1, so if less than 1, then n is done counting.
	if n < 1 then: // 1 is the base case for recursion
	{
		Print(curString) // Print the currently generated bit string
	}
	else:
	{
		curString[n-1] = 0 // Set current bit's position to 0.
		generateBitString(curString, n-1)
			// Recursively generate bit strings that have 1 less digit.
		curString[n-1] = 1 // Set current bit's position to 1.
		generateBigString(curString, n-1)
			// Runs again to generate all possible combinations of bit strings.
			// This is what does the recursion part basically,
				// breaking it down smaller and smaller.
	}
}
