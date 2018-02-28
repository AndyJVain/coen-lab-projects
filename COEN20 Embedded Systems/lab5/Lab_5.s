        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// int32_t minimum_asm(int32_t data[], int32_t count){

                .global     minimum_asm
minimum_asm:    LDR         R2,[R0],4       // R2 <-- Assumed minimum value
                CMP         R1,1            // Ends if there is only one value
                BEQ         End
                LDR         R3,[R0]         // R3 <-- Next Value


Top:            CMP         R3,R2           // Compares R3 (next value) with R2 (minimum)
                IT          LT
                MOVLT       R2,R3           // If it is less than the minimum, move it into R2 (minimum)

                SUB         R1,R1,1         // Decrement the count
                CMP         R1,0            // If it is 0, branch to the end
                BEQ         End
                LDR         R3,[R0],4       // Load the next value into R3 (next value)
                B           Top             // Go back to the beginning of the loop

End:            MOV         R0,R2           // Move R2 (minimum value) into R0
                BX          LR

                .end

