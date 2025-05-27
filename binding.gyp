{
  "targets": [
    {
      "target_name": "icu-iana-from-windows",
      "sources": [ "src/icu-iana-from-windows.cc" ],
      "include_dirs": [
        "./node_modules/node-addon-api",
        "<!(brew --prefix icu4c)/include"
      ],
      "libraries": [
        "-L<!(brew --prefix icu4c)/lib",
        "-licui18n", "-licuuc", "-licudata"
      ],
      "cflags_cc": [ "-std=c++17" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}