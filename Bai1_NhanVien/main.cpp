#include "NhanVien.h"

int main()
{
    NhanVien* ds[100];

    int n;

    cout << "Nhap so nhan vien: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int loai;

        cout << "\n1. Nhan vien san xuat";
        cout << "\n2. Nhan vien van phong";
        cout << "\nNhap loai: ";
        cin >> loai;

        if(loai == 1)
        {
            ds[i] = new NhanVienSanXuat();
        }
        else
        {
            ds[i] = new NhanVienVanPhong();
        }

        ds[i]->nhap();
        ds[i]->tinhLuong();
    }

    cout << "\n DANH SACH NHAN VIEN \n";

    for(int i = 0; i < n; i++)
    {
        ds[i]->xuat();
    }

    double tong = 0;

    for(int i = 0; i < n; i++)
    {
        tong += ds[i]->getLuong();
    }

    cout << "\nTong luong cong ty: " << tong << endl;

    for(int i = 0; i < n; i++)
    {
        delete ds[i];
    }

    return 0;
}
