#include "initialize.hpp"

void initialize(struct settings initial){
    read_settings(initial);
    return;
}

bool read_settings(struct settings initial){
    // reads settings file so the main file can be initialized properly
    std::ifstream file;

    // open the file
    file.open("src\\initialize\\settings.txt");

    // check if the file has been opened
    if (!file){
        std::cout << "Unable to open settings.txt" << std::endl;
        return false;
    }
    else{
        std::cout << "Settings.txt opened" << std::endl;
    }

    // read the file and initialize the proper settings

}