Globals:
my_nondet: bv32
c: bv32
y: bv32
z: bv32

L: my_nondet -> true, c -> true, y -> true, z -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_c && Gamma_y && Gamma_z

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
