//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

int minDistance(int *dist, bool *visited, int n)
{
	int min = INT_MAX, min_index = -1;
	for(int i = 0; i < n; i++)
		if(!visited[i] && min > dist[i])
			min = dist[i], min_index = i;
	return min_index;
}

void dfs(list<int> *child, int *arr, int n, int m)
{
	bool *visited = new bool[n], *visited2 = new bool[n];
	list<int>::iterator itr;
	int *dist = new int[n];
	for(int  i = 0; i < n; i++)
		visited[i] = false;
	for(int q = 0; q < m; q++)
	{
		int max = 0, max_index = -1;
		for(int i = 0; i< n; i++)
			visited2[i] = false, dist[i] = INT_MAX;
		dist[arr[q] - 1] = 0;
		visited[arr[q]-1] = !visited[arr[q]-1];
		for(int i = 0; i < n; i++)
		{
			int u = minDistance(dist, visited2, n);
			visited2[u] = true;
			if(max <= dist[u] && !visited[u])
				if(max == dist[u] && u > max_index)
					max_index = u;
				else if(max < dist[u])
					max_index = u, max = dist[u];
			for(itr = child[u].begin(); itr != child[u].end(); itr++)
				if(dist[*itr] > dist[u]+ 1)
					dist[*itr] = dist[u]+1;
		}
		if(max_index != -1)
			cout<<max_index+1<<endl;
		else
			cout<<arr[q]<<endl;
	}
	return;
}

int main()
{
	int t, n, m, temp;
	cin>>t;
	for(int testcases = 0; testcases < t; testcases++)
	{
		cin>>n>>m;
		list<int> *child;
		int arr[m];
		child = new list<int>[n];
		for(int i = 1; i < n; i++)
		{
			scanf("%d", &temp);
			child[temp-1].push_back(i);
			child[i].push_back(temp-1);
		}
		for(int i = 0; i < m; i++)
			scanf("%d",&arr[i]);
		cout<<endl<<endl;
		dfs(child, arr, n, m);
		cout<<endl<<endl;
	}
}
