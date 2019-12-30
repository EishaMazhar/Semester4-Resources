#Eisha
#17k-3730
#sec C

if [$# -eq 0]
    then
        echo "No File Supplied-Give name of file to be renamed as arguments"
        exit 1
else
    temp=0
    args=("$@")
    while [[temp -lt $#]]
    do
        echo "File to be renamed ${args[temp]}"
        FILE=${args[temp]}
        if[-f $FILE]
        then
            echo "${args[temp]}exists."
            mv ${args[temp]} `echo ${args[temp]} | sed 's/\(.*\.\)sh/\1exe/'`
            # sed stands for stream editor
            echo "File renamed"
        else
            echo "File $FILE does not exist in current directory."
        fi
          ((temp=$temp+1))
    done
fi