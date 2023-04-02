#!/bin/bash



read choice

case $choice in
		
 

 0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9] )
	echo "Grade is D"
				;;
5[1-9])
	echo "Grade is C"
				;;
6[0-9])
	echo "Grade is B"
				;;
7[0-9])
	echo "Grade is B+"
				;;
8[0-9]*)
	echo "Grade is A"
				;;

*) 
	echo "Wrong Input"
				;;
esac


#!/bin/bash

read a1
read a2

echo "Enter 1 for Addition"
echo "Enter 2 for Subtraction"
echo "Enter 3 for Multiplication"
echo "Enter 4 for Division"

read choice
case $choice in
1)
	a3=$(($a1+$a2))
	echo "VAlue is " $a3
				;;
2)
	a3=$(($a1-$a2))
	echo "VAlue is " $a3
				;;
3)
	a3=$(($a1*$a2))
	echo "VAlue is " $a3
				;;
4)
	a3=$(($a1/$a2))
	echo "VAlue is " $a3
				;;
esac 
