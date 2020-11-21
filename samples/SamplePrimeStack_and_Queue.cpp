
#include <iomanip>
#include "Queue.h"
#include "Stack.h"
#include <stack>


int main() // Демонстрация работы стека
{
	setlocale(LC_ALL, "Russian");
	int A = 1, B = 2, C = 3;
	Stack<int> a(3);
	a.push(A);
	a.push(B);
	a.push(C);

	cout << "Демонстрация работы стека" << endl;
	cout << "Вывод адреса С:" << &(a.pop()) << endl; 
	cout << "B=" << a.pop() << endl; 

	int D, E, F;
	D = 4; E = 5; F = 7;
	int* mas = new int[3];
	mas[0] = D;
	mas[1] = E;
	mas[2] = F;
	void* t = mas;
	Stack<int>d;
	d.SetMemory(t, 3);

	cout << "Метод SetMemory" << endl;
	cout << d.pop() << endl;
	cout << d.pop() << endl;
	cout << d.pop() << endl;
//---------------------------------------------------------------------------------------------//
// Демонстрация работы очереди

	Queue<int> b(3);
	b.push(A);
	b.push(B);
	b.push(C);
	
	cout << "Демонстрация работы очереди" << endl;
	cout << "A=" << b.pop() << endl; 	
//---------------------------------------------------------------------------------------------//


// Доп. задания

	cout << "Демонстрация работы доп. заданий" << endl;

	A = -1;
	B = 6;
	C = 27;
	D = 3;
	E = 0;

	Queue<int> c(5);
	c.push(A);
	c.push(B);
	c.push(C);
	c.push(D);
	c.push(E);

	cout << c.find(3) << endl;



	A = 1;
	B = 6;
	C = 4;
	D = 3;
	E = 10;
	F = 2;

	Stack<int> ee(6);
	ee.push(A);
	ee.push(B);
	ee.push(C);
	ee.push(D);
	ee.push(E);
	ee.push(F);
	
	ee.transform();

	cout << ee.pop() << " ";
	cout << ee.pop() << " ";
	cout << ee.pop() << " ";
	cout << ee.pop() << " ";
}
