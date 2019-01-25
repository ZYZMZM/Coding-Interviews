#include "myqueuec.h"

/* 队列: 只允许在表的一端(队尾rear)进行插入操作，而在另一端(队头front)进行删除操作的线性表
 * 插入操作简称为入队  删除操作简称为出队   队列具有先进先出的特点
 */

/*=====队列的入队、出队示意图========
 *
 *  出队 ----------------- 入队
 *   <--- a1,a2,a3,...,an <---
 *      -----------------
 *
 *================================*/

//创建队列 queueCapacity-队列容量
status initQueue(queue *PQueue,int queueCapacity)
{
    //给数组指针分配内存
    PQueue->pBase = (ElemType *)malloc(sizeof(ElemType)*queueCapacity);
    if(!PQueue->pBase)
    {
        printf("给数组指针分配内存失败\n");
        return ERROR;
    }

    PQueue->front = 0; //最开始创建时，队头索引为0
    PQueue->rear = 0; //最开始创建时，队尾索引为0
    PQueue->maxSize = queueCapacity;

    return OK;
}

//销毁队列
void destroyQueue(queue *PQueue)
{
    free(PQueue);  //释放队列数组指针指向的内存
    PQueue = NULL;    //队列数组指针重新指向NULL,避免成为野指针
}

//清空队列
void clearQueue(queue *PQueue)
{
    PQueue->front = 0; //队头索引清0
    PQueue->rear = 0; //队尾索引清0
}

//判断队列是否为空
status isEmpityQueue(queue *PQueue)
{
    if( PQueue->front == PQueue->rear )  //队头==队尾，说明为空
        return TRUE;

    return FALSE;
}

/*
 *在循环队列中,“队满”和“队空”的条件有可能是相同的，都是front==rear，
 *这种情况下，无法区别是“队满”还是“队空”。
 *针对这个问题，有3种可能的处理方法：
 *（1）另设一个标志以区别是“队满”还是“队空”。（即入队/出队前检查是否“队满”/“队空”）
 *（2）设一个计数器，此时甚至还可以省去一个指针。
 *（3）少用一个元素空间，即约定队头指针在队尾指针的下一位置时就作为“队满”的标志，
 *即“队满”条件为：(PQueue->rear+1)%MAX_SIZE == PQueue->front。
 *  【这里采用了第3种处理方法】
 */
//判断队列是否为满
status isFullQueue(queue *PQueue)
{
    if( (PQueue->rear+1)%PQueue->maxSize == PQueue->front )  //队列满
        return TRUE;

    return FALSE;
}

//获得队列长度
int getQueueLen(queue *PQueue)
{
    //正常情况下，队列长度为队尾队头指针之差，但如果首尾指针跨容量最大值时，要%
    return (PQueue->rear - PQueue->front + PQueue->maxSize)%PQueue->maxSize;
}

//新元素入队 [先进先出原则：在队尾的位置插入] element-要插入元素
status enQueue(queue *PQueue,ElemType element)
{
    if(isFullQueue(PQueue)==TRUE)
    {
        printf("队列已满,不能再插入元素了!\n");
        return FALSE;
    }

    //向队列中添加新元素
    PQueue->pBase[PQueue->rear] = element;
    PQueue->rear = (PQueue->rear+1) % PQueue->maxSize; //将rear赋予新的合适的值

    return TRUE;
}

//新元素出队,同时保存出队的元素 [先进先出原则：在队头的位置删除]
status deQueue(queue *PQueue,ElemType *pElement)
{
    //如果队列为空,则返回false
    if(isEmpityQueue(PQueue)==TRUE)
    {
        printf("队列为空，出队失败!\n");
        return FALSE;
    }

    *pElement = PQueue->pBase[PQueue->front];       //先进先出
    PQueue->front = (PQueue->front+1) % PQueue->maxSize; //移到下一位置

    return TRUE;
}

//遍历队列
void queueTraverse(queue *PQueue)
{
    int i = PQueue->front;           //从头开始遍历
    printf("遍历队列：\n");
    while(i != PQueue->rear)     //如果没有到达rear位置，就循环
    {
        printf("%d  ", PQueue->pBase[i]);
        i = (i+1) % PQueue->maxSize;              //移到下一位置
    }
    printf("\n");
}