clearListener()
format "\nWriting file in binary mode...\n"
f = _FOpen "C:\\test1.bin" "wb"
_WriteString f "String"
_WriteByte f 117
_WriteFloat f 345.78e-8
pos = _FTell f
_WriteShort f -1000
_WriteLong f 123456
_FSeek f pos #seek_set
_WriteShort f -2000
pos = _FTell f
_FClose f

format "\nReading file in binary mode...\n"
f = FOpen "C:\\test1.bin" "rb"
str = ReadString f
b = ReadByte f
flt = ReadFloat f
pos = FTell f
sh = ReadShort f
l = ReadLong f
FSeek f pos #seek_set
sh = ReadShort f
pos = FTell f
FClose f

