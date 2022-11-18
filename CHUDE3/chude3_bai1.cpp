#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define N 10000
int index = 0;
int check_solution = 0;

// Mảng dist lưu giá trị đường đi ngắn nhất từ source cho tới điểm i 
long long dist_no_priority[N];
long long dist_priority[N];
// trả về true nếu điểm i đã được set 
bool check_no_priority[N];

struct Edge {

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
                mt[index].weight = rand() % (1000 - 100 + 1) + 100; // random tu 200 - 100
                temp[i][j] = mt[index].weight;
                index++;
            }
        }
    }
}

// Chọn đường đi ngắn nhất từ đỉnh 
int minDistance() {

	// Khai báo giá trị 
	int min = 5000, min_index;

	for (int v = 0; v < N; v++)
		if (check_no_priority[v] == false && dist_no_priority[v] <= min)
			min = dist_no_priority[v], min_index = v;

	return min_index;
}

void printSolution() {

	cout << "Vertex \t No Priority \t Priority" << endl;
	for (int i = 0; i < N; i++) {
		cout << i << "\t\t" << dist_no_priority[i] << "\t\t" << dist_priority[i] << endl;
		if(dist_no_priority[i] != dist_priority[i]) check_solution = 1;
	}
	if(check_solution == 0) cout << "Same answer!" << endl;
	else cout << "Wrong answer!" << endl;
}

void dijkstra_priority(Edge *graph) {
	dist_priority[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, 0});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second; // diem thu 2
		int weight = top.first; //weight
		if(weight > dist_priority[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(int i = 0; i < N - 1; i++) {
			int v = graph[u * N - u + i].v;
			int w = graph[u * N - u + i].weight;
			if(dist_priority[v] > dist_priority[u] + w) {
				dist_priority[v] = dist_priority[u] + w;
				Q.push({dist_priority[v], v});
			}
		}
	}
}

void dijkstra_no_priority(Edge *graph) {

	// Khoảng cách từ nguồn tới chính nó luôn bằng 0 
	dist_no_priority[0] = 0;

	// Tìm đường ngắn nhất cho tất cả các đỉnh 
	for (int count = 0; count < N - 1; count++) {

		// Chọn đường đi ngắn nhất từ cái đỉnh đang xét 
        // Giá trị ban đầu luôn luôn là từ source 
		int u = minDistance();

		// Đánh dấu điểm đã đi qua 
		check_no_priority[u] = true;

		// Update các giá trị 
		for (int v = 0; v < N - 1; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!check_no_priority[graph[u * N - u + v].v]
				&& dist_no_priority[graph[u * N - u + v].u] != 5000
				&& dist_no_priority[graph[u * N - u + v].u] + graph[u * N - u + v].weight < dist_no_priority[graph[u * N - u + v].v])
				dist_no_priority[graph[u * N - u + v].v] = dist_no_priority[graph[u * N - u + v].u] + graph[u * N - u + v].weight;
	}

	// print the constructed distance array
}

// driver's code
int main() {

    clock_t start, end;
    double time_no_priority, time_priority;

	for(int i = 0; i < N; i++) {
		dist_no_priority[i] = 5000;
		dist_priority[i] = 5000;
		check_no_priority[i] = false;
	}

	Edge *graph = new Edge[N * N];
    generate_graph(graph);

    start = clock();
	dijkstra_no_priority(graph);
    end = clock();
    time_no_priority = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	dijkstra_priority(graph);
    end = clock();
    time_priority = (double)(end - start) / CLOCKS_PER_SEC;

	printSolution();

    cout << "Time with no priority: " << time_no_priority << endl 
		<< "Time with priority: " << time_priority;

	delete []graph;
}
