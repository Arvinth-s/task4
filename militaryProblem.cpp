//OM NAMO NARAYANA
#include<iostream>
#include<list>
#include<stdio.h>

using namespace std;

int stackUp(list<int> *child, int u, int k, int n)
{
	list<int> stack;
	list<int>::iterator itr;
	int count = 0;
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	stack.push_back(u);
	count++;
	if(count >= k)
	{
		//printf("%d\n", u+1);
		return u+1;
	}
	int s;
	while(!stack.empty())
	{
		for(itr =child[stack.back()].begin(); itr != child[stack.back()].end(); itr++)
		{
			if(!visited[*itr] && *itr)
			{
				visited[*itr] = true;
				count++;
				if(count >= k)
				{
					//printf("%d\n", *itr+1);
					return *itr+1;
				}
				stack.push_back(*itr);
				break;
			}
		}
		if(itr == child[stack.back()].end())
		{
			stack.pop_back();
		}
	}
	//printf("-1\n");
	return - 1;
	
}

int main()
{
	int n, q;
	cin>>n>>q;
	list<int> *child;
	int ans[q];
	child = new list<int>[n];
	int temp[n];
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d", &temp[i]);
		child[temp[i] - 1].push_back(i+1);
	}
	int u, k;
	for(int i = 0; i< q; i++)
	{
		scanf("%d%d", &u, &k);
		ans[i] = stackUp(child, u-1, k, n);
	}
	for(int i = 0 ; i < q; i++)
	{
		printf("\n%d", ans[i]);
	}
}
