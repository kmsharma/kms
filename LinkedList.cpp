#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push_back(Node** head, int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tmp = *head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
void printList(Node* head)
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
	}

	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


void reverse(Node** head)
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}

	Node* a = *head;
	Node* b = NULL;
	Node* c = NULL;

	while (a->next)
	{
		b = a;
		a = a->next;
		b->next = c;
		c = b;
	}
	a->next = b;
	*head = a;
}

Node* reverseK(Node* head, int k)
{
	Node* cur = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count = 0;
	Node* newHead = NULL;

	while (cur->next && count++< k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	newHead = prev;

	if (next != NULL)
	{
		head->next = next;
	}

	return newHead;
}


void reverseFromAtoB(Node *head, int a, int b)
{
	if (a >= b)
	{
		cout << "Invalid List Input";
	}
	int k = b - a + 1;
	int i = 0;
	Node* tmp = head;
	Node* prev = NULL;

	while (i < a-1)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}

	Node *newKHead = reverseK(tmp, k);

	prev->next = newKHead;
	
}

int main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6 , 7, 8};
	unsigned int sz = sizeof(ar)/sizeof(ar[0]);

	Node* head = NULL;

	for (size_t i = 0; i < sz; i++)
	{
		push_back(&head, ar[i]);
	}

	printList(head);
	
	//reverse(&head);
	reverseFromAtoB(head, 4, 6);

	printList(head);
	
	return 0;
}