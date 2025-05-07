#include"Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);


	QueueDestroy(&q);
}

int main()
{
	test1();

	return 0;
}