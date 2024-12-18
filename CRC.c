#include<stdio.h> 
void division(int temp[],int gen[],int n,int r) 
{ 
     for(int i=0;i<n;i++) 
     { 
         if (gen[0]==temp[i]) 
         { 
             for(int j=0,k=i;j<r+1;j++,k++) 
             { 
                temp[k]=temp[k]^gen[j]; 
             } 
         } 
     
     } 
     
} 
int main() 
{ 
     int n,r,message[50],gen[50],temp[50]; 
     
     printf("Enter the number of frame bits : "); 
     scanf("%d",&n); 
     printf("Enter the frame : "); 
     for(int i=0;i<n;i++) 
     scanf("%d",&message[i]); 
     printf("Enter the number of generator bits : "); 
     scanf("%d",&r); 
     
     printf("Enter the generator : "); 
     for(int i=0;i<r;i++) 
     scanf("%d",&gen[i]); 
     r--; 
     for(int i=0;i<r;i++) 
     message[n+i] = 0; 
     for(int i=0;i<n+r;i++) 
     temp[i] = message[i]; 
     division(temp,gen,n,r); 
     printf("CRC : "); 
     for(int i=0;i<r;i++) 
     { 
         printf("%d ",temp[n+i]); 
         message[n+i] = temp[n+i]; 
     } 
     printf("\nTransmitted Message : "); 
     for(int i=0;i<n+r;i++) 
     printf("%d ",message[i]); 
     printf("\nDecoding "); 
     for(int i=0;i<n+r;i++) 
     temp[i] = message[i]; 
     division(temp,gen,n,r); 
     for(int i=0;i<r;i++) 
     { 
         if(temp[n+i]) 
         { 
             printf("Error detected in received message."); 
             return 0; 
         } 
     
     } 
     printf("\nNo error in received Message."); 
     printf("\nAfter decoding crc is "); 
     for(int i=0;i<r;i++) 
     { 
        printf("%d ",temp[n+i]); 
     } 
     printf("\nReceived Message : "); 
     for(int i=0;i<n;i++) 
     printf("%d ",message[i]); 
     return 0; 
} 
