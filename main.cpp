#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int StrToInt(string binaryStr) {
	int result = 0;
	int power = 1;

	for (int i = binaryStr.length() - 1; i >= 0; i--) {
		if (binaryStr[i] == '1')
			result += power;//åñëè 1 - äîáàâëÿåì òåêóùóþ ñòåïåíü äâîéêè
		power *= 2;//óâåëè÷èâàåìì ñòåïåíü
	}
	return result;
}

void BubbleSort(string* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			string first = arr[j].substr(2);//íà÷èíàÿ ñ èíäåêñà 2
			string second = arr[j + 1].substr(2);

			int NumFirst = StrToInt(first);//ïåðåâîäèì â äâî÷èíîå ÷èñëî
			int NumSecond = StrToInt(second);

			if (NumFirst > NumSecond) {
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void TestBubbleSort() {
	cout << "Òåñòèðîâàíèå ñîðòèðîâêè: " << endl;
	int AllTests = 5;
	int DoneTests = 0;
	{
		//òåñò 1 - îáû÷íûé ñëó÷àé
		string data[3] = { "0b1100100", "0b100101", "0b100" };
		string expected[3] = { "0b100", "0b100101", "0b1100100" };
		int size = 3;
		BubbleSort(data, size);

		bool ok;
		for (int i = 0; i < size; i++)
			assert(data[i] == expected[i]);
		DoneTests++;
	}
	{
		//òåñò 2 - îäèí ýëåìåíò
		string data[1] = { "0b1010" };
		string expected[1] = { "0b1010" };
		int size = 1;
		BubbleSort(data, size);
		assert(data[0] == expected[0]);
		DoneTests++;
	}
	{
		//òåñò 3 - óæå îòñîðòèðîâàí
		string data[] = { "0b1", "0b10", "0b11" };
		string expected[] = { "0b1", "0b10", "0b11" };
		int size = 3;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	{
		//òåñò 4 - îäèíàêîâûå ÷èñëà
		string data[] = { "0b101", "0b1", "0b101", "0b1" };
		string expected[] = { "0b1", "0b1", "0b101", "0b101" };
		int size = 4;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	{
		//òåñò 5 - îáðàòíûé ïîðÿäîê
		string data[] = { "0b111", "0b110", "0b101", "0b100" };
		string expected[] = { "0b100", "0b101", "0b110", "0b111" };
		int size = 4;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	cout << "Ïðîéäåíî: " << DoneTests << " èç " << AllTests << endl;
}



int main() {
	setlocale(LC_ALL, "russian");

	int choice;
	cout << "×òî õîòèòå ñäåëàòü? 1 - Çàïóñòèòü ñîðòèðîâêó, 2 - Çàïóñòèòü òåñòû ";
	cin >> choice;

	if (choice == 1) {

		int count;
		string* BinuryNum;
		cout << "Ñêîëüêî ñòðîê ñ äâîè÷íûìè ÷èñëàìè õîòèò ââååñòè? " << endl;
		cin >> count;
		while (count < 1) {
			cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî!" << endl;
			cin >> count;
		}
		BinuryNum = new string[count];
		cout << "Ââíäèòå " << count << " còðîê â ôîðìàòå 0b1010 (ñ ïðåôèêñîì 0b):" << endl;
		for (int i = 0; i < count; i++) {
			cout << "Ñòðîêà " << i + 1 << ":";
			cin >> BinuryNum[i];

			while (BinuryNum[i].length() < 2 || BinuryNum[i].substr(0, 2) != "0b") {
				cout << "Îøèáêà! Ñòðîêà äîëæíà íà÷èíàòüñÿ ñ '0b'. Ïîâòîðèòå ââîä:";
				cin >> BinuryNum[i];
			}
		}
		cout << endl;
		cout << "Âû ââåëè:" << endl;
		for (int i = 0; i < count; i++) {
			cout << BinuryNum[i] << " ";
		}
		cout << endl;

		BubbleSort(BinuryNum, count);

		cout << "Ïîñëå ñîîðòèðîâêè îï âîçðàñòàíèþ: " << endl;
		for (int i = 0; i < count; i++)
			cout << BinuryNum[i] << " ";
		cout << endl;
		delete[]BinuryNum;


	}
	else if (choice == 2) {
		TestBubbleSort();
	}
	else {
		cout << "Íå ñóùåñòâóåò òàêîãî âàðèàíòà!";
		return 1;
	}
	return 0;
}

