﻿// Laba2_ZI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <cstdlib>
#define ll long long
using namespace std;
ll int A_public = 0;
ll int A_private = 0;
ll int B_public = 0;
ll int B_private = 0;
string message = "Полевая ромашка!";
string enc_message = "";
string dec_message = "";
ll int A_partial = 0;
ll int B_partial = 0;
ll int A_full = 0;
ll int B_full = 0;
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}


bool Miller(ll int p, int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2 == 0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
int Generator() {
    int iteration = 5;
    ll num;
    num = rand()%20+2;
    Miller(num, iteration);
    if (Miller(num, iteration))
        return num;
    else Generator();
}
int partial_key(int public_1, int private_1, int public_2) {
    int partial = pow(public_1, private_1);
    partial %= public_2;
    return partial;
}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    //A_public = Generator();
    //A_private = Generator();
    //B_public = Generator();
    //B_private = Generator();
    cout << message << endl;
    A_public = 13;
    A_private = 7;
    B_public = 11;
    B_private = 3;
    cout <<"A_public: " << A_public << endl;
    cout <<"A_private: "<< A_private << endl;
    cout << "B_public: " << B_public << endl;
    cout << "B_private: " << B_private << endl;
    A_partial = pow(A_public, A_private);
    cout << "Промежуточный A_p: " << A_partial << endl;
    A_partial = A_partial % B_public;
    cout << A_partial << endl;
    B_partial = pow(A_public, B_private);
    cout <<"Промежуточный B_p: " << B_partial << endl;
    B_partial = B_partial % B_public;
    cout << B_partial << endl;
    A_full = pow(B_partial, A_private);
    cout << "Промежуточный A_F : " << A_full << endl;
    A_full = A_full % B_public;
    cout << A_full<<endl;
    B_full = pow(A_partial, B_private);
    cout << "Промежуточный B_F : " << B_full << endl;
    B_full = B_full % B_public;
    cout << B_full<<endl;
    enc_message = "";
    for (int i = 0; i < message.length(); i++) {
        enc_message += char((int)(message[i] + A_full));
    }
    cout << enc_message << endl;
    dec_message = "";
    for (int i = 0; i < enc_message.length(); i++) {
        
        dec_message += char((int)(enc_message[i] - B_full));
    }
    cout << dec_message << endl;
    return 0;
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
