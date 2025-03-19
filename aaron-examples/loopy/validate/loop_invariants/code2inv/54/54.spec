Globals:
my_nondet: bv32
c: bv32
n: bv32
v1: bv32
v2: bv32
v3: bv32

L: my_nondet -> true, c -> true, n -> true, v1 -> true, v2 -> true, v3 -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_c && Gamma_n && Gamma_v1 && Gamma_v2 && Gamma_v3

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
