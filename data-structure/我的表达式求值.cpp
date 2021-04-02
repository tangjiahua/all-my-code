#include "stdio.h"  
#include "string.h"  
#include "math.h"  
#define MAX 9999999  
  
int figure[100];  
char symbol[100];  
int topf = -1, tops = -1;  
char operation[9] = {'+','-','*','/','(',')','#','^','%'};  
char checklist[9][9] = {  
    {'>','>','<','<','<','>','>','<','<'},  
    {'>','>','<','<','<','>','>','<','<'},  
    {'>','>','>','>','<','>','>','<','>'},  
    {'>','>','>','>','<','>','>','<','>'},  
    {'<','<','<','<','<','=',' ','<','<'},  
    {'>','>','>','>',' ','>','>','>','>'},  
    {'<','<','<','<','<',' ','=','<','<'},  
    {'>','>','>','>','<','>','>','<','>'},  
    {'>','>','>','>','<','>','>','<','>'}  
};  
int number(char *q){  
    return (int)(*q - '0');  
}  
  
void push_figure(int q){  
    figure[++topf] = q;  
}  
  
int pop_figure(){  
    return figure[topf--];  
}  
  
char pop_symbol(){  
    return symbol[tops--];  
}  
  
void push_symbol(char ch){  
    symbol[++tops] = ch;  
}  
  
int operate(int x, int y, char symbol){  
    switch(symbol){  
        case '+': return x+y;  
        case '-': return x-y;  
        case '*': return x*y;  
        case '/': if(y) return x/y;  
                  else{  
                      printf("Divide 0.\n");  
                      return MAX;  
                  }  
        case '%': return (int)fmod(x,y);  
        case '^': if(y>=0) return (int) pow(x,y);  
                    else{  
                        printf("error.\n");  
                        return MAX;  
                    }  
        default: printf("error.\n");  
                 return MAX;  
    }  
}  
  
char compare(char x, char y){  
    int a, b;  
    for(int i = 0; i <= 8; i++){  
        if(operation[i] == x){  
            a = i;  
            break;  
        }  
    }  
    for(int i = 0; i <= 8; i++){  
        if(operation[i] == y){  
            b = i;  
            break;  
        }  
    }  
    return checklist[a][b];  
}  
int main(){  
    int n, flag = 0;//0表示数字 1表示( 2表示其他  
    char expression[100], *p;  
      
      
    scanf("%d",&n);  
    while(n--){  
        flag = 2;  
        scanf("%s",expression);  
        strcat(expression, "#");//E代表运算结束标志  
        p = expression;  
        push_symbol('#');  
      k:while(*p != '#' || symbol[tops] != '#'){  
            if(*p >='0' && *p <= '9'){  
                if(flag == 0){  
                    push_figure(pop_figure()*10+number(p++));  
                    flag = 0;  
                }  
                else  
                    push_figure(number(p++));  
                    flag = 0;  
            }  
            else{  
                  
                if(flag == 1){  
                    if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' ||*p == '^'){  
                        printf("error.\n");  
                        goto j;  
                    }  
                }  
                if(*p == '(') flag = 1;  
                else flag = 2;  
  
                if(tops == -1){  
                    printf("error.\n");  
                    goto j;  
                }  
                else{  
                    char ch = pop_symbol(), ans;  
                    ans = compare(ch, *p);  
                    if(ans == ' '){  
                        printf("error.\n");  
                        goto j;  
                    }  
                    else if(ans == '<'){  
                        push_symbol(ch);  
                        push_symbol(*p++);  
                        goto k;  
                    }  
                    else if(ans == '='){  
                          
                        p++;  
                        goto k;  
                    }  
                    else{  
                        //对x,y,ch进行运算，并将数字存进  
  
                        int integer_x, integer_y;  
                        integer_y = pop_figure();  
                        integer_x = pop_figure();  
                        int judge = operate(integer_x, integer_y, ch);  
                        if(judge == MAX)  
                            goto j;  
                        else   
                            push_figure(judge);  
                        continue;  
                    }  
                    p++;  
                }  
                  
            }  
        }  
        if(topf == 0 && tops == 0) printf("%d\n",figure[topf]);  
        else{  
            printf("error.\n");  
        }  
     j:   memset(expression,'\0',100);  
        topf = -1;  
        tops = -1;  
    }  
    return 0;  
}  