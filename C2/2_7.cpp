#include <thread>
#include <vector>
void do_work(unsigned id);
void f()
{
    std::vector<std::thread> threads;
    for (auto i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(do_work, i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
