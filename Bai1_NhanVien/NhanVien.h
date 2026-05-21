#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    virtual void nhap();
    virtual void xuat();
    virtual void tinhLuong() = 0;

    double getLuong();

    virtual ~NhanVien();
};

class NhanVienSanXuat : public NhanVien
{
private:
    double luongCanBan;
    int soSanPham;

public:
    void nhap();
    void xuat();
    void tinhLuong();
};

class NhanVienVanPhong : public NhanVien
{
private:
    int soNgayLam;

public:
    void nhap();
    void xuat();
    void tinhLuong();
};

#endif
