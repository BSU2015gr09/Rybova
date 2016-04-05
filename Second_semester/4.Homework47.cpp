#define _CRT_SECURE_NO_WARNINGS  //47 В массиве А(N,M) переставить строки в порядке убывания количества содержащихся в них положительных элементов.
#include <iostream> 
#include <iomanip>
#include <ctime> 
using namespace std;

void showtask() 
{ 
	cout <<"47. В массиве А(N,M) переставить строки в порядке убывания количества содержащихся в них положительных элементов.";
} 

void   ArrayInit(int *A,int N,int M)
{
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)     
			*(A+i*M+j)=rand() % 50-10; //Заполнение матрицы случайными числами
}
//Печать массива
void PrintArray(int *A, int N,int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout <<setw(4)<<*(A+i*M+j);
		}
		cout << endl;
	}
}
//Вычисление кол-ва положительных элементов
int *GetKol(int *A, int N,int M)
{
	int *kol = new int[N];
	for (int i = 0; i < N; i++)
	{
		int curKol = 0;
		for (int j = 0; j < M; j++)
		{
			if (*(A+i*M+j)>0)
				curKol ++;
		}
		*(kol+i) = curKol;
	}
	return kol;
}
void PrintArrayWithKol(int *A, int *kol_posit, int N,int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout <<setw(4)<<*(A+i*M+j);
		}
		cout <<"  Кол-во полож. элементов:"<<*(kol_posit+i) << endl;
	}
}

//Перестановка строк в порядке убывания количества содержащихся в них положительных элементов
void SortByKolPol(int *A, int *kol, int N, int M)
{
	for (int i = 0; i < (N - 1); i++)
	{
		for (int j = 0; j < (N - i - 1); j++)
		{
			if (*(kol+j)<*(kol+j+1))
			{
				for(int k=0;k < M; k++)
				{
					int tmpStr =*(A+j*M+k);
					*(A+j*M+k)=*(A+(j+1)*M+k);
					*(A+(j+1)*M+k) = tmpStr;
				}
				int tmpkol= *(kol+j);
				*(kol+j) = *(kol+j+1);
				*(kol+j+1)= tmpkol;
			}
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian"); 
	srand(time(NULL)); 
	while (1) 
	{ 
		int variant;
		cout<<endl;
		cout << "Выберите вариант\n";
		cout<<" 0. Выход из программы\n";
		cout<<" 1. Просмотреть текст задания\n";
		cout<<" 2. Выполнить программу\n";
		cout << ">> ";
		cin >> variant;
		switch (variant) 
		{ 
		case 1: 
			{ showtask(); 
			break; 
			} 
		case 2: 
			{ 
				int N, M; 
				cout<<"Введите размерность массива:"<<endl;
				cout<<"N = "; cin>>N;
				cout<<"M = "; cin>>M;
				int *A = new int[N*M];
				ArrayInit(A,N,M); 
				cout << "Массив:" << endl;
				PrintArray(A,N,M);
				int *kol_pz = GetKol(A,N,M); //Получаем кол-во пол.элементов
				cout << endl << "Массив и количеством полож. элементов в строке: " << endl;
				PrintArrayWithKol(A,kol_pz,N,M); //Печатаем массив вместе с кол-ом пол.элементов
				SortByKolPol(A,kol_pz,N,M); //Сортируем по кол-ву полож.элем. строк
				cout << endl << "Массив после перестановки строк:" << endl;
				PrintArrayWithKol(A,kol_pz,N,M);  //Печатаем массив после перестановки.
				delete[] kol_pz;
				delete[] A;
				cin.get(); 
			} 
		case 0: 
			{
				cout<<"Выход из программы "; 
				return;
			} 
		default:
			{
				cout << "Вы выбрали неверный вариант" << endl;
				break;
			}
		} 
	}
}