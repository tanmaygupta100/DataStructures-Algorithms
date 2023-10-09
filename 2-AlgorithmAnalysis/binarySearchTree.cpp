Algorithm binarySearchTree(root)
{
  // Calculate the range of a binary search tree.
  // input: root - root node of the tree
  // ouput: range of set

	if rootNode == 0 then return 0
		// if set is empty (has no elements), then there is no range
		// root is the starting node of the tree.
	
	// Initializing values
	minValue = rootNode.value
	maxValue = rootNode.value
	stack = new Stack() // creating a new stack
	currentNode = rootNode // used for traversal and the location initializing

// Going through the list using a loop:
// We only check the left side because it's the ascending order.
		// if node exists and stack isn't empty and current node exists:
	while currentNode != 0 or stack.isEmpty != true() do:
	{
		while currentNode != 0 do: // while current node exists
		{
			stack.push(currentNode) // add current element to the top of stack
			currentNode = currentNode.left // set element on left as the current node.
		}
		currentNode = stack.pop() //

		// Check and update the min/max values:
		if currentNode.value < minValue then minValue = currentNode.value
		else if currentNode.value > maxValue then maxValue = currentNode.value
		
		// Now move onto the right values to check them:
		currentNode = currentNode.right
	}

	return maxValue - minValue // return the range
}
