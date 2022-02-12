.PHONY: run

target := main

ifeq ($(OS), Windows_NT)
    target := $(target).exe
    libs := $(libs) -lfreeglut -lopengl32 -lglew32 -lglu32
else
	libs := $(libs) -LGLEW -lglut -lGL -lGLU -lm
endif

run: $(target)
	./$(target)

$(target): main.cpp libs/*.cpp libs/*.hpp Makefile
	g++ -Wall -std=c++17 -Iinclude -IGLUT/include -Llib-mingw-w64 -LGLEW/lib/Release/x64 -LGLUT/lib/x64 -o main main.cpp libs/Cubo.cpp  libs/Malha.cpp libs/Vetor.cpp libs/Cilindro.cpp libs/Cone.cpp libs/Matriz.cpp libs/Transformacoes.cpp libs/Esfera.cpp libs/Luz.cpp libs/Material.cpp $(libs)