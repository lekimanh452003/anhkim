#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class BenhNhan
{
	protected:
		char ma[10];//Ma ho so
		char ht[30];//Ho ten
		char cd[50];//Chuan doan benh
		int ns;//Ngay sinh
	public:
	
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma ho so: ";cin.getline(this->ma,10);
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);
			cout<<"\tChuan doan benh: ";cin.getline(this->cd, 50);
			cout<<"\tNhap ngay sinh: ";cin>>this->ns;	
		}
		virtual void xuat()
		{
			cout<<setw(20)<<left<<this->ma;
			cout<<setw(20)<<left<<this->ht;
			cout<<setw(20)<<left<<this->cd;
			cout<<setw(20)<<left<<this->ns;
		}
		~BenhNhan(){};
		virtual int loaihoso()=0;	
		int get_ns()
		{
			int x;
			cout<<"x= ";cin>>x;
			if(ns > x)
			{
				return true;
			}else{
				return false;
			}
		}
};
class NoiTru:  public BenhNhan
{
	protected:
		
		char tk[20];//Ten khoa
		int nnv, nrv; //ngay nhap vien, ngay ra vien
		int sg;//So giuong
	public:
		void nhap()
		{
			BenhNhan::nhap();
			fflush(stdin);
			cout<<"\tNhap ten khoa: ";cin.getline(this->tk,20);
			cout<<"\tNhap ngay nhap vien: ";cin>>this->nnv;
			cout<<"\tNhap ngay ra vien: ";cin>>this->nrv;
			cout<<"\tNhap so giuong: ";cin>>this->sg;
		}	
		void xuat()
		{
			BenhNhan::xuat();
			cout<<setw(20)<<left<<this->tk;
			cout<<setw(20)<<left<<this->nnv;
			cout<<setw(20)<<left<<this->nrv;
			cout<<setw(20)<<left<<this->sg<<endl;;
		}	
		int loaihoso()
		{
			return 0;
		}
};
class NgoaiTru: public BenhNhan
{
	protected:
		char noi[30];//Noi chuyen
		int nc;//Ngay chuyen
	public:
		void nhap()
		{
			BenhNhan::nhap();	
			fflush(stdin);
			cout<<"\tNhap noi chuyen : ";cin.getline(this->noi,30);
			cout<<"\tNhap ngay chuyen: ";cin>>this->nc;
		}
		void xuat()
		{
			BenhNhan::xuat();
			cout<<setw(20)<<left<<this->noi;
			cout<<setw(20)<<left<<this->nc<<endl;;
		}
		int loaihoso()
		{
			return 1;
		}
};

int main()
{
	
	BenhNhan *bn[100];	
	int n,i, chon;
	cout<<"\nNhap so ho so benh nhan: ";cin>>n;
	for(i=0; i<n; i++)
	{
		cout<<"\nHo so thu "<<i+1<<endl;	
		cout<<"\nBenh nhan noi tru(1), Benh nhan ngoai tru(2): ";
		cin>>chon;		
		
		if(chon==1)
		{
			bn[i] = new NoiTru();
		}else if(chon==2)
		{
			bn[i]=new NgoaiTru();
		}
		bn[i]->nhap();
	}
		
		
	cout << "Danh sach benh nhan:" << endl;
 	for (int i = 0; i < n; i++)
  	{
  		bn[i]->xuat(); 
    }

	int dem=0;
	for(int i=0; i<n; i++)
	{
		if(bn[i]->loaihoso()==0)
		{
			dem++;
		}
	}
	cout<<"\nSo luong ho so noi tru la "<<dem<<endl;
	cout<<"\nSo luong ho so ngoai tru la "<<n-dem<<endl;
	return 0;
}