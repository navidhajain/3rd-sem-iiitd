#!/bin/env bash
date="$1"
IFS=- read dd mm yyyy <<< "$date"
flag="true"
if [[ $mm = @("01"|"03"|"05"|"07"|"08"|"10"|"12") ]]
then
    if [ $dd -gt 31 ] || [ $dd -le 0]
    then
    flag="false"
    fi
elif [[ $mm = @("04"|"06"|"09"|"11") ]]  
then
    if [ $dd -gt 30 ] || [ $dd -le 0 ]
    then
    flag="false"
    fi
elif [ $mm == "02" ]
then
    if [ $dd -le 0 ]
    then 
    flag="false"
    elif [ $(($yyyy%4)) -ne 0 ] && [ $dd -gt 28 ]
    then 
    flag="false"
    elif [ $(($yyyy%4)) -eq 0 ] && [ $dd -gt 29 ]
    then
    flag="false"
    fi
else
flag="true"
fi

if [ $flag == "false" ]
then
echo "invalid date"
else
cal $mm $yyyy
fi