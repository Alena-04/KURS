/** @file
* @author Елинова А.С
* @version 1.0
* @date 27.12.2023
* @copyright ИБСТ ПГУ
* @warning Курсовая работа студента
* @brief Заголовочный файл для модуля Comunicator
*/

#pragma once
#include "mdfile.h"

/** @brief Класс Comunicator
* @details Для создания сокета сервера и слушания запросов предназначен метод self_addr \n
* Для создания сокета клиента и подключения его к серверу метод client_addr \n
* Для авторизации клиента предназначен метод client_addr \n
*/

class Comunicator
{
public:
    /**
    * @brief Создание сокета сервера
    * @param [in] port порт 
    * @param [in] err_way файл записи логов
    * @return Сокет
    */
    int self_addr(int port, std::string &err_way);
    /**
    * @brief Создание сокета клиента
    * @param [in] s сокет сервера 
    * @param [in] err_way файл записи логов
    * @return Сокет клиента
    */
    int client_addr(int s, std::string &err_way);
     /**
    * @brief Авторизация
    * @param [in] work_sock сокет клиента 
    * @param [in] file_name файл записи логов
    * @param [in] all_names словарь с базой данных
    * @param [in] err_way файл записи логов
    * @return Сокет клиента
    */
    int autorized(int work_sock, std::string file_name,std::map <std::string,std::string> &all_names, std::string &err_way);
};
