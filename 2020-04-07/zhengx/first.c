//第一个C
#include <stdio.h>

int global_var =1;
static int static_var =1;
void hello(void)
{
	fprintf(stderr, "hello\n" );
}

void func(void)
{
	void *buff[10];
	static int i;
	for (int i = 0; i < 100; ++i)
	{
		buff[i] = hello;
	}

}

int main(int argc, char const *argv[])
{
	int buff[1000];
	/* code */
	func();
	return 0;
}

