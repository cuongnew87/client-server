#include<stdio.h>
#include<conio.h>
int main()
{
char str[100][100];
int n;
printf("Nhap so phan tu:");
scanf("%d",&n);
int a[100];
int dem=0;
for(int i=0;i<n;i++)
{
	printf("a[%d]=",i);
	scanf("%d",&a[i]);
	dem++;
}
int Dem[n];
for(int i=0; i<n; i++)
{
	Dem[i] = 0;
}
int max = 0;
for(int i=0;i<n;i++)
{
	if(max <= a[i])
	max = a[i];
}
for(int i=0;i<max;i++)
{
	int Dich_phai = 0;
	while(Dem[i] != a[i])
	{
		str[Dich_phai][i] = "*";
		Dem[i]++;
		Dich_phai++;
	}
}
for(int i=0;i<dem;i++)
{
	for(int j=0;j<max;j++)
	{
		printf("%c",str[i][j]);
	}
}
}
