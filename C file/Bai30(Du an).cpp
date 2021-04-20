#include<stdio.h>
#include<string.h>
struct DuAn
{
	char mada[10],tenda[30],quimo[10];
    float kinhphi;	
};
struct Node
{
	DuAn Data;
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
NODE *GetNode(DuAn data)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=data;
	p->Next=NULL;
}
void AddHead(LIST &l,NODE *p)
{
	if(l.Head==NULL)
	{
		l.Head=l.Tail=p;
	}
	else
	{
		p->Next=l.Head;
		l.Head=p;
	}
}
void LietKe(LIST l)
{
for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data.kinhphi>=5000 && p->Data.kinhphi<=10000)
		printf("%10s%10s%10s%10.2f\n",p->Data.mada,p->Data.tenda,p->Data.quimo,p->Data.kinhphi);
	}	
}
int Duyet(LIST l,char x[10])
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(strcmp(p->Data.mada,x)==0)
		return 1;
	}	
	return 0;
}
void Xoa(LIST &l,char x[10])
{
	if(strcmp(l.Head->Data.mada,x)==0)
	{
		l.Head=l.Head->Next;
	}
	else
	{
		NODE *p=l.Head;
		while(p->Next->Next!=NULL && strcmp(p->Next->Data.mada,x)!=0)
		{
			p=p->Next;
		}
		if(strcmp(p->Next->Data.mada,x)==0)
		{
		p->Next=p->Next->Next;
	}
	}
}
void Nhap(LIST &l,int n)
{
	KhoiTao(l);
	for(int i=0;i<n;i++)
	{
		DuAn a;
		printf("Nhap ma du an:"); fflush(stdin); gets(a.mada);
		printf("Nhap ten du an:"); fflush(stdin); gets(a.tenda);
		printf("Nhap qui mo:"); fflush(stdin); gets(a.quimo);
		printf("Nhap kinh phi:"); scanf("%f",&a.kinhphi);
		NODE *p=GetNode(a);
		AddHead(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%10s%10s%10s%10.2f\n",p->Data.mada,p->Data.tenda,p->Data.quimo,p->Data.kinhphi);
	}
}
int main()
{
	int n;
	LIST l;
	printf("Nhap so luong du an:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach du an vua nhap:\n");
	Xuat(l);
	printf("Danh sach du an co kinh phi tu 5000-10000:\n");
	LietKe(l);
	char x[10];
	printf("Nhap ma du an can tim:");
	fflush(stdin);
	gets(x);
	int k=Duyet(l,x);
	if(k==1)
	{
		printf("Ma du an da duoc luu\n");
		Xoa(l,x);
		printf("Danh sach du an sau khi xoa:\n");
		Xuat(l);
	}
	else
	{
		printf("Ma du an khong ton tai\n");
	}
}
