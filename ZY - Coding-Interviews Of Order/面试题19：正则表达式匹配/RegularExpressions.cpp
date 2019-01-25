// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。


/*
	整个正则表达式函数只涉及到'.'和'*'两个字符的匹配匹配
	对于'.'匹配，只要把'.'字符特殊处理，'.'可以和任何字符匹配
	对于'*'匹配，这就比较麻烦，要考虑全所有情况。

	思路：
		假设字符串为str，模式串为pattern，考虑以下情况：
		A. 模式串下一个字符为*，即   *(pattern+1)=='*'：
		如果当前字符匹配，即*str==*pattern或者*str=='.' && *pattern!='\0'，三种可能：
		 1、模式串当前字符出现0次，即*表示当前字符出现0次，则主串位置不变，模式串向后移动两个位置，即str=str,pattern=pattern+2;
		 2、模式串当前字符出现1次，即*表示当前字符出现1次，则主串位置加一，模式串向后移动两个位置，即str=str+1,pattern=pattern+2;
		 3、模式串当前字符出现2次或2次以上，即*表示当前字符出现2次或以上，则主串位置加一，模式串位置不变，即str=str+1,pattern=pattern;
		如果当前字符不匹配，则只能让*表示当前字符出现0次，则str=str，pattern=pattern+2;
		B. 模式串下一个字符不为*
		如果当前字符匹配，即*str==*pattern或者*str=='.' && *pattern!='\0'，则主串和模式串同时加一向后遍历，即str=str+1,pattern=pattern+1.
*/

#include <stdio.h>

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
	if (str == NULL || pattern == NULL)
	{
		return false;
	}
	return matchCore(str,pattern);
}

bool matchCore(const char* str, const char* pattern)
{
	if (*str == '\0' && *pattern == '\0' )
	{
		return true;
	}
	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}

	if (*(pattern+1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str+1,pattern+2)    // 进入有限状态机的下一个状态
				|| matchCore(str+1,pattern)     // 进入有限状态机的下一个状态
				|| matchCore(str,pattern+2);    // 略过一个'*' 
		}
		else
		{
			return matchCore(str,pattern+2);    // 略过一个'*' 
		}
	}

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
	{
		return matchCore(str+1,pattern+1);
	}

	return false;
}




// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
