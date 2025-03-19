Globals:
my_nondet: bv32
i: bv32
j: bv32
c: bv32
t: bv32

L: my_nondet -> true, i -> true, j -> true, c -> true, t -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_i && Gamma_j && Gamma_c && Gamma_t

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
