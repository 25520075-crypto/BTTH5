#include "GiaoDich.h"

int main()
{
    GiaoDich* ds[100];

    int n;

    cout << "Nhap so giao dich: ";
    cin >> n;

    // ================= NHAP =================

    for(int i = 0; i < n; i++)
    {
        int loai;

        cout << "\n1. Dat";
        cout << "\n2. Nha pho";
        cout << "\n3. Can ho";
        cout << "\nNhap loai giao dich: ";
        cin >> loai;

        if(loai == 1)
        {
            ds[i] = new GiaoDichDat();
        }
        else if(loai == 2)
        {
            ds[i] = new GiaoDichNhaPho();
        }
        else
        {
            ds[i] = new GiaoDichCanHo();
        }

        ds[i]->nhap();
        ds[i]->tinhThanhTien();
    }

    // ================= DEM SO LUONG =================

    int demDat = 0;
    int demNhaPho = 0;
    int demCanHo = 0;

    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichDat*>(ds[i]))
        {
            demDat++;
        }

        else if(dynamic_cast<GiaoDichNhaPho*>(ds[i]))
        {
            demNhaPho++;
        }

        else if(dynamic_cast<GiaoDichCanHo*>(ds[i]))
        {
            demCanHo++;
        }
    }

    cout << "\nSo giao dich dat: " << demDat << endl;
    cout << "So giao dich nha pho: " << demNhaPho << endl;
    cout << "So giao dich can ho: " << demCanHo << endl;

    // ================= TRUNG BINH CAN HO =================

    double tong = 0;
    int dem = 0;

    for(int i = 0; i < n; i++)
    {
        GiaoDichCanHo* ch =
            dynamic_cast<GiaoDichCanHo*>(ds[i]);

        if(ch != NULL)
        {
            tong += ch->getThanhTien();
            dem++;
        }
    }

    if(dem != 0)
    {
        cout << "\nTrung binh thanh tien can ho: "
             << tong / dem << endl;
    }

    // ================= NHA PHO MAX =================

    GiaoDichNhaPho* maxNP = NULL;

    double maxTien = -1;

    for(int i = 0; i < n; i++)
    {
        GiaoDichNhaPho* np =
            dynamic_cast<GiaoDichNhaPho*>(ds[i]);

        if(np != NULL)
        {
            if(np->getThanhTien() > maxTien)
            {
                maxTien = np->getThanhTien();
                maxNP = np;
            }
        }
    }

    if(maxNP != NULL)
    {
        cout << "\n NHA PHO TRI GIA CAO NHAT \n";

        maxNP->xuat();
    }

    // ================= THANG 12/2024 =================

    cout << "\n GIAO DICH THANG 12/2024 \n";

    for(int i = 0; i < n; i++)
    {
        if(ds[i]->getNgayGD().substr(3,7) == "12/2024")
        {
            ds[i]->xuat();
        }
    }

    // ================= DELETE =================

    for(int i = 0; i < n; i++)
    {
        delete ds[i];
    }

    return 0;
}
