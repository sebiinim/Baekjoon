#include <stdio.h>
#include <string.h>

int main() {
    int nums[1000][2];
    int i=0;
    while(1){
        scanf("%d %d", &nums[i][0], &nums[i][1]);
        if((nums[i][0] == 0)&&(nums[i][1] == 0)){
            break;
        }
        i++;
    }

    for(int j=0; j<i; j++){
        if(nums[j][1] % nums[j][0] == 0){
            printf("factor\n");
        } else if (nums[j][0] % nums[j][1] == 0)
        {
            printf("multiple\n");
        } else{
            printf("neither\n");
        }
    }
}
