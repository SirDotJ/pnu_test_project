#include <iostream>

void pause_prog()
{
    cin.get();
    return;
}

void out_result(char *result)
{
    cout << "Результат сложения двух введенных чисел: " << endl;
    for (int i = 0; i < max_size - zero_count; i++)
    {
        cout << result[i];
    }
    cout << endl;
    return;
}

void get_numbers(char *&input_1, char *&input_2)
{
    cout << "Введите БОЛЬШОЕ число: " << endl;
    cin.getline(input[0], input_max_size);

    cout << "Введите второе БОЛЬШОЕ число: " << endl;
    cin.getline(input[1], input_max_size);
    return;
}