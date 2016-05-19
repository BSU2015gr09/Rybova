#include <iostream>

using namespace std;

class Complex{
private:
	double real; //�������������� ����� ������������ �����(real part)
	double im; //������ ���� ������������ �����(imaginary part)
public:
	 void swap(Complex& first, Complex& second){
		using std::swap;
		swap(first.im,second.im);
		swap(first.real,second.real);
	}
	Complex():real(0.0),im(0.0){}// ����� ������������ ��� ������������ 

	Complex(double Real, double Im=0) : real(Real),im(Im){}

	Complex(const Complex& other) : real(other.real), im(other.im) {}

	Complex(Complex&& other)  {
		swap(*this,other);
	}

	Complex& operator = (Complex other){
		swap(*this,other);
		return *this;
	}

	/*Complex& operator = (const Complex& other){
	Complex temp(other);
	swap(*this,temp);
	return *this;
	}*/


	const Complex operator+ (const Complex& other)const {
		Complex result(real+other.real,im+other.im);
		return result;
	}

	const Complex operator- (const Complex& other)const {
		Complex result(real-other.real,im-other.im);
		return result;
	}

	const Complex operator* (const Complex& other)const {
		Complex result((real*other.real-im*other.im),(real*other.im+im*other.real));
		return result;
	}

	friend ostream& operator <<(ostream& out, Complex num);/*������������� ��������� >> � << ��� ����� � ������. ��� ���������� ������������ ��� ������������� ��������� ������, ������� ����� ��������� ���������:
                                                            friend istream& operator >> (istream&, ���_������& ���_���������);
                                                            friend ostream& operator >> (ostream&, const ���_������& ���_���������);*/
	friend istream& operator >>(istream& in, Complex& num);


	~Complex(){}
};

ostream& operator <<(ostream& out, Complex num){
	if (num.real>=0&&num.im>0)
	{
		if(num.im==1) cout << num.real << " + i\n";
		else cout << num.real << " + " << num.im << "i\n";
	}
	else if (num.im==0)
	{
		cout << num.real << endl;
	}
	else if (num.real<=0&&num.im<0)
	{
		if(num.im==-1) cout << "-(" << num.real << " + i)\n";
		else cout << "-(" << num.real << " + " << num.im*-1 << "i)\n";
	}
	else if (num.im<0)
	{
		if(num.im==-1) cout << num.real << " - i\n";
		else cout << num.real << " - " << num.im << "i\n";
	}
	return out;
}



istream& operator >>(istream& in, Complex& num){
	cout << "Enter the real part: " << endl;
	cin >> num.real;
	cout << "Enter the imaginary part(without i): " << endl;	
	cin >> num.im;
	return in;
}


int main(int argc, char const *argv[])
{
	Complex a,b,res;
	cin>>a>>b;
	cout<<"Addition: "<<a+b;
	cout<<"Multiplication: "<<a*b;
	cout<<"Subtraction: "<<a-b;
	return 0;
}