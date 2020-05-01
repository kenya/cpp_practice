#include <iostream>
#include <atomic>
#include <thread>
#include <boost/asio/io_context.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio/executor_work_guard.hpp>

#define MAX 20000
namespace as = boost::asio;

int main() {
    as::io_context ioc;
    // ioc.run()をreturnさせないもの
    as::executor_work_guard<decltype(ioc.get_executor())> work{ioc.get_executor()};
    std::atomic<int> x = 0;
    std::thread t1([&ioc](){ ioc.run(); });
    std::thread t2([&ioc](){ ioc.run(); });
    for (int i = 0; i < MAX; ++i) {
        as::post(ioc, [&x](){ ++x; });
        if (i == MAX - 1) {
            as::post(ioc, [&x](){ std::cout << x << std::endl; });
        }
    }
    // joinがなければabort trap:6が出る
    t1.join();
    t2.join();
}
