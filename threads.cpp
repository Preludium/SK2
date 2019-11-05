#include <pthread.h>
#include <unistd.h>
#include <thread>
//using namespace std;
    
void* func (void*) {
    sleep(1);
    return nullptr;
}

void fn(int x)
{
    sleep(x);

}

int main() {

    int x = 2;
    std::thread t;
    {
        t = std::thread(fn, x);
    }
    t.detach();

    pthread_t tid;
    pthread_create(&tid, nullptr, func, nullptr);
    
    void* ptr;
    pthread_join(tid, &ptr);
    return 0;
}