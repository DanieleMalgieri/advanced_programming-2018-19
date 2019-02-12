#include <iostream>
#include <string>

int main(){
  double value{};
  std::string unit{};
  std::cout << "Pls, insert an integer" << '\n';
  std::cin >> value >> unit;
  if (unit=="meter" ){
    value = value * 0.3048;
    unit = "feet";
  } else if (unit=="feet"){
    value = value/0.3048;
    unit = "meters";
  }
  else {std::cout<< "Wrong input!" << std::endl;
}
  std::cout << value << " " << unit <<'\n';
  return 0;
}
