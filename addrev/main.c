#include <stdio.h>
#include <stdlib.h>

int reverse(int input)
{
  //printf("reverse(%d)\n", input);
  int output = 0;
  for(;input != 0;input/=10)
    {
      output*=10;
      output+=(input%10);
      //printf("output=%d, input=%d\n", output, input);
    }
  //printf("\n");
  return output;
}

int main(int argc, char *argv[])
{
  int first = 0, second = 0;
  char * buffer;
  buffer = malloc(sizeof(char)*256);

  while(1)
    {
      int ret =fgets(buffer, 256, stdin);
      if(ret ==0)
	return 0;
      ret = sscanf(buffer,"%d %d",&first,&second);
      //printf("fgets = %s\n", buffer);
      //printf("sscanf(%d %d)\n", first, second);
      if(ret != 2)
	{
	  //printf("fail\n");
	  continue;
	}
      printf("%d\n", reverse(reverse(first)+reverse(second)));
      first=0;
      second=0;
    }

  return 0;
}
