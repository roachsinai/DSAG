/*
* 2016.01.23
*
* 实现循环队列
* front 指向队首元素； rear指向队尾元素下一个位置；
* 对空条件： front == rear
* 堆满条件： front == (rear + 1) % maxSize，其中maxSize为开辟空间的大小
*/

#include "iostream"
#include "cir_queue.h"

using namespace std;

// Function: Create a empty cir_queue
void CreateCir_Queue(Cir_Queue Q, int maxSize)
{
    Q->pBase = new Element[maxSize];
    if (Null == Q->pBase)
    {
        cout << "Memory allocation failure") << endl;
        exit(-1);
    }
    Q->front = 0;
    Q->rear = 0;
    Q->maxSize = maxSize;

}

// Function: Print the cir_queue elements
void TraverseCir_Queue(Cir_Queue Q)
{
    int i = Q->front;
    cout << "循环队列中的元素是：" << endl;
    while (i % Q->maxSize != Q->rear)
    {
        cout << Q->pBase[i] << endl;
        ++i;
    }
    cout << endl;
}

// Function: if queue if full, return ture
bool isFull(Cir_Queue Q)
{
    if (Q->front == (Q->rear + 1) % Q->maxSize)
        return true;
    else
        return false;
}

// Function: if queue is empty, return true
bool isEmpty(Cir_Queue Q)
{
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}

// Function: insert an element
bool EnCir_Queue(Cir_Queue Q, Element val)
{
    if (isFull(Q))
    {
        cout << "循环队列已满！" << endl;
        return false;
    }
    else
    {
        Q->pBase[Q->rear] = val;
        Q->rear = (Q->rear + 1) % Q->maxSize;
        return true;
    }
}

// Function: Remove next element
bool DeCir_Queue(Cir_Queue Q, Element *val)
{
    if (isEmpty(Q))
    {
        cout << "队列已空！" << endl;
        return false;
    }
    else
    {
        *val = Q->pBase[Q->front];
        Q->front = (Q->front + 1) % Q->maxSize;
        return true;
    }
}