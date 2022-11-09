#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define N 1000
int parent_for_DSU[N + 1];
int size[N + 1];
int index = 0;

struct Edge{

    int u, v;
    int weight;
};

// khoi tao ngau nhien do thi day du
void generate_graph(Edge *mt) {

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
                // mt[index].u = i;
                // mt[index].v = j;
                // mt[index].weight = temp[j][i];
                // index++;
                continue;
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
    for(int i = 0; i < index; i++) {

        if(find_set(mt[i].u) != find_set(mt[i].v)) {

            min_cost += mt[i].weight;
            //cout << "Edge " << edge_count++ << ": " << mt[i].u << "-" << mt[i].v << ": " << mt[i].weight << endl;
            union_set(mt[i].u, mt[i].v);
        }
    }
    cout << "MST cost: " << min_cost << endl;
}

int main() {

    clock_t start, end;
    double time_kruskal_DSU, time_sort;
    Edge *graph_for_kruskal = new Edge[N * N];

    generate_graph(graph_for_kruskal);

    start = clock();
    sort(graph_for_kruskal, graph_for_kruskal + index + 1, cmp);
    end = clock();
    time_sort = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    kruskal_DSU(graph_for_kruskal);
    end = clock();
    time_kruskal_DSU = (double)(end - start) / CLOCKS_PER_SEC;

    delete []graph_for_kruskal;
    cout << "DSU time: " << time_kruskal_DSU + time_sort;
}