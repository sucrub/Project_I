#include<bits/stdc++.h>
#include<time.h>
#include<limits.h>
using namespace std;

// So luong dinh
#define N 8
int graph[N][N];
// Kiem tra do thi co dung khong
bool valid = false;

// Sinh do thi co huong ngau nhien
void create_graph() {

    srand(time(NULL)); 
    // Mac dinh ban dau la 0
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }
    // Random cac gia tri, tru dinh dich k co duong nao truyen di
    for(int i = 0; i < N - 1; i++) {
        for(int j = 1; j < N; j++) {
            if(graph[j][i] == 0 && i != j) {
                if(rand() % 2) {
                    graph[i][j] = rand() % (10 - 1 + 1) + 1;
                }
            }
        }
    }
}

// Kiem tra do thi co di den duoc dich hay khong
void check_valid_graph(int u) {

    for(int i = 0; i < N; i++) {
        if(graph[u][i] == 0) continue;
        if(i == N - 1 && graph[u][i] != 0) {
            valid = true;
            break;
        }
        if(u == N) break;
        check_valid_graph(u + 1);      
    }
}

void print_graph() {

    cout << "##############################" << endl;
    cout << "Graph: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] != 0) cout << i << " -> " << j << ": " << graph[i][j] << endl;
        }
    }
    cout << "##############################" << endl;
}

bool bfs(int rGraph[N][N], int parent[N]) {

    bool visited[N];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < N; v++) {
            if(visited[v] == false && rGraph[u][v] > 0) {

                if(v == N - 1) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;

}

int emonds_Karp() {

    int u, v;
    int rGraph[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }

    int parent[N];

    int max_flow = 0;

    while(bfs(rGraph, parent)) {
        int path_flow = INT_MAX;
        // tìm ngược lại đường đi
        for(v = N - 1; v != 0; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for(v = N - 1; v != 0; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

// Edmonds_Karp


int main() {

    while(!valid) {
        create_graph();
        check_valid_graph(0);
    }
    print_graph();
    cout << "Max flow: " << emonds_Karp();

}