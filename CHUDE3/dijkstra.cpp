#include <iostream>
#include <time.h>
using namespace std;

#define N 1000
const int MAX = N*N + 100;
int index = 0;

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
                mt[index].weight = rand() % (N - 10 + 1) + 10;
                temp[i][j] = mt[index].weight;
                index++;
            }
        }
    }
}

// Chọn đường đi ngắn nhất từ đỉnh 
int minDistance(int dist[], bool sptSet[]) {

	// Khai báo giá trị 
	int min = MAX, min_index;

	for (int v = 0; v < N; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[]) {

	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < N; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(Edge *graph, int src) {

    // Mảng dist lưu giá trị đường đi ngắn nhất từ source cho tới điểm i 
	int dist[N];

    // sptSet trả về true nếu điểm i đã được set 
	bool sptSet[N];

    // gán giá trị cho mọi điểm là MAX và chưa sử dụng điểm đấy 
	for (int i = 0; i < N; i++)
		dist[i] = MAX, sptSet[i] = false;

	// Khoảng cách từ nguồn tới chính nó luôn bằng 0 
	dist[src] = 0;

	// Tìm đường ngắn nhất cho tất cả các đỉnh 
	for (int count = 0; count < N - 1; count++) {

		// Chọn đường đi ngắn nhất từ cái đỉnh đang xét 
        // Giá trị ban đầu luôn luôn là từ source 
		int u = minDistance(dist, sptSet);

		// Đánh dấu điểm đã đi qua 
		sptSet[u] = true;

		// Update các giá trị 
		for (int v = 0; v < N - 1; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[graph[u * N - u + v].v]
				&& dist[graph[u * N - u + v].u] != MAX
				&& dist[graph[u * N - u + v].u] + graph[u * N - u + v].weight < dist[graph[u * N - u + v].v])
				dist[graph[u * N - u + v].v] = dist[graph[u * N - u + v].u] + graph[u * N - u + v].weight;
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main() {

	Edge *graph = new Edge[N * N];
    generate_graph(graph);

	dijkstra(graph, 0);

	delete []graph;
}
