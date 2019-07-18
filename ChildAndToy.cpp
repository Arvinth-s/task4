#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

void PrintArray(int arr[], int n)
{
	for(int i = 0 ; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

void Print2DArray(int arr[][2], int n)
{
	for(int i = 0; i < n ; i++)
		printf("%d\t%d\n", arr[i][0], arr[i][1]);
	printf("\n");
}
void swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a += -*b;
}

int layer(int index)
{
	int sum = 0;
	int i = 1;
	while(index >= sum)
	{
		sum += pow(2, i);
	}
	return i - 1;
}

int child(int index)
{
	if(index == -1)return 0;
	int lp = (2 * pow(2, layer(index) - 1) - 2) + 1;
	int lc = (2 * pow(2, layer(index))) -2 + 1;
	return lc + (index - lp)*2;
}

int parent(int index)
{
	if(index == 0)return -1;
	int lp = (2 * pow(2, layer(index) - 2) -2) + 1;
	int lc = (2 * pow(2, layer(index) - 1) -2) + 1;
	return lp + (index - lc)/2; 
}

MaxHeap(int arr[], int arange[], int index, int n)
{
	int ch, flag, maxChild;
	int *maxIndex, *tempMaxIndex;
	if(child(index)+1 < n)
	{
		ch = arr[child(index) + 1] > arr[child(index)];
		maxChild = arr[child(index)+ch];
		maxIndex = &arr[child(index)+ ch];
		tempMaxIndex = &arange[child(index) + ch];
		flag = index;
		while(maxChild > arr[index] && index+1)
		{
			swap(&arr[index], maxIndex);
			swap(&arange[index], tempMaxIndex);
			maxIndex = &arr[index];
			tempMaxIndex = &arange[index];
			index = parent(index);
		}
		index = flag;
		if(arr[child(index) + !ch] > arr[index])
		{
			maxChild = arr[child(index)+ !ch];
			maxIndex = &arr[child(index) + !ch];
			tempMaxIndex = &arange[child(index) + !ch];
			while(maxChild > arr[index])
			{
				swap(&arr[index], maxIndex);
				swap(&arange[index], tempMaxIndex);
				maxIndex = &arr[index];
				tempMaxIndex = &arange[index];
				index = parent(index);
			}
		}
		index = flag;
		MaxHeap(arr, arange, child(index), n);
		MaxHeap(arr, arange, child(index)+1, n);
	}
	else if(child(index) + 1 == n)
	{
		if(arr[child(index)] > arr[index]){
		swap(&arr[child(index)] , &arr[index]); swap(&arange[child(index)], &arange[index]);
	}
	}
}

void MaxHeapped(int arr[], int arange[], int n)
{
	int ch, flag, maxChild, index = 0;
	int *maxIndex, *tempMaxIndex;
	while(child(index) + 1 < n)
	{
		ch = arr[child(index)+ 1] > arr[child(index)];
		maxChild = arr[child(index) + ch];
		maxIndex = &arr[child(index) + ch];
		tempMaxIndex = &arange[child(index) + ch];
		if(maxChild <= arr[index])return;
		swap(maxIndex, &arr[index]);
		swap(tempMaxIndex, &arange[index]);
		index = child(index) + ch;
	}
	if(child(index) + 1 == n)
		if(arr[child(index)] > arr[index]){
			swap(&arr[child(index)], &arr[index]); swap(&arange[child(index)], &arange[index]);
		}
}

void HeapSort(int arr[], int arange[], int &last, int n)
{
	last--;
	swap(&arr[0], &arr[last]);
	swap(&arange[0], &arange[last]);
	MaxHeapped(arr, arange, last);
	if(last <= 1)
	{
		if(arr[last] < arr[0]){
			swap(&arr[last], &arr[0]); swap(&arange[last], &arange[0]);}
		return;
		
	}
	HeapSort(arr, arange, last, n);
	
}

int main()
{
	int n1, n2;
	int sum = 0;
	cin>>n1>>n2;
	int arr1[n1+1], arange[n1+1], indices[n1+1], arr2[n2+1][2], last = n1;
	for(int  i= 0; i< n1; i++)
	{
		cin>>arr1[i];
		arange[i] = i+1;
	}
	MaxHeap(arr1, arange, 0, n1);
	HeapSort(arr1, arange, last, n1);
	for(int i = 0; i < n1 ; i++)
		indices[arange[i] - 1] = i;
	for(int i = 0; i < n2; i++)
	{
		cin>>arr2[i][0]>>arr2[i][1];
		sum += (indices[arr2[i][0]-1] < indices[arr2[i][1] - 1]) ? arr1[indices[arr2[i][0]-1]] : arr1[indices[arr2[i][1]-1]];
	}
	printf("\n%d",sum);
}
