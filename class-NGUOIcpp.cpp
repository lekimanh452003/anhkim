#include <iostream.h>
#include <string.h>
#include <iomanip.h>
class NGUOI
{
	private:
		char ht[30];
		char scm[10];
		char gt[4];
	public:
		NGUOI(){}; // Ham khoi tao khong tham so
		NGUOI(char *ht1, char *scm1, char *gt1) // Ham khoi tao co tham so
		{
			strcpy(this->ht, ht1);
			strcpy(this->scm, scm1);
			strcpy(this->gt, gt1);
		}	
		~NGUOI(){};
		
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ho ten: "; cin.getline(this->ht, 30);
			cout<<"\tNhap so chung minh: "; cin.getline(this->scm, 10);
			cout<<"\tNhap gioi tinh: "; cin.getline(this->gt, 4);
		}
		void xuat()
		{
			cout<<setw(20)<<left<<this->ht
				<<setw(20)<<left<<this->scm
				<<setw(20)<<left<<this->gt<<endl;
		}
		char* getHT()
		{
			return ht;
		}
};
void tieude()
{
	cout<<setw(20)<<left<<"Ho ten"
	<<setw(20)<<left<<"So chung minh"
	<<setw(20)<<left<<"Gioi tinh"<<endl;
}
int main()
{
	int n; 
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	NGUOI ng[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap thong tin nguoi thu "<<i+1<<endl;
		ng[i].nhap();
	}
	cout<<"\nXuat thong tin cua mot nguoi: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		ng[i].xuat();
	}
	
	cout<<"\nTim kiem nguoi ten Nguyen Van A: "<<endl;
	
	for(int i=0; i<n; i++)
	{
		if(strcmp(ng[i].getHT(),"Nguyen Van A")==0)
		{
			tieude();
			ng[i].xuat();
		}
		else{
			cout<<"\tKhong co nguoi ten Nguyen Van A trong danh sach. "<<endl;
		}	
	}
	
	return 0;
}