#include <iostream.h>
template <class T>
T nhapmang(T a[], int n)
{
	for(int i=0; i<n;i++)
	{
		cout<<"\nNhap phan tu thu "<<i+1<<endl;
		cin>>a[i];
	}	
}
template <class T>
T xuatmang(T a[], int n)
{
	cout<<"\nXuat mang: "<<endl;
	for(int i=0; i<n;i++)
	{
		cout<<a[i]<<"	";
	}
	cout<<endl;
}
template <class T>
T Max(T a[], int n)
{
	T max=a[0];
	for(int i=0; i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

template <class T>
char *Max_kitu(char *c[], int n)
{
	char* m=c[0];
	for(int i=0; i<n;i++)
	{
		if(strcmp(c[i],m)>0)
		{
			m=c[i];
		}
	}
	return m;
}
template <class T>
T tong(T a[], int n)
{
	T s=0;
	for(int i=0; i<n; i++)
	{
		s=s+a[i];
	}
	return s;
}
class PS
{
	private:
		float a;//tu so
		float b;//mau so
	public:
		PS(float a=1.2, float b=1.0)
		{
			this->a=a;
			this->b=b;
		}
		~PS(){};
		void nhap()
		{
			cout<<"\tNhap tu so = "; cin>>this->a;
			cout<<"\tNhap mau so = "; cin>>this->b;
		}
		void xuat()
		{
			cout<<this->a<<"/"<<this->b<<"		";
		}
		friend istream& operator >>(istream &is,PS &ps)
		{
			cout<<"\nNhap tu so: ";is>>ps.a;
			cout<<"\nNhap mau so: ";is>>ps.b;
			return is;
		}		
		friend ostream& operator <<(ostream &os,PS &ps)
		{
			cout<<ps.a<<"/"<<ps.b<<"		";
			return os;
		}	
		
		friend bool operator > (PS &ps1, PS &ps2)
		{
			return ps1.a/ps1.b > ps2.a/ps2.b;
		
		}
		PS operator = (float x)
		{
			this->a=x;
			this->b=1;
			return *this;
		}
		friend PS operator + (PS &ps1, PS &ps2)
		{
			PS kq;
			kq.a=ps1.a*ps2.b+ ps2.a*ps1.b;
			kq.b=ps1.b*ps2.b;
			return kq;	
		}
};

int main()
{
	int m;
	cout<<"\nNhap mang so thuc: ";cin>>m;
	float b[m];
	nhapmang(b,m);
	xuatmang(b,m);
	cout<<"\nSo thuc lon nhat = "<<Max(b,m)<<endl;
	cout<<"\nTong mang; "<<tong(b,m)<<endl;
	int n;
	cout << "\nNhap So luong Mang Phan So: ";
	cin >> n;
	PS *a;
	a = new PS[n];
	nhapmang(a,n);
	xuatmang(a,n);
	cout << "\nPhan So Lon Nhat la: ";
	Max(a,n).xuat();
	cout<<"\nTong PS= ";
	tong(a,n).xuat();
	cout << endl;
	char *s1;
	return 0;
}