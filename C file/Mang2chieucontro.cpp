#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	p=(int *)malloc(2*3*sizeof(int));
	int i,j;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
	{
		scanf("%d",(p + 3 * i + j));
		}
		}
		for(int i=0;i<2;i++)
		{
			{
			for(int j=0;j<3;j++)
			printf("%d",*(p + 3 * i + j));
			}
			printf("\n");
			}
			return 0;
}
