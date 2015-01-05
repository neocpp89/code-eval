#!/bin/sh

fib() {
    if [ $1 -le 0 ]
    then
        return 0
    elif [ $1 -eq 1 ]
    then
        return 1
    else
        ONE=1
        TWO=2
        aa=$(($1 - $ONE))
        fib $aa
        r=$?
        bb=$(($aa - $ONE))
        fib $bb 
        s=$?
        p=$(( r + s ))
        echo $1 $aa $bb $r $s $p
        return $p
    fi
}

fibi () {
    if [ $1 -le 0 ]
    then
        echo 0
        return 0
    elif [ $1 -eq 1 ]
    then
        echo 1
        return 1
    else
        f1=0
        f2=1
        r=1
        for x in `seq 2 $1`;
        do { r=$(($f1+f2)); f1=$f2; f2=$r;}; done;
        echo $r
        return $r
    fi
}

count=0
while read line;
do
#    if [ $count -eq 0 ]
#    then
#        fibi $line
#        echo -n $?
#    else
#        fibi $line
#        echo -n "\n$?"
#    fi
    if [ -n "$line" ]
    then
        fibi $line
        #echo $?
        count=$((count + 1))
    fi
done < $1


