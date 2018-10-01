## How do you check if a given linked list contains a cycle? How do you find the starting node of the cycle?

### Solution:
##### Create 2 pointers point to the HEAD which called Slow pointer and Fast pointer. Fast Ptr forward by 2 and Slow Ptr forward by 1
##### if pointers meets -> loop.

```
linkedList_s *fastPtr = head;
linkedList_s *slowPtr = head;

while ((fastPtr!=NULL) && (slowPtr!=NULL) && (fastPtr->next != NULL))
{
	slowPtr = slowPtr->next;
	fastPtr = fastPtr->next->next;

	if(fastPtr == slowPtr)
	{
		printf("LOOP: %d\n", fastPtr->data);
		//findStartingOfLoop(head, fastPtr);
		return;
	}
}
```

##### To get this start of loop, put one of your 2 pointers at the start and now start moving both pointers forward by 1.
##### When they meet, you know that this is your loop’s starting point.

```
linkedList_s *ptr1 = head;
linkedList_s *ptr2 = meetPoint;

while (ptr1 != ptr2)
{
	ptr1 = ptr1->next;
	ptr2 = ptr2->next;
}
printf("at %d\n", ptr2->data);

```
