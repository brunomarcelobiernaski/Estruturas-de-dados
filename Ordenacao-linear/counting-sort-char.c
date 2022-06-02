#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j;
  double  total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  
  for(i = 0; i <=range; i++){C[i] = 0;}

  char c;
  while((c = fgetc(f)) != EOF){
    char aux = tolower(c);   
    if(isalpha(aux) != 0){
      C[aux-97] = C[aux-97] + 1;
    }
  }

  for(i = 0; i <= range; i++){total += C[i];}

  /*Imprimir no final desta função as frequências das letras!*/

  printf("Letra\tContagem\tFrequencia\n");
  for(i = 0; i <= range; i++){
    printf("  %c\t  %d\t\t  %.4lf\n", 97 + i, C[i], C[i]/total);
  }
}

/* */
int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

