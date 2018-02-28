        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// extern Q32     Q32Poly(Q32, Q32 [], int32_t) ;

            .global     Q32Poly
Q32Poly:    PUSH        {R4,R5,R6,R7,R8,R9,R10,R11,LR}
            CBZ         R3,End          // Checks if there are 0 terms
            MOV         R4,R0           // R4 <-- Lo x
            MOV         R5,R1           // R5 <-- Hi x
            MOV         R6,R2           // R6 <-- Coefs
            MOV         R7,R3           // R7 <-- Terms

            LDMIA       R6!,{R0,R1}     // R8,R9 <-- Lo coef, Hi coef
            MOV         R8,R0           // R8 <-- Lo coef
            MOV         R9,R1           // R9 <-- Hi coef

            MOV         R10,R4          // R10 <-- Used for power of lo x
            MOV         R11,R5          // R11 <-- Used for power of hi x

Top:        SUB         R7,R7,1         // Decrement the terms (counter)
            CBZ         R7,End          // Branch to the end if terms are now 0

            LDMIA       R6!,{R0,R1}     // R0,R1 <-- Next coef
            MOV         R2,R10          // R2 <-- Power of lo x power
            MOV         R3,R11          // R3 <-- Power of hi x power
            BL          Q32Product
            ADDS        R8,R8,R0        // R8 <-- R8 + Lo of Q32 Product
            ADC         R9,R9,R1        // R9 <-- R9 + Hi of Q32 Product

            MOV         R0,R4           // R0 <-- Lo x
            MOV         R1,R5           // R1 <-- Hi x
            MOV         R2,R10          // R2 <-- Lo x power
            MOV         R3,R11          // R3 <-- Hi x power
            BL          Q32Product
            MOV         R10,R0          // R10 <-- New lo x power
            MOV         R11,R1          // R11 <-- New hi x power

            B           Top             // Go back to beginning of loop
End:        MOV         R0,R8           // Move saved lo portion into R0
            MOV         R1,R9           // Move saved hi portion into R1
            POP         {R4,R5,R6,R7,R8,R9,R10,R11,LR}
            BX          LR

            .end
