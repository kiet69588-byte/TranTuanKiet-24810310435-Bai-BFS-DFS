#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define MAX 100

int A[MAX][MAX];
int n;

char dinh[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

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
    cout << "Ma tran ke cua do thi:\n";

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
void BFS(int u, int v)
{
    int visited[MAX] = {0};
    int truoc[MAX];

    for (int i = 0; i < n; i++)
        truoc[i] = -1;

    queue<int> q;

    visited[u] = 1;
    q.push(u);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int y = 0; y < n; y++)
        {
            if (A[x][y] == 1 && visited[y] == 0)
            {
                visited[y] = 1;
                truoc[y] = x;
                q.push(y);
            }
        }
    }

    if (visited[v] == 0)
    {
        cout << "Khong co duong di tu "
             << dinh[u] << " den " << dinh[v];
        return;
    }

    int duongDi[MAX];
    int dem = 0;
    int x = v;

    while (x != -1)
    {
        duongDi[dem] = x;
        dem++;
        x = truoc[x];
    }

    cout << "Duong di ngan nhat tu "
         << dinh[u] << " den " << dinh[v] << ": ";

    for (int i = dem - 1; i >= 0; i--)
    {
        cout << dinh[duongDi[i]];

        if (i > 0)
            cout << " -> ";
    }

    cout << "\nSo canh cua duong di: " << dem - 1;
}

// CAU 5:
int main()
{
    Nhap();

    HienThi();

    cout << endl;

    BFS(0, 7);

    return 0;
}

