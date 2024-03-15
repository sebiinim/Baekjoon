#include <math.h>
#include <stdio.h>
// 배열에서 두 요소의 위치를 교환하는 함수
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 배열을 분할하고 피벗을 정하는 함수
int partition(int arr[], int low, int high) {
  int pivot = arr[high];  // 피벗을 배열의 마지막 요소로 선택
  int i = low - 1;        // 작은 요소들의 마지막 인덱스

  for (int j = low; j < high; j++) {
    // 현재 요소가 피벗보다 작으면 작은 요소들의 영역을 확장
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  // 피벗을 올바른 위치에 놓음
  swap(&arr[i + 1], &arr[high]);
  return i + 1;  // 피벗의 위치 반환
}

// 퀵 정렬을 수행하는 함수
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);  // 분할
    quickSort(arr, low, pi - 1);         // 왼쪽 부분 배열 정렬
    quickSort(arr, pi + 1, high);        // 오른쪽 부분 배열 정렬
  }
}

int main() {
  int nums[7] = {10, 20, 20, 2830, 1, 99, 7};
  quickSort(nums, 0, 6);

  for (int i = 0; i < 7; ++i) {
    printf("%d ", nums[i]);
  }
}