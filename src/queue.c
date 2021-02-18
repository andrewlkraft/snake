#include "headers.h"

void push(Queue *q, const Coord pos)
{
	// init new node
	struct Node *n = (struct Node*) malloc(sizeof(struct Node));
	*n = (struct Node){0, pos};

	// add to queue
	if (q->tail == 0)
	{
		q->head = q->tail = n;
	}
	else
	{
		q->tail->next = n;
		q->tail = n;
	}
}

Coord pop(Queue *q) {
	Coord pos = {.x = -1, .y = -1};
	if (q->head == 0)
		return pos;
	
	pos = q->head->pos;

	struct Node *p = q->head;
	q->head = q->head->next;
	free(p);

	return pos;
}

void clear(Queue *q)
{
	for(struct Node *p=q->head; p->next; )
	{
		q->head = q->head->next;
		free(p);
		p = q->head;
	}
	free(q->head);
	q->head = q->tail = 0;
}