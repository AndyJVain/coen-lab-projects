#include <stdio.h>
#include <stdint.h>
#include "library.h"

extern void PrintTwo(char *format, uint32_t numb) ;

int main(void)
	{
        InitializeHardware(HEADER, PROJECT_NAME) ;
        PrintTwo("numb=%d\n",15) ;
        return 0 ;
	}

