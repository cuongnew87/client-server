#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Media
{
	protected:
	char ten[100];
	float gia;
	public:
		Media() //Ham khoi tao
		{
			strcpy(ten,"A");  // Ten sinh vien = A
			gia=0;
		}
		~Media() //Ham huy
		{
		}
		void nhap()
		{
		cout<<"Nhap ten media:"; fflush(stdin); gets(ten);
		cout<<"Nhap gia:"; cin>>gia;
		}
		void xuat()
		{
			cout<<ten<<setw(10)<<gia<<endl; // setw(10) = Khoang cach giua cac chu la 10 don vi
		}
};
class Video
{
	Media a[100];
	int n;
	int thoigian;
	public:
	void nhapN() //Nhap so luong sinh vien
	{
	cout<<"Nhap so luong:";
	cin>>n;
	}
	void nhap()
	{
	for(int i=0;i<n;i++)
	{
		a[i].nhap();
	}
}
	void xuat()
	{
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
}
};
int main()
{
	int n;
	Video ds;
	ds.nhapN();
	ds.nhap();
	ds.xuat();	
}
