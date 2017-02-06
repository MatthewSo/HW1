#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *f = fopen("first.ppm", "w");
  if (f == NULL)
    {
      printf("Error opening file!\n");
      exit(1);
    }

  const char *text =  "P3 500 500 255";  
  fprintf(f, "%s \n", text);

  int i = 0;
  int j = 0;
  int t = j - 250;

  for (;i < 500; i++){
    for (;j < 500; j++){
      int r = 0;
      int b = 0;
      int g = 0;
      t = j - 250;
      if (i + 10 > t * t/100 && i - 10  < t * t/100){
	r = 100;
	b = 100;
	g = i * 256 / 500;}
      else{
	r = i * 256 / 500;
	b = i * 256 / 500;
	g = j * 256 / 500;}

      fprintf(f, "%d %d %d \n",r,g,b);

    }
    j = 0;
  
  }

}
