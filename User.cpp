#include "User.h"

#include <iomanip>
#include <openssl/sha.h> // Подключение библиотеки для работы с SHA-256
#include <sstream>

/**
 * @brief Геттер для атрибута ID
 */
string User::get_ID() { return ID; }

/**
 * @brief Сеттер для атрибута ID
 */
void User::set_ID(string ID1) { ID = ID1; }

/**
 * @brief Геттер для атрибута hash
 */
string User::get_hash() { return hash; }

/**
 * @brief Сеттер для атрибута hash
 */
void User::set_hash(string hash1) { hash = hash1; }

/**
 * @brief Функция для преобразования строки в SHA-256 хеш
 * @param input Входная строка для хеширования
 * @return Хеш SHA-256 в виде строки шестнадцатеричных символов
 */
/*string User::SHA256_hash(const string& input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)input.c_str(), input.size(), hash);

    // Переводим хеш в строку шестнадцатеричных символов
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}*/

/**
 * @brief Функция для проверки ID подключенного клиента
 * @return Возвращает true - если в БД есть ID подключенного клиента, иначе false
 */
bool User::CheckLogin(vector<string> Db_ID)
{
    for(const auto& db_id : Db_ID) {
        if(db_id == ID) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Функция для проверки пароля подключенного клиента
 * @param Db_password Вектор паролей клиентов из базы данных
 * @param Db_ID Вектор ID клиентов из базы данных
 * @param SALT Соль для хеширования
 * @return Возвращает true - если хеш пароля клиента совпадает с хешем из БД, иначе false
 */
bool User::CheckPassword(vector<string> Db_password, vector<string> Db_ID, string SALT)
{
    int t = -1;
    for(size_t i = 0; i < Db_ID.size(); ++i) {
        if(Db_ID[i] == ID) {
            t = i;
            break;
        }
    }

    if(t == -1) {
        return false; // ID не найден
    }

    // Хешируем комбинацию соли и пароля из БД
    string hashSHA256 = SALT + Db_password[t];
    string expectedHash = SHA256_hash(hashSHA256);

    // Сравниваем хеши
    return expectedHash == hash;
}
