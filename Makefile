.PHONY: run

target := main

libs := -lfreeglut

ifeq ($(OS), Windows_NT)
    target := $(target).exe
    libs := $(libs) -lopengl32 -lglew32
else
	libs := $(libs) -lGL -LGLEW
endif

run: $(target)
	./$(target)

$(target): main.cpp Makefile
	g++ -Wall -std=c++17 -Iinclude -IGLUT/include -Llib-mingw-w64 -LGLEW/lib/Release/x64 -LGLUT/lib/x64 -o main main.cpp $(libs)