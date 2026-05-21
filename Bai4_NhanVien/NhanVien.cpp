#include "NhanVien.h"

#include <iomanip>

// ================= NHAN VIEN =================

void NhanVien::nhap()
{
    cin.ignore();

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap tuoi: ";
    cin >> tuoi;

    cin.ignore();

    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);

    cout << "Nhap email: ";
    getline(cin, email);

    cout << "Nhap luong co ban: ";
    cin >> luongCB;
}

void NhanVien::xuat()
{
    cout << fixed << setprecision(0);

    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << sdt << endl;
    cout << "Email: " << email << endl;
    cout << "Luong co ban: " << luongCB << endl;
    cout << "Luong: " << luong << endl;
}

double NhanVien::getLuong()
{
    return luong;
}

NhanVien::~NhanVien()
{

}

// ================= LAP TRINH VIEN =================

void LapTrinhVien::nhap()
{
    NhanVien::nhap();

    cout << "Nhap so gio overtime: ";
    cin >> soGioOT;
}

void LapTrinhVien::tinhLuong()
{
    luong = luongCB + soGioOT * 200000;
}

void LapTrinhVien::xuat()
{
    cout << "\n LAP TRINH VIEN \n";

    NhanVien::xuat();

    cout << "So gio overtime: "
         << soGioOT << endl;
}

// ================= KIEM CHUNG VIEN =================

void KiemChungVien::nhap()
{
    NhanVien::nhap();

    cout << "Nhap so loi phat hien: ";
    cin >> soLoi;
}

void KiemChungVien::tinhLuong()
{
    luong = luongCB + soLoi * 50000;
}

void KiemChungVien::xuat()
{
    cout << "\n KIEM CHUNG VIEN \n";

    NhanVien::xuat();

    cout << "So loi phat hien: "
         << soLoi << endl;
}
