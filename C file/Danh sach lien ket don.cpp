#include<stdio.h>
#include<stdlib.h>
struct DS
{
	int data;
	struct DS *next;
};
typedef struct DS *node;
node createnode(int giatri) //Tao moi 1 node
{
	node a;
	a = (node)malloc(sizeof(struct DS));
	a -> next = NULL;
	a -> data = giatri;
	return a;
}
node addhead(node head, int giatri) //Them gia tri vao dau danh sach
{
	node a = createnode(giatri);
	if(head == NULL)
	{
		head = a;
	}
	else
	{
		a->next = head;
		head = a;
	}
	return head;
}
node addtail(node head, int giatri) //Them gia tri vao cuoi danh sach
{
	node a,p;
	a = createnode(giatri);
	if(head == NULL)
	{
		head = a;
	}
	else
	{
		p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = a;
	}
	return head;
}
node addat(node head,int giatri,int vitri) //Them vao 1 vi tri bat ki
{
	if(head == NULL || vitri == 0)
	{
		head = addhead(head,giatri);
	}
	else
	{
	node p=head;
	int k=1;
	while(p != NULL && k!= vitri)
	{
		p=p->next;
		k++;
	}
	if(k!=vitri)
	{
		head=addtail(head,giatri);
	}
	else
	{
		node a=createnode(giatri);
		a->next = p->next;
		p->next = a; 
	}
}
return head;
}
node delhead(node head)
{
	if(head == NULL)
	printf("Khong co phan tu de xoa");
	else
	head = head->next;
	return head;
}
node deltail(node head)
{
	node p = head;
while(p->next->next != NULL)
{
	p = p->next;
}
p->next = NULL;
	return head;
}
int timvitri(node head,int giatri)
{
	int vitri=0;
	for(node p = head;p != NULL;p = p->next)
	{
		if(p->data == giatri)
		return vitri;
		vitri++;
	}
	return -1;
}
void Duyet(node head) //Duyet danh sach
{
	printf("\n");
	for(node p = head; p!= NULL;p = p->next)
	printf("%5d",p->data);
}
node Khoitao() 
{
	node head;
	head = NULL;
	return head;
}
node Nhap()
{
	node head = Khoitao();
	int n,giatri;
	do
	{
		printf("\nNhap so luong phan tu:");
		scanf("%d",&n);
	}
	while(n<=0);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap gia tri:");
		scanf("%d",&giatri);
	    head = addtail(head,giatri);
    }
    	return head;
}

int main()
{
	node head = Nhap();
	Duyet(head);
	int a,b,c;
	printf("\nNhap gia tri can them vao dau:");
	scanf("%d",&a);
    head = 	addhead(head,a);
	Duyet(head);
	printf("\nNhap gia tri can them vao cuoi:");
	scanf("%d",&b);
    head = 	addtail(head,b);
	Duyet(head);
	printf("\nDanh sach sau khi xoa phan tu dau:");
	head = delhead(head);
	Duyet(head);
	printf("\nDanh sach sau khi xoa phan tu cuoi:");
	head = deltail(head);
	Duyet(head);
	printf("\nNhap so can tim:");
	scanf("%d",&c);
	int vitri = timvitri(head,c);
	printf("\nVi tri can tim la: %d",vitri);
	printf("\n");
	head = addat(head,9,2);
	Duyet(head);
}
