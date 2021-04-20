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
	struct Node *Prev;
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
	p->Prev = NULL;
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
		l.Head->Prev = p; 
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
		p->Prev = l.Tail;
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
		int k=1;
		while(k != x && l.Head->Next != NULL)
		{
			k++;
			l.Head = l.Head->Next;
		}
		if(k != x)
		{
			AddTail(l,p);
		}
		else
		{
			p->Next = l.Head->Next;
			l.Head->Next = p;
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
		l.Head->Prev = NULL;
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
		l.Tail->Next = p;
		l.Tail = p;
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
int main()
{
	LIST l;
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &n);
	Nhap(l,n);
	printf("Danh sach sinh vien :\n");
	OutPut(l);
	printf("\nDanh sach sinh vien sau khi chen dau:\n");
	Sinhvien a;
    strcpy(a.tensv,"a");
    strcpy(a.masv,"01");
    a.diem = 5;
	NODE *p;
	p = GetNODE(a);
	AddHead(l,p);
	OutPut(l);
	printf("\nDanh sach sinh vien sau khi chen cuoi:\n");
	Sinhvien b;
    strcpy(b.tensv,"b");
    strcpy(b.masv,"02");
    b.diem = 6;
	NODE *q;
	q = GetNODE(b);
	AddTail(l,q);
	OutPut(l);
}
