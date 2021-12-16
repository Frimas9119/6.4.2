#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;

}

double Min(int* a, const int size)
{
	int z = 0;
	int min = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
			z = i;
		}
	}
	return z + 1;
}
int Math(int* a, const int size, int z) {
	int rez = 0;
	for (int i = 0; i <= size;i++) {
		if (a[i] < 0) {
			for (int x = i + 1;x < size;x++) {
				if (a[x] < 0) {
					return rez;
				}
				else {
					rez = rez + a[x];
				}
			}
		}
	}
}

/*void Math2(int* a, int* b, const int size) {
	int k = 0;
	for (int i = 0; i < size;i++) {
		if (abs(a[i]) < 1) {
			b[k] = a[i];
			k++;
		}
	}
	int m = size;
	for (int i = 0; i < size;i++) {
		if (abs(a[i]) >= 1) {
				b[m] = a[i];
				m--;
		}
	}
	for (int i = 0; i < size;i++) {
		cout << " " << b[i];
	}
}*/

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cin >> n;
	int* arr = new int[n];
	int* b = new int[n];
	int Low = -2;
	int High = 10;
	Create(arr, n, Low, High, 0);
	Print(arr, n, 0);
	cout << "Num elem: " << Min(arr, n) << endl;
	cout << "Sum: " << Math(arr, n, 0) << endl;
	//Math2(arr, b, n);
	delete[] arr;
	delete[] b;
	return 0;
}