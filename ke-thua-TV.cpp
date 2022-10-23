#include <iostream.h>
#include <iomanip.h>
class SP
{
	private:
		char ma[10];
		char ten[30];
		int nam;
	public:
		SP(char *ma="", char *ten="", int nam=0)
		{
			strcpy(this->ma,"");
			strcpy(this->ten,"");
			this->nam=nam;
		}
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma san pham: ";
			cin.getline(this->ma,10);
			cout<<"\tNhap ten san pham: ";
			cin.getline(this->ten,30);
			cout<<"\tNhap nam san xuat: ";
			cin>>this->nam;
		}	
		void xuat()
		{
			cout<<setw(20)<<right<<this->ma;
			cout<<setw(20)<<right<<this->ten;
			cout<<setw(20)<<right<<this->nam;
		}
};
class TV: public SP
{
	private:
		float d, r;// Chieu dai, rong
	public:
		TV(char *ma="", char *ten="", int nam=0, float d=0, float r=0):SP(ma, ten, nam)
		{
			this->d=d;
			this->r=r;
		}
		friend istream& operator >>(istream &is, TV &tv)
		{
			tv.SP::nhap();
			cout<<"\tNhap chieu dai ti vi: ";
			is>>tv.d;
			cout<<"\tNhap chieu rong ti vi: ";
			is>>tv.r;
			return is;
		}
		friend ostream& operator << (ostream &os, TV &tv)
		{
			tv.SP::xuat();
			cout<<setw(20)<<right<<tv.d;
			cout<<setw(20)<<right<<tv.r<<endl;
			return os;
		}
		float get_DienTich()
		{
			return d*r;
		}	
};
float sap_xep(TV tv[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(tv[i].get_DienTich() > tv[j].get_DienTich())
			{
				TV temp = tv[i];
					tv[i]=tv[j];
					tv[j]=temp;
			}
		}
	}
}
void tieude()
{
	cout<<setw(20)<<right<<"Ma";
	cout<<setw(20)<<right<<"Ten";
	cout<<setw(20)<<right<<"Nam san xuat";
	cout<<setw(20)<<right<<"Chieu dai";
	cout<<setw(20)<<right<<"Chieu rong"<<endl;
}
int main()
{
	TV *tv;
	int n;
	cout<<"\nNhap so luong ti vi: ";
	cin>>n;
	tv = new TV[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap san pham thu "<<i+1<<endl;
		cin>>tv[i];
	}
	tieude();
	for(int i=0; i<n; i++)
	{
		cout<<tv[i];
	}
	cout<<"\nSap xep tang dan theo dien tich ti vi: "<<endl;
	tieude();
	sap_xep(tv, n);
	for(int i=0; i<n; i++)
	{
		cout<<tv[i];
	}
	return 0;
}