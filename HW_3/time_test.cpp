#include <cstdio>
#include <chrono>

int main()
{
    auto begin = std::chrono::system_clock::now();
    int a[1000000];
    for (int i = 0; i < 1000000; ++i){a[i]=i;}
        
    auto end = std::chrono::system_clock::now();

    std::printf("StackTime: %f seconds\n", std::chrono::duration<double>(end - begin).count());

    begin = std::chrono::system_clock::now();
    int *b=new int[1000000];
    for (int i = 0; i < 1000000; ++i){b[i]=i;}
    delete(b);
    end = std::chrono::system_clock::now();

    std::printf("HeapTime : %f seconds\n", std::chrono::duration<double>(end - begin).count());
    return 0;
}
