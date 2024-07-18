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
    L->Data = (int *)malloc(sizeof(int) * TheMaxSize);
    L->Length = 0;
    L->MaxSize = TheMaxSize;
    for (int i = 0; i < L->MaxSize; i++)
    {
        L->Data[i] = i + 1;
        L->Length++;
    }
}
int Insert(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->Length + 1)
        return FALSE;
    if (L->Length >= L->MaxSize)
        return FALSE;
    for (int j = L->Length; j >= i; j--)
    {
        L->Data[j] = L->Data[j - 1];
    }
    L->Data[i - 1] = e;
    L->Length++;
    return TRUE;
}
int Delete(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->Length)
        return FALSE;
    e = L->Data[i - 1];
    for (int j = i; j < L->Length; j--)
    {
        L->Data[j - 1] = L->Data[j];
    }
    L->Length--;
    return TRUE;
}
int UpDateElem(SeqList *L,int i,int e){
    if(i<1||i>L->Length){
        return FALSE;
    }
    L->Data[i-1]=e;
    return TRUE;
}
int LocateElem(SeqList *L, int e)
{
    for (int i = 0; i < L->Length; i++)
    {
        if (L->Data[i] == e)
        {
            return i + 1;
        }
    }
    return FALSE;
}
void PrintfList(SeqList *L)
{
    for (int i = 0; i < L->Length; i++)
    {
        printf("%d : %d\n", i, L->Data[i]);
    }
}
void RemoveMin(SeqList *L)
{
    if(L->Length<1){
        printf("输入顺序表为空");
    }
    int i=L->Data[0];
    int j=0;
    for(int k=1;k<L->Length;k++){
        if(L->Data[k]<i){
            i=L->Data[k];
            j=k;
        }
    }
    if(j!=L->Length){
        UpDateElem(L,j+1,L->Data[L->Length-1]);
    }
    Delete(L,L->Length,0);
}
int main()
{
    SeqList sl;
    InitList(&sl);
    PrintfList(&sl);
    RemoveMin(&sl);
    PrintfList(&sl);
    return 0;
}