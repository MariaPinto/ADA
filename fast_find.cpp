#include <iostream>
#include <string>
#include <ctime>
#include <dos.h>

using namespace std;

#define N 10

struct fast_find
{
    int id[N];
    void init()
    {
        for(int i=0;i<N;i++)
        {
            id[i] = i;
        }
    }
    bool conectado(int p, int q)
    {
        return (id[p] == id[q]);
    }
    void join(int p, int q)
    {
        int temp= id[p];
        for(int i=0;i<N;i++)
        {
            if (id[i] == temp)
            {
                id[i] = id[q];
            }
        }
    }
    
    void print()
    {
        for(int i=0;i<N;i++)
        {
            cout << id[i] << "-";
        }
    }
};

int main()
{
    fast_find prueba;
    double t0, t1;
    prueba.init();
    t0 = clock();
    for(int i=0; i<N; i++)
    {
    	prueba.join(rand()%N, rand()%N);
	}
	t1 = clock();
	double time = ((t1-t0)/CLOCKS_PER_SEC);
	cout<< time;
    /*
    prueba.join(4,3);
    prueba.join(3,8);
    prueba.join(6,5);
    prueba.join(9,4);
    prueba.join(2,1);
    prueba.join(5,0);
    prueba.join(7,2);
    prueba.join(6,1);
    prueba.print();
    cout << endl;
    cout << prueba.conectado(8,9);*/
    return 0;
}
