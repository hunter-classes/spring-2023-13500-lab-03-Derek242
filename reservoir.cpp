// add your code

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"


double get_east_storage(std::string date){
    
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File can't be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file 
    double eastSt; double eastEl; double westSt; double westEl; std::string ddate;
    while(fin >> ddate >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 

        if (ddate == date){
            return eastSt;
        }
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
         //ignoring the remaining columns 
    }
    fin.close();
}

double get_min_east(){
    
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File can't be opened for reading." << std::endl;
        exit(1); 
    }
    std::string junk; 
    getline(fin, junk); 
    double minEast = INT_MAX;
    double eastSt; double eastEl; double westSt; double westEl; std::string ddate;

    while(fin >> ddate >> eastSt >> eastEl >> westSt >> westEl) { 

        if (eastSt < minEast){
            minEast = eastSt;
            
        }

    fin.ignore(INT_MAX, '\n'); 
                     
}
    fin.close();
    return minEast;
}


double get_max_east(){
    
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File can't be opened for reading." << std::endl;
        exit(1); 
    }
    std::string junk; 
    getline(fin, junk); 
    double maxEast = 0;
    double eastSt; double eastEl; double westSt; double westEl; std::string ddate;

    while(fin >> ddate >> eastSt >> eastEl >> westSt >> westEl) { 

        if (eastSt > maxEast){
            maxEast = eastSt;
            
        }

    fin.ignore(INT_MAX, '\n'); 
                     
}
    fin.close();
    return maxEast;
}


std::string compare_basins(std::string date){

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()){
        std::cerr << "File can't be opened for reading." << std::endl;
        exit(1); 
    }

    std::string junk; 
    getline(fin, junk); 
    double maxEast = 0;
    double eastSt; double eastEl; double westSt; double westEl; std::string ddate;

    while(fin >> ddate >> eastSt >> eastEl >> westSt >> westEl) { 

        if (ddate == date){
            if (eastEl < westEl){
                return "East";
            } else if (eastEl > westEl) {
                return "West";
            } else if (eastEl == westEl)
                return "Equal";

        }

    fin.ignore(INT_MAX, '\n'); 
                     
    }

    fin.close();
    return " ";
}