#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct Queue
{
	int offset;
	int ndata;
	int* data;
	int array_size;
};

void init(Queue *s, int array_size)
{
	s->array_size = array_size;
	s->ndata = 0;
	s->offset = 0;
	s->data = (int*)malloc(sizeof(int) * array_size);
}

void enqueue(Queue *s, int value)
{
	int index = (s->offset + s->ndata) % s->array_size;
	s->data[index] = value;
	s->ndata++;
}

int dequeue(Queue *s)
{
	int index = s->offset++;
	s->offset %= s->array_size;
	s->ndata--;
	return s->data[index];
}

void print(Queue *s)
{
	for (int i = 0; i < s->ndata; ++i)
	{
		printf("%d ", s->data[(s->offset + i) & s->array_size]);
	}
}


int main()
{
	int array_size = 6;

	Queue q;
	init(&q, array_size);

	for (int i = 0; i < array_size; ++i)
	{
		int value = 0;
		printf("Enter a value: ");
		int r = scanf("%d\n", &value);
		enqueue(&q, r);
	}


	print(&q);


	system("pause");
	return 0;
}