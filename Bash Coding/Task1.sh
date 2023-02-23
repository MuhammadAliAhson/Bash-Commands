#!/bin/bash

read var1

case $var1 in
100) echo "A+ grade";;
9[0-9]) echo "A grade";;
[0-59]*) echo "D grade";;
6[0-9]) echo "C grade";;
7[0-9]) echo "B grade";;
8[0-9]) echo "B+ grade";;
*) echo "Wrong input";;
esac



# calculator

echo "Enter Two numbers : "
read a
read b
echo "Enter Choice for the operation :"
echo "1. Addition (+)"
echo "2. Subtraction (-)"
echo "3. Multiplication (*)"
echo "4. Division (/)"
read ch
case $ch in
  1)
  result=$(($a+$b))
  ;;
  2)
  result=$(($a-$b))
  ;;
  3)
  result=$(($a*$b))
  ;;
  4)
  result=$(($a/$b))
  ;;
esac
echo "Result of the operation is:  $result"
