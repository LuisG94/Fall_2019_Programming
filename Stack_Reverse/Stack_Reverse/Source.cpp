#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int array_size;
	int ndata;
	char* data;
};

void init(Stack *s, int array_size)
{
	s->array_size = array_size;
	s->ndata = 0;
	s->data = (char*)malloc(sizeof(char) * array_size);
}

void Push(Stack *s, char value)
{
	s->data[s->ndata++] = value;
}

char Pop(Stack *s)
{
	return s->data[--s->ndata];
}

void Reverse(const char *src, char *dst, Stack *s)
{
	int len = strlen(src);
	int num_pushes = 0;

	for (int i = 0; i < len; ++i)
	{
		if (s->ndata >= s->array_size) break;
		Push(s, src[i]);
		num_pushes++;
	}

	for (int i = 0; i < num_pushes; ++i)
	{
		dst[i] = Pop(s);
	}
	s->data[num_pushes] = 0;
}



int main()
{




	system("pause");
	return 0;
}