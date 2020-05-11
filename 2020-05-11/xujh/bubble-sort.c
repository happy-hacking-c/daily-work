#include <stdio.h>

void paoSort(char *p);
void myPrint(char *p);

void paoSort(char *p)
{
    int len = 0;
    char *t = p;
    while(*t++ != '\0')
        len++;

    int lastExchangeIndex = 0;
    int sortBoder = len - 1;

    for(int i = 0; i < len ; i++) {

        int isSorted = 1;

        for(int j = 0; j < sortBoder; j++) {
            if(*(p+j) > *(p+j+1)) {
                int tmp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = tmp;
                isSorted = 0;
                lastExchangeIndex = j;
            }

        }

        sortBoder = lastExchangeIndex;
        if(isSorted)
            break;
    }

}

void myPrint(char *p)
{
    while (*p != '\0')
        printf("%d ", *p++);
    
    printf("\n");
    
}


int main()
{
    char myArray[13] = {1,52,23,16,95,40,32,15,87,82,6,15};

    paoSort(myArray);

    myPrint(myArray);

    return 0;
}
