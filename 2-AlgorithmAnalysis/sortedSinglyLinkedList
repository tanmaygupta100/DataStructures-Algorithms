Algorithm sortedSinglyLinkedList(head)
{
  // Calculate the range of a singly sorted linked list.
		// A linked list is a list of nodes containing
			// information and pointers pointing to the next node.
		// A singly sorted linked list is a linked list in a particular order.
  // input: head - first node in linked list
  // ouput: range of set

	if head == 0 then return 0
		// if set is empty (has no elements), then there is no range
		// head is the first node

	// initializing the min/max values to store the node's data.
	minValue = head.nodeData // equal to the first node's data
	maxValue = head.nodeData
	currentNode = head // points to the first node (its location), not its data

	// loop to keep updating the minimum and maximum values:
	while currentNode != 0 do
	{
		if currentNode.value < minValue then minValue = currentNode.value
		else if currentNode.value > maxValue then maxValue = currentNode.value
		currentNode = currentNode.next
	}

	return maxValue - minValue
}
