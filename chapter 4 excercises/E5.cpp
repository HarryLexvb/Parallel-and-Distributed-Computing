#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>

bool done = false;
std::promise<void> done_promise;
std::future<void> done_future = done_promise.get_future();
std::mutex m;
std::condition_variable c;

auto child = []() -> void {
    std::cout << "child" << std::endl;

    {
        std::lock_guard<std::mutex> lock(m);
        done = true;
    }

    done_promise.set_value();
};

void custom_join() {
    done_future.wait();
}

int main() {
    std::thread thread(child);

    custom_join();

    std::cout << "parent" << std::endl;

    if (thread.joinable()) {
        thread.join();
    }

    return 0;
}
