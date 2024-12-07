/**
 * @file ClientHandler.cpp
 */
#include "ClientHandler.h"
//int ClientHandler::interaction(string database, string logFile);
//int ClientHandler::get_port();
//string ClientHandler::get_address();

/**
 * @brief Геттер для атрибута address
 */
string ClientHandler::get_address() { return address; }

/**
 * @brief Сеттер для атрибута address
 */
void ClientHandler::set_address(string address1)
{
    const vector<string> list_add = { "127.0.0.1" };
    int fl = 0;
    for(auto it : list_add) {
        if(it == address1) {
            fl = 1;
            address = address1;
        }
    }
    if(fl != 1) {
        Err.error_recording("критичная", "Fun: set_address. Адрес сервера не соответствует разрешенным.");
    }
}

/**
 * @brief Геттер для атрибута port
 */
int ClientHandler::get_port() { return port; }

/**
 * @brief Сеттер для атрибута port
 */
void ClientHandler::set_port(int port1)
{
    if(port1 < 1023) {
        Err.error_recording("критичная", "Fun: set_port. Порт сервера должен быть больше 1024.");
    }

    port = port1;
}

/**
 * @brief Сеттер для атрибута vec
 */
vector<uint32_t> ClientHandler::get_vec() { return vec; }

/**
 * @brief Геттер для атрибута vec
 */
void ClientHandler::set_vec(vector<uint32_t> v) { vec = v; }

/**
 * @brief Геттер для атрибута salt
 */
string ClientHandler::get_salt() { return salt; }

/**
 * @brief Сеттер для атрибута salt
 */
void ClientHandler::set_salt()
{
    // Символы, которые могут встречаться в строке SALT
    const string saltCharacters = "0123456789ABCDEF";
    const int saltLength = 16;

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, saltCharacters.length() - 1);

    std::string Salt;
    Salt.reserve(saltLength);

    for(int i = 0; i < saltLength; ++i) {
        int randomIndex = dis(gen);
        Salt += saltCharacters[randomIndex];
    }

    salt = Salt;
}

/**
 * @brief Геттер для атрибута BasDclients
 */
pair<vector<string>, vector<string>> ClientHandler::get_BasDclients() { return BasDclients; }

/**
 * @brief Сеттер для атрибута BasDclients
 */
void ClientHandler::set_BasDclients(vector<string> login, vector<string> password)
{
    BasDclients = std::make_pair(login, password);
}

/**
 * @brief Функция вычисления суммы векторов
 * @return Возвращает сумму векторов атрибута vec
 */
uint32_t ClientHandler::summ()
{
    uint32_t sum = 0;
    for(uint32_t value : vec) {
        // Проверка на переполнение
        if(sum > 4294967295 - value) {
            // Обработка переполнения (в данном случае, просто возвращаем максимальное значение)
            return 4294967295;
        }

        sum += value;
    }
    return sum;
}

/**
 * @brief Главная функция для взаимодействия сервера с клиентами
 * @throw Errors при возникновении ошибки
 */
int ClientHandler::interaction(string database, string logFile)
{

    // Получение пути к файлу для записи ошибок
    Errors Err;
    Err.set_File_Log(logFile);

    // Получение пути к файлу с БД клиентов
    DataReader DB;
    DB.set_File(database);
    auto db = DB.getClient();

    vector<std::string> str1 = db.first;
    vector<std::string> str2 = db.second;

    set_BasDclients(str1, str2);

    // Создание сокета
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1) {
        Err.error_recording("критичная", "Fun: interaction. Ошибка при создании сокета.");
    }

    // Настраиваем адрес сервера
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(get_address().c_str());
    serverAddress.sin_port = htons(get_port());

    // Привязка сокета к адресу
    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        close(serverSocket);
        Err.error_recording("критичная", "Fun: interaction. Ошибка при привязке сокета к адресу.");
    }

    // Прослушивание порта
    if(listen(serverSocket, 5) == -1) {
        close(serverSocket);
        Err.error_recording("критичная", "Fun: interaction. Ошибка при начале прослушивания порта.");
    }

    std::cout << "\nСервер запущен на адресе " << get_address();
    std::cout << " и порту " << get_port() << std::endl;

    while(true) {
        // Принимаем соединение от клиента
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if(clientSocket == -1) {
            close(serverSocket);
            Err.error_recording("некритичная", "Fun: interaction. Ошибка при принятии соединения.");
        }

        cout << "ПОДКЛЮЧЕНИЕ - YES" << endl;

        char buf[1024];
        int bytes_read;

        // Получение от клиента логина
        bytes_read = recv(clientSocket, buf, sizeof(buf), 0);
        buf[bytes_read] = '\0';
        User u;
        u.set_ID(string(buf));

        string s1;
        // Проверка логина
        if(!u.CheckLogin(BasDclients.first)) {

            s1 = "ERR";
            cout << "АУТЕНТИФИКАЦИЯ - NO" << endl;
            cout << "ЗАКРЫТИЕ СОКЕТА" << endl;
            strcpy(buf, s1.c_str());
            send(clientSocket, buf, s1.length(), 0);

            close(clientSocket);
            Err.error_recording("некритичная", "Fun: interaction. Ошибка аутентификации");
            continue;
        }

        // Отправка SALT16 клиенту
        set_salt();
        string s2 = get_salt();
        cout << "SALT16=" << s2 << endl;
        strcpy(buf, s2.c_str());
        send(clientSocket, buf, s2.length(), 0);

        // Получение от клиента HASH
        bytes_read = recv(clientSocket, buf, sizeof(buf), 0);
        buf[bytes_read] = '\0';

        u.set_hash(string(buf));

        string s3;
        // Проверка пароля

        if(!u.CheckPassword(BasDclients.second, BasDclients.first, get_salt())) {
            s3 = "ERR";
            cout << "АУТЕНТИФИКАЦИЯ - NO" << endl;
            cout << "ЗАКРЫТИЕ СОКЕТА" << endl;
            strcpy(buf, s3.c_str());
            send(clientSocket, buf, s3.length(), 0);

            close(clientSocket);
            Err.error_recording("некритичная", "Fun: interaction. Ошибка аутентификации");
            continue;
        }

        string s4 = "OK";
        cout << "АУТЕНТИФИКАЦИЯ - YES" << endl;
        strcpy(buf, s4.c_str());
        send(clientSocket, buf, s4.length(), 0);

        // Получение веторов

        // Получение количества векторов
        uint32_t col = 0;
        recv(clientSocket, &col, sizeof(col), 0);
        cout << "КОЛИЧЕСТВО ВЕКТОРОВ: " << col << endl;

        for(int i = 0; i < col; i++) {

            // Получение длины вектора
            uint32_t vec_len = 0;
            recv(clientSocket, &vec_len, sizeof(vec_len), 0);
            cout << "ДЛИНА ВЕКТОРА: " << vec_len << endl;

            // Получение вектора
            uint32_t arr[vec_len] = { 0 };

            recv(clientSocket, &arr, sizeof(arr), 0);

            vector<uint32_t> vec1;
            for(size_t j = 0; j < vec_len; j++) {
                vec1.push_back(arr[j]);
                cout << vec1[j] << " ";
            }
            cout << "\n";

            // Подсчет результатов
            set_vec(vec1);
            auto res = summ();
            cout << "РЕЗУЛЬТАТ ВЫЧИСЛЕНИЙ: " << res << endl;

            // Отправка результата
            send(clientSocket, &res, sizeof(res), 0);
        }
        // Закрываем соединение с клиентом
        cout << "ЗАКРЫТИЕ СОКЕТА" << endl;
        close(clientSocket);
    }

    // Закрываем серверный сокет
    close(serverSocket);

    return 0;
}
