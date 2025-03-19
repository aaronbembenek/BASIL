Globals:
my_nondet: bv32
w: bv32
x: bv32
y: bv32
z: bv32

L: my_nondet -> true, w -> true, x -> true, y -> true, z -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_w && Gamma_x && Gamma_y && Gamma_z

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
