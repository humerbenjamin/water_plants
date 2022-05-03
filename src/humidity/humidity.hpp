#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP


// include files
#include <vector>
#include <iostream>


// define structs
struct humidity{
    std::vector<float> humid_arr;
};


// define functions
bool get_cur_humid(struct humidity cur_humid, int num_plants);

bool get_indiv_humid(struct humidity cur_humid, int plant_num);

#endif