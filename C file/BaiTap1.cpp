#include <iostream> 
#include <iomanip> 
#include <stdio.h>
#include <string.h>
using namespace std;
class Nguoi
{
	private:
	char ten[100],que[100];
	int tuoi;
	public:
		char* getTen()
		{
			return ten;
		}
		void setTuoi(int t)
		{
			tuoi = t;
		}
		void setTen(char t[100])
		{
			strcpy(ten,t);
		}
		Nguoi()//ham tao/thiet lap/cau tu/constructor
		{
			strcpy(ten," ");
			strcpy(que," ");
			tuoi = 0;
		}
		Nguoi(char ten1[100],char que1[100], int tuoi1 )//ham tao/thiet lap/cau tu/constructor
		{
			strcpy(ten,ten1);
			strcpy(que,que1);
			tuoi = tuoi1;
		}
		friend ostream& operator <<(ostream &o, Nguoi obj)
		{
			o<<setw(15)<<obj.ten<<setw(5)<<obj.que<<setw(5)<<obj.tuoi<<endl;
		}
		friend istream& operator >>(istream &i, Nguoi &obj)
		{
			cout<<"Nhap ten:";
			fflush(stdin);
			gets(obj.ten);
			cout<<"Nhap que:";
			fflush(stdin);
			gets(obj.que);
			cout<<"Nhap tuoi:";
			i>>obj.tuoi;
		}
		void nhap()
		{
			cout<<"Nhap ten:";
			fflush(stdin);
			gets(ten);
			cout<<"Nhap que:";
			fflush(stdin);
			gets(que);
			cout<<"Nhap tuoi:";
			cin>>tuoi;
		}
		void in()
		{	
			cout<<setw(15)<<ten<<setw(5)<<que<<setw(5)<<tuoi;
		}
};

class SV : public Nguoi
{
	char ma[100];
	float T,L, A;
	public:
		SV():Nguoi()//ham tao/thiet lap/cau tu/constructor
		{
			strcpy(ma," ");
			T = 0;
			L = 0;
			A = 0;
		}
		SV(char ma1[100],float T1, float L1, float A1,char ten1[100],char que1[100], int tuoi1 ):Nguoi(ten1,que1,tuoi1)
		{
			strcpy(ma," ");
			T = T1;
			L = L1;
			A = A1;
		}
		friend ostream& operator <<(ostream &o, SV obj)
		{
			Nguoi c = obj;
			o<<c;
			o<<setw(10)<<obj.ma<<setw(5)<<obj.T<<setw(5)<<obj.L<<setw(5)<<obj.A;
			//o<<setw(15)<<obj.ten<<setw(5)<<obj.que<<setw(5)<<obj.tuoi<<endl;
		}
		friend istream& operator >>(istream &i, SV &obj)
		{
			Nguoi *c = &obj;
			i>>*c;
			cout<<"Nhap ma:";
			fflush(stdin);
			gets(obj.ma);
			cout<<"Nhap toan:";
			i>>obj.T;
			cout<<"Nhap ly:";
			i>>obj.L;
			cout<<"Nhap anh:";
			i>>obj.A;
		}
		void nhapSV()
		{
			nhap();
			//viet them
		}
		void inSV()
		{
			in();	
			//viet them
		}
};

int main()
{
	SV a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	a[0].setTuoi(19);//a[0].tuoi = 19;
	//sap xep
	for(int i=0; i< n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(a[i].getTen() , a[j].getTen())> 0)
			{
				SV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	

}
