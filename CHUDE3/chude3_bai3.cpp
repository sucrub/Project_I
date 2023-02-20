#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define M 6 // input
#define N 6 // output
int graph[M][N];
bool valid = false;
int people[M];

void generate_graph()
{

    srand(time(NULL));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (rand() % 2)
                graph[i][j] = 1;
        }
    }
}

void print_graph()
{

    cout << "##############################" << endl;
    cout << "Graph: " << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 0)
                cout << i << " -> " << j << endl;
        }
    }
    cout << "##############################" << endl;
}

// DFS tìm đường nối hợp lý
bool bpm(int u, bool seen[], int matchR[])
{

    // Duyệt tất cả các job
    for (int v = 0; v < N; v++)
    {
        // Nếu người đó yêu thích và chưa được duyệt qua
        if (graph[u][v] == 1 && !seen[v])
        {
            // Đã duyệt công việc
            seen[v] = true;
            // việc v chưa có ai làm hoặc duyệt những người đã làm việc đó có thể làm việc khác không, nếu có thể
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                // thì áp vào
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM()
{
    // Mảng thể hiện việc i do người matchR[i] đảm nhận
    int matchR[N];

    // Ban đầu chưa có việc nào được ai làm
    memset(matchR, -1, sizeof(matchR));

    // Kết quả
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        // Gán tất cả các công việc là chưa được xét ở mỗi vòng lặp
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Tìm xem người u có thể tìm được việc không
        if (bpm(u, seen, matchR))
            result++;
    }
    for (int i = 0; i < N; i++)
    {
        if (matchR[i] == -1)
            cout << "Khong ai lam viec thu " << i << endl;
        else
            cout << matchR[i] << " -> " << i << endl;
    }

    return result;
}

int main()
{

    generate_graph();
    print_graph();
    cout << maxBPM();
}