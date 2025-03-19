Globals:
my_nondet: bv32
x: bv32

L: my_nondet -> true, x -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
