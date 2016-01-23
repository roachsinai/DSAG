#ifndef CIR_QUEUE_H_
#define CIR_QUEUE_H_
typedef int Element;
struct Cir_Queue
{
	Element *pBase;
	int front;  // 指向队列第一个元素
	int rear;  // 指向队列最后一个元素后一个位置
	int maxSize;  // 循环队列开辟的空间
}Cir_Queue, *p_Cir_Queue;

void CreateCir_Queue(Cir_Queue Q, int maxSize);
void TraverseCir_Queue(Cir_Queue Q);
bool isFull(Cir_Queue Q);
bool isEmpty(Cir_Queue Q);
bool EnCir_Queue(Cir_Queue Q, Element val);
bool DeCirQueue(Cir_Queue Q, Element *val);
#endif