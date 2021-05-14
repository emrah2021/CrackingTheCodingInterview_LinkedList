#pragma once
#include <stdio.h>
#include <iostream>
#include <list>
#include <map>

class Node
{
private:
	int number;
	Node* next = NULL;
public:
	Node(int num);
	void setData(int num);
	int getData();
	void setNext(Node *n);
	Node* getNext();

	void appendToTail(int num);
	Node* deleteNode(Node* head, int number);
	void printLinkedList(Node* node);
	Node* findLoopNodeCircularList(Node* head);
	Node* removeDubs(Node* head);
	Node* findNthElementToLast(Node* head, int n);
	Node* deleteMiddleNode(Node* head);
	Node* addTwoLists(Node* head1, Node* head2, int carry);
};
