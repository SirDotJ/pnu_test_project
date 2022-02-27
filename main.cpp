// Программа берёт два числа гигантских размеров и складывает их между собой (больше чем длина unsigned long int)
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    
    system("chcp 65001");
    system("cls");

    // ОБъявление переменныхz
    int input_max_size;
    const int input_max_size = 2000;
    char input_1[input_max_size];
    char input_2[input_max_size];
    int max_size = 0;
    int cur_num;
    int zero_count = -1;
    

    // 0 - первый больше или одинаковы, 1 - второй больше
    bool fir_big_or_eq = 0;

    // Че то вводим
    cout << "Введите БОЛЬШОЕ число: " << endl;
    cin.getline(input_1, input_max_size);

    cout << "Введите второе БОЛЬШОЕ число: " << endl;
    cin.getline(input_2, input_max_size);

    // Че то делаем
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
        zero_count++;
    }
    

    // Выводим результат
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