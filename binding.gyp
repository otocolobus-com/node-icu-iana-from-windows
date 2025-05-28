{
    "targets": [
        {
            "target_name": "icu-iana-from-windows",
            "sources": ["src/icu-iana-from-windows.cc"],
            "cflags_cc": ["-std=c++17"],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "include_dirs": [
                "./node_modules/node-addon-api",
                "<!(pkg-config --cflags-only-I icu-i18n | sed 's/-I//g')",
            ],
            "libraries": [],
        }
    ],
}
