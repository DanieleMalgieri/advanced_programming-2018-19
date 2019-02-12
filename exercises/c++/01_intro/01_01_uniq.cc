#include <iostream>

/*
It is suggested to implement the loop in two different schemes.

I choose the while.
*/

int main(){
  std::string previous_line{};
  std::string line{};
  int i{1};
  std::cout<<"Let's start the program. Remember, Ctrl-D interrupt insert"<<'\n';
  //while (std::cin >> line)
  while(std::getline(std::cin,line)){
    if (line==previous_line) {
        i++;
    } else {
        std::cout << previous_line << '\t' << " ( " << i <<" ) " << '\n';
        i = 1;
    }
    previous_line = line;
    }
  }
