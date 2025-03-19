Globals:
my_nondet: bv32
i: bv32
size: bv32
sn: bv32

L: my_nondet -> true, i -> true, size -> true, sn -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_i && Gamma_size && Gamma_sn

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
