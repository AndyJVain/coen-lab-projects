        .syntax     unified
	.cpu        cortex-m4
        .text
        .thumb_func
        .align       2

            // int Modulus(int number, int divisor);

            .global     Modulus
Modulus:    SDIV        R2,R0,R1        // R2 <-- (number/divisor)
            MLS         R2,R2,R1,R0     // R2 <-- (number - divisor*(number/divisor))
            ADD         R2,R2,R1        // R2 <-- (number % divisor) + divisor
            SDIV        R3,R2,R1        // R3 <-- (((number % divisor) + divisor)/divisor)
            MLS         R3,R1,R3,R2     // R3 <-- ((number % divisor) + divisor) - divisor*(((number % divisor) + divisor)/divisor)
            MOV         R0,R3           // R0 <-- Result
            BX          LR
            .end
