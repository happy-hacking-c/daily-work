#include <stdio.h>

int main(int argc, char* argv[]) {
    char* s = argv[0];
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *s -= 32;
        } else if (*s >= 'A' && *s <= 'Z') {
            *s += 32;
        }
        s++;
    }
    printf("%s\n", argv[0]);
}