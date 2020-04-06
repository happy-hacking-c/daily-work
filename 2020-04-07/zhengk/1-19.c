
/**
 * ��������ַ��㵽֮���������
 * ֣��
 * 2020��4��6��15:02:47
 * */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 //�����������ַ����ȣ������ó��Ƚ����ضϴ���

char input[MAX_LENGTH]; //�����ַ���
char output[MAX_LENGTH]; //����ַ���
int charCounts; //ͳ�������ַ���

//��������(����ԭ��)
void reverse(void);
int readLine(void);
void emptyArray(void);

//�������
void emptyArray(void)
{
    //���顰��ա�����
    memset(input, ' ', MAX_LENGTH);
    memset(output, ' ', MAX_LENGTH);
}

//��ԭ�ַ���˳��ߵ�
void reverse(void)
{
    int j = charCounts-1 ;
    for( int i = 0; i < charCounts; i++ ) {
         output[j] = input[i];
         j--;
    }

}

//��ȡһ������
int readLine(void)
{
    //�ַ���ͳ�Ƹ����ַ���
    int c, i; 

    //�����������
    emptyArray();

    //���ϴ������ַ����ж�ȡ�ַ����ݣ�ֱ������
    while(( c = getchar()) != EOF && i <= MAX_LENGTH && c != '\n' ) {
        input[i] = c;
        i++;
    }

    //���һ���������
    if( c == '\n') {
        input[i] = c;
        i++;
    }

    //��ʾ�Ľ��ı������������ӽ��������Ա��������֪���ַ�����ʱ����
    input[i] = '\0';
    
    //�ַ���
    return i;
}


int main()
{

    //�ַ�
    int c; 

    //����ѭ�������ַ�������
    while (1)
    {

        //����̨��Ϣ
        printf("��������һ���ı���Ϣ����󳤶�%d, �����˳��ȵĲ��ֽ����Զ��ضϴ���Ctrl+C�˳����򣩣�\n", MAX_LENGTH);
    
        //��ȡһ����Ϣ������ȡ����
        charCounts = readLine();

        //�������ַ�������˳��ߵ�
        reverse();

        //���������������ȥ�������з�
        printf("��һ��������%d ���ַ�������ߵ����֮��Ľ�����£�", charCounts-1);

        int i = 0;
        while (output[i] != '\0') {
            printf("%c", output[i]);
            i++;
        }
        printf("\n");

    }

    //�˳�����
    printf("�˳��ɹ�\n");
    return 0;
}