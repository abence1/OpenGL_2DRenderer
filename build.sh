clang++ -std=c++17 -fdiagnostics-color=always -Wall -g \
  -I./dependencies/include \
  -L./dependencies/library \
  ./dependencies/library/libglfw.3.4.dylib \
  ./src/*.cpp ./src/glad.c \
  -o ./app \
  -framework OpenGL -framework Cocoa -framework IOKit \
  -framework CoreVideo -framework CoreFoundation \
  -Wno-deprecated
