/**
 * @file SHA256.cpp
 */

#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>



/**
 * @brief Получение хэш-кода по алгоритму SHA-256
 * @param msg Сообщение для хэширования
 * @return Хэш-код SHA-256
 */
std::string SHA256_hash(const std::string& msg);
/*{
    using namespace CryptoPP;

    // Создаем объект для хеширования по SHA-256
    SHA256 hash;

    // Переменная для записи результата хеширования
    std::string digest;

    // Настройка цепочки преобразований: хешируем, кодируем в hex и сохраняем результат в строку
    StringSource(msg, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));

    // Возвращаем хеш-код SHA-256 в шестнадцатеричном формате
    return digest;
}*/
