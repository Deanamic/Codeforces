num=${PWD##*/}
for let in ${@}
do
    g++ bin/${let}${num}.cc -o bin/${let}.out 2> debug/${let}${num}.txt
done
