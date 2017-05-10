num=${PWD##*/}
for let in ${@}
do
    g++ src/${let}${num}.cc -o bin/${let}.out 2> debug/${let}${num}.txt -DLOCAL_MACHINE
done
