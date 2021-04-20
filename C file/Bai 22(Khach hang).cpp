#include<stdio.h>
#include<string.h>
struct KhachHang
{
	int Makh;
	char Tenkh[30],Diachi[30],Sdt[10];
    float Tienthanhtoan;	
};
struct Node
{
	KhachHang Data;
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
NODE *GetNode(KhachHang data)
{
	NODE *p=new NODE;
	if(p==NULL)
	return NULL;
	p->Data=data;
	p->Next=NULL;
	p->Prev=NULL;
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
void LietKe(LIST l,char x[30])
{
for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		if(strcmp(p->Data.Diachi,x)==0)
		printf("%10d%10s%10s%10s%10.2f\n",p->Data.Makh,p->Data.Tenkh,p->Data.Diachi,p->Data.Sdt,p->Data.Tienthanhtoan);
	}	
}
void Swap(NODE *p,NODE *q)
{
	int tg1;
	tg1=p->Data.Makh;
	p->Data.Makh=q->Data.Makh;
	q->Data.Makh=tg1;
	char tg2[30];
	strcpy(tg2,p->Data.Tenkh);
	strcpy(p->Data.Tenkh,q->Data.Tenkh);
	strcpy(q->Data.Tenkh,tg2);
	char tg3[30];
	strcpy(tg3,p->Data.Diachi);
	strcpy(p->Data.Diachi,q->Data.Diachi);
	strcpy(q->Data.Diachi,tg3);
	char tg4[10];
	strcpy(tg4,p->Data.Sdt);
	strcpy(p->Data.Sdt,q->Data.Sdt);
	strcpy(q->Data.Sdt,tg4);
	float tg5;
	tg5=p->Data.Tienthanhtoan;
	p->Data.Tienthanhtoan=q->Data.Tienthanhtoan;
	q->Data.Tienthanhtoan=tg5;
}
void SapXep(LIST &l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		for(NODE *q=p->Next;q!=NULL;q=q->Next)
		{
			if(p->Data.Tienthanhtoan<q->Data.Tienthanhtoan)
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
		KhachHang a;
		printf("Nhap ma khach hang:"); scanf("%d",&a.Makh);
		printf("Nhap ten khach hang:"); fflush(stdin); gets(a.Tenkh);
		printf("Nhap dia chi:"); fflush(stdin); gets(a.Diachi);
		printf("Nhap so dien thoai:"); fflush(stdin); gets(a.Sdt);
		printf("Nhap tien thanh toan:"); scanf("%f",&a.Tienthanhtoan);
		NODE *p=GetNode(a);
		AddTail(l,p);
	}
}
void Xuat(LIST l)
{
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		printf("%10d%10s%10s%10s%10.2f\n",p->Data.Makh,p->Data.Tenkh,p->Data.Diachi,p->Data.Sdt,p->Data.Tienthanhtoan);
	}
}
int main()
{
	int n;
	LIST l;
	printf("Nhap so luong khach hang:"); scanf("%d",&n);
	Nhap(l,n);
	printf("Danh sach khach hang vua nhap:\n");
	Xuat(l);
	printf("Danh sach khach hang co dia chi o Ha Noi la:\n");
	LietKe(l,"HaNoi");
	printf("Danh sach khach hang co tong tien thanh toan giam dan la:\n");
	SapXep(l);
	Xuat(l);
}
