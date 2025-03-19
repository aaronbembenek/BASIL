Globals:
my_nondet: bv32
x: bv32
e: bv32
s: bv32

L: my_nondet -> true, x -> true, e -> true, s -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_e && Gamma_s

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
