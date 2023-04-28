#include <stdio.h> 

int main() 
{ 
     int a, b, c; 

     scanf("%d %d %d", &a, &b, &c); 
      
      
     if (a>=b && a>=c) { 
          if (b>c)  
               printf("%d \n", b); 
          else  
               printf("%d \n", c); 
     } 
     else if (b>=a && b>=c) { 
          if (c>a) 
               printf("%d \n", c); 
          else  
               printf("%d \n", a); 
     } 
      
     else 
     { 
          if (a>b) 
               printf("%d \n", a); 
          else  
               printf("%d \n", b); 
     } 

     return 0; 
} 