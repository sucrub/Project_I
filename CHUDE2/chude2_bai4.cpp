#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define N 1000
const int MAX = N + 100;
// phân loại để xét chu kỳ
int parent_for_DSU[N + 1];
int parent_for_non_DSU[N + 1];
int size[N + 1];
// số cạnh
int index_kruskal = 0;
int index_prim = 0;
bool used_no_priority[N + 1];
bool used_priority[N + 1]; // = used[i] = true -> i thuoc cay khung
int parent[N + 1], d[N + 1];

struct Edge{

    int u, v, weight;
};

// khoi tao ngau nhien do thi day du
void generate_graph(Edge *kruskal, Edge *prim) {

    srand(time(NULL)); 

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         if (i >= j)
    //             continue;
    //         else if (i < j) {
    //             mt[index].u = i;
    //             mt[index].v = j;
    //             mt[index].weight = mt[j * N - j + i];
    //             index++;
    //         }
    //         else {
    //             mt[index].u = i;
    //             mt[index].v = j;
    //             mt[index].weight = rand() % (N - 1 + 1) + 1;
    //             index++;
    //         }
    //     }
    //}

    int **temp = new int *[N];
    for(int i = 0; i < N; i++) {
        temp[i] = new int [N];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(i > j) {
                prim[index_prim].u = i;
                prim[index_prim].v = j;
                prim[index_prim].weight = temp[j][i];
                index_prim++;
            }
            else {
                kruskal[index_kruskal].u = i;
                kruskal[index_kruskal].v = j;
                kruskal[index_kruskal].weight = rand() % (N - 1 + 1) + 1;
                temp[i][j] = kruskal[index_kruskal].weight;
                prim[index_prim].u = kruskal[index_kruskal].u;
                prim[index_prim].v = kruskal[index_kruskal].v;
                prim[index_prim].weight = kruskal[index_kruskal].weight;
                index_kruskal++;
                index_prim++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        delete []temp[i];
    }
    delete []temp;
}

/// DSU
void make_set_for_DSU() {
    for(int i = 0; i < N; i++) {
        parent_for_DSU[i] = i;
        size[i] = 1;
    }
}

void make_set_for_non_DSU() {
    for(int i = 0; i < N; i++) {
        parent_for_non_DSU[i] = i;
    }
}

//cmp
bool cmp(Edge a, Edge b) {

    return a.weight < b.weight;
}

int find_set(int i) {

    if(i == parent_for_DSU[i])
        return i;
    return parent_for_DSU[i] = find_set(parent_for_DSU[i]);
}

void union_set(int a, int b) {

    a = find_set(a);
    b = find_set(b);
    if(a != b) {

        if(size[a] < size[b]) {
            parent_for_DSU[a] = b;
            size[b] += size[a];
        }
        else {
            parent_for_DSU[b] = a;
            size[a] += size[b];
        }
    }
}

/////


//////////////////////////////////////////////////
//O(ElogV + E + V)
void kruskal_DSU(Edge *mt) {

    int min_cost = 0;
    make_set_for_DSU();
    int edge_count = 0;
    for(int i = 0; i < index_kruskal; i++) {

        if(find_set(mt[i].u) != find_set(mt[i].v)) {

            min_cost += mt[i].weight;
            //cout << "Edge " << edge_count++ << ": " << mt[i].u << "-" << mt[i].v << ": " << mt[i].weight << endl;
            union_set(mt[i].u, mt[i].v);
        }
    }
    cout << min_cost << endl;
}

//O(ElogV + V^2)
void kruskal_non_DSU(Edge *mt) {

    int min_cost = 0;
    make_set_for_non_DSU();
    int edge_count = 0;
    for(int i = 0; i < index_kruskal; i++) {

        if(parent_for_non_DSU[mt[i].u] != parent_for_non_DSU[mt[i].v]) { 

            min_cost += mt[i].weight;
            //cout << "Edge " << edge_count++ << ": " << mt[i].u << "-" << mt[i].v << ": " << mt[i].weight << endl;
            int old_parent = parent_for_non_DSU[mt[i].u];
            int new_parent = parent_for_non_DSU[mt[i].v];
            for(int j = 0; j < N; j++) {

                if(parent_for_non_DSU[j] == old_parent)
                    parent_for_non_DSU[j] = new_parent;
            }
        }
    }
    cout << min_cost << endl;
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
    double time_kruskal_non_DSU, time_kruskal_DSU, time_sort;
    double time_prim_no_priority, time_prim_priority;

    Edge *graph_for_kruskal = new Edge[N * N];
    Edge *graph_for_prim = new Edge[N * N];

    memset(used_no_priority, false, sizeof(used_no_priority));
    memset(used_priority, false, sizeof(used_priority));
    memset(d, MAX, sizeof(d));

    generate_graph(graph_for_kruskal, graph_for_prim);

    start = clock();
    sort(graph_for_kruskal, graph_for_kruskal + index_kruskal + 1, cmp);
    end = clock();
    time_sort = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    kruskal_non_DSU(graph_for_kruskal);
    end = clock();
    time_kruskal_non_DSU = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    kruskal_DSU(graph_for_kruskal);
    end = clock();
    time_kruskal_DSU = (double)(end - start) / CLOCKS_PER_SEC;

    delete []graph_for_kruskal;

    start = clock();
    prim_no_priority(0, graph_for_prim);
    end = clock();
    time_prim_no_priority = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    prim_priority(0, graph_for_prim);
    end = clock();
    time_prim_priority = (double)(end - start) / CLOCKS_PER_SEC;

    delete []graph_for_prim;
    
    cout << "Non DSU time: " << time_kruskal_non_DSU + time_sort << endl <<  "DSU time: " << time_kruskal_DSU + time_sort << endl;
    cout << "No priority time: " << time_prim_no_priority << endl << "Priority time: " << time_prim_priority << endl;;
}