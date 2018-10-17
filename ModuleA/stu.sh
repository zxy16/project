gcc -c -I ~/review/MyProject/ModuleA ~/review/MyProject/ModuleA/stulib.c -o ~/review/MyProject/ModuleA/stulib.o
ar -rsv ~/review/MyProject/ModuleA/libstulib.a ~/review/MyProject/ModuleA/stulib.o
gcc -o stu stu.c -I ~/review/MyProject/ModuleA/ -L ~/review/MyProject/ModuleA/ -lstulib
~/review/MyProject/ModuleA/stu
