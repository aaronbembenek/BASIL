Subroutine: my_assert
Requires: R0_in != 0bv64
Ensures DIRECT: "stack == memory_store32_le(old(stack), bvadd64(R31_in, 18446744073709551612bv64), memory_load32_le(stack, bvadd64(R31_in, 18446744073709551612bv64)))"

Subroutine: my_unknown 
Ensures DIRECT: "stack == memory_store64_le(memory_store64_le(old(stack), bvadd64(R31_in, 18446744073709551600bv64), memory_load64_le(stack, bvadd64(R31_in, 18446744073709551600bv64))), bvadd64(R31_in, 18446744073709551608bv64), memory_load64_le(stack, bvadd64(R31_in, 18446744073709551608bv64)))"
