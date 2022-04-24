#include <iostream>
#include <stdio.h>
#include <vector>

bool zero(int number)
{
  for(number; number>0; number/=10)
    {
      if(number%10==0)
	return true;
    }
  return false;
}

std::vector<int> solution(int number)
{
  for(int i=1; i< number; i++)
    {
      if(zero(i))
	continue;
      for(int j=1; j<number;j++)
	{
	  if(zero(j))
	    continue;

	  printf("%d+%d\n",i,j);

	  if(i+j==number)
	    {
	      return {i,j};
	    }
	}
    }
  return {};
}


int main()
{
  int number = 0;
  scanf("%d",&number);

  std::vector<int> vec = solution(number);

  printf("%d %d\n", vec[0],vec[1]);

}
