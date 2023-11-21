Algorithm ConnectedComponentVertices(graph)
{
  // Output the vertices of each connected component in a graph.
  // input: graph - graph
  // ouput: collection of sets (the sets are connected components)

	components = empty collection of sets
	allVertices == unvisited
	vertext = individual vertex

	for each vertex in graph do:
	{
		if vertex == unvisited then:
		{
			component = empty set
			vertex == visited
			component.add(vertex) // add vertex to component set

			stack = empty stack
			stack.push(vertex)

			//Do loop to fill stack of connected components
			while stack is not empty do:
			{
				//Checking pairs/connected components and adding their vertices together
					// then adding to the stacks.
				currentVertex = stack.pop()
				for each neighbor in graph adjacent to currentVertex do:
				{
					if neighbor == unvisited then:
					{
						neighbor == visited
						component.add(neighbor)
						stack.push(neighbor)
					}
				}

				components.add(component)
			}
		}
	}

	//Printing the finally connected components:
	return components
}
