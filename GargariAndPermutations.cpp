//OM NAMO NARAYANA
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void printArray(int *arr, int n)
{
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void printVector(vector<int> arr)
{
	vector<int>::iterator itr;
	printf("vector\n");
	for(itr = arr.begin(); itr != arr.end(); itr++)
		printf("%d\t", *itr);
	printf("\n");	
}

int lcs(int *arr, int n, int m, vector<int> arr2, int index = 0)
{
	for(int i = 0 ; i < m; i++)
		if(arr2[i] <= 0)
			return 0;
	int flag = 0, hold = 0;
	for(int i = 1; i < m; i++)
	{
		 if(arr[i*n + arr2[i] - 1] != arr[arr2[0] - 1])
		 {
			flag++;
			break;
		}
	}
	if(flag == 0)
	{
		for(int i = 0 ; i < m; i++)
			arr2[i] -= 1;
		return lcs(arr, n, m, arr2) + 1;
	}
	
	else
	{
		
		vector<int>::iterator itr;
		int max = 0, temp;
		for(int i = 0; i < m; i++)
		{
			vector<int> arr3;
			for(itr = arr2.begin(); itr != arr2.end(); itr++)
				arr3.push_back(*itr);
			arr3[i] = arr3[i] - 1;
			temp = lcs(arr, n, m, arr3);
			if(temp > max)
				max = temp;
		}
		return max;
	}
	
}

int main()
{
	int n, m;
	cin>>n>>m;
	int arr[m][n];
	for(int i = 0 ; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	vector<int> arr2;
	for(int i = 0 ; i < m; i++)
	{
		arr2.push_back(n);
	}
	int count = lcs(&arr[0][0], n,  m, arr2);
	cout<<endl<<count;
	return 0;
}
