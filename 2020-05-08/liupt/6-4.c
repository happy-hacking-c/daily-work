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
char *mstrdup(char *);
int getword(char *word, int lim);
void swap(struct tnode ** x, struct tnode **y);
void SelectSortOP(struct tnode *array[], int size);
/* the tree node: */
struct tnode
{
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

struct tnode *left;

struct tnode *array[MAXWORD];
int arri = 0;

/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    SelectSortOP(array,arri);
    int i = MAXWORD;
    printf("after sort\n");

    while (arri >= 0)
    {
        if(array[arri] != NULL && array[arri]->count !=0){
            printf("%d %d %s\n", arri,array[arri]->count, array[arri]->word);

        }
        arri--;
    }
    


    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL)
    {                 /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = mstrdup(w);
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
        int count1 = p->count;
        array[arri++] = p;
        // while (array[count1] != NULL && strlen(array[count1]->word) != 0)
        // {
        //     if(array[count1]->count > p->count){
        //         struct tnode *tmp = array[count1];
        //         array[count1] = p;
        //         p = tmp;
        //     }
        //     count1++;

        // }
        // array[count1] = p;
        
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *mstrdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim)
{
    int c, d;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (isalpha(c))
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()))
            {
                ungetch(*w);
                break;
            }
    }

    *w = '\0';
    return c;
}


void swap(struct tnode ** x, struct tnode **y)
{
	struct tnode ** tmp = x;
	x = y;
	y = tmp;
}

//选择排序的优化(一次将两个元素放在它的最终位置上）
void SelectSortOP(struct tnode *array[], int size)
{
	//最小值下标
	int minpos = 0;
	//最大值下标
	int maxpos = 0;
	int left = 0;
	int right = size - 1;
	int j = 0;
	//循环size-1次
	while (left < right)
	{
		maxpos = left;
		minpos = left;
		//确定最大值下标以及最小值下标
		for (j = left; j <= right; j++)
		{
			if (array[j]->count > array[maxpos]->count)
			{
				maxpos = j;
			}
			if (array[j]->count < array[minpos]->count)
			{
				minpos = j;
			}
		}
		//将最大值插到最后
		if (maxpos != right)
		{
            struct tnode *tmp = array[maxpos];
            array[maxpos] = array[right];
            array[right] = tmp;
			// swap(&array[maxpos], &array[right]);
		}
		//防止minpos在最大值要插入的位置
		if (minpos == right)
		{
			minpos = maxpos;
		}
		//将最小值插到最前面
		if (minpos != left)
		{
            struct tnode *tmp = array[maxpos];
            array[maxpos] = array[right];
            array[right] = tmp;
			// swap(&array[minpos], &array[left]);
		}
		left++;
		right--;
	}
}