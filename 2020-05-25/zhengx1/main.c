#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 100


int main(int argc, char const *argv[])
{
	char buf[BUFSIZE];
	int n;
	while((n = read(0,buf,BUFSIZE)) >0)
	{
		write(1,buf,n);
	}
	
	return 0;
}
