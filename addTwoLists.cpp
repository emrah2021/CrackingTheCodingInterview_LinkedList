int main()
{
	// add two lists
	Node* head11 = NULL;
	Node* first11 = new Node(3);
	Node* second11 = new Node(1);
	Node* third11 = new Node(5);
	head11 = first11;
	first11->setNext(second11);
	second11->setNext(third11);
	third11->setNext(NULL);

	Node* head22 = NULL;
	Node* first22 = new Node(5);
	Node* second22 = new Node(9);
	Node* third22 = new Node(2);
	head22 = first22;
	first22->setNext(second22);
	second22->setNext(third22);
	third22->setNext(NULL);

	Node* result = head11->addTwoLists(head11, head22, 0);
	printLinkedList(result);
	
	cin.get();
	return 0;
}
