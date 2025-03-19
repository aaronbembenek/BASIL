Globals:
my_nondet: bv32
NONDET: bv32
i: bv32
N: bv32
a: bv32
x: bv32

L: my_nondet -> true, NONDET -> true, i -> true, N -> true, a -> true, x -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_NONDET && Gamma_i && Gamma_N && Gamma_a && Gamma_x

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
