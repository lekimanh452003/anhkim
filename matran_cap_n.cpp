#include <iostream.h>
#include <iomanip.h> 
#define max 50
void nhap(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]= ";
			cin>>a[i][j];
		}
		cout<<endl;
	}	
}
void xuat(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<setw(6)<<a[i][j];
			
		}
		cout<<endl;
	}	
}
int min(int a[max][max], int n)
{
	int min=a[0][n=1];
	for(int i=0; i<n; i++)
	{
		if(a[i][n-i-1]<min){
			min=a[i][n-i-1];
		}
	}
	return min;
}
float avg(int a[max][max],int n)
{
	int s=0; int d=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[i][j]%7==4)
			{
				s=s+a[i][j];
				d++;
			}
		}
	}
	return (float)s/d;
}
int main()
{
	int a[max][max];
	int n;
	cout<<"\nNhap cap ma tran n= ";cin>>n;
	nhap(a,n);
	cout<<"\nXuat: "<<endl;
	xuat(a,n);
	cout<<"\nSo min tren duong cheo phu= "<<min(a,n)<<endl;
	cout<<"\nTBC= "<<avg(a,n)<<endl;
	return 0;
}