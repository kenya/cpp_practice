#include <iostream>
#include <atomic>
#include <thread>
#include <boost/asio/io_context.hpp>
#include <boost/asio/post.hpp>

#define MAX 20000
namespace as = boost::asio;

int main() {
    as::io_context ioc;
    std::atomic<int> x = 0;
    for (int i = 0; i < MAX; ++i) {
        as::post(ioc, [&x](){ ++x; });
        if (i == MAX - 1) {
            as::post(ioc, [&x](){ std::cout << x << std::endl; });
        }
    }
    std::thread t1([&ioc](){ ioc.run(); });
    std::thread t2([&ioc](){ ioc.run(); });
    t1.join();
    t2.join();
}
