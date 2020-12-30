
template<class T> struct PQueue {
    struct NODE { T VALUE; NODE* NEXT; };
    NODE* HEAD; NODE* TAIL; size_t SIZE;

    PQueue() {
        HEAD = NULL;
        TAIL = NULL;
        SIZE = 0;
    }
    size_t size() {
        return SIZE;
    }
    bool empty() {
        return (SIZE == 0);
    }
    T front() {
        assert(HEAD != NULL);
        return HEAD->VALUE;
    }
    T pop() {
        assert(SIZE > 0);
        T result = HEAD->VALUE;
        HEAD = HEAD->NEXT; SIZE--;
        return result;
    }
    void push(T v) {
        NODE* TEMP = new NODE;
        TEMP->VALUE = v, TEMP->NEXT = NULL;
        if (HEAD == NULL) {
            HEAD = TEMP;
            TAIL = TEMP;
        } else {
            TAIL->NEXT = TEMP;
            TAIL = TAIL->NEXT;
        }
        SIZE++;
    }
};