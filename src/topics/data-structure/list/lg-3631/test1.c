/**
 * TLE了
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

//创建新的结点并返回指针
node *create(int n) {
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL) {
        free(new);
        exit(1);
    }
    new->value = n;
    new->next = NULL;
    return new;
}

//在x后面插入新结点
void insertAfter(node *x, int y) {
    node *newnode = create(y);
    newnode->next = x->next;
    x->next = newnode;
}

//删除x后的结点
void delete (node *x) {
    if (x->next != NULL) {
        node *temp = x->next;
        x->next = temp->next;
        free(temp);
    }
}

//查询x后的结点的值
int query(node *x) {
    if (x->next == NULL) {
        return 0;
    } else {
        return x->next->value;
    }
}

node *find(node *head, int x) {
    for (node *cur = head; cur; cur = cur->next) {
        if (cur->value == x) {
            return cur;
        }
    }
    return NULL;
}

void clear(node **head) {
    node *cur = NULL;
    while ((*head)->next) {
        cur = (*head)->next;
        (*head)->next = cur->next;
        free(cur);
    }
    free(*head);
    *head = NULL;
}

int main() {
    int q, p, x, y;
    scanf("%d", &q);
    //创建头结点
    node *head = create(1);
    node *cur = NULL;
    while (q--) {
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d%d", &x, &y);
            if (cur = find(head, x)) {
                insertAfter(cur, y);
            }
        } else if (p == 2) {
            scanf("%d", &x);
            if (cur = find(head, x)) {
                printf("%d\n", cur->next ? cur->next->value : 0);
            }
        } else if (p == 3) {
            scanf("%d", &x);
            if (cur = find(head, x)) {
                if (cur->next) {
                    delete (cur);
                }
            }
        }
    }
    clear(&head);
}