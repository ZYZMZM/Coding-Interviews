#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>



bool Match(char *str)
{
	Sqstack stack;
	InitStack(&stack);
	int len = strlen(str);
	int st;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			Push(&stack,str[i]);
		}
		else if(str[i] != '\0')
		{
			if (stack.top == 0)
			{
				return false;
			}
			Pop(&stack,&st);
			if (st == '(' && str[i] != ')' || st == '[' && str[i] != ']' || st == '{' && str[i] != '}')
			{
				return false;
			}
		}
	}
	if (stack.top != 0)
	{
		return false;
	}
	return true;
}




//  1212121
bool IsPalindorm(char *str)
{
	Sqstack stack;
	InitStack(&stack);
	int len = strlen(str);
	int des[100] = {};
	for (int i = 0; i < len; i++)
	{
		Push(&stack,str[i]);
	}
	for (int i = 0; i < len/2; i++)
	{
		Pop(&stack,&des[i]);
		if (des[i] != str[i])
		{
			return false;
		}
	}
	return true;
}



void ReverseString(char *str,int len)
{
	Sqstack stack;
	InitStack(&stack);

	for (int i = 0; i < len; i++)
	{
		Push(&stack,str[i]);
	}
	for (int i = 0;i < len; i++)
	{
		int des[100] = {};
		Pop(&stack,&des[i]);
		printf("%c",des[i]);
	}
	printf("\n");
}


int main()
{
	char str2[] = "012663210";
	if (IsPalindorm(str2))
	{
		printf("huiwen\n");
	}
	else
	{
		printf("bushi\n");
	}
	char str1[] = "[{}{}]";
	if(Match(str1)) {printf("OK");}
	else
	{
		printf("WRONG");
	}

	char str[] = "i l ov ey ou";
	int len = sizeof(str)/sizeof(str[0]);
	ReverseString(str,len);
	/*Sqstack st;
	InitStack(&st);
	for(int i = 0;i < 10;i++)
	{
		Push(&st,i);
	}
	Push(&st,10);
	Push(&st,88);

	Show(&st);
	int tmp = 0;
	Pop(&st,&tmp);
	printf("%d\n",tmp);
	Pop(&st,&tmp);
	printf("%d\n",tmp);
	Pop(&st,&tmp);
	printf("%d\n",tmp);
	Show(&st);
	return 0;*/
}
