
/**
 * ͳ�������ַ��������ַ�����Ƶ�ȵ�ֱ��ͼ
 * ֣��
 * 2020��4��6��20:01:43
 * */

#include <stdio.h>

#define MAX_LENGTH 100 //������ദ����ַ�������
#define CHAR_COUNTS 128 //��׼ASCII�ַ�����ĿǰΪֹ������128���ַ�

int wordBox[CHAR_COUNTS]; //�洢�����ַ����ַ��ĳ��ִ�����Ϣ

int main()
{
    //����̨��Ϣ
    printf("��������һ���ı���Ϣ����󳤶�%d, �����˳��ȵĲ��ֽ����Զ��ضϴ���\n", MAX_LENGTH);

    int c, j;

    //���ϴ������ַ����ж�ȡ�ַ����ݣ�ֱ������
    while(( c = getchar()) != EOF && j <= MAX_LENGTH) {
        wordBox[c] += 1;
        j++;
    }

    //����ˮƽ����ֱ��ͼ
    printf("ˮƽֱ��ͼ��\n");
    
    int i,lengthTemp;
    for( i = 64 ; i < CHAR_COUNTS ; i++) {
        printf("%d  ", i);
        lengthTemp =10;
        while (lengthTemp > 0)
        {
            printf(" * ");
            lengthTemp--;
        }
        printf("\n");

    }
    //��ӡ������
    printf("ch/co");
    for( i = 0 ; i <= MAX_LENGTH ; i++) {
       printf(" %d ",i);
    }
    printf("\n");


    return 0;
    
}