#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

bool done = false;
std::mutex m;
std::condition_variable c;

//bloqueo join personalizado
void custom_join1() {
    std::unique_lock<std::mutex> lock(m);
    c.wait(lock, []{ return done; });
}

//bloqueo explicito
void custom_join2() {
    std::unique_lock<std::mutex> lock(m);
    while (!done) {
        c.wait(lock);
    }
}

/*
//bloqueo de alcance, forma invalida
void custom_join3() {
    std::lock_guard<std::mutex> lock(m);
    c.wait(m, []{ return done; });
}
//*/

int main () {
    auto child = [] () -> void {
        std::cout << "child" << std::endl;

        std::unique_lock<std::mutex> lock(m);
        done = true;
        c.notify_one();
    };

    std::thread thread(child);
    custom_join1();

    std::cout << "parent" << std::endl;
}
