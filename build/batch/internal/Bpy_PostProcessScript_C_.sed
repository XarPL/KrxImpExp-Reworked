# This script processes the INDENT and END_INDENT words
# by inserting tabulation

# If the pattern space contains END_INDENT
# then remove a single tab from the hold space
/END_INDENT/{
x
s/\t\(.*\)/\1/
x
s/END_INDENT[ \t]*//
}

# Prepend the pattern space with the hold space (containing tabs)
H
g
s/\n//

# Keep only leading tabs in the hold space
x
s/^\(\t*\).*$/\1/
x

# If the pattern space contains INDENT
# then prepend the hold space with a single tab
/INDENT/{
x
s/\(.*\)/\t\1/
x
s/[ \t]*INDENT//
}
