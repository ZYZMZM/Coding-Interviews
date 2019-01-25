//面试题50-2 ：在第一个字符串中，删除第二个字符串中所有的字符

#include<stdio.h>
#include<string.h>
void DeleteStrChar(char *str1,char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return;
	}

	const int size = 256;
	unsigned int hashTable[size];
	for (unsigned int i = 0; i < size; i++)
	{
		hashTable[i] = 0;
	}

	char *pStr_1 = str1;
	char *pStr_2 = str1;

	while (*str2 != '\0')
	{
		hashTable[*str2++]++;
	}

	while (*pStr_2 != '\0')
	{
		if (hashTable[*pStr_2] == 0)
		{
			*pStr_1++ = *pStr_2++;
		}
		else
		{
			pStr_2++;
		}
	}
	*pStr_1 = '\0';
}


// ====================测试代码====================

int main(int argc, char* argv[])
{
	char str1[] = "google";
	char str2[] = "gl";
	DeleteStrChar(str1,str2);
	printf("%s\n",str1);

	char str3[] = "We are students";
	char str4[] = "aeiou";
	DeleteStrChar(str3,str4);
	printf("%s\n",str3);   // W r stdnts

	char str5[] = "abcdefg";
	char str6[] = "bdf";
	DeleteStrChar(str5,str6);
	printf("%s\n",str5);   // aceg

	char str7[] = "abcdefg";
	char str8[] = "tt";
	DeleteStrChar(str7,str8);
	printf("%s\n",str7);   // abcdefg

    return 0;
}