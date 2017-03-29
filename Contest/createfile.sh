num=${PWD##*/}
mkdir bin
mkdir debug
mkdir caseout
mkdir src
mkdir data
for let in {A..E}
do
    touch src/${let}${num}.cc
    mkdir data/${let}testcases
    printf "#include<bits/stdc++.h>\n" >>  src/${let}${num}.cc
    printf "using namespace std;\n\n" >>  src/${let}${num}.cc
    printf "int main(){\n" >>  src/${let}${num}.cc
    printf "\tios::sync_with_stdio(0);\n" >>  src/${let}${num}.cc
    printf "\tcin.tie(0);\n\n\n" >>  src/${let}${num}.cc
    printf "}\n" >>  src/${let}${num}.cc
done
