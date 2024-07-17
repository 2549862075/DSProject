#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define TheMaxSize 20
typedef struct
{
    int *Data;
    int Length, MaxSize;
} SeqList;

void InitList(SeqList *L)
{
    L->Data=(int*)malloc(sizeof(int)*TheMaxSize);
    L->Length=0;
    L->MaxSize=TheMaxSize;
}
int Insert(SeqList *L,int i,int e){
    if(i<1||i>L->Length+1)
    return FALSE;
    if(L->Length>=L->MaxSize)
    return FALSE;
    for(int j=L->Length;j>=i;j--){
        L->Data[j]=L->Data[j-1];
    }
    L->Data[i-1]=e;
    L->Length++;
    return TRUE;
}
int main()
{
    SeqList sl;
    InitList(&sl);
    Insert(&sl,1,1);
    Insert(&sl,2,3);
    Insert(&sl,2,2);
    printf("%d",sl.Data[1]);
    return 0;
}