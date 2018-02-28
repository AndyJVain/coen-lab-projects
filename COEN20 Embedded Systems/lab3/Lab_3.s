        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// extern int *pWord(void *arrayBaseAdr, int numberOfColumns, int currentRow, int currentCol);

            .global     pWord

pWord:      PUSH        {LR}
            MUL         R1,R1,R2    // Multiply numberOfColumns by currentRow, stored in R1 and R2 respectively
            ADD         R1,R1,R3    // Add currentCol to that number just multiplied together (which is stored in R0)
            LSL         R1,R1,2     // Multiply by 4, which is the same as LSL 2
            ADD         R0,R0,R1    // Add this to R0, the base address
            POP         {PC}
            .end
