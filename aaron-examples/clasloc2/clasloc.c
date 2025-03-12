#define LO 0
#define HI 1

int z;
int nondet;

int unknown() { return nondet; }

int source() {
    z = LO;
    return nondet;
}

void sink(int) {}

typedef struct {
    int level;
    int data;
} clasloc_t;

int main() {
    clasloc_t cur = { LO, 0 };
    while (unknown()) {
        int data = source();
        cur = (clasloc_t) { z, data };
    }
    if (cur.level != HI) {
        sink(cur.data);
    }
}