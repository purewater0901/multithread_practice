#include <iostream>
#include <thread>
#include <vector>

void test(int a)
{
    std::cout << a << std::endl;
}

class Bar
{
public:
    Bar()
    {
        N_ = 10;
    }

    void foo(const int& a, const int& b, int& result)
    {
        result = a+b;
    }

    void process()
    {
        std::vector<std::thread> thread_set(N_);
        std::vector<int> result(N_);
        for(int i=0; i<N_; ++i)
            thread_set[i] = std::thread(&Bar::foo, this, i, i, std::ref(result[i]));

        for(int i=0; i<N_; ++i)
            thread_set[i].join();

        for(int i=0; i<N_; ++i)
            std::cout << result[i] << std::endl;
    }

    int N_;
};

int main() {

    Bar bar;
    bar.process();

    std::cout << "Hello From main" << std::endl;

    return 0;
}
