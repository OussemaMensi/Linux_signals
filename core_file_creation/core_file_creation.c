int main() {
    volatile int x = 1;
    volatile int y = 0;
    int z = x / y;  // SIGFPE garanti ( division par 0)
    return 0;
}
