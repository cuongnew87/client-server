#include<stdio.h>
#include<conio.h>
int BCNN(int a,int b)
{
int n=a*b;
for(int i=n;i>=1;i--)
{
	if(i%a==0 && i%b==0)
	n=i;
	}	
	return n;
}
int UCLN(int a,int b)
{
	int n=1;
	for(int i=n;i<=a*b;i++)
	{
		if(a%i==0 && b%i==0)
		n=i;
	}
	return n;
}
int main()
{
	int a,b;
	printf("Nhap a,b:");
	scanf("%d %d",&a,&b);
	printf("BCNN=%d\n",BCNN(a,b));
	printf("UCLN=%d\n",UCLN(a,b));
}
