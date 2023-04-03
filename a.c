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

//0.���ӵĴ洢�ṹ
typedef struct QNode{
    QElemType* data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;     //��ͷָ��
    QueuePtr rear;      //��βָ��
}LinkQueue;

//������1.���ӵĳ�ʼ��(InitQueue)
Status InitQueue(LinkQueue* Q)
{
    //����������ͷ��㣬��ͷ��βָ��˽��
    if(!(Q -> front = Q -> rear = (QueuePtr)malloc(sizeof(QNode))))
    {
        exit(OVERFLOW);
    }
    //ͷ����ָ�����ÿ�
    Q -> front -> next = NULL;
    return OK;
}

//������2.���(EnQueue)
Status EnQueue(LinkQueue* Q,QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p -> data = e;
    p -> next = NULL;
    Q -> rear -> next = p;
    Q -> rear = p;
    return OK;
}

//������3.����(DeQueue)
Status DeQueue(LinkQueue* Q,QElemType *e){
    if(Q -> front == Q -> rear)
    {
        printf("�ն���");
        return ERROR;
    }
    QueuePtr p = Q -> front -> next;
    *e = p -> data;
    Q -> front -> next = p -> next;
    if(Q -> front == Q -> rear)
    {
        printf("�ն���");
        return ERROR;
    }
    free(p);
    return OK;
}

//������4.ȡ��ͷԪ��(GetHead)
int GetHead(LinkQueue* Q){
    if(Q -> rear == Q -> front){
        printf("�ն���");
        return ERROR;
    }
    return Q -> front -> next -> data;
}


void Delete(char* a,char target){
    int i = 0;
    int j = i;
    for(i = 0;a[i] != '\0';i++){
        //�������ӵ�һ��Ԫ�ؿ�ʼֱ��'\0'
        if(a[i] != target){
            //�����������Ԫ�ز���Ŀ��Ԫ�أ�Ŀ��Ԫ��֮ǰ�Ĳ��䶯��Ŀ��Ԫ��֮�����ǰ��һ��λ��
            a[j++] = a[i];
        }
    }
    a[j] = '\0';
}

void Is_Prime_Number(int Number){
    if(Number == 1){
        printf("1����");
    }
    for(int i = 2;i <= sqrt(Number);i++){
        if(Number % i == 0){
            printf("%d��������",Number);
            break;
        }else if(i > sqrt(Number)){
            printf("%d������",Number);
            break;
        }
    }
}

int main(){
    int a = 0;
    printf("��������Ҫ�ж�������\n");
    scanf("%d",&a);
    Is_Prime_Number(a);
    //printf("%f",sqrt(a));
}