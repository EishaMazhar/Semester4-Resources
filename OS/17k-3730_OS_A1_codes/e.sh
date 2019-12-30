#Eisha
#17k-3730
#sec C

read -p "Enter string : " str
rev=$(echo $str | rev)
if [ $str = $rev ]
then
    echo "$string is palindrome"
else
    echo "$string is not palindrome"
fi