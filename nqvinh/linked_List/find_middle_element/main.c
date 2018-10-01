#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linkedList_s {
	int data;
	struct linkedList_s *next;
} linkedList_s;

int findMiddle_onePass(linkedList_s *head)
{
	linkedList_s *fastPtr = head;
	linkedList_s *slowPtr = head;
	int count = 0;

	if (head == NULL)
		return 0;

	while (fastPtr != NULL)
	{
		fastPtr = fastPtr->next;
		count++;
		if (count == 2)
		{
			slowPtr = slowPtr->next;
			count = 0;
		}
	}

	return (slowPtr->data);
}

void pushNode(linkedList_s **head_ref, int newdata)
{
	// allocate memory for new node
	linkedList_s *newNode = (linkedList_s *)malloc(sizeof(linkedList_s));

	newNode->data = newdata;
	newNode->next = *head_ref;

	*head_ref = newNode;
}

void printLinkedlist(linkedList_s *node)
{
	while (node != NULL)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	linkedList_s *head = NULL;

	// Use current time as seed for random generator
	srand(time(0));

	for (int i = 0; i < 10; ++i)
	{
		// create a Linked list with 10 first elements
		pushNode(&head, rand() % (40 - 1 + 1) + 1);
	}

	printLinkedlist(head);

	// find middle element

	printf("middle element :%d\n", findMiddle_onePass(head));

	return 0;
}
