#include <iomanip>           // setw
#include <stdlib.h>          // rand  srand
#include <time.h>            // time
#include <iostream>          // cin cout

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
    const int n = 6;
    int A[n][n]; //��������� �������
    int B[n][n]; //�������� �������
    for (int i = 0; i < n; i++ )
    {
        A[i][n] = rand() % 100;
    }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = rand() % 100;      // ���������� ������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << A[i][j]; // ����� ��������� �������
		cout << endl; 
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			//������ � N-1-�� �������� ����� �� i-��
			for (int k = n - 1; k >= i; k--)
				// ����� ��������� � ������ ������������� �������
				if (A[i][k - 1] > A[i][k])
				{
					int x = A[i][k - 1];
					A[i][k - 1] = A[i][k];
					A[i][k] = x;
				}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << A[i][j];
		cout << endl;
	}
	*/
	
	for (int i = 0; i < n; i++) // ���������� �������� ������� B
	{
			for (int j = 0; j < n; j++)
			{
				for (int k = i; k >= 0; k--)
				{
					int max = 0;
					
					for (int m = j; m < n; m++)
					{
						if (A[k][m] > max)
						{
							max = A[k][m];
						}
					}
					if (B[i][j]< max)
					B[i][j] = max;
				}
				
			}
	}
	cout << "   " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << B[i][j]; // ����� ��������� �������
		cout << endl;
	}

		return 0;
}