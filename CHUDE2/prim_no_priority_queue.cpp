#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define N 100
const int MAX = N + 100;
bool used[N + 1]; // = used[i] = true -> i thuoc cay khung
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
    used[u] = true;
    while(MST.size() < N - 1) {

        int min_w = MAX;
        int X, Y;

        // duyet cac dinh
        // kiem tra dinh da used chua
        // duyet tiep cac dinh ke (use some math here Bach, think !)
        // neu dinh chua used va weight min thi luu bien do
        // them vao cay, dinh do thanh da used
        for(int i = 0; i < N; i++) {  

            if(used[i]) {
                for(int j = 0; j < N - 1; j++) {

                    if(!used[mt[j + i * N - i].v] && mt[j + i * N - i].weight < min_w) {

                        min_w = mt[j + i * N - i].weight;
                        X = mt[j + i * N - i].v;
                        Y = i;

                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;
    }
    cout << "MST: " << d << endl;
    // for(Edge e : MST) {
    //     cout << e.u << " " << e.v << " " << e.weight << endl;
    // }
}

int main() {

	clock_t start, end;
	double time_use_1, time_use_2;

    memset(used, false, sizeof(used));

	Edge *graph = new Edge[N * N];

	generate_graph(graph);
    start = clock();
    prim_no_priority(0, graph);
    end = clock();
    time_use_1 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << time_use_1;
	delete []graph;

}