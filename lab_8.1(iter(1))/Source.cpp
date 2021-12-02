// ���� ������� �����, ���� ������ ����������� ������� s[0], ..., s[n], ...
// 1. ϳ��������� ������� �������� ������� �� ������� �+�, �-�, �=� � �����������
//s[1], �, s[n].
// 2.  ������� ����� ���� ������� �++�, �--�, �==� ������ ������ �***�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str);
char* Change(char* str);


int main()
{

	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of '+' '=' '-'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}int Count(char* str)
{
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			k++;
		}
	}
	return k;
}char* Change(char* str)
{
	char* buff = new char[strlen(str) * 2];
	int l = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == '+' && str[i + 1] == '+') || (str[i] == '-' && str[i + 1] == '-') || (str[i] == '=' && str[i + 1] == '='))
		{
			buff[l] = '*';
			buff[l + 1] = '*';
			buff[l + 2] = '*';
			l += 3;
			i++;
		}
		else
		{
			buff[l] = str[i];
			l++;
		}
	}
	buff[l] = '\0';
	return buff;

}