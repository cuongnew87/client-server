#include<stdio.h>
#include<conio.h>
struct Node
{
	int Data;
	struct Node *Next;
};
typedef struct Node NODE;
struct Stack
{
	NODE *top;
};
typedef struct Stack STACK;
void KhoiTao(STACK &s)
{
	s.top=NULL;
}
NODE *GetNode(int x)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=x;
	p->Next=NULL;
}
void Push(STACK &s,int x)
{
	NODE *p= GetNode(x);
	if(p!=NULL)
	{
		p->Next=s.top;
		s.top=p;
	}
}
void InPut(STACK &s,int n)
{
	KhoiTao(s);
	for(int i=0;i<n;i++)
	{
		int x;
		printf("Nhap x:"); scanf("%d",&x);
		Push(s,x);
	}
}
void OutPut(STACK s)
{
	for(NODE *p=s.top;p!=NULL;p=p->Next)
	{
		printf("%5d",p->Data);
	}
}
int Pop(STACK &s)
{
	NODE *p;
	int x;
	if(s.top!=NULL)
	{
		p=s.top;
		s.top=p->Next;
		x=p->Data;
	}
}
int main()
{
	int n;
	STACK s;
	printf("Nhap so luong phan tu:");
	scanf("%d",&n);
	InPut(s,n);
	printf("\nDanh sach sau khi nhap:\n");
	OutPut(s);
}
