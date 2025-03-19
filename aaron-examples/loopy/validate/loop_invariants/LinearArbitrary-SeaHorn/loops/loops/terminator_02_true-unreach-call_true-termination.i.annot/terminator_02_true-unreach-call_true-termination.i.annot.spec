Globals:
my_nondet: bv32
x: bv32
y: bv32
z: bv32
tmp: bv32

L: my_nondet -> true, x -> true, y -> true, z -> true, tmp -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_y && Gamma_z && Gamma_tmp

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
