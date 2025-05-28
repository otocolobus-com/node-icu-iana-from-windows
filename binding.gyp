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
            "libraries": [],
            "conditions": [
                [
                    "OS=='win'",
                    {
                        "variables": {
                            "vcpkg_root": "<!(echo %VCPKG_ROOT%)",
                            "vcpkg_default_triplet": "<!(echo %VCPKG_DEFAULT_TRIPLET%)",
                        },
                        "include_dirs": [
                            "<!(echo %VCPKG_ROOT%/installed/<!(echo %VCPKG_DEFAULT_TRIPLET%)/include)",
                        ],
                        "libraries": [
                            "<!(echo %VCPKG_ROOT%/installed/<!(echo %VCPKG_DEFAULT_TRIPLET%)/lib/icuin.lib)",
                            "<!(echo %VCPKG_ROOT%/installed/<!(echo %VCPKG_DEFAULT_TRIPLET%)/lib/icuuc.lib)",
                            "<!(echo %VCPKG_ROOT%/installed/<!(echo %VCPKG_DEFAULT_TRIPLET%)/lib/icudt.lib)",
                        ],
                    },
                ],
                [
                    "OS=='linux' or OS=='mac'",
                    {
                        "include_dirs": [
                            "<!(pkg-config --cflags-only-I icu-i18n | sed 's/-I//g')",
                        ],
                        "libraries": [
                            "<!(pkg-config --libs-only-L icu-i18n)",
                            "<!(pkg-config --libs-only-l icu-i18n)",
                        ],
                    },
                ],
            ],
            "xcode_settings": {
                "CLANG_CXX_LANGUAGE_STANDARD": "c++17",
                "CLANG_CXX_LIBRARY": "libc++",
            },
        }
    ],
}
