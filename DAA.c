#include<stdio.h>

int toh(int n,char a,char b,char c){
 
 if(n==1){printf(" %d move disk from %c to %c \n",n,a,c);
     return 0;
 }
 
 toh(n-1 ,a,c,b);
 
 printf(" %d move disk from %c to %c \n ",n,a,c);
 
 toh(n-1,b,a,c);
 
    
    
}


void swap(int  *a,int *b){
    int t=*a;
     *a=*b;
     *b=t;
    
}

void permute(int arr[],int l,int h ){
    
    if(l==h){
        for(int i=0;i<=h;i++){
            printf("%d",arr[i]);}
        printf("\n");
        return;
        
    
    }
    for(int i=l;i<=h;i++){
        
        swap(&arr[l],&arr[i]);
        
        permute(arr,l+1,h);
        
        swap(&arr[l],&arr[i]);
        
        
    }}
    
int bs(int arr[],int l, int r ,int k){
    int mid=l+(r-l)/2;
    
    if(arr[mid]==k){
        return mid;
    }
    
    
    if(k<arr[mid]){
     return bs(arr,l,mid,k);
    }
    return bs(arr,mid+1,r,k);
    
    
    
}





int main(){
    
    toh(3,'a','b','c');


    int a[]={1,2,3};
    permute(a,0,2);



 
}
