//OM NAMO NARAYANA
#include<iostream>
#include<list>
#include<stdio.h>

using namespace std;

int main()
{
	list<int> lake[50];
	list<int> real_lake[50];
	list<int>::iterator itr;
	int r, c, k, count = 0;
	cin>>r>>c>>k;
	char input[r+1][c+1];
	int hold[r+1][c+1];
	for(int i = 0 ; i < r; i++)
		for(int  j = 0; j < c; j++)
		{
			cin>>input[i][j];
			if(input[i][j] == '.')
			{
				if(i > 0 && input[i-1][j] == '.' )
					hold[i][j] = hold[i-1][j];
				else if (j > 0 && input[i][j-1] == '.')
					hold[i][j] = hold[i][j-1];
				else
					hold[i][j] = count++;
				lake[hold[i][j]].push_back(c*i + j);
			}
		}
	int count2 = count, arange[count+1], indices[count+1];
	for(int i = 0 ; i < r; i++)
	{
		if(input[i][0] == '.')lake[hold[i][0]].push_back(-1);
		if(input[i][c - 1] == '.')lake[hold[i][c-1]].push_back(-1);
	}
	for(int i = 0; i < c; i ++)
	{
		if(input[0][i] == '.')lake[hold[0][i]].push_back(-1);
		if(input[r-1][i] == '.')lake[hold[r-1][i]].push_back(-1);
	}
	//count - k should be removed
	
	int size[count+1], sum = 0, j =0;
	for(int i = 0; i < count2; i++)
	{
		itr = lake[i].end();
		itr--;
		if(*itr != -1)
		{
			real_lake[j] = lake[i];
			size[j] = lake[i].size();
			arange[j] = j;
			j++; 
		}
		else
			count--;
	}
	if(count > 2 * k)
	{
		for(int i = 0; i < k; i++)
			for(int j = 0; j < count - i - 1; j++)
				if(size[j] > size[j+1])
				{
					size[j] += size[j+1];
					arange[j] += arange[j+1];
					size[j+1] = size[j] - size[j+1];
					arange[j+1] = arange[j] - arange[j+1];
					size[j] += -size[j+1];
					arange[j] += -arange[j+1];
				}
		for(int i = 0; i < count - k; i++)
		{
			sum+= size[i]; 
			for(itr = real_lake[arange[i]].begin(); itr != real_lake[arange[i]].end(); ++itr)
			input[*itr/c][*itr%c] = '*';
		}
	}
	else
		for(int i = 0 ; i < count - k; i++)//first count - k things are sorted and added
		{
			for(int j = count - 1 ; j > i; j--)
				if(size[j-1] > size[j])
				{
					size[j] += size[j-1];
					arange[j] += arange[j-1];
					size[j-1] = size[j] - size[j-1];
					arange[j-1] = arange[j] - arange[j-1];
					size[j] += -size[j-1];
					arange[j] += -arange[j-1];
				}
			sum += size[i]; 
			for(itr = real_lake[arange[i]].begin(); itr != real_lake[arange[i]].end(); ++itr)
			input[*itr/c][*itr%c] = '*';
		}
	cout<<endl<<sum<<endl;
	for(int i=0; i < r; ++i)
	{
		for(int j=0; j<c; j++)
			cout<<input[i][j];
		cout<<endl;
	}
}

