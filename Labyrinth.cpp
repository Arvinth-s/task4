//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<list>
#include<string>

using namespace std;

printArray(char *arr, int n, int m)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c\t", arr[i*n+j]);
		printf("\n");
	}
	printf("\n");
}

class Node
{
	public:
		int l;
		int r;
		int x;
		int y;
	Node(int l, int r, int x, int y);	
};

Node::Node(int l, int r, int x, int y)
{
	this->l = l;
	this->r = r;
	this->x = x;
	this->y = y;
}

int main()
{
	int n, m, x, y, nl, nr, count = 1;
	scanf("%d%d%d%d%d%d", &m, &n, &x, &y, &nl, &nr);
	char arr[m][n];
	int cost[m][n][2];
	bool visited[m][n];
	for(int i = 0; i < m; i++)
		for(int  j = 0; j < n; j++)
			cin>>arr[i][j],cost[i][j][0] = cost[i][j][1] = INT_MAX, visited[i][j] = false;
	list<Node> queue;
	queue.push_back(Node(nl, nr, x-1, y-1));
	visited[x-1][y-1] = true;
	Node s(nl, nr, x-1, y-1);
	while(!queue.empty())
	{
		s = queue.front();
		queue.pop_front();
		//first right, top, left and down
		if(s.y+1 < n && arr[s.x][s.y+1] == '.'&& s.r > 0 && !visited[s.x][s.y+1])
			queue.push_back(Node(s.l, s.r-1, s.x, s.y+1)), visited[s.x][s.y+1] = true, count++;
		if(s.x-1 >=0 && arr[s.x-1][s.y] == '.' && !visited[s.x-1][s.y])
			queue.push_back(Node(s.l, s.r, s.x-1, s.y)), visited[s.x-1][s.y] = true, count++;
		if(s.y-1 >= 0 &&arr[s.x][s.y-1] == '.' && s.l >0 && !visited[s.x][s.y-1])
			queue.push_back(Node(s.l-1, s.r, s.x, s.y-1)), visited[s.x][s.y-1] = true, count++;
		if(s.x+1 < m && arr[s.x+1][s.y] == '.' && !visited[s.x+1][s.y])
			queue.push_back(Node(s.l, s.r, s.x+1, s.y)), visited[s.x+1][s.y] = true, count++;
		
	}
	for(int i = 0 ; i < m; i ++)
		for(int j = 0; j < n; j++)
			if(visited[i][j])
				arr[i][j] = '+';
	printArray(&arr[0][0], n, m);
	cout<<count<<endl;
	
}
