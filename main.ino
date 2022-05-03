#include "src/intitialize/initialize.hpp"
#include "src/humidity/humidity.hpp"


struct settings set;
struct humidity cur_humid;
struct pinout pins;

struct all_data{
    struct settings settings;
    struct humidity humidity;
    struct pinout pinout;
};

struct all_data data;


void setup(void)
{
    // initialize settings from settings.txt
    initialize_settings(set);
    data.settings = set;

    // initialize pinout from pinout.txt
    initialize_pinout(pins);
    data.pinout = pins;
}

void loop(void)
{
    // get humidity data from all the plants
    if(get_cur_humid(humidity)){
        std::cout << "humidity data received" << std::endl;
    }else{
        std::cout << "unable to receive humidity data" << std::endl;
    }


}