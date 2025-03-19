Globals:
my_nondet: bv32
n: bv32
j: bv32
i: bv32
k: bv32

L: my_nondet -> true, n -> true, j -> true, i -> true, k -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_n && Gamma_j && Gamma_i && Gamma_k

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
