// Программа берёт два числа гигантских размеров и складывает их между собой (больше чем длина unsigned long int)
#include <iostream>
#include <string.h>
#include <math.h>
#include "lib.h"

using namespace std;

int main()
{
    
    system("chcp 65001");
    system("cls");

    // ОБъявление переменных
    const int input_max_size = 2000;
    char input[2][input_max_size];
    int max_size = 0;
    int cur_num;
    int zero_count = -1;
    

    // 0 - первый больше или одинаковы, 1 - второй больше
    bool which_big = 0;

    // Че то вводим
    get_numbers(input[0], input[1], max_size);

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
    char result[input_max_size + 1];
    for (int i = 0; i < input_max_size + 1; i++)
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
    out_result(result, max_size, zero_count);
    
    // Конец программы
    pause_prog();
    return 0;
}