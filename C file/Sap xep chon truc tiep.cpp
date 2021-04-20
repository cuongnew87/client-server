#include<stdio.h>
int main()
{
	int a[100],min;
	int n;
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("Day so sau khi sap xep la:\n");
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
			min = j;
			}
		}
		if(min != i)
		{
			int tg = a[i];
			a[i] = a[min];
			a[min] = tg;
		}
	}
for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);		
	}
}
