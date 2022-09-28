#include <iostream.h>
//Ham nhap mang
void nhapmang(int a[], int n)
{

	for(int i=0; i<n; i++)
	{
		cout<<" a["<<i<<"]= "<<"  ";
		cin>>a[i];
	}
}
void xuatmang(int a[], int n) //Ham xuat mang
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"  ";
	}
}
void hoanvi(int &a, int &b)
{
	int temp=a;// Hoan vi 2 gia tri trong mang
		a=b;
		b=temp;
}
void daonguocmang(int a[], int n)
{
	int j=n-1;
	for(int i=0; i<n/2; i++)
	{
		hoanvi(a[i],a[j]);
		j--;
	}
}
int timkiem(int a[], int n, int x)
{
	for(int i=0; i<n; i++)
	{
		if(x==a[i])
		{
			cout<<"\nPhan tu "<<x<<" nam o vi tri "<<i+1<<endl;
			break;
		}
	}
}
void sapxeptangdan(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[i] > a[j])
			{
				hoanvi(a[i],a[j]);
			}
		}
	}
}
int main() //Ham chinh
{ 
	int a[100], n;
	cout<<"\nNhap vao so luong phan tu mang: ";
	cin>>n;
	nhapmang(a, n);
	cout<<"\nXuat mang: "<<endl;
	xuatmang(a, n);
	cout<<"\nDao nguoc mang: "<<endl;
	daonguocmang(a, n);
	xuatmang(a, n);
	int x;
	cout<<"\nNhap gia tri x can tim, x = ";
	cin>>x;
	timkiem(a, n, x);
	cout<<"\nSap xep tang dan: ";
	sapxeptangdan(a, n);
	xuatmang(a, n);
	return 0;
}

