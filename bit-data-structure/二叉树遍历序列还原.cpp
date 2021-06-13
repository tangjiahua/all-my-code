#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char iorder[100], porder[100];

typedef struct tree{
    char data;
    struct tree *lchild;
    struct tree *rchild;
    struct tree *next;
}BiNode, *BiTree;
///i j就是字符串中的位置
BiTree CreateTree(int m, int n, int p, int q){
    char in = porder[q];
    int ps, flag = 0;
    for(int i = m; i <= n; i++){
        if(iorder[i] == in){
            ps = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0) return NULL;
    else{
        BiTree root = (BiTree)malloc(sizeof(BiNode));
        root->data = iorder[ps];
        //only right tree
        if(ps == m && ps == n){
            root->lchild = NULL;
            root->rchild = NULL;
        }
        else if(ps == m){
            root->lchild = NULL;
            root->rchild = CreateTree(m+1, n, p, q-1);
        }
        //only left tree
        else if(ps == n){
            root->rchild = NULL;
            root->lchild = CreateTree(m, n-1, p, q-1);
        }
        else{
            root->lchild = CreateTree(m, ps-1, p, p+ps-m-1);
            root->rchild = CreateTree(ps+1, n, p+ps-m, q-1);
        }
        return root;
    }
   
}

BiTree head = NULL, tail = NULL;

void Push(BiTree p){
    tail->next = p;
    p->next = NULL;
    tail = tail->next;
    
}

void Pop(){
    head->next = head->next->next;
    if(head->next == NULL)
        tail = head;
}

int main(int argc, char const *argv[])
{
    scanf("%s%s",iorder, porder);
    int n, i = 0, j;
    n = strlen(iorder);
    j = n-1;
    BiTree root = NULL;
    root = CreateTree(i, j, i, j);
    head = (BiTree)malloc(sizeof(BiNode));
    head->next = NULL;
    tail = head;
    if(root){
        Push(root);
    }
    while(head->next != NULL){
        BiTree temp = head->next;
        putchar(temp->data);
        Pop();
        if(temp->lchild){
            Push(temp->lchild);
        }
        if(temp->rchild){
            Push(temp->rchild);
        }
    }

    putchar('\n');
    return 0;
}
