num=${PWD##*/}
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
for let in ${@}
do
    if g++ src/${let}${num}.cc -o -DLOCAL -O2 bin/${let}.out 2> debug/${let}${num}.txt; then
        echo "Problem ${let}${GREEN} compiled succesfully${NC}";
    else echo "Problem ${let}${RED} didn't compile${NC}";
    fi

done
