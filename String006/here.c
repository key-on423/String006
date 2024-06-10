#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//8.编写一个名为string_in的函数，接受两个指向字符串的指针作为参数。如果第二个字符串包含在第一个字符串中，则该函数返回第一个字符串开始的地址
//。例如，string_in("hats","at")返回hats中a的地址。否则，该函数返还空指针。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
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
	printf("请输入第一个字符串：\n");
	s_gets(arr1, max);
	//printf("strlen of arr1=%d\n", strlen(arr1));
	printf("请输入第二个字符串（如果第二个字符串包含在第一个字符串函数返回第一个字符串开始的地址）\n");
	s_gets(arr2, max);
	if ((arr3 = string_in(arr1, arr2)) != NULL)
		printf("包含！\n");
	else
		printf("不包含！\n");
	printf("返还的首地址为%p\n",arr3);
	printf("arr1的首地址为%p\n", arr1);
	Sleep(1500);
	system("cls");
	printf("以下为是arr1中包含的：\n");
	while (i < strlen(arr2))
	{
		printf("%c", arr1[i]);
		i++;
	}
	return 0;

}
//char* string_in(char st1[max], char st2[max]) //两种方式都可以 最好用下面一种↓
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