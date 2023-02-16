#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 
    double eastSt, eastEl, westSt, westEl; 
    int x = 0;
    int y = 0;
    double rArray[365];
    double newrArray[365];
    std::string ddate; 
    std::string dArray[365], nArray[365];

    while(fin >> ddate >> eastSt >> eastEl >> westSt >> westEl) { 
        if(ddate >= date1 && ddate <= date2){
            rArray[x] = westEl;
            dArray[x] = ddate;
            x++;
        }
        fin.ignore(INT_MAX, '\n');
    }
     for(int j = x-1; j >= 0; j--){
        newrArray[j] = rArray[y];//double
        nArray[j] = dArray[y];//string
        std::cout << nArray[j]<< "\t" << rArray[j] << std::endl;
        y++;
    }
    fin.close();
}
