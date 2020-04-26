#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
 
#define FILE_LINE_LEN 1024
 
long g_curr_offset = 0;
 
int32_t c_tail(const char *file);
int32_t c_tail(const char *file)
{
    if (!file) return -1; 
    FILE *fp = fopen(file, "r");
    if (!fp) {
        printf("cant open file, file: %s\n", file);
        return -2; 
    }   
 
    fseek(fp, g_curr_offset, SEEK_SET);
 
    char text[FILE_LINE_LEN];
    uint32_t len;
    while(!feof(fp)) {
 
        memset(text, 0x0, FILE_LINE_LEN);
        fgets(text, FILE_LINE_LEN, fp);
        len = strlen(text);
        if (len == 0 || text[len - 1] != '\n') continue;
        text[len - 1] = 0;
        g_curr_offset += len;
        printf("%s\n", text);
    }   
 
    fclose(fp);
 
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: exe file_name\n");
        exit(-1);
    }
 
    while (1) {
        c_tail(argv[1]);
    }
 
    return 0;
}
