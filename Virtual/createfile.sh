num=${PWD##*/}
mkdir bin
mkdir debug
mkdir src
mkdir data
touch Readme.md
for let in {A..Z}
do
    touch src/${let}${num}.cc
    mkdir data/${let}
    mkdir data/${let}/test
    mkdir data/${let}/ans
    mkdir data/${let}/out
    cont=1
    for file in {1..5..1}
    do
        touch data/${let}/test/test${file}
        touch data/${let}/ans/ans${file}
    done
    printf "#include<bits/stdc++.h>\n" >>  src/${let}${num}.cc
    printf "using namespace std;\n\n" >>  src/${let}${num}.cc
    printf "int main(){\n" >>  src/${let}${num}.cc
    printf "\tios::sync_with_stdio(0);\n" >>  src/${let}${num}.cc
    printf "\tcin.tie(0);\n\n\n" >>  src/${let}${num}.cc
    printf "}\n" >>  src/${let}${num}.cc
    if [[ ${let} = ${1} ]]; then
	exit 1
    fi
done
