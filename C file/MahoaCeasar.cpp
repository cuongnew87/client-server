#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define SIZE 100
//VD: Ma hoa chu center , k = 5 -> Sau khi ma hoa: hjsyjw
    void Khoitao(char Str[])
    {
        for(int i = 0; i < SIZE; i++)
        {
        	Str[i]=0;
		}        
    }
void Mahoa(char Str_Nguon[],char Str_Mahoa[],int len,int k)
{
	for(int i=0;i<len;i++)
	{
		char c = Str_Nguon[i]; 
		if(c >= 'A' && c <= 'Z') // c = C
		{
			Str_Mahoa[i] = (Str_Nguon[i] - 'A' + k) % 26 +'A'; //Str_Mahoa = (3 - 0 + 5) % 26 + 0 = 7 = H  (A = 0, C = 3, H = 7, k = 5 )			
		}
		else if(c >= 'a' && c <= 'z')
		{
			Str_Mahoa[i] = (Str_Nguon[i] - 'a' + k) % 26 +'a'; //Str_Mahoa = (3 - 0 + 5) % 26 + 0 = 7 = h  (a = 0, c = 3, h = 7, k = 5 )			
		}
	}
}
void Giaima(char Str_Nguon[],char Str_Giaima[],int len,int k)
{
	for(int i=0;i<len;i++)
	{
		char c = Str_Nguon[i]; 
		if(c >= 'A' && c <= 'Z') // c = C
		{
			Str_Giaima[i] = (abs(Str_Nguon[i] - 'A' - k)) % 26 +'A'; //Str_Giaima = (|7 - 0 - 5|) % 26 + 0 = 2 = C  (A = 0, C = 3, H = 7, k = 5 )			
		}
		else if(c >= 'a' && c <= 'z')
		{
			Str_Giaima[i] = (abs(Str_Nguon[i] - 'a' - k)) % 26 +'a'; //Str_Giaima = (|7 - 0 - 5|) % 26 + 0 = 2 = c  (a = 0, c = 3, h = 7, k = 5 )			
		}
	}
}
int main()
{
	char Str_Nguon[SIZE], Str_Mahoa[SIZE], Str_Giaima[SIZE];
	int k; //Khoa k
	printf("Nhap chuoi:");
	gets(Str_Nguon);
	int len = strlen(Str_Nguon); //Do dai cua chuoi vua nhap
	printf("Nhap khoa k:");
	scanf("%d",&k);
	Khoitao(Str_Mahoa);
	Khoitao(Str_Giaima);
	
	printf("Chuoi so sau khi ma hoa la: "); //center -> hjsyjw
	Mahoa(Str_Nguon,Str_Mahoa,len,k);
	printf("%s",Str_Mahoa);
	
	printf("\nChuoi so sau khi giai ma la: "); //center -> dbiobm
	Giaima(Str_Nguon,Str_Giaima,len,k);
	printf("%s",Str_Giaima);	
}
