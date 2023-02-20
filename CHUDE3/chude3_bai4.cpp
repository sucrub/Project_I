#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
// Hàng, cột, số xe, số chỗ đỗ
int ROWS, COLS, N = 0, M = 0;

// Test case
vector<string> park =
    // {"CCCCC", ".....", "PXPXP"};
    {"XXXXXXXXXXX",
     "X......XPPX",
     "XC...P.XPPX",
     "X......X..X",
     "X....C....X",
     "XXXXXXXXXXX"};
// {"P.....P...X.XX.X.X..X...XXXX.....X..P......X.P....",
//  "...XX..P..X...X.X..X..X..X..XX.X.XX....XXX....X...",
//  "X.X..XX..XX..XP.......X....X.X.....PX...........XX",
//  "..XXX..X...X.......X....X..X.X..X.XX.X.XX..P.XX...",
//  ".XX.X.PXP......XX.XXXX......XX.....XXXXXX..X..X...",
//  ".XX.......X...X..XXXX.X.XX..........X...XX......X.",
//  ".PX......XXX.XX.XPX..X....XX.X.X...XXP..XX...XX...",
//  "..X..........X..X...X.X.X.X....X.XP....X..PX......",
//  ".X...X.X.........X..........X.XXXXXX.X....X...XXXX",
//  ".X.P..........XX......X.P..P.X.....X..XPX.P..P..XX",
//  "....X......X.XX.XXX.X..PX.XX......X......C.X....XX",
//  ".......X...XX.XPX.X.XX.XC.XX..X...X..X....PXXX....",
//  ".XX..X..X.....X....X...........X.X..XX...X...X....",
//  "X......C...X.X..X....XX.X..........P......X...XP..",
//  ".X.XXXP.XX.X.X..XX.PPX....X.....X..XX......XXCXXX.",
//  "X.XX..........XXXX.......X....X.....P.X.X...X.XP.P",
//  ".XX.X.....X.PXX.XC.X.XXP.....PX.P.........X..X...X",
//  "X........PXX......X......XXPX..P...X..X....X..XP..",
//  "...X.PX....XX...XX....X.X.P......XX.X.X...X...X...",
//  "....X.XX......PX.X.PX..X..XXX.C..X.XPX.X.X....P.XX",
//  ".XXP.XXX.XX.XX...XX.XX.X..XX...X.X.....PX...X..X..",
//  ".X.....X.XXP...X.....X...XXXXX.X.X........X..X.X.X",
//  "X..X...X..XX..P.X.XXX..XXXPX.X...XX...X.X.......X.",
//  ".XXXXXXXX..X....X.X.X.X..........XP.....X.......X.",
//  ".....X.XXXXX..........XP...X....PXX.X...........XX",
//  ".XXX....X......X.....X.XX..X......XXX......XXX..XX",
//  "......X....XX...X.XXX...X..X.P...X.XX...XX.X.X..XX",
//  "X..P..XX.XP.....X.XXXX.X......X...P..X.PXX.XX.....",
//  ".XX...X..X...X......P...X...PXPX.XX....X......X...",
//  "X......X.XX..XXX.X.......XX..X....X.X.X.X.P..XXX.X",
//  "....X.X.X.XX...X.X.XXPX.XX.P.X..X.X.XX.XXX...X....",
//  ".XX.X..X....X....X..XX.XX..P.XX.....XX..XP.X.XXXXX",
//  ".....XXXX..P.XP...X...X...X.XPX.XX........X....XXX",
//  "..X.....XX...X.........X.X.X.....X.X.XX.XXX.......",
//  "X...X......P..P.P..X....P...XX..X.......X.....X.X.",
//  "XX.X....X.X.X.PXX.X..X..XX........X.......XXXX...X",
//  ".X.X..X..X.X.....X.........X..P.X.....X..XX.X.....",
//  ".XX.........X.XX....XX.....XX..XX.XXXXXXXX....XP.X",
//  "X.P...X..XX.XP...X..P.X.X....XP....PXX...X.X...X..",
//  "......XX.XXX...X.....XX.X....XX..P...C.XX.X...X.X.",
//  "..X.....X......X.XC..XXXX......X....X.X......X.XCX",
//  "..XXX..X....X....X..XXXX.X.P...XP.X.X.X.X....X....",
//  "X.....X.X....X..........X..X.XPXXXX.X..X..XX.X.X.X",
//  ".....X..XX..X..XX....X...XX.X.....X.X..XXX.......X",
//  "XXX...XXXX.....X.......XX.X.X.X.X......X.XXXXP....",
//  "..XX..XX.XX..........C...XXPP..XX...X..........XXX",
//  "XP........X..X..X......X.P....XXX.X..P............",
//  "XXX..X.XXX.X...X.X..X...X...X.P...PX..XXXX..X.....",
//  "XX.X.....X..X.XX..X.X..XPXXX...X.P.X.X.X..X.....XX",
//  ".P.........PX........P..X..X.X.X..XX..XX...X..X..."};
// {"P.................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
//  "..................................................",
//  ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
//  "..................................................",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC"};

// cost[i][j]: giá trị ngắn nhất xe i tới bến j
int **cost;
// Hướng di chuyển
int rowNum[4] = {-1, 0, 0, 1};
int colNum[4] = {0, -1, 1, 0};

// Lưu tọa độ
struct Point
{
    int x, y;
};

// Vị trí và khoảng cách
struct queuePoint
{
    Point pt;
    int dist;
};

// Dạng một đường đi. Ở đâu - bao xa - từ đâu
struct Node
{
    int where, cost, from;
    Node(int _where, int _cost, int _from) : where(_where), cost(_cost), from(_from){};
};

// Lưu tọa độ của xe, bãi đậu, tường
vector<Point> car_coor;
vector<Point> parking_coor;
vector<Point> wall_coor;

// Kiểm tra có hợp lệ không
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Định nghĩa so sánh cho priority queue
bool operator<(Node a, Node b)
{
    return a.cost > b.cost;
}

// Tìm đường đi ngắn nhất từ start đến end
int BFS(int **base, Point start, Point end)
{
    // Đánh dấu các vị trí đã đi qua
    bool visited[ROWS][COLS];
    // Gán ban đầu là false hết, chưa đi qua chỗ nào
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            visited[i][j] = false;
        }
    }
    // Gán vị trí start là đã đi qua
    visited[start.x][start.y] = true;
    queue<queuePoint> q;
    // Cho vào queue vị trí ban đầu
    queuePoint s = {start, 0};
    q.push(s);
    // Queue còn thì duyệt
    while (!q.empty())
    {
        // Lấy vị trí đang xét
        queuePoint curr = q.front();
        Point pt = curr.pt;
        // Nếu là vị trí cuối thì trả về kết quả
        if (pt.x == end.x && pt.y == end.y)
            return curr.dist;
        q.pop();
        // Xét các vùng xung quanh
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            // Nếu trong vùng mê cung, là đường đi và chưa đi qua
            if (isValid(row, col) && base[row][col] && !visited[row][col])
            {
                visited[row][col] = true;
                queuePoint Adjcell = {{row, col}, curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
    // Không thấy đường đến trả về INF
    return INF;
}

int minTime()
{

    int D = 0, sink = N + M;

    // car i in car_match[i], park i have park_match[i] car
    int car_match[200], park_match[200];
    // Gán ban đầu không có gì cả
    for (int i = 0; i < 200; i++)
    {
        car_match[i] = -1;
        park_match[i] = -1;
    }

    // Duyệt các xe, mỗi lần 1 xe thì
    for (int source = 1; source >= 0; source--)
    {
        cout << "check car number: " << source << endl;
        // Đã thăm, cái nào đến từ cái nào, bao gồm cả xe lẫn parking slot
        bool visited[400];
        // Đến từ đâu ?
        int from[400];
        for (int i = 0; i < 400; i++)
        {
            visited[i] = false;
            from[i] = -1;
        }

        priority_queue<Node> pq;
        // Push cạnh đang xét, i guess, cạnh where - cost - from
        pq.push(Node(source, 0, -1)); // Xe đầu tiên, cost chưa có, bắt nguồn không có
        // cout << "push (" << source << ", " << 0 << ", " << -1 << ")" << endl;
        while (!pq.empty())
        {
            cout << "checking node: " << pq.top().where << " " << pq.top().cost << " " << pq.top().from << endl;
            // Tiếp tục bây giờ where là bến đỗ đang xét, giá trị, from xe nào
            int cst = pq.top().cost;
            cout << "cst: " << cst << endl;
            int where = pq.top().where;
            cout << "where: " << where << endl;
            int _from = pq.top().from;
            cout << "_from: " << _from << endl;
            pq.pop();
            // Đã xét where thì bỏ qua
            if (visited[where])
                continue;          // kiểm tra xe này đã xét chưa, bến đỗ này xét chưa
            visited[where] = true; // gán là đã xét
            // cout << "visited of " << where << " is true" << endl;
            // where đến từ đâu ?
            from[where] = _from; // gán xe này đến từ from (TH này là -1), bến này từ xe nào
            cout << where << " is from " << from[where] << endl;
            // If where is a car then try all M parking slots
            if (where < N)
            { // Nếu nó là xe thì
                cout << where << " is a car" << endl;
                for (int i = 0; i < M; i++)
                { // Xét các bến đỗ
                    // If the edge doesn't exist or this car is already matched with this parking slot
                    if (cost[where][i] == INF || car_match[where] == i)
                    {
                        // cout << "cant find the way or car " << where << " is already have a place" << endl;
                        if (cost[where][i] == INF)
                            cout << "cant find the way" << endl;
                        else
                            cout << "already have a place" << endl;
                        continue;
                    }
                    int ncst = max(cst, cost[where][i]);
                    // cout << "ncst: " << ncst << endl;
                    // The i-th parking slot is N + i
                    pq.push(Node(N + i, ncst, where)); // Bến đỗ, giá trị từ xe đó đến đó, từ xe nào
                    cout << "push (" << N + i << ", " << ncst << ", " << where << ")" << endl;
                }
            }
            // Nếu là chỗ đỗ xe
            else
            {
                cout << where << " is a parking slot" << endl;
                // Nếu chỗ đỗ trống
                if (park_match[where - N] == -1)
                { // Nếu chỗ đỗ xe này chưa có xe
                    // Nối chỗ đỗ xe tới sink (kiểu cái cạnh)
                    from[sink] = where; // Cho về sink từ cái bến đỗ đấy
                    cout << "sink is from " << where << endl;
                    // Lấy thời gian
                    D = max(D, cst); // Đường đi
                    cout << "D = " << D << endl;
                    break;
                }
                // Không thì lấy xe ở cái chỗ đang xét, xe mà đã ở đó sẵn rồi
                int next = park_match[where - N];
                cout << "next is the car in this place already which is " << park_match[where - N] << endl;
                // So sánh tiếp ?
                int ncst = max(cst, cost[next][where - N]);
                // cout << where << endl;
                // cout << "ncst: " << ncst << " cost: " << cst << endl;
                pq.push(Node(next, ncst, where));
                cout << "push (" << next << ", " << ncst << ", " << where << ")" << endl;
            }
        }
        // where là chỗ đỗ, nối đến sink, nếu không có tức là không đến được, i guess
        int where = from[sink];
        if (where == -1)
            return -1;
        // prev là xe nối đến chỗ đỗ where
        int prev = from[where];
        // Nếu là chỗ đỗ xe thật ?
        if (where >= N)
        {
            // Gán xe với chỗ đỗ với nhau
            car_match[prev] = where;
            park_match[where - N] = prev;
        }
        // Chỗ đỗ xe giờ mang giá trị xe ?
        // where = prev;
    }
    for (int i = 0; i < N; i++)
    {
        cout << "car " << i << " is in parking slot number " << car_match[i] - N << endl;
    }
    for (int i = 0; i < M; i++)
    {
        if (park_match[i] == -1)
            cout << "parking slot number " << i << " has no car" << endl;
        else
            cout << "parking slot number " << i << " have car number " << park_match[i] << endl;
    }
    return D;
}

int main()
{

    ROWS = park.size();
    COLS = park[0].length();
    // Đếm số xe, chỗ đỗ, tường, gán vị trí cho nó
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (park[i][j] == 'C')
            {
                N++;
                car_coor.push_back({i, j});
            }
            if (park[i][j] == 'P')
            {
                M++;
                parking_coor.push_back({i, j});
            }
            if (park[i][j] == 'X')
            {
                wall_coor.push_back({i, j});
            }
        }
    }

    // Cấp phát bảng động
    cost = new int *[N];
    for (int i = 0; i < N; i++)
    {
        cost[i] = new int[M];
    }
    // base cho mê cung
    int **base = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        base[i] = new int[COLS];
    }

    // Gán bảng xét mê cung ban đầu là đường đi hết, rồi cho vị trí tường vào sau
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            base[i][j] = 1;
        }
    }
    for (auto coor : wall_coor)
    {
        base[coor.x][coor.y] = 0;
    }

    // Mê cung từng xe, từng chỗ đỗ
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cost[i][j] = BFS(base, car_coor[i], parking_coor[j]);
            // cout << cost[i][j] << " ";
        }
        // cout << endl;
    }

    // if(minTime() == -1) cout << "It is impossible for each car to drive to a parking place" << endl;
    // else cout << "minimum time is " << minTime();

    cout << minTime();

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Xóa bảng cấp phát
    for (int i = 0; i < N; i++)
    {
        delete[] cost[i];
    }
    delete[] cost;
    for (int i = 0; i < ROWS; i++)
    {
        delete[] base[i];
    }
    delete[] base;
}