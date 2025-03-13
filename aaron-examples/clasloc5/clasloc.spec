Globals:
public: bv32
secret: bv32
sink_mode: bv32
source_mode: bv32
sink_lock: bv32
source_lock: bv32

L: public -> true, secret -> false, sink_mode -> true, source_mode -> true, sink_lock -> true, source_lock -> true

Rely: (old(sink_lock) == 1bv32 ==> old(sink_mode) == sink_mode && sink_lock == 1bv32) &&
        (old(source_lock) == 1bv32 ==> old(source_mode) == source_mode && source_lock == 1bv32)
Guarantee: (old(sink_lock) == 2bv32 ==> old(sink_lock) == sink_lock && old(sink_mode) == sink_mode) &&
        (old(source_lock) == 2bv32 ==> old(source_lock) == source_lock && old(source_mode) == source_mode)

Subroutine: unknown
Ensures: Gamma_R0_out

Subroutine: sink_at_mode
Requires: (Gamma_R0_in || sink_mode == 1bv32) && sink_lock == 1bv32
Ensures: sink_lock == old(sink_lock)

Subroutine: source_at_mode
Requires: source_lock == 1bv32
Ensures: (Gamma_R0_out || old(source_mode) == 1bv32) && source_lock == old(source_lock)
