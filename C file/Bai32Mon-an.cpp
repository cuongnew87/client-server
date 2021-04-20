#include<stdio.h>
#include<string.h>
struct date
{
	int ngay,thang,nam;
};
struct MonAn
{
	char ID[6],ten[100];
	date ngay_sx;
	int han_sd;
    float gia;	
};
struct Node
{
	MonAn Data;
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
NODE *GetNode(MonAn data)
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
		if(p->Data.ngay_sx.ngay==5 && p->Data.ngay_sx.thang==10 && p->Data.ngay_sx.nam==2019)
		printf("%10s%10s%10d/%d/%d%10d%10.2f\n",p->Data.ID,p->Data.ten,p->Data.ngay_sx.ngay,p->Data.ngay_sx.thang,p->Data.ngay_sx.nam,p->Data.han_sd,p->Data.gia);
	}	
}
void Nhap(LIST &l,int n)
{
	KhoiTao(l);
	for(int i=0;i<n;i++)
	{
		MonAn a;
		printf("Nhap ma mon an:"); fflush(stdin); gets(a.ID);
		printf("Nhap ten mon an:"); fflush(stdin); gets(a.ten);
		printf("Nhap ngay san xuat:"); scanf("%d%d%d",&a.ngay_sx.ngay,&a.ngay_sx.thang,&a.ngay_sx.nam);
		printf("Nhap han su dung:"); scanf("%d",&a.han_sd);
		printf("Nhap gia mon an:"); scanf("%f",&a.gia);
		NODE *p=GetNode(a);
		AddHead(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%10s%10s%10d/%d/%d%10d%10.2f\n",p->Data.ID,p->Data.ten,p->Data.ngay_sx.ngay,p->Data.ngay_sx.thang,p->Data.ngay_sx.nam,p->Data.han_sd,p->Data.gia);
	}
}
int main()
{
	int n;
	LIST l;
	printf("Nhap so luong mon an:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach mon an vua nhap:\n");
	Xuat(l);
	printf("Danh sach mon an duoc san xuat vao ngay 05/10/2019:\n");
	LietKe(l);
	MonAn a;
	printf("Nhap ma mon an:"); fflush(stdin); gets(a.ID);
	printf("Nhap ten mon an:"); fflush(stdin); gets(a.ten);
	printf("Nhap ngay san xuat:"); scanf("%d%d%d",&a.ngay_sx.ngay,&a.ngay_sx.thang,&a.ngay_sx.nam);
	printf("Nhap han su dung:"); scanf("%d",&a.han_sd);
	printf("Nhap gia mon an:"); scanf("%f",&a.gia);
	NODE *p=GetNode(a);
	AddHead(l,p);
	printf("Danh sach mon an sau khi them vao dau danh sach:\n");
	Xuat(l);
	
}
