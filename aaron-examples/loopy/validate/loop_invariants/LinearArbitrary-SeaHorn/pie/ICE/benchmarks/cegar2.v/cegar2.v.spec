Globals:
my_nondet: bv32
N: bv32
x: bv32
m: bv32
input: bv32
v1: bv32
v2: bv32
v3: bv32

L: my_nondet -> true, N -> true, x -> true, m -> true, input -> true, v1 -> true, v2 -> true, v3 -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_N && Gamma_x && Gamma_m && Gamma_input && Gamma_v1 && Gamma_v2 && Gamma_v3

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
