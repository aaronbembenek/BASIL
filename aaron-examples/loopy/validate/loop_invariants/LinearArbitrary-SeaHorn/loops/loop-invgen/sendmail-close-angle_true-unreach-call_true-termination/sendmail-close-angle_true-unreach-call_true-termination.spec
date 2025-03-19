Globals:
my_nondet: bv32
in: bv32
inlen: bv32
bufferlen: bv32
buf: bv32
buflim: bv32

L: my_nondet -> true, in -> true, inlen -> true, bufferlen -> true, buf -> true, buflim -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_in && Gamma_inlen && Gamma_bufferlen && Gamma_buf && Gamma_buflim

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
