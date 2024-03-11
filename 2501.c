#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int cnt=0;
    for(int i=1; i<N-1; i++){
        if(N%i == 0){
            cnt++;
        }
        if(cnt == K){
            printf("%d\n", i);
            break;
        }
    }

    if(cnt < K){
        printf("0\n");  
    }
    
}
