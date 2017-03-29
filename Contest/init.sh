mkdir ${1}
cp ./*.sh ./${1}
cd ${1}
rm init.sh
sh ./createfile.sh
rm createfile.sh
