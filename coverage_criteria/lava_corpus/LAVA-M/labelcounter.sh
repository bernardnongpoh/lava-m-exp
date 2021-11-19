#!/bin/bash

TESTDIR="./out_src"

for f in ${TESTDIR}/*.c
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

