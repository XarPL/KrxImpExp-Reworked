#n
# This inserts a block's body if the block is empty

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

# Insert a block's body if the block is empty
s/\([^_]\)INDENT\([^\n]*\)\n\([^\n]*\)END_INDENT/\1INDENT\2\nNone\n\3END_INDENT/g

# Print everything
p}
