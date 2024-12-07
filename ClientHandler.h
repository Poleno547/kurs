/**
 * @file ClientHandler.h
 * @author Жиганов К.А.
 * @version 1.0
 * @date 09.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля ClientHandler
 */


#include "User.h"
#include "UserDAtabase.h"

#include <arpa/inet.h>
#include <codecvt>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <locale>
#include <netinet/in.h>
#include <random>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;

/**
* @brief Класс для взаимодействия сервера с клиентами
* @param address Адрес сервера
* @param port Порт сервера
* @param vec Вектор для вычисления расчетов
* @param BasDclients
 БД клиентов
* @param Err объект класса Errors обработки ошибок
*/
class ClientHandler
{
public:
    int interaction(string database, string logFile);
    uint32_t summ();

    string get_address();
    void set_address(string address1);

    int get_port();
    void set_port(int port1);

    vector<uint32_t> get_vec();
    void set_vec(vector<uint32_t> v);

    string get_salt();
    void set_salt();

    pair<vector<string>, vector<string>> get_BasDclients();
    void set_BasDclients(vector<string> login, vector<string> password);

private:
    string address;
    int port;
    vector<uint32_t> vec;
    string salt;
    pair<vector<string>, vector<string>> BasDclients;
    Errors Err;
};
