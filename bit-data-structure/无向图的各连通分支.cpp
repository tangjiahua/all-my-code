#include <stdio.h>

int n;
int queue[1000], tail = -1, head = 0;
struct{
    int visited;
    int count;
    int to[18];
}v[18];

void BFS(){
    int k = queue[head];
    if(v[queue[head]].visited==0){
        v[queue[head]].visited=1;
        printf("-%d",queue[head]);
        head++;
        for(int i=0;i<v[k].count;i++) {
            tail++;
            queue[tail] = v[k].to[i];
        }
    }
    else
        head++;
    return;
}

int main() {
    
    int x,y;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        v[i].visited=0;
        v[i].count=0;
    }
    

    while(1){
        scanf("%d",&x);
        if(x==-1)
            break;
        scanf("%d",&y);
        v[y].to[v[y].count]=x;
        v[y].count++;
        v[x].to[v[x].count]=y;
        v[x].count++;
    }
    
    for(int p = 0; p < n; p++){
        for(int i=0;i<v[p].count;i++)
        for(int j=i+1;j<v[p].count;j++)
            if(v[p].to[i]>v[p].to[j]){
                int a = v[p].to[i];
                v[p].to[i]=v[p].to[j];
                v[p].to[j]=a;
            }
    }

    for(int i=0;i<n;i++) {
        if(v[i].visited == 0) {
            queue[head] = i;
            tail = head;
            for(int j=0;j<v[queue[head]].count;j++) {
                    tail++;
                    queue[tail] = v[queue[head]].to[j];
                }
            v[i].visited = 1;
            printf("%d",i);
            head++;
            while(tail > head || tail == head)
                BFS();
            printf("\n");
            head = 0;
            tail = -1;
        }
    }
    return 0;
}