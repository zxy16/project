gcc -c -I ~/review/MyProject/ModuleB ~/review/MyProject/ModuleB/classlib.c -o ~/review/MyProject/ModuleB/classlib.o
ar -rsv ~/review/MyProject/ModuleB/libclasslib.a ~/review/MyProject/ModuleB/classlib.o
gcc -o class class.c -I ~/review/MyProject/ModuleB/ -L ~/review/MyProject/ModuleB/ -lclasslib
~/review/MyProject/ModuleB/class
