#include "stdio.h"  
#include "stdlib.h"  
#include "string.h"  
  
typedef struct CSNode{  
     char data;  
     struct CSNode  *firstchild, *nextsibling;  
} CSNode, *CSTree;  
  
char ch[100];  
  
void checkwin(CSTree p, int depth, char way);  
  
CSTree CreateTree(){  
    char ch = getchar();  
    char data;  
    if(ch == '('){  
        data = getchar();  
        CSTree p = (CSTree)malloc(sizeof(CSNode));  
        p->data = data;  
        p->nextsibling = NULL;  
        p->firstchild = NULL;  
        putchar(data);  
        putchar('\n');  
        char ch1;  
        ch1 = getchar();  
        if(ch1 == ')'){  
            p->firstchild = NULL;  
            ch1 = getchar();  
            if(ch1 == ',')  
                p->nextsibling = CreateTree();  
            if(ch1 == ')')  
                p->nextsibling = NULL;  
        }  
        else if(ch1 == ','){  
            p->firstchild = CreateTree();  
            ch1 = getchar();  
            if(ch1 == ','){  
                p->nextsibling = CreateTree();  
            }  
        }  
        return p;  
    }  
}  
  
CSTree check(CSTree p, char ch){  
    p = p->firstchild;  
    while(1){  
        if(p->data != ch){  
            p = p->nextsibling;  
        }  
        else{  
            return p;  
        }  
        if(p == NULL) return NULL;  
    }  
}  
  
int winlist[10];  
int loselist[10];  
int thewindeep[10];  
int thelosedeep[10];  
int flagwin = 0, flaglose = 0, deep = 0;  
int count = 0;  
void decide(CSTree node){  
    CSTree child;  
    for(int i = 0; i < 10; i++){  
        winlist[i] = 0;  
        loselist[i] = 0;  
        thewindeep[i] = 999;  
        thelosedeep[i] = 0;  
        count = 0;  
    }  
    child = node->firstchild;  
    while(1){  
        flagwin = 0, flaglose = 0, deep = 0;  
        checkwin(child, 1, 'c');  
        count++;  
        if(child->nextsibling != NULL)  
            child = child->nextsibling;  
        else break;  
    }  
}  
  
void checkwin(CSTree p, int depth, char way){  
    if(way == 'p'){  
        if(p->firstchild == NULL){  
            loselist[count] = 1;  
            if(depth > thelosedeep[count]){  
                thelosedeep[count] = depth;  
            }  
        }  
        else{  
            p = p->firstchild;  
            while(p != NULL){  
                checkwin(p, depth+1, 'c');  
                p = p->nextsibling;  
            }  
        }  
    }  
    else{  
        if(p->firstchild == NULL){  
            winlist[count] = 1;  
            if(depth < thewindeep[count]){  
                thewindeep[count] = depth;  
            }  
        }  
        else{  
            p = p->firstchild;  
            while(p!=NULL){  
                checkwin(p, depth+1, 'p');  
                p = p->nextsibling;  
            }  
        }  
    }  
  
}  
  
CSTree Choose(CSTree node){  
    int flag = 0;//1有确保取胜，0不存在确保取胜  
    int windeeper = 999;  
    int losedeeper = 0;  
    for(int i = 0; i < 10 && i <= count; i++){  
        //if(loselist[i] == 0){  
            if(winlist[i] == 1 && loselist[i] == 0){  
                if(thewindeep[i] <= windeeper){  
                    windeeper = thewindeep[i];  
                    flag = 1;  
                    break;  
                }  
            }  
        //}  
        else{  
            if(thelosedeep[i] > losedeeper){  
                    losedeeper = thelosedeep[i];  
            }  
            if(thewindeep[i] < windeeper){  
                    windeeper = thewindeep[i];  
                }  
        }  
    }  
  
    if(flag){  
        for(int i = 0; i < 10 && i <= count; i++){  
            if(thewindeep[i] == windeeper && winlist[i] == 1 && loselist[i] == 0){  
                node = node->firstchild;  
                for(int j = 0 ; j < i; j++){  
                    node = node->nextsibling;  
                }  
                break;  
            }  
        }  
    }  
    else{  
        if(windeeper < losedeeper){  
            for(int i = 0; i < 10 && i <= count; i++){  
                if(thelosedeep[i] == losedeeper){  
                    node = node->firstchild;  
                    for(int j = 0; j < i; j++){  
                        node = node->nextsibling;  
                    }  
                    break;  
                }  
            }  
        }  
        else{  
            for(int i = 0; i < 10 && i <= count; i++){  
                if(thewindeep[i] == windeeper){  
                    node = node->firstchild;  
                    for(int j = 0; j < i; j++){  
                        node = node->nextsibling;  
                    }  
                    break;  
                }  
            }  
        }  
          
    }  
    return node;  
}  
CSTree node1;  
int main(){  
    char step;  
    CSTree root = NULL;  
    CSTree node = NULL;  
    root = CreateTree();  
    root->nextsibling = NULL;  
    while(1){  
        printf("Who play first(0: computer; 1: player )?\n");  
        int choose;  
        scanf("%d",&choose);  
        getchar();  
        if(choose == 1){  
            node = root;  
            while(1){  
                printf("player:\n");  
                scanf("%c",&step);  
                getchar();  
                node1 = check(node, step);  
                if(node1 == NULL){  
                    printf("illegal move.\n");  
                    node1 = NULL;  
                    continue;  
                }  
                else{  
                    node = node1;  
                    if(node->firstchild == NULL){  
                        printf("Congratulate, you win.\n");  
                        break;  
                    }  
  
                    else{  
                        px:decide(node);  
                        node = Choose(node);  
                        printf("computer: %c",node->data);  
                        putchar('\n');  
                        if(node->firstchild == NULL){  
                            printf("Sorry, you lost.\n");  
                            break;  
                        }  
                        else  
                            continue;  
                    }  
                }  
                  
  
            }  
            printf("Continue(y/n)?\n");  
            char choose2;  
            scanf("%c", &choose2);  
            getchar();  
            if(choose2 == 'n')  goto end;  
            else continue;  
        }  
        else{  
            node = root;  
            goto px;  
        }  
    }  
  
    end: return 0;  