Globals:
my_nondet: bv32
x1: bv32
x2: bv32
x3: bv32
x1p: bv32
x2p: bv32
x3p: bv32
input: bv32

L: my_nondet -> true, x1 -> true, x2 -> true, x3 -> true, x1p -> true, x2p -> true, x3p -> true, input -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x1 && Gamma_x2 && Gamma_x3 && Gamma_x1p && Gamma_x2p && Gamma_x3p && Gamma_input

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
