#include<stdio.h>
#include<string.h>
 
#define BUFSIZE 100 
 
char buf[BUFSIZE]; 
int bufp = 0; 
 
int getch(void); 
void unGetch(int);

/* Getch: get a ( possibly pushed back) character. */ 
int getch(void) 
{ 
     return (bufp > 0) ? buf[--bufp]: getchar(); 
} 
 
/* unGetch: push character back on input. */ 
void unGetch(int c) 
{ 
    if(bufp >= BUFSIZE) 
        printf("\nUnGetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
}  
void ungets(const char *s) 
{     
  size_t i = strlen(s); //size_t 是unsigned int类型的

  while (i > 0) 
    unGetch(s[--i]); 
}

int main(void) 
{ 
  char *s = "hello, world.  this is a test."; 
  int c; 

  ungets(s); 
  while ((c = getch()) != EOF) 
    putchar(c);                
  return 0; 
}
