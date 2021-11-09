#include<iostream>
using namespace std;

typedef int Item;
class Day
{
protected:
	int ngay;
	int thang;
	int nam;
public:
	Day();
	Day(int ngay, int thang, int nam);
	Day(const Day& day);
	~Day();
	void NhapDay();
	void XuatDay();
};

Day::Day()
{
	ngay = 0;
	thang = 0;
	nam = 0;
}

Day::Day(int ngay, int thang, int nam)
{
	ngay = ngay;
	thang = thang;
	nam = nam;
}

Day::Day(const Day& day)
{
	*this = day;
}

Day::~Day()
{
}

void Day::NhapDay()
{
	char PhanChia;   //phan chia dung ki tu "/"
	cout << "(dd/mm/yyyy):  ";
	cin >> ngay >> PhanChia >> thang >> PhanChia >> nam;
}

void Day::XuatDay()
{
	cout << ngay << "/" << thang << "/" << nam << endl;
}


			//XAY DUNG LOP NGUOI
class Nguoi : public Day
{
private:
	string Ma;
	string HoTen;
	int Tuoi;
	string GioiTinh;
	Day NgaySinh;
	string DiaChi;
	float Luong;
	float TienThuong;
	float HeSoLuong;
public:
	//ham tao ham huy 
	Nguoi();
	Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong);
	Nguoi(const Nguoi &nguoi);
	~Nguoi();
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhLuong() = 0;
	float getLuong();
	float getTienThuong();
};

Nguoi::Nguoi()
{
	this->Ma = "";
	this->HoTen = "";
	this->Tuoi = 0;
	this->GioiTinh = "";
	this->DiaChi = "";
	this->Luong = 0;
	this->TienThuong = 0;
}

Nguoi::Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong)
{
	this->Ma = Ma;
	this->HoTen = HoTen;
	this->Tuoi = Tuoi;
	this->GioiTinh = GioiTinh;
	this->DiaChi = DiaChi;
	this->Luong = Luong;
	this->TienThuong = TienThuong;
}

Nguoi::Nguoi(const Nguoi&nguoi)
{
	*this = nguoi;
}

Nguoi::~Nguoi()
{	
}

void Nguoi::Nhap()
{
	cout<<"\tNhap Vao Ma So Nhan Vien: ";
	fflush(stdin);
	getline(cin,Ma);
	cout<<"\tNhap Ho Va Ten (Day Du): ";
	fflush(stdin);
	getline(cin,HoTen);
	cout<<"\tNhap So Tuoi: ";
	cin >> Tuoi;
	cout<<"\tNhap Ngay Sinh  ";
	NgaySinh.NhapDay();
	cout<<"\tNhap Gioi Tinh: ";
	fflush(stdin);
	getline(cin,GioiTinh);
	cout<<"\tNhap Dia Chi: ";
	fflush(stdin);
	getline(cin,DiaChi);
}

void Nguoi::Xuat()
{
	cout<<"\tMa So Nhan Vien La: "<<Ma<<endl;
	cout<<"\tHo Ten Cua Nhan Vien La: "<<HoTen<<endl;
	cout<<"\tSo Tuoi La:"<<Tuoi<<endl;
	cout<<"\tNgay Sinh: ";
	NgaySinh.XuatDay();
	cout<<"\tGioi Tinh :"<<GioiTinh<<endl;
	cout<<"\tDia Chi: "<<DiaChi<<endl;
}

float Nguoi::getLuong()
{
	return Luong;
}
float Nguoi::getTienThuong()
{
	return TienThuong;
}

		//THONG TIN NHAN VIEN
class NhanVienChinhThuc : public Nguoi
{
private:
	string ChucVu;
	int ThamNien;

	string BoPhan; //ke toan , desinger , CEO , chao hang , 
public:
	void Nhap();
	void Xuat();
	float TinhLuong();//Hesoluong*1600*0.8
	float TienThuong();//bao nhieu cha duoc 
//	friend class QuanLiNhanVien;
};

void NhanVienChinhThuc::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap Chuc vu cua nhan vien la: ";
	fflush(stdin);
	getline(cin, ChucVu);
	cout<<"\tnhap vao tham nien: ";
	cin>> ThamNien;
	cout<<"nhap Vao bo Phan viec lam: ";
	fflush(stdin);
	getline(cin, BoPhan);
}
void NhanVienChinhThuc::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tChuc Vu cua nhan vien : "<<ChucVu<<endl;
	cout<<"\tTham Nien : "<<ThamNien<<endl;
	cout<<"\tBo Phan Lam Viec La: "<<BoPhan<<endl;
}


float NhanVienChinhThuc::TinhLuong()
{
    return (HeSoLuong*1600*0.8);
}


class NhanVienBanThoiGian : public Nguoi
{
private:
	int SoGioLam;
	float SoLuongTheoGio;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();// so gio nhan voi so luong theo gio
//	friend class QuanLiNhanVien;
};

void NhanVienBanThoiGian::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Gio Lam : ";
	cin>>SoGioLam;
	cout<<"\tNhap So Luong Theo Gio: ";
	cin>> SoLuongTheoGio;
}

void NhanVienBanThoiGian::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tSo Gio Lam la: "<<SoGioLam<<endl;
	cout<<"\tSo luong Theo Gio La: "<<SoLuongTheoGio<<endl;
}

float NhanVienBanThoiGian::TinhLuong(){
    return (SoGioLam*SoLuongTheoGio);
}

class NhanVienLamTheoSanPham : public Nguoi
{
private:
	int SoLuongHang;
	float GiaHang;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();//so luong hang * gia hang
//	friend class QuanLiNhanVien;
};

void NhanVienLamTheoSanPham::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Luong Hang Hoa: ";
	cin>>SoLuongHang;
	cout<<"\tNhap Vao Gia Hang: ";
	cin>>GiaHang;
}

void NhanVienLamTheoSanPham::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tSo Luong Hang Hoa: "<<SoLuongHang<<endl;
	cout<<"\tVao Gia Hang: "<<GiaHang<<endl;
}
float NhanVienLamTheoSanPham::TinhLuong(){

}


class NhanVienThuViec : public Nguoi
{
private:
	Day NgayVaoLam;
	float LuongTheoGio;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();// muc luong co ban cua nhan vien = luong theo gio* 8 time;
//	friend class QuanLiNhanVien;
}; 

void NhanVienThuViec::Nhap()
{
	cout<<"\tNhap thoi gian vao lam ";
	NgayVaoLam.NhapDay();
	cout<<"\tNhap vao muc luong theo gio: ";
	cin>>LuongTheoGio;	
}	

void NhanVienThuViec::Xuat()
{
	cout<<"\tNgay vao lam la: ";
	NgayVaoLam.XuatDay();
	cout<<"\tMuc Luong Theo Gio La: "<<LuongTheoGio<<endl;
}

float NhanVienThuViec::TinhLuong(){

}
typedef class node* Node;
class node {
    private:
        Nguoi *data;
	    Node next;
        Node prev;
    public:
       node(Node next, Node prev);
       void SetNext(Node next);
       Node getNext();
       void SetPrev(Node prev);
       Node getPrev();
       friend class QuanLiNhanVien;
};
node::node(Node next, Node prev)
{
    this->next = next;
    this->prev;
}
void node::SetNext(Node next)
{
    this->next = next;
}
Node node::getNext()
{
    return next;
}
typedef class QuanLiNhanVien* QLNhanVien;
class QuanLiNhanVien
{
private:
	Node head;
	Node tail;
	long size;
public:
	QuanLiNhanVien();//khhoi tao quan li nhan vien 
    ~QuanLiNhanVien();
    void SetTail (Node tail);
    Node get (int index);
	Node* CreateNode(Nguoi *nv);
	void TaoNodeNhanVien(Nguoi *nv);
	void ThemNhanVien(Nguoi *nv);//hoi if vào class nao 		
	Item DemNhanVien();	// Count the number of students with low GPA (GPA < 4)
	void Duyet() const;//tim kiem nhan vien 
	void XoaNhanVien();
	void SapXepTen();
	void SapXepLuong();
	void HienThi();
	Item TimKiemTen();
	Item TimKiemMa();
	Item SuaNhanVien();
	Item SuaTen();
	Item SuaMa();
	Item SuaChuaVu();//tang chuc , giam chuc , duoi viec, thu viec  
	Item MaxLuong();//min
	void TongLuong();
	void TongNhanVien();
	void Docfile();
	void Ghifile();
	void Giaodien();
}; 
        //begin
QuanLiNhanVien::QuanLiNhanVien()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

QuanLiNhanVien::~QuanLiNhanVien()
{
	delete head;
	delete tail;
	size = 0;
}

void QuanLiNhanVien::SetTail(Node tail)
{
    this->tail = tail;
}
Node QuanLiNhanVien::get(int index)
{
    if (index < 0 || index >size)
        return NULL;
    Node tmp = head;
    for (int i=0 ; i< index; i++)
        tmp = tmp->getNext();
    return tmp;
}

Node *QuanLiNhanVien::CreateNode(Nguoi *nv)//them nut dau tien
{
	Node* p = new Node;
	p->data = nv;
	p->next = NULL;
	return p;
}

void QuanLiNhanVien::TaoNodeNhanVien(Nguoi *nv)
{
    Node *p = CreateNode(nv);
    p->next = head;
    head = p;
    if (size == 0)
        tail = p;
    size++;
}
void QuanLiNhanVien::ThemNhanVien(Nguoi *nv)
{
    nv = new NhanVienChinhThuc;
    string i;
}
void NhapDS(QuanLiNhanVien *QL)
{
    int SL1,SL2,SL3,SL4;
    cout<<"So Luong Nhan Vien Chinh Thuc La: ";
    cin>>SL1;
    Nguoi *nv;
    for (int i=0; i<SL1; i++)
    {
        nv = new NhanVienChinhThuc;
        QL->TaoNodeNhanVien = nv->Nhap();
    }
}
void Menu()
{
	int Chon, Flat =1;
    int SL1,SL2,SL3,SL4;
	while(Flat)
	{
		cout<<"               Quan Li Nhan Vien              "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"               CHUC NANG                      "<<endl;
		cout<<"1. nhap            ||    2. xuat              "<<endl;
		cout<<"3. Them Nhan Vien  ||    4. xoa               "<<endl;
		cout<<"                                              "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"Hay Chon Mot Chuc Nang (Bam So): ";
		cin >> Chon;
		switch (Chon)
		{
			case 1:
				{

					break;
				}
			case 2:
				{
					break;
				}
			case 3:
				{
					break;
				}
			case 4:
				{
					break;
				}
			case 6:
				{
					break;
				}
			case 7:
				{
					break;
				}
			case 8:
				{
					break;
				}
			case 9:
				{
					break;
				}
			case 10:
				{
					break;
				}
			case 11:
				{
					break;
				}
			case 12:
				{
					break;
				}
			case 13:
				{
					break;
				}
			case 14:
				{
					break;
				}
			case 15:
				{
					break;
				}
			default:
				{
					cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
					break;
				}
		}		
	}
}

int main()
{
    Menu() ;
} 
