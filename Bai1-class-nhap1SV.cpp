#include <iostream.h>
class SV
{
	private:
		char ht[30]; // Ho ten
		float t, l, h; // Diem toan, li, hoa
	public:
			SV()// Ham tao khong tham so
		{
			strcpy(this->ht,"an");
			this->t=0;
			this->l=0;
			this->h=0;
		}
		SV(char *ht1, int a, int b, int c) // Ham tao nhieu tham so
		{
			strcpy(this->ht, ht1);
			this->t=a;
			this->l=b;
			this->h=c;
		}
		void nhap()
		{
			fflush(stdin);
			cout<<"\nNhap ten sinh vien: "; cin.getline(this->ht,30);
			cout<<"\nNhap diem toan: "; cin>>this->t;
			cout<<"\nNhap diem li: "; cin>>this->l;
			cout<<"\nNhap diem hoa: "; cin>>this->h;	
		}	
		void xuat()
		{
			cout<<"\tHo ten: "<<this->ht<<endl;
			cout<<"\tToan: "<<this->t<<endl;
			cout<<"\tLi: "<<this->l<<endl;
			cout<<"\tHoa: "<<this->h<<endl;
		}
		~SV(){};
};
int main()
{
	SV sv;
	cout<<"\nNhap thong tin sinh vien: "<<endl; 
	sv.nhap();
	cout<<"\nXuat thong tin sinh vien: "<<endl;
	sv.xuat();
	return 0;
}