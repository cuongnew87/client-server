#include<stdio.h>
#include<stdlib.h>
void nhap(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
}
int main()
{
	int n,*a;
	a = (int *) malloc (sizeof (int));
	printf("Nhap n:");
	scanf("%d",&n);
    nhap(a,n);
	FILE *f = fopen("D:\ghifile.txt","w");
	for(int i=0;i<n;i++)
	{
		fprintf(f,"%5d",*(a+i));
	}
	fclose(f);
}
