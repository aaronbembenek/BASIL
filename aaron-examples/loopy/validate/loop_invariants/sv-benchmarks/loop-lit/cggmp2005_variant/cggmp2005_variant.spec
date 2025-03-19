Globals:
my_nondet: bv32
lo: bv32
mid: bv32
hi: bv32

L: my_nondet -> true, lo -> true, mid -> true, hi -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_lo && Gamma_mid && Gamma_hi

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
