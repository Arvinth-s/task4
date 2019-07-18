//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<list>
#include<math.h>

using namespace std;

void dfs(list<int> *adj, int n, int k)
{
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	int count = 0, s, sum = 0;
	list<int> hold;
	list<int>::iterator itr;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			count = 1;
			list<int> queue;
			queue.push_back(i);
			visited[i] = true;
			while(!queue.empty())
			{
				s = queue.front();
				queue.pop_front();
				for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
				{
					if(!visited[*itr])
					{
						visited[*itr] = true;
						count++;
						queue.push_back(*itr);
					}
				}
			}
			hold.push_back(count);
			sum += int(pow(count, k)) % int((pow(10, 9) + 7));
			sum = sum % int((pow(10, 9) + 7));
		}
	}
	sum = int(pow(n, k))%int(pow(10, 9) + 7) - sum;
	printf("%d", sum);
}

int main()
{
	int n, k;
	int u, v, c;
	scanf("%d%d", &n, &k);
	list<int> *adj;
	adj = new list<int>[n];
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		if(!c)
		{
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
	}
	dfs(adj, n, k);
}
