#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct Hocsinh
{
	char ms[7];
	char ht[30];
	char qq[30];
	float td;
};
void nhap(Hocsinh a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap hoc sinh thu "<<i+1<<endl;
		cout<<"\tNhap ma so: ";
		fflush(stdin);
		cin.getline(a[i].ms,7);
		cout<<"\tNhap ho ten: ";
		cin.getline(a[i].ht, 30);
		cout<<"\tNhap que quan: ";
		cin.getline(a[i].qq, 30);
		cout<<"\tNhap tong diem: ";
		cin>>a[i].td;
	}
}
void tieude()
{
	cout<<setw(20)<<left<<"Ma so";
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"Que quan";
	cout<<setw(20)<<left<<"Tong diem"<<endl;
}

void xuat(Hocsinh a[], int n)
{
	tieude();
	for(int i=0; i<n ;i++)
	{
		cout<<setw(20)<<left<<a[i].ms
		<<setw(20)<<left<<a[i].ht
		<<setw(20)<<left<<a[i].qq
		<<setw(20)<<left<<a[i].td<<endl;
	}
}
void sap_xep_giam_dan(Hocsinh a[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[i].td < a[j].td)
			{
				Hocsinh temp=a[i];
				a[i]=a[j];
				a[j]=temp; 
			} 
		} 
	}
}
char hs_cung_que(Hocsinh a[], int n)
{
	tieude();
	for(int i=0; i<n; i++)
	{
		if(strcmp(a[i].qq,"nam dinh")==0)
		{
			cout<<setw(20)<<left<<a[i].ms
			<<setw(20)<<left<<a[i].ht
			<<setw(20)<<left<<a[i].qq
			<<setw(20)<<left<<a[i].td<<endl;
		}
	}
}
int main()
{
	Hocsinh a[100];
	int n;
	do{
		cout<<"\nNhap so luong hoc sinh: ";
		cin>>n;
		if(n<0)
		{
			cout<<"\nNhap lai n!!";
		}
	}while(n<0);
	
	nhap(a, n);
	cout<<"\nDanh sach hoc sinh: "<<endl;
	xuat(a, n);
	cout<<"\nDanh sach lop theo thu tu giam dan cua tong diem: "<<endl;
	sap_xep_giam_dan(a, n);
	xuat(a, n);
	cout<<"\nDanh sach sinh vien co que tai Nam Dinh: "<<endl;
	hs_cung_que(a, n);
	return 0;
}