#include "time.h"
#include "iostream"
#include <conio.h>
using namespace std;

void arr_in(int* arr, const int N)
{
	for (int i = 0; i < N; i++)
		arr[i] = (int)(100 * rand() / RAND_MAX);  // или a[i] = (int)(rand()%100);
}

void arr_out(const int a[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}

void max_min(const int* a, const int n, int& max, int& min)
{
	max = a[0];
	min = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
}

void arr_in2(int* a, const int n, const int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i * m + j] = (int)(100 * rand() / RAND_MAX);
}

void arr_out2(const int a[][5], const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << '\n';
	}
}

void max_min2(int* a, const int n, const int m, int& max, int& min)
{
	max = *a;	// *a <==> a[0]
	min = *a;	// *a <==> a[0]

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i * m + j] > max)
				max = a[i * m + j];
			if (a[i * m + j] < min)
				min = a[i * m + j];
		}
}

void arr_in3(int** a, const int n, const int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = (int)(100 * rand() / RAND_MAX);
}

void arr_out3(int** matrix, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
	cout << "\n";
}


int main(int argc, char* argv[])
{
	/*
	int i = 1;
	int j = 555;

	int* p1 = &i;
	cout << p1 << endl;			// 00B3FAF0  
	cout << *p1 << endl; 		// 1

	*p1 = 3;
	cout << "i = " << i << endl; 			// 3

	int* p2 = p1;
	*p2 = 4;
	cout << i << endl << *p1 << endl << *p2 << endl; 	// 4  4  4


	i = 5;
	cout << "Values: " << i << endl << *p1 << endl << *p2 << endl; 	// 5  5  5
	cout << "Adresses: " << &i << endl << p1 << endl << p2 << endl; 	// 5  5  5

	p2 = &j;
	cout << "*p1:" << *p1 << endl << "*p2:" << *p2 << endl; 	// 5  555
	cout << "Adresses: " << endl << p1 << endl << p2 << endl;

*/	
//	_getch();

	cout << RAND_MAX;
	cout << endl << endl;

	srand((unsigned)time(NULL));

	int max, min, N = 10;
	int* a = new int[N];
	arr_in(a, N);
	arr_out(a, N);
	max_min(a, N, max, min);
	cout << '\n' << max << '\t' << min << "\n\n\n";
	delete[]a; // to avoid MEMORY LEAK
	//-----------------------------------------
	int b[4][5];
	arr_in2(&b[0][0], 4, 5);
	arr_out2(b, 4, 5);
	max_min2(&b[0][0], 4, 5, max, min);
	cout << '\n' << max << '\t' << min << "\n\n\n";

	//-----------------------------------------
	typedef int* pint;	// typedef вводит новое имя (синоним) pint для существующего типа int*
	pint* c;			// если не использовать pint, то пишем так:	int **c;
	c = new pint[4];	//											c=new int*[4];
	c[0] = new int[4 * 5];
	for (int i = 1; i < 4; i++)
		c[i] = c[i - 1] + 5;

	arr_in3(c, 4, 5);
	arr_out3(c, 4, 5);

	delete c[0];
	delete[]c;

	cout << '\n';
	
	return 0;
}