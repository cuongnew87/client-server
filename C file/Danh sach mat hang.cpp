#include<stdio.h>
#include<string.h>
struct MatHang
{
	char mahang[10],tenhang[30],loaihang[30],xuatxu[30];
	int namsx;
	float giaban;
};
struct Node
{
	MatHang Data;
	struct Node *Next;
	struct Node *Prev;
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
NODE *GetNode(MatHang data)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=data;
	p->Next=NULL;
	p->Prev=NULL;
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
		p->Prev=l.Tail;
		l.Tail=p;
	}
}
void Nhap(LIST &l,int n)
{
	KhoiTao(l);
	for(int i=0;i<n;i++)
	{
		MatHang a;
		printf("Nhap ma hang:"); fflush(stdin); gets(a.mahang);
		printf("Nhap ten hang:"); fflush(stdin); gets(a.tenhang);
		printf("Nhap loai hang:"); fflush(stdin); gets(a.loaihang);
		printf("Nhap nam san xuat:"); scanf("%d",&a.namsx);
		printf("Nhap xuat xu:"); fflush(stdin); gets(a.xuatxu);
		printf("Nhap gia ban:"); scanf("%f",&a.giaban);
		NODE *p=GetNode(a);
		AddTail(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%10s%10s%10s%10d%10s%10.2f\n",p->Data.mahang,p->Data.tenhang,p->Data.loaihang,p->Data.namsx,p->Data.xuatxu,p->Data.giaban);
	}
}
void LietKe(LIST l)
{
		for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(strcmp(p->Data.loaihang,"giadung")==0 && p->Data.giaban>=500000 && p->Data.giaban<=1000000)
		printf("%10s%10s%10s%10d%10s%10.2f\n",p->Data.mahang,p->Data.tenhang,p->Data.loaihang,p->Data.namsx,p->Data.xuatxu,p->Data.giaban);
	}
}
void Swap(NODE *p,NODE *q)
{
	char tg1[10];
	strcpy(tg1,p->Data.mahang);
	strcpy(p->Data.mahang,q->Data.mahang);
	strcpy(q->Data.mahang,tg1);
	char tg2[30];
	strcpy(tg2,p->Data.tenhang);
	strcpy(p->Data.tenhang,q->Data.tenhang);
	strcpy(q->Data.tenhang,tg2);
	char tg3[30];
	strcpy(tg3,p->Data.loaihang);
	strcpy(p->Data.loaihang,q->Data.loaihang);
	strcpy(q->Data.loaihang,tg3);
	int tg4;
	tg4=p->Data.namsx;
	p->Data.namsx=q->Data.namsx;
	q->Data.namsx=tg4;
	char tg5[30];
	strcpy(tg5,p->Data.xuatxu);
	strcpy(p->Data.xuatxu,q->Data.xuatxu);
	strcpy(q->Data.xuatxu,tg5);
	float tg6;
	tg6=p->Data.giaban;
	p->Data.giaban=q->Data.giaban;
	q->Data.giaban=tg6;
}
void ListSwap(LIST &l,char x[30])
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		for(NODE *q=p->Next;q!=NULL;q=q->Next)
		if(strcmp(p->Data.xuatxu,x)==0 && strcmp(q->Data.xuatxu,x)!=0)
		{
			Swap(p,q);
		}
	}
	NODE *q=l.Head;
	while(q->Next!=l.Tail)
	{
		q=q->Next;
	}
	if(strcpy(q->Next->Data.xuatxu,x)==0)
	{
		q->Next=q->Next->Next=NULL;
	}
}
int main()
{
	LIST l;
	int n;
	printf("Nhap so luong mat hang:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach mat hang vua nhap:\n");
	Xuat(l);
	printf("Danh sach cac mat hang gia dung co gia tu 500000-1000000:\n");
	LietKe(l);
	printf("Danh sach cac mat hang sau khi xoa mat hang co xuat xu tu TQ:\n");
	ListSwap(l,"TQ");
	Xuat(l);
}
