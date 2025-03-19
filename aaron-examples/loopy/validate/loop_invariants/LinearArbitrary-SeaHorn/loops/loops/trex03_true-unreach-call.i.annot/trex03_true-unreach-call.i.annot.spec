Globals:
my_nondet: bv32
x1: bv32
x2: bv32
x3: bv32
d1: bv32
d2: bv32
d3: bv32
c1: bv32
c2: bv32

L: my_nondet -> true, x1 -> true, x2 -> true, x3 -> true, d1 -> true, d2 -> true, d3 -> true, c1 -> true, c2 -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x1 && Gamma_x2 && Gamma_x3 && Gamma_d1 && Gamma_d2 && Gamma_d3 && Gamma_c1 && Gamma_c2

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
