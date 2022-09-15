#include <thread>
#include <iostream>

void init_Function() {
    std::cout << "Hello, Concurrency World !" << std::endl;
}

int main() {
    std::thread t(init_Function);
    t.join();
}
