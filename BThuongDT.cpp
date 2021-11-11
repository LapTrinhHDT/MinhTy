#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string>
using namespace std;

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
	string getTen();
	string getMa();
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
string Nguoi::getTen(){
	return HoTen;
}
string Nguoi::getMa(){
	return Ma;
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
	float HeSoLuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();//Hesoluong*1600*0.8
	float TienThuong();//bao nhieu cha duoc 
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
	return (SoLuongHang *GiaHang);
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
	Nguoi::Nhap();
	cout<<"\tNhap thoi gian vao lam ";
	NgayVaoLam.NhapDay();
	cout<<"\tNhap vao muc luong theo gio: ";
	cin>>LuongTheoGio;	
}	

void NhanVienThuViec::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tNgay vao lam la: ";
	NgayVaoLam.XuatDay();
	cout<<"\tMuc Luong Theo Gio La: "<<LuongTheoGio<<endl;
}

float NhanVienThuViec::TinhLuong(){
	return (LuongTheoGio*8);
}
//==============================Ham Nhap ================================


//==============================danh sach lien ke========================
/*
typedef class node* Node;
class node {
    private:
        Nguoi *data;
	    Node next;
    public:
       node(Node next);
       void SetNext(Node next);
       Node getNext();
       friend class QuanLiNhanVien;
};
void node::SetNext(Node next)
{
    this->next = next;
}
Node node::getNext()
{
    return next;
}
*/
typedef int Item;
struct Node {
	Nguoi *data;
	Node *next;
}; 
class QuanLiNhanVien
{
private:
	Node *head;
	Node *tail;
	long size;
public:
	QuanLiNhanVien();//khhoi tao quan li nhan vien 
    ~QuanLiNhanVien();
	Node* CreateNode(Nguoi* nv);
	void AddLast(Nguoi *nv);
	Node* traverse(Node *p
	);//duyet danh sach
	void XuatDS();
	int DemNhanVien();
	void TimKiemTen();
	void TimKiemMa();
	void removefirst();
	void removelast();
	void XoaNhanVien();
	void SapXepTen();
	void SapXepMa();
	void MaxLuong();
	void MinLuong();
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
Node* QuanLiNhanVien::CreateNode(Nguoi *nv)
{
	Node* p = new Node;
	p->data = nv;
	p->next = NULL;
	return p;
}
void QuanLiNhanVien::AddLast(Nguoi *nv) {
    Node *p = CreateNode(nv);
    if (size == 0) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;      
    }
    size ++;
}
Node *QuanLiNhanVien::traverse(Node *p){
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}


//----------------------------------------cac Ham --------------------------------



void NhapDS (QuanLiNhanVien &QL)
{
	Nguoi *nv;
	int SL1,SL2,SL3,SL4;
	cout<<"Nhap so Luong Nhan Vien Chinh Thuc:";
	cin>>SL1;
	for (int i = 0; i < SL1; i++)
	{
		nv = new NhanVienChinhThuc;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong Ban Thoi Gian:";
	cin>>SL2;
	for (int i = 0; i < SL2; i++)
	{
		nv = new NhanVienBanThoiGian;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong lam theo san pham:";
	cin>>SL3;
	for (int i = 0; i < SL3; i++)
	{
		nv = new NhanVienLamTheoSanPham;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong Thu viec:";
	cin>>SL4;
	for (int i = 0; i < SL4; i++)
	{
		nv = new NhanVienThuViec;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
}
void QuanLiNhanVien::XuatDS(){
	Nguoi *nv;
	cout<<endl<<"*******Danh sach Nhan Vien*******"<<endl;
	for(Node *p= head;p!=NULL;p = p->next){
		p->data->Xuat();
		cout<<"---------------------------------------------"<<endl;
    }	
}
void QuanLiNhanVien::TimKiemTen(){
	string TenTK;
	cout<<"Nhap Ten Nhan Vien can tim:";
	fflush(stdin);
	getline(cin,TenTK);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->getTen()==TenTK){
			p->data->Xuat();
		}
	}
}
void QuanLiNhanVien::TimKiemMa(){
	string MaTK;
	cout<<"Nhap Ma Nhan Vien can tim:";
	fflush(stdin);
	getline(cin,MaTK);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->getMa()==MaTK){
			p->data->Xuat();
		}
	}
}
int QuanLiNhanVien::DemNhanVien(){
	int Dem=0;
	for(Node*p=head;p!=NULL;p=p->next){
		Dem++;
	}
	cout<<"Tong so Nhan Vien la:"<<Dem<<endl;
}
void QuanLiNhanVien::removefirst(){
   if(head==NULL){
   	    cout<<"ko xoa duoc!";
	}else{
		Node*t=head;
		head=head->next;
		delete t;
		size--;
    }
}

void QuanLiNhanVien::XoaNhanVien(){
	string Maxoa;
	cout<<"Nhap Ma Nhan Vien can xoa:";
	fflush(stdin);
	getline(cin,Maxoa);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->getMa()==Maxoa){
			if(p==head){
			   	removefirst();
			}
			else if(p==tail){
				removelast();
			}
			else{
				Node *pre = traverse(p);
            	pre->next = p->next;
				delete p;
				size--;
			}
		}
	}
}
//void QuanLiNhanVien::XoaNhanVien(){
//	Node *p;
//	if (p == head) {
//		removefirst();
//		return;
//	}
//	if (p == tail) {
//		removelast();
//		return;
//	}
//	Node *pre = traverse(p);
//	pre->next = p->next;
//	delete p;
//	size--;
//}
void QuanLiNhanVien::removelast(){
	Node *pre = traverse(tail);
	Node*t =tail;
	pre->next=NULL;
	tail=pre;
	delete t;
	size--;
}	
void QuanLiNhanVien::SapXepTen(){
	Node*temp;
	for(Node*p=head;p!=tail;p=p->next){
		for(Node*q=p->next;q!=NULL;q=q->next){
		    if(p->data->getTen() > q->data->getTen()){
		        temp->data =p->data;
		        p->data=q->data;
		        q->data=temp->data;
		   }
		}
	}
}
void QuanLiNhanVien::SapXepMa(){
	Node*temp;
	for(Node*p=head;p!=tail;p=p->next){
		for(Node*q=p->next;q!=NULL;q=q->next){
		    if(p->data->getMa() > q->data->getMa()){
		        temp->data =p->data;
		        p->data=q->data;
		        q->data=temp->data;
		   }
		}
	}
}
void QuanLiNhanVien::MaxLuong(){
	Node*p=head;
	float Max=head->data->TinhLuong();
	for(p=head->next;p!=NULL;p=p->next){
		if(p->data->TinhLuong() > Max){
			Max=p->data->TinhLuong();
		}
	}
	p->data->Xuat();
}          
void QuanLiNhanVien::MinLuong(){
	Node*p=head;
	float Min=head->data->TinhLuong();
	for(p=head->next;p!=NULL;p=p->next){
		if(p->data->TinhLuong() < Min){
			Min=p->data->TinhLuong();
		}
	}
	p->data->Xuat();
}                
	int SuaNhanVien();
	int SuaTen();
	int SuaMa();
	int SuaChuaVu();//tang chuc , giam chuc , duoi viec, thu viec 
	void TongLuong();
	void Giaodien();

void Menu()
{
	QuanLiNhanVien t;
	int n;
	int Chon, Flat =1;
    int SL1,SL2,SL3,SL4;
	do{
		cout<<"               Quan Li Nhan Vien              "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"               CHUC NANG                      "<<endl;
		cout<<"1. Nhap                      ||    2. Xuat              "<<endl;
		cout<<"3. Them Nhan Vien            ||    4. Xoa               "<<endl;
		cout<<"5. Dem Tong Nhan Vien        ||    6. Tim Kiem nhan vien theo Ten"<<endl;
		cout<<"7.Tim Kiem Nhan Vien Theo Ma ||    8. Xoa Nhan Vien    " <<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"Hay Chon Mot Chuc Nang (Bam So): ";
		cin >> Chon;
		switch (Chon)
		{
			case 1:
				{
                    NhapDS(t);
					break;
				}
			case 2:
				{
					t.XuatDS();
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
			case 5:
				{
					t.DemNhanVien();
					break;
				}
			case 6:
				{
					t.TimKiemTen();					
					break;
				}
			case 7:
				{
					t.TimKiemMa();
					break;
				}
			case 8:
				{
   			    	t.XoaNhanVien();
					break;
				}
			case 9:
				{
					t.SapXepTen();
					t.XuatDS();
					break;
				}
			case 10:
				{
					t.SapXepMa();
					t.XuatDS();
					break;
				}
			case 11:
				{
					t.MaxLuong();
					break;
				}
			case 12:
				{
					t.MinLuong();
					break;
				}
			case 13:
				{
					break;
				}
			case 0:
				{
					cout<<"Ban da Thoat!"<<endl;
					break;
				}
			default:
				{
					cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
					break;
				}
		}		
	}while(Chon != 0);
}

int main()
{
    Menu() ;
}
