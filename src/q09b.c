#include <stdio.h>

#define MAX_LEN 100

int main () {
    char str[MAX_LEN];
    char end_char[4] = "end";
    
    while (1) {
        // 文字列の入力
        printf("Input String:");
        scanf("%s", str);

        // 文字列がendならbreak
        int end_flag = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != end_char[i]) {
                end_flag = 0;
                break;
            }
        }
        if (end_flag) break;
    
        // 各文字の数をカウント
        int char_count['z' - 'A' + 1] = {0};
        for (int i = 0; str[i] != '\0'; i++) {
            char c = str[i];
    
            if (!('A' <= c && c <= 'Z') && !('a' <= c && c <= 'z')) continue;
            char_count[c - 'A']++;
        }
    
        // 最も多く登場する文字を取得
        char max_char = '?';
        int max_count = 0;
        for (int i = 0; i < 'z' - 'A' + 1; i++) {
            if (char_count[i] > max_count) {
                max_count = char_count[i];
                max_char = i + 'A';
            }
        }
    
        // 出力
        printf("Character with max occurrences: %c\n", max_char);
    }

    return 0;
}