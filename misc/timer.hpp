struct Timer {
    chrono::system_clock::time_point start;

    Timer() { reset(); }
    void reset() { start = chrono::system_clock::now(); }

    // return millisecond
    inline double get_second() {
        chrono::system_clock::time_point now = chrono::system_clock::now();
        return (double) chrono::duration_cast<chrono::milliseconds> (now - start).count();
    }
};
