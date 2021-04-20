#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
using namespace std;
class CB{
	char hoten[20];
	char diachi[20];
	char gioitinh[20];
	char ns[12];
	
	public:
		~CB()
		{
			cout<<"\nHuy CB";
		}
		virtual void nhap()
		{
			cout<<"nhap vao ho ten :";
			fflush(stdin);
			gets(hoten);
			cout<<"nhap vao dia chi :";
			fflush(stdin);
			gets(diachi);
			cout<<"nhap vao gioi tinh :";
			fflush(stdin);
			gets(gioitinh);
			cout<<"nhap vao nam sinh :";
			fflush(stdin);
			gets(ns);
		}
		virtual void xuat()
		{
			cout<<setw(15)<<hoten<<setw(6)<<diachi<<setw(4)<<gioitinh<<setw(8)<<ns;
		}
};

class CN :public CB{
	int bac;
	
	public:
		CN()
		{
			
		}
		~CN()
		{
			cout<<"Huy cong nhan";
		}
		void nhap()
		{
			CB::nhap();
			cout<<"Nhap bac luong :";
			cin>>bac;
		}
		void xuat()
		{
			CB::xuat();
			cout<<setw(15)<<bac<<"/7";
		}
};

class KS :public CB{
	char nganh[20];
	
	public:
		void nhap()
		{
			CB::nhap();
			cout<<"nhap vao nganh :";
			fflush(stdin);
			gets(nganh);
		}
		void xuat()
		{
			CB::xuat();
			cout<<setw(15)<<nganh;
		}
};

class NV :public CB{
	char congviec[20];
	
	public:
		void nhap()
		{
			CB::nhap();
			cout<<"nhap vao cong viec :";
			fflush(stdin);
			gets(congviec);
		}
		void xuat()
		{
			CB::xuat();
			cout<<setw(15)<<congviec;
		}
};

int main()
{
	
	
	int n;
	cout<<"Nhap vao n can bo:";
	cin>>n;
	CB *A[n] ;
	//A=new CB*[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Moi ban lua chon:"<<endl;
		cout<<"0. Ky Su"<<endl;
		cout<<"1. Cong Nhan"<<endl;
		cout<<"2. Nhan Vien"<<endl;
		int chon;
		cin>>chon;
		
		if(chon == 0)
		{
			//nhap vao 1 ky su
			cout<<"Nhap thong tin Ky Su"<<endl;
			A[i] = new KS();
			A[i]->nhap();
		}
		else if(chon == 1)
		{
			//nhap vao 1 cong nhan
			cout<<"Nhap thong tin cong nhan"<<endl;
			A[i] = new CN();
			A[i]->nhap();
		}
		else
		{
			cout<<"Nhap thong tin nhan vien"<<endl;
			A[i] = new NV();
			A[i]->nhap();
		}
		
	}
	for(int i=0;i<n;i++)
	{
		A[i]->xuat();
		delete A[i];
	}
	
}
