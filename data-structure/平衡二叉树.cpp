#include "stdio.h"
#include "stdlib.h"
typedef struct Avnode
{
    char data;
    struct Avnode * lchild, *rchild;
}NODE;
NODE *root = NULL;

int Height(NODE*p){
    if(p == NULL) return 0;
    else{
        if(Height(p->lchild) > Height(p->rchild))   return Height(p->lchild)+1;
        else return Height(p->rchild)+1;
    }
}

NODE* LL(NODE *p){
    NODE *q;
    q = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;
    return q;
}

NODE* RR(NODE *p){
    NODE *q = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;
    return q;
}

NODE* LR(NODE *p){
    NODE *q = p->lchild, *q1 = q->rchild;
    q->rchild = q1->lchild;
    p->lchild = q1;
    q1->lchild = q;
    p->lchild = q1->rchild;
    q1->rchild = p;
    return q1;
}

NODE* RL(NODE *p){
    NODE *q = p->rchild, *q1 = p->rchild->lchild;
    q->lchild = q1->rchild;
    p->rchild = q1;
    q1->rchild = q;
    p->rchild = q1->lchild;
    q1->lchild = p;
    return q1;
}

NODE* Insert(char c, NODE *p){
    if(p == NULL){
        p = (NODE*)malloc(sizeof(NODE));
        p->data = c;
        p->lchild = NULL;
        p->rchild = NULL;
        return p;
    }
    else{
        if(c < p->data){
            p->lchild = Insert(c, p->lchild);
            if(Height(p->lchild) - Height(p->rchild) > 1){
                if(c < p->lchild->data){
                    p = LL(p);
                }
                else{
                    p = LR(p);
                }
            }
            return p;
        }
        else{
            p->rchild = Insert(c, p->rchild);
            if(Height(p->lchild) - Height(p->rchild) < -1){
                if(c > p->rchild->data){
                    p = RR(p);
                }
                else{
                    p = RL(p);
                }
            }
            return p;
        }
    }
}

void Inorder(NODE *head)
{
    if (head->lchild)
        Inorder(head->lchild);
    printf("%c", head->data);
    if (head->rchild)
        Inorder(head->rchild);
}


void Preorder(NODE *head)
{
    printf("%c", head->data);
    if (head->lchild)
        Preorder(head->lchild);
    if (head->rchild)
        Preorder(head->rchild);
}
void Postorder(NODE *head)
{
    if (head->lchild)
        Postorder(head->lchild);
    if (head->rchild)
        Postorder(head->rchild);
    printf("%c", head->data);
}


void Print(NODE *p, int depth){
    int i;
    if (p->rchild)
        Print(p->rchild, depth + 1);
    for (i = 0; i < depth; i++)
        printf("    ");
    printf("%c\n", p->data);
    if (p->lchild)
        Print(p->lchild, depth + 1);
}

int main()
{
    char c;
    while (1)
    {
        c = getchar();
        if (c == '\n')
            break;
        root = Insert(c, root);
    }
    
    printf("Preorder: ");
    Preorder(root);
    putchar('\n');
    printf("Inorder: ");
    Inorder(root);
    putchar('\n');
    printf("Postorder: ");
    Postorder(root);
    putchar('\n');
    printf("Tree:\n");
    Print(root, 0);
    return 0;
}