#include <iostream>
#include <regex>


bool solution(std::string &string)
{
     std::regex regex_phone("[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9]", std::regex::grep);
  return std::regex_match(string, regex_phone);
}

int main()
{
  std::string buff;
  std::cin>>buff;


  std::cout<< buff << "\n";
  std::cout<< (solution(buff) ? "true" : "false")<<"\n" ;


}
