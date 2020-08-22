#n
# This script removes exceeded empty lines

# Store any line in the hold space
H

# Remove the first newline from the first line
1{
x
s/^\n//
x
}

# For the last line
${
# Copy all file contents back to the pattern space
g

# Remove exceeded empty lines
te
:e
s/\n[ \t]*\n[ \t]*\n/\n\n/
s/:[ \t]*\n[ \t]*\n/:\n/
te

# Print everything
p}
