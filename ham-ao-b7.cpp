#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class BenhNhan
{
	private:
		char ma[10];//ma ho so
		char ht[30];//ho ten
		char cd[50];//chuan doan benh
		int ns;//ngay sinh
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma ho so: ";cin.getline(this->ma,10);
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);
			cout<<"\tNhap chuan doan benh: ";cin.getline(this->cd,50);
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
			return ns;
		}
};
class NoiTru:public BenhNhan
{
	private:
		char tk[20];//Ten khoa
		int nnv, nrv;//Ngay nhap vien, ngay ra vien
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
			cout<<setw(20)<<left<<this->sg<<endl;
		}
		int loaihoso()
		{
			return 0;
		}
		
};
class NgoaiTru: public BenhNhan
{
	private:
		char noi[30];//noi chuyen
		int nc;//ngay chuyen
	public:
		void nhap()
		{
			BenhNhan::nhap();
			fflush(stdin);
			cout<<"\tNhap noi chuyen: ";cin.getline(this->noi,30);
			cout<<"\tNhap ngay chuyen: ";cin>>this->nc;
		}
		void xuat()
		{
			BenhNhan::xuat();
			cout<<setw(20)<<left<<this->noi;
			cout<<setw(20)<<left<<this->nc<<endl;
		}
		int loaihoso()
		{
			return 1;
		}
	
};
int main()
{
	BenhNhan *bn[100];
	int n,i,chon;
	cout<<"\nNhap so ho so benh nhan: ";cin>>n;
	for(int i=0; i<n;i++)
	{
		cout<<"\nHo so thu "<<i+1<<endl;
		cout<<"\nBenh nhan noi tru(1), Benh nhan ngoai tru(2): ";
		cin>>chon;
		if(chon==1){
			bn[i]=new NoiTru();
		}else if(chon==2)
		{
			bn[i]=new NgoaiTru();
		}
		bn[i]->nhap();
	}
	cout<<"\nDanh sach benh nhan: "<<endl;
	for(int i=0; i<n; i++)
	{
		bn[i]->xuat();
	}
	int x;
	cout<<"\nx= ";cin>>x;
	
	int dem=0, dem2=0;
	for(int i=0; i<n;i++)
		{
			if(bn[i]->get_ns() > x)
			{
				if(bn[i]->loaihoso()==0) dem++;
				if(bn[i]->loaihoso()==1) dem2++;
			}
		}	
	
	cout<<"\nSo luong ho so noi tru co ngay sinh >x la: "<<dem<<endl;
	cout<<"\nSo luong ho so ngoai tru co ngay sinh >x la: "<<dem2<<endl;
	return 0;
}