#!/bin/bash
# Author: Chahat Deep Singh

# A simple script to run a set of articles from arxiv.com.
# The latest papers appears first in the list.
# You can search your own and add the URL in this code.

# Instructions: 
# Save arxiv.sh in some folder; Open terminal in that folder
# and run the following:

# sudo chmod u+x arxiv.sh
# echo "alias arxiv='bash arxiv.sh'" >> ~/.bashrc

# Open a new terminal and run 'arxiv'
# NOTE: Change the browser from google-chrome to firefox if needed.
#############################################################

# Comment one of the browser:
browser=google-chrome 
#browser=firefox

# Shell Color Defination:
RED='\033[0;31m'
NC='\033[0m' # No Color
GREEN='\033[0;32m'
CYAN='\033[1;36m'
YELLOW='\033[1;33m'

# Echo all arxiv indexes:
echo "Which recent papers do you wanna look for?"
printf "${RED}Note:${NC} Default Browser is ${RED}$browser${NC}!\n"
echo "Enter from one of the following:"
printf "${CYAN}1${NC}: ${YELLOW}Generative Adversarial Networks\n"
printf "${CYAN}2${NC}: ${YELLOW}Deep Learning\n"
printf "${CYAN}3${NC}: ${YELLOW}Quadrotor\n"
printf "${CYAN}4${NC}: ${YELLOW}Optical Flow\n"
printf "${CYAN}5${NC}: ${YELLOW}General Computer Vision\n"

printf "${NC}" # Set color to No color!

# Input the search index:
read -p 'Index: ' -n 1 -r

## Set the search variables here!!
# GAN:
if [[ $REPLY =~ ^[1]+$ ]] ; then
	index="http://arxiv.org:443/find/all/1/ti:+AND+Network+AND+Generative+Adversarial/0/1/0/2018/0/1";

# Deep Learing:
elif [[ $REPLY =~ ^[2]+$ ]] ; then
index="http://arxiv.org:443/find/grp_stat,grp_cs,grp_math,grp_physics/1/ti:+AND+Deep+Learning/0/1/0/2018/0/1";

# Quadrotor:
elif [[ $REPLY =~ ^[3]+$ ]] ; then
index="http://arxiv.org:443/find/grp_eess,grp_stat,grp_cs,grp_math,grp_physics/1/ti:+Quadrotor/0/1/0/2018/0/1";

# Optical Flow:
elif [[ $REPLY =~ ^[4]+$ ]] ; then
index="http://arxiv.org:443/find/grp_eess,grp_stat,grp_cs,grp_math,grp_physics/1/ti:+AND+Optical+Flow/0/1/0/2018/0/1";

# General Computer Vision:
elif [[ $REPLY =~ ^[5]+$ ]] ; then
index="https://arxiv.org/list/cs.CV/recent";

fi

# Open arxiv Link in the browser:
#printf "\n$index "
printf "\n${RED}Check your $browser${NC}\n"
$browser $index & exit
