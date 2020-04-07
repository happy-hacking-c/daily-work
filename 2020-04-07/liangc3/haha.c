#define MAXLINE 500
void reverse(char s[]);
void getLine(char s[], int line);
int getLen(char s[]);

int main() {
    char line[MAXLINE];
    getLine(line, MAXLINE);
    reverse(line);
    printf("s[] reversed is %s \n", line);
}

void getLine(char s[], int limit) {
    int i, c;
    for (i=0; i<limit && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
}

void reverse(char s[]) {
    int i, len, string;
    len = getLen(s);
    if (len < 2)
        return;
    for(i=0; i < len-1-i; i++) {
        string = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = string;
    }
}

int getLen(char s[]) {
    int i;
    for (i=0; s[i] != '\0' && s[i] != '\n'; i++)
        ;
    return i;
}