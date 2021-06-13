#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
    int flag;
    struct Node *lchild;
    struct Node *rchild;
}*BiTree, BiNode;

int main(int argc, char const *argv[])
{
    int n, len, i;
    char str[100000];
    int flag = 0;

    BiTree root, p;
    root = (BiTree)malloc(sizeof(BiNode));
    root->flag = 0;
    root->lchild = NULL;
    root->rchild = NULL;
    scanf("%d",&n);

    while(n--){
        memset(str, 0, sizeof(str));
        scanf("%s",str);
        len = strlen(str);
        p = root;
        for(int i = 0; i < len; i++){
            if(str[i] == '1'){
                if(p->lchild == NULL){
                    p->lchild = (BiTree)malloc(sizeof(BiNode));
                    p = p->lchild;
                    p->lchild = NULL;
                    p->rchild = NULL;
                    if(i == len-1)
                        p->flag = 1;
                    else   
                        p->flag = 0;
                }
                else{
                    if(i == len-1 || p->lchild->flag == 1){
                        goto end1;
                    }
                    else p = p->lchild;
                }
            }
            else{
                if(p->rchild == NULL){
                    p->rchild = (BiTree)malloc(sizeof(BiNode));
                    p = p->rchild;
                    p->lchild = NULL;
                    p->rchild = NULL;
                    if(i == len-1)
                        p->flag = 1;
                    else   
                        p->flag = 0;
                }
                else{
                    if(i == len-1 || p->rchild->flag == 1){
                        goto end1;
                    }
                    else p = p->rchild;
                }
            }
        }
    }
    if(!flag){
        printf("YES\n");
        return 0;
    }
    end1: printf("%s\n",str);
    return 0;
}
