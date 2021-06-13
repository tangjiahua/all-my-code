#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    struct Node *lchild;
    struct Node *rchild;
    char data;
}*BiTree, BiTNode;

int flag = 0;

// void CreateBiTree(NODE &T, char *ch){
//     if(*ch == '#' || *ch == '\n') T = NULL;
//     else{
//         if(!(T = (NODE*)malloc(sizeof(NODE))))
//             exit(0);
//         T->data = *ch++;
//         if(!flag){                                       //没必要用标志位，先序，第一个是根
//             flag = 1;
//             root = T;
//         }
//         CreateBiTree(T->lchild, ch);
//         ch++;
//         CreateBiTree(T->rchild, ch);
//         ch++;                                            //这个多余，会让ch多加一次
//     }
// }

int index = 0, leaves = 0;
BiTree CreateBiTree(const char *str)
{
    BiTree T = NULL;

    if (str[index] != '#')
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = str[index];

        ++index;
        T->lchild = CreateBiTree(str);
        ++index;
        T->rchild = CreateBiTree(str);
        if(T->lchild == NULL && T->rchild == NULL)
            leaves++;
    }

    return T;
}

// char ch;
// BiTree CreateBiTree(){
//     BiTree T = NULL;
//     ch = getchar();
//     if(ch != '\n' && ch != '#'){
//         BiTree T = (BiTree)malloc(sizeof(BiTNode));
//         T->data = ch;

//         T->lchild =  CreateBiTree();
//         T->rchild = CreateBiTree();
//     } 
//     return T;
// }


void PrintBiTree(BiTree T, int depth){
    if(T == NULL) return;
    else{
        for(int i = 0; i < depth; i++)
            printf("    ");
        printf("%c\n",T->data);
        PrintBiTree(T->lchild, depth + 1);
        PrintBiTree(T->rchild, depth + 1);
    }
}

void preorder(BiTree T){
    if(T){
        printf("%c",T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void inorder(BiTree T){
    if(T){
        inorder(T->lchild);
        printf("%c",T->data);
        inorder(T->rchild);
    }
}

void postorder(BiTree T){
    if(T){
        postorder(T->lchild);
        postorder(T->rchild);
        printf("%c",T->data);
    }
}

void Swap(BiTree T){
    BiTree verse;
    verse = T->lchild;
    T->lchild = T->rchild;
    T->rchild = verse;
    if(T->lchild)
        Swap(T->lchild);
    if(T->rchild)
        Swap(T->rchild);
}

int main(){
    char str[100005];
    scanf("%s", str);
    BiTree root = NULL;
    root = CreateBiTree(str);
    printf("BiTree\n");
    PrintBiTree(root, 0);
    printf("pre_sequence  : "); 
    preorder(root);
    printf("\n"); 
    printf("in_sequence   : "); 
    inorder(root);
    printf("\n"); 
    printf("post_sequence : ");
    postorder(root);
    printf("\n");
    printf("Number of leaf: %d\n", leaves);
    printf("BiTree swapped\n"); 
    Swap(root);
    PrintBiTree(root, 0);
    printf("pre_sequence  : "); 
    preorder(root);
    printf("\n"); 
    printf("in_sequence   : "); 
    inorder(root);
    printf("\n"); 
    printf("post_sequence : ");
    postorder(root);
    printf("\n");
    return 0;
}