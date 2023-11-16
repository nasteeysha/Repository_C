#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE="bytes.txt"
echo "" > log.txt

for var in -e
do
    for var2 in 'numb' 'FBI' 'Money' '^do' 'do^' 'so'
    do
        for var3 in -i -v -c -l -n -h -s -iv -in -ic -il -is -vc -vl -vn -vh -vs -ivn -inc -inl -ins -vnc -vnl -vnh -vns
        do
            TEST1="$var $var2 $var3 $TEST_FILE"
            echo "$TEST1"
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( COUNTER_SUCCESS++ ))
                echo " \033[36mSUCCESS: $COUNTER_SUCCESS\033[0m"
            else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
                echo "\033[31mFAIL: $COUNTER_FAIL\033[0m"
            fi
            rm s21_grep.txt grep.txt
                        
        done
    done
done

for var in -e
do
    for var2 in 'numb' 'FBI' 'Money' '^do' 'do^' 'so'
    do
        for var3 in -i -v -c -l -n
        do
            TEST1="$var $var2 $var3 $TEST_FILE"
            echo "$TEST1"
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( COUNTER_SUCCESS++ ))
                echo " \033[36mSUCCESS: $COUNTER_SUCCESS\033[0m"
            else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
                echo "\033[31mFAIL: $COUNTER_FAIL\033[0m"
            fi
            rm s21_grep.txt grep.txt
                        
        done
    done
done


for var in -e
do
    for var2 in 'numb' 'FBI' 'Money' '^do' 'do^' 'so'
    do
        for var3 in -i -v -c -l -n
        do
                for var4 in -i -v -n
        do
                if [ $var != $var3 ] && [ $var3 != $var4 ] && [ $var != $var4 ]
        then
            TEST1="$var $var2 $var3 $var4 $TEST_FILE"
            echo "$TEST1"
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( COUNTER_SUCCESS++ ))
                echo " \033[36mSUCCESS: $COUNTER_SUCCESS\033[0m"
            else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
                echo " \033[31mFAIL: $COUNTER_FAIL\034[0m"
            fi
            rm s21_grep.txt grep.txt
            fi
            done
        done
    done
done


echo "\033[32mSUCCESS: $COUNTER_SUCCESS\033[0m"
echo "\033[31mFAIL: $COUNTER_FAIL\033[0m"
