#include <iostream.h>
#include <iomanip.h>
struct HangHoa
{
	char mh[8]; // Ma hang
	char th[30]; //Ten hang
	int sl; // So luong
	float dg; // Don gia
	float tt; //Thanh tien		
};
void thanhtien(HangHoa a[], int n)
{
	for(int i=0; i<n; i++)
	{
		a[i].tt=a[i].sl*a[i].dg;
	}
}
void tieude()
{
	cout<<setw(20)<<left<<"Ma hang";
	cout<<setw(20)<<left<<"Ten hang";
	cout<<setw(20)<<left<<"So luong";
	cout<<setw(20)<<left<<"Don gia";
	cout<<setw(20)<<left<<"Thanh tien"<<endl;
}
void nhap(HangHoa a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap hang hoa thu "<<i+1<<endl;
		cout<<"\tNhap ma hang: ";
		fflush(stdin);
		cin.getline(a[i].mh, 8);
		cout<<"\tNhap ten hang: ";
		cin.getline(a[i].th, 30);
		cout<<"\tNhap so luong hang: ";
		cin>> a[i].sl;
		cout<<"\tNhap don gia: ";
		cin>> a[i].dg;
	}
}
void xuat(HangHoa a[], int n)
{
	tieude();
	for(int i=0; i<n; i++)
	{
		cout<<setw(20)<<left<<a[i].mh
			<<setw(20)<<left<<a[i].th
			<<setw(20)<<left<<a[i].sl
			<<setw(20)<<left<<a[i].dg
			<<setw(20)<<left<<a[i].tt<<endl;
	}
}
void dongia(HangHoa a[], int n) //Hien thi nhung mat hang co don gia lon hon 50
{
	for(int i=0; i<n; i++)
	{
		if(a[i].dg> 50)
		{
			cout<<setw(20)<<left<<a[i].mh
				<<setw(20)<<left<<a[i].th
				<<setw(20)<<left<<a[i].sl
				<<setw(20)<<left<<a[i].dg
				<<setw(20)<<left<<a[i].tt<<endl;
		}
	}
}
int main()
{
	HangHoa a[50];
	int n;
	cout<<"\nNhap so luong hang hoa: "<<endl;
	cin>>n;
	nhap(a, n);
	cout<<"\nDanh sach hang hoa: "<<endl;
	thanhtien(a, n);
	xuat(a, n);
	cout<<"\nThong tin mat hang co don gia lon hon 50: "<<endl;
	tieude();
	dongia(a, n);
	return 0;
}