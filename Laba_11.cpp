#include <iostream>
#include <fstream>
#include <string> 
#include <algorithm>
#include "math.h"

using namespace std;
//float frequency_internet[33] = { 8.2,1.59,4.4,1.96,2.68,7.98,0.04,1.04,1.89,6.65,1.11,3.39,5.89,3.21,6.74,10.73,2.54,4.53,5.17,4.9,
//                  2.95,0.16,0.87,0.44,1.04,1.3,0.21,0.04,1.90,1.94,0.32,0.64,2.10 };
float frequency_internet[33] = { 8.45,1.59,4.4,1.7,2.62,8.01,0.04,1.44,1.65,6.7,1.21,3.49,6.26,3.21,7.35,10.97,2.81,4.54,5.47,4.73,
              2.98,0.26,0.73,0.48,0.94,0.97,0.36,0.03,1.90,1.74,0.32,0.64,2.01 };
//float frequency_internet[33] = { 8.01, 1.59, 4.54, 1.7, 2.98, 8.45, 0.04, 0.94,1.65, 7.35, 1.21, 3.49, 4.4, 3.21, 6.7, 10.97, 2.81, 4.73,
//5.47, 6.26, 2.62, 0.26, 0.97, 0.48, 1.44, 0.73, 0.36, 0.04, 1.9, 1.74, 0.32, 0.64, 2.01 };
char letter_ = ' ', letter = ' ', letter_line = ' ', letter_line_ = ' ';
float arrn[33] = { 0 };
float arr3[33] = { 0 };
float arr4[33] = { 0 };
int bigramm[33][33] = { 0 };
int encbigramm[33][33] = { 0 };
int sym = 1;
int symn, str, stl, str_, stl_ = 0;
//int i = 0;
int f = 0;
int max1, max1_ = 0;
int max2[10] = { 0 }, max2_[10] = { 0 };
int max_column[10] = { 0 }, max_column_[10] = { 0 };
int max_line[10] = { 0 }, max_line_[10] = { 0 };
string A = "ТАПОКБВГДЕЁЖЗИЙЛМНРСУФХЦЧШЩЪЫЬЭЮЯ";
string a = "тапокбвгдеёжзийлмнрсуфхцчшщъыьэюя";

string text;
string textn;
string textbi;
string B = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
string b = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
string b_orig = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
string   Alphabet_after_sort_enc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
string Alphabet_after_sort_internet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
string bigramm_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

char temp, temp1;

int main()
{
    setlocale(LC_ALL, "Rus");

    //считывание файла в строки textn и textbi
    ifstream file;
    file.open("P:\\War_and_Peace.txt");
    if (file.is_open())
    {
        while (getline(file, text))
        {
            textn = textn + text;
        }
    }
    file.close();
    textbi = textn;
    int alpha[33] = { 0 };
    int alpha_index[33] = { 0 };
    for (int i = 0; i < textn.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (textn[i] == B[j] || textn[i] == b[j]) {
                alpha[j]++;
            }

        }
    }
    for (int i = 0; i < 33; i++) {
        alpha_index[i] = alpha[i];
    }
    sort(alpha, alpha + 33, greater<float>());
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 33; j++) {
            if (alpha_index[i] == alpha[j]) {
                alphabet[j] = b[i];
                break;
            }

        }
    }
    //cout << "Алфавит оригинала: " << alphabet << endl;
    //шифр Цезеря с выбором величины сдвига k
    //ввод k и сдвиг алфавита
    cout << "Введите ключ: ";
    cin >> f;

    for (int j = 0; j < f; j++)
    {
        temp = A[A.length() - 1];
        temp1 = a[a.length() - 1];
        for (int i = A.length(); i >= 1; i--) {
            A[i] = A[i - 1];
            a[i] = a[i - 1];
        }
        A[0] = temp;
        a[0] = temp1;
    }
    //шифрование текста 
    for (int i = 0; i < textn.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (textn[i] == B[j]) {
                textn[i] = a[j];
                break;
            }
            else if (textn[i] == b[j]) {
                textn[i] = a[j];
                break;
            }
        }

    }
    text = textn;
    //вывод шифрованных алфовитов и текста
    cout << "Шифрованный текст: " << endl;
    cout << textn << endl;
    string textnn = textn;
    string textbi_try2 = textn;

    //монограммный анализ
    // подсчёт количества букв
    for (int i = 0; i <= textn.length(); i++) {
        if (textn[i] != ' ' && textn[i] != 'A-Z' && textn[i] != '.' && textn[i] != ',' && textn[i] != ':' && textn[i] != '!' && textn[i] != '?' && textn[i] != '-')
            sym++;
    }


    //вычисление частоты появления каждой буквы
    for (int i = 0; i < textn.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (textn[i] == B[j] || textn[i] == b[j]) {
                arrn[j]++;
            }

        }
    }


    for (int i = 0; i < 33; i++) {
        arr3[i] = arrn[i];
    }
    sort(arrn, arrn + 33, greater<float>());
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 33; j++) {
            if (arr3[i] == arrn[j]) {
                Alphabet_after_sort_enc[j] = b[i];
                break;
            }

        }
    }
    cout << "Alphabet_after_sort_enc" << Alphabet_after_sort_enc;
    for (int i = 0; i < 33; i++) {
        arr4[i] = frequency_internet[i];
    }

    sort(frequency_internet, frequency_internet + 33, greater<float>());
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 33; j++) {
            if (arr4[i] == frequency_internet[j]) {
                Alphabet_after_sort_internet[j] = b[i];
                break;
            }

        }
    }
    //cout << "Alphabet_after_sort_internet " << Alphabet_after_sort_internet << endl;;
    //cout << "Alphabet_after_sort_enc " << Alphabet_after_sort_enc << endl;
    for (int i = 0; i < textn.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (textn[i] == Alphabet_after_sort_enc[j]) {
                textn[i] = Alphabet_after_sort_internet[j];
                //  cout << "молодая котлета " << textn[i];
                break;
            }

        }

    }
    //cout << "\n\nДешифрация монограммами: " << endl;
   // cout << textn << endl;

    //биграмный анализ


    //подсчёт количества пар в оригинальном тексте
    /*int amount = 0;
    for (int k = 0; k < textbi.length() - 1; k++) {
        for (int i = 0; i < b.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (textn[k] == b[i] && textn[k + 1] == b[j]) {
                    amount++;
                    break;
                }
            }
        }
    }*/


    //запись количества биграм в оригинальном тексте в двумерный массив
    bool a = false;
    for (int k = 0; k < textbi.length() - 1; k++) {
        a = false;
        for (int i = 0; i < b.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (textbi[k] == b[i] && textbi[k + 1] == b[j]) {

                    bigramm[i][j]++;
                    a = true;
                    break;
                }
            }
            if (a) break;
        }
    }



    //запись количества биграм в расшифрованном тексте в двумерный массив
    for (int k = 0; k < text.length() - 1; k++) {
        a = false;
        for (int i = 0; i < b.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (textn[k] == b[i] && textn[k + 1] == b[j]) {                    // textnn или textn (???????)
                    encbigramm[i][j]++;
                    a = true;
                    break;
                }
            }
            if (a) break;
        }
    }
    //вывод биграм
    /*
    for (int i = 0;i < b.length();i++) {
        for (int j = 0; j < b.length();j++) {
            cout << bigramm[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            cout << encbigramm[i][j]<<" ";
        }
        cout << endl;
    }*/
    //нахождение максимальных элементов в массиве с шифрованными биграммами и их расположение
    max1 = encbigramm[0][0];
    for (int w = 0; w < 10; w++) {
        for (int q = 0; q < 33; q++)
        {
            for (int j = 0; j < 33; j++)
            {
                if (encbigramm[q][j] > max1)
                {
                    max1 = encbigramm[q][j];
                    str = q;
                    stl = j;
                    max2[w] = max1;
                    max_column[w] = str;
                    max_line[w] = stl;
                    encbigramm[q][j] = 0;


                }

            }

        }
        max1 = encbigramm[0][0];
    }
    /*for (int k = 0; k < 6; k++) {

        cout << max2[k] << " ";
        cout << max_column[k] << " ";
        cout << max_line[k] << " " << endl;

    }*/
    //cout << endl;

    //нахождение максимальных элементов в массиве с оригинальными биграммами и их расположение;
    max1_ = bigramm[0][0];
    for (int w = 0; w < 10; w++) {
        for (int q = 0; q < 33; q++)
        {
            for (int j = 0; j < 33; j++)
            {
                if (bigramm[q][j] > max1_)
                {
                    max1_ = bigramm[q][j];
                    str_ = q;
                    stl_ = j;
                    max2_[w] = max1_;
                    max_column_[w] = str_;
                    max_line_[w] = stl_;
                    bigramm[q][j] = 0;

                }

            }

        }
        max1_ = encbigramm[0][0];
    }
    /*for (int k = 0; k <6; k++) {

        cout << max2_[k] << " ";
        cout << max_column_[k] << " ";
        cout << max_line_[k] << " " << endl;

    }*/
    // cout << endl;
     /*b_orig = alphabet;
     for (int i = 0; i < 6; i++) {
         letter = b[max_column[i]];
         letter_ = b[max_column_[i]];
         cout << letter << endl;
         cout << letter_ << endl;
         for (int j = 0; j < 33; j++) {
             for (int k = 0; k < 33; k++) {
                 if (b_orig[j] == letter && b_orig[k] == letter_)
                     swap(b_orig[j], b_orig[k]);

             }
         }
     }
     for (int i = 0; i < 6; i++) {
         letter = b[max_line[i]];
         letter_ = b[max_line_[i]];
         for (int j = 0; j < 33; j++) {
             for (int k = 0; k < 33; k++) {
                 if (b_orig[j] == letter && b_orig[k] == letter_)
                     swap(b_orig[j], b_orig[k]);

             }
         }
     }*/
     /* cout << "Старый алфавит" << Alphabet_after_sort_enc <<"b "<<b<< endl;
      for (int i = 0; i < 6; i++) {
          letter = b[max_column[i]];
          letter_ = b[max_column_[i]];
          letter_line = b[max_line[i]];
          letter_line_ = b[max_line_[i]];
          cout << letter << endl;
          cout << letter_ << endl;
          for (int j = 0; j < 33; j++) {
              for (int k = 0; k < 33; k++) {
                  if (Alphabet_after_sort_enc[j] == letter && Alphabet_after_sort_enc[k] == letter_) {
                      cout << "ПЕрвые буквы " << Alphabet_after_sort_enc[j] << " " << Alphabet_after_sort_enc[k] << endl;
                      swap(Alphabet_after_sort_enc[j], Alphabet_after_sort_enc[k]);
                  }

              }
          }
      }
      //cout << "новый алфавит\t" << Alphabet_after_sort_enc << endl;;
      for (int i = 0; i < 6; i++) {
          letter = b[max_line[i]];
          letter_ = b[max_line_[i]];
          for (int j = 0; j < 33; j++) {
              for (int k = 0; k < 33; k++) {
                  if (Alphabet_after_sort_enc[j] == letter && Alphabet_after_sort_enc[k] == letter_) {
                      cout << "Вторые буквы " << Alphabet_after_sort_enc[j] << " " << Alphabet_after_sort_enc[k] << "letter " << letter << "letter_" << letter_ << endl;
                      swap(Alphabet_after_sort_enc[j], Alphabet_after_sort_enc[k]);
                  }

              }
          }
      }*/
      //cout << "b_orig\t " << b_orig << endl;
      //cout << "новый алфавит\t" << Alphabet_after_sort_enc << endl;
      //cout << "алфавит интернет\t" << Alphabet_after_sort_internet << endl;
      //cout << "Алфавит оригинала: " << alphabet << endl;
    bool probel = false;
    for (int i = 0; i < textnn.length(); i++) {
        probel = false;
        for (int j = 0; j < B.length(); j++) {
            //cout << "средняя котлета" << textnn[i];

            for (int k = 0; k < 10; k++)
            {
                letter = b[max_column[k]];
                letter_ = b[max_column_[k]];
                letter_line = b[max_line[k]];
                letter_line_ = b[max_line_[k]];

                if (textn[i] == letter && textn[i + 1] == letter_line) {
                    //cout << letter << " " << letter_ << " " << letter_line << " " << letter_line_;
                    textn[i] = letter_;
                    textn[i + 1] = letter_line;
                    i = i + 2;
                    probel = true;
                    break;
                }
            }
            if (probel) break;
            //if (textn[i] == Alphabet_after_sort_enc[j]) { 
               // textn[i] = Alphabet_after_sort_internet[j];
                //cout << "котлета "  << " " << Alphabet_after_sort_enc[j] << " " << Alphabet_after_sort_internet[j] << endl;

             //  break;

           //}
            /*else if (textnn[i] == Alphabet_after_sort_internet[j]) {
                textnn[i] = alphabet[j];
                break;
            }*/

        }

    }
    cout << "\nДешифрация биграммами\n" << textn << endl;


    bool check = false;
    for (int i = 0; i < textbi_try2.length() - 1; i++)


        system("pause");

}