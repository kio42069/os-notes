#!/bin/bash

# Prompt the user for the password
read -s -p "Enter your Git password: " password
echo

# Run the Git commands
git add .
git commit -m "updates"
echo $password | git push

# Clear the password variable for security
unset password

