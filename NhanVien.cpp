#include "NhanVien.h"
#include <iomanip>

void NhanVien::nhap()
{
    cin.ignore();

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}

void NhanVien::xuat()
{
    cout << fixed << setprecision(0);

    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong: " << luong << endl;
}

double NhanVien::getLuong()
{
    return luong;
}

NhanVien::~NhanVien()
{

}

// ================= SAN XUAT =================

void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();

    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;

    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NhanVienSanXuat::tinhLuong()
{
    luong = luongCanBan + soSanPham * 5000;
}

void NhanVienSanXuat::xuat()
{
    cout << "\n NHAN VIEN SAN XUAT \n";

    NhanVien::xuat();

    cout << "Luong can ban: " << luongCanBan << endl;
    cout << "So san pham: " << soSanPham << endl;
}

// ================= VAN PHONG =================

void NhanVienVanPhong::nhap()
{
    NhanVien::nhap();

    cout << "Nhap so ngay lam: ";
    cin >> soNgayLam;
}

void NhanVienVanPhong::tinhLuong()
{
    luong = soNgayLam * 100000;
}

void NhanVienVanPhong::xuat()
{
    cout << "\n NHAN VIEN VAN PHONG \n";

    NhanVien::xuat();

    cout << "So ngay lam: " << soNgayLam << endl;
}
