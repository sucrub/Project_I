#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define N 1000
int parent_for_non_DSU[N + 1];
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
void make_set_for_non_DSU() {
    for(int i = 0; i < N; i++) {
        parent_for_non_DSU[i] = i;
    }
}

//cmp
bool cmp(Edge a, Edge b) {

    return a.weight < b.weight;
}

/////


//////////////////////////////////////////////////
//O(ElogV + V^2)
void kruskal_non_DSU(Edge *mt) {

    int min_cost = 0;
    make_set_for_non_DSU();
    int edge_count = 0;
    for(int i = 0; i < index; i++) {

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
    cout << "MST cost: " << min_cost << endl;
}

int main() {

    clock_t start, end;
    double time_kruskal_non_DSU, time_sort;
    Edge *graph_for_kruskal = new Edge[N * N];

    generate_graph(graph_for_kruskal);

    start = clock();
    sort(graph_for_kruskal, graph_for_kruskal + index + 1, cmp);
    end = clock();
    time_sort = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    kruskal_non_DSU(graph_for_kruskal);
    end = clock();
    time_kruskal_non_DSU = (double)(end - start) / CLOCKS_PER_SEC;

    delete []graph_for_kruskal;
    cout << "Non DSU time: " << time_kruskal_non_DSU + time_sort << endl;
}