Globals:
my_nondet: bv32
a: bv32
m: bv32
j: bv32
k: bv32

L: my_nondet -> true, a -> true, m -> true, j -> true, k -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_a && Gamma_m && Gamma_j && Gamma_k

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
