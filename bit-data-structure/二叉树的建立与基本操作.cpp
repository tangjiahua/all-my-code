#include<stdio.h> 
#include<stdlib.h> 
 
struct Btreenode 
{ 
   char element; 
  struct Btreenode *left; 
    struct Btreenode *right; 
}; 
typedef struct Btreenode *PtrNode; 
int numlef; 
void Creat_Btree(PtrNode*proot)     //用二级指针创建二叉树 
{ 
  char c; 
    c = getchar(); 
 if (c == '#') 
      *proot = NULL; 
 else 
   { 
      (*proot) = (PtrNode)malloc(sizeof (struct Btreenode)); 
     (*proot)->element = c; 
      Creat_Btree(&(*proot)->left); 
       Creat_Btree(&(*proot)->right); 
      if (!(*proot)->left&&!(*proot)->right) 
           numlef++; 
  } 
} 
 
PtrNode creat_BTree(PtrNode proot)  //用返回值创建二叉树（没用二级指针） 
{ 
 
    char c; 
    c = getchar(); 
 if (proot == NULL&&c!='#') 
 { 
      proot = (PtrNode)malloc(sizeof (struct Btreenode)); 
        proot->element = c; proot->left = proot->right = NULL; 
        proot->left = creat_BTree(proot->left); 
      proot->right = creat_BTree(proot->right); 
        if (!(proot)->left&&!(proot)->right) 
         numlef++; 
  } 
  return proot; 
} 
 
void inorder(PtrNode rt) 
{ 
    if (rt) 
    { 
      inorder(rt->left); 
      printf("%c", rt->element); 
      inorder(rt->right); 
 } 
} 
 
void preorder(PtrNode rt) 
{ 
   if (rt) 
    { 
      printf("%c", rt->element); 
      preorder(rt->left); 
     preorder(rt->right); 
    } 
} 
 
void postorder(PtrNode rt) 
{ 
  if (rt) 
    { 
 
     postorder(rt->left); 
        postorder(rt->right); 
       printf("%c", rt->element); 
  } 
} 
 
void Printline(char c, int num) 
{ 
 for (int i = 0; i < 4*num; i++) 
 { 
      printf(" "); 
   } 
  printf("%c\n", c); 
} 
 
void listtree(PtrNode rt, int depth) 
{ 
   if (rt) 
    { 
      Printline(rt->element, depth); 
      listtree(rt->left, depth + 1); 
      listtree(rt->right, depth + 1); 
 } 
} 
 
void Swap(PtrNode rt) 
{ 
   if (rt) 
    { 
 
     if (rt->left||rt->right) 
     { 
          PtrNode tmp = rt->left; 
         rt->left = rt->right; 
            rt->right = tmp; 
            if (rt->left) 
               Swap(rt->left); 
         if (rt->right) 
              Swap(rt->right); 
        } 
  } 
} 
int main() 
{ 
   //freopen("1.txt","r", stdin); 
 PtrNode root=NULL; 
 printf("BiTree\n"); 
    //Creat_Btree(&root); 
  root=creat_BTree(root); 
    listtree(root, 0); 
 
 
   printf("pre_sequence  : "); 
    preorder(root); printf("\n"); 
  printf("in_sequence   : "); 
    inorder(root); printf("\n"); 
   printf("post_sequence : "); 
    postorder(root); printf("\n"); 
 
 
   printf("Number of leaf: %d\n", numlef); 
    printf("BiTree swapped\n"); 
    Swap(root); 
    listtree(root, 0); 
 
    printf("pre_sequence  : "); 
    preorder(root); printf("\n"); 
  printf("in_sequence   : "); 
    inorder(root); printf("\n"); 
   printf("post_sequence : "); 
    postorder(root); printf("\n"); 
 
 
   return 0; 
} 
