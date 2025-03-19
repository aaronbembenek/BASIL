Globals:
my_nondet: bv32
n: bv32
c: bv32

L: my_nondet -> true, n -> true, c -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_n && Gamma_c

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
