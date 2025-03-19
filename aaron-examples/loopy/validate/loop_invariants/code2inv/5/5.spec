Globals:
my_nondet: bv32
x: bv32
size: bv32
y: bv32
z: bv32

L: my_nondet -> true, x -> true, size -> true, y -> true, z -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_size && Gamma_y && Gamma_z

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
