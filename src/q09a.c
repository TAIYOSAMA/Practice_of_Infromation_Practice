#include <stdio.h>

#define MAX_LEN 100

int main () {
    char str[MAX_LEN];

    // 文字列を入力
    printf("Input:");
    scanf("%s", str);

    // 大文字に変換
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A');
    }

    // 出力
    printf("Output:%s\n", str);
}