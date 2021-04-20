#include<stdio.h>
#include<conio.h>
int SNT(int n)
{
for(int i=2;i<n;i++)
	if(n%i==0)	
	return 1;
	return 0;
}
int main()
{
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	if(SNT(n)==1)
	printf("%d ko la so nguyen to",n);
	else
	printf("%d la so nguyen to",n);
}
