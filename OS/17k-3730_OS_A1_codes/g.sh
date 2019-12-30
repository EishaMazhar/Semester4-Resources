#Eisha
#17k-3730
#sec C

echo -e "\nAll files in current directory : \n"
for file in *.*
do 
    echo -e "\nname : $file"
    if [ -r $file ]
    then
        echo "$file has read permission."
    else
        echo "#file doesn't have read permission."
    fi #if ended
    if [-w $file ]
    then
        echo "$file has WRITE permission."
    else
        echo "#file does NOT have WRITE permission."
    fi
    if [ -x $file ]
    then
        echo "$file has execute permission."
    else
        echo "#file doesn't have permission to execute."
    fi


done