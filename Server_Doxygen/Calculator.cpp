//std::cout<< <<std::endl;
#include "Calculator.h"
#include <boost/cast.hpp>
void Calculator::math(int work_sock, std::string &err_way)
{
    uint32_t amount;
    uint32_t vector_size;
    recv(work_sock, &amount, sizeof(amount), 0);
    //цикл векторов
    for(uint32_t i=0; i<amount; i++) {
        recv(work_sock, &vector_size, sizeof(vector_size), 0);//прием длинны для первого вектора

        std::unique_ptr< int16_t[] > v(new int16_t[vector_size]);
        int v_size;
        if( (v_size = recv(work_sock, (void*)v.get(), sizeof(int32_t)*vector_size, 0)) == -1 ) {
            throw ServerError("Тип данных клиента не соответствует серверу (Не критическая)");
        }
        if( sizeof(int16_t)*vector_size != (uint32_t)v_size ) {
            throw ServerError("Тип данных клиента не соответствует серверу (Не критическая)");
        }
        // Цикл вычислений
        int16_t sum = 0;
        for(uint32_t j=0; j<vector_size; j++) {
            int16_t squared_number;
            try {
                squared_number = boost::numeric_cast<int16_t, uint32_t>(v[j]*v[j]);
                sum = boost::numeric_cast<int16_t>(sum + squared_number);
            } catch(const boost::bad_numeric_cast &e) {
                sum = std::numeric_limits< int16_t >::max();
                break;
            }
        }
        send(work_sock, &sum, sizeof(sum), 0);
    }
    LogWriter::log(err_way, "Результат вычислений получен и отправлен клиенту");
    std::cout << "Program finish!" <<std::endl;
    close(work_sock);
}
