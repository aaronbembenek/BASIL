Globals:
my_nondet: bv32
x: bv32
n: bv32
i: bv32
j: bv32

L: my_nondet -> true, x -> true, n -> true, i -> true, j -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_n && Gamma_i && Gamma_j

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
