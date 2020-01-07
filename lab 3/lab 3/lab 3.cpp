// lab 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define STR 100000

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

;

struct spis
{
	int		a;
	spis	*pred=NULL;
	spis	*next=NULL;
};
int		kolvo(spis* a);
void	put(spis* a, int chis);
void	vivod(spis* a);

int     main(int argc, char* c[])
{
	setlocale(LC_ALL, "Russian");
	ifstream    vhod(c[1]);
	ofstream    vihod(c[2]);
	char        stroka[STR];
	spis		a;

	if (vhod.is_open() && vihod.is_open())
	{
		//cout << c[1] << endl;
		vhod.getline(stroka, STR);
		cout << stroka << "asd\n";
		put(&a, 21);
		put(&a, 12);
		vivod(&a);
		cout << kolvo(&a) << endl;
	}
	else
	{
		cout << "Файл не открылся" << endl;
	}

	vhod.close();
	vihod.close();
}

void	put(spis *a, int chis)
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
