/** @defgroup group1 The First Group
 *  This is the first group
 *  @{
 */

#include <iostream>
#include <string.h>
#include <math.h>
#include "lib.cpp"

using namespace std;

/** @brief class Number in group1
 * 
 * 
 * 
 * future builds hope to store input numbers as class
 */
class Number {};
/** 
 * Main of function, entry point
 * 
 * In execution the function will ask to input two big numbers size of const input_max_size
 * and will output the result of their sum
 * @return {int} exitcode - if return 0, then program was executed succesfully
 */

int main()
{
    
    system("chcp 65001");
    system("cls");

    // ОБъявление переменныхz
    const int input_max_size = 2000;
    char input_1[input_max_size];
    char input_2[input_max_size];
    int max_size = 0;
    int cur_num;
    int null_count = -1;
    

    // 0 - первый больше или одинаковы, 1 - второй больше
    bool fir_big_or_eq = 0;

    // Вводим исходные данные:
    get_numbers(input_1, input_2, max_size);

    // Вычисляем максимальный размер и выясняем, какое число больше какого:
    if (strlen(input_1) == strlen(input_2))
    {
        max_size = 1 + strlen(input_1);
    }
    else
    {
        max_size = 1 + strlen(input_1) * (strlen(input_1) > strlen(input_2)) + strlen(input_2) * (strlen(input_2) > strlen(input_1));
        fir_big_or_eq = (strlen(input_2) > strlen(input_1));
    };

    // Объявление массива результата
    char result[input_max_size + 1];
    for (int i = 0; i < input_max_size + 1; i++)
    {
        result[i] = '0';
    }
    

    // Вычисление разницы в размере двух чисел
    int dif_size;
    if (fir_big_or_eq)
    {
        dif_size = strlen(input_2) - strlen(input_1);
    } else {
        dif_size = strlen(input_1) - strlen(input_2);
    }
    
    
    // Начинаем сложение в зависимости от того, кто больше кого
    
    if (fir_big_or_eq)
    {
        // Первый больше или равен второму

        // Проходим через все символы, пока не дойдём до конца меньшего, проводим сложение и перенос
        for (int i = max_size; i > dif_size + 1; i--)
        {
            cur_num = input_2[i-2] + input_1[i - dif_size - 2] + result[i] - 144;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }

        // Добавляем остальные символы через все оставшиеся символы, учитывая перенос
        for (int i = dif_size + 1; i > 1; i--)
        {
            cur_num = input_2[i-2] + result[i] - 96;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }

    } else {

        // Второй больше первого

        // Проходим через все символы, пока не дойдём до конца меньшего, проводим сложение и перенос
        for (int i = max_size; i > dif_size + 1; i--)
        {
            cur_num = input_1[i-2] + input_2[i - dif_size - 2] + result[i] - 144;
            result[i] = char(cur_num % 10) + 48;
            result[i-1] += char(cur_num / 10);
        }


        // Добавляем остальные символы через все оставшиеся символы, учитывая перенос
        for (int i = dif_size + 1; i > 1; i--)
        {
            cur_num = input_1[i-2] + result[i] - 96;
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
        null_count++;
    }
    

    // Выводим результат:
    out_result(result, max_size, null_count);
    
    // Конец программы
    pause_prog();
    return 0;
}

/** @} */ // end of group1
