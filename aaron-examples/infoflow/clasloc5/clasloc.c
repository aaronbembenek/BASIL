#include <stdatomic.h>

#define LO 0
#define HI 1

int sink_mode;
int source_mode;
int public;
int secret;
atomic_int sink_lock;
atomic_int source_lock;

int unknown() { return public; }

int source_at_mode() {
    if (source_mode == HI) {
        return secret;
    }
    return public;
}

void sink_at_mode(int x) {
    if (sink_mode == HI) {
        secret = x;
    } else {
        public = x;
    }
}

int main() {
    unsigned data = 0;
    int cur_mode = LO;
    while (unknown()) {
        int new_mode = unknown() > 0;
        if (new_mode != cur_mode) {
            int expected = 0;
            while (!atomic_compare_exchange_weak(&sink_lock, &expected, 1)) {
                expected = 0;
                while (sink_lock != 0) {}
            }
            sink_mode = cur_mode;
            sink_at_mode(data);
            sink_lock = 0;
            data = 0;
            cur_mode = new_mode;
        }
        int expected = 0;
        while (!atomic_compare_exchange_weak(&source_lock, &expected, 1)) {
            expected = 0;
            while (source_lock != 0) {}
        }
        source_mode = cur_mode;
        data += source_at_mode();
        source_lock = 0;
    }
}