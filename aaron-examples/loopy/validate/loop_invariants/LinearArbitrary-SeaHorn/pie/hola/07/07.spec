Globals:
my_nondet: bv32
i: bv32
n: bv32
a: bv32
b: bv32

L: my_nondet -> true, i -> true, n -> true, a -> true, b -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_i && Gamma_n && Gamma_a && Gamma_b

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
