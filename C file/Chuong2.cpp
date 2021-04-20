//Chuong 2: Mang 1 chieu
#include<stdio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)//Nhap mang
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
}
void xuatmang(int *a,int n)//Xuat mang
{
	for(int i=0;i<n;i++)
		printf("%5d",*(a+i));
}
void mangdao(int *a,int n)//Hien thi mang dao
{
	for(int i=n-1;i>=0;i--)
	printf("%5d",a[i]);
}
int main()
{
	int *pa,n,a[100];
	pa= (int*) malloc(sizeof (int));
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang vua nhap la:\n");
	xuatmang(a,n);
	printf("\nMang dao la:\n");
	mangdao(a,n);
}
