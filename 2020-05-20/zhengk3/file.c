
/**
 * 第32堂课示例代码：文件操作
 * 郑凯
 * 2020年5月20日
 * */
#include<stdio.h>

void filecopy(FILE *ifp, FILE * ofp);

void filecopy(FILE *ifp, FILE * ofp)
{
    int c;

    while(( c = getc(ifp)) != EOF)
       putc(c, ofp);

}

int main(int argc, char *argv[])
{
    FILE *fp;
    
    if( argc == 1)
       filecopy(stdin, stdout);
    else
    {
        while(--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
            } else {
                //将文本从一个文件输出到标准输出
                //filecopy(fp, stdout);
                //fclose(fp);
                //将文本从一个文件输出到另一个文件
                FILE *ofp;
                if ((ofp = fopen("output.txt", "a")) == NULL){
                    printf("cat: can't open output.txt\n");
                } else {
                    filecopy(fp, ofp);
                    fclose(fp);
                }
                
            }
        }
    }
    
    return 0;
}