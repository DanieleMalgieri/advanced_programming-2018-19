#include <iostream>
#include <string>


int main(){
  int i;
  std::cout << "Pls, insert an integer" << '\n';
  while(!(std::cin >> i)){
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Wrong type insert" << '\n';
  }
  std::cout << "Finally! "<< i <<" is an appropriate number!";
  return 0;
}
