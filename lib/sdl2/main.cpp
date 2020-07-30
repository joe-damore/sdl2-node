#include <napi.h>

#include "SDL_power.cpp"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    
    SDLN_Power::Init(env, exports);

    return exports;
}

NODE_API_MODULE(sdl2_node, Init);
