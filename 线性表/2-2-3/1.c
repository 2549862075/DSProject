#include <stdio.h>
#include <stdlib.h>
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
int main()
{
    SeqList sl;
    InitList(&sl);
    printf("hello world");
    return 0;
}