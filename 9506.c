#include <stdio.h>
#include <string.h>
#define N 100

int main() {
  int nums[N];
  int cnt=0;
  //숫자 입력받기
  for(int i=0; i<N; i++){
    scanf("%d", &nums[i]);

    if(nums[i] == -1){
      break;
    }
    cnt++;
  }

  //모든 약수 합 구하기
  for(int i=0; i<cnt; i++){
    int factorsum=0, factorcnt=0; 

    //j 가 nums[i]의 인수이면 factorsum에 더하기, factorcnt 1 증가
    for(int j=1; j<nums[i]; j++){
      if(nums[i]%j==0){
        factorsum+=j;
        factorcnt++;
      }
    }

    //완전수이면
    if(nums[i] == factorsum){
      int nowfcnt=0;
      printf("%d = ", nums[i]);
      for(int j=1; j<nums[i]; j++){
        if(nums[i]%j==0){
          printf("%d ", j);
          nowfcnt++;
          if(nowfcnt<factorcnt){
          printf("+ ");
          }
        } 
      }
      printf("\n");
    } else{   //완전수가 아니면
      printf("%d is NOT perfect.\n", nums[i]);
    }

  }

}
