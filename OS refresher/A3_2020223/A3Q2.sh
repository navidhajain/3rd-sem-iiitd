#! /bin/bash

add() {    
    ans=0
    for (( i=1; $i<$#; i++))
    do
    let ans=$ans+${arr[i]} 
    done
    echo $ans    
}

sub() {
    arr=($@)
    ans=${arr[1]}
    for (( i=2; $i<$#; i++))
    do
    let ans=$ans-${arr[i]} 
    done
    echo $ans
}

div() {
    arr=($@)
    ans=${arr[1]}
    for (( i=2; $i<$#; i++))
    do
    let ans=$ans/${arr[i]} 
    done
    echo $ans
}

exp() {
    arr=($@)
    n=$(($#-1))
    ans=${arr[$n]}
    ((n--))
    while [ $n -ge 1 ]
    do
        let ans=ans**${arr[n]}
        ((n--))
    done
    echo $ans
}

mul() {
    arr=($@)
    ans=1
    for (( i=1; $i<$#; i++))
    do
    let ans=$ans*${arr[i]} 
    done
    echo $ans
}

args=("$@")
arr=($@)

if [ $1 == "add" ]
then 
    add "${args[@]}"

elif [ $1 == "sub" ]
then 
    sub "${args[@]}"

elif [ $1 == "div" ]
then
    div "${args[@]}"

elif [ $1 == "exp" ]
then
    exp "${args[@]}"

elif [ $1 == "mul" ]
then
    mul "${args[@]}"
else
    echo "Incorrect code entered"
fi