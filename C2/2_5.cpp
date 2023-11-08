void f(int i, std::string &s);

void not_oops(int some_param)
{
    char buffer[1024];
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 3, std::string(buffer));
    t.detach()
}

std::thread f()
{
    void some_func();
    return std::thread(some_func);
}

std::thread g()
{
    void some_other_func(int);
    std::thread t(some_othre_func, 42);
    return t;
}

void f(std::thread t);
void g()
{
    void some_func();
    f(std::thread(some_func));
    std::thread t(some_func);
    f(std::move(t));
}