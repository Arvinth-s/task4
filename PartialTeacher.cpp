//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>

using namespace std;

void act(int *value, int &index, list<int> &store)
{
	value[index] = value[index-1];
	index++;
	store.pop_front();
}

int maxy(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

void printArray(int *arr, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

int main()
{
	int n, count = 1, index = 0, j =0, flag = 0;;
	cin >> n;
	char arr[n];
	vector<int> hold;
	list<int> store;
	cin>>arr[0];
	while(arr[index] == '=')
	{
		store.push_back(index+1);
		index++;
		cin>>arr[index];
	}
	char temp = arr[index];
	int value[n];
	for(int i = 1; i < n-1-index; i++)//input for array
	{
		cin>>arr[i];
		if(arr[i] == temp)
			count++;
		else if(arr[i] == '=')
			store.push_back(i+1);
		else
		{
			hold.push_back(count);
			count = 1;
			temp = arr[i];
		}
	}
	hold.push_back(count);
	vector<int>::iterator itr;
	
	
	index = 0, j = 0;
	
	if(arr[0]=='=')
	{
		for(int i = 0; i < store.front(); i++)
			index++;
		flag = store.front();
		store.pop_front();
	}
	
	
	if(arr[index] == 'L')
	{
		value[index++] = hold[0]+1;
		while(j+2 < hold.size())
		{
			for(int i = 0; i < hold[j]; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
					value[index++] = hold[j] - i;
					
			for(int i = 0; i < hold[j+1] - 1; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
				value[index++] = 2 + i;
				
			if(index == store.front())
				act(value, index, store);
		
			value[index++] = maxy(hold[j+1]+1, hold[j+2]+1);
			j += 2;
			if(index == store.front())
				act(value, index, store);
		}
		if(j+2 == hold.size())
		{
			for(int i = 0; i < hold[j]; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
					value[index++] = hold[j] - i;

			for(int i = 0; i < hold[j+1] - 1; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
				value[index++] = 2 + i;
			
			if(index == store.front())
				act(value, index, store);
				
			value[index++] = hold[j+1]+1;
			
			if(index == store.front())
				act(value, index, store);
		}
		else if(j+1 == hold.size())
		{
			for(int i = 0; i < hold[j]; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
					value[index++] = hold[j] - i;
		}
			if(index == store.front())
				act(value, index, store);		
		
	}
	
	else
	{
		value[index++] = 1;
		while(j+1 < hold.size())
		{
			for(int i = 0; i < hold[j] - 1; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
					value[index++] = 2+i;
			
			if(index == store.front())
				act(value, index, store);

			value[index++] = maxy(hold[j] + 1, hold[j+1] + 1);
			
			for(int i = 0; i < hold[j+1]; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
				value[index++] = hold[j+1]-i;

			if(index == store.front())
				act(value, index, store);			
			j += 2;
		}
		if(j+1 == hold.size())
		{
			for(int i = 0; i < hold[j] - 1; i++)
				if(index == store.front())
					act(value, index, store), i--;
				else
					value[index++] = 2+i;
			
			if(index == store.front())
				act(value, index, store);
				
			value[index++] = hold[j] + 1;
			
			if(index == store.front())
				act(value, index, store);
		}
	}
	if(arr[0] == '=')
	{
		for(int i = 0 ; i < flag; i++)
			value[i] = value[flag];
	}
	printArray(value, n);
}
