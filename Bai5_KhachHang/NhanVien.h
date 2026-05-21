#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

// ================= LOP CHA =================

class NhanVien
{
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;

    double luongCB;
    double luong;

public:
    virtual void nhap();
    virtual void xuat();
    virtual void tinhLuong() = 0;

    double getLuong();

    virtual ~NhanVien();
};

// ================= LAP TRINH VIEN =================

class LapTrinhVien : public NhanVien
{
private:
    int soGioOT;

public:
    void nhap();
    void xuat();
    void tinhLuong();
};

// ================= KIEM CHUNG VIEN =================

class KiemChungVien : public NhanVien
{
private:
    int soLoi;

public:
    void nhap();
    void xuat();
    void tinhLuong();
};

#endif
