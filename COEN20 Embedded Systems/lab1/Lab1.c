#include <stdio.h>

void Dec2Bin(int number, int binary[]);
void PrintBinary(int binary[]);

int binary[8] = {0,0,0,0,0,0,0,0};

int main(void)
{
    int input;
    
    printf("Enter a decimal integer (-128 to 255): ");
    scanf("%d", &input);
    
    // Checks that the input is not out of range
    if(input > 255 || input < -128)
    {
        printf("out of range \n \n");
        return 0;
    }
    
    // Prints the 2's complement by adding 256 to the integer
    if(input >= -128 && input <= -1)
    {
        printf("\n2's complement: ");
        Dec2Bin(input+256, binary);
    }
    
    // Prints the 2's complement (unsigned)
    if (input >= 0 && input <= 127)
    {
        printf("\nUnsigned and 2's complement: ");
        Dec2Bin(input, binary);
    }
    
    // Prints the unsigned binary
    if (input >= 128 && input <= 255)
    {
        printf("\nUnsigned: ");
        Dec2Bin(input, binary);
    }
    
    return 0;
}

// Converts a decimal to binary
void Dec2Bin(int number, int binary[])
{
    int num = number;
    int bit;
    int count = 7;
    
    while(num != 0)
    {
        bit = num % 2;
        binary[count] = bit;
        num = num / 2;
        count -= 1;
    }
    
    PrintBinary(binary);
}

// Called by the Dec2Bin function, prints the binary bits to the console
void PrintBinary(int binary[])
{
    int i;
    
    for(i=0; i < 8; i++)
    {
        printf("%d", binary[i]);
    }
    printf("\n \n");
}
