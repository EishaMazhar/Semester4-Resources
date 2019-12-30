#Eisha
#17k3730
#sec C


read -p "Enter name of File1 : " f1
read -p "Enter name of f2 : " f2
if [ -f $f1]
then
    echo "$FILE exists."
    if [ -r $f1 ]
    then
        echo "$FILE allows reading."
        if [ -f $f2 ]
        then 
            echo "$f2 exists"
            read -p "Do you want to overwrite $f2 ? (Y/N)" n 
            if [[ $n = 'y' || $n = 'Y' ]]
            then
                cat $f1 > $f2
                echo "$f1 is copied into $f2"
                exit 0
            else
                echo "Exiting Script without copying"
                exit 1

            fi
        else
            echo "$f2 does not exists"
            cat $f1 > $f2
            echo "$FILE is copied into $f2"
            exit 0
        fi

    else
        echo "$FILE does not allow reading. Please Set Permissions"
        exit 1
    fi

    # sed stands for stream editor
   
else
    echo "File $f1 does not exist in current directory."
fi