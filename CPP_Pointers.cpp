#include "time.h"
#include "iostream"
#include <conio.h>
#include <ctime>
using namespace std;

/// <summary>
/// Ввод одномерного массива случайными числами
/// </summary>
/// <param name="array"></param>
/// <param name="N"></param>
static void arrayInput(int* array, const int N)
{
	for (int i = 0; i < N; i++)
		array[i] = rand() % 100;  // проще и читаемее, чем (int)(100 * rand() / RAND_MAX)
}

/// <summary>
/// Вывод одномерного массива
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
static void arrayOutput(const int a[], const int N)
{
	cout << "Массив (" << N << " элементов):\n";
	for (int i = 0; i < N; i++)
		cout << a[i] << '\t';
	cout << endl;
}

/// <summary>
///  Поиск максимума и минимума в одномерном массиве
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
/// <param name="max"></param>
/// <param name="min"></param>
static void findMaxMin(const int* a, const int N, int& max, int& min)
{
	max = min = a[0];
	for (int i = 1; i < N; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
}

/// <summary>
/// Ввод двумерного массива через указатель (один блок памяти)
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
/// <param name="M"></param>
static void arrayInput2(int* a, const int N, const int M)
{
	for (int i = 0; i < N * M; i++)
		a[i] = rand() % 100;
}

/// <summary>
/// Вывод двумерного массива фиксированной ширины
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
/// <param name="M"></param>
static void arrayOutput2(const int a[][5], const int N, const int M)
{
	cout << "Двумерный массив (" << N << "x" << M << "):\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << a[i][j] << '\t';
		cout << '\n';
	}
	cout << endl;
}

/// <summary>
/// Поиск min/max в двумерном массиве, представленном в виде одного указателя
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
/// <param name="M"></param>
/// <param name="max"></param>
/// <param name="min"></param>
static void findMaxMin2(const int* a, const int N, const int M, int& max, int& min)
{
	max = min = *a;	// *a <==> a[0]
	for (int i = 0; i < N * M; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
}

/// <summary>
/// Ввод двумерного массива с раздельным выделением строк
/// </summary>
/// <param name="a"></param>
/// <param name="N"></param>
/// <param name="M"></param>
static void arrayInput3(int** a, const int N, const int M)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = rand() % 100;
}

/// <summary>
/// Вывод двумерного массива через двойной указатель
/// </summary>
/// <param name="matrix"></param>
/// <param name="N"></param>
/// <param name="M"></param>
static void arrayOutput3(int** matrix, const int N, const int M)
{
	cout << "Двумерный массив через двойной указатель (" << N << "x" << M << "):\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned>(time(nullptr)));

	cout << "=== Демонстрация работы с указателями ===\n\n";

	int i = 1, j = 555;
	int* p1 = &i;
	int* p2 = &j;

	cout << "Адреса указателей:\n";
	cout << "p1 -> " << p1 << "\n"		// 00B3FAF0
		<< "p2 -> " << p2 << "\n\n";		// 00B3FAF4

	cout << "Значения через указатели:\n"
		<< "*p1 = " << *p1 << "\n"			// 1
		<< "*p2 = " << *p2 << "\n\n";		// 555
	_getch();

	*p1 = 3;
	cout << "Изменяем *p1 = 3  >  i теперь равно " << i << "\n";
	_getch();

	p2 = p1;
	*p2 = 4;
	cout << "\nПосле присваивания p2 = p1 и *p2 = 4:\n";
	cout << "i = " << i << "\t*p1 = " << *p1 << "\t*p2 = " << *p2 << "\n";	// 4  4  4
	_getch();

	i = 5;
	cout << "\nПосле изменения i = 5:\n";
	cout << "Значения: " << i << '\t' << *p1 << '\t' << *p2 << endl;			// 5  5  5
	cout << "Адреса:\n" << &i << '\n' << p1 << '\n' << p2 << endl;
	_getch();

	p2 = &j;
	cout << "\nТеперь p2 снова указывает на j.\n";
	cout << "*p1 = " << *p1 << "\t*p2 = " << *p2 << endl;							// 5  555
	cout << "Адреса:\n" << p1 << '\n' << p2 << endl;
	_getch();

	//-----------------------------------------
	cout << "\n=== Работа с одномерным массивом ===\n";
	int max, min, N = 15;
	int* a = new int[N];
	arrayInput(a, N);
	arrayOutput(a, N);
	findMaxMin(a, N, max, min);
	cout << "\nMAX = " << max << "\tMIN = " << min << "\n";
	delete[] a; // освобождаем память
	_getch();

	//-----------------------------------------
	cout << "\n=== Работа с двумерным массивом (единый блок памяти) ===\n";
	int b[4][5];
	arrayInput2(&b[0][0], 4, 5);
	arrayOutput2(b, 4, 5);
	findMaxMin2(&b[0][0], 4, 5, max, min);
	cout << "\nMAX = " << max << "\tMIN = " << min << "\n";
	_getch();

	//-----------------------------------------
	cout << "\n=== Работа с двумерным массивом через массив указателей ===\n";
	int rows = 4, columns = 6;

	typedef int* pointerToInt;      // typedef вводит новое имя (псевдоним) pointerToInt для существующего типа int*
	pointerToInt* c;                // если не использовать pointerToInt, то пишем так: int **c;
	c = new pointerToInt[rows];     // эквивалентно: c = new int*[rows];

	// выделяем единый блок памяти для всех строк
	c[0] = new int[rows * columns];
	for (int i = 1; i < rows; i++)
		c[i] = c[i - 1] + columns;

	arrayInput3(c, rows, columns);
	arrayOutput3(c, rows, columns);

	findMaxMin2(&c[0][0], rows, columns, max, min);
	cout << "\nMAX = " << max << "\tMIN = " << min << "\n";

	delete[] c[0];  // освобождаем единый блок
	delete[] c;     // освобождаем массив указателей

	cout << "\n=== Завершение работы программы ===\n";
	_getch();

	return 0;
}