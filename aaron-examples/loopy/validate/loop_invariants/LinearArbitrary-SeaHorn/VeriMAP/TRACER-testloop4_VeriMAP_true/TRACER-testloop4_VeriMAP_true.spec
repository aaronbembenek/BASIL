Globals:
my_nondet: bv32
x: bv32
N: bv32
a: bv32

L: my_nondet -> true, x -> true, N -> true, a -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_N && Gamma_a

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
