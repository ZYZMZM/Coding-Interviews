#include<stdio.h>
#include<string.h>
void Show(char *str,int begin,int end)
{
	char *pStr = str;
	for (int i = begin; i < end; i++)
	{
		printf("%c",pStr[i]);
	}
	printf("\n");
}

void Combine(char *str,int length)
{
	char *pStr = str;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			int begin = i;
			int end = j;
			Show(pStr,begin,end);
		}
	}
}

int main()
{
	char str[] = "abcd";
	int length = sizeof(str)/sizeof(str[0]);
	Combine(str,length);
}