#include<stdio.h>
struct Node
{
	int Data;
	struct Node *Next;
};
typedef struct Node NODE;
struct List
{
	NODE *Front;
	NODE *Rear;
};
typedef struct List LIST;
void Init(LIST &l)
{
	l.Front=l.Rear=NULL;
}
NODE *GetNode(int x)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=x;
	p->Next=NULL;
}
void Add(LIST &l,NODE *p)
{
	if(l.Front==NULL)
	l.Front=l.Rear=p;
	else
	{
		l.Rear->Next=p;
		l.Rear=p;
	}
}
void Nhap(LIST &l,int n)
{
	Init(l);
	for(int i=0;i<n;i++)
	{
		int data;
		printf("Nhap so:"); scanf("%d",&data);
		NODE *p=GetNode(data);
		Add(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Front;p!=NULL;p=p->Next)
	{
		printf("%5d",p->Data);
	}
}
int main()
{
	LIST l;
	int n;
	printf("Nhap so luong:");
	scanf("%d",&n);
	Nhap(l,n);
	Xuat(l);
}
