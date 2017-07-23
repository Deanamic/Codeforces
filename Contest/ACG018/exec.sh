num=${PWD##*/}
if zsh ./compile.sh ${1}; then
  ./${1}/${1}.out
else
  exit 1;
fi
