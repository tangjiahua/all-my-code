    #include <cstdio> 
    #include <cstring> 
    #include <math.h> 
    using namespace std; 
    int fuck(double x);
    const int MAX = 10000+5; 
    int n,k; 
    double solution[MAX];

       int kkk() 
    {
      double left = 0,right = 100000; 
        for(int i=0;i<1000;i++) 
      { 
          double mid = (right+left) / 2; 
         if(fuck(mid)) 
          { 
              left = mid; 
            } 
          else  
          { 
              right = mid; 
           } 
      } 
      printf("%.2lf\n",floor(left*100)/100);
      //floor(left*100)/100;  //floor 向下取整  
      return 1;
    } 

    int fuck(double x) 
    { 
      int number = 0; 
       for(int i=0;i<n;i++) 
        { 
          number += (int)(solution[i] / x); 
        } 
      if(number >= k) return 1;
      else return 0;
    }  


    int main() 
    { 
      int i;  
        while(scanf("%d %d",&n,&k)!=EOF) 
        { 
          for(i=0;i<n;i++) 
            { 
              scanf("%lf",&solution[i]);  
           }  
         kkk(); 
       } 
      return 0; 
    }  