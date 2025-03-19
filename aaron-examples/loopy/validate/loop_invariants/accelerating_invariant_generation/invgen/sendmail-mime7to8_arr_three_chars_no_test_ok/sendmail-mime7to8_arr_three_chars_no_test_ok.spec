Globals:
my_nondet: bv32
__BLAST_NONDET: bv32
fbuflen: bv32
fb: bv32

L: my_nondet -> true, __BLAST_NONDET -> true, fbuflen -> true, fb -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma___BLAST_NONDET && Gamma_fbuflen && Gamma_fb

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
