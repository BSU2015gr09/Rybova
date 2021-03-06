//c)В программе объявлен массив А целых чисел (размер массива 100).
//Пользователь вводит число реально используемой части массива (число N). 
//Эта часть затем заполняется случайными числами. Потом распечатываем массив.
//Затем удаляем первый элемент массива (сдвигая остальные элементы) и меняем N на единицу.
//Потом пользователь вводит произвольное число и оно добавляется в конец используемой части массива и меняем N на единицу.
//Потом распечатываем массив. Затем опять удаляем первый элемент массива (сдвигая остальные элементы) и меняем N на единицу.
//Потом пользователь вводит произвольное число и оно добавляется в конец используемой части массива и меняем N на единицу.
//Потом распечатываем массив.
#include <iostream>
#include <iomanip>
using namespace std;

//инициализация массива
int init_mas(int mas[], int N)
{
	for (int i = 0; i<N; i++)
	{
		mas[i] = rand() % 40 - 20;
	}
	return 0;
}

//вывод элементов массива
int vyvod(int mas[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout <<mas[i]<<' ';
	}
	cout << endl << endl;
		return 0;
}
//удаление первого элемента массива
int udalen(int mas[], int &N)
{
	for (int i = 0; i < N; i++)
	{
		mas[i] = mas[i + 1];
	}
	N = N - 1;
	return 0;
}
//добавление введённого пользователем числа в конец массива
int dobavl(int mas[], int &N)
{
	int num=0;
	cout << "Введите число, которое хотите добавить в конец   ";
	cin >> num;
	cout << endl;
	N++;
	for (int i = 0; i < N; i++)
	{
		mas[N-1] = num;
	}
		return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const  n=100;
	int N, mas[n];
	cout << "Введите количество элементов массива  " << endl;
	cin >> N;
	cout << endl;
	if (N <= 100)
	{
		init_mas(mas, N);//инитиализация массива
		vyvod(mas, N);//вывод элементов массива

		udalen(mas, N);//удаление первого элемента массива
		cout << "Удаление первого элемента массива" << endl << endl;
		vyvod(mas, N);

		dobavl(mas, N);//добавление введённого пользователем числа в конец массива
		cout << "Добавление введённого пользователем числа в конец массива" << endl << endl;
		vyvod(mas, N);

		udalen(mas, N);
		dobavl(mas, N);
		cout << "Удаление первого элемента массива и добавление, введённого пользователем числа, в конец массива" << endl << endl;
		vyvod(mas, N);
	}
	else 
		cout << "К сожалению,Вы ввели число, превышающее размерность массива" << endl << endl;
	return 0;
}