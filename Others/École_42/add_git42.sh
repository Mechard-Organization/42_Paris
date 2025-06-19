#!/bin/sh

pwd=$(pwd)

if [ "$1" = "-g" ] || [ ! "$1" ]; then
	if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
		echo "Push of 42_Paris folder and subfolders in progress !"

		# Push de 42_paris
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris
		echo "42_Paris"
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		if [ "$?" = "1" ]; then
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mNothing need to be pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		else
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mCursus_2023 was pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		fi

		# Push de Cursus_2023
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		echo "Cursus_2023"
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		if [ "$?" = "1" ]; then
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mNothing need to be pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		else
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mCursus_2023 was pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		fi

		# Push de Others
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris/Others
		echo "Others"
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		if [ "$?" = "1" ]; then
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mNothing need to be pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		else
			git push > /dev/null 2>&1
			if [ "$?" = "0" ]; then
				echo "\033[33mCursus_2023 was pushed !\033[0m"
			else
				echo "\033[31mAn error as occured !\033[0m"
			fi
		fi
		echo "--------------------------------------------------------------------------------------------------------"

		cd $pwd

	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
		echo "Push de Cursus_2023 !"

		# Push de Cursus_2023

		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd

	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Others")" ]; then
		echo "Push de Others !"

		# Push de Cursus_2023

		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd

	else
		echo "This command can only be used in 42_Paris and 42_Paris's repositories"
	fi
elif [ "$1" = "-p" ]; then
	echo "-p"
	if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
		echo "42_paris"
		cd ~/Downloads/42_paris
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
		echo "Cursus_2023"
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	fi
else
	echo "Usage: 42git { -g | -p }\n"
fi