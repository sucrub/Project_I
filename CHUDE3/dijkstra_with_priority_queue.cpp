#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define N 1000				// số đỉnh
int index = 0;				// số cạnh trong quá trình tạo đồ thị
long long dist_priority[N]; // Khoảng cách từ nguồn tới đỉnh đó

struct Edge
{

	int u, v, weight;
};

void generate_graph(Edge *mt)
{

	int **temp = new int *[N];
	for (int i = 0; i < N; i++)
	{
		temp[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			if (i > j)
			{
				mt[index].u = i;
				mt[index].v = j;
				mt[index].weight = temp[j][i];
				index++;
			}
			else
			{
				mt[index].u = i;
				mt[index].v = j;
				mt[index].weight = rand() % (N - 10 + 1) + 10;
				temp[i][j] = mt[index].weight;
				index++;
			}
		}
	}
}

void dijkstra_priority(Edge *graph)
{
	dist_priority[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, 0});
	while (!Q.empty())
	{
		// Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
		pair<int, int> top = Q.top();
		Q.pop();
		int u = top.second;			   // diem thu 2
		int weight = top.first;		   // weight
		if (weight > dist_priority[u]) // nếu lớn hơn khoảng cách từ nguồn tới đỉnh đó thì bỏ
			continue;
		// Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		// nhật khoảng cách với các đỉnh kề với u
		for (int i = 0; i < N - 1; i++)
		{
			int v = graph[u * N - u + i].v;
			int w = graph[u * N - u + i].weight;
			if (dist_priority[v] > dist_priority[u] + w)
			{
				dist_priority[v] = dist_priority[u] + w;
				Q.push({dist_priority[v], v});
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << dist_priority[i] << endl;
	}
}

int main()
{

	clock_t start, end;
	double time;

	for (int i = 0; i < N; i++)
	{
		dist_priority[i] = 2000;
	}

	Edge *graph = new Edge[N * N];
	generate_graph(graph);

	start = clock();
	dijkstra_priority(graph);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << time;
	delete[] graph;
}