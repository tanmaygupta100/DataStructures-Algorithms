Algorithm patternDetector(text)
{
  // Counting how many times pattern 'AB' appears in a string.
  // input: text - string pattern
  // ouput: Count of desired string pattern appearing in larger string

	//Variable for the number of total letters in the larger string:
	n = text length

	//We want to count the times AB appears in a string:
	count = 0 // Initializing the count to start at 0.

	//Loop to find A from 0 to last value:
	for startingLetter from 0 to n-1 do:
	{
		//If A was found:
		if text[startingLetter] == 'A' then:
		{
			//If A was found, look for B:
			for endingLetter from startingLetter+1 to n-1 do:
				// +1 because we want to start from the spot after A.
			{
				//If B is found, increase counter for AB's appearances:
				if text[endingLetter] == 'B' then count++
			}
		}
	}

	//Return the count value:
	return count
}
