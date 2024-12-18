#include <stdio.h> 
void main() 
{ 
     int nf, i, ack; 
     printf("Enter no. of frames: "); 
     scanf("%d", &nf); 
     for(i=0; i<nf; i++) 
     { 
        printf("SENDER: Transmitting frame %d\n",i); 
     
     } 
     printf("Enter last received acknowledgement: "); 
     scanf("%d", &ack); 
     for(i=0; i<=ack; i++) 
     { 
        printf("RECEIVER: Frame %d is received\n", i); 
     } 
     int lstr=ack; 
     
     while(ack !=nf-1) 
     { 
         printf("SENDER: Retransmitting Frame %d\n", ack+1); 
         printf("Enter last received acknowledgement: "); 
         scanf("%d", &ack); 
         for(i=lstr+1; i<=ack; i++) 
         { 
            printf("RECEIVER: Frame %d is received\n", i); 
         } 
         lstr=ack; 
     } 
     
}
