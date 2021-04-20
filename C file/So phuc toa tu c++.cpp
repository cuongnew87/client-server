#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class SP
{
	protected:
	int thuc,ao;
	public:
		friend istream &operator >> (istream &nhap, SP &a) 
		{
			cout<<"Nhap phan thuc:";
			nhap>>a.thuc;
			cout<<"Nhap phan ao:";
			nhap>>a.ao;
			return nhap;
		}
		friend ostream &operator << (ostream &xuat, SP a) 
		{
		xuat<<a.thuc<<"+"<<a.ao<<"i";
		return xuat;
		}
		SP operator+(SP y)
		{
			SP a;
			a.thuc = thuc + y.thuc;
			a.ao = ao + y.ao;
			return a;
		}
};
int main()
{
	SP a;
	SP b;
	cin>>a;
	cin>>b;
	cout<<"So phuc vua nhap la:"<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<"Tong 2 so phuc la:";
	SP kq = a.operator+(b);
	cout<<kq;
	
}
