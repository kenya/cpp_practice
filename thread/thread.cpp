#include <thread>
#include <iostream>

int main()
{
    int x = 0, y = 0;

    std::thread t([&]{ ++x; });
    --y;
    t.join();

    std::cout << x << " " << y << std::endl;
    return 0;
}
