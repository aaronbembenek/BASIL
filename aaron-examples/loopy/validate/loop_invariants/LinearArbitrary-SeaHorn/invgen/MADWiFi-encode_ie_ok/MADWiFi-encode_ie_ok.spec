Globals:
my_nondet: bv32
p: bv32
i: bv32
leader_len: bv32
bufsize: bv32
bufsize_0: bv32
ielen: bv32

L: my_nondet -> true, p -> true, i -> true, leader_len -> true, bufsize -> true, bufsize_0 -> true, ielen -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_p && Gamma_i && Gamma_leader_len && Gamma_bufsize && Gamma_bufsize_0 && Gamma_ielen

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
