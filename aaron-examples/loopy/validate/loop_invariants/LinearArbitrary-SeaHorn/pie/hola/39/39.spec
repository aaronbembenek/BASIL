Globals:
MAXPATHLEN: bv32
my_nondet: bv32
buf_off: bv32
pattern_off: bv32
bound_off: bv32
glob3_pathbuf_off: bv32
glob3_pathend_off: bv32
glob3_pathlim_off: bv32
glob3_pattern_off: bv32
glob3_dc: bv32

L: MAXPATHLEN -> true, my_nondet -> true, buf_off -> true, pattern_off -> true, bound_off -> true, glob3_pathbuf_off -> true, glob3_pathend_off -> true, glob3_pathlim_off -> true, glob3_pattern_off -> true, glob3_dc -> true

Subroutine: main
Requires: Gamma_MAXPATHLEN && Gamma_my_nondet && Gamma_buf_off && Gamma_pattern_off && Gamma_bound_off && Gamma_glob3_pathbuf_off && Gamma_glob3_pathend_off && Gamma_glob3_pathlim_off && Gamma_glob3_pattern_off && Gamma_glob3_dc

Subroutine: my_unknown
Ensures: Gamma_R0_out

Subroutine: my_assert
Requires: R0_in != 0bv64
