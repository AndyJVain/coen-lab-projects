        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// extern Remainder2(int s32, int k);

                .global     Remainder2
Remainder2:     LDR         R2,=1       // R2 <-- 1
                LSL         R2,R2,R1    // R2 <-- Divisor (Shift R2 left by k to have 2^k)
                SUB         R1,R2,1     // R1 <-- 2^k - 1
                AND         R1,R1,R0    // R1 <-- modulus
                CMP         R0,0        // Compare to see if number < 0
                ITE         LT
                SUBLT       R0,R1,R2    // Mod - divisor if number is negative
                MOVGE       R0,R1       // Move modulus into R0 if positive
                BX          LR

                .end

