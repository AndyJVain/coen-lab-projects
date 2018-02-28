        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

// float Poly(float, float [], int32_t) ;

        .global     Poly
Poly:   CBZ         R1,End      // Checks if there are 0 terms
        VLDMIA      R0!,{S2}    // S2 <-- First coef
        VMOV        S3,S0       // S3 <-- Powers of x
Top:    SUB         R1,R1,1     // Decrement the terms (counter)
        CBZ         R1,End1     // Branch to the end if 0
        VLDMIA      R0!,{S1}    // S1 = Next coef
        VMLA.F32    S2,S1,S3    // S2 += S1*S3
        VMUL.F32    S3,S3,S0    // Create the next x term
        B           Top         // Start the loop over
End1:   VMOV        S0,S2       // Move the total into S0
End:    BX          LR

        .end

one:    .float      1.0

