#include <string.h>
#include <stdio.h>

char * my_strncpy(char * dest, const char * source, size_t count)
{
    char *start = dest;

    while (count && (*dest++ = *source++))   //复制字符串
        count--;

    if (count)                              //后续都赋‘\0’
    while (--count)
        *dest++ = '\0';

    return(start);
}

char * my_strncat(char * dest, const char * src, size_t count)
{
    char *start = dest;

    while (*dest++)
        ;
    dest--;

    while (count--)
    if (!(*dest++ = *src++))
        return(start);

    *dest = '\0';
    return(start);
}

int my_strncmp(const char *first, const char *last, size_t count)
{
    size_t x = 0;

    if (!count)
    {
        return 0;
    }

    if (count >= 4)
    {
        for (; x < count - 4; x += 4)   //count大于4时，就4个元素放在一起判断
        {
            first += 4;
            last += 4;

            if (*(first - 4) == 0 || *(first - 4) != *(last - 4))
            {
                return(*(unsigned char *)(first - 4) - *(unsigned char *)(last - 4));
            }

            if (*(first - 3) == 0 || *(first - 3) != *(last - 3))
            {
                return(*(unsigned char *)(first - 3) - *(unsigned char *)(last - 3));
            }

            if (*(first - 2) == 0 || *(first - 2) != *(last - 2))
            {
                return(*(unsigned char *)(first - 2) - *(unsigned char *)(last - 2));
            }

            if (*(first - 1) == 0 || *(first - 1) != *(last - 1))
            {
                return(*(unsigned char *)(first - 1) - *(unsigned char *)(last - 1));
            }
        }
    }

    for (; x < count; x++)
    {
        if (*first == 0 || *first != *last)
        {
            return(*(unsigned char *)first - *(unsigned char *)last);
        }
        first += 1;
        last += 1;
    }

    return 0;
}


int main(int argc, char *argv[]){
	char *src = "1234567890";
	char dest[100] = {0};
 	printf("---------------------\n");
	my_strncpy(dest,src,5);
	printf("dest:%s\n",dest);
	printf("---------------------\n");
	my_strncat(dest,src,7);
	printf("dest:%s\n",dest);
	return 0;
}
