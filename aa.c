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

//》》》顺序表的结构
typedef struct {
    ElemType* base;
    int length;
}SqList;

//》》》顺序表的初始化
Status InitList(SqList* S){
    S -> base = (SqList*)malloc(sizeof(ElemType) * MAXSIZE);
    S -> length = 0;
}

//》》》顺序表元素的创建
Status EnList(SqList* S,int Number){
    ElemType e = 0;
    for(int i = 0;i < Number;i++){
        printf("");
        printf("请输入第%d个元素\n",i + 1);
        scanf("%d",&e);
        S -> base[i] = e;
    }
    S -> base[Number] = NULL;
    S -> length = Number;
}

//顺序表的遍历
void PrintList(SqList L){
    int i = 0;
    while(L.base[i]){
        printf("第%d个元素为%d\n",i + 1,L.base[i]);
        i++;
    }
}

//顺序表的插入
Status Insert(SqList* S,int Number,ElemType e){
    for(int i = 0;i < Number;i++){
        S -> base[S -> length] = e;
                (S -> length)++;
                S -> base[S -> length] = NULL;
    }
}

//顺序表的扫描并插入(扫描是否有相异的元素，若有返回该元素的下标)
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
    printf("#############分割线#############\n");
    EnList(&B,3);

    PrintList(A);
    printf("#############分割线#############\n");
    PrintList(B);
    printf("#############分割线#############\n");

    Scan(&B,&A);

    PrintList(A);
}

