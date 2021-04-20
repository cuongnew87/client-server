//Chuong 2: Mang 1 chieu
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhapmang(float *a,int n)//Nhap mang
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%f",a+i);
	}
}
void xuatmang(float *a,int n)//Xuat mang
{
	for(int i=0;i<n;i++)
		printf("%7.2f",*(a+i));
}
float tb(float *a,int n)//tinh gia tri trung binh
{
	float tb;
	for(int i=0;i<n;i++)
	{
	tb= tb + a[i];
}
	return (float)tb/n;
}
int main()
{
	int n;
	float a[100],*pa;
	pa= (float*) malloc(sizeof (float));
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang vua nhap la:\n");
	xuatmang(a,n);
	printf("\nGia tri trung binh la:%f",tb(a,n));
}
