#pragma once
typedef struct Node
{
	int data;
	Node *next;
}Node,*List;

void InitList(List plist);//初始化单链表

bool Insert_head(List plist,int val);//头插法

bool Insert_tail(List plist,int val);//尾插法

bool Insert_pos(List plist,int pos,int val);//pos 位置插入

bool IsEmpty(List plist);//是否为空

Node *Search_pre(List plist,int key);//查找 key 的前驱

bool Delete(List plist,int key);//删除 key 这个结点

void Destroy(List plist);//摧毁函数（如果有动态开辟内存）

int GetLength(List plist);//得到单链表的长度

void Show(List plist);//打印单链表
