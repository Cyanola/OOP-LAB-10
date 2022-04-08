#include <iostream>
#include <thread>//потоки
#include <string>
#include <chrono>//время
#include <ctime>
#include <mutex>
#include <iomanip>

using namespace std;
#define row 5
#define col 5
#define n 5

mutex mtx;

void func(double arr[row][col], int i, double mas[n])
{
	double sum = 0;
	int a = 0;
	int j = 0;

	cout << "\t\t\t\t_______________" << endl;
	cout << "\t\t\t\tРабота " << i + 1 << " потока" << "\n";
	cout << "\t\t\t\t_______________" << endl << endl;
	cout << "\nПоток " << this_thread::get_id() << "\t\t";
	arr[i][j] *= mas[a];
	arr[i][j + 1] *= mas[a + 1];
	arr[i][j + 2] *= mas[a + 2];
	arr[i][j + 3] *= mas[a + 3];
	arr[i][j + 4] *= mas[a + 4];

	mtx.lock();

	this_thread::sleep_for(chrono::milliseconds(1000));

	cout << arr[i][j]; this_thread::sleep_for(chrono::milliseconds(300));	cout << " + ";	this_thread::sleep_for(chrono::milliseconds(300));

	cout << arr[i][j + 1];	this_thread::sleep_for(chrono::milliseconds(300)); cout << " + ";	this_thread::sleep_for(chrono::milliseconds(300));

	cout << arr[i][j + 2]; 	this_thread::sleep_for(chrono::milliseconds(300));	cout << " + "; this_thread::sleep_for(chrono::milliseconds(300));

	cout << arr[i][j + 3];	this_thread::sleep_for(chrono::milliseconds(300));	cout << " + "; this_thread::sleep_for(chrono::milliseconds(300));

	cout << arr[i][j + 4]; 	this_thread::sleep_for(chrono::milliseconds(300));	cout << " = ";


	sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3] + arr[i][j + 4];

	for (int m = 0; m < 10; m++)
	{
		this_thread::sleep_for(chrono::milliseconds(300));
		putchar('.');
	}

	cout << "" << sum << "" << "\n\n";
	mtx.unlock();

}
void Z(double arr[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
		cout << "\n";
	}
	cout << endl;
}
void Z2(double arr[row][col])
{
	cout << "Матрица: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}
void Loading()
{
	string c = "|", f = "__";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
	cout << "\t\t\tLoading";
	for (int s = 0; s < 10; s++)
	{
		this_thread::sleep_for(chrono::milliseconds(300));
		putchar('.');
	}
	cout << "\n";
	cout << "\t\t\t\t\t";
	for (int w = 0; w < 20; w++)
	{
		cout << f;
	}
	cout << endl;
	cout << "\t\t\t\t\t";
	for (int w = 0; w < 10; w++)
	{
		this_thread::sleep_for(chrono::milliseconds(300));
		cout << c << " . ";
	}
	cout << c;
	cout << endl;
	cout << "\t\t\t\t\t";
	for (int w = 0; w < 20; w++)
	{
		cout << f;
	}
	this_thread::sleep_for(chrono::milliseconds(3000));
}
void Z1(double arr[row][col], double mas[n])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0, a = 0; j < col; a++, j++)
		{

			cout << a + 1 << ") " << arr[i][j] << " * " << mas[a] << " = " << arr[i][j] * mas[a] << "     ";

		}
		cout << "\n";
	}
	cout << "\n";
	cout << endl;
}
//void Z1(double arr[row][col], double mas[n])
//{
//	for (int a = 0; a < n; a++)
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				cout << a + 1 << ") " << arr[i][j] << " * " << mas[a] << " = " << arr[i][j] * mas[a] << "     ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//	}
//	cout << endl;
//}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	double arr[row][col];
	double mas[n];
	cout << "Введите вектор: ";
	for (int a = 0; a < n; a++)
	{
		cin >> mas[a];
	}
	
	Z(arr);
	
	system("cls");

	Loading();
	system("cls");
	Z1(arr, mas);
	cout << "Вектор: ";
	for (int a = 0; a < n; a++)
	{
		cout << mas[a] << " ";
	}
	cout << "\n\n";
	Z2(arr);

	thread th(func, arr, 0, mas);
	th.join();

	thread th1(func, arr, 1, mas);
	th1.join();

	thread th2(func, arr, 2, mas);
	th2.join();

	thread th3(func, arr, 3, mas);
	th3.join();

	thread th4(func, arr, 4, mas);
	th4.join();


	system("pause");
	return 0;
}
