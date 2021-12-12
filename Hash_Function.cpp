// Hash_Function.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std;

string salt(string data) {
    string salty_data = data;
	for (int i = 0; i < data.length(); i++)
	{
		salty_data += (char)((int)data[i] + i);
	}
	return salty_data;
}
int hash_function(string data) {
	long int sum = 0;
	for (int i = 0; i < data.length(); i++)
	{
		sum += (int)data[i];
	}
	sum *= sum;
	sum >> 3;
	sum += sum;
	sum << 2;
	sum = sum & (sum<<4);
	//if (sum == 0) hash_function(data);
	return sum;
}


int main()
{	
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	long int hash_result = 0;
	
	string data = "";
	cin >> data;
	cout << "Входная строка: " << data << endl;
	data = salt(data);
    cout << "Солёная строка: "<<data<<endl;
	hash_result = hash_function(data);
	cout << "Результат: " << hash_result << endl;
	string hash_string = "";
	for (int i = 0; hash_string.length()<33; i++)
	{
		char buff = (char)( 48 + ((long int)(hash_result / (pow(i+1,2)))%(122-48)) );
		//cout << "hash: " << hash_result << " i: " << i <<"char buff: "<< (int)buff<< endl;
		 hash_string += buff;
		
	}
	cout << "Хэшированная строка: " << hash_string << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
