        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// void PrintTwo(char *format, uint32_t numb) ;

            .global     PrintTwo
PrintTwo:   PUSH        {R4,R5,LR}  // Preserves R4, R5, and LR in the stack
            MOV         R4,R0       // Saves the value in the first register into R5
            MOV         R5,R1       // Saves the value in the second register to R5
            BL          printf      // Prints the first value (15)
            ADD         R1,R5,1     // Adds 1 to 15 and stores it in R1
            MOV         R0,R4       // Moves R4 into R0 after it was modified in the previous printf call
            BL          printf      // Prints the second value (16)
            POP         {R4,R5,LR}  // Restores R4, R5, and LR

            .end
