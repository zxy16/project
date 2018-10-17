main:main.c
	gcc -I./ModuleA -I./ModuleB main.c -o main -L./RELEASE -lstulib -lclasslib
