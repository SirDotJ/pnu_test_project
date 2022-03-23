/** @defgroup group2 The Second Group
 *  This is the second group
 *  @{
 */
#ifndef LIB_H
#define LIB_H
#include <iostream>

/*!
* \brief const input_max_size - определяет максимальное количество
* входящих цифр в введенные числа.
* \fn input_max_size
*/
const int input_max_size = 2000;


/**
* \brief Function pause_prog() puts the program on pause until the user hits any
* button on their keyboard
*/
void pause_prog() {
    std::cin.get();
    return;
}
/*! 
 * \brief pause_prog function.
 *
 * Details about pause_prog function.
 */

/** \fn void pause_prog() 
 *  \brief pause program..
 *  \exception std::out_of_range parameter is out of range..
 */

/**
* \brief Function out_result outputs given char pointer contents
* into the terminal
* 
* \param{char*} *result - The char pointer function will print out
* \param{int} max_size - The max size a given char pointer can be
* \param{int} zero_count - the ammount of zeros at the end of the char massive (which are not counting towards its value)
*/
void out_result(char* result, int max_size, int zero_count) {
    std::cout << "Результат сложения двух введенных чисел: " << std::endl;
    for (int i = 0; i < max_size - zero_count; i++)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
    return;
}
/*!
 * \brief out_result function.
 *
 * Details about out_result function.
 */

/*! \fn void out_result(char* result, int max_size, int zero_count) 
 *  \brief A example function.
 *  \param result char pointer to output.
 *  \param max_size an integer.amount of max characters that can be output
 *  \param zero_count an integer amount of.0 which dont count to poionter value
 *  \exception std::out_of_range parameter is out of range.
 */

/**
* \brief Function get_numbers gets tells the user to input two big numbers and reads users input
* 
* \param{char*} *input_1 - first char pointer the user will enter
* \param{char*} *input_2 - second char pointer the user will enter
* \param{int} input_max_size - the max ammount of characters user can enter
*/
void get_numbers(char* input_1, char* input_2, int input_max_size) {
    std::cout << "Введите БОЛЬШОЕ число: " << std::endl;
    std::cin.getline(input_1, input_max_size);

    std::cout << "Введите второе БОЛЬШОЕ число: " << std::endl;
    std::cin.getline(input_2, input_max_size);
    return;
}
/*! 
 * \brief get_numbers function.
 *
 * Details about get_numbers function.
 */

/** \fn void get_numbers(char* input_1, char* input_2, int input_max_size) 
 *  \brief A example function.
 *  \param input_1 first char pointer to input
 *  \param input_2 second char pointer to input
 *  \param input_max_size an integer ammount of characters that can be input into a pointer
 *  \exception std::out_of_range parameter is out of range.
 */
    
    #endif

/** @} */ // end of group2