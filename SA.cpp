#include <iostream>
#include <vector>
using namespace std;


void AS(int s[], int f[], int n)
{
	vector<int> r;
	int k = 0;
	r.push_back(0);
	
	
	for(int i = 1; i < n; i++ )
	{
		if(s[i] >= f[k])
		{
			r.push_back(i);
			k = i;
		}
	} 
	
	for(int i = 0; i < r.size(); i++ )
	{
		cout<<"("<<s[r[i]]<<","<<f[r[i]]<<")"<<'\t';
	}
}

int main()
{
	int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
	int f[11] = {4,5,6,7,9,9,10,11,12,14,16};
	AS(s,f,11);
	
	return 0;
}
