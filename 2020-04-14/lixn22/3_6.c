#include <stdio.h>
#include <string.h>

/* reverse : reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

/* itoa : convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        s[i++] = n %10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);
}

/* itoa2 : convert n to characters in s */
void itoa2(int n, char s[], int minLen) {
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        s[i++] = n %10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    //s[i] = '\0';
    for (int j = i; j < minLen; j++, i++)
    {
        s[j] = ' ';

    }
    s[i] = '\0';
    reverse(s);
}


int main() {
    int n = 234567;
    char s[100], t[100];
    itoa(n, s);
    printf("%s\n", s);
    int m = 123124;

    itoa2(m, t, 10);
    printf("%s\n", t);

    return 0;
}
