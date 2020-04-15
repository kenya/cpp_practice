#include <thread>
#include <iostream>

int main()
{
    int x = 0, y = 0;

    std::thread t1([&]{ ++x; });
    std::thread t2([&]{ ++x; });
    --y;
    t1.join();
    t2.join();

    std::cout << x << " " << y << std::endl;
    std::cout << t1.get_id() << std::endl;
    std::cout << t2.get_id() << std::endl;
    return 0;
}
