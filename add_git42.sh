#!/bin/sh

if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
	echo "42_paris"
	pwd=$(pwd)
	cd ~/Downloads/42_paris
	git add -A && git commit -m "$(date) - $(pwd) update" && git push
	cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
	git add -A && git commit -m "$(date) - $(pwd) update" && git push
elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
	echo "Cursus_2023"
fi
