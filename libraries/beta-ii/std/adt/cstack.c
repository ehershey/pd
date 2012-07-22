/*
   cstack.c: simple fixed-size circular stack in LPC 3.0
    -- by Truilkan@TMI - 92/03/11
*/

private static mixed *queue;
private static int hptr, tptr, size, primed;
private static int count;

public mixed *query_queue()
{
	return queue;
}

public mixed dequeue()
{
   int h;

   if (!count)
      return -1;
   count--;
   h = hptr;
   hptr = (hptr + 1) % size;
   return queue[h];          /* pre-increment */
}

int enqueue_cstack(mixed elt)
{
   if (count++ == size)
      return -1;
   queue[tptr] = elt;  /* post-increment */
   tptr = (tptr + 1) % size;
   return 0;
}

mixed pop()
{
	int h;

	if (!count)
		return -1;
	count--;
	h = hptr;
	hptr = (hptr + size - 1) % size;
	return queue[h];
}

void alloc_cstack(int s)
{
   count = 0;
   hptr = 0;
   tptr = 0;
   size = s;
   queue = allocate(size);
}

void remove()
{
   destruct(this_object());
}
