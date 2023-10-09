Algorithm FindCycle(graph):
{
  // Identify a cycle in a graph if it exists,
		// if not, indicate that the graph is acyclic.
  // input: graph - graph
  // output: cycle - cycle (list of vertices that make the graph a cycle)
		// or a message indicating the graph is acylic.

	visited = empty set
  stack = empty stack // Stack for DFS traversal
  visitedFrom = empty map // Map to store visited vertices' parents

	//Iterate through each vertex in the graph:
  for each vertex v in graph do:
	{

    if v not in visited then:
		{
      visitedFrom[v] = None
      stack.push(v)

			// Perform DFS traversal
      while stack is not empty do:
			{
        currentVertex = stack.pop()
        visited.add(currentVertex)

				//Check neighbors of the current vertex:
        for each neighbor in graph adjacent to currentVertex do:
				{

          if neighbor not in visited do:
					{
            visitedFrom[neighbor] = currentVertex
            stack.push(neighbor)
					}
          else if visitedFrom[currentVertex] != neighbor do:
					{
            //After finding cycle, backtrack to find vertices in the cycle:
            cycle = [neighbor, currentVertex]
            previousVertex = visitedFrom[currentVertex]

            while previousVertex != neighbor do:
						{
              cycle.append(previousVertex)
              previousVertex = visitedFrom[previousVertex]
						}

            cycle.append(neighbor) // Close the cycle

            return cycle
					}
				}
			}
		}
	}

	return "Graph is acyclic."
}
