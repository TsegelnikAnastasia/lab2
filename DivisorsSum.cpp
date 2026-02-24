
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int sum = 0;
	bool IsAre = false;

	cout << "все целые числа из промежутка от 100 до 300, у которых сумма делителей равна 50" << endl;

	for (int i = 100; i <= 300; i++) {
		sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == 50) {
			cout << i << " ";
			IsAre = true;
		}
	}

	if (!IsAre) cout << "таких числе нет";
	return 0;

}