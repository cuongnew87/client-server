#include<iostream>
#include<math.h>
//VD: PAY ,k={17, 17, 5, 21, 18, 21 ,2 ,2 ,19}
using namespace std;
float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];
void getKeyMatrix() //Nhap ma tran va ky tu
{ 
   int i, j;
   char mes[3];
   cout<<"Nhap ma tran 3x3:\n";
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++)
    {
   	    cout<<"a"<<"["<<i<<"]"<<"["<<j<<"]"<<"=";
        cin>>a[i][j];
        m[i][j] = a[i][j];
   }
   cout<<"\nNhap 3 ky tu: ";
   cin>>mes;
   for(i = 0; i < 3; i++)
   msg[i][0] = mes[i] - 65;
}
void encrypt() //Ma hoa
{ 
   int i, j, k;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   en[i][j] = en[i][j] + a[i][k] * msg[k][j];
   cout<<"\nKy tu sau khi ma hoa: ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(en[i][0], 26) + 65); //fmod(num,26) = num mod 26 
}
void inversematrix() { //Tim ma tran nghich dao
   int i, j, k;
   float p, q;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) 
   {
        if(i == j)
            b[i][j]=1;
        else
            b[i][j]=0;
   }
   for(k = 0; k < 3; k++)
    {
      for(i = 0; i < 3; i++) 
	   {
            p = m[i][k];
            q = m[k][k];
            for(j = 0; j < 3; j++) 
			{
                if(i != k) 
				{
                    m[i][j] = m[i][j]*q - p*m[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
       }
   }
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++)
   b[i][j] = b[i][j] / m[i][i];
   cout<<"\n\nMa tran nghich dao:\n";
    for(i = 0; i < 3; i++)
	{
      for(j = 0; j < 3; j++)
      cout<<b[i][j]<<" ";
      cout<<"\n";
   }
}
void decrypt()  //Giai ma
{ 
   int i, j, k;
   inversematrix();
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   de[i][j] = de[i][j] + b[i][k] * en[k][j];
   cout<<"\nKy tu sau khi giai ma: ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(de[i][0], 26) + 65); 
   cout<<"\n";
}
int main() 
{
   getKeyMatrix();
   encrypt();
   decrypt();
}
