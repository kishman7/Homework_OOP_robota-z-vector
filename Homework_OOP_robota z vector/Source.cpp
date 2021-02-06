#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <algorithm> // ���������� random_shuffle() - ���������� �������� �������

using namespace std;

//Exercise1. ��������� ���� ������� vector<int> :
//v1 � �������, ������ �������� � ���������;
//v2 � 10 �������� ��������;
//v3 � ������� ������ � ���������, �������� ����������� ���������� �����;
//v4 � ��������� �� �������� v1;
//v5 � ��������� �� ������� �� ��������������� �������� v3.
//
//Exercise2. ������� �� �������� ������� v3 �� �����, � �� �������� ������� v1
//� ����������� ������� � ���� �Numbers.txt�.
//
//Exercise3. ��������� �������� ������� v2 ������� 1, 2, 3, ..., 10.
//������������ �������� ������� v2,
//�������� ������ �� ������� ��������,
//������� �������� ������������� ������� �� �����.
//
//Exercise4. ������� ����� ������� ������� v4.���������, (12, 10, 35) �(12,
//	12, 10, 10, 35, 35).
//
//Exercise5. �������� �� �������� ������� v5,
//	c�������� � v5 ���� ���� �������� v4,
//	�������� �������� ������� �������� v5 �����,
//	������� �� ����� ������������ ������.
//
//Exercise6. ������� �������� ������� v4 �� v5.

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(unsigned(time(NULL)));
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	void PrintElemVector(vector<int>); // ������� ������ �������� ������� �� �����
	
# pragma region Exercise1
	//v1 � �������, ������ �������� � ���������;
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

	//v2 � 10 �������� ��������;
	v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cout << "Output elements vector2:" << endl;
	PrintElemVector(v2);


	//v3 � ������� ������ � ���������, �������� ����������� ���������� �����;
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

	//v4 � ��������� �� �������� v1;
	v4.assign(v1.begin(), v1.end()); //������� ��� �� ������ ������� � �����
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);

	//v5 � ��������� �� ������� �� ��������������� �������� v3.
	v5.assign(v3.begin() + 1, v3.end() - 1); // ������� �� ������� �� ��������������� �������� v3
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);
#pragma endregion

#pragma region Exercise2
	system("pause");
	//system("cls");
	cout << "\nExercise 2" << endl;

	//������� �� �������� ������� v3 �� �����
	cout << "Output elements vector3:" << endl;
	PrintElemVector(v3);
	
	// ������� �� �������� ������� v1 � ����������� ������� � ���� �Numbers.txt�.
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

	// ��������� �������� ������� v2 ������� 1, 2, 3, ..., 10.
	v2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Output elements vector2 (1,2.3...10):" << endl;
	PrintElemVector(v2);

	// ������������ �������� ������� v2
	random_shuffle(v2.begin(), v2.end()); // ������������ �������� �������
	cout << "Output mixed elements of vector2: " << endl;
	PrintElemVector(v2);

	// �������� ������ �� ������� ��������
	//v2.erase(v2.begin() + 1);
	//v2.erase(v2.end() - 1);
	//cout << "Output of vector2 elements without element 2 and penultimate element: " << endl;
	//PrintElemVector(v2);
	// �������� ������ �� ������� �������� 
	// ������������� ������ ����� ��������
	vector<int>::iterator it = v2.begin(); // ��������� ��������
	advance(it, 1); // ���������� ��������� �������� ������� �������, ����� ������� ��������
	v2.erase(it);  // ��������� ������ ������� �������
	it = v2.end() - 2; // ���������� ��������� �������� ��������������� �������, ����� ��������������� ��������, ������� 2, ��� end() ����� �� NULL
	v2.erase(it); // ��������� ������������ ������� �������
	cout << "Output of vector2 elements without element 2 and penultimate element: " << endl;
	PrintElemVector(v2);

#pragma endregion

#pragma region Exercise4
	system("pause");
	//system("cls");
	cout << "\nExercise 4" << endl;

	//Exercise4. ������� ����� ������� ������� v4.���������, (12, 10, 35) �(12, 12, 10, 10, 35, 35).
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	vector<int>temp; // ��������� ���������� ������
	for (int i = 0; i < v4.size(); i++) // ���� ��� �������� ��������
	{
		temp.push_back(v4[i]); // ���������� ������ ��� ������� � ���������� ������
		temp.push_back(v4[i]); // ���������� �������� ������� � ���������� ������
	}
	v4.assign(temp.begin(), temp.end()); // ������� �������� � ����������� ������� � ����������
	cout << "Output duplicated elements vector4:" << endl;
	PrintElemVector(v4);
#pragma endregion

#pragma region Exercise5
	system("pause");
	//system("cls");
	cout << "\nExercise 5" << endl;

	//Exercise5. �������� �� �������� ������� v5,
	//	c�������� � v5 ���� ���� �������� v4,
	//	�������� �������� ������� �������� v5 �����,
	//	������� �� ����� ������������ ������.
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);

	// �������� �� �������� ������� v5
	v5.clear(); 
	//	c�������� � v5 ���� ���� �������� v4,
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	for (int i = 0; i < v4.size(); i++)
	{
		if (v4[i]%2 == 0) // �������� �� �������� (�������)
		{
			v5.push_back(v4[i]); // ���������� ���� ���� �����
		}
	}
	cout << "Output elements vector5 after copying paired elements vector4:" << endl;
	PrintElemVector(v5);
	//	������� �� ����� ������������ ������.
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

	//������� �������� ������� v4 �� v5.
	cout << "Output elements vector4:" << endl;
	PrintElemVector(v4);
	cout << "Output elements vector5:" << endl;
	PrintElemVector(v5);
	vector<int>temp1; // ���������� ������
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

void PrintElemVector(vector<int> v) { // ������� ������ �������� ������� �� �����
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}