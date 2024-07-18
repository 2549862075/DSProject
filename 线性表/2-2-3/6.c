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

void InitList1(SeqList *L)
{
    L->Data = (int *)malloc(sizeof(int) * TheMaxSize);
    L->Length = 0;
    L->MaxSize = TheMaxSize;
    for (int i = 0; i < L->MaxSize; i++)
    {
        L->Data[i] = i * 2 + 1;
        L->Length++;
    }
}

void InitList2(SeqList *L)
{
    L->Data = (int *)malloc(sizeof(int) * TheMaxSize);
    L->Length = 0;
    L->MaxSize = TheMaxSize;
    for (int i = 0; i < L->MaxSize; i++)
    {
        L->Data[i] = (i + 1) * 2;
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
int UpDateElem(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->Length)
    {
        return FALSE;
    }
    L->Data[i - 1] = e;
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
void MergeList(SeqList *L1, SeqList *L2, SeqList *L3)
{
    int i = 0; // 记录L1
    int j = 0; // 记录L2
    while (i < L1->Length && j < L2->Length)
    {
        if (L1->Data[i] < L2->Data[j])
        {
            L3->Data[i + j] = L1->Data[i];
            i++;
            L3->Length++;
            continue;
        }
        else
        {
            L3->Data[i + j] = L2->Data[j];
            j++;
            L3->Length++;
            continue;
        }
    }
    if (i == L1->Length)
    {
        for (j; j < L2->Length; j++)
        {
            L3->Data[i + j] = L2->Data[j];
            L3->Length++;
        }
    }
    else if (j == L2->Length)
    {
        for (i; i < L1->Length; i++)
        {
            L3->Data[i + j] = L1->Data[i];
            L3->Length++;
        }
    }
}
int main()
{
    SeqList sl1;
    SeqList sl2;
    SeqList sl3;
    sl3.Data = (int *)malloc(sizeof(int) * 40);
    sl3.Length = 0;
    sl3.MaxSize = 40;
    InitList1(&sl1);
    InitList2(&sl2);
    MergeList(&sl1, &sl2, &sl3);
    PrintfList(&sl1);
    PrintfList(&sl2);
    PrintfList(&sl3);
    return 0;
}