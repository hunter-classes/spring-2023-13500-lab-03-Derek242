// 
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 3

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"
int main()
{
  //Task A: East Basin storage to date
  std::cout << "Enter Date: 01/04/2018\n" << "East basin storage: " << get_east_storage("01/04/2018") << " billion gallons\n" << std::endl;
  std::cout << "Enter Date: 12/30/2018\n" << "East basin storage: " << get_east_storage("12/30/2018") << " billion gallons\n" << std::endl;
  std::cout << "Enter Date: 07/17/2018\n" << "East basin storage: " << get_east_storage("07/17/2018") << " billion gallons\n" << std::endl;

  //Task B: The min and maxes of East basin
  std::cout << "Minimum storage in east basin: " << get_min_east() << " billion gallons\n" << std::endl;
  std::cout << "Maximum storage in east basin: " << get_max_east() << " billion gallons\n" << std::endl;
  
  //Task C: Comparing the East basin to the West basin
  std::cout << "Enter Date: 08/27/2018: " << compare_basins("08/27/2018") << std::endl << std::endl;

  //Task D: Reverse order of Basin dates
  std::cout << "Beginning date: 02/27/2018\n" << "Ending date: 07/17/2018\n " << "The basin levels from 07/17/2018 to 2/27/2018 are: \n";
  reverse_order("02/12/2018","07/17/2018");
  std::cout << std::endl;

  
  return 0;
} 