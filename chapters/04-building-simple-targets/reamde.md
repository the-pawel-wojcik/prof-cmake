# 4 Building Simple Targets
```bash
cmake -S src -B build
cmake --build build  # does not build the helper tool excluded from ALL
cmake --build build --target reporter  # Call the target explicitly
```

Build a shared library
```bash
cmake -DBUILD_SHARED_LIB=NO -S src/ -B build
cmake --build build --target mylib
```

Link with a library
```bash
cmake -S src/ -B build
cmake --build build --target mylib
cmake --build build --target reporter
```
