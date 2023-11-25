/*. ���� �� ��������� ����������� ������������ ����� ������:
������������ ���������� �����, ���� ��� �������, � �����, ���������� �� ��������� ����� ��� ������ ���� ��������� ����� � �������� ������� (������������),
���� ����� �������. �������� ���������, ������� ������� ��� ������������
����� � ��������� �� � �� b. */

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
        isPrime[i] = true; // ���������� ������������� ���� ������ �������� true ��� ��� ����� ������ ����� �������������
    }
    isPrime[0] = isPrime[1] = false; // 1 � 0 �� ������� �����

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

    for (int i = 0; i < b; i++)
    {
        int SuperPrimeNum = 0;
        int TempSPN = 0;
        int revnum = 0;
        if (isPrime[RevPrime[i]])
        {
            TempSPN = RevPrime[i];
            while (RevPrime[i] > 0)   // ���� ������� �������������� �����
            {
                revnum = revnum * 10 + RevPrime[i] % 10;
                RevPrime[i] /= 10;
            }
            cout << revnum<< "|" << TempSPN << endl;
        }
    }
    return 0;
}