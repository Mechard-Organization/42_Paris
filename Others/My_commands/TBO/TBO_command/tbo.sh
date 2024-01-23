#!/bin/bash

# The Biggest One is my own commands

function tbo {

    ######### VARIABLES GLOBALES #########

    local var_usr="mechard"

    ######### VARIABLES NIVEAU 1 #########

    local var_config=("-c" "-configuration")

    local var_github=("-g" "-github")

    local var_intra=("-i" "-intra")

    ######### VARIABLES NIVEAU 2 #########

    ## GITHUB && INTRA ##
    local var_update=("-u" "-update")
    local var_clone=("-cl" "-clone")
    local var_push=("-p" "-push")
    local var_add=("-a" "-add")
	local var_del=("-d" "-del" "-delete")
	local var_move=("-m" "-mv" "-move")

    ######### VARIABLES NIVEAU 3 #########

    ## UPDATE && CLONE && PUSH ##
    local var_all=("-a" "-all")
    local var_choose=("-c" "-choose")

    ######### AUTRES VARIABLES #########

    ## LOCAL ##
	source /home/mechard/.TBO/bin/path_tbo

	. $TBO_bin/verif_answer.sh
	. $TBO_bin/path_tbo
	. $TBO_bin/update_folder.sh
	. $TBO_bin/clone_folder.sh
	. $TBO_bin/delete_folder.sh

    ######### AVEC ARGUMENT #########
	if [[ $TBO_param ]]; then
		source "$TBO_param"
	else
		bash $TBO_config
	fi
    if [[ -z $1 || " ${var_config[@]} " =~ " $1 " ]]; then
        bash "$TBO_config"
    elif [[ " ${var_github[@]} " =~ " $1 " ]]; then
		if [[ ( "$path_folder_github" && "$path_folder_github" != "$(pwd)/" ) || " ${var_move[@]} " =~ " $2 " ]]; then
			move_to -g
		fi
        if [[ " ${var_update[@]} " =~ " $2 " ]]; then
			previous_location=$(pwd)
            if [[ " ${var_all[@]} " =~ " $3 " || -z "$3" ]]; then
                update_all_folders -g
            elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
                if [[ $4 ]]; then
					update_selected_folder -g $4
				else
					update_selected_folder -g
				fi
            fi
        elif [[ " ${var_clone[@]} " =~ " $2 " ]]; then
    		if [[ " ${var_all[@]} " =~ " $3 " ]]; then
        		if [[ -z $github_folder ]]; then
					echo "Aucun folder n'as ete enregistre ! Veuillez utiliser la commande tbo -g -cl -c !"
				else
        			clone_all_folders -g
				fi
    		elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
				if [[ $4 ]]; then
					clone_selected_folder -g $4
				else
					clone_selected_folder -g
				fi
			fi
		elif [[ " ${var_del[@]} " =~ " $2 " ]]; then
			if [[ " ${var_all[@]} " =~ " $3 " ]]; then
            	delete_all_folders -g
        	elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
				if [[ $4 ]]; then
					delete_selected_folder -g $4
				else
					delete_selected_folder -g
				fi
			fi
		else
            echo "\033[31mUne erreur est survenue !\033[0m"
			echo "Veuillez reessayer !"
        fi
    elif [[ " ${var_intra[@]} " =~ " $1 " ]]; then
		if [[ ( "$path_folder_intra" && "$path_folder_intra" != "$(pwd)/" ) || " ${var_move[@]} " =~ " $2 " ]]; then
        	if [[ " ${var_all[@]} " =~ " $2 " ]]; then
				move_to -i
			fi
		fi
		if [[ " ${var_update[@]} " =~ " $2 " ]]; then
			previous_location=$(pwd)
	        if [[ " ${var_all[@]} " =~ " $3 " || -z "$3" ]]; then
	           	update_all_folders -i
	    	elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
	        	if [[ $4 ]]; then
					update_selected_folder -i $4
				else
					update_selected_folder -i
				fi
	        fi
		elif [[ " ${var_clone[@]} " =~ " $2 " ]]; then
			if [[ " ${var_all[@]} " =~ " $3 " ]]; then
        		if [[ -z $github_folder ]]; then
					echo "Aucun folder n'as ete enregistre ! Veuillez utiliser la commande tbo -g -cl -c !"
				else
        			clone_all_folders -i
				fi
    		elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
				if [[ $4 ]]; then
					clone_selected_folder -i $4
				else
					clone_selected_folder -i
				fi
			fi
		elif [[ " ${var_del[@]} " =~ " $2 " ]]; then
			if [[ " ${var_all[@]} " =~ " $3 " ]]; then
            	delete_all_folders -i
        	elif [[ " ${var_choose[@]} " =~ " $3 " ]]; then
				if [[ $4 ]]; then
					delete_selected_folder -i $4
				else
					delete_selected_folder -i
				fi
			fi
		else
            echo "\033[31mUne erreur est survenue !\033[0m"
			echo "Veuillez reessayer !"
        fi
	###############ARGUMENT_INVALIDE###############
    else
        if [[ " ${var_move[@]} " != " $2 " ]]; then
        	echo -e "\033[31mThe command github needs a valid argument !\033[0m"
        	echo -e 'Check the manual of github for more informations'
		fi
    fi
	# if [[ $previous_location ]]; then
	# 	cd $previous_location
	# fi
}