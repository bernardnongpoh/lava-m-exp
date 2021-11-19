#!/bin/bash
#./script.sh base64|md5sum|uniq|who
# Labelling Without Removing Function Side Effect

./cannotate $1/coreutils-8.24-lava-safe/src/$1.c  --crit="ABS,AOR,COR,ROR,MCC" -o out_src/$1_labeled.c -- -I $1/coreutils-8.24-lava-safe/lib/  -I /usr/local/lib/clang/13.0.0/include/ -I $1/build/lib/ -I $1/build/src/

echo "Labeled file: out_src/$1_labeled.c"

./func-side-effect $1/coreutils-8.24-lava-safe/src/$1.c -o $1/coreutils-8.24-lava-safe/src/$1_normalized.c -- -I $1/coreutils-8.24-lava-safe/lib/  -I /usr/local/lib/clang/13.0.0/include/ -I $1/build/lib/ -I $1/build/src/

echo "Normalized file: $1/coreutils-8.24-lava-safe/src/$1_normalized.c"

./cannotate $1/coreutils-8.24-lava-safe/src/$1_normalized.c  --crit="ABS,AOR,COR,ROR,MCC" -o out_src/$1_nomalized_labeled.c -f cov_file -- -I $1/coreutils-8.24-lava-safe/lib/  -I /usr/local/lib/clang/13.0.0/include/ -I $1/build/lib/ -I $1/build/src/

echo "Normalized Labeled file: out_src/$1_nomalized_labeled.c"

#Count labels

for f in out_src/$1_*.c
do
    echo "----- ${f} -----"
    echo "MCC: "
    grep "MCC Label" $f | wc -l
    echo "ABS: "
    grep "ABS Label" $f | wc -l
    echo "AOR: "
    grep "AOR Label" $f | wc -l
    echo "COR: "
    grep "COR Label" $f | wc -l
    echo "ROR: "
    grep "ROR Label" $f | wc -l
    echo "-----------------"
done




