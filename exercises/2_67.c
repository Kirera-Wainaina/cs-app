int int_size_is_32() {
    int x = 1;
    return (x << 31 << 1) == 0;
}
