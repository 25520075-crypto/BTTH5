#include "GiaoDich.h"

#include <iomanip>

// ================= GIAO DICH =================

void GiaoDich::nhap()
{
    cin.ignore();

    cout << "Nhap ma giao dich: ";
    getline(cin, maGD);

    cout << "Nhap ngay giao dich: ";
    getline(cin, ngayGD);

    cout << "Nhap don gia: ";
    cin >> donGia;

    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDich::xuat()
{
    cout << fixed << setprecision(0);

    cout << "Ma GD: " << maGD << endl;
    cout << "Ngay GD: " << ngayGD << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: " << thanhTien << endl;
}

double GiaoDich::getThanhTien()
{
    return thanhTien;
}

string GiaoDich::getNgayGD()
{
    return ngayGD;
}

GiaoDich::~GiaoDich()
{

}

// ================= DAT =================

void GiaoDichDat::nhap()
{
    GiaoDich::nhap();

    cout << "Nhap loai dat (A/B/C): ";
    cin >> loaiDat;
}

void GiaoDichDat::tinhThanhTien()
{
    if(loaiDat == 'A')
    {
        thanhTien = dienTich * donGia * 1.5;
    }
    else
    {
        thanhTien = dienTich * donGia;
    }
}

void GiaoDichDat::xuat()
{
    cout << "\n=== GIAO DICH DAT ===\n";

    GiaoDich::xuat();

    cout << "Loai dat: " << loaiDat << endl;
}

// ================= NHA PHO =================

void GiaoDichNhaPho::nhap()
{
    GiaoDich::nhap();

    cin.ignore();

    cout << "Nhap loai nha: ";
    getline(cin, loaiNha);

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

void GiaoDichNhaPho::tinhThanhTien()
{
    if(loaiNha == "cao cap")
    {
        thanhTien = dienTich * donGia;
    }
    else
    {
        thanhTien = dienTich * donGia * 0.9;
    }
}

void GiaoDichNhaPho::xuat()
{
    cout << "\n=== GIAO DICH NHA PHO ===\n";

    GiaoDich::xuat();

    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi: " << diaChi << endl;
}

// ================= CAN HO =================

void GiaoDichCanHo::nhap()
{
    GiaoDich::nhap();

    cin.ignore();

    cout << "Nhap ma can: ";
    getline(cin, maCan);

    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
}

void GiaoDichCanHo::tinhThanhTien()
{
    if(viTriTang == 1)
    {
        thanhTien = dienTich * donGia * 2;
    }
    else if(viTriTang >= 15)
    {
        thanhTien = dienTich * donGia * 1.2;
    }
    else
    {
        thanhTien = dienTich * donGia;
    }
}

void GiaoDichCanHo::xuat()
{
    cout << "\n=== GIAO DICH CAN HO ===\n";

    GiaoDich::xuat();

    cout << "Ma can: " << maCan << endl;
    cout << "Vi tri tang: " << viTriTang << endl;
}
