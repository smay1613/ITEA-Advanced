#!/bin/bash
function sameContent3(){
  local path=$1
  echo "147896325" >> "$path"
}
function sameContent2(){
  local path=$1
  echo "987654321" >> "$path"
}
function sameContent1(){
  local path=$1
  echo "123456789" >> "$path"
}
function randomContent(){
  local path=$1
  local randCounter=0
  for ((randCounter=0; randCounter<20; randCounter++ ))
  do
    echo "$(($RANDOM%10))" >> "$path"
  done
}
function createFiles(){
  local funcPath=$1
  local counter=0
  while [ $counter -le $numberOfFiles ]
  do
    touch "$funcPath/test$counter$funcLevel.txt"
    case $(($RANDOM%4)) in
        0)
        randomContent "$funcPath/test$counter.txt"
        ((statisticOfrandomContent++))
        ;;
        1)
        sameContent1 "$funcPath/test$counter.txt"
        ((statisticOfsameContent1++))
        ;;
        2)
        sameContent2 "$funcPath/test$counter.txt"
        ((statisticOfsameContent2++))
        ;;
        3)
        sameContent3 "$funcPath/test$counter.txt"
        ((statisticOfsameContent3++))
        ;;
    esac
    ((counter++))
  done
}
function createDirectories {
  local funcPath=$1
  local dirCounter=0
    while [ $dirCounter -le $numberOfDirectories ]
    do
        mkdir "$funcPath/test$dirCounter"
        createFiles "$funcPath/test$dirCounter"
        ((dirCounter++))
    done
}
statisticOfrandomContent=0
statisticOfsameContent1=0
statisticOfsameContent2=0
statisticOfsameContent3=0
echo "Enter test directory path:"
dirpath=0
read dirpath
echo "Enter number of directoryes in each folder:"
numberOfDirectories=0
read numberOfDirectories
echo "Enter number of files in each folder:"
numberOfFiles=0
read numberOfFiles
mkdir $dirpath"/bashTestFolder"
dirpath=$dirpath"/bashTestFolder"
createFiles "$dirpath"
createDirectories "$dirpath"
for ((Count=0;$Count <= $numberOfDirectories;Count++))
do
createDirectories "$dirpath/test$Count"
done
echo "Statistic:"
echo "Same content1: $statisticOfsameContent1"
echo "Same content2: $statisticOfsameContent2"
echo "Same content3: $statisticOfsameContent3"
echo "Random content: $statisticOfrandomContent"