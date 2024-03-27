#include <stdio.h>

int main() {
  char words[100][60];
  scanf("%s", &words[0]);

  for (int j = 0; j < 60; j++) {
    if (words[0][j] == '(') {
      printf("(");
    } else if ((words[0][j]) == ')') {
      printf(")");
    } else {
      break;
    }
  }
}
