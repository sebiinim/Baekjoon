#include <stdio.h>

int main() {
  int x, y, w, h, garo, sero;
  scanf("%d %d %d %d", &x, &y, &w, &h);

  if (x < w - x) {
    garo = x;
  } else {
    garo = w - x;
  }

  if (y < h - y) {
    sero = y;
  } else {
    sero = h - y;
  }

  if (garo < sero) {
    printf("%d", garo);
  } else {
    printf("%d", sero);
  }
}