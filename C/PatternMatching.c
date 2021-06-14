//Pattern Matching
#include<stdio.h>

#include<string.h>

#include<stdlib.h>

char str[50], pat[50], rep[50];
int start = 0, patfound = 0;
int lasts, lastp, lastr;
void replacepattern() {
  int i, j;
  lastr = strlen(rep) - 2;
  if (lastp != lastr) {
    printf("\nInvalid length of the Replace String");
    exit(0);
  } 
  else {
    i = start;
    for (j = 0; j <= lastr; j++) {
      str[i] = rep[j];
      i++;
    }
  }
  return;
}
void findpattern() {
  int i, j, inmatch;
  lasts = (strlen(str)) - 2;
  lastp = (strlen(pat)) - 2;
  int endmatch;
  for (endmatch = lastp; endmatch <= lasts; endmatch++, start++) {
    if (str[endmatch] == pat[lastp]) {
      inmatch = start;
      j = 0;
      while (j < lastp) {
        if (str[inmatch] == pat[j])

        {
          inmatch++;
          j++;
        } 
        else {
          break;
        }
      }
      if (j == lastp) {
        patfound = 1;
        replacepattern();
      }
    }
  }
  return;
}
void main() {
  printf("\nEnter the main String: ");
  fgets(str, 50, stdin);
  printf("\nEnter the Pattern to be matched: ");
  fgets(pat, 50, stdin);
  printf("\nEnter the String to be replaced: ");
  fgets(rep, 50, stdin);
  printf("\nThe String before Pattern match is:\n %s", str);
  findpattern();
  if (patfound == 0)
    printf("\nThe Pattern is not found in the main String");
  else
    printf("\nThe String after Pattern match and replace is: \n %s ", str);
}
