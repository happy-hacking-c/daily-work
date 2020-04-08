#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[100], s2[100];
    int pos;
    scanf("%s", s1);
    scanf("%s", s2);

    pos = any(s1, s2);

    printf("\n%d", pos);
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, pos;
    i = j = 0;
    pos = -1;
    while (s2[i] != '\0')
    {
        while (s1[j] != '\0')
        {
            if (s2[i] == s1[j])
            {
                pos = j;
                break;
            }
            j++;
        }
        if (pos != -1)
        {
            break;
        }
        
        i++;
        
    }

    return pos;
    
}