#include "NhanVien.h"

int main()
{
    NhanVien* ds[100];

    int n;

    cout << "Nhap so nhan vien: ";
    cin >> n;

    // ================= NHAP =================

    for(int i = 0; i < n; i++)
    {
        int loai;

        cout << "\n1. Lap trinh vien";
        cout << "\n2. Kiem chung vien";
        cout << "\nNhap loai nhan vien: ";
        cin >> loai;

        if(loai == 1)
        {
            ds[i] = new LapTrinhVien();
        }
        else
        {
            ds[i] = new KiemChungVien();
        }

        ds[i]->nhap();
        ds[i]->tinhLuong();
    }

    // ================= XUAT DANH SACH =================

    cout << "\n DANH SACH NHAN VIEN \n";

    for(int i = 0; i < n; i++)
    {
        ds[i]->xuat();
    }

    // ================= LUONG TRUNG BINH =================

    double tongLuong = 0;

    for(int i = 0; i < n; i++)
    {
        tongLuong += ds[i]->getLuong();
    }

    double luongTB = tongLuong / n;

    cout << "\nLuong trung binh: "
         << luongTB << endl;

    // ================= LUONG THAP HON TRUNG BINH =================

    cout << "\n===== NHAN VIEN LUONG < TRUNG BINH =====\n";

    for(int i = 0; i < n; i++)
    {
        if(ds[i]->getLuong() < luongTB)
        {
            ds[i]->xuat();
        }
    }

    // ================= NHAN VIEN LUONG CAO NHAT =================

    NhanVien* maxNV = ds[0];

    for(int i = 1; i < n; i++)
    {
        if(ds[i]->getLuong() > maxNV->getLuong())
        {
            maxNV = ds[i];
        }
    }

    cout << "\n NHAN VIEN LUONG CAO NHAT \n";

    maxNV->xuat();

    // ================= NHAN VIEN LUONG THAP NHAT =================

    NhanVien* minNV = ds[0];

    for(int i = 1; i < n; i++)
    {
        if(ds[i]->getLuong() < minNV->getLuong())
        {
            minNV = ds[i];
        }
    }

    cout << "\n===== NHAN VIEN LUONG THAP NHAT =====\n";

    minNV->xuat();

    // ================= LAP TRINH VIEN LUONG MAX =================

    LapTrinhVien* maxLTV = NULL;

    double maxLuongLTV = -1;

    for(int i = 0; i < n; i++)
    {
        LapTrinhVien* ltv =
            dynamic_cast<LapTrinhVien*>(ds[i]);

        if(ltv != NULL)
        {
            if(ltv->getLuong() > maxLuongLTV)
            {
                maxLuongLTV = ltv->getLuong();
                maxLTV = ltv;
            }
        }
    }

    if(maxLTV != NULL)
    {
        cout << "\n LAP TRINH VIEN LUONG CAO NHAT \n";

        maxLTV->xuat();
    }

    // ================= KIEM CHUNG VIEN LUONG MIN =================

    KiemChungVien* minKCV = NULL;

    double minLuongKCV = 1e18;

    for(int i = 0; i < n; i++)
    {
        KiemChungVien* kcv =
            dynamic_cast<KiemChungVien*>(ds[i]);

        if(kcv != NULL)
        {
            if(kcv->getLuong() < minLuongKCV)
            {
                minLuongKCV = kcv->getLuong();
                minKCV = kcv;
            }
        }
    }

    if(minKCV != NULL)
    {
        cout << "\n KIEM CHUNG VIEN LUONG THAP NHAT \n";

        minKCV->xuat();
    }

    // ================= DELETE =================

    for(int i = 0; i < n; i++)
    {
        delete ds[i];
    }

    return 0;
}
