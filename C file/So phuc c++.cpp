#include<iostream>
#include<iomanip>
using namespace std;
class sophuc
{
	private:
	int thuc,ao;
	public:
		void nhap();
		void xuat();
		void cong(sophuc b);
		void tru(sophuc b);
		void nhan(sophuc a,sophuc b);
};
void sophuc ::nhap()
{
	cout<<"Nhap phan thuc:";
	cin>>thuc;
	cout<<"Nhap phan ao:";
	cin>>ao;
}
void sophuc ::xuat()
{
	cout<<thuc<<" + "<<ao<<"i";
}
void sophuc ::cong(sophuc b)
{
	thuc = thuc + b.thuc;
	ao = ao + b.ao;
}
void sophuc ::tru(sophuc b)
{
	thuc = thuc - b.thuc;
	ao = ao - b.ao;
}
void sophuc ::nhan(sophuc a, sophuc b)
{ 
	thuc = a.thuc * b.thuc - a.ao * b.ao;
	ao = a.thuc * b.ao + b.thuc * a.ao;
}
int main()
{
	sophuc a,b,c;
	a.nhap();
	b.nhap();
	cout<<"So phuc vua nhap la:"<<endl;
	a.xuat();
	cout<<endl;
	b.xuat();
	cout<<endl;
	//Tong 2 so phuc
	c = a;
	c.cong(b);
	cout<<"Tong 2 so phuc la:";
	c.xuat();
	//Hieu 2 so phuc
	c = a;
	c.tru(b);
	cout<<endl;
	cout<<"Hieu 2 so phuc la:";
	c.xuat();
	//Tich 2 so phuc
	c = a;
	c.nhan(a,b);
	cout<<endl;
	cout<<"Tich 2 so phuc la:";
	c.xuat();
}
