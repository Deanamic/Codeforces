num=${PWD##*/}

touch Readme.md
printf "Codeforces XXX Round YYY Div Z\n" >> Readme.md
printf "[Contest Link](http://codeforces.com/contest/XXX)\n" >> Readme.md
printf "[Editorial Link](http://codeforces.com/blog/entry/)\n\n" >> Readme.md

printf "Atcoder XXX Contest YYY\n" >> Readme.md
printf "[Contest Link](http://XXXYYY.contest.atcoder.jp/)\n" >> Readme.md
printf "[Editorial Link](https://atcoder.jp/img/XXXYYY/editorial.pdf)\n\n" >> Readme.md

for let in {A..Z}
do
  mkdir ${let}
  touch ${let}/${let}${num}.cc
  touch ${let}/Debug.txt
  echo - [ ] Problem ${let} >> Readme.md
  printf "\n" >> Readme.md
  printf "#include<bits/stdc++.h>\nusing namespace std;\n\nint main(){\n\tios::sync_with_stdio(0);\n\tcin.tie(0);\n\n}\n" >> ${let}/${let}${num}.cc
  if [[ ${let} = ${1} ]]; then
    exit 1
  fi
done
