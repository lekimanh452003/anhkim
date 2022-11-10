#include <iostream.h>
#include <iomanip.h>
#include <string.h>
using namespace std;
class MatHang
{
	protected:
		char ma[10];//Ma
		char ten[30];//ten
		float dg;//don gia
	public:
		MatHang(char *ma="",char* ten="",float dg=0)
		{
			strcpy(this->ma,ma);
			strcpy(this->ten,ten);
			this->dg=dg;
		}	
		~MatHang(){};
		friend istream& operator >> (istream& is, MatHang &a)
		{
			fflush(stdin);
			cout<<"\tNhap ma mat hang: ";is.getline(a.ma,10);
			cout<<"\tNhap ten mat hang: ";is.getline(a.ten,30);	
			cout<<"\tNhap don gia: ";is>>a.dg;
			return is;
		}
		friend ostream& operator << (ostream& os, MatHang &a)
		{
			fflush(stdin);
			cout<<setw(15)<<left<<a.ma;
			cout<<setw(15)<<left<<a.ten;
			cout<<setw(15)<<left<<a.dg;
			return os;
		}
};
class BanhKeo: public MatHang
{
	protected:
		int sl;//so luong
		char nsx[30];//noi san xuat
		long int tt;//thanh tien
	public:
		BanhKeo(char *ma="",char* ten="",float dg=0, int sl=0, char* nsx="", long int tt=0)
		:MatHang(ma,ten,dg)
		{
			this->sl=sl;
			strcpy(this->nsx,nsx);
			this->tt=tt;
		}
		~BanhKeo(){};
		long int thanh_tien()
		{
			this->tt=(this->dg)*(this->sl);
			return tt;
		}
		friend istream& operator >> (istream& is, BanhKeo &a)
		{
			is>>(MatHang&)a;
			cout<<"\tNhap so luong: ";is>>a.sl;
			fflush(stdin);
			cout<<"\tNhap noi san xuat: ";is.getline(a.nsx,30);
			return is;
		}
		friend ostream& operator << (ostream& os, BanhKeo &a)
		{
			os<<(MatHang&)a;
			fflush(stdin);
			cout<<setw(15)<<left<<a.sl;
			cout<<setw(15)<<left<<a.nsx;
			cout<<setw(15)<<left<<a.tt<<endl;
			return os;
		}
		friend bool operator >(BanhKeo &a1, BanhKeo &a2)
		{
			return (a1.dg > a2.dg);
		}
		
		bool operator == (BanhKeo &a1)
		{
			return (strcmp(this->get_nsx(),"Ha Noi")==0);
			
		}
		friend long int operator +(BanhKeo &a1, BanhKeo &a2)
		{
			return (a1.tt + a2.tt);
		}
		char* get_nsx()
		{
			return (this->nsx);
		}
		float get_dg()
		{
			return this->dg;
		}
};
void tieude()
{
	cout<<setw(15)<<left<<"Ma";
	cout<<setw(15)<<left<<"Ten";
	cout<<setw(15)<<left<<"Don gia";
	cout<<setw(15)<<left<<"So luong";
	cout<<setw(15)<<left<<"Noi SX";
	cout<<setw(15)<<left<<"Thanh tien"<<endl;
}
float tim_max(BanhKeo a[], int n)
{
	float max=a[0].get_dg(); 
	for(int i=0; i<=n; i++)
	{
		if(a[i].get_dg()>max)
		{
			max=a[i].get_dg();
		}
	}
	return max;
}
int main()
{
	BanhKeo *a;
	int n;
	cout<<"\nNhap so luong banh keo: ";cin>>n;
	a = new BanhKeo[n];
	for(int i=0; i<n;i++)
	{
		cout<<"\nNhap banh keo thu "<<i+1<<endl;
		cin>>a[i];
	}
	cout<<"\nXuat danh sach banh keo: "<<endl;
	tieude();
	for(int i=0; i<n;i++)
	{
		cout<<a[i];
	}
	cout<<"\nBanh keo co don gia lon nhat: "<<tim_max(a,n)<<endl;
	
	long int s=0;
	for(int i=0; i<n; i++)
	{
		s=s+a[i].thanh_tien();	
	}
	cout<<"\nTong thanh tien cua danh sach banh keo: "<<s<<endl;
	cout<<"\nDanh sach banh keo san xuat o Ha Noi: "<<endl;
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].get_nsx(),"Ha Noi")==0)
		{
			cout<<a[i];
		}
	}
	return 0;
}