#include<bits/stdc++.h>
using namespace std;

#define INF 1000000
int ROWS, COLS, N = 0, M = 0;

vector<string> park = 
{"P.....P...X.XX.X.X..X...XXXX.....X..P......X.P....", 
"...XX..P..X...X.X..X..X..X..XX.X.XX....XXX....X...", 
"X.X..XX..XX..XP.......X....X.X.....PX...........XX", 
"..XXX..X...X.......X....X..X.X..X.XX.X.XX..P.XX...", 
".XX.X.PXP......XX.XXXX......XX.....XXXXXX..X..X...", 
".XX.......X...X..XXXX.X.XX..........X...XX......X.", 
".PX......XXX.XX.XPX..X....XX.X.X...XXP..XX...XX...", 
"..X..........X..X...X.X.X.X....X.XP....X..PX......", 
".X...X.X.........X..........X.XXXXXX.X....X...XXXX", 
".X.P..........XX......X.P..P.X.....X..XPX.P..P..XX", 
"....X......X.XX.XXX.X..PX.XX......X......C.X....XX", 
".......X...XX.XPX.X.XX.XC.XX..X...X..X....PXXX....", 
".XX..X..X.....X....X...........X.X..XX...X...X....", 
"X......C...X.X..X....XX.X..........P......X...XP..", 
".X.XXXP.XX.X.X..XX.PPX....X.....X..XX......XXCXXX.", 
"X.XX..........XXXX.......X....X.....P.X.X...X.XP.P", 
".XX.X.....X.PXX.XC.X.XXP.....PX.P.........X..X...X", 
"X........PXX......X......XXPX..P...X..X....X..XP..", 
"...X.PX....XX...XX....X.X.P......XX.X.X...X...X...", 
"....X.XX......PX.X.PX..X..XXX.C..X.XPX.X.X....P.XX", 
".XXP.XXX.XX.XX...XX.XX.X..XX...X.X.....PX...X..X..", 
".X.....X.XXP...X.....X...XXXXX.X.X........X..X.X.X", 
"X..X...X..XX..P.X.XXX..XXXPX.X...XX...X.X.......X.", 
".XXXXXXXX..X....X.X.X.X..........XP.....X.......X.", 
".....X.XXXXX..........XP...X....PXX.X...........XX", 
".XXX....X......X.....X.XX..X......XXX......XXX..XX", 
"......X....XX...X.XXX...X..X.P...X.XX...XX.X.X..XX", 
"X..P..XX.XP.....X.XXXX.X......X...P..X.PXX.XX.....", 
".XX...X..X...X......P...X...PXPX.XX....X......X...", 
"X......X.XX..XXX.X.......XX..X....X.X.X.X.P..XXX.X", 
"....X.X.X.XX...X.X.XXPX.XX.P.X..X.X.XX.XXX...X....", 
".XX.X..X....X....X..XX.XX..P.XX.....XX..XP.X.XXXXX", 
".....XXXX..P.XP...X...X...X.XPX.XX........X....XXX", 
"..X.....XX...X.........X.X.X.....X.X.XX.XXX.......", 
"X...X......P..P.P..X....P...XX..X.......X.....X.X.", 
"XX.X....X.X.X.PXX.X..X..XX........X.......XXXX...X", 
".X.X..X..X.X.....X.........X..P.X.....X..XX.X.....", 
".XX.........X.XX....XX.....XX..XX.XXXXXXXX....XP.X", 
"X.P...X..XX.XP...X..P.X.X....XP....PXX...X.X...X..", 
"......XX.XXX...X.....XX.X....XX..P...C.XX.X...X.X.", 
"..X.....X......X.XC..XXXX......X....X.X......X.XCX", 
"..XXX..X....X....X..XXXX.X.P...XP.X.X.X.X....X....", 
"X.....X.X....X..........X..X.XPXXXX.X..X..XX.X.X.X", 
".....X..XX..X..XX....X...XX.X.....X.X..XXX.......X", 
"XXX...XXXX.....X.......XX.X.X.X.X......X.XXXXP....", 
"..XX..XX.XX..........C...XXPP..XX...X..........XXX", 
"XP........X..X..X......X.P....XXX.X..P............", 
"XXX..X.XXX.X...X.X..X...X...X.P...PX..XXXX..X.....", 
"XX.X.....X..X.XX..X.X..XPXXX...X.P.X.X.X..X.....XX", 
".P.........PX........P..X..X.X.X..XX..XX...X..X..."};	
// {"P.................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.", 
// "..................................................", 
// ".XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 
// "..................................................", 
// "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC"};

int **cost;
int rowNum[4] = {-1, 0, 0, 1};
int colNum[4] = {0, -1, 1, 0};

struct Point {
    int x, y;
};

struct queuePoint {
    Point pt;
    int dist;
};

struct Node {
    int where, cost, from;
    Node(int _where, int _cost, int _from): where(_where), cost(_cost), from(_from) {};
};

vector<Point> car_coor;
vector<Point> parking_coor;
vector<Point> wall_coor;

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

bool operator < (Node a, Node b) {
    return a.cost > b.cost;
}

int BFS(int **base, Point start, Point end) {
    bool visited[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    visited[start.x][start.y] = true;
    queue<queuePoint> q;
    queuePoint s = {start, 0};
    q.push(s);
    while(!q.empty()) {
        queuePoint curr = q.front();
        Point pt = curr.pt;
        if(pt.x == end.x && pt.y == end.y)
            return curr.dist;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if(isValid(row, col) && base[row][col] && !visited[row][col]) {
                visited[row][col] = true;
                queuePoint Adjcell = {{row, col}, curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
    return INF;
}

int minTime() {
    int D = 0, sink = N + M;
    int car_match[105], park_match[105];
    for(int i = 0; i < 105; i++) {
        car_match[i] = -1;
        park_match[i] = -1;
    }
    for(int source = 0; source < N; source++) {
        bool visited[210];
        int from[210];
        for(int i = 0; i < 210; i++) {
            visited[i] = false;
            from[i] = -1;
        }
        priority_queue<Node> pq;
        pq.push(Node(source, 0, -1));
        while(!pq.empty()) {
            int cst = pq.top().cost;
            int where = pq.top().where;
            int _from = pq.top().from;
            pq.pop();
            if(visited[where]) continue;
            visited[where] = true;
            from[where] = _from;
            // If where is a car then try all M parking slots
            if(where < N) {
                for(int i = 0; i < M; i++) {
                    // If the edge doesn't exist or this car is already matched with this parking slot
                    if(cost[where][i] == INF || car_match[where] == i) continue;
                    int ncst = max(cst, cost[where][i]);
                    // The i-th parking slot is N + i
                    pq.push(Node(N + i, ncst, where));
                }
            }
            else {
                if(park_match[where - N] == -1) {
                    from[sink] = where;
                    D = max(D, cst);
                    break;
                }
                int next = park_match[where - N];
                int ncst = max(cst, cost[next][where]);
                pq.push(Node(next, ncst, where));
            }
        }
        int where = from[sink];
        if (where == -1) return -1;
        int prev = from[where];
        if (where >= N) {
            car_match[prev] = where;
            park_match[where - N] = prev;
        }
        where = prev;

    }
    return D;
}

int main() {

    ROWS = park.size();
    COLS = park[0].length();
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(park[i][j] == 'C') {
                N++;
                car_coor.push_back({i, j});
            }
            if(park[i][j] == 'P') {
                M++;
                parking_coor.push_back({i, j});
            }
            if(park[i][j] == 'X') {
                wall_coor.push_back({i, j});
            }
        }
    }
    cost = new int *[N];
    for(int i = 0; i < N; i++) {
        cost[i] = new int [M];
    }
    // for(auto x : wall_coor) {
    //     cout << x.x << " " << x.y << endl;
    // }
    int **base = new int *[ROWS];
    for(int i = 0; i < ROWS; i++) {
        base[i] = new int[COLS];
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            base[i][j] = 1;
        }
    }
    for(auto coor : wall_coor) {
        base[coor.x][coor.y] = 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cost[i][j] = BFS(base, car_coor[i], parking_coor[j]);
            // cout << cost[i][j] << " ";
        }
        // cout << endl;
    }
    cout << minTime();
}