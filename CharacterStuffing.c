#include<stdio.h> 
#include<string.h> 
void main() 
{ 
     char a[30], fs[50] = "", t[3], sd, ed, x[3], s[3], d[3], y[3], destuffed[50] = ""; 
     int i, j, p = 0, q = 0;
     // Input for stuffing 
     printf("Enter characters to be stuffed: "); 
     scanf("%s", a); 
     printf("\nEnter a character that represents starting delimiter: "); 
     scanf(" %c", &sd); 
     printf("\nEnter a character that represents ending delimiter: "); 
     scanf(" %c", &ed); 
     
     // Prepare the delimiters and the stuffing sequences 
     x[0] = s[0] = s[1] = sd; 
     x[1] = s[2] = '\0'; 
     y[0] = d[0] = d[1] = ed; 
     d[2] = y[1] = '\0'; 
     
     // Stuffing process 
     strcat(fs, x); // Add the starting delimiter 
     for(i = 0; i < strlen(a); i++) 
     { 
         t[0] = a[i]; 
         t[1] = '\0'; 
         if(t[0] == sd) 
         { 
            strcat(fs, s); // Add extra starting delimiter if found in the string 
         } 
         else if(t[0] == ed) 
         { 
            strcat(fs, d); // Add extra ending delimiter if found in the string 
         } 
         else 
         { 
            strcat(fs, t); // Add the character as is 
         } 
     } 
     strcat(fs, y); // Add the ending delimiter 
     printf("\nAfter stuffing: %s", fs); 
     // Destuffing process 
     for(i = strlen(x); i < strlen(fs) - strlen(y); i++) 
     { 
         if(fs[i] == sd && fs[i+1] == sd) 
         { 
            destuffed[p++] = fs[i++]; 
         } 
         else if(fs[i] == ed && fs[i+1] == ed) 
         { 
            destuffed[p++] = fs[i++]; 
         } 
         else 
         { 
            destuffed[p++] = fs[i]; 
         } 
     } 
     destuffed[p] = '\0'; // Null-terminate the destuffed string 
     printf("\nAfter destuffing: %s\n", destuffed); 
} 
