#define _CRT_SECURE_NO_WARNINGS  //35.В строке найти и вывести на экран все слова максимальной длины,  и удалить за ними следующее слово. 
#include <iostream> 
#include <stdio.h>
#include <cstring>
#include <clocale> 
#include <fstream>

using namespace std;
const int n=900;

char* vvod_string (char * str)
{
	int d=0; 
	cout<<"Выберите способ ввода строки:"<<endl<<"  1. Автоматически "<<endl<<"  2. Ввод с клавиатуры "<<endl<<"  3. Из текстового файла "<<endl; 
	cin>>d; 
	switch(d){ 
	case 1: strcpy(str,"Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do");
		cout<<str<<endl; 
		break; 
	case 2:
		cout << "Введите строку" <<endl;
		cin.get();
		cin.getline(str, n);
		break;
	case 3:
	default: 
		ifstream infile("d:\\input.txt"); 
		if(!infile.is_open())
			cout<<"File is not open "<<endl;
		else
			while (!infile.eof()){ 
				infile.getline(str, n); 
			}
			break;
	}
	return str; 
} 

void max_lengh(char *str,int n)
{  
	char *source = str; 
	char *p = new char[n];
	char *s = new char[n];
	strcpy(s, str);
	strcpy(p, str);
	char * pch = strtok(p, " ,.-;:"); 
	int maxlen = strlen(pch);
	while (pch != NULL) 
	{
		if (maxlen < strlen(pch))
			maxlen = strlen(pch);
		pch = strtok(NULL, " ,.-;:");
	}
	cout << "Максимальная длина слова="<<maxlen<<endl<<"Слова максимальной длины:"<<endl;

	bool max_len_before(false);
	char * pch1 = strtok(s, " ,.-;:");
	while (pch1 != NULL)
	{
		size_t cur_len = strlen(pch1);
		if( max_len_before && cur_len != maxlen) //не удаляем если слова max длины идут друг за другом
		{
			size_t end = strlen(source)-cur_len;
			strncpy(source-1, source + cur_len, end); //смещаем ОБЛАСТЬ ПАМЯТИ!!!! начиная с позиции след. за максимальным + токен 
			source[end-1] = '\0';
		}
		else
		{
			source+=(cur_len+1); //увеличиваем указатель на длину слова с токеном
		}

		if (cur_len==maxlen)
		{
			cout<<pch1<<endl;
			max_len_before = true;
		}
		else
		{
			max_len_before = false;
		}

		pch1 = strtok(NULL, " ,.-;:");
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	char *str = new char[n];
	vvod_string(str); 
	max_lengh(str,n);
	cout << "Строка после удаления=" <<endl<<str<<endl;
	return 0;
}
