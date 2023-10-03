class String {
    size_t capacity;

    union {
        struct {
            char *data;
            size_t size;
        } heapString;

        char stackString[15];
    };
};