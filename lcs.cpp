#include <iostream>
#include <vector>
using namespace std;
#define M 3
#define N 4
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int LCS(char a[], char b[])
{
	vector<char> r;
	int m[M + 1][N + 1];
	for(int i = 0; i <= M; i++ )
	{
		for(int j = 0; j <= N; j++)
		{
			if(i == 0 || j == 0)
			{
				m[i][j] = 0;
			}
			
			else if(a[i] == b[j])
			{
				r.push_back(a[i-1]);
				m[i][j] = 1 + m[i-1][j-1];
				
				
			}
			else
				m[i][j] = max(m[i-1][j], m[i][j-1]);
			
			
		}
		
	}
	
	for(int i = 0; i < r.size(); i++)
	{
		cout<<r[i];
	}
	cout<<endl;
	return m[M][N];
}

int main()
{
	char a[] = "abc";
	char b[] = "baba";
	
	cout<<LCS(a, b);
	
	return 0;
	
}
