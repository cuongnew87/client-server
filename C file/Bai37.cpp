#include<stdio.h>
#include<stdlib.h>
void nhapmang(float *a,int n)
{
	for(int i=0;i<n;i++)
	{
	printf("a[%d]=",i);
	scanf("%f",a+i);
}
}
void xuatmang(float *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5.2f",*(a+i));
	}
}
float tich(float *a,int n)//tim tich cac so duong
{
	float tich=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		tich *=  a[i];
	}
	return tich;
	}
int main()
{
	int n;
	float *pa,a[100];
 pa=(float *)	malloc (sizeof(float));
printf("Nhap n:");
scanf("%d",&n);
nhapmang(a,n);
printf("\nMang vua nhap la:\n");
xuatmang(a,n);
printf("\nTich cac so duong la:%f",tich(a,n));
}
