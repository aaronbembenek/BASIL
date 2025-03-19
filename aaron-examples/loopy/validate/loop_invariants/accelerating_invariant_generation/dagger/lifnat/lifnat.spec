Globals:
my_nondet: bv32
I: bv32
Sa: bv32
Ea: bv32
Ma: bv32
Sb: bv32
Eb: bv32
Mb: bv32

L: my_nondet -> true, I -> true, Sa -> true, Ea -> true, Ma -> true, Sb -> true, Eb -> true, Mb -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_I && Gamma_Sa && Gamma_Ea && Gamma_Ma && Gamma_Sb && Gamma_Eb && Gamma_Mb

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
