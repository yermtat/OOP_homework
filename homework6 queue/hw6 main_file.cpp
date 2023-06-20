#include "Printer.h"

struct tm get_time();

int main() {
    
    Client client1{ "Tanya", 45, get_time() };
    Client client2{ "Arnold", 23, get_time() };
    Client client3{ "Behemoth the cat", 13, get_time() };

    Printer printer;
    printer.addClient(client1);
    printer.addClient(client2);
    printer.addClient(client3);

    printer.Print();    

}

struct tm get_time() {

    time_t rawtime = time(&rawtime);

    struct tm timeinfo;
    localtime_s(&timeinfo, &rawtime);

    return timeinfo;
}