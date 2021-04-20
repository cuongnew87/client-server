#include<stdio.h>
#include<string.h>
struct CauThu
{
	char Mact[10],ten[30],vitri[30];
	int tuoi;
    float tienthuong;	
};
struct Node
{
	CauThu Data;
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
NODE *GetNode(CauThu data)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=data;
	p->Next=NULL;
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
void LietKe(LIST l,char x[30])
{
for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(strcmp(p->Data.vitri,x)==0)
		printf("%10s%10s%10s%10d%10.2f\n",p->Data.Mact,p->Data.ten,p->Data.vitri,p->Data.tuoi,p->Data.tienthuong);
	}	
}
void Swap(NODE *p,NODE *q)
{
	char tg1[10];
	strcpy(tg1,p->Data.Mact);
	strcpy(p->Data.Mact,q->Data.Mact);
	strcpy(q->Data.Mact,tg1);
	char tg2[30];
	strcpy(tg2,p->Data.ten);
	strcpy(p->Data.ten,q->Data.ten);
	strcpy(q->Data.ten,tg2);
	char tg3[30];
	strcpy(tg3,p->Data.vitri);
	strcpy(p->Data.vitri,q->Data.vitri);
	strcpy(q->Data.vitri,tg3);
	int tg4;
	tg4=p->Data.tuoi;
	p->Data.tuoi=q->Data.tuoi;
	q->Data.tuoi=tg4;
	float tg5;
	tg5=p->Data.tienthuong;
	p->Data.tienthuong=q->Data.tienthuong;
	q->Data.tienthuong=tg5;
}
void SapXep(LIST &l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		for(NODE *q=p->Next;q!=NULL;q=q->Next)
		{
			if(p->Data.tuoi<q->Data.tuoi)
			{
				Swap(p,q);
			}
		}
	}
}
void Nhap(LIST &l,int n)
{
	KhoiTao(l);
	for(int i=0;i<n;i++)
	{
		CauThu a;
		printf("Nhap ma cau thu:"); fflush(stdin); gets(a.Mact);
		printf("Nhap ten cau thu:"); fflush(stdin); gets(a.ten);
		printf("Nhap vi tri:"); fflush(stdin); gets(a.vitri);
		printf("Nhap tuoi:"); scanf("%d",&a.tuoi);
		printf("Nhap tien luong:"); scanf("%f",&a.tienthuong);
		NODE *p=GetNode(a);
		AddTail(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%10s%10s%10s%10d%10.2f\n",p->Data.Mact,p->Data.ten,p->Data.vitri,p->Data.tuoi,p->Data.tienthuong);
	}
}
int main()
{
	int n;
	LIST l;
	printf("Nhap so luong cau thu:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach cau thu vua nhap:\n");
	Xuat(l);
	printf("Danh sach cau thu o vi tri trung ve la:\n");
	LietKe(l,"trungve");
	printf("Danh sach cau thu theo do tuoi giam dan la:\n");
	SapXep(l);
	Xuat(l);
}
