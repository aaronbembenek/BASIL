Globals:
my_nondet: bv32
i: bv32
j: bv32
from: bv32
to: bv32
k: bv32

L: my_nondet -> true, i -> true, j -> true, from -> true, to -> true, k -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_i && Gamma_j && Gamma_from && Gamma_to && Gamma_k

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
