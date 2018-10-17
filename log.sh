a=0
b=0
c=0
d=0
e=0
f=0
g=0
h=0
echo <log.txt
while read line
	do
		echo $line
		a1=` echo $line | awk '{printf $1 $2}'`
		echo $a1
		if [ "$a1" == "findstudent" ]
			then
			a=$(($a+1))
			elif [ "$a1" == "findclass" ]
			then
			b=$(($b+1))
			elif [ "$a1" == "deleteclass " ]
			then
			c=$(($c+1))
			elif [ "$a1" == "addclass" ]
			then
			d=$(($c+1))
			elif [ "$a1" == "amendclass" ]
			then
			e=$(($c+1))
			elif [ "$a1" == "deletestudent" ]
			then
			f=$(($c+1))
			elif [ "$a1" == "addstudent" ]
			then
			g=$(($c+1))
			elif [ "$a1" == "amendstudent" ]
			then
			h=$(($c+1))
		fi
	done<log.txt
	echo "您查看了学生的信息次数" $a
	echo "您查看了课程信息次数" $b
	echo "您删除课程信息次数" $c
	echo "您添加课程信息次数" $d
	echo "您修改课程信息次数" $e
	echo "您删除学生信息次数" $f
	echo "您添加学生信息次数" $g
	echo "您修改学生信息次数" $h
	echo "请输入student或者class"
	read name
	echo "请输入想要查看的学生的学号或者课程的编号"
	read num
	b=0
	while read line
		do
			a2=`echo $line | awk {'printf $3'}`
			a3=`echo $line | awk {'printf $2'}`
			if [ "$name" != "$a3" ]
				then
				continue
				elif [ "$name" == "$a3" ]
				then
				if [ "$num" == "$a2" ]
				then
				b=1
				echo "已修改过"
				break
				fi
				fi
				done<log.txt
				if [ $b -eq 0 ]
					then
					echo "未修改过"
					fi
