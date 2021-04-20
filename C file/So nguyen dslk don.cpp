#include<stdio.h>
#include<string.h>
struct Node
{
	int Data;
	struct Node *Next;
};
typedef struct Node NODE;
struct List
{
	NODE *Head;
	NODE *Tail;
};
typedef struct List LIST;
void KhoiTao(LIST &l)
{
	l.Head=l.Tail=NULL;
}
NODE *GetNode(int data)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=data;
	p->Next=NULL;
	return p;
}
void AddTail(LIST &l,NODE *p)
{
	if(l.Head==NULL)
	{
		l.Head=l.Tail=p;
	}
	else
	{
		l.Tail->Next=p;
		l.Tail=p;
	}
}
int Duyet(LIST l,int x)
{
	int dem=0;
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data==x)
		dem++;
	}
	return dem;
}
void TimMin(LIST l)
{
	int min;
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data>=0)
		{
		min=p->Data;
		break;
	}
	}
for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data<min && p->Data>=0)
		{
		min=p->Data;
	}
}
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data==min)
		printf("%5d",p->Data);
	}
}
void TimMax(LIST l)
{
	int max;
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data<=0)
		{
		max=p->Data;
		break;
	}
	}
for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data>max && p->Data<=0)
		{
		max=p->Data;
	}
}
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data==max)
		printf("%5d",p->Data);
	}
}
void Nhap(LIST &l,int n)
{
	KhoiTao(l);
	for(int i=0;i<n;i++)
	{
		int a;
		printf("Nhap so:"); scanf("%d",&a);
		NODE *p=GetNode(a);
		AddTail(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%5d",p->Data);
	}
}
void DeleteKey(LIST &l, int key) 
{  
    NODE *p=l.Head; 
    NODE *prev;
    while (p != NULL && p->Data == key) 
    { 
        l.Head=p->Next;   
        delete p;            
        p = l.Head;       
    } 
    while (p != NULL) 
    { 
        while (p != NULL && p->Data != key) 
        { 
            prev = p; 
            p = p->Next; 
        } 
        if (p == NULL) return;  
        prev->Next = p->Next;  
        delete p;  
        p = prev->Next; 
    } 
} 
int main()
{
	LIST l;
	int n;
	printf("Nhap so luong:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach vua nhap:\n");
	Xuat(l);
	printf("\nPhan tu duong be nhat la:\n");
	TimMin(l);
	printf("\nPhan tu am lon nhat la:\n");
	TimMax(l);
	int x;
	printf("\nNhap so can duyet:"); scanf("%d",&x);
	printf("\nSo %d xuat hien %d lan\n",x,Duyet(l,x));
	printf("\nDanh sach sau khi xoa so %d:\n",x);
	DeleteKey(l,x);
	Xuat(l);
}
