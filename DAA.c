#include<stdio.h>

int toh(int n,char a,char b,char c){
 
 if(n==1){printf(" %d move disk from %c to %c \n",n,a,c);
     return 0;
 }
 
 toh(n-1 ,a,c,b);
 
 printf(" %d move disk from %c to %c \n ",n,a,c);
 
 toh(n-1,b,a,c);
 
    
    
}

int main(){
    
    toh(3,'a','b','c');
}
