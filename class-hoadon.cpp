#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct NgayThang
{
	int dd, mm, yyyy;// Ngay, thang, nam	
};
class HoaDon
{
	private:
		char mvt[10]; //Ma vat tu
		char t[30]; //Ten vat tu
		char lp[6]; //Loai phieu
		NgayThang nt; // Ngay lap
		float kl; // Khoi luong
		int dg; //Don gia (nghin)
		int tt; //Thanh tien
	public:
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma vat tu: "; cin.getline(this->mvt, 10 );
			cout<<"\tNhap ten vat tu: ";cin.getline(this->t, 30);
			cout<<"\tNhap loai phieu: "; cin.getline(this->lp, 6);
			cout<<"\tNhap ngay: "; cin>>this->nt.dd;
			cout<<"\tNhap thang: "; cin>>this->nt.mm;
			cout<<"\tNhap nam: "; cin>>this->nt.yyyy;
			cout<<"\tNhap khoi luong: "; cin>>this->kl;
			cout<<"\tNhap don gia: "; cin>>this->dg;	
		}
		void xuat() 
		{
			cout<<setw(15)<<left<<this->mvt;
			cout<<setw(30)<<left<<this->t;
			cout<<setw(15)<<left<<this->lp;
			cout<<setw(15)<<left<<this->kl;
			cout<<setw(15)<<left<<this->dg;
			cout<<setw(15)<<left<<this->tt<<endl;
		}
		bool kt() //Ham kiem tra phieu nhap hay xuat
		{
			if(strcmp(lp, "nhap")==0)
			{
				return true;
			}else{
				return false;
			}
		}
		friend int thanh_tien(HoaDon hd[], int n); 
		friend int tong_thanh_tien(HoaDon hd[], int n);
		friend int sapxep(HoaDon hd[], int n);
		~HoaDon(){};
};
void tieude()
{
	cout<<setw(15)<<left<<"Ma vat tu";
	cout<<setw(30)<<left<<"Ten";
	cout<<setw(15)<<left<<"Loai phieu";
	cout<<setw(15)<<left<<"Khoi luong";
	cout<<setw(15)<<left<<"Don gia";
	cout<<setw(15)<<left<<"Thanh tien"<<endl;
}
int thanh_tien(HoaDon hd[], int n)// Ham tinh thanh tien
{
	for(int i=0 ; i<n; i++)
	{
		hd[i].tt=hd[i].dg;
	}
}
int tong_thanh_tien(HoaDon hd[], int n)// Ham tinh tong thanh tien
{
	int t=0;
	for(int i=0; i<n; i++)
	{
		t=t+hd[i].tt;
			
	}
	return t;
}
int sapxep(HoaDon hd[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(hd[i].tt < hd[j].tt)
			{
				HoaDon temp=hd[i];
				hd[i]=hd[j];
				hd[j]=temp;
			}
		}
	}
}
int main()
{
	HoaDon *hd;
	int n;
	cout<<"\nNhap so luong vat tu: ";
	cin>>n;
	hd = new HoaDon[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nThong tin vat tu "<<i+1<<endl;
		hd[i].nhap();
	}
	thanh_tien(hd, n);
	cout<<"\nThong tin vat tu vua nhap la: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		hd[i].xuat();
	}
	cout<<"\nTong thanh tien: "<<tong_thanh_tien(hd, n)<<endl;
	sapxep(hd, n);
	cout<<"\nIn ra danh sach sap xep theo so tien giam dan: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		hd[i].xuat();
	}
	return 0;
}