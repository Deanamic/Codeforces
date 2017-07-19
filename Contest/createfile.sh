num=${PWD##*/}

touch Readme.md
for let in {A..Z}
do
  mkdir ${let}
  touch ${let}/${let}${num}.cc
  touch ${let}/Debug.txt
  echo - [ ] Problem ${let} >> Readme.md
  printf "#include<bits/stdc++.h>\nusing namespace std;\n\nint main(){\n\tios::sync_with_stdio(0);\n\tcin.tie(0);\n\n}\n" >> ${let}/${let}${num}.cc
  if [[ ${let} = ${1} ]]; then
    exit 1
  fi
done
