#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void hienthi(int *a,int n)//hien thi so chinh phuong
{
	for(int i=0;i<n;i++)
	{
		int b=(int)sqrt(a[i]);
		if(b*b==a[i])
		printf("%5d",a[i]);
	}
}
void hienthi2(int *a,int n)//hien thi so nguyen to
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
		for(int j=2;j<a[i];j++)
		{
		if(a[i] % j ==0 )
		dem++;
}
}
if(dem==0 && a[i]!=1)
	printf("%5d",*(a+i));
}
}
void hienthi3(int *a,int n)//thay the phan tu am = 0
{
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		a[i]=0;
	}
	xuatmang(a,n);
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
printf("\nSo chinh phuong la:\n");
hienthi(a,n);
printf("\nSo nguyen to la:\n");
hienthi2(a,n);
printf("\nMang sau khi thay phan tu am la:\n");
hienthi3(a,n);
}
