#include <napi.h>
#include "SDL.h"

namespace SDLN_Power {

    /**
     * SDL_GetPowerInfo() binding.
     */
    Napi::Object GetPowerInfo(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();

        int seconds;
        int percentage;
        int power = (int) SDL_GetPowerInfo(&seconds, &percentage);

        Napi::Object powerLevelInfo = Napi::Object::New(env);

        powerLevelInfo.Set(Napi::String::New(env, "secs"), seconds);
        powerLevelInfo.Set(Napi::String::New(env, "pct"), percentage);
        powerLevelInfo.Set(Napi::String::New(env, "state"), power);

        return powerLevelInfo;
    }

    /**
     * Exports for SDL_Power bindings.
     */
    Napi::Object Init(Napi::Env env, Napi::Object exports) {
        
        Napi::Object powerLevelEnum = Napi::Object::New(env);

        powerLevelEnum.Set(Napi::String::New(env, "SDL_POWERSTATE_UNKNOWN"), (int)SDL_POWERSTATE_UNKNOWN);
        powerLevelEnum.Set(Napi::String::New(env, "SDL_POWERSTATE_ON_BATTERY"), (int)SDL_POWERSTATE_ON_BATTERY);
        powerLevelEnum.Set(Napi::String::New(env, "SDL_POWERSTATE_NO_BATTERY"), (int)SDL_POWERSTATE_NO_BATTERY);
        powerLevelEnum.Set(Napi::String::New(env, "SDL_POWERSTATE_CHARGING"), (int)SDL_POWERSTATE_CHARGING);
        powerLevelEnum.Set(Napi::String::New(env, "SDL_POWERSTATE_CHARGED"), (int)SDL_POWERSTATE_CHARGED);

        exports.Set(Napi::String::New(env, "SDL_PowerState"), powerLevelEnum);
        exports.Set(Napi::String::New(env, "SDL_GetPowerInfo"), Napi::Function::New(env, GetPowerInfo));

        return exports;
    }
}
