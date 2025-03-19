Globals:
my_nondet: bv32
x: bv32
y: bv32
z1: bv32
z2: bv32
z3: bv32

L: my_nondet -> true, x -> true, y -> true, z1 -> true, z2 -> true, z3 -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_y && Gamma_z1 && Gamma_z2 && Gamma_z3

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
