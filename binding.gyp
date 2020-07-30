{
    "targets": [
        {
            "target_name": "sdl2_node",
            "cflags": ["-fexceptions", "-lSDL2", "-pthread"],
            "cflags_cc": ["-fexceptions", "-lSDL2", "-pthread"],
            "sources": ["lib/sdl2/main.cpp"],
            "include_dirs": ["<!@(node -p 'require(\"node-addon-api\").include')"],
            "libraries": [],
            "dependencies": ["<!(node -p 'require(\"node-addon-api\").gyp')"],
            "defines": ["NAPI_CPP_EXCEPTIONS"],
            "conditions": [
                ['OS=="linux" and target_arch=="x64"', {
                    "libraries": [
                        "/usr/lib/x86_64-linux-gnu/libSDL2-2.0.so",
                    ],
                    "include_dirs": [
                        "/usr/include/SDL2"
                    ]
                }],
            ]
        }
    ]
}
