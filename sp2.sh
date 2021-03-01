#! /bin/bash

echo "Программа создания образа"
echo " "
echo "Разработчик: Герасимов Антон"
echo " "

while true
do
echo "Введите путь к каталогу (путь к папке, с которой создается образ): "
read path
if [ -d $path ]
then
echo "Ваша директория $path"
else
echo "Нет такой директории"
break
fi

echo "Введите имя будущего образа диска (без .iso)"
read name
if ! [ -e "$name".iso ]
	then
	genisoimage -o $name.iso $path
	echo "Образ создан с именем $name"
		else
			genisoimage -o "$name-"`date +"%d-%m-%Y.%H:%M:%S"`"".iso $path
			echo "К имени вашего образа добавлена дата $name-"`date +"%d-%m-%Y.%H:%M:%S"`""
		fi

#/home/puntuntukh/TiMP5

while true
do
	echo "Начать заново? (y/n)"
	read yn
	if [[ $yn == "y" ]]
	then
		break
	elif [[ $yn == "n" ]]
	then

		exit
	fi
done
done
