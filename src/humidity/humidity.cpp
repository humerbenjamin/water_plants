// include header files
#include "humidity.hpp"

/*
main humidity readout function
*/

bool get_cur_humid(struct humidity cur_humid, int num_plants){
    // main function for reading out humidity values from all the plants

    // run through all the different plants, getting humidity from each of them
    for(int i = 0; i < num_plants; i++){
        if(get_indiv_humid(cur_humid, i)){
            std::cout << "humidity data for plant " << i << "received" << std::endl;
        }else{
            std::cout << "humidity data for plant " << i << "NOT received" << std::endl;
            return false;
        }
    }

    return true;
}


bool get_indiv_humid(struct humidity cur_humid, int plant_num){
    // gets the humidity value from one individual humidity sensor and adds it to the humidity array
    
    // initialize variables
    float humid_val;

    // append the current humidity value to the array
    (cur_humid.humid_arr).push_back(humid_val);
    
}