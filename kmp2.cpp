#include <iostream>
#include <string>
using namespace std;
int posicion(char l, string c )
{
	for(int i = 0; i < c.size(); i++)
	{
		if(c[i] == l)
		{
			return i;
		}
	}
}
int kmp(string a, string b)
{
	string c = "ABC";
	int m[3][b.size()];
	int temp = 1;
	int x = 0; // columna
	int resp;
	
	for(int i =0; i<3;i++) // inicia en 0
	{
		for(int j =0; j<b.size();j++)
			m[i][j]=0;
	}
	for(int i = 0; i < b.size(); i++ ) // llenamos matriz
	{
		for(int j = 0; j < 3; j++)
		{
			if (c[j] == b[i])
			{
				m[j][i] = temp;
				temp ++;
			}
			else
			{
				m[j][i] = m[j][x];
			}

		}
		if(i > 0)// actualiza x
		{
			x  = m[posicion(b[i],c)][x];	
		}
		
				
	}
	
	for(int i = 0; i < 3; i ++) // imprime matriz
	{
		for(int j = 0; j <  b.size(); j++)
		{
			cout<< m[i][j]<<'\t';
		}
		cout<<endl;
	}
	int col = 0, posi;
	for(int i = 0; i < a.size(); i++) // recorre texto
	{
		resp = m[posicion(a[i], c)][col];
		if(resp == 1)
		{
			posi = i;
		}
		if(resp == b.size())
		{
			cout<<"se encontro patron"<<endl;
			return posi;
		}
		
		col = resp; 
	}	
}

int main()
{
	string a="AABACAABABACAA";
	string b="ABABAC";
	cout<<"posicion: "<<kmp(a,b);
	return 0;
}
