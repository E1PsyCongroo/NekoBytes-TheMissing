#!/bin/bash

all_pass=1
gcc sudoku.c -o sudoku

# 去除文件中每行末尾的空格
normalize_file() {
    local input_file=$1
    local output_file=$2
    awk '{$1=$1;print}' "$input_file" | tr -d '\r' > "$output_file"
}

# 定义测试用例
for i in {1..2}; do
  echo "Running test case $i:"

  # 运行学生程序并将输出重定向到学生输出文件
  ./sudoku "case$i.in" > output.txt

  # 规范化学生输出和期望输出
  normalize_file output.txt normalized_output.txt
  normalize_file "case$i.out" normalized_expected_output.txt

  # 比较学生输出与期望输出
  diff normalized_output.txt normalized_expected_output.txt > diff.txt
  if [ $? -eq 0 ]; then
    echo "PASS"
  else
    echo "FAIL"
    echo "Differences:"
    cat diff.txt
    all_pass=0  
  fi
  echo "" 
  rm diff.txt normalized_output.txt normalized_expected_output.txt
done

if [ $all_pass -eq 1 ]; then
  echo "All test cases passed. Congratulations!"
else
  echo "Some test cases failed. Please check the differences above."
fi




