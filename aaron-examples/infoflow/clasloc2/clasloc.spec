Globals:
z: bv32
nondet: bv32

L: z -> true, nondet -> true

Subroutine: unknown
Ensures: Gamma_R0_out

Subroutine: sink
Requires: Gamma_R0_in

Subroutine: source
Ensures: Gamma_R0_out <==> z != 1bv32