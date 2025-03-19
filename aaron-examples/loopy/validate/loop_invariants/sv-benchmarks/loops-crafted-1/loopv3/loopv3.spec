Globals:
SIZE: bv32
my_nondet: bv32
i: bv32
j: bv32

L: SIZE -> true, my_nondet -> true, i -> true, j -> true

Subroutine: main
Requires: Gamma_SIZE && Gamma_my_nondet && Gamma_i && Gamma_j

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
