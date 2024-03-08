#include <stdio.h>
#include <string.h>

int main() {
    char input[2000];

    // 사용자로부터 문자열 입력 받기
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // 입력 문자열을 공백으로 분리하여 출력
    char *token = strtok(input, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
