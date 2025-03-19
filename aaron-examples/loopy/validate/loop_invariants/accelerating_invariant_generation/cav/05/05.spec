Globals:
my_nondet: bv32
x: bv32
flag: bv32
y: bv32
j: bv32
i: bv32

L: my_nondet -> true, x -> true, flag -> true, y -> true, j -> true, i -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_x && Gamma_flag && Gamma_y && Gamma_j && Gamma_i

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
