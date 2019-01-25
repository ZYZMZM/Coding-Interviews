#include <stdio.h>
#include "myqueuec.h"

int main(void)
{
    int value;          //用于保存出队的元素
    //创建队列对象
    queue *PQueue = (queue *)malloc(sizeof(queue));
    if(!PQueue->pBase)
    {
        printf("给队列对象分配内存失败\n");
        return -1;
    }

    //调用初始化队列的函数
    initQueue(PQueue,MAX_SIZE);
    //调用出队函数
    //enQueue(PQueue, 1);
    //enQueue(PQueue, 2);
    //enQueue(PQueue, 3);
    //enQueue(PQueue, 4);
    //enQueue(PQueue, 5);
    //enQueue(PQueue, 6);
    //enQueue(PQueue, 7);
    //enQueue(PQueue, 8);

	for(int i = 0;i < 10;i++)
	{
		enQueue(PQueue,i);    //0-7
	}



    //调用遍历队列的函数
    queueTraverse(PQueue);
    //调用出队函数
    if(deQueue(PQueue, &value))
    {
        printf("出队一次，元素为：%d\n", value);
    }
    queueTraverse(PQueue);
    if(deQueue(PQueue, &value))
    {
        printf("出队一次，元素为：%d\n", value);
    }
    queueTraverse(PQueue);

    free(PQueue);
    PQueue = NULL;

    getchar();
    return 0;
}
