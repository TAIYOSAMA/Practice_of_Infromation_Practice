#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct list {
        int data;
        struct list* next;
    };

    int x, temp;
    char str[10];
    struct list *p, *q, *top;
    top = NULL;

    for (; printf("Command: "), scanf("%s", str) != EOF;) {
        if (strncmp(str, "insert", 6) == 0) {
            scanf("%d", &x);

            /*先頭に値xを追加する*/
            q = (struct list*)malloc(sizeof(struct list));
            q->data = x;
            q->next = top;
            top = q;
        }

        if (strncmp(str, "delete", 6) == 0) {
            scanf("%d", &x);

            /*値xを削除する*/
            q = top;
            p = NULL;
            while (q != NULL && q->data != x) {
                p = q;
                q = q->next;
            }
            if (q == NULL) {
                continue;
            }
            if (p == NULL) {
                top = q->next;
            } else {
                p->next = q->next;
            }
            free(q);
        }

        if (strncmp(str, "sort", 4) == 0) {
            /*中身を小さい順に並び替える*/
            if (top == NULL) continue;
            for (struct list *i = top; i->next != NULL; i = i->next) {
                for (struct list *j = i->next; j != NULL; j = j->next) {
                    if (i->data > j->data) {
                        int tmp = i->data;
                        i->data = j->data;
                        j->data = tmp;
                    }
                }
            }
        }

        if (strncmp(str, "print", 5) == 0) {
            printf("Data: ");
            p = top;
            while (p != NULL) {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("\n");
        }
        
        if (strncmp(str, "end", 3) == 0) {
            break;
        }
    }
    return 0;
}