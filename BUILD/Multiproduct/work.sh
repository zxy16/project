cd ..
cd ..
cd ModuleA
make
mv libstulib.so ../RELEASE
cd ..
cd ModuleB
make
mv libclasslib.so ../RELEASE
cd ..
make
export LD_LIBRARY_PATH=/home/zxy16/review/MyProject/RELEASE
i=1;
./main
while [ $i -eq 1 ]
do
    echo 0.退出系统
	echo 1.再次操作
	read i
	if [ $i -eq 1 ]
	then
	./main
	elif [ $i -eq 0 ]
	then
	echo 欢迎下次使用本系统
	fi
done
