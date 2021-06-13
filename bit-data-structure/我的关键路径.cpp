#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[500] = {-1};
int tail = -1;
int vNum, eNum;

typedef struct node2{
    int num;
    int value;
    int e;
    int l;
    struct node2 *next;
}Node2;
Node2* node2[500];
typedef struct node{
    char name[10];
    int visited;
    int inDegree;
    int outDegree;
    struct node2 *next;
}Node;
Node node[500];
int topo = 0;
int Topolist[500];
int ve[500] = {0};
int vl[500] = {0};


// typedef struct EL{
//     int from;
//     int to;
//     int e;
//     int l;
// }elNode;
// elNode el[100];

void CriticalPath(int vNum){
    int n = vNum;
    topo = 0;
    //求ve
    //修正Topolist[i]的值
    for(int i = 0; i < n; i++){
        //对i之前的每个进行枚举，找他们到Topolist[i]的值是否更新
        for(int j = 0; j < n; j++){
            Node2 *p = node[Topolist[j]].next;
            while(p != NULL){
                if(p->num == Topolist[i]){
                    if(ve[Topolist[j]] + p->value > ve[Topolist[i]]){
                        ve[Topolist[i]] = ve[Topolist[j]] + p->value;
                    }
                }
                p = p->next;
            }
        }
        topo++;
    }
    //vl
    for(int i = 0; i < vNum; i++){
        vl[i] = ve[vNum-1];
    }
    //i慢慢减小，topolist[i]对应倒序拓扑排序值
    for(int i = vNum-1; i >= 0; i--){
        Node2 *p = node[Topolist[i]].next;
        while(p != NULL){
            for(int j = vNum-1; j >= 0; j--){
                if(Topolist[j] == p->num){
                    if(vl[i] > vl[j] - p->value){
                        vl[i] = vl[j] - p->value;
                    }
                }
            }
            p = p->next;
        }
    }
    
    int topo2[vNum];
    for(int i = 0; i < vNum; i++){
        for(int j = 0; j < vNum; j++){
            if(Topolist[j] == i){
                topo2[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < vNum; i++){
        Node2 *p = node[i].next;
        while(p != NULL){
            p->e = ve[i];
            int j;
            for(int k = 0; k < vNum; k++){
                if(Topolist[k] == p->num){
                    j = k;
                    break;
                }
            }
            p->l = vl[j] - p->value;
            p = p->next;
        }
    }

}
// int flag = 0;

int TopoSort(int n){
    int n1 = n;

    while(n1--){
        for(int i = 0; i < n; i++){
            if(node[i].inDegree == 0 && node[i].visited == 0){
                stack[++tail] = i;
                Topolist[topo++] = i;
                node[i].visited = 1;
                // node[i].inDegree = -1;
                Node2 *q;
                q = node[i].next;
                while(q != NULL){
                    node[q->num].inDegree--;
                    q = q->next;
                }
                break;
            }
        }
        
    }
    for(int i = 0; i < vNum; i++){
        if(node[i].inDegree != 0)
            return 1;
    }
    return 0;
}

void DFS(Node2 *p, int x){
    if(p == NULL){
        if(x != vNum-1){
            stack[tail] = -1;
            tail--;
            return;
        }
        int i = 0;
        while(stack[i] != -1){
            printf("%s",node[stack[i]].name);
            i++;
            if(stack[i] != -1)putchar('-');
        }
        putchar('\n');
        stack[tail] = -1;
        tail--;
        return;
    }
    else{
        while(p!=NULL){
            if(p->e == p->l){
                tail++;
                stack[tail] = p->num;
                DFS(node[p->num].next, p->num);
            }
            p = p->next;
        }
        stack[tail] = -1;
        tail--;
    }
}

int main(){
    
    char str[1000];
    scanf("%d,%d",&vNum,&eNum);
    scanf("%s",str);
    int k=0;
    int qtemp=0;
    
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=','){
            node[k].name[qtemp++]=str[i];
        }
        else {
            node[k].name[qtemp]='\0';
            node[k].inDegree = 0;
            node[k].outDegree = 0;
            node[k].next = NULL;
            node[k].visited = 0;
            k++;
            qtemp=0;
        }
    }
    getchar();
    int x, y ,value;
    char ch;
    Node2 *p;
    while(eNum>0){
        scanf("<%d,%d,%d>",&x,&y,&value);
        p = (Node2*)malloc(sizeof(Node2));
        p->num = y;
        p->value = value;
        if(node[x].next != NULL){
            Node2 *q = node[x].next;
            Node2 *qp = NULL;
            if(y < node[x].next->num){
                p->next = node[x].next;
                node[x].next = p;
            }
            else{
                
                while(1){
                    qp = q;
                    q = q->next;
                    if(q != NULL){
                        if(qp->num < y && q->num < y) continue;
                        else if(qp->num < y && q->num > y){
                            p->next = qp->next;
                            qp->next = p;
                            break;
                        }
                    }
                    else{
                        qp->next = p;
                        p->next = NULL;
                        break;
                    }
                }

            }
        }
        else{
            node[x].next = p;
            p->next = NULL;
        }
        ch = getchar();
        eNum--;
        node[x].outDegree++;
        node[y].inDegree++;
    }
    for(int i = 0; i < 500; i++){
        stack[i] = -1;
    }
    if(TopoSort(vNum)){
        printf("NO TOPOLOGICAL PATH\n");
        return 0;
    }
    else{
        for(int i = 0; i < vNum; i++){
            printf("%s",node[stack[i]].name);
            if(i == vNum-1) printf("\n");
            else printf("-");
        }
    }
    CriticalPath(vNum);
    
    // for(int i = 0; i < vNum; i++){
    //     node2[i] = node[i].next;
    // }
    for(int i = 0; i < 500; i++){
        stack[i] = -1;
    }
    tail = -1;
    stack[++tail] = 0;
    DFS(node[0].next, 0);
}