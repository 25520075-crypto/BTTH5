#include "KhachHang.h"
#include <iomanip>
int main()
{
    ifstream fin("XYZ.INP");

    ofstream fout("XYZ.OUT");

    if(!fin)
    {
        cout << "Khong mo duoc file XYZ.INP";
        return 0;
    }

    KhachHang* ds[3000];

    int x, y, z;

    fin >> x >> y >> z;

    int n = 0;

    // ================= KHACH HANG A =================

    for(int i = 0; i < x; i++)
    {
        ds[n] = new KhachHangA();

        ds[n]->nhap(fin);

        ds[n]->tinhTien();

        n++;
    }

    // ================= KHACH HANG B =================

    for(int i = 0; i < y; i++)
    {
        ds[n] = new KhachHangB();

        ds[n]->nhap(fin);

        ds[n]->tinhTien();

        n++;
    }

    // ================= KHACH HANG C =================

    for(int i = 0; i < z; i++)
    {
        ds[n] = new KhachHangC();

        ds[n]->nhap(fin);

        ds[n]->tinhTien();

        n++;
    }

    // ================= XUAT FILE =================

    fout << x << " "
         << y << " "
         << z << endl << endl;

    double tongTien = 0;

    for(int i = 0; i < n; i++)
    {
        ds[i]->xuat(fout);

        fout << endl;

        tongTien += ds[i]->getSoTien();
    }

    // ================= TONG CONG TY THU =================

    fout << "TongSoTienCongTyThuDuoc" << endl;

    fout << fixed << setprecision(0)
         << tongTien << endl;

    // ================= DELETE =================

    for(int i = 0; i < n; i++)
    {
        delete ds[i];
    }

    fin.close();
    fout.close();

    return 0;
}
