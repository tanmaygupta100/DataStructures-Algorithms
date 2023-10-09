Algorithm detectFullyConnectedMesh(A)
{
	// algorithm to detect a fully connected mesh
	// input: matrix A
	// output: true - it is a fully connected mesh, or false otherwise

	n = number of nodes // variable for size of matrix A

	//Check if there's at least 3 nodes minumum:
	if n <= 3 then return false

	//Go through each row of nodes in the matrix:
	for i from 0 to n-1 do:
	{
		neighborCount = 0 // initializing a variable that counts neighboring nodes

		//Go through each column of nodes in the matrix:
		for j from 0 to n-1 do:
		{
			//Check if matrix values (all neighbors) are valid,
				// then move onto the next node:
			if A[i][j] == true then neighborCount++
		}

		//Check if each node has n-1 neighbors:
			// Each node must neighbor every other node but itself.
		if neighborCount != n - 1 then return false
	}

	// If all criterias are met, it is valid!
	return true
}
