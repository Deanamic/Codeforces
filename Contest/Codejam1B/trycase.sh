for let in "${@}"
do

    cont=1
    sh ./compile.sh ${let}
    touch ./caseout/${let}test.out
    rm ./caseout/${let}test.out
    touch ./caseout/${let}test.out
    for file in ./data/${let}testcases/*
    do
        echo ${let}${file##*/}
        printf "test case ${cont}\n\n" >> ./caseout/${let}test.out
        bin/${let}.out < ${file} >> ./caseout/${let}test.out
        printf "*****\n" >> ./caseout/${let}test.out
        ((cont++))
    done
done
