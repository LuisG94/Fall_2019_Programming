#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int offset;
	int ndata;
	char* data;
	int array_size;
};

void init(Queue *s, int array_size)
{
	s->array_size = array_size;
	s->ndata = 0;
	s->offset = 0;
	s->data = (char*)malloc(sizeof(char) * array_size);
}

void queue(Queue *s, char value)
{
	int index = (s->offset + s->ndata) % s->array_size;
	s->data[index] = value;
	s->ndata++;
}

char dequeue(Queue *s)
{
	int index = s->offset++;
	s->offset %= s->array_size;
	s->ndata--;
	return s->data[index];
}


int main()
{
	



	system("pause");
	return 0;
}