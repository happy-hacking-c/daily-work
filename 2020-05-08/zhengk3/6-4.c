
/**
 * 第23堂课作业：统计输入内容中的单词数
 * 郑凯
 * 2020年5月8日
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getchar.c"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *myStrdup(char *);

//存储输入的单词表
char *wordList[MAXWORD][MAXWORD];

struct tnode
{                       
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *myStrdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL)
    {                 /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = myStrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;    /* repeated word */
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

//打印排序之后的内容
void sortTree(struct tnode *p)
{
    //把树里的内容按对应关系塞到对应的坑位里
    if (p != NULL)
    {
        sortTree(p->left);
        int i = 0;
        //*(wordList+(p->count)) 是外层指向内层的指针
        //*(wordList+(p->count))+i 是内层指针移动操作
        //*(*(wordList+(p->count))+i) 就是对应内层的那个位置的变量值

        while(*(*(wordList+(p->count))+i) != NULL) {
            i++;
        }

        *(*(wordList+(p->count))+i) = p->word;
        sortTree(p->right);
    }


}

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int main()
{
    printf("please input some characters：\n");

    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    //把树里的内容按规律放到对应的“坑”里
    sortTree(root);

    //按递减顺序，输出每一个坑里存的单词（相同数量的坑里，单词按字典升序，也就是平衡二叉树的顺序，先左后右）
    for(int i = MAXWORD-1; i > 0; i--) {
        if(wordList[i][0] != NULL){
            //如果这个坑位里有值，再进行单词循环输出
            for(int j = 0; j < MAXWORD; j++) {
                //每个空位中，单词的最大值是MAXWORD
                if(wordList[i][j] != NULL)
                    //有单词，就输出
                    printf("%d  %s\n", i,wordList[i][j]);
            }
        }
            
    }

    
    return 0;
}
