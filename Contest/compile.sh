num=${PWD##*/}
for let in ${@}
do
    if g++ src/${let}${num}.cc -o bin/${let}.out 2> debug/${let}${num}.txt; then
        echo "${let}${num} compiled succesfully";
    else echo "${let}${num} didn't compile";
    fi

done
