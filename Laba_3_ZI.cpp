// Laba_3_ZI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "BigInteger\BigIntegerLibrary.hh"
#define ull BigInteger
using namespace std;
ull  p, SK, PK;
ull  d;
ull  m = 0;
ull  x = 0;
ull  phi = 0;
ull  q = 0;
ull  n = 0;
int e = 2;
int div1 = 2;
ull arr[100] = { 0 }, b[100] = { 0 }, c[100] = { 0 };

ull* prime_factors(ull a, ull arr[]) {
    //cout << "a" << a << endl;
    int i = 0;
    while (a != 1) {
        if (a % div1 == 0) {
            arr[i] = div1;

            //cout << "arr[i]" << arr[i] << endl;
            i++;
            a = a / div1;
        }
        else
            if (div1 == 2) div1++;
            else div1 += 2;

    }
    div1 = 2;
    return arr;

}
ull mulmod(ull a, ull b, ull mod)
{
    ull x = 0, y = a % mod;
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

ull modulo(ull base, ull exponent, ull mod)
{
    ull x = 1;
    ull y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}


bool Miller(ull p, int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2 == 0)
    {
        return false;
    }
    ull s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ull a = rand() % (p - 1) + 1 ,temp = s;
        ull mod = modulo(a, temp, p);
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
ull Generator() {
    int iteration = 5;
    ull num;
    num = rand();
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
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    p = Generator();
    //cout << "p = " << p << endl;
    q = Generator();
    //cout << "q = " << q << endl;
    n = p * q;
    //cout << "n = " << n << endl;
    phi = (p - 1) * (q - 1);
    cout << "phi = " << phi << endl;
    //cout << "e = " << e << endl;
    int* t;
    int* t1;
    
    t1 = prime_factors(phi, c);
    //cout << "массив простых множителей e" << "\t" << "массив простых множителей phi" << endl;
    //for (int j = 0; j < 100; j++) {

    //    cout << t[j] << "\t" << t1[j] << endl;
    //}


    for (int i = 0; i < sizeof(t); i++) {
        for (int j = 0; j < sizeof(t1); j++) {
            
            t = prime_factors(e, b);
            if (t[i] == t1[j] && t[i] != 0 && t1[j] != 0) {
                e++;
                //cout << e << endl;
                t = prime_factors(e, b);
                t1 = prime_factors(phi, c);
                i = 0;
                j = 0;
            }

        }
    }
    cout << e << endl;
    string message = "Привет";
    cout << message << endl;
    while ((d * e) % phi != 1) {
        d++;
    }
    cout << "d = " << d<<endl;
   // d = (int)pow(e, (-1)) % phi;

    for (int i = 0; i < message.length(); i++) {
        unsigned char bb = message[i];
        m = (int)bb;
        x = (pow(m, e));
        x= x % n;
        cout << "x"<< x<<endl;
        //cout << "x = " << x;
        message[i] = unsigned((char)(x));

        //cout << "m = " << m;

    }
    cout <<"Зашифрованное сообщение"<< message << endl;
    for (int i = 0; i < message.length(); i++) {
        m = (int)(message[i]);
        m = pow(x, d);
        m= m % n;
        message[i] = (char)(m);

    }
    cout <<"расшифрованное сообщение "<< message << endl;



    //(d*e)mod phi =1
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
