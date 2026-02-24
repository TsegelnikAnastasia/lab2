/* Даны натуральное число n и вещественные числа
d1, d2, …, d8. Верно ли, что произведение вещественных
чисел больше n? */

#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");

	int n;
	double d1, d2, d3, d4, d5, d6, d7, d8;
	double composition;
	cout << "Введите натуральоне число n " << endl;
	cin >> n;
	if (n < 1) {
		cout << "Не натуралное число";
		return 1;
	}
	cout << "Введите вещетсвенные числа d1, d2, …, d8" << endl;
	cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7 >> d8;
	composition = d1 * d2 * d3 * d4 * d5 * d6 * d7 * d8;
	if (composition > n) {
		cout << "Произведение больше натурального числа - верно" << endl;
	}
	else if (composition < n) {
		cout << "произвдение меньше натурльного числа - неверно" << endl;
	}
	else cout << "равны - неверно " << endl;


	return 0;
}