#include<bits/stdc++.h>
using namespace std;

#define INF 1000000
#define ROWS 6
#define COLS 12
// Số xe
#define N 2
// Số chỗ đỗ
#define M 6
vector<string> park =   {"XXXXXXXXXXP",
                        "X......XPPX",
                        "XC...P.XPPX",
                        "X......X..X",
                        "X....C....X",
                        "XXXXXXXXXXX"};

int cost[N][M];
int rowNum[4] = {-1, 0, 0, 1};
int colNum[4] = {0, -1, 1, 0};

struct Point {
    int x, y;
};

struct queueNode {
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

int BFS(int base[][COLS], Point start, Point end) {
    bool visited[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    visited[start.x][start.y] = true;
    queue<queueNode> q;
    queueNode s = {start, 0};
    q.push(s);
    while(!q.empty()) {
        queueNode curr = q.front();
        Point pt = curr.pt;
        if(pt.x == end.x && pt.y == end.y)
            return curr.dist;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if(isValid(row, col) && base[row][col] && !visited[row][col]) {
                visited[row][col] = true;
                queueNode Adjcell = {{row, col}, curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
    return INF;
}


int main() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(park[i][j] == 'C') {
                car_coor.push_back({i, j});
            }
            if(park[i][j] == 'P') {
                parking_coor.push_back({i, j});
            }
            if(park[i][j] == 'X') {
                wall_coor.push_back({i, j});
            }
        }
    }
    // for(auto x : wall_coor) {
    //     cout << x.x << " " << x.y << endl;
    // }
    int base[ROWS][COLS];
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
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}