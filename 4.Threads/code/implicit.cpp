#include <iostream>
#include <thread>
#include <chrono> // Include for std::this_thread and std::chrono

void printName(const std::string& threadName) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread Name: " << threadName << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 500 milliseconds
    }
}

int main() {
    std::string name1 = "Thread 1";
    std::string name2 = "Thread 2";

    std::thread t1(printName, name1);
    std::thread t2(printName, name2);


    t1.detach();
    t2.detach();
 
    int a;
    std::cin>>a;
    return 0;
}
