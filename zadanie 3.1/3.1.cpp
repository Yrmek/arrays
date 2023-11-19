/*��� ������ ����� �����, ���������� n ���������. ��� ������������ ������������� ����������� �������� �������� ������� ��������� �������: ���
�������� � ��������������, ����������� �������� (� ��� ����� ���������), ���
������ ����������� ��������. ����� ������� ������������� ������� ������� ����� ���� � �������������� ������������ (enum).

2. ����� � ������������� ������� �� ���� �������� 5 ���������� ���������.

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
		cout << "�������� ��� �������������:\n"
		<< (int)enmArrayInit::WithConst  << ". ����������� � ����\n"
		<< (int)enmArrayInit::WithRand  << ". ���������� �������\n"
		<< (int)enmArrayInit::ByUser  << ". ������ �������\n";
	cout << "����� ������ ������ �������� ���������\n"
		"     ��� �����: ";
	int ch = 0;
	cin >> ch;
	switch ((enmArrayInit)ch)
	{
	case enmArrayInit::WithConst:
	{// ������������� ������������ � ���� �����������
		int a[N] = { 1,12,2,51,16,115,135,61 };
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

		//��������� ������� �� ������� N-1 ���
		for (int i = 1; i < N; i++)
			//������ � N-1-�� �������� ����� �� i-��
			for (int j = N - 1; j >= i; j--)
				// ����� ��������� � ������ ������������� �������
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  ����� ���������������� ������� �� �����
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;
		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

	}
		break;

	case enmArrayInit::WithRand:
	{
		// ������������� ���������� ������
		int a[N];
		for (int i = 0; i < N; i++)  // ���������� ������� ��������� �������
			a[i] = rand() % 100;
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

		//��������� ������� �� ������� N-1 ���
		for (int i = 1; i < N; i++)
			//������ � N-1-�� �������� ����� �� i-��
			for (int j = N - 1; j >= i; j--)
				// ����� ��������� � ������ ������������� �������
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  ����� ���������������� ������� �� �����
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;

		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

	}
		break;
	case enmArrayInit::ByUser:
	{
		// ������������� ������ ������������
		int a[N];
		for (int i = 0; i < N; i++)  // ���������� ������� ��������� �������
		{
			cout << "������� ������� ������:";
			cin >> a[i]; //���� �������� ������� � ����������
		}
		cout << " massiv a:" ;

		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

		//��������� ������� �� ������� N-1 ���
		for (int i = 1; i < N; i++)
			//������ � N-1-�� �������� ����� �� i-��
			for (int j = N - 1; j >= i; j--)
				// ����� ��������� � ������ ������������� �������
				if (a[j - 1] > a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}

		//  ����� ���������������� ������� �� �����
		cout << " sorted array a:" ;
		for (int i = 0; i < N; i++)
			cout << setw(8) << a[i];
		cout << endl;

		cout << "5 naibolshih elementov:";
		for (int i = N - 5; i < N; i++)
			cout << setw(8) << a[i]; // ����� ������� �� �����
		cout << endl;

	}
		break;
	default:
		{
			cout << "��������� �����������" << endl;
			return 0;
		}
	}


}
 
