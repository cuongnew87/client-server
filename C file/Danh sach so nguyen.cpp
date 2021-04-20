#include<stdio.h>
#include<string.h>
struct Node
{
	int Data;
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
NODE *GetNode(int data)
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
void DelHead(LIST &l)
{
	if(l.Head==NULL)
	printf("Ko the xoa");
	else
	{
		l.Head=l.Head->Next;
	}
}
void DelTail(LIST &l)
{
	if(l.Head==NULL)
	printf("Ko the xoa");
	else
	{
		NODE *p=l.Head;
		while(p->Next!=l.Tail)
		{
			p=p->Next;
		}
		l.Tail=p;
		l.Tail->Next=NULL;
	}
}
void DeleteKey(LIST &l, int key) 
{  
    NODE *p=l.Head; 
    NODE *prev;
    // If head node itself holds the key or multiple occurrences of key 
    while (p != NULL && p->Data == key) 
    { 
        l.Head=p->Next;   // Changed head 
        delete p;            // free old head 
        p = l.Head;         // Change Temp 
    } 
    // Delete occurrences other than head 
    while (p != NULL) 
    { 
        // Search for the key to be deleted, keep track of the 
        // previous node as we need to change 'prev->next' 
        while (p != NULL && p->Data != key) 
        { 
            prev = p; 
            p = p->Next; 
        } 
        // If key was not present in linked list 
        if (p == NULL) return;  
        // Unlink the node from linked list 
        prev->Next = p->Next;  
        delete p;  // Free memory 
        //Update Temp for next iteration of outer loop 
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
	printf("\nDanh sach sau khi xoa so 2:\n");
	DeleteKey(l,2);
	Xuat(l);
}
