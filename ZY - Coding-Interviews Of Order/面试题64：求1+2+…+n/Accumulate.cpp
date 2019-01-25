// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。

//===========方法一：使用 && 的短路性质==========
#include <stdio.h>

int add(int n, int *sum)
{
	n && add(n - 1, sum);
	return (*sum += n);
}

#if 0
int main()
{
	int sum  = 0;
	int n = 100;
	printf("%d\n",add(n,&sum));
}
#endif

//===========方法二：使用函数指针 ==========
typedef unsigned int(*fun)(unsigned int);
unsigned int Teminator(unsigned int n)
{
	return 0;  // 递归结束，返回0值
}

unsigned int Sum(unsigned int n)
{
	static fun f[2] = {Teminator, Sum};
	return n + f[!!n](n - 1);  // n非零时，!!n为 1 ,调用Sum进行递归运算；n为零时，递归结束，!!n为 0，调用Teminator结束递归
}


// ====================测试代码====================
void Test(const unsigned int n)
{
	printf("%d\n",Sum(n));
}

void Test1()
{
    const unsigned int number = 1;
    Test(number);  //	1 
}

void Test2()
{
    const unsigned int number = 5;
    Test(number);	// 15

}

void Test3()
{
    const unsigned int number = 10;
    Test(number);  // 55
}

void Test4()
{
    const unsigned int number = 0;
    Test(number);  // 0
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}