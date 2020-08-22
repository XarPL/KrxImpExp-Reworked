-------------------------------------------------------------------------------
-- Name:        KrxGMaxExtender.ms
-- Purpose:     A MAXScript file providing an interface to use functions
--              implemented in the "KrxGMaxExtender.dll" library
-- Author:      Vitaly Baranov
-- Created:     January 14, 2009
-- Licence:     GNU General Public License
-------------------------------------------------------------------------------

-------------------------------
-- Helper functions          --
-------------------------------

-- Get result from extender dll
function _GetLongFromExtenderDll = 
(
  resf = FOpen ((getDir #maxroot) + "KrxExtender.res") "rb"
  if(resf == undefined) then
    return undefined
  n = ReadLong resf
  FClose resf
  deleteFile ((getDir #maxroot) + "KrxExtender.res")
  return n
)

-- Replaces special characters with escape sequences
-- This function in inverse for the "execute" function,
-- for any string the following equation is identical:
-- execute(_Stringize(s)) == s
function _Stringize str =
(
  rstr = "\""
  for i = 1 to str.count do
  (
    ch = str[i]
    if ch == "\"" then
      ch = "\\\""
    if ch == "\n" then
      ch = "\\n"
    if ch == "\r" then
      ch = "\\r"
    else if ch == "\t" then
      ch = "\\t"
    else if ch == "\*" then
      ch = "\\\*"
    else if ch == "\?" then
      ch = "\\\?"
    else if ch == "\\" then
      ch = "\\\\"
    else if ch == "\%" then
      ch = "\\\%"
    rstr = rstr + ch
  )
  rstr = rstr + "\""
  return rstr
)

-- Count commands and clear Listener window periodically
function _AdvanceCommandCounter =
(
  global _commandCounter
  if _commandCounter == 1024 then
  (
    clearListener()
    _commandCounter = 0
  )
  else if _commandCounter == undefined then
  (
    _commandCounter = 0
  )
  _commandCounter = _commandCounter + 1
)
	

-------------------------------
-- Running external programs --
-------------------------------

-- Execute an external program
function _DosCommand cmdline = 
(
  _AdvanceCommandCounter()
  scmdline = _Stringize cmdline
  format "DOSCommand %\n" scmdline
  return _GetLongFromExtenderDll()
)


-------------------------------
-- Writing to binary files   --
-------------------------------

-- Open a file for writing in binary mode. 
-- The second parameter (mode) must be equal to "wb".
-- The function will return an integer value
-- that is a handle of an open file or undefined if failed.
function _FOpen filename mode = 
(
  _AdvanceCommandCounter()
  sfilename = _Stringize filename
  smode = _Stringize mode
  format "FOpen % %\n" sfilename smode
  return _GetLongFromExtenderDll()
)

-- Close file.
function _FClose handle =
(
  _AdvanceCommandCounter()
  format "FClose %\n" handle
)

-- Returns the current file pointer position.
function _FTell handle = 
(
  _AdvanceCommandCounter()
  format "FTell %\n" handle
  return _GetLongFromExtenderDll()
)

-- Move the file pointer to the specified location
function _FSeek handle offset origin = 
(
  _AdvanceCommandCounter()
  format "FSeek % % %\n" handle offset origin
)

-- Write an integer to file as one byte.
function _WriteByte handle i sgn =
(
  _AdvanceCommandCounter()
  format "WriteByte % % %\n" handle i sgn
  true
)

-- Write an integer to file as two bytes.
function _WriteShort handle i sgn =
(
  _AdvanceCommandCounter()
  format "WriteShort % % %\n" handle i sgn
  true
)

-- Write an integer to file as four bytes.
function _WriteLong handle i sgn =
(
  _AdvanceCommandCounter()
  format "WriteLong % % %\n" handle i sgn
  true
)

-- Write a float to file as four bytes.
function _WriteFloat handle f =
(
  _AdvanceCommandCounter()
  format "WriteFloat % %\n" handle f
  true
)

-- Write a string with terminating zero to a file.
function _WriteString handle str =
(
  _AdvanceCommandCounter()
  sstr = _Stringize str
  format "WriteString % %\n" handle sstr
  true
)



-------------------------------
-- Writing to text files     --
-------------------------------

-- Open a file for writing in text mode. 
-- The function will return an integer value
-- that is a handle of an open file or undefined if failed.
function _createFile filename = 
(
  _AdvanceCommandCounter()
  sfilename = _Stringize filename
  format "createFile %\n" sfilename
  return _GetLongFromExtenderDll()
)

-- Open an existing file for append output.
-- The second parameter must be equal to "a" or "at".
-- The function will return an integer value
-- that is a handle of an open file or undefined if failed.
function _openFile filename mode = 
(
  _AdvanceCommandCounter()
  sfilename = _Stringize filename
  smode = _Stringize mode
  format "openFile % %\n" sfilename smode
  return _GetLongFromExtenderDll()
)

-- Close file.
function _close handle =
(
  _AdvanceCommandCounter()
  format "close %\n" handle
)

-- Returns the current file pointer position.
function _filePos handle = 
(
  _AdvanceCommandCounter()
  format "filePos %\n" handle
  return _GetLongFromExtenderDll()
)

-- Move the file pointer to the specified location
function _seek handle = 
(
  _AdvanceCommandCounter()
  format "seek %\n" handle offset
)

-- Write a string to file
function _format str _to: = 
(
  _AdvanceCommandCounter()
  sstr = _stringize str
  format "format % to:%\n" sstr _to
  true
)


------------
-- Checks --
------------

-- Check if this the "KrxGMaxExtender.dll" library loaded
function _IsKrxGMaxExtenderDllLoaded =
(
  global g_dllLoaded
  if(g_dllLoaded == undefined) then
  (
    r = _DosCommand "ver"
    g_dllLoaded = (r != undefined)
  )
  return g_dllLoaded
)
