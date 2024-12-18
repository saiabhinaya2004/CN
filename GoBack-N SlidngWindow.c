#include <stdio.h> 
void main() 
{ 
     int ws, nf, c=0, ack; 
     printf("Enter window size: "); 
     scanf("%d", &ws); 
     printf("Enter number of frames: "); 
     scanf("%d", &nf); 
     while(1) 
     { 
     
         for(int i=0; i<ws; i++) 
         { 
             printf("Frame %d is transmitted\n", c); 
             if(c== nf-1) 
             break; 
             c+= 1; 
         } 
         printf("Enter the last acknowledgement received: "); 
         scanf("%d", &ack); 
         if(ack == c) 
         break; 
         else 
         c = ack+1; 
     } 
} 
