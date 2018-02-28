        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// extern uint32_t UBFX(uint32_t word, uint32_t lsb, uint32_t width) ;
// extern uint32_t BFI(uint32_t word, uint32_t value, uint32_t lsb, uint32_t width) ;

        .global     UBFX
UBFX:   LDR         R3,=1       // Loads 1
        LSL         R3,R3,R2    // Shifts it left to match the size of the width
        SUB         R3,R3,1     // Subtracts by 1 to make all 1's, creating the mask
        LSR         R0,R0,R1    // Shifts the word so that the start position is at position 0
        AND         R0,R0,R3    // ANDs the word with the mask, so that everything is 0 before the extracted portion
        BX          LR

        .global     BFI
BFI:    PUSH        {R4,R5,R6,LR}
        ADD         R6,R2,R3        // Total to shift over to clear the right side
        LSR         R4,R0,R6        // Shift right to clear out right side to 0
        LSL         R4,R4,R6        // Shift left to make right side all 0s
        LSL         R1,R1,R2        // Shifts the inserted word to the correct position
        ORR         R4,R4,R1        // R4 <-- Left half and inserted portion
        LDR         R6,=32
        SUB         R6,R6,R2        // Total to shift left to clear out left side
        LSL         R5,R0,R6        // Shifts left to clear left side to 0
        LSR         R5,R5,R6        // Shift right to make left side all 0s
        ORR         R0,R4,R5        // R0 <- The bitfield with the inserted value
        POP         {R4,R5,R6,PC}

        .end

