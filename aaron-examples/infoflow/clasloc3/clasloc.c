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

#define BUF_SIZE 3

int main() {
    clasloc_t buf[BUF_SIZE];
    for (unsigned i = 0; i < BUF_SIZE; ++i) {
        int data = source();
        buf[i] = (clasloc_t) { z, data };
    }
    clasloc_t e = buf[0];
    if (e.level != HI) {
        sink(buf[0].data);
    }
}