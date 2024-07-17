#!/bin/bash
all_pass=1
gcc zuma.c -o zuma
for i in {1..5}; do
  echo "第 $i 次测试："
  ./datamaker
  ./zuma
  diff random_case.out myans.out > diff.txt
  if [ $? -eq 0 ]; then
    echo "PASS"
  else
    echo "NO PASS"
    echo "Difference at:"
    cat diff.txt
    all_pass=0  
  fi
  echo "" 
  rm diff.txt 
done

if [ $all_pass -eq 1 ]; then
  echo "Pass All Testcase Congratulation!"
else
  echo "Still Wrong,Try Again!"
fi