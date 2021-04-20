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
void sapxep(int *a,int n)//sap xep theo chieu tang dan
{
	int tg;
	for(int i=0;i<n+1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
	}
	xuatmang(a,n);
}
int max(int *a,int n)//tim Max
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}
void min(int *a,int n)//tim vi tri Min
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<=a[0])
		printf("%5d",i);
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
printf("\nMang sau khi sap xep la:\n");
sapxep(a,n);
printf("\nGia tri lon nhat la:%d\n",max(a,n));
printf("\nVi tri min la:\n");
min(a,n);
}
