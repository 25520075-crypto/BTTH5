#ifndef GIAODICH_H
#define GIAODICH_H

#include <iostream>
#include <string>

using namespace std;

class GiaoDich
{
protected:
    string maGD;
    string ngayGD;
    double donGia;
    double dienTich;
    double thanhTien;

public:
    virtual void nhap();
    virtual void xuat();
    virtual void tinhThanhTien() = 0;

    double getThanhTien();

    string getNgayGD();

    virtual ~GiaoDich();
};

// ================= DAT =================

class GiaoDichDat : public GiaoDich
{
private:
    char loaiDat;

public:
    void nhap();
    void xuat();
    void tinhThanhTien();
};

// ================= NHA PHO =================

class GiaoDichNhaPho : public GiaoDich
{
private:
    string loaiNha;
    string diaChi;

public:
    void nhap();
    void xuat();
    void tinhThanhTien();
};

// ================= CAN HO =================

class GiaoDichCanHo : public GiaoDich
{
private:
    string maCan;
    int viTriTang;

public:
    void nhap();
    void xuat();
    void tinhThanhTien();
};

#endif
