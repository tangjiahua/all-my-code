#include<stdio.h>  
#include<stdlib.h>  

int heap[200];  
int length;
void HeapAdjust(int x,int t)
{    
    //i代表现在为止，j代表左右子树位置
    int i,j,up;
        i=x;
        j=2*i;
        up=heap[i];
        while(j<=t)
        {        if(j<t&&heap[j]<heap[j+1])
                        j++;
                if(up<heap[j])
                {        heap[i]=heap[j];
                        i=j;
                        j=2*i;
                }
                else
                {        j=t+1;
                }
        }
        heap[i]=up;
}

// void HeapAdjust( int x, int y)
// {  
//     int rc=heap[x];  
//     for(int j=2*x;j<=y;j*=2){    
//         if(j<y && rc < heap[j])
//             j++;
//         if(rc < heap[j])   
//             break;        
//         heap[x]=heap[j];  
//         x=j;  
//     }  
//     heap[x]=rc;  
//     heap[1]=heap[y];  
// }  

void HeapSort()   
{  
    int i;    
    for(i = length/2; i>0; i--){  
        HeapAdjust(i,length);  
    }   

}  

int main() 
{  
    scanf("%d",&length);  
    for(int i=1; i<=length ;i++)  
        scanf("%d",&heap[i]);  
    for(int q = 0; q < 3; q++){
        HeapSort();
        for(int i=1;i<=length;i++)  
            printf("%d ",heap[i]);  
        printf("\n");
        int temp = heap[1];
        heap[1] = heap[length];
        heap[length] = heap[1];
        length--;
    }
    return 1;
}  
