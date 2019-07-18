//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

void printArray(int *dist, int n)
{
	printf("printing array\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", dist[i]);
	printf("\n");
}

int minDistance(int *dist, bool *visited, int n)
{
	int min = INT_MAX, min_index = -1;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i] && min > dist[i])
		{
			min = dist[i]; 
			min_index = i;
		}
	}
	return min_index;
}

void findDistance(int *W, list<int> *adj, int src, int n)
{
	bool *visited = new bool[n];
	int *dist = new int[n], max,  max_index;
	list<int>::iterator itr;
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	for(int i = 0; i < n; i++)
	{
		int u = minDistance(dist, visited, n);
		visited[u] = true;
		if(dist[u] > max)
			max = dist[u], max_index = u;
		for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
			if(!visited[*itr] && W[u*n + *itr] && dist[*itr] > W[u*n + *itr] && dist[*itr] > dist[u])
				if(dist[u] > W[u*n + *itr])
					dist[*itr] = dist[u];
				else
					dist[*itr] = W[u*n + *itr];
	}
	//printArray(dist, n);
	printf("%d\n", max);
	return;
}

int main()
{
	int n, m, k, u, v, w;
	cin>>n>>m>>k;
	int W[n][n];
	list<int> *adj;
	adj = new list<int>[n];
	int special[k];
	for(int i = 0; i < k; i++)
		cin>>special[i];
	for(int i = 0; i < m; i ++)
	{
		cin>>u>>v>>w;
		if(W[u-1][v-1] == 0 || W[u-1][v-1] > w)
		{
			W[u-1][v-1] = W[v-1][u-1] = w;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
	}
	for(int i = 0 ; i < k; i++)
		findDistance(&W[0][0], adj, special[i] - 1, n);
	
}
