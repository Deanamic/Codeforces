GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

for let in "${@}"
do
    echo "PROBLEM ${let}"
    cont=1
    zsh ./compile.sh ${let}
    DIR=./data/${let}
    while [ -s ${DIR}/test/test${cont} ]
    do
        file=test${cont}
        echo "Running test ${cont}"
        bin/${let}.out < ${DIR}/test/${file} > ${DIR}/out/out${cont}
        if [ -s ${DIR}/ans/ans${cont} ]; then
            cmp -s ${DIR}/ans/ans${cont} ${DIR}/out/out${cont} || echo "TEST ${cont}:${RED} WRONG ANSWER ${NC}"
            cmp -s ${DIR}/ans/ans${cont} ${DIR}/out/out${cont} && echo "TEST ${cont}:${GREEN} ACCEPTED ${NC}"
        fi
        ((cont++))
    done
done
