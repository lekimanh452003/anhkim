#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct NGAYTHANG
{
	int dd, mm, yyyy;		
};
class SinhVien
{
	private: // Khong co Private van se mac dinh la private
 		char msv[12]; //Ma sinh vien
		char hd[15]; // Ho dem
		char t[15]; //Ten
		NGAYTHANG ns; // ns ke thua lai cac thuoc tinh cua struct NGAYTHANG
		char gt[5];  // Gioi tinh
		char k[30]; // ho khau thuong tru
		float dt;  // Diem thi dai hoc
	public:
		void nhap()
		{
			cin.ignore(); // nen dung fflush(stdin)- ko ton bo nho
			cout<<"\tNhap ma sinh vien: "; cin.getline(this->msv, 12);
			cout<<"\tNhap ho dem: "; cin.getline(this->hd,15);
			cout<<"\tNhap ten: "; cin.getline(this->t, 15);
			cout<<"\tNhap ngay sinh: "; 
			cin>>this->ns.dd;
			cout<<"\tNhap thang sinh: ";
			cin>>this->ns.mm;
			cout<<"\tNhap nam sinh: ";
			cin>>this->ns.yyyy;
			cin.ignore(); // Ham getline: ham lay chuoi
			cout<<"\tNhap gioi tinh: "; cin.getline(this->gt,5);
			cout<<"\tNhap ho khau thuong tru: "; cin.getline(this->k, 30);
			cout<<"\tNhap diem thi dai hoc: "; cin>>this->dt;
		}
		void xuat()
		{
			cout<<setw(15)<<left<<this->msv
				<<setw(15)<<left<<this->hd
				<<setw(15)<<left<<this->t
				<<setw(10)<<right<<this->ns.dd
				<<"/"<<this->ns.mm<<"/"<<this->ns.yyyy
				<<setw(20)<<left<<this->gt
				<<setw(15)<<left<<this->k
				<<setw(15)<<left<<this->dt<<endl;
		}
		bool getdt()
		{
			return dt;
		}
		~SinhVien(){};		
};
void tieude()
{
	cout<<setw(15)<<left<<"MSV";
	cout<<setw(15)<<left<<"Ho dem";
	cout<<setw(15)<<left<<"Ten";
	cout<<setw(20)<<left<<"Ngay/thang/nam";
	cout<<setw(20)<<left<<"Gioi tinh";
	cout<<setw(15)<<left<<"Ho khau";
	cout<<setw(15)<<left<<"Diem thi"<<endl;
}
int main()
{
	SinhVien *sv;
	int n;
	cout<<"\nNhap so luong sinh vien: ";
	cin>>n;
	sv = new SinhVien[n];
	cout<<"\nNhap thong tin sinh vien: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap thong tin sinh vien thu "<<i+1<<endl;
		sv[i].nhap();
	}
	cout<<"\nHien thi danh sach sinh vien da nhap: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		sv[i].xuat();
	}
	cout<<"\nDanh sach sinh vien sap xep theo thu tu tang dan la: "<<endl;

	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(sv[i].getdt() > sv[j].getdt())
			{
				SinhVien temp=sv[i];
						sv[i]=sv[j];
						sv[j]=temp;
			}
		}
	}
	tieude();
	for(int i=0; i<n; i++)
	{
		sv[i].xuat();
	}
	return 0;
}