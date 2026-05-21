#include "SinhVien.h"

#include <iomanip>

// ================= SINH VIEN =================

void SinhVien::nhap()
{
    cin.ignore();

    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    cout << "Nhap tong tin chi: ";
    cin >> tongTinChi;

    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

void SinhVien::xuat()
{
    cout << fixed << setprecision(2);

    cout << "Ma SV: " << maSV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tong tin chi: " << tongTinChi << endl;
    cout << "Diem TB: " << diemTB << endl;
}

double SinhVien::getDiemTB()
{
    return diemTB;
}

SinhVien::~SinhVien()
{

}

// ================= CAO DANG =================

void SinhVienCaoDang::nhap()
{
    SinhVien::nhap();

    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTN;
}

bool SinhVienCaoDang::xetTotNghiep()
{
    return tongTinChi >= 120
        && diemTB >= 5
        && diemThiTN >= 5;
}

void SinhVienCaoDang::xuat()
{
    cout << "\n SINH VIEN CAO DANG \n";

    SinhVien::xuat();

    cout << "Diem thi tot nghiep: "
         << diemThiTN << endl;
}

// ================= DAI HOC =================

void SinhVienDaiHoc::nhap()
{
    SinhVien::nhap();

    cin.ignore();

    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);

    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

bool SinhVienDaiHoc::xetTotNghiep()
{
    return tongTinChi >= 170
        && diemTB >= 5
        && diemLuanVan >= 5;
}

void SinhVienDaiHoc::xuat()
{
    cout << "\n SINH VIEN DAI HOC \n";

    SinhVien::xuat();

    cout << "Ten luan van: "
         << tenLuanVan << endl;

    cout << "Diem luan van: "
         << diemLuanVan << endl;
}
