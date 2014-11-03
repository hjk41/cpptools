#include <chrono>
#include <thread>
#include <cstdint>
using namespace std;

double get_time()
{
        using namespace std::chrono;
        high_resolution_clock::duration tp = high_resolution_clock::now().time_since_epoch();
        return (double) tp.count() * high_resolution_clock::period::num / high_resolution_clock::period::den;
}

void sleep_us(uint64_t us)
{
        std::this_thread::sleep_for(std::chrono::microseconds(us));
}
