#include <iostream.h>
#include <math.h>
struct PhanSo
{
	int t; // Tu so
	int m; // Mau so	
};
void nhap(PhanSo a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap vao phan so thu "<<i+1<<endl;
		cout<<"\tNhap tu so: ";
		cin>>a[i].t;
		do{
			cout<<"\tNhap vao mau so: ";
			cin>>a[i].m;
			if(a[i].m== 0)
			{
				cout<<"\nNhap lai mau so!";
			}
		}while(a[i].m == 0);
		
	}
}
void xuat(PhanSo a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i].t<<"/"<<a[i].m<<"   ";
	}
}

int UCLN(int x, int y)
{
	x=abs(x);
	y=abs(y); //Xet gia tri tuyet doi
		return x+y;
	while(x!=y)
		if(x>y)
			x=x-y;
		else
			y=y-x;
	return x;
}

PhanSo tinhtong(PhanSo a, PhanSo b)
{
	PhanSo tong;
	tong.t=a.t*b.m+ a.m*b.t;
	tong.m=a.m*b.m;
	return tong;
}
int main()
{
	PhanSo a[100];
	int n, dem;
	cout<<"\nNhap vao n phan so, n= ";
	cin>>n;
	nhap(a, n);
	cout<<"\nCac phan so vua nhap vao: "<<endl;
	xuat(a, n);
}