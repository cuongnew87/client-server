#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class canbo
{
	char ma[10],ten[20],que[20];
	int tuoi,hsl,phucap,luong;
	public:
			canbo()
		{
			strcpy(ten,"Nguyen Van A");
			strcpy(ma,"M01");
			strcpy(que,"");
			tuoi = 0;
			hsl = 0;
			phucap = 0;
		}
			canbo(char ma[10],char ten[20],char que[20],int tuoi,float hsl,int phucap,int luong)
		{
			strcpy(ten,ten);
			strcpy(ma,ma);
			strcpy(que,que);
			tuoi = tuoi;
			hsl = hsl;
			phucap = phucap;
		}
		void nhap()
		{
			cout<<"Nhap ma can bo:"; 	fflush(stdin);
			gets(ma);
			cout<<"Ten can bo:";	fflush(stdin);
			gets(ten);
			cout<<"Que quan:";	fflush(stdin);
			gets(que);
			cout<<"Nhap tuoi:";
			cin>>tuoi;
			cout<<"He so luong:";
			cin>>hsl;
			cout<<"Phu cap:";
			cin>>phucap;
		}
		void xuat()
		{
			cout<<setw(10)<<ma<<setw(10)<<ten<<setw(10)<<que<<setw(10)<<tuoi<<setw(10)<<hsl<<setw(10)<<phucap<<endl;
		}
		void tinhluong()
		{
			luong = 1500000 * hsl + phucap;
		}
		void xuatluong()
		{
			cout<<luong<<endl;
		}
	};
	class DS
	{
		canbo a[100];
		int n;
		public:
		void nhapN()
		{
			cin>>n;
		}
		void nhap()
		{
			for(int i=0;i<n;i++)
			a[i].nhap();
		}
		void xuat()
		{
				cout<<setw(10)<<"Ma can bo"<<setw(10)<<"Ten can bo"<<setw(10)<<"Que quan"<<setw(10)<<"Tuoi"<<setw(10)<<"He so luong"<<setw(10)<<"Phu cap"<<endl;
				for(int i=0;i<n;i++)
				{
					a[i].xuat();
				}
		}
		void tinhluong()
		{
			for(int i=0;i<n;i++)
				{
					a[i].tinhluong();
				}
		}
	void xuatluong()
	{
		
		for(int i=0;i<n;i++)
			a[i].xuatluong();
	}
	void max()
	{
		
	}
};
int main()
{
	DS a,b;
	int n;
	cout<<"Nhap so luong can bo:";
	a.nhapN();
	a.nhap();
	a.xuat();
	cout<<"Luong cua can bo la:"<<endl;
	a.tinhluong();
	a.xuatluong();
}
