Globals:
my_nondet: bv32
lock: bv32
x: bv32
y: bv32

L: my_nondet -> true, lock -> true, x -> true, y -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_lock && Gamma_x && Gamma_y

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
