Algorithm cliqueProblem(G, k)
{
  // Finding a clique of size k in graph G.
  // input: G - graph, k - size of clique.
  // ouput: True if a clique of size k exists in graph G.

	n = number of vertices in G // vertices/nodes/points
	verticesList = list of all vertices in G
	combinations = all possible combinations of vertices/nodes
		// This list contains ALL cliques/groups in an array.
			// Each clique should be of size k, existing in graph G.

	//Checking through each possible clique in combination
	for clique in combinations do:
	{
		cliqueFound = true
			// All cliques are iniqualized as true until one is proven invalid.

		//For every pair of vertices, check if they are a valid group:
		for i from 0 to k-1 // starting the loop for the 1st value in pair.
		{
			for j from 0 to k-1 // starting the loop for the 2nd value in pair.
			{
				if G[clique[i]][clique[j]] == 0 then do:
				{
					cliqueFound = false
					break
				}
			}

		//If no disjointed pairs were found, it's a valid clique!
		if cliqueFound = true then return true
		}
	}

	//No valid clique was found (being of size k):
	return false
}
