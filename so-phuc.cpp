#include <iostream.h>
class SoPhuc{
	private:
		int pt, pa; // Phan thuc va phan ao cua so phuc
	public:
		void nhap()
		{
			cout<<"\nNhap phan thuc = ";
			cin>>pt;
			cout<<"\nNhap phan ao = ";
			cin>>pa;
		}
		void xuat()
		{
			cout<<"\nA = "<<pt<<" + "<<pa<<"*j"<<endl;
		}
		int getpt()
		{
			return pt;
		}
		int getpa()
		{
			return pa;
		}
};
int main()
{
	SoPhuc a[2];
	for(int i=0; i<2; i++)
	{
		a[i].nhap();
	}
	
	cout<<"\nTong 2 so phuc vua nhap: "<<endl;
	cout<<a[0].getpt() + a[1].getpt()<<" + "<<a[0].getpa() + a[1].getpa()
		<<"*j"<<endl;
		
	cout<<"\nHieu 2 so phuc vua nhap: "<<endl;
	cout<<a[0].getpt() - a[1].getpt()<<" + "<<"("<<a[0].getpa() - a[1].getpa()
		<<")"<<"*j"<<endl;
	return 0;
}