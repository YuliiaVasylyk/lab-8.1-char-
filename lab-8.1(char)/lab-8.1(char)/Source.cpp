// Lab_08_1(char).cpp
// <Василик Юлія>
// Лабораторна робота №8.1(char)
// Пошук та заміна символів у літерному рядку 
// Варіант 2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

using namespace std;

int Count(char* s, const char ch)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, ch))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}

char* Change(char* s, const char ch)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, ch))
	{
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "**");
		pos1 = pos2;
	}

	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[101];
	cout << "Введіть літерний рядок:" << endl;
	cin.getline(str, 100);
	char ch[4] = "+-=";
	int k = Count(str, ch[0]) + Count(str, ch[1]) + Count(str, ch[2]);
	cout << "Літерний рядок містить " << k << " символів '+ - ='" << endl;
	char* dest = new char[151];

	Change(str, ch[0]);
	Change(str, ch[1]);
	dest = Change(str, ch[2]);

	cout << "Модифікований літерний рядок: " << dest << endl;

	return 0;
}

