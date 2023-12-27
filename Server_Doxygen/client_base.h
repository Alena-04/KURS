/** @file
* @author Елинова А.С
* @version 1.0
* @date 27.12.2023
* @copyright ИБСТ ПГУ
* @warning Курсовая работа студента
* @brief Заголовочный файл для модуля client_base
*/
#pragma once
#include "mdfile.h"
/** @brief Класс ClientBase
* @details Для чтения базы данных предназначен метод read
* Для поиска клиента в базе данных предназначен метод find
*/
class ClientBase
{
public:
    /**
    * @brief Чтение базы данных
    * @param [in] way путь к базе данных 
    * @param [in] err_way файл записи логов
    * @return Словарь с парой login,password
    * @throw ServerError, если база данных пустая
    */
    static std::map <std::string,std::string> read(std::string way, std::string err_way);
    /**
    * @brief Поиск клиента в базе данных
    * @param [in] name login клиента 
    * @param [in] all словарь с базой данных
    * @return строку с паролем
    * @throw ServerError, если в базе данных отсутствует пользователь
    */
    static std::string find(std::string &name, std::map< std::string, std::string > &all);
};
