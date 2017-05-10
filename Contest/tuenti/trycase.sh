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
        bin/${let}.out < ${file} >> ./caseout/${let}test.out
        ((cont++))
    done
done
