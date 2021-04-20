#include <stdio.h>
#include <conio.h>
#include <string.h>
struct Sinhvien
{
char tensv[10],masv[10];
float diem;	
};
struct Node
{
	Sinhvien Data;
	struct Node *Next;
};
typedef struct Node NODE;
struct List
{
	NODE *Head;
	NODE *Tail;
};
typedef struct List LIST;

void Khoitao(LIST &l)
{
	l.Head = l.Tail = NULL;
}
NODE* GetNODE(Sinhvien data) 
{
	NODE *p = new NODE;
	if(p == NULL)
	{	
		return NULL;
	}
	p->Data = data;
	p->Next = NULL;
	return p;
}
void AddHead(LIST &l,NODE *p)
{
	if(l.Head == NULL) 
	{
		l.Head = l.Tail = p;
	}
	else
	{
		p ->Next = l.Head; 
		l.Head = p; 		 
	}
}
void AddTail(LIST &l,NODE *p)
{
	if(l.Head == NULL) 
	{
		l.Head = l.Tail = p;
	}
    else
	{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
void AddAt(LIST &l,NODE *p, int x)
{
	if(x == 0 || l.Head == NULL)
	{
		AddHead(l,p);
	}
	else
	{		
	NODE *q=l.Head;
		int k=1;
		while(k != x && q->Next != NULL)
		{
			k++;
			q = q->Next;
		}
		if(k != x)
		{
			AddTail(l,p);
		}
		else
		{
			p->Next = q->Next;
			q->Next = p;
		}
	}
}
void DelHead(LIST &l)
{
	if(l.Head == NULL)
	{
		printf("Khong co phan tu de xoa");
	}
	else
	{
		l.Head = l.Head->Next;
	}
}
void DelTail(LIST &l)
{
	if(l.Head == NULL)
	{
		printf("Khong co phan tu de xoa");
	}
	else
	{
		NODE *p = l.Head;
		while(p->Next != l.Tail)
		{
			p = p->Next;
		}
		{
		l.Tail = p;
		l.Tail->Next = NULL;
	}
	}
}
void DelAt(LIST &l,int x)
{	
if(x == 0 || l.Head->Next == NULL)
{
	DelHead(l);
}
else
{
	int k=1;
	NODE *p = l.Head;
	while(p->Next->Next != NULL && k != x)
	{
		p = p->Next;
		k++;
	}
	if(k != x)
	printf("Khong the xoa\n");
	else
	{
		p->Next = p->Next->Next;
	}
}
	}
void Nhap(LIST &l,int n)
{
	Khoitao(l); 
	for(int i = 1; i <= n; i++)
	{
		Sinhvien data;
		printf("\nNhap ma sinh vien: "); fflush(stdin); gets(data.masv);
		printf("\nNhap ten sinh vien: "); fflush(stdin); gets(data.tensv);
		printf("\nNhap diem sinh vien: ");  scanf("%f",&data.diem);	
		NODE *p = GetNODE(data); 
		AddTail(l, p);
	}
}
void OutPut(LIST l)
{
	for(NODE *p = l.Head; p != NULL; p = p ->Next)
	{
		printf("%10s%10s%10.2f\n",p->Data.masv,p->Data.tensv,p->Data.diem);
	}
}
int Search(LIST l,NODE *a)
{
	NODE *p = l.Head;
	int x=0;
	while(p != NULL && strcmp(p->Data.masv,a->Data.masv) != 0)
	{
		x++;
		p = p->Next;
	}
	return x;
}
void Swap(NODE *p, NODE *q)
{
	float tg1;
    tg1 = p->Data.diem;
    p->Data.diem = q->Data.diem;
    q->Data.diem = tg1;	
    char tg2[10];
    strcpy(tg2,p->Data.masv);
    strcpy(p->Data.masv,q->Data.masv);
    strcpy(q->Data.masv,tg2);
    char tg3[30];
    strcpy(tg3,p->Data.tensv);
    strcpy(p->Data.tensv,q->Data.tensv);
    strcpy(q->Data.tensv,tg3);
}
void SapXep(LIST &l)
{
NODE *p;
NODE *q;
for(p=l.Head;p!=l.Tail;p=p->Next)
{
	for(q=p->Next;q!=NULL;q=q->Next)
	{
		if(p->Data.diem>q->Data.diem)
		Swap(p,q);
	}
}
}
void TimMax(LIST l)
{
	float max=0;
	NODE *p = l.Head;
	while(p!=NULL)
	{
		if(p->Data.diem>max)
		max=p->Data.diem;
		p=p->Next;
	}
	for(p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data.diem==max)
		{
		printf("%10s%10s%10.2f\n",p->Data.masv,p->Data.tensv,p->Data.diem);	
		}
	}
}
void XoaMin(LIST &l,float x)
{
	NODE *p=l.Head;
for(p=l.Head;p!=NULL;p=p->Next)
	{
		if(p->Data.diem>=x)
		{
		printf("%10s%10s%10.2f\n",p->Data.masv,p->Data.tensv,p->Data.diem);	
		}
	}
}
float TB(LIST l)
{
	float tong=0;
	int x=0;
	for(NODE *p=l.Head;p!=NULL;p=p->Next)
	{
		tong += p->Data.diem;
		x++;
	}
	return (float)tong/x;
}
int main()
{
	LIST l;
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &n);
	Nhap(l,n);
	OutPut(l);
	Sinhvien a;
	strcpy(a.masv,"01");
	strcpy(a.tensv,"a");
	a.diem = 5;
	NODE *p;
	p = GetNODE(a);
	AddAt(l,p,2);
	printf("\nDanh sach sinh vien sau khi chen:\n");
	OutPut(l);
  printf("\nDanh sach sau khi xoa dau:\n");
  DelHead(l);
  OutPut(l);
  printf("\nDanh sach sau khi xoa cuoi:\n");
  DelTail(l);
  OutPut(l);
  int y;
  printf("Nhap vi tri can xoa:");
  scanf("%d",&y);
  DelAt(l,y);
  printf("\nDanh sach sau khi xoa:\n");
  OutPut(l);
  NODE *q;
  Sinhvien t;
  printf("Nhap ma can tim:");
  fflush(stdin); gets(t.masv);
  q = GetNODE(t);
  printf("\nVi tri can tim: %d",Search(l,q));
  printf("Danh sach sau khi sap xep theo diem:\n");
  SapXep(l);
  OutPut(l);
  printf("Danh sach sinh vien co diem so cao nhat:\n");
  TimMax(l);
  printf("Danh sach sinh vien sau khi xoa sv co diem <5:\n");
  XoaMin(l,5);
    printf("Diem trung binh:%5.2f",TB(l));
}
