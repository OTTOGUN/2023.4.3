#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

//������˳���Ľṹ
typedef struct {
    ElemType* base;
    int length;
}SqList;

//������˳���ĳ�ʼ��
Status InitList(SqList* S){
    S -> base = (SqList*)malloc(sizeof(ElemType) * MAXSIZE);
    S -> length = 0;
}

//������˳���Ԫ�صĴ���
Status EnList(SqList* S,int Number){
    ElemType e = 0;
    for(int i = 0;i < Number;i++){
        printf("");
        printf("�������%d��Ԫ��\n",i + 1);
        scanf("%d",&e);
        S -> base[i] = e;
    }
    S -> base[Number] = NULL;
    S -> length = Number;
}

//˳���ı���
void PrintList(SqList L){
    int i = 0;
    while(L.base[i]){
        printf("��%d��Ԫ��Ϊ%d\n",i + 1,L.base[i]);
        i++;
    }
}

//˳���Ĳ���
Status Insert(SqList* S,int Number,ElemType e){
    for(int i = 0;i < Number;i++){
        S -> base[S -> length] = e;
                (S -> length)++;
                S -> base[S -> length] = NULL;
    }
}

//˳����ɨ�貢����(ɨ���Ƿ��������Ԫ�أ����з��ظ�Ԫ�ص��±�)
int Scan(SqList* S1,SqList* S2){
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 0;i < S1 -> length;i++){
        for(j = 0;j < S2 -> length;j++){
            if(S1 -> base[i] == S2 -> base[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            Insert(S2,1,S1 -> base[i]);}
    }
}

int main(){
    SqList A;
    SqList B;

    InitList(&A);
    InitList(&B);

    EnList(&A,4);
    printf("#############�ָ���#############\n");
    EnList(&B,3);

    PrintList(A);
    printf("#############�ָ���#############\n");
    PrintList(B);
    printf("#############�ָ���#############\n");

    Scan(&B,&A);

    PrintList(A);
}

