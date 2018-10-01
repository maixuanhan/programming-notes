## How do you find the middle element of a singly linked list in one pass?

### Solution:
##### Create 2 pointers point to the HEAD which called Slow pointer and Fast pointer. Fast Ptr pass 2 step then Slow Ptr pass 1 step, go on until fast reach the tail then Slow reach the middle.

```
linkedList_s *fastPtr = head;
linkedList_s *slowPtr = head;
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
```
