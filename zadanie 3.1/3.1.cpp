/*Дан массив целых чисел, содержащий n элементов. Для тестирования предусмотреть возможность задавать элементы массива различным образом: при
описании с инициализацией, присвоением значений (в том числе случайных), или
вводом необходимых значений. Выбор способа инициализации массива сделать через меню с использованием перечисления (enum).

2. Найти в целочисленном массиве за один просмотр 5 наибольших элементов.

*/

#include <iomanip>           // setw
#include <stdlib.h>          // rand  srand

#include <iostream>          // cin cout

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	const int N = 8;
	enum class enmArrayInit
	{
		Uninited ,
		WithConst ,
		WithRand,
		ByUser,
	};
		cout << "Выберите тип инициализации:\n"
		<< (int)enmArrayInit::WithConst  << ". константами в коде\n"
		<< (int)enmArrayInit::WithRand  << ". случайными числами\n"
		<< (int)enmArrayInit::ByUser  << ". ввести вручную\n";
	cout << "Любая другая кнопка завершит программу\n"
		"     Ваш выбор: ";
	int ch = 0;
	cin >> ch;
	switch ((enmArrayInit)ch)
	{
	case enmArrayInit::WithConst:
	{// инициализация прописанными в коде константами
		int a[N] = { 1,12,2,51,16,115,135,61 };
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

		//повторять проходы по массиву N-1 раз
		for (int i = 1; i < N; i++)
			//проход с N-1-го элемента вверх до i-го
			for (int j = N - 1; j >= i; j--)
				// обмен элементов в случае неправильного порядка
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  вывод отсортированного массива на экран
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;
		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

	}
		break;

	case enmArrayInit::WithRand:
	{
		// инициализация случайными числам
		int a[N];
		for (int i = 0; i < N; i++)  // заполнение массива рандомныи числами
			a[i] = rand() % 100;
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

		//повторять проходы по массиву N-1 раз
		for (int i = 1; i < N; i++)
			//проход с N-1-го элемента вверх до i-го
			for (int j = N - 1; j >= i; j--)
				// обмен элементов в случае неправильного порядка
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  вывод отсортированного массива на экран
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;

		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

	}
		break;
	case enmArrayInit::ByUser:
	{
		// инициализация вводом пользователя
		int a[N];
		for (int i = 0; i < N; i++)  // заполнение массива рандомныи числами
		{
			cout << "введите элемент масива:";
			cin >> a[i]; //ввод элемента массива с клавиатруы
		}
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

		//повторять проходы по массиву N-1 раз
		for (int i = 1; i < N; i++)
			//проход с N-1-го элемента вверх до i-го
			for (int j = N - 1; j >= i; j--)
				// обмен элементов в случае неправильного порядка
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  вывод отсортированного массива на экран
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;

		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // вывод массива на экран
		cout << endl;

	}
		break;
	default:
		{
			cout << "Программа завершается" << endl;
			return 0;
		}
	}


}
 
