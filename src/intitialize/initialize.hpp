#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP


// include files and header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>


// define structs
struct settings{
    int numplants;
    bool humidity;
    bool temp;
    bool vis;
    bool indiv_water;
    bool water;
    bool mass;
};

struct pinout{
    std::vector<std::string> hdata_in;
    std::vector<std::string> valve_out;
    std::vector<bool> assigned;
};


// define functions
void initialize_settings(struct settings initial);

bool read_settings(struct settings initial);

void initialize_pinout(struct pinout pins);

bool read_pinout(struct pinout pins);

#endif