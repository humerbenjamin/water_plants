// include header files
#include "initialize.hpp"

/*
main initialization function
*/

void initialize_settings(struct settings initial){
    // main settings initialization function
    if(read_settings(initial)){
        std::cout << "settings initialization finished" << std::endl;
    }
    return;
}

void initialize_pinout(struct pinout pins){
    // main pinout struct initialization function
    if(read_pinout(pins)){
        std::cout << "pinout initialization finished" << std::endl;
    }
    return;
}


/*
helper functions
*/

bool read_settings(struct settings initial){
    // reads settings file so the main file can be initialized properly
    std::ifstream file;

    // open the file
    file.open("src\\initialize\\settings.txt");

    // check if the file has been opened
    if (!file){
        std::cout << "Unable to open settings.txt" << std::endl;
        return false;
    }else{
        std::cout << "settings.txt opened" << std::endl;
    }

    // declare variables for reading lines from settings file
    std::string a;
    std::string b;
    int c;

    // read the settings file and initialize the proper settings
    while (file >> a >> b >> c){
        if(a == "numplants"){   // set numplants
            initial.numplants = c;
        }else if(a == "humidity"){  // set humidity
            if(!c){
                initial.humidity = false;
            }else{
                initial.humidity = true;
            }
        }else if(a == "temp"){  // set temp
            if(!c){
                initial.temp = false;
            }else{
                initial.temp = true;
            }
        }else if(a == "vis"){   // set vis
            if(!c){
                initial.vis = false;
            }else{
                initial.vis = true;
            }
        }else if(a == "indiv_water"){   // set indiv_water
            if(!c){
                initial.indiv_water = false;
            }else{
                initial.indiv_water = true;
            }
        }else if(a == "water"){     // set water
            if(!c){
                initial.water = false;
                initial.indiv_water = false;   // override for indiv water
            }else{
                initial.water = true;
            }
        }else if(a == "mass"){
            if(!c){
                initial.mass = false;
            }else{
                initial.mass = true;
            }
        }
    }
    // setting initialization finished
    return true;
}

bool read_pinout(struct pinout pins){
    // reads pinout file so the main file can be initialized properly
    std::ifstream file;

    // open the file
    file.open("src\\initialize\\pinout.txt");

    // check if the file has been opened
    if (!file){
        std::cout << "Unable to open pinout.txt" << std::endl;
        return false;
    }else{
        std::cout << "pinout.txt opened" << std::endl;
    }

    // declare variables for reading lines from settings file
    std::string a;
    int b;
    std::string c;

    while (file >> a >> b >> c){
        if(b){
            if(c == "hdata_in"){
                (pins.hdata_in).push_back(a);
                (pins.assigned).push_back(true);
            }if(c == "valve_out"){
                (pins.valve_out).push_back(a);
                (pins.assigned).push_back(true);
            }
        }else{
            (pins.assigned).push_back(false);
        }
    }
    // pinout initialization finished
    return true;
}