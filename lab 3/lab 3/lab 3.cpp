// lab 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define STR 100000

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct spis
{
	int		a;
	spis	*pred=NULL;
	spis	*next=NULL;
};
int		kolvo(spis* a);
void	put(spis* a, int chis);
void	vivod(spis* a);

spis*	perevod(char mas[STR]);
int		count(int number);

int     main(int argc, char* c[])
{
	setlocale(LC_ALL, "Russian");
	ifstream    vhod(c[1]);
	ofstream    vihod(c[2]);
	string		str;
	spis		*a = new spis;

	if (vhod.is_open() && vihod.is_open())
	{
		string s = "-35";
		int x = atoi(s.c_str());
		cout << x << endl;
		cout << count(x) << endl;

		while (!vhod.eof())
		{
			vhod >> str;
			if ((str[0] >= '0' || str[0] <= '9' || str[0] == '-') && count(atoi(str.c_str())) == str.length())
				put(a, atoi(str.c_str()));
		} 
		vivod(a);
	}
	else
	{
		cout << "Файл не открылся" << endl;
	}

	vhod.close();
	vihod.close();
}

int		count(int number) 
{
	int count = (number == 0 || number < 0) ? 1 : 0;
	while (number != 0) {
		count++;
		number /= 10;
	}
	return count;
}

spis*	perevod(char mas[STR])
{
	
	spis*	a = new spis;
	/*
	int		chis = 0;
	bool	ifchis(false);
	bool	ifotr(false);


	for (int i = 0; i < STR; i++)
	{
		if (mas[i] >= '0' || mas[i] <= '9')
		{
			ifchis = 1;
			chis = chis * 10 + (mas[i]-'0');
		}
		else
		{
			if (mas[i] == '-' && ifchis == 0)
			{
				ifotr = 1;
			}
			else
			{
				if (ifchis == 1)
				{
					if (ifotr == 1)
						chis *= -1;
					put(a, chis);
				}
				

				chis = 0;
				ifchis = 0;
				ifotr = 0;
				if (mas[i] == '\0')
					break;
			}
		}
	}
	*/
	return a;
	

}

void	put(spis *a, int chis)//функции списка
{
	spis* b = new spis;

	b->a = chis;
	while (a->next != NULL)
	{
		a = a->next;
	}
	a->next = b;
	b->pred = a;
}
int		kolvo(spis* a)//1 элемент вводный
{
	int k = 0;
	while (a->next != NULL)
	{
		k++;
		a = a->next;
	}
	return k;
}
void	vivod(spis* a)
{
	while (a->next != NULL)
	{
		cout << a->a << " ";
		a = a->next;
	}
	cout << a->a << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
