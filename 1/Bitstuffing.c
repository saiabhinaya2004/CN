#include <string.h>
#include <stdio.h>
void main() 
{
    char startFlag[] = "01111110", endFlag[] = "01111110";
    char data[50], res[100], de[100];
    int c = 0;
    printf("Enter data part: ");
    scanf("%s", data);
    
    int i = 0, ind = 0;
    
    // Bit stuffing
    while (i < strlen(data)) 
    {
        res[ind] = data[i];
        ind++;
        if (data[i] == '1') 
        {
            c++;
        } 
        else 
        {
            c = 0; // Reset the count if '0' is encountered
        }
        if (c == 5) 
        { // After 5 consecutive 1s, stuff a '0'
            res[ind] = '0';
            
            ind++;
            c = 0; // Reset the count after stuffing
        }
        i++;
    }
    res[ind] = '\0'; // Null-terminate the stuffed data
    
    // Bit destuffing
    i = 0;
    ind = 0;
    c = 0;
    while (i < strlen(res)) 
    {
        de[ind] = res[i];
        ind++;
        if (res[i] == '1') 
        {
            c++;
        } 
        else 
        {
            c = 0; // Reset the count if '0' is encountered
        }
        if (c == 5 && res[i+1] == '0') 
        { // Skip the stuffed '0'
            i++;
            c = 0; // Reset the count after destuffing
        }
        i++;
    }
    de[ind] = '\0'; // Null-terminate the destuffed data
    
    printf("The data after bit stuffing is: %s%s%s\n", startFlag, res, endFlag);
    
    printf("The destuffed string is: %s\n", de);
}
