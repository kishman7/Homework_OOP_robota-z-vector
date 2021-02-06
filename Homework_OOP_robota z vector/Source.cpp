#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <algorithm> // п≥дключенн€ random_shuffle() - перетосовуЇ елементи вектора

using namespace std;

//Exercise1. ќголосити пТ€ть вектор≥в vector<int> :
//v1 Ц порожн≥й, ввести елементи з клав≥атури;
//v2 Ц 10 нульових елемент≥в;
//v3 Ц к≥льк≥сть ввести з клав≥атури, елементи згенерувати випадковим чином;
//v4 Ц скоп≥ювати вс≥ елементи v1;
//v5 Ц скоп≥ювати в≥д другого до передостаннього елементи v3.
//
//Exercise2. ¬ивести вс≥ елементи вектора v3 на екран, а вс≥ елементи вектора v1
//у зворотньому пор€дку у файл СNumbers.txtТ.
//
//Exercise3. «аповнити елементи вектора v2 числами 1, 2, 3, ..., 10.
//ѕеретасувати елементи вектора v2,
//видалити другий та останн≥й елементи,
//вивести елементи результуючого вектора на екран.
//
//Exercise4. ѕодвоњти кожен елемент вектора v4.Ќаприклад, (12, 10, 35) Ц(12,
//	12, 10, 10, 35, 35).
//
//Exercise5. ¬идалити вс≥ елементи вектора v5,
//	cкоп≥ювати у v5 лише парн≥ елементи v4,
//	зменшити значенн€ кожного елемента v5 удв≥ч≥,
//	вивести на екран результуючий вектор.
//
//Exercise6. ќбм≥н€ти елементи вектор≥в v4 та v5.

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(unsigned(time(NULL)));
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	void PrintElemVector(vector<int>); // функц≥€ виводу елемент≥в вектора на екран
	
# pragma region Exercise1
	//v1 Ц порожн≥й, ввести елементи з клав≥атури;
	cout << "Exercise 1" << endl;
	int size;
	cout << "Enter size vector1: ";
	cin >> size;

	cout << "Enter " << size << " elements vector1 from the keyboard:" << endl;
	for (int i = 0; i < size; i++)
	{
		int number;
		cin >> number;
		v1.push_back(number);
	}
	cout << "Output elements vector1:" << endl;
	PrintElemVector(v1);

	//v2 Ц 10 нульових елемент≥в;
	v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cout << "Output elements vector2:" << endl;
	PrintElemVector(v2);


	//v3 Ц к≥льк≥сть ввести з клав≥атури, елементи згенерувати випадковим чином;
	int size3;
	cout << "Enter size vector3: ";
	cin >> size3;

	cout << "Enter " << size3 << " elements vector3 from the keyboard:" << endl;
	for (int i = 0; i < size3; i++)
	{
		int number = rand() % 10 + 1;
		v3.push_back(number);
	}
	cout << "Output elements vector3:" << endl;
	PrintElemVector(v3);

	//v4 Ц скоп≥ювати вс≥ елементи v1;
	v4.assign(v1.begin(), v1.end()); //коп≥юЇмо дан≥ ≥з одного вектора в ≥нший
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);

	//v5 Ц скоп≥ювати в≥д другого до передостаннього елементи v3.
	v5.assign(v3.begin() + 1, v3.end() - 1); // коп≥юЇмо в≥д другого до передостаннього елементи v3
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);
#pragma endregion

#pragma region Exercise2
	system("pause");
	//system("cls");
	cout << "\nExercise 2" << endl;

	//¬ивести вс≥ елементи вектора v3 на екран
	cout << "Output elements vector3:" << endl;
	PrintElemVector(v3);
	
	// ¬ивести вс≥ елементи вектора v1 у зворотньому пор€дку у файл СNumbers.txtТ.
	cout << "Output elements vector1:" << endl;
	PrintElemVector(v1);
	cout << "Output revers elements vector1:" << endl;
	reverse(v1.begin(), v1.end());
	PrintElemVector(v1);
	string path = "Numbers.txt";
	ofstream fout;
	fout.open(path);
	if (fout.is_open())
	{
		for (int i = 0; i < v1.size(); i++)
		{
			fout << v1[i] << "\t";
		}
	}
	fout.close();
#pragma endregion

#pragma region Exercise3
	system("pause");
	//system("cls");
	cout << "\nExercise 3" << endl;

	// «аповнити елементи вектора v2 числами 1, 2, 3, ..., 10.
	v2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Output elements vector2 (1,2.3...10):" << endl;
	PrintElemVector(v2);

	// ѕеретасувати елементи вектора v2
	random_shuffle(v2.begin(), v2.end()); // перетусовуЇмо елементи вектора
	cout << "Output mixed elements of vector2: " << endl;
	PrintElemVector(v2);

	// видалити другий та останн≥й елементи
	//v2.erase(v2.begin() + 1);
	//v2.erase(v2.end() - 1);
	//cout << "Output of vector2 elements without element 2 and penultimate element: " << endl;
	//PrintElemVector(v2);
	// видалити другий та останн≥й елементи 
	// використовуЇмо способ через ≥тератор
	vector<int>::iterator it = v2.begin(); // створюЇмо ≥тератор
	advance(it, 1); // присвоюЇмо ≥тератору значенн€ першого ≥ндексу, тобто другого елементу
	v2.erase(it);  // видал€Їмо другий елемент вектора
	it = v2.end() - 2; // присвоюЇмо ≥тератору значенн€ передостаннього ≥ндексу, тобто передостаннього елементу, м≥нусуЇмо 2, так end() вказуЇ на NULL
	v2.erase(it); // видал€Їмо передостанн≥й елемент вектора
	cout << "Output of vector2 elements without element 2 and penultimate element: " << endl;
	PrintElemVector(v2);

#pragma endregion

#pragma region Exercise4
	system("pause");
	//system("cls");
	cout << "\nExercise 4" << endl;

	//Exercise4. ѕодвоњти кожен елемент вектора v4.Ќаприклад, (12, 10, 35) Ц(12, 12, 10, 10, 35, 35).
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	vector<int>temp; // створюЇмо тимчасовий вектор
	for (int i = 0; i < v4.size(); i++) // цикл дл€ подвоЇнн€ елемент≥в
	{
		temp.push_back(v4[i]); // вставл€Їмо перший раз елемент в тимчасовий вектор
		temp.push_back(v4[i]); // вставл€Їмо повторно елемент в тимчасовий вектор
	}
	v4.assign(temp.begin(), temp.end()); // коп≥юЇмо елементи з тимчасового вектора в початковий
	cout << "Output duplicated elements vector4:" << endl;
	PrintElemVector(v4);
#pragma endregion

#pragma region Exercise5
	system("pause");
	//system("cls");
	cout << "\nExercise 5" << endl;

	//Exercise5. ¬идалити вс≥ елементи вектора v5,
	//	cкоп≥ювати у v5 лише парн≥ елементи v4,
	//	зменшити значенн€ кожного елемента v5 удв≥ч≥,
	//	вивести на екран результуючий вектор.
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);

	// ¬идалити вс≥ елементи вектора v5
	v5.clear(); 
	//	cкоп≥ювати у v5 лише парн≥ елементи v4,
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	for (int i = 0; i < v4.size(); i++)
	{
		if (v4[i]%2 == 0) // перев≥рка на кратн≥сть (парн≥сть)
		{
			v5.push_back(v4[i]); // вставл€Їмо лише парн≥ числа
		}
	}
	cout << "Output elements vector5 after copying paired elements vector4:" << endl;
	PrintElemVector(v5);
	//	вивести на екран результуючий вектор.
	for (int i = 0; i < v5.size(); i++)
	{
		v5[i] /= 2;
	}
	cout << "Output elements vector5 after dividing the elements in half:" << endl;
	PrintElemVector(v5);
#pragma endregion

#pragma region Exercise6
	system("pause");
	//system("cls");
	cout << "\nExercise 6" << endl;

	//ќбм≥н€ти елементи вектор≥в v4 та v5.
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);
	vector<int>temp1; // тимчасовий вектор
	temp1.assign(v4.begin(), v4.end());
	v4.assign(v5.begin(), v5.end());
	v5.assign(temp.begin(), temp.end());
	//copy(v5.begin(), v5.end(), back_inserter(v4));
	cout << "Output elements vector4 after copy elements with vector5:" << endl;
	PrintElemVector(v4);
	cout << "Output elements vector5 after copy elements with vector4:" << endl;
	PrintElemVector(v5);

#pragma endregion
	return 0;
}

void PrintElemVector(vector<int> v) { // функц≥€ виводу елемент≥в вектора на екран
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}