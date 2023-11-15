#!/bin/bash

# Generate AUTHORS file based on Git history

# Get the list of contributors from Git log
git log --format='%aN <%aE>' | sort -u > AUTHORS

# Print a message indicating success
echo "AUTHORS file generated successfully."

