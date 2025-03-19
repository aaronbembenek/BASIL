Globals:
my_nondet: bv32
j: bv32
k: bv32
n: bv32

L: my_nondet -> true, j -> true, k -> true, n -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_j && Gamma_k && Gamma_n

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
