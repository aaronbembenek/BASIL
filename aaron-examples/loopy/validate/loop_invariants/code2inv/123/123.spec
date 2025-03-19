Globals:
my_nondet: bv32
i: bv32
size: bv32
sn: bv32
v1: bv32
v2: bv32
v3: bv32

L: my_nondet -> true, i -> true, size -> true, sn -> true, v1 -> true, v2 -> true, v3 -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_i && Gamma_size && Gamma_sn && Gamma_v1 && Gamma_v2 && Gamma_v3

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
