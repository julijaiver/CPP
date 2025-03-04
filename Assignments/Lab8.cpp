#include <iostream>

class Counter {
public:
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual operator int() = 0;
    virtual ~Counter() {};
};

class LimitedCounter : public Counter {
    public:
        LimitedCounter(int const initial_value, const int upper_limit) :
            counter(initial_value), upper_limit(upper_limit) {}

        void inc() override {
            if (counter < upper_limit) {
                ++counter;
            }
        }
        void dec() override {
            if (counter > 0) {
                --counter;
            }
        }
        operator int() override {
            return counter;
        }
    private:
        int counter;
        const int upper_limit;
};

class OverflowCounter : public Counter {
    public:
        OverflowCounter(int const initial_value, const int upper_limit) :
            counter(initial_value), upper_limit(upper_limit) {}

        void inc() override {
            if (counter >= upper_limit) {
                counter = 0;
            } else {
                ++counter;
            }
        }
        void dec() override {
            if (counter == 0) {
                counter = upper_limit;
            } else {
                --counter;
            }
        }
        operator int() override {
            return counter;
        }
    private:
        int counter;
        const int upper_limit;
};

// you need to implement this function
void UseCounter(Counter& ctr, int num) {
    if (num > 0) {
        for (int i = 0; i < num; ++i) {
            ctr.inc();
        }
    } else if (num < 0) {
        for (int i = 0; i > num; --i) {
            ctr.dec();
        }
    }
}


int main(int argc, char** argv) {
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    std::cout << oc << std::endl;
    UseCounter(oc, 5);
    std::cout << oc << std::endl; // should display zero
    UseCounter(oc, -1);
    std::cout << oc << std::endl; // should display 9
    oc.dec();
    std::cout << oc << std::endl; // should display 8

    std::cout << lc << std::endl;
    lc.inc();
    std::cout << lc << std::endl;
    lc.dec();
    std::cout << lc << std::endl;
    for(int i = 0; i < 10; ++i) lc.inc();
    std::cout << lc << std::endl;
    UseCounter(lc, -9);
    std::cout << lc << std::endl;

    return 0;
}
