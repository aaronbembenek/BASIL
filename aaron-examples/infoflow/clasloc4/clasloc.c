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

int main() {
    int cur = 0;
    unsigned cnt = 0;
    while (unknown()) {
        cur = (++cnt % 2 != 0) ? source() : 0;
    }
    if (cnt % 2 == 0) {
        sink(cur);
    }
}