// 单链表
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
int InitList(LinkList L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return TRUE;
}
int GetLength(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        len++;
        printf("%d:%d\n",len,p->data);
        p = p->next;
    }
    return len;
}
LNode* GetElem(LinkList L,int i){
    LNode* p=L->next;//直接略过头节点
    int j=1;//从第一个节点开始
    while(p!=NULL&&j<i){
        p=p->next;
        j++; 
    }
    return p;
}
LNode* LocateElem(LinkList L,int e){
    LNode* p=L->next;//直接略过头节点
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}
int Insert(LinkList L,int i,int e){
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return FALSE;
    }
    LNode* elem=(LNode *)malloc(sizeof(LNode));
    elem->data=e;
    //开始插入
    elem->next=p->next;
    p->next=elem;
    //插入完毕
    return TRUE;
}
int DeleteElem(LinkList L,int e){
    LNode* p=L;//万一删除第一个呢？不要直接指向第一个了
    LNode* q;//指向要删除的节点，然后free
    while(p->next!=NULL)
    {
        if(p->next->data==e){
            q=p->next;
            p=q->next;
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}
LinkList List_HeadInsert(LinkList L){
    LNode *s;
    int x;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
LinkList List_TailInsert(LinkList L){
    int x;
    L=(LNode*) malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while (x!=999)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
    
}
int main()
{
    LinkList ll;
    ll=List_HeadInsert(ll);
    GetLength(ll);
    return 0;
}