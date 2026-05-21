#include "SinhVien.h"

int main()
{
    SinhVien* ds[100];

    int n;

    cout << "Nhap so sinh vien: ";
    cin >> n;

    // ================= NHAP =================

    for(int i = 0; i < n; i++)
    {
        int loai;

        cout << "\n1. Sinh vien Cao Dang";
        cout << "\n2. Sinh vien Dai Hoc";
        cout << "\nNhap loai sinh vien: ";
        cin >> loai;

        if(loai == 1)
        {
            ds[i] = new SinhVienCaoDang();
        }
        else
        {
            ds[i] = new SinhVienDaiHoc();
        }

        ds[i]->nhap();
    }

    // ================= XUAT DANH SACH =================

    cout << "\n DANH SACH SINH VIEN \n";

    for(int i = 0; i < n; i++)
    {
        ds[i]->xuat();
    }

    // ================= DU DIEU KIEN TOT NGHIEP =================

    cout << "\n SINH VIEN DU DIEU KIEN TOT NGHIEP \n";

    for(int i = 0; i < n; i++)
    {
        if(ds[i]->xetTotNghiep())
        {
            ds[i]->xuat();
        }
    }

    // ================= KHONG DU DIEU KIEN =================

    cout << "\n SINH VIEN KHONG DU DIEU KIEN \n";

    for(int i = 0; i < n; i++)
    {
        if(!ds[i]->xetTotNghiep())
        {
            ds[i]->xuat();
        }
    }

    // ==========SINH VIEN DAI HOC DIEM TB MAX =================

    SinhVienDaiHoc* maxDH = NULL;

    double maxDHScore = -1;

    for(int i = 0; i < n; i++)
    {
        SinhVienDaiHoc* dh =
            dynamic_cast<SinhVienDaiHoc*>(ds[i]);

        if(dh != NULL)
        {
            if(dh->getDiemTB() > maxDHScore)
            {
                maxDHScore = dh->getDiemTB();
                maxDH = dh;
            }
        }
    }

    if(maxDH != NULL)
    {
        cout << "\n SINH VIEN DAI HOC DIEM TB CAO NHAT \n";

        maxDH->xuat();
    }

    // =========== SINH VIEN CAO DANG DIEM TB MAX ===========

    SinhVienCaoDang* maxCD = NULL;

    double maxCDScore = -1;

    for(int i = 0; i < n; i++)
    {
        SinhVienCaoDang* cd =
            dynamic_cast<SinhVienCaoDang*>(ds[i]);

        if(cd != NULL)
        {
            if(cd->getDiemTB() > maxCDScore)
            {
                maxCDScore = cd->getDiemTB();
                maxCD = cd;
            }
        }
    }

    if(maxCD != NULL)
    {
        cout << "\n SINH VIEN CAO DANG DIEM TB CAO NHAT \n";

        maxCD->xuat();
    }

    // ================= DEM KHONG TOT NGHIEP =================

    int rotCD = 0;
    int rotDH = 0;

    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<SinhVienCaoDang*>(ds[i])
           && !ds[i]->xetTotNghiep())
        {
            rotCD++;
        }

        if(dynamic_cast<SinhVienDaiHoc*>(ds[i])
           && !ds[i]->xetTotNghiep())
        {
            rotDH++;
        }
    }

    cout << "\nSo sinh vien Cao Dang khong tot nghiep: "
         << rotCD << endl;

    cout << "So sinh vien Dai Hoc khong tot nghiep: "
         << rotDH << endl;

    // ================= DELETE =================

    for(int i = 0; i < n; i++)
    {
        delete ds[i];
    }

    return 0;
}
