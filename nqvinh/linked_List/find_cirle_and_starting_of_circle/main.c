#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linkedList_s {
	int data;
	struct linkedList_s *next;
} linkedList_s;

void findStartingOfLoop(linkedList_s *head, linkedList_s * meetPoint);

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

void detectLoopInLinkedList(linkedList_s *head)
{
	linkedList_s *fastPtr = head;
	linkedList_s *slowPtr = head;

	while ((fastPtr!=NULL) && (slowPtr!=NULL) && (fastPtr->next != NULL))
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;

		if(fastPtr == slowPtr)
		{
			printf("LOOP: %d\n", fastPtr->data);
			findStartingOfLoop(head, fastPtr);
			return;
		}
	}

	printf("NO loop\n");
	return;
}

void findStartingOfLoop(linkedList_s *head, linkedList_s * meetPoint)
{
	linkedList_s *ptr1 = head;
	linkedList_s *ptr2 = meetPoint;

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	printf("at %d\n", ptr2->data);
}

linkedList_s *newNode(int newData)
{
    linkedList_s *temp = (linkedList_s*)malloc(sizeof(linkedList_s));
    temp->data = newData;
    temp->next = NULL;
    return temp;
}

int main(int argc, char const *argv[])
{
	linkedList_s *head = newNode(10);

	head->next = newNode(20);
	head->next->next = newNode(30);
	head->next->next->next = newNode(40);
	head->next->next->next->next = newNode(50);
	head->next->next->next->next->next = newNode(60);
	head->next->next->next->next->next->next = newNode(70);
	head->next->next->next->next->next->next->next = newNode(80);

	// 10 ----> 20 ----> 30 ----> 40 ----> 50 ----> 60 ----> 70 ---> 80 ---> NULL

	// print normal linkedlist
	printLinkedlist(head);

	// create a loop for testing
	head->next->next->next->next->next->next->next->next = head->next->next->next;

/*
	10 ----> 20 ----> 30 ----> 40 ----> 50---->60
								^				|
								|				|
								|				v
							   80 <---- -----  70
*/
	detectLoopInLinkedList(head);

	return 0;
}
