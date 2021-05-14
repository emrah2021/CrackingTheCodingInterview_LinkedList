#include "Node.h"

using namespace std;

Node::Node(int num)
{
	number = num;
}

void Node::setData(int num)
{
	number = num;
}

int Node::getData()
{
	return number;
}

void Node::setNext(Node * n)
{
	next = n;
}

Node * Node::getNext()
{
	return next;
}

void Node::appendToTail(int num)
{
	Node* end = new Node(num);
	Node* n = this;
	while (n->getNext() != NULL)
		n = n->getNext();
	n->setNext(end);
}

Node* Node::deleteNode(Node* head, int number)
{
	Node* tempNode = NULL;
	tempNode = head;

	// empty linked list
	if (head == NULL)
		return NULL;

	// head moved to next
	if (tempNode->getData() == number)
	{
		return tempNode->getNext();
	}

	while (tempNode != NULL)
	{
		if (tempNode->getNext()->getData() == number)
		{
			tempNode->setNext(tempNode->getNext()->getNext());
			return head;
		}
		tempNode = tempNode->getNext();
	}
}

void Node::printLinkedList(Node* node)
{
	while (node != NULL)
	{
		cout << "Node number: " << node->getData() << endl;
		node = node->getNext();
	}
}

Node* Node::findLoopNodeCircularList(Node* head)
{
	Node* fastNode = NULL;
	Node* slowNode = NULL;

	if (head == NULL)
		return NULL;
	else if (head->getNext() == NULL)
		return NULL;

	fastNode = head;
	slowNode = head;

	while (true)
	{
		if (fastNode == NULL)
			break;

		fastNode = fastNode->getNext()->getNext();
		slowNode = slowNode->getNext();

		if (fastNode == slowNode)
			break;
	}

	// list is not circular
	if (fastNode == NULL)
		return fastNode;
	// circular node find
	else
	{
		slowNode = head;
		while (fastNode != slowNode)
		{
			fastNode = fastNode->getNext();
			slowNode = slowNode->getNext();
		}
	}

	return fastNode;
}

Node* Node::removeDubs(Node* head)
{
	Node* removedList = NULL;
	removedList = head;

	// empty linked list
	if (head == NULL)
		return NULL;

	map<int, bool> numExistMap;
	map<int, bool>::iterator it;

	// head moved to next
	if (removedList->getNext() == NULL)
	{
		return removedList;
	}

	numExistMap.insert(pair<int, bool>(removedList->getData(), true));

	while (removedList != NULL)
	{
		// last element, break
		if (removedList->getNext() == NULL)
			break;
		else
			it = numExistMap.find(removedList->getNext()->getData());

		// number is not found
		if (it == numExistMap.end())
		{
			numExistMap.insert(pair<int, bool>(removedList->getNext()->getData(), true));
			removedList = removedList->getNext();
		}
		// number found
		else
		{
			removedList->setNext(removedList->getNext()->getNext());
			removedList = removedList->getNext();
		}
	}

	return head;
}

Node* Node::findNthElementToLast(Node* head, int n)
{
	Node* currentNode = NULL;
	Node* returnNode = NULL;
	int counter = 0;
	currentNode = head;
	returnNode = head;

	if (head == NULL)
		return head;

	while (currentNode != NULL)
	{
		currentNode = currentNode->getNext();
		++counter;
		// start increment returnNode
		if (counter > n)
			returnNode = returnNode->getNext();
	}

	return returnNode;
}

Node* Node::deleteMiddleNode(Node* head)
{
	Node* currentNode = NULL;
	Node* deleteNode = NULL;
	currentNode = head;
	deleteNode = head;

	if (head == NULL)
		return head;

	while (true)
	{
		if ((currentNode->getNext()->getNext() == NULL) || (currentNode->getNext()->getNext()->getNext() == NULL))
		{
			deleteNode->setNext(deleteNode->getNext()->getNext());
			break;
		}
		else
		{
			currentNode = currentNode->getNext()->getNext();
			deleteNode = deleteNode->getNext();
		}
	}

	return head;
}

Node* Node::addTwoLists(Node* head1, Node* head2, int carry)
{
	Node* resultNode = new Node(0);
	int value = carry;

	if (head1 == NULL && head2 == NULL)
	{
		resultNode->setNext(NULL);
		return NULL;
	}

	if (head1 != NULL)
	{
		value += head1->getData();
		head1 = head1->getNext();
	}

	if (head2 != NULL)
	{
		value += head2->getData();
		head2 = head2->getNext();
	}

	resultNode->setData(value % 10);
	value = value / 10;
	Node* more = addTwoLists(head1, head2, value);
	resultNode->setNext(more);

	return resultNode;
}
