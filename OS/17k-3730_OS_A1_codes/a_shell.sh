#Eisha
#17k-3730
#sec C


read -p "Enter your Mail : " user
read -s -p "Enter your Password : " pw
echo -e "\nMails\n"
curl -u $user:$pw --silent "https://mail.google.com/mail/feed/atom" | grep -oPm1 "(?<=<title>)[^<]+" | sed '1d'