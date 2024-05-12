#!/bin/bash
# make -C philo_bonus && clear
# exe=./philo_bonus/philo_bonus
make && clear
exe=./philo

tests=10

x=1
time=0.1
echo -e "\e[41;30m teste(1/14) 2 100 200 200 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 100 200 200 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m teste(2/14) 2 150 360 100 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 150 360 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m teste(3/14) 2 150 200 100 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 150 200 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m teste(4/14) 1 400 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m teste(5/14) 4 210 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m teste(6/14) 1 800 200 200 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 1 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m teste(7/14) 5 800 200 200 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 5 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo
x=1
time=0.1
echo -e "\e[41;30m teste(8/14) 4 310 200 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m teste(9/14) 5 400 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo
x=1
time=0.1
echo -e "\e[41;30m teste(10/14) 5 200 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 5 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m teste(11/14) 3 400 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo
x=1
time=0.1
echo -e "\e[41;30m teste(12/14) 3 200 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 3 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m teste(13/14) 4 410 200 200 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 4 410 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m teste(14/14) 4 399 200 200 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 4 399 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo