#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

const int numFilosofos = 5;

enum Estado {
    PENSANDO,
    FAMINTO,
    COMENDO
};

mutex mtx;
condition_variable cv;
Estado estados[numFilosofos];

void testar(int filosofo) {
    if (estados[filosofo] == FAMINTO &&
        estados[(filosofo + 4) % numFilosofos] != COMENDO &&
        estados[(filosofo + 1) % numFilosofos] != COMENDO) {
        estados[filosofo] = COMENDO;
        cout << "Filósofo " << filosofo << " está comendo." << endl;
        cv.notify_all();
    }
}

void pegarGarfos(int filosofo) {
    unique_lock<mutex> lock(mtx);
    estados[filosofo] = FAMINTO;
    cout << "Filósofo " << filosofo << " está faminto." << endl;
    testar(filosofo);
    if (estados[filosofo] != COMENDO) {
        cv.wait(lock);
    }
}

void largarGarfos(int filosofo) {
    unique_lock<mutex> lock(mtx);
    estados[filosofo] = PENSANDO;
    cout << "Filósofo " << filosofo << " largou os garfos." << endl;
    testar((filosofo + 4) % numFilosofos);
    testar((filosofo + 1) % numFilosofos);
}


void filosofo(int filosofo) {
    while (true) {
        // Pensar
        cout << "Filósofo " << filosofo << " está pensando." << endl;
        this_thread::sleep_for(chrono::seconds(2));

        // Pegar garfos
        pegarGarfos(filosofo);

        // Comer
        cout << "Filósofo " << filosofo << " está comendo." << endl;
        this_thread::sleep_for(chrono::seconds(2));

        // Largar garfos
        largarGarfos(filosofo);
    }
}

int main() {
    thread filosofos[numFilosofos];

    for (int i = 0; i < numFilosofos; i++) {
        filosofos[i] = thread(filosofo, i);
    }

    for (int i = 0; i < numFilosofos; i++) {
        filosofos[i].join();
    }

    return 0;
}