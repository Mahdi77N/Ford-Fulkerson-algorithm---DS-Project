#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
#include "queue.h"

using namespace std;

bool bfs(vector<vector<int>> rGraph, int number, int s, int t, int parent[])
{
	bool visited[number];
	memset(visited, 0, sizeof(visited));
	Queue q(number);

	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int u = q.Front();
		q.pop();
		for(int v = 0; v < number; v++) {
			if(visited[v] == false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return (visited[t] == true);
}

int fordFulkerson(vector<vector<int>> graph, int number, int s, int t)
{
	int u, v;
	vector<vector<int>> rGraph(number);
	for(u = 0; u < number; u++) {
		rGraph[u] = vector<int>(number);
		for(v = 0; v < number; v++) {
			rGraph[u][v] = graph[u][v];
		}
	}

	int parent[number];
	int max_flow = 0;

	while(bfs(rGraph, number, s, t, parent)) {
		int path_flow = INT8_MAX;
		vector<int> vec;
		for(v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
			vec.push_back(v);
		}

		vec.push_back(s);
		for(int k = vec.size() - 1; k >= 0; k--) {
			cout << vec[k] + 1;
			if(k != 0)
				cout << " -> ";
		}
		vec.clear();
		cout << " : " << path_flow << endl;

		for(v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}

	return max_flow;
}

void display(vector<vector<int>> graph, int number)
{
	for(int i = 0; i < number; i++)
		for(int j = 0; j < number; j++)
			if(graph[i][j] != 0)
				cout << "(" << i + 1 << ")" << " --> " << "(" << j + 1 << ")" << " ~ weight = " << graph[i][j] << endl;
}

void cls()
{
	//Clear Screen :)
	cout << "\033[2J\033[1;1H";
}

void delay(int seconds)
{
	clock_t endwait; 
	endwait = clock() + (seconds * CLOCKS_PER_SEC); 
	while(clock() < endwait) {} 
}

int main()
{
	int number;
	cout << "Enter number of nodes : ";
	cin >> number;

	vector<vector<int>> graph(number);
	for(int i = 0; i < number; i++)
		graph[i] = vector<int>(number);
	
	cout << endl << "Now Enter weight of edges :" << endl;
	int s, d, weight;
	while(1) {
		cin >> s >> d >> weight;
		if(s == 0 && d == 0 && weight == 0)
			break; 
		graph[--s][--d] = weight;
	}
	cout << endl << "Proximity matrix is constructed :)" << endl;
	delay(2);
	cls();

	int source, sink;
	cout << "Enter source node's number : ";
	cin >> source;
	cout << "Enter sink node's number : ";
	cin >> sink;
	cls();

	cout << "Your Graph :" << endl << endl;
	display(graph, number);
	cout << endl;
	cout << "******************************" << endl << endl;

	int ans = fordFulkerson(graph, number, --source, --sink);
	cout << endl << "Maximum flow = " << ans << endl;

	return 0;
}