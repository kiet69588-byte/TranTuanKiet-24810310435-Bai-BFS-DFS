#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int A[MAX][MAX];
int n;

char dinh[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int visited[MAX];
int duongDi[MAX];
int duongDiTotNhat[MAX];

int dem;
int demTotNhat;
int minTrongSo;

// CAU 2:
void Nhap()
{
    ifstream file("Grap.txt");

    if (!file)
    {
        cout << "Khong mo duoc file Grap.txt!";
        return;
    }

    file >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> A[i][j];
        }
    }

    file.close();
}

// CAU 3:
void HienThi()
{
    cout << "Ma tran trong so:\n";

    cout << "  ";
    for (int i = 0; i < n; i++)
        cout << dinh[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dinh[i] << " ";

        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

// CAU 4:
void DFS(int u, int v, int tong)
{
    if (u == v)
    {
        if (tong < minTrongSo)
        {
            minTrongSo = tong;
            demTotNhat = dem;

            for (int i = 0; i < dem; i++)
                duongDiTotNhat[i] = duongDi[i];
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (A[u][i] > 0 && visited[i] == 0)
        {
            visited[i] = 1;
            duongDi[dem] = i;
            dem++;

            DFS(i, v, tong + A[u][i]);

            dem--;
            visited[i] = 0;
        }
    }
}

void TimDuongDi(int u, int v)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dem = 1;
    demTotNhat = 0;
    minTrongSo = 1000000;

    duongDi[0] = u;
    visited[u] = 1;

    DFS(u, v, 0);

    if (demTotNhat == 0)
    {
        cout << "Khong co duong di!";
        return;
    }

    cout << "Duong di ngan nhat tu "
         << dinh[u] << " den " << dinh[v] << ": ";

    for (int i = 0; i < demTotNhat; i++)
    {
        cout << dinh[duongDiTotNhat[i]];

        if (i < demTotNhat - 1)
            cout << " -> ";
    }

    cout << "\nTong trong so: " << minTrongSo;
}

// CAU 5:
int main()
{
    Nhap();

    HienThi();

    cout << endl;

    TimDuongDi(0, 6);

    return 0;
}
 
