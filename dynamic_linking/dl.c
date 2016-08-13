#include <iostream>
#include <dlfcn.h>

int main() {
    void* dl_handle;
    typedef float (*fptr)(float);
    fptr func;
    char* error;

    dl_handle = dlopen("libm.so.6", RTLD_LAZY);
    func = reinterpret_cast<fptr>(dlsym(dl_handle, "cosf"));
    std::cout << "output of func" << (*func)(0.0f);
    std::cout << "output of func" << (*func)(0.5f);
    dlclose(dl_handle);
}
