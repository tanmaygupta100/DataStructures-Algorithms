Algorithm findLargestKey(root)
{
	// Find the largest key in a Binary Search Tree.
	// Input: rootNode - root node of the BST.
	// Output: largestKey - largest key/number in the BST.

	//Checking if the tree is empty:
	if rootNode is null:
	{
		return null // tree is indeed empty, because rootNode doesn't exist.
	}
	
	//Initializing currentNode as the rootNode for now:
	currentNode = rootNode

	//Traversing rightmost nodes in the tree:
	while currentNode.right is not null do: // aka, if a right child doesn't exist.
	{
		currentNode = currentNode.right
		// right-most children will always be larger than the current/root node.
	}

	// When no right children nodes left, currentNode is the largest:
	largestKey = currentNode.key
		// '.key' was used because we want the actual data in this location.
	return largestKey
}
