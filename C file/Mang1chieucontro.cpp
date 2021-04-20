#include<stdio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
	printf("a[%d]=",i);
	scanf("%5d",a+i);
}
}
void xuatmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",*(a+i));
	}
}
int main()
{
	int *pa,n,a[100];
 pa=(int *)	malloc (sizeof(int));
printf("Nhap n:");
scanf("%d",&n);
nhapmang(a,n);
printf("\nMang vua nhap la:\n");
xuatmang(a,n);
}
