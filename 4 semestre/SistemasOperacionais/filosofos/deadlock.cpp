#include <iostream>
#include <thread>
#include <mutex>

std::mutex garfo1, garfo2, garfo3, garfo4, garfo5;

void philosopher(std::string name, std::mutex &left_fork, std::mutex &right_fork) {
    while (true) {
        std::cout << name << " está pensando...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << name << " tenta pegar o garfo esquerdo.\n";
        left_fork.lock();

        std::cout << name << " pegou o garfo esquerdo e tenta pegar o garfo direito.\n";
        right_fork.lock();

        std::cout << name << " está comendo.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << name << " terminou de comer e largou os garfos.\n";
        left_fork.unlock();
        right_fork.unlock();
    }
}

int main() {
    std::thread t1(philosopher, "Platão", std::ref(garfo1), std::ref(garfo2));
    std::thread t2(philosopher, "Aristóteles", std::ref(garfo2), std::ref(garfo3));
    std::thread t3(philosopher, "Ednaldo Pereira", std::ref(garfo3), std::ref(garfo4));
    std::thread t4(philosopher, "Bruno Aiub", std::ref(garfo4), std::ref(garfo5));
    std::thread t5(philosopher, "Lil Pump", std::ref(garfo5), std::ref(garfo1));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}