Globals:
my_nondet: bv32
MAXPATHLEN: bv32
pathbuf_off: bv32
bound_off: bv32
glob2_p_off: bv32
glob2_pathbuf_off: bv32
glob2_pathlim_off: bv32

L: my_nondet -> true, MAXPATHLEN -> true, pathbuf_off -> true, bound_off -> true, glob2_p_off -> true, glob2_pathbuf_off -> true, glob2_pathlim_off -> true

Subroutine: main
Requires: Gamma_my_nondet && Gamma_MAXPATHLEN && Gamma_pathbuf_off && Gamma_bound_off && Gamma_glob2_p_off && Gamma_glob2_pathbuf_off && Gamma_glob2_pathlim_off

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
