// "����������" �����������. ��������� �������� ������� �� 0. ��������� ���������� �������� ��� ������� ��������. ����� �� ������� ������� 'e'.������� �c�-����� ���� ��������.//
#include <iostream>
#include <clocale>
#include <cmath>
using std::cout;
using std::cin;
int main(){
	char oper =' ',k=' ';
	float rez=0,a=0,b=0;
	setlocale(LC_ALL, "Russian");
	cout <<"��� ������ ������� 'e',��� ��������� ������� �c�\n\n";
	cout << "������� �����: ";
	cin >> a;
	while (oper != '='){ 
			cout << "������� ��������";
			cin >> oper;
		if ((oper != '=') && (oper != 'e') && (oper != 'c')){
			cout << "������� �����: ";
			cin >> b;
			k='1';
		}
		switch (oper){
		case '+': rez = a + b;
			break;
		case '-': rez = a - b;
			break;
		case '*': rez = a * b;
			break;
		case '/':
			if (b == 0)
				cout << "������ �� 0 ������\n";
			else
				rez = a / b;
			break;
		case 'c': rez = 0;
			cout << "���������\n";
			cout << "������� �����: ";
			cin >> a;
			break;
		case '=':
			break;
		case 'e': exit(0);
		default:
			break;
		}
		cout<<k;
		 if ( (oper == '=') && (k==' ')) {
			 rez=a;}
	     if (oper != 'c'){
		  a = rez;
		}
	}
	cout << "���������� ��������=" << rez << "\n";
	return 0;
}