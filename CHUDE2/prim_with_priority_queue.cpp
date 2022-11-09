#include<bits/stdc++.h>
#include<queue>
#include<time.h>
using namespace std;

#define N 10000
const int MAX = N + 100;
bool used[N + 1]; // = used[i] = true -> i thuoc cay khung
int index = 0;
int parent[N + 1], d[N + 1];

struct Edge{

	int u, v, weight;
};


void generate_graph(Edge *mt) {

    int **temp = new int *[N];
    for(int i = 0; i < N; i++) {
        temp[i] = new int [N];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(i > j) {
                mt[index].u = i;
                mt[index].v = j;
                mt[index].weight = temp[j][i];
                index++;
            }
            else {
                mt[index].u = i;
                mt[index].v = j;
                mt[index].weight = rand() % (N - 1 + 1) + 1;
                temp[i][j] = mt[index].weight;
                index++;
            }
        }
    }
}

void prim_no_priority(int u,Edge *mt) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<Edge> MST;
    int sum = 0;
    Q.push({0, u});
    while(!Q.empty()) {

        pair<int, int> top = Q.top();
        Q.pop();
        int vertex = top.second;
        int weight = top.first;

        if(used[vertex]) continue;
        sum += weight;
        used[vertex] = true;
        // khong xet dinh dau tien 
        if(u != vertex) {
            MST.push_back({vertex, parent[vertex], weight});
        }
        for(int j = 0; j < N - 1; j++) {
            int Y = mt[vertex * N - vertex + j].v;
            int W = mt[vertex * N - vertex + j].weight;
            if(!used[Y] && W < d[Y]) {

                Q.push({W, Y});
                d[Y] = W;
                parent[Y] = vertex;
            }
        }
    }
    cout << sum << endl;
}

int main() {

	clock_t start, end;
	double time_use_1, time_use_2;

    memset(used, false, sizeof(used));
    memset(d, MAX, sizeof(d));

	Edge *graph = new Edge[N * N];

	generate_graph(graph);
    start = clock();
    prim_no_priority(0, graph);
    end = clock();
    time_use_1 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << time_use_1;
	delete []graph;

}