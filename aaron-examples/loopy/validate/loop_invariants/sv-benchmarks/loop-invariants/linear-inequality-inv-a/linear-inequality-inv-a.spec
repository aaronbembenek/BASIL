Globals:
my_nondet: bv32
n: bv8
v: bv8
s: bv32
i: bv32

L: my_nondet -> true, n -> true, v -> true, s -> true, i -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_n && Gamma_v && Gamma_s && Gamma_i

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
