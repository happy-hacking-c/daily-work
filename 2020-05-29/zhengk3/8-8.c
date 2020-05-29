
/**
 * 最后一堂课作业：8-8
 * 郑凯
 * 2020年5月29日
 * */
#include <stdio.h>
#include <stdlib.h>

#define MAXBYTES (unsigned) 1024

typedef long Align;

union header {
    struct {
        union header *ptr;  
        unsigned size;    
    } s;
    Align x;
};

typedef union header Header;

static Header    base; 
static Header   *freep = NULL; 

#define ALIGN(p) (sizeof(Align)-((unsigned)(p)%sizeof(Align)))%sizeof(Align)

void wtbfree(void *, unsigned);
void bfree(void *, unsigned);

void bfree(void *p, unsigned n) {
    unsigned align, s, r;

    if (n < sizeof(Header)) {
        wtbfree(p, n);
        return;
    }

    align = ALIGN(p);
    if (align) {
        wtbfree(p, align);
        p = (char *)p + align;
        n -= align;
    }
    s = n / sizeof(Header);
    r = n % sizeof(Header);

   
    if (r) {
        wtbfree((char *)p + n + r, r);
    }

    if (s) {

        if (freep == NULL) {
            base.s.ptr = freep = &base;
            base.s.size = 0;
        }

        ((Header *)p)->s.size = s;
        free((Header *)p + 1);
    }
}

struct wtbheader {
    struct wtbheader *next;
    void *p;
    unsigned n;
};

void try_to_free(struct wtbheader *p) {
    char *tp;
    unsigned align;
    unsigned n;

    tp = p->p;
    align = ALIGN(p->p);

    if ((align < p->n) && ((p->n - align) % sizeof(Header) == 0)) {
        tp += align;
        n = p->n - align;
        p->n = align;

        ((Header *)tp)->s.size = n / sizeof(Header);
        free((Header *)tp + 1);
    }
}

static struct wtbheader *headptr;

void wtbfree(void *p, unsigned n)  {
    struct wtbheader *hp, *prevp;

    if (headptr == NULL) {
        if (! (headptr = malloc(sizeof *headptr)))
            return;
        headptr->p = p;
        headptr->n = n;
        headptr->next = NULL;
    } else if (p < headptr->p) {        
        if ((char *)p + n == headptr->p) { 
            headptr->p = p;
            headptr->n = n;
            try_to_free(headptr);

            if(!headptr->n) { 
                void *tp = headptr;
                headptr = headptr->next;
                free(tp);
            }
        } else {
            struct wtbheader *tp;
            if (! (tp = malloc(sizeof *tp)))
                return;
            tp->p = p;
            tp->n = n;
            tp->next = headptr;
            headptr = tp;
        }

    } else {
        for (prevp = hp = headptr; hp->next && p > hp->next->p; prevp = hp, hp = hp->next) {
            ; 
        }

        if ((char *)hp->p + hp->n == p) {   
            hp->n += n;
            try_to_free(hp);

            if (!hp->n) {
                if (hp == headptr)
                    headptr = NULL;
                prevp->next = hp->next;
                free(hp);
            }

        } else if (hp->next && (char *)p + n == hp->next->p) {
            hp->next->p = p;
            hp->next->n += n;
            try_to_free(hp->next);

            if (! hp->next->n) {
                void *tp = hp->next;
                hp->next = hp->next->next;
                free(tp);
            }
        } else {
            struct wtbheader *tp;
            if(! (tp = malloc(sizeof *tp))) 
                return;
            tp->p = p;
            tp->n = n;

            tp->next = hp->next;
            hp->next = tp;
        }


    }

}


int main(int argc, char *argv[]) {
    int *p = NULL;
    int i = 0;

    p = malloc(100 * sizeof *p);
    if (NULL == p) {
        printf("malloc returned NULL");

    } else {
        for(i=0; i <= 100; i++) {
            printf("%08X", p[i]);
            if (i % 8 == 7) {
                printf("\n");
            }
        }
        printf("\n");
        bfree(p, 1 * sizeof *p);
    }
    return 0;
}