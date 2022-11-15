#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define N 100
const int MAX = N + 100;
bool used_no_priority[N + 1];
bool used_priority[N + 1]; // = used[i] = true -> i thuoc cay khung
int parent[N + 1], d[N + 1];
int index = 0;

struct Edge{

	int u, v, weight;
};

void generate_graph(Edge *mt) {

    srand(time(NULL)); 

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

//O(V^3)
void prim_no_priority(int u, Edge *mt) {

    vector<Edge> MST;
    int d = 0; //chieu dai cay khung
    used_no_priority[u] = true;
    while(MST.size() < N - 1) {

        int min_w = MAX;
        int X, Y;

        // duyet cac dinh
        // kiem tra dinh da used chua
        // duyet tiep cac dinh ke (use some math here Bach, think !)
        // neu dinh chua used va weight min thi luu bien do
        // them vao cay, dinh do thanh da used
        for(int i = 0; i < N; i++) {  

            if(used_no_priority[i]) {

                // for(pair<int, int> it : adj[i]) {

                //     int j = it.first, weight = it.second;
                //     if(!used[j] && weight < min_w) {

                //         min_w = weight;
                //         X = j;
                //         Y = i;
                //     }
                // }
//////something is wrong here
                for(int j = 0; j < N - 1; j++) {

                    if(!used_no_priority[mt[j + i * N - i].v] && mt[j + i * N - i].weight < min_w) {

                        min_w = mt[j + i * N - i].weight;
                        X = mt[j + i * N - i].v;
                        Y = i;

                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used_no_priority[X] = true;
    }
    cout << d << endl;
    // for(Edge e : MST) {
    //     cout << e.u << " " << e.v << " " << e.weight << endl;
    // }
}

void prim_priority(int u,Edge *mt) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<Edge> MST;
    int sum = 0;
    Q.push({0, u});
    while(!Q.empty()) {

        pair<int, int> top = Q.top();
        Q.pop();
        int vertex = top.second;
        int weight = top.first;

        if(used_priority[vertex]) continue;
        sum += weight;
        used_priority[vertex] = true;
        if(u != vertex) {
            MST.push_back({vertex, parent[vertex], weight});
        }
        for(int j = 0; j < N - 1; j++) {
            int Y = mt[vertex * N - vertex + j].v;
            int W = mt[vertex * N - vertex + j].weight;
            if(!used_priority[Y] && W < d[Y]) {

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
	double time_prim_no_priority, time_prim_priority;

    memset(used_no_priority, false, sizeof(used_no_priority));
    memset(used_priority, false, sizeof(used_priority));
    memset(d, MAX, sizeof(d));

	Edge *graph_for_prim = new Edge[N * N];

	generate_graph(graph_for_prim);

    start = clock();
    prim_no_priority(0, graph_for_prim);
    end = clock();
    time_prim_no_priority = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    prim_priority(0, graph_for_prim);
    end = clock();
    time_prim_priority = (double)(end - start) / CLOCKS_PER_SEC;

    cout << time_prim_no_priority << endl << time_prim_priority;
	delete []graph_for_prim;

}