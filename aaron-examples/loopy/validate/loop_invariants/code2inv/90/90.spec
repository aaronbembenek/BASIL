Globals:
my_nondet: bv32
lock: bv32
v1: bv32
v2: bv32
v3: bv32
x: bv32
y: bv32

L: my_nondet -> true, lock -> true, v1 -> true, v2 -> true, v3 -> true, x -> true, y -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_lock && Gamma_v1 && Gamma_v2 && Gamma_v3 && Gamma_x && Gamma_y

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
