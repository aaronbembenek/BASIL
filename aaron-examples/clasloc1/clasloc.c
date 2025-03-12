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
    while (unknown()) {
        int data = source();
        if (z != HI) {
            cur = data;
        }
    }
    sink(cur);
}