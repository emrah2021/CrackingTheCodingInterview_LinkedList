#include <stdio.h>
#include <iostream>
#include <list>
#include <map>
#include "Node.h"

using namespace std;

Node* flattenList = NULL;
bool endOfList = false;
void flatten(list<Node*> nodeList)
{
	list<Node*>::iterator it;
	if (flattenList == NULL)
	{
		it = nodeList.begin();
		flattenList = new Node((*it)->getData());
	}
	
	endOfList = true;
	for (it = nodeList.begin(); it != nodeList.end(); it++)
	{
		if ((*it) != NULL)
		{
			flattenList->appendToTail((*it)->getData());
			(*it) = (*it)->getNext();
			endOfList = false;
		}
	}

	if (endOfList)
		return;

	flatten(nodeList);
}

int main()
{	
	// interview
	Node* head1 = NULL;
	Node* first1 = new Node(15);
	Node* second1 = new Node(16);
	Node* third1 = new Node(17);
	Node* fourth1 = new Node(18);
	head1 = first1;
	first1->setNext(second1);
	second1->setNext(third1);
	third1->setNext(fourth1);
	fourth1->setNext(NULL);

	Node* head2 = NULL;
	Node* first2 = new Node(25);
	Node* second2 = new Node(26);
	Node* third2 = new Node(27);
	head2 = first2;
	first2->setNext(second2);
	second2->setNext(third2);
	third2->setNext(NULL);

	Node* head3 = NULL;
	Node* first3 = new Node(35);
	Node* second3 = new Node(36);
	Node* third3 = new Node(37);
	Node* fourth3 = new Node(38);
	Node* fifth3 = new Node(39);
	head3 = first3;
	first3->setNext(second3);
	second3->setNext(third3);
	third3->setNext(fourth3);
	fourth3->setNext(fifth3);
	fifth3->setNext(head3);

	list<Node*> nodeList;
	nodeList.push_back(head1);
	nodeList.push_back(head2);
	nodeList.push_back(head3);

	flatten(nodeList);
	flattenList = deleteNode(flattenList, 15);
	printLinkedList(flattenList);
  
	cin.get();
	return 0;
}
