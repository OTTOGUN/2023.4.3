#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef int QElemType;

//0.链队的存储结构
typedef struct QNode{
    QElemType* data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;     //队头指针
    QueuePtr rear;      //队尾指针
}LinkQueue;

//》》》1.链队的初始化(InitQueue)
Status InitQueue(LinkQueue* Q)
{
    //》》》生成头结点，队头队尾指向此结点
    if(!(Q -> front = Q -> rear = (QueuePtr)malloc(sizeof(QNode))))
    {
        exit(OVERFLOW);
    }
    //头结点的指针域置空
    Q -> front -> next = NULL;
    return OK;
}

//》》》2.入队(EnQueue)
Status EnQueue(LinkQueue* Q,QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p -> data = e;
    p -> next = NULL;
    Q -> rear -> next = p;
    Q -> rear = p;
    return OK;
}

//》》》3.出队(DeQueue)
Status DeQueue(LinkQueue* Q,QElemType *e){
    if(Q -> front == Q -> rear)
    {
        printf("空对列");
        return ERROR;
    }
    QueuePtr p = Q -> front -> next;
    *e = p -> data;
    Q -> front -> next = p -> next;
    if(Q -> front == Q -> rear)
    {
        printf("空对列");
        return ERROR;
    }
    free(p);
    return OK;
}

//》》》4.取队头元素(GetHead)
int GetHead(LinkQueue* Q){
    if(Q -> rear == Q -> front){
        printf("空队列");
        return ERROR;
    }
    return Q -> front -> next -> data;
}


void Delete(char* a,char target){
    int i = 0;
    int j = i;
    for(i = 0;a[i] != '\0';i++){
        //》》》从第一个元素开始直到'\0'
        if(a[i] != target){
            //》》》如果该元素不是目标元素，目标元素之前的不变动，目标元素之后的向前移一个位置
            a[j++] = a[i];
        }
    }
    a[j] = '\0';
}

void Is_Prime_Number(int Number){
    if(Number == 1){
        printf("1不算");
    }
    for(int i = 2;i <= sqrt(Number);i++){
        if(Number % i == 0){
            printf("%d不是素数",Number);
            break;
        }else if(i > sqrt(Number)){
            printf("%d是素数",Number);
            break;
        }
    }
}

int main(){
    int a = 0;
    printf("请输入想要判定的数字\n");
    scanf("%d",&a);
    Is_Prime_Number(a);
    //printf("%f",sqrt(a));
}