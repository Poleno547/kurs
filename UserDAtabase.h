/**
 * @file UserDAtabase.h
 * @author Жиганов К.А.
 * @version 1.0
 * @date 13.11.2024
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля DataReader
 */

#include "Errors.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Класс для получения БД клиентов
 * @param File путь к файлу с БД клиентов
 * @param Err объект класса Errors обработки ошибок
 */
class DataReader
{
public:
    string get_File();
    void set_File(string file);

    pair<vector<string>, vector<string>> getClient();

private:
    string File;
    Errors Err;
};
