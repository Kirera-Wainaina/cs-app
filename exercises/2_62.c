int int_shifts_are_arithmetic() {
    // Yields 1 when run on a machine with arithmetic shifts
    int x = -1;
    return (x >> 1) == -1;
}
