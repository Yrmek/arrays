/*. Один из вариантов определения сверхпростых чисел гласит:
сверхпростым называется число, если оно простое, и число, полученное из исходного числа при записи цифр исходного числа в обратном порядке («перевертыш»),
тоже будет простым. Написать программу, которая выводит все сверхпростые
числа в диапазоне от а до b. */

#include <iostream>// cin cout
#include <iomanip>

using namespace std;

int main() 
{
    setlocale (LC_ALL,"");
    const short int b = 1000; 
    int a = 17;

    bool isPrime[b * 10 + 1];
    for (int i = a ; i <= b * 10; i++) 
    {
        isPrime[i] = true; // изначально присваивается всем числам значение true так как после лишние будут вычеркиваться
    }
    isPrime[0] = isPrime[1] = false; // 1 и 0 не простые числа

    int maxnum = 0;

    for ( int i = 2 ; i * i <= b * 10; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= b * 10 ; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }

    cout << "Простые числа от a до " << b << ":\n" ;

    int RevPrime[b + 1]{};
    for (int i = a ; i <= b; i++) 
    {
        if (isPrime[i])
        {
            cout << i << " ";     // вывод простых чисел для проверки
            RevPrime[i] = i;      // массив простых чисел который впоследствие будет проверяться на сверхпростые числа
            maxnum = i;
        }
    }

    cout << " " << endl;
    cout << "Максимально вычислимое простое число по алгоритму Эратосфена :" << maxnum << endl;

    for (int i = a; i <= b - 1; i++)
    {
        int revnum = 0;
        while (RevPrime[i] > 0)   // цикл который переворачивает числа
        {
            revnum = revnum * 10 + RevPrime[i] % 10;
            RevPrime[i] /= 10;
        }
        RevPrime[i] = revnum;
    }
    cout <<" "<< endl;
    cout << "Сверхпростые числа:" << endl;

    for (int i = 0; i < b; i++)
    {
        int SuperPrimeNum = 0;
        int TempSPN = 0;
        int revnum = 0;
        if (isPrime[RevPrime[i]])
        {
            TempSPN = RevPrime[i];
            while (RevPrime[i] > 0)   // цикл который переворачивает числа
            {
                revnum = revnum * 10 + RevPrime[i] % 10;
                RevPrime[i] /= 10;
            }
            cout << revnum<< "|" << TempSPN << endl;
        }
    }
    return 0;
}