/**
 * @file Errors.h
 * @author Жиганов К.А.
 * @version 1.0
 * @date 09.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля Errors
 */

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Класс обработки ошибок
 * @param File путь к файлу с журналом ошибок
 */
class Errors
{
public:
    string get_File_Log();
    void set_File_Log(string file);

    void error_recording(string flag, string info);

private:
    string File;
};
