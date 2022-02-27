// Программа берёт два числа гигантских размеров и складывает их между собой (больше чем длина unsigned long int)
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    
    system("chcp 65001");
    system("cls");

    // ОБъявление переменных
    char input[2][1001];
    int max_size = 0;
    int cur_num;
    int zero_count = -1;
    

    // 0 - первый больше или одинаковы, 1 - второй больше
    bool which_big = 0;

    // Че то вводим
    cout << "Введите БОЛЬШОЕ число: " << endl;
    cin.getline(input[0], 1001);

    cout << "Введите второе БОЛЬШОЕ число: " << endl;
    cin.getline(input[1], 1001);

    // Че то делаем
    if (strlen(input[0]) == strlen(input[1]))
    {
        max_size = 1 + strlen(input[0]);
    }
    else
    {
        max_size = 1 + strlen(input[0]) * (strlen(input[0]) > strlen(input[1])) + strlen(input[1]) * (strlen(input[1]) > strlen(input[0]));
        which_big = (strlen(input[1]) > strlen(input[0]));
    };

    // Объявление массива результата
    char result[1000];
    for (int i = 0; i < 1000; i++)
    {
        result[i] = '0';
    }
    

    // Вычисление разницы в размере двух чисел
    int dif_size;
    if (which_big)
    {
        dif_size = strlen(input[1]) - strlen(input[0]);
    } else {
        dif_size = strlen(input[0]) - strlen(input[1]);
    }
    
    
    // Че то делаем опять
    
    if (which_big)
    {

        for (int i = max_size; i > dif_size + 1; i--)
        {
            cur_num = input[1][i-2] + input[0][i - dif_size - 2] + result[i] - 144;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }



        for (int i = dif_size + 1; i > 1; i--)
        {
            cur_num = input[1][i-2] + result[i] - 96;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }

    } else {

        for (int i = max_size; i > dif_size + 1; i--)
        {
            cur_num = input[0][i-2] + input[1][i - dif_size - 2] + result[i] - 144;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }



        for (int i = dif_size + 1; i > 1; i--)
        {
            cur_num = input[0][i-2] + result[i] - 96;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }

    }    

    // Сдвигаем число если дополнительный разряд не понадобился при сложении
    while (result[0] == '0')
    {   
        for (int i = 0; i < max_size; i++)
        {
            result[i] = result[i+1];
        }
        zero_count++;
    }
    

    // Че то выводим
    cout << "Результат сложения двух введенных чисел: " << endl;
    for (int i = 0; i < max_size - zero_count; i++)
    {
        cout << result[i];
    }
    cout << endl;
    
    // Конец программы
    system("pause");
    return 0;
}