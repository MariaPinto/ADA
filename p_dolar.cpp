#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
using namespace std;
#define N 10
class BST
{
    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x >= t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    void search(int x)
    {
        root = find(root, x);
    }
    
    int f_max()
    {
    	node* t = findMax(root);
    	return t->data;
    	
	}
};


//DOLAR
void dolar(int a[])
{
	BST tree;
	int ganancia = 0;
	int c, v;
	for(int i = 0; i < N; i++)
	{
		tree.insert(a[i]);
	}
	int maxi = tree.f_max();
//	cout<<maxi<<endl;
	for(int i = 0; i < N - 1; i++)
	{
		ganancia = max(ganancia, maxi - a[i]);
		//cout<<ganancia<<endl;
		tree.remove(a[i]);
		if(a[i] == maxi)
		{
			maxi = tree.f_max();
		}
		
	}
	cout<<"ganancia: "<<ganancia<<endl;
}

void imp(int p[])
{
	for(int i = 0; i<N; i++)
	{
		cout<<p[i]<<" ";
	}
}
void inicia(int p[])
{
	srand (time(NULL));
	int r;
	for(int i = 0; i<N; i++)
	{
		r = rand() % 100 + 1;
		p[i] = r;
	}
}

int main()
{
	int precios[N]= {1,1,1,1,1,1,1,1,1,1};
//	inicia(precios);
//  imp(precios);
//	cout<<endl;
	dolar(precios);
	return 0;
}


