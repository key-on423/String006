#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//8.��дһ����Ϊstring_in�ĺ�������������ָ���ַ�����ָ����Ϊ����������ڶ����ַ��������ڵ�һ���ַ����У���ú������ص�һ���ַ�����ʼ�ĵ�ַ
//�����磬string_in("hats","at")����hats��a�ĵ�ַ�����򣬸ú���������ָ�롣��һ�������ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����ֵ��
#define max 30
//char* string_in(char st1[max], char st2[max]);
char* string_in(char* st1, char* st2);
char* s_gets(char* st, int n);
int main()
{
	int i = 0;
	char arr1[max];
	char arr2[max];
	char* arr3;
	printf("�������һ���ַ�����\n");
	s_gets(arr1, max);
	//printf("strlen of arr1=%d\n", strlen(arr1));
	printf("������ڶ����ַ���������ڶ����ַ��������ڵ�һ���ַ����������ص�һ���ַ�����ʼ�ĵ�ַ��\n");
	s_gets(arr2, max);
	if ((arr3 = string_in(arr1, arr2)) != NULL)
		printf("������\n");
	else
		printf("��������\n");
	printf("�������׵�ַΪ%p\n",arr3);
	printf("arr1���׵�ַΪ%p\n", arr1);
	Sleep(1500);
	system("cls");
	printf("����Ϊ��arr1�а����ģ�\n");
	while (i < strlen(arr2))
	{
		printf("%c", arr1[i]);
		i++;
	}
	return 0;

}
//char* string_in(char st1[max], char st2[max]) //���ַ�ʽ������ ���������һ�֡�
char* string_in(char *st1, char *st2)
{
	if (strncmp(st1, st2,strlen(st2)-1) == 0)
		return st1;
	else
		return NULL;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] ='\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}