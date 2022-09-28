#include <iostream.h>
class HCN
{
	private:
		float d,r; //chieu dai, rong 
	public:
		void nhap()
		{
			cout<<"\tNhap chieu dai: ";
			cin>>d;
			cout<<"\tNhap chieu rong: ";
			cin>>r;
		}
		void inthongtin()
		{
			cout<<"\tDai: "<<d<<"  Rong: "<<r<<endl;
		}
		float tinhchuvi()
		{
			return (d+r)*2;
		}
		float tinhdientich()
		{
			return d*r;
		}	
};
int main()
{
	HCN h[50]; //Khai bao doi tuong
	int n;
	cout<<"\nNhap so luong hinh chu nhat: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap thong tin hinh chu nhat thu "<<i+1<<endl;
		h[i].nhap(); //Goi ham thanh phan cua doi tuong
	}
	cout<<"\nIn thong tin hinh chu nhat: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nHinh chu nhat thu "<<i+1<<endl;
		h[i].inthongtin();	
		float cv=h[i].tinhchuvi();
		cout<<"\tChu vi: "<<cv;
		float dt=h[i].tinhdientich();
		cout<<"\tDien tich: "<<dt<<endl;
	}
	//Tim chu vi lon nhat
	float  maxcv=h[0].tinhchuvi();
	for(int i=0; i<n; i++)
	{
		if(maxcv < h[i].tinhchuvi())
		{
			maxcv=h[i].tinhchuvi();
		}
	}
	cout<<"\nGia tri lon nhat cua chu vi la: "<<maxcv;
	return 0;
}