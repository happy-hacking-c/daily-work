
/**
 * 第20堂课作业：5-18
 * 郑凯
 * 2020年4月29日
 * */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 100
#define BUFSIZE 100
enum
{
    NAME, //变量名
    PARENS, //英文翻译：系列章程，()
    BRACKETS //括号
};
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;           /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}



//将字符压回到输入（buf）中
void ungetch(int c)
{
    if (bufp >= BUFSIZ){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}

int gettoken(void) /* return next token */
{

    int c;
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    //判断是否是英文字母
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else if(c == EOF) {
        return tokentype = c;
    } else{
        printf("Error: unknown character %c\n", c);
    }
        
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}
/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;
    if (tokentype == '(')
    { /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int main() /* convert declaration to words */
{
    while (gettoken() != EOF)
    {   
        strcpy(datatype, token); /* is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* undcl: convert word descriptions to declarations */
// int main()
// {
//     int type;
//     char temp[MAXTOKEN];
//     while (gettoken() != EOF)
//     {
//         strcpy(out, token);
//         while ((type = gettoken()) != '\n')
//             if (type == PARENS || type == BRACKETS)
//                 strcat(out, token);
//             else if (type == '*')
//             {
//                 sprintf(temp, "(*%s)", out);
//                 strcpy(out, temp);
//             }
//             else if (type == NAME)
//             {
//                 sprintf(temp, "%s %s", token, out);
//                 strcpy(out, temp);
//             }
//             else
//                 printf("invalid input at %s\n", token);
//     }
//     return 0;
// }
