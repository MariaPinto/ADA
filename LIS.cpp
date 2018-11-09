#include <iostream>
#include <stack>
using namespace std;

void LIS(int array[], int n)
{
	stack<int> s;
	int help[n] = {0};
	help[0] = 1;
	for(int i = 1 ;i < n; i++ )
	{
		for(int j = 0; j < n; j++)
		{
			if(array[j] < array[i] && help[j] > help[i])
			{
				help[i] = help[j];	
			}	
		}	
		help[i]++;
	}
	
	int resp = -100000;
	for(int i = 0; i < n; i++)
	{
		resp = max(resp, help[i]);
	}
	cout<<"largo: "<<resp<<endl;
	int temp = resp;
	for(int j = n-1; j >= 0; j--)
	{
		if(help[j] == temp)
		{
			s.push(array[j]);
			temp--;
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<'\t';
		s.pop();
	}
}

int main()
{
	//int array[n] = {1,5,13,3,11,7,10,13,4,12,8,16};
	int array[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
//	int n = 12;
	int n = sizeof(array)/sizeof(array[0]);

	LIS(array, n);
	
	return 0;
}
