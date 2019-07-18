//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	public:
	Graph(int V);
	void addEdge(int u, int v);
	int dfs();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
	
void Graph::addEdge(int u, int v)//the variables are index
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int Graph::dfs()
{
	int count = 0, s;
	bool *visited = new bool[V];
	for(int  i = 0; i < V; i++)
		visited[i] = false;
	list<int>::iterator itr;
	for(int i = 0; i < V; i++)
	{
		if(visited[i])continue;
		count++;
		list<int> queue;
		queue.push_back(i);
		while(!queue.empty())
		{
			s = queue.front();
			queue.pop_front();
			for(itr = adj[s].begin(); itr != adj[s].end(); ++itr)
				if(!visited[*itr])
				{
					visited[*itr] = true;
					queue.push_back(*itr);
				}
		}
	}
	return count;
} 

int main()
{
	int n, m, count = 0;
	cin>>n>>m;
	int arr[m+1];
	Graph g(m);
	for(int i = 0 ; i < m; i++)
	{
		cin>>arr[i];
		for(int j = 0; j < i; j++)
			if(!(arr[i] & arr[j]))g.addEdge(i, j);
	}
	count = g.dfs();
	cout<<endl<<count;
	return 0;
}
