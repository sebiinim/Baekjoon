#include <stdio.h>
#include <string.h>

int main() {
    int nums[10];

    for(int i=0; i<3; i++){
        scanf("%d", &nums[i]);
    }

    for(int i=0; i<3; i++){
        printf("%d\t", nums[i]);
    }

    return 0;
}
