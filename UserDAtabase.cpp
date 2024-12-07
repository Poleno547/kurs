/**
 * @file UserDAtabase.cpp
 */
#include "UserDAtabase.h"

/**
 * @brief Геттер для атрибута File
 */
string DataReader::get_File() { return File; }

/**
 * @brief Сеттер для атрибута File
 */
void DataReader::set_File(string file) { File = file; }

/**
 * @brief Функция для получения БД клиентов
 * @return Возращает два вектора: логины и пароли клиентов
 * @throw Errors при возникновении ошибки
 */
pair<vector<string>, vector<string>> DataReader::getClient()
{
    vector<string> firstVector;
    vector<string> secondVector;

    ifstream inputFile(get_File());

    if(!inputFile.is_open()) {
        inputFile.close();
        Err.error_recording("критичная", "Fun: getClient. Файла с БД открыть невозможно.");

    } else if(inputFile.peek() == std::ifstream::traits_type::eof()) {
        inputFile.close();
        Err.error_recording("критичная", "Fun: getClient. Файл с БД пуст.");

    }

    else {
        std::string line;
        while(std::getline(inputFile, line)) {
            std::istringstream ss(line);
            std::string first, second;

            // Чтение двух строк, разделенных пробелом
            if(std::getline(ss, first, ':') && std::getline(ss, second, ':')) {
                firstVector.push_back(first);
                secondVector.push_back(second);
            }
        }

        inputFile.close();
    }

    return std::make_pair(firstVector, secondVector);
}
