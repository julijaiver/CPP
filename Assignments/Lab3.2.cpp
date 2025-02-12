#include <deque>
#include <iostream>

class RunningAverage {
    public:
        explicit RunningAverage(int size);
        void add_value(int value);
        [[nodiscard]] double get_average() const;
    private:
        std::deque<int> data;
        const int size;
        double deque_sum;
};

int main() {
    RunningAverage avg(5);

    while (true) {
        int input;
        std::cout << "Enter a number or 0 to stop: ";
        std::cin >> input;
        if (input != 0) {
            avg.add_value(input);
            std::cout << "Running average: " << avg.get_average() << std::endl;
        } else {
            std::cout << "Running average: " << avg.get_average() << std::endl;
            break;
        }
    }
    return 0;
}

RunningAverage::RunningAverage(const int size) : size(size) , deque_sum(0) {
}

void RunningAverage::add_value(const int value) {
    if (data.size() >= size) {
        deque_sum -= data.front();
        data.pop_front();
    }
    data.push_back(value);
    deque_sum += value;
}

double RunningAverage::get_average() const {
    if (data.empty()) {
        return 0;
    }
    return deque_sum / data.size();   //static_cast<double>(data.size());
}
