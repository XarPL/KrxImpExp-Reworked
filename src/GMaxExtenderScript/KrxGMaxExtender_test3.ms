clearListener()
format "\nWriting file in text mode...\n"
f = _createFile "C:\\test1.txt"
_format "The first" _to: f
_format " line." _to: f
_format "\n" _to:f
_format "The second line.\n" _to:f
_format "\tThe line with tab, \"quotes\", " _to: f
_format "and \\backslashes\\.\n" _to: f
_close f

format "\nAppending file in text mode...\n"
f = _openFile "C:\\test1.txt" "a"
_format "The appended line.\n" _to:f
_close f

format "\nReading file in text mode...\n"
f = openFile "C:\\test1.txt"
i = 1
while not eof f do
( 
  str = readLine f
  format "Line %>%\n" i str
  i = i + 1
)
