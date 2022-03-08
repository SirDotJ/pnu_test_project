#include "lib.h"

void pause_prog()
{
    std::cin.get();
    return;
}

void out_result(char *result, int max_size, int zero_count)
{
    std::cout << "Результат сложения двух введенных чисел: " << std::endl;
    for (int i = 0; i < max_size - zero_count; i++)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
    return;
}

void get_numbers(char *input_1, char *input_2, int input_max_size)
{
    std::cout << "Введите БОЛЬШОЕ число: " << std::endl;
    std::cin.getline(input_1, input_max_size);

    std::cout << "Введите второе БОЛЬШОЕ число: " << std::endl;
    std::cin.getline(input_2, input_max_size);
    return;
}