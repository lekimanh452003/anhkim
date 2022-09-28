#include <iostream.h>
#include <iomanip.h>
struct NGAYTHANG
{
	int dd, mm, yyyy;	
};
struct SinhVien
{
	char msv[12];
	char hd[15];
	char t[15];
	NGAYTHANG ns;// ns ke thua lai cac thuoc tinh cua struct NGAYTHANG
	char gt[5];
	char k[30]; // ho khau thuong tru
	float dt; // Diem thi dai hoc	
	// & tham chieu: bao ve bien, giusp gia tri ko bi xung dot; sd khi du lieu vao co su thay doi
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
			<<setw(5)<<right<<this->ns.dd
			<<"/"<<this->ns.mm<<"/"<<this->ns.yyyy
			<<setw(15)<<right<<this->gt
			<<setw(15)<<right<<this->k
			<<setw(15)<<right<<this->dt<<endl;
	}

};
void tieude()
{
	cout<<setw(15)<<left<<"MSV"
	<<setw(15)<<left<<"Ho dem"
	<<setw(15)<<left<<"Ten"
	<<setw(15)<<left<<"Ngay/thang/nam"
	<<setw(15)<<right<<"Gioi tinh"
	<<setw(15)<<right<<"Ho khau"
	<<setw(15)<<right<<"Diem thi"<<endl;
}
void sxtd(SinhVien sv[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(sv[i].dt > sv[j].dt )
			{
				SinhVien temp=sv[i];
						sv[i]=sv[j];
						sv[j]=temp;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"\nNhap so luong sinh vien: ";
	cin>>n;
	SinhVien sv[n];
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
	sxtd(sv, n);
	for(int i=0; i<n; i++)
	{
		sv[i].xuat();
	}
	return 0;
}