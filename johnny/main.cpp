#include <iostream>
#include <vector>
#include <algorithm>

struct package {
  unsigned int value;
  unsigned int position;
  package(int val, int pos) : value (val), position(pos) {};

  bool operator < (const package& package) const
  {
    return (value < package.value);
  }

};


//this is just silly
std::ostream& operator<<(std::ostream &strm, const package &a)
{
  return strm << "Val:" << std::to_string(a.value) << " At: " << std::to_string(a.position);
}

struct hand {
  std::vector<package> vec;
  int total = 0;

  void add(package input)
  {
    vec.push_back(input);
  }
};

void rough(std::vector<package> &input, hand &left, hand &right)
{
  for( std::vector<package>::iterator iter = input.begin(); iter!= input.end(); ++iter)
    {
      package temp = *iter;

      //std::cout<< "temp =" << temp << "\n";

      //printf("left: %d right: %d\n", left.total, right.total);
      if(left.total<right.total)
	{
	  left.total += temp.value;
	  left.vec.push_back(temp);
	  //printf("placing left\n");
	}
      else
	{
	  right.total += temp.value;
	  right.vec.push_back(temp);
	  //printf("placing right\n");
	}
    }

}

void printhand(hand input)
{
  //std::cout << "Hand:"<< input.total << "\n";
  for( std::vector<package>::iterator iter = input.vec.begin(); iter!= input.vec.end(); ++iter)
    {
      //std::cout << "\t" << *iter << "\n";
      std::cout << iter->position << "\n" ;
    }
}

int main(int argc, char *argv[])
{

  int count;
  std::cin>>count;
  //printf("number of packages: %d\n", count);

  hand left, right;

  std::vector<package> input;
  input.reserve(count);

  for(int i = 1; i<=count;i++)
    {
      int weight;
      std::cin>>weight;
      package temp = package(weight, i);
      input.push_back(temp);
    }


  std::sort(input.begin(),input.end());
  rough(input, left, right);

  printhand(left);

  return 0;
}
