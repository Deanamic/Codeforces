num=${PWD##*/}
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if g++ ${1}/${1}${num}.cc -DLOCAL -O2 -o ${1}/${1}.out 2> ${1}/Debug.txt; then
    echo "Problem ${1}${GREEN} compiled succesfully${NC}";
    exit 0;
else echo "Problem ${1}${RED} didn't compile${NC}";
    exit 1;
fi
