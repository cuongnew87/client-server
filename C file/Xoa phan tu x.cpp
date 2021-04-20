#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
}
void xuatmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",*(a+i));
	}
}
void min(int *a,int n)
{
	int min= *a;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)<min)
		min = *(a+i);
	}
	for(int i=0;i<n;i++)
	{
		if(min == *(a+i))
		printf("%5d",i);
	}
}
int dem(int *a,int n,int x)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(x == *(a+i))
		dem++;
	}
	return dem;
}
void xoa(int *a,int &n,int q)
{
	for(int i=q;i<n;i++)
	{
			*(a+i) = *(a+(i+1));			
	}	
	n--;
}
void xoa1(int *a,int &n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(*(a+i) == x)
		{
		xoa(a,n,i);
		i--;
	}
}
	xuatmang(a,n);
}
int main()
{
	int n,*a;
	a= (int *) malloc (sizeof (int));
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang vua nhap la:\n");
	xuatmang(a,n);
	printf("\nVi tri co so nho nhat la:");
	min(a,n);
	int x;
	printf("\nNhap x:");
	scanf("%d",&x);
	printf("Co %d so %d trong mang",dem(a,n,x),x);
	printf("\nMang sau khi xoa la:\n");
	xoa1(a,n,x);
	
}
