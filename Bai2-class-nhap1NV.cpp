#include <iostream.h>
class NhanVien
{
	private:
		char ma[10]; // Ma nhan vien
		char ht[30]; // Ho ten
		float hsl; // He so luong
	public:
		NhanVien()// Ham tao khong tham so
		{
			strcpy(this->ma,"a123");
			strcpy(this->ht,"Tran Ha");
			this->hsl=0;
		}
		NhanVien(char *ma1, char *ht1, int a ) // Ham tao nhieu tham so
		{
			strcpy(this->ma, ma1);
  			strcpy(this->ht, ht1);
			this->hsl=a;
		}
		void nhap()
		{
			fflush(stdin);
			cout<<"\nNhap ma nhan vien: "; cin.getline(this->ma,10);
			cout<<"\nNhap ho ten: "; cin.getline(this->ht, 30);
			cout<<"\nNhap he so luong: "; cin>>this->hsl;	
		}	
		void xuat()
		{
			cout<<"\tMa: "<<this->ma<<endl;
			cout<<"\tHo ten: "<<this->ht<<endl;
			cout<<"\tHe so luong: "<<this->hsl<<endl;
		}
		~NhanVien(){};
};
int main()
{
	NhanVien nv;
	cout<<"\nNhap thong tin nhan vien: "<<endl; 
	nv.nhap();
	cout<<"\nXuat thong tin nhan vien: "<<endl;
	nv.xuat();
	return 0;
}