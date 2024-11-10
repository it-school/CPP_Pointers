#include "time.h"
#include "iostream"
#include <conio.h>
using namespace std;

void arrayInput(int* array, const int N)
{
	for (int i = 0; i < N; i++)
		array[i] = (int)(100 * rand() / RAND_MAX);  // или a[i] = (int)(rand()%100);
}

void arrayOutput(const int a[], const int N)
{
	for (int i = 0; i < N; i++)
		cout << a[i] << '\t';
}

void findMaxMin(const int* a, const int N, int& max, int& min)
{
	max = a[0];
	min = a[0];

	for (int i = 1; i < N; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
}

void arrayInput2(int* a, const int N, const int M)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i * M + j] = (int)(100 * rand() / RAND_MAX);
}

void arrayOutput2(const int a[][5], const int N, const int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << a[i][j] << '\t';
		cout << '\n';
	}
}

void findMaxMin2(int* a, const int N, const int M, int& max, int& min)
{
	max = *a;	// *a <==> a[0]
	min = *a;	// *a <==> a[0]

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (a[i * M + j] > max)
				max = a[i * M + j];
			if (a[i * M + j] < min)
				min = a[i * M + j];
		}
}

void arrayInput3(int** a, const int N, const int M)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = (int)(100 * rand() / RAND_MAX);
}

void arrayOutput3(int** matrix, const int N, const int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
	cout << "\n";
}


int main(int argc, char* argv[])
{
	int i = 1;
	int j = 555;

	int* p1 = &i;
	cout << p1 << endl;					// 00B3FAF0  
	cout << *p1 << endl; 				// 1

	*p1 = 3;
	cout << "i = " << i << endl;		// 3

	int* p2 = p1;
	*p2 = 4;
	cout << i << endl << *p1 << endl << *p2 << endl; 	// 4  4  4


	i = 5;
	cout << "Values: " << i << endl << *p1 << endl << *p2 << endl;		// 5  5  5
	cout << "Adresses: " << &i << endl << p1 << endl << p2 << endl; 	// 5  5  5

	p2 = &j;
	cout << "*p1:" << *p1 << endl << "*p2:" << *p2 << endl;				// 5  555
	cout << "Adresses: " << endl << p1 << endl << p2 << endl;


	_getch();

	srand((unsigned)time(NULL));

	int max, min, N = 10;
	int* a = new int[N];
	arrayInput(a, N);
	arrayOutput(a, N);
	findMaxMin(a, N, max, min);
	cout << '\n' << max << '\t' << min << "\n\n\n";
	delete[]a; // to avoid MEMORY LEAK

	//-----------------------------------------
	int b[4][5];
	arrayInput2(&b[0][0], 4, 5);
	arrayOutput2(b, 4, 5);
	findMaxMin2(&b[0][0], 4, 5, max, min);
	cout << '\n' << max << '\t' << min << "\n\n\n";

	//-----------------------------------------
	int rows = 4, columns = 5;
	typedef int* pointerToInt;	// typedef вводит новое имя (псевдоним) pointerToInt для существующего типа int*
	pointerToInt* c;			// если не использовать pointerToInt, то пишем так:		int **c;
	c = new pointerToInt[rows];	//														c=new int*[rows];
	c[0] = new int[rows * columns];
	for (int i = 1; i < rows; i++)
		c[i] = c[i - 1] + columns;

	arrayInput3(c, rows, columns);
	arrayOutput3(c, rows, columns);

	delete c[0];
	delete[]c;

	cout << endl;

	return 0;
}