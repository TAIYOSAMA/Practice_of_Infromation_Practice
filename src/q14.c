
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

void preorder(struct tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {


    int x, temp;
    char str[10];
    struct tree *p, *q, *newNode, *root;
    root = NULL;

    for (; printf("Command: "), scanf("%s", str) != EOF;) {
        if (strncmp(str, "insert", 6) == 0) {
            scanf("%d", &x);

           /*値xを追加する（完成済）*/
            newNode = (struct tree*)malloc(sizeof(struct tree));
            newNode->data = x;
            newNode->left = NULL;
            newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                p = root;
                q = NULL;
                while (p != NULL) {
                    q = p;
                    if (x < p->data) {
                        p = p->left;
                    } else {
                        p = p->right;
                    }
                }
                if (p == NULL) {
                    if (x < q->data) {
                        q->left = newNode;
                    } else if (x > q->data) {
                        q->right = newNode;
                    }
                }
            }
        }

        if (strncmp(str, "search", 6) == 0) {
            scanf("%d", &x);
            /*値xを検索する*/
            p = root;
            while (p != NULL) {
                if (x == p->data) {
                    printf("found\n");
                    break;
                }
                if (x < p->data) {
                    p = p->left;
                } else {
                    p = p->right;
                }
            }
            if (p == NULL) {
                printf("not found\n");
            }
        }

        if (strncmp(str, "preorder", 8) == 0) {
            /*先行順に出力する*/
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
        }

        if (strncmp(str, "inorder", 7) == 0) {
            /*中間順に出力する*/
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
        }

        if (strncmp(str, "postorder", 9) == 0) {
            /*後行順に出力する*/
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
        }
        
        if (strncmp(str, "end", 3) == 0) {
            break;
        }
    }
    return 0;
}