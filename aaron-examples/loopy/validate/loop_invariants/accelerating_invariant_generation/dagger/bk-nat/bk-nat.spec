Globals:
my_nondet: bv32
invalid: bv32
unowned: bv32
nonexclusive: bv32
exclusive: bv32

L: my_nondet -> true, invalid -> true, unowned -> true, nonexclusive -> true, exclusive -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_invalid && Gamma_unowned && Gamma_nonexclusive && Gamma_exclusive

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
