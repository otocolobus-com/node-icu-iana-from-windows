{
    "targets": [
        {
            "target_name": "icu-iana-from-windows",
            "sources": ["src/icu-iana-from-windows.cc"],
            "cflags_cc": ["-std=c++17"],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "include_dirs": [
                "./node_modules/node-addon-api",
            ],
            "conditions": [
                [
                    "OS == 'win'",
                    {
                        "include_dirs": [
                            "<!(pkg-config --cflags-only-I icu-i18n | sed 's/-I//g')",
                        ],
                        "libraries": [
                            "<!(pkg-config --libs-only-L icu-i18n)",
                        ],
                    },
                ],
                [
                    "OS == 'linux'",
                    {
                        "include_dirs": [
                            "<!(pkg-config --cflags-only-I icu-i18n | sed 's/-I//g')",
                        ],
                        "libraries": [
                            "<!(pkg-config --libs-only-L icu-i18n)",
                        ],
                    },
                ],
                [
                    "OS == 'mac'",
                    {
                        "include_dirs": [
                            "<!(brew --prefix icu4c)/include",
                        ],
                        "libraries": [
                            "-L<!(brew --prefix icu4c)/lib",
                        ],
                    },
                ],
            ],
        }
    ],
}
