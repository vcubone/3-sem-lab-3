// lab 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define STR 100000

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>

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

int comb(int* sort, int size);
int		count(int number);

int     main(int argc, char* c[])
{
	setlocale(LC_ALL, "Russian");
	ifstream    vhod(c[1]);
	ifstream	vhodv2(c[1]);
	ofstream    vihod(c[2]);
	string		str;
	spis		*a = new spis;
	int			strkol(0);
	int			strlen(0);

	unsigned int start_time = clock();
	if (vhod.is_open() && vihod.is_open() && vhodv2.is_open())
	{
		while (!vhod.eof())//считывание с файла в список
		{
			vhod >> str;
			if ((str[0] >= '0' || str[0] <= '9' || str[0] == '-') && count(atoi(str.c_str())) == str.length())
				put(a, atoi(str.c_str()));
		}

		while (!vhodv2.eof())
		{
			getline(vhodv2, str);
			strkol++;
			strlen += str.length();
		}
		
		int		kolich = kolvo(a);//список в массив
		int*	mas = new int[kolich];
		spis*	j = a->next;
		for (int i = 0; i < kolich; i++)
		{
			mas[i] = j->a;
			j = j->next;
		}
		
		
		if (argc > 3 && c[3][0] == '-' &&c[3][1] == 't' && c[3][2] == '\0')
		{
			comb(mas, kolich);
		}

		int maxsimv = STR;//вывод в файл
		int kolichstr = strkol;
		if (kolich > 0)
			vihod << mas[0];
		for (int i = 1; i < kolich; i++)
		{
			if (maxsimv - count(mas[i]) - 1 >= 0)
			{
				vihod <<" "<< mas[i];
			}
			else
			{
				vihod << endl;
				kolichstr--;
				vihod <<" "<< mas[i];
				maxsimv = STR;
			}
		}
		for (kolichstr; kolichstr > 1; kolichstr--)
		{
			vihod << endl;
		}



	}
	else
	{
		cout << "Файл не открылся" << endl;
	}
	
	unsigned int end_time = clock();
	cout << start_time - end_time << " " << strlen / strkol << " " << strkol << endl;//вывод в командную строку
	

	vhodv2.close();
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

int comb(int* sort, int size)// sort-название массива, size-размер массива,если нужно ввести массив с клавиатуры, то нужно создать динамический массив
{
	int n = 0; // количество перестановок
	double fakt = 1.2473309; // фактор уменьшения
	double step = size - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < size; ++i)
		{
			if (sort[i] > sort[i + (int)step])
			{
				swap(sort[i], sort[i + (int)step]);
				n++;
			}
		}
		step /= fakt;
	}
	// сортировка пузырьком
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (sort[j] > sort[j + 1]) {
				swap(sort[j], sort[j + 1]);
				swapped = true;
				++n;
			}
		}

		if (!swapped)
			break;
	}
	return n;
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
