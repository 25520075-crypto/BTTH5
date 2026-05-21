#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    virtual void nhap();
    virtual void xuat();
    virtual bool xetTotNghiep() = 0;

    double getDiemTB();

    virtual ~SinhVien();
};

// ================= CAO DANG =================

class SinhVienCaoDang : public SinhVien
{
private:
    double diemThiTN;

public:
    void nhap();
    void xuat();
    bool xetTotNghiep();
};

// ================= DAI HOC =================

class SinhVienDaiHoc : public SinhVien
{
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void nhap();
    void xuat();
    bool xetTotNghiep();
};

#endif
