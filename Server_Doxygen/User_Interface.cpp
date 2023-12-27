#include "User_Interface.h"
#include "client_base.h"
#include "Comunicator.h"
User_Interface::User_Interface(int argc, char **argv)
{
    descr.add_options()
    ("help,h", "Помощь")
    ("file,f", po::value<std::string>(&file), "введите имя файла с базой клиентов")
    ("logwrite,l", po::value<std::string>(&LogWrite), "введите имя файла с журналом работы")
    ("port,p", po::value<int>(&port), "введите номер порта")
    ;
    po::store(po::command_line_parser(argc, argv).options(descr).run(), vm);
    po::notify(vm);
}
void User_Interface::operator()()
{
    UI_err();
    LogWriter::log(LogWrite, "Командная строка прочитана");
    std::string error;
    std::map <std::string,std::string> all_names;
    try
    {
        all_names = ClientBase::read(file, LogWrite);
    }
    catch(const std::exception& e)
    {
        LogWriter::log(LogWrite, e.what());
        exit(1);
    }
    Comunicator Comunicator;    
    int socket = Comunicator.self_addr(port, LogWrite);
    while(true) {
        int work_sock = Comunicator.client_addr(socket, LogWrite);
        
        try
        {
            Comunicator.autorized(work_sock, file, all_names, LogWrite);
            Calculator::math(work_sock, LogWrite);
        }
        catch(const std::exception& e)
        {
            LogWriter::log(LogWrite, e.what());
            close(work_sock);
        }
        
    }
}
void User_Interface::UI_err()
{
    if ( vm.count("help") or vm.empty() ) {
        descr.print(std::cout);
        exit(0);
    }
    if ( vm.count("file") == 0 ) {
        LogWriter::log(LogWrite, "Пропущен путь к файлу с базой клиентов (Критическая)");
        throw ServerError("Miss CB filename (Критическая)");
    }
    if ( vm.count("port") == 0 ) {
        LogWriter::log(LogWrite, "Пропущен порт (Критическая)");
        throw ServerError("Miss port");
    }
    if ( vm.count("logwrite") == 0 ) {
        LogWriter::log(LogWrite, "Пропущен путь к файлу для записи ошибок (Критическая)");
        throw ServerError("Miss log filename");
    }
}