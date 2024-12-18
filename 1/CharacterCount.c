#include<stdio.h> 
#include<string.h> 
void main() 
{ 
     char ch[50]; 
     int frames; 
     printf("Enter the string:"); 
     scanf("%s",ch); 
     int l = strlen(ch); 
     printf("Enter the number of frames:"); 
     scanf("%d",&frames); 
     
     int fsize[frames],ind=0; 
     for(int i=0;i<frames;i++) 
     { 
         printf(" Enter Frame-%d size:",i+1); 
         scanf("%d",&fsize[i]); 
         if(fsize[i]+ind>l) 
         { 
             printf("limit exceeded"); 
             break; 
         } 
         printf("The content of frame-%d: ",i+1); 
         
         for(int j=ind;j<fsize[i]+ind;j++) 
         { 
            printf("%c",ch[j]); 
         } 
         printf("\n"); 
         ind+=fsize[i]; 
     } 
}
