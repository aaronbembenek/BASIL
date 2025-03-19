Globals:
my_nondet: bv32
sn: bv32
loop1: bv32
n1: bv32
x: bv32

L: my_nondet -> true, sn -> true, loop1 -> true, n1 -> true, x -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_sn && Gamma_loop1 && Gamma_n1 && Gamma_x

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
