#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cmath>
#include<windows.h>
using namespace std;

const int size = 5;   // kich thuoc cua ban co
int Board[size + 1][size + 1];
int X[8] = { 2, 2, 1, -1, -2, -2, -1, 1 }; //Toa do ma quan ma co the di chuyen
int Y[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };
bool done = FALSE;        // kieu du lieu dung hoac sai
void gotoxy(int x, int y)   // xay dung ham toa do gotoxy trong thu vien windows.h
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
};
void Move(int x, int y, int n)
{   // Xay dung ham buoc di
	int u, v;
	for(int i = 0; i <= 8; i++)
	{
		u = x + X[i];   // Tao mot vi tri x moi
		v = y + Y[i];   // Tao mot vi tri y moi
		if(0 < u && u <= size && 0 < v && v <= size && Board[u][v] == 0)
		// Neu khong tim duoc se tra lai vi tri ban dau
		{
			Board[u][v] = n;
			gotoxy(5 + u * 4, 3 + v * 2); //gotoxy(13,9)
			Sleep(100); // Thoi gian cho khi con ma di chuyen toi buoc tiep theo
			cout<<n;    
			gotoxy(6 + n * 3, 10 + size * 2); //gotoxy(18,20)
			cout<<n;
			if(n == size * size)
			{  
				done = TRUE;   
				putchar(8);     
				
			}
		    if(done == FALSE)  // Quan ma chua di het ban co
		    	Move(u, v, n + 1);
		    if(done == TRUE )
				return ;
		    Board[u][v] = 0;
			gotoxy(5 + u * 4, 3 + v * 2); //gotoxy(13,9)
		    Sleep(100);  
			cout<<"   ";
		    gotoxy(6 + n * 3, 10 + size * 2);
		    cout<<"   ";
		}
	}
};
int main()
{
	int x, y;
	cout<<"\n Moi ban nhap vi tri xuat phat  x - y : ";  cin>>x>>y;
	if(x < 1 || x > size)  // x chon lon hon 1 va nho hon kich thuoc ban co
		x = 1;
	if(y < 1 || y > size)  // y chon lon hon 1 va nho hon kich thuoc ban co
		y = 1;
	gotoxy(4,4);  // Vi tri hien thi buoc di cua quan ma
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	gotoxy(0, 10 + size * 2);
	cout<<"Buoc di :";
	Move(x - 2, y - 1, 1);  
	gotoxy(0, 5 + size * 2);
	if(done == TRUE)
		cout<<"Thanh cong !";
	else
		cout<<"Khong co loi giai.";  // Neu khong tim duoc xe thong bao
	return 1;
};

