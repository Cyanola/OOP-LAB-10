#include <iostream>

#include <thread>//потоки

#include <chrono>//время
#include <mutex>
using namespace std;

//void DoWork()
//{
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << "ID =" << this_thread::get_id() << "\tDoWork\t"<<i << endl;
//		this_thread::sleep_for(chrono::milliseconds(1000));
//	}
//}
void DoWork(int a, int b)
{

	/*for (size_t i = 0; i < 10; i++)
	{
		cout << "ID =" << this_thread::get_id() << "\tDoWork\t" << i << endl;*/
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "============================\t" << "DoWork STARTED\t=============" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "a + b = " << a + b << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "============================\t" << "DoWork STOPPED\t=============" << endl;
	
}
//mutex mtx;
void Print(char ch)
{
	//mtx.lock();

	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;

	//mtx.unlock();
}
int main0()
{
	setlocale(LC_ALL, "RUS");
//	cout << "START_MAIN" << endl;
//
//	this_thread::sleep_for(chrono::milliseconds(1000));//программа задерживает выполнение кода
//
//cout<< this_thread::get_id() << endl;
//
//cout << "END MAIN" << endl;
	/*thread th(DoWork);
	
	thread th2(DoWork);*/

	//th.detach();
	//thread th(DoWork, 2,3);
	/*for (size_t i = 0; i < 10; i++)
	{
		cout<<"ID ="<< this_thread::get_id()<<"\tmain\t"<<i<<endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}*/
	//DoWork(2, 3);
	/*for (size_t i = 0;true; i++)
	{
		cout << "ID =" << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}*/
	thread t1(Print, '*');
	thread t2(Print, '#');
	

	t1.join();
	t2.join();
	//th2.join();
	return 0;
}