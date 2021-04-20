#include<stdio.h>
#include<conio.h>
void nhapmang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}
void timmin(int a[],int n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
		for(int i=0;i<n;i++)
	{
		if(a[i] == min)
		printf("%2d",i+1);
	}
}
int max(int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
} 
void sont(int a[],int n)
{
	int dem=0;
	int dem_1=0;
	printf("\nDay so nguyen to la:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<a[i];j++)	
		{
			if(a[i]%j==0)
			dem++;		
	}
	if(dem == 0)
		{
		printf("%5d",a[i]);
		dem_1++;
}
}
	printf("\nCo %d so nguyen to",dem_1);
}
int main()
{
	int n,a[100];
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("Mang vua nhap vua nhap la:\n");
	xuatmang(a,n);
	printf("\nVi tri co so nho nhat la:");
	timmin(a,n);
	printf("\nGia tri max trong mang la: %d",max(a,n));
	sont(a,n);
}
