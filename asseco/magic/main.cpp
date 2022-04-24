#include <iostream>
#include <stdio.h>
#include <vector>

bool magic(std::vector<std::vector<int>> & table,int x1,int y1, int size)
{
  int i=0, j=0;
  int magic=0;

  int value=0;
  std::vector<int> row;
  //row
  //TODO
  printf("row\n");
  for(i=x1;i<=x1+size;i++)
    {
      //if (value!=magic)
      //return false;
      value = 0;

      row = table[i];
      for(j=y1; j<y1+size;j++)
	{

	  value += row [j];
	}
      printf("%d\n", value);
    }

  printf("col\n");
  for(i=x1;i<=x1+size;i++)
    {
      //if (value!=magic)
      //return false;
      value = 0;

      row = table[j];
      for(j=y1; j<y1+size;j++)
	{

	  value += row [i];
	}
      printf("%d\n", value);
    }


  return true;
}

int solution(std::vector< std::vector<int> > &table) {
  int rows = table.size();
  int cols = table[0].size();
  int maxsquare = std::min(rows,cols);

  for(maxsquare; maxsquare>1; maxsquare--)
    {
      for(int x1 = 0; x1 <= rows-maxsquare; x1++)
	{
	  for(int y1 = 0; y1 <= rows-maxsquare; y1++)
	    {
	      printf("generating square: %d,%d %d,%d",x1,y1,x1+maxsquare,y1+maxsquare);
	      if(magic(table,x1,y1,maxsquare))
		return maxsquare;
	    }
	}
    }
  return 1;
}


int main()
{
  std::vector<std::vector<int>>table =  {{4, 3, 4, 5, 3}, {2, 7, 3, 8, 4}, {1, 7, 6, 5, 2}, {8, 4, 9, 5, 5}};

  solution(table);

}
