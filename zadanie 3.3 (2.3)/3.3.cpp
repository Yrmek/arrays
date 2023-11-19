/*. ���� �� ��������� ����������� ������������ ����� ������:
������������ ���������� �����, ���� ��� �������, � �����, ���������� �� ��������� ����� ��� ������ ���� ��������� ����� � �������� ������� (������������),
���� ����� �������. �������� ���������, ������� ������� ��� ������������
����� � ��������� �� � �� b. */

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
        isPrime[i] = true; // ���������� ������������� ���� ������ �������� true ��� ��� ����� ������ ����� �������������
    }
    isPrime[0] = isPrime[1] = false; // 1 � 0 �� ������� �����

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
    cout << "������� ����� �� a �� " << b << ":\n";

    int RevPrime[b + 1]{};

    for (int i = a ; i <= b; i++) 
    {
        if (isPrime[i])
        {
            cout << i << " ";     // ����� ������� ����� ��� ��������
            RevPrime[i] = i;      // ������ ������� ����� ������� ������������ ����� ����������� �� ������������ �����
        }
    }

    for (int i = a; i <= b - 1; i++)
    {
        int revnum = 0;
        while (RevPrime[i] > 0)   // ���� ������� �������������� �����
        {
            revnum = revnum * 10 + RevPrime[i] % 10;
            RevPrime[i] /= 10;
        }
        RevPrime[i] = revnum;
    }

    cout <<" "<< endl;
    cout << "������������ �����:" << endl;

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