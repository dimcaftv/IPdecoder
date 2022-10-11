#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void read_quad(unsigned int& quad)
{
	cin >> quad;
	while (!(quad >= 0 && quad <= 255))
	{
		cout << "Введите правильный квадрант: \n";
		cin >> quad;
	}
}

void input_quads(unsigned int& q1, unsigned int& q2, unsigned int& q3, unsigned int& q4)
{
	cout << "Введите первый квадрант: \n";
	read_quad(q1);

	cout << "Введите второй квадрант: \n";
	read_quad(q2);

	cout << "Введите третий квадрант: \n";
	read_quad(q3);

	cout << "Введите четвертый квадрант: \n";
	read_quad(q4);
}

unsigned long long int DecToOct(unsigned int n)
{
	unsigned long long int remainder, i = 1;
	unsigned long long int octal = 0;

	while (n != 0)
	{
		remainder = n % 8;
		n /= 8;
		octal += (remainder * i);
		i *= 10;
	}
	return octal;
}

string DecToHex(unsigned int n)
{
	char hexaDeciNum[100];

	int i = 0;
	while (n != 0) {

		int temp = 0;

		temp = n % 16;


		if (temp < 10) {
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}
	string res = "";

	for (int j = i - 1; j >= 0; j--)
		res += hexaDeciNum[j];
	return res;
}




int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int quad1, quad2, quad3, quad4, fullIp;
	unsigned long long int fullIpOct;
	string txtIpBin, txtIpBinSplit, txtIpDex, txtIpOct, txtIpHex;
	string start; unsigned int startI;
	input_quads(quad1, quad2, quad3, quad4);

	fullIp = (quad1 << 8 * 3) + (quad2 << 8 * 2) + (quad3 << 8) + quad4;


	txtIpBin = bitset<8 * sizeof(unsigned int)>(fullIp).to_string();
	txtIpBinSplit = txtIpBin;

	for (int i = 8; i < 8 * 4; i += 9)
	{
		txtIpBinSplit.insert(i, 1, ' ');
	}


	txtIpDex = to_string(fullIp);

	for (int i = txtIpDex.size() - 3; i > 0; i -= 3)
	{
		txtIpDex.insert(i, 1, ',');
	}


	fullIpOct = DecToOct(fullIp);
	txtIpOct = to_string(fullIpOct);

	for (int i = txtIpOct.size() - 3; i > 0; i -= 3)
	{
		txtIpOct.insert(i, 1, ',');
	}


	txtIpHex = DecToHex(fullIp);


	cout << endl << endl;
	cout << "Ваш IP: " << quad1 << "." << quad2 << "." << quad3 << "." << quad4 << endl;
	cout << "IP в десятичной форме: " << fullIp << "    " << txtIpDex << endl;
	cout << "IP в двоичной форме: " << txtIpBin << "    " << txtIpBinSplit << endl;
	cout << "IP в восьмиричной форме: " << fullIpOct << "    " << txtIpOct << endl;
	cout << "IP в шестнадцатеричной форме: " << txtIpHex << endl;


	system("pause");

	return EXIT_SUCCESS;
}

