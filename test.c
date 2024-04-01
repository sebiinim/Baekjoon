#include <stdio.h>

int main() {
  char score;
  int scorenum;

  printf("학점을 입력하시오 : \n");
  scanf("%d", &scorenum);

  if (90 < scorenum)
    score = 'A';
  else if (80 < scorenum)
    score = 'B';
  else if (70 < scorenum)
    score = 'C';
  else if (60 < scorenum)
    score = 'D';
  else
    score = 'F';

  printf("학점은 %c입니다", score);
}