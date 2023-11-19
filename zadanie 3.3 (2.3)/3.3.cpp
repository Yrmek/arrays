/*. Один из вариантов определения сверхпростых чисел гласит:
сверхпростым называется число, если оно простое, и число, полученное из исходного числа при записи цифр исходного числа в обратном порядке («перевертыш»),
тоже будет простым. Написать программу, которая выводит все сверхпростые
числа в диапазоне от а до b. */

#include <iostream>// cin cout
using namespace std;

int main() 
{
    setlocale (LC_ALL,"");
    const short int b = 100; 
    int a = 9;

    bool isPrime[b + 1];
    for (int i = a ; i <= b; i++) 
    {
        isPrime[i] = true; // изначально присваивается всем числам значение true так как после лишние будут вычеркиваться
    }
    isPrime[0] = isPrime[1] = false; // 1 и 0 не простые числа

    for ( int i = 2 ; i * i <= b; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= b; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
    cout << "Простые числа от a до " << b << ":\n";

    int RevPrime[b + 1]{};

    for (int i = a ; i <= b; i++) 
    {
        if (isPrime[i])
        {
            cout << i << " ";     // вывод простых чисел для проверки
            RevPrime[i] = i;      // массив простых чисел который впоследствие будет проверяться на сверхпростые числа
        }
    }

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

    for (int i = a; i <= b; i++)
    {
        int k = 2;
        int SuperPrimeNum = 0;

        while (k < RevPrime[i])
        {
            if (RevPrime[i] % k != 0) SuperPrimeNum = RevPrime[i];
            else
            {
                continue;
                k++;
            }
            k++;
        }

        if (SuperPrimeNum != 0) cout << SuperPrimeNum << " ";
    }

    return 0;
}