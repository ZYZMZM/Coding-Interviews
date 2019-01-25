//面试题50-3：删除字符串中所有重复的字符

#include<stdio.h>
void DeleteRepeatChar(char *str)
{
	if (str == NULL)
	{
		return;
	}

	const int size = 256;
	unsigned int hashTable[size];
	for (unsigned int i = 0; i < size; i++)
	{
		hashTable[i] = 0;
	}

	char *pStr_1 = str;
	char *pStr_2 = str;
	char *pStr = str;

	while (*pStr != '\0')
	{
		hashTable[*(pStr++)]++;
	}

	while (*pStr_2 != '\0')
	{
		if (hashTable[*pStr_2] == 1)
		{
			*pStr_1++ = *pStr_2++;
		}
		else
		{
			hashTable[*pStr_2]--;
			pStr_2++;

		}
	}
	*pStr_1 = '\0';
}

// ====================测试代码====================

int main(int argc, char* argv[])
{
	char str1[] = "google";
	DeleteRepeatChar(str1);
	printf("%s\n",str1);

	char str2[] = "We are students";
	DeleteRepeatChar(str2);
	printf("%s\n",str2);

    return 0;
}