#include<iostream>
using namespace std;

class NgaySinh
{
	protected:
		int ngay;
		int thang;
		int nam;
	public:
		NgaySinh();
		NgaySinh(int ngay, int thang, int nam);
		NgaySinh(const NgaySinh &day);
		~NgaySinh();
		void NhapNgaySinh();
		void XuatNgaySinh();
};
NgaySinh::NgaySinh()
{
	ngay=0;
	thang=0;
	nam=0;
}
NgaySinh::NgaySinh(int ngay, int thang, int nam)
{
	ngay = ngay;
	thang = thang;
	nam = nam;
}
NgaySinh::NgaySinh(const NgaySinh &day)
{
	*this = day;
}
NgaySinh::~NgaySinh()
{
}
void NgaySinh::NhapNgaySinh()
{
    char PhanChia;   //phan chia dung ki tu "/"
    cout<<"\nnhap ngay, thang, nam sinh(dd/mm/yyyy)  ";
    cin>>ngay>>PhanChia>>thang>>PhanChia>>nam;
}
void NgaySinh::XuatNgaySinh()
{
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}


class Nguoi : public NgaySinh
{
	private:	
		string Name;
		int age;
		string sex;
		NgaySinh ns;
		string DiaChhi;
		int SoGioLam;
		float Luong;
		float TienThuong;
	public:
		virtual istream & operator >> (istream &is,Nguoi &Ng);
		virtual friend ostream & operator <<(ostream &os,const B &b);
		virtual void TinhLuong() = 0;
}; 
class NhanVien: public Nguoi
{
	private:
		string CongViec;
		int MucLuongHienTai;
		
		
};
class ThuKi
{
	
};
class CapQuanTri
{
	
};
//
class QuanLiNhanVien
{
	
};
