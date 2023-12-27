/** @file
* @author Елинова А.С
* @version 1.0
* @date 27.12.2023
* @copyright ИБСТ ПГУ
* @warning Курсовая работа студента
* @brief Заголовочный файл для модуля Calculator
*/
#include "mdfile.h"
#include <type_traits>
#pragma once
/** @brief Класс Calculator
* @details Для выполнения операции над данными и их отправки предназначен метод math
* @warning Реализация только для типа данных uint32_t
*/
class Calculator
{
public:
    /**
	* @brief Метод math для выполнения операции над данными и их отправки
	* @param [in] work_sock сокет 
	* @param [in] err_way файл записи логов
	* @return Метод ничего не возвращает
	*/
    static void math(int work_sock, std::string &err_way);
};
