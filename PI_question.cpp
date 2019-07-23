//OM NAMO NARAYANA
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	int i, count = 0;
	cin>>i;
	vector<int> index;
	while(i / 2 > 0)
	{
		if(i % 2 == 1)
			index.push_back(count);
		count++;
		i /= 2;
	}
	if(i%2 == 1)
		index.push_back(count), count++;
	int sum  = 0; 
	vector<int>::iterator itr;
	for(itr = index.end() - 1; itr != index.begin(); itr--)
		sum += pow(2, *itr)*(*itr) + 1;
	cout<<"ans:"<<sum;
}
