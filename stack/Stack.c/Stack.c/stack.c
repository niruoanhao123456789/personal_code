#include"stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;//这里如果top = 0，意味着top指向栈顶的下一个；top = -1,top指向栈顶
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

static void CheckCapacity(Stack** ps)
{
	assert(ps);
	if ((*ps)->capacity == (*ps)->top)
	{
		int newcapacity = (*ps)->capacity == 0 ? 4 : (*ps)->capacity * 2;
		STDataType* tmp = (STDataType*)realloc((*ps)->data, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			exit(-1);
		}
		(*ps)->data = tmp;
		(*ps)->capacity = newcapacity;
		tmp = NULL;
	}
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	CheckCapacity(&ps);
	ps->data[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->top > 0);
	return (ps->data[ps->top - 1]);
}

void StackPrint(const Stack* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->top; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}