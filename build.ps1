cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug

# Clean without deleting
# cmake --build build --target clean

# From your Raytracer root
#rmdir /s /q build        # on Windows PowerShell or CMD
# or
#rm -rf build             # on Linux/macOS