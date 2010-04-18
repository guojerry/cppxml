all : mp3parse.ax

OBJS=parser.obj puller.obj mp3parse.obj

mp3parse.ax : $(OBJS)
	link.exe @<<
	/NOLOGO
	/DLL /DEF:mp3parse.def /OUT:mp3parse.ax
	$(OBJS) strmbase.lib
	kernel32.lib user32.lib advapi32.lib oleaut32.lib 
	uuid.lib ole32.lib winmm.lib Quartz.lib 
	/release /stack:0x200000,0x200000 /entry:"DllEntryPoint@12" /OPT:NOREF
<<

.cpp.obj::
	cl.exe @<<
	/c /nologo /Gz /MD /W3 /O2 /Ob0 /TP /D "WIN32" /D "_WIN32"
	/D "_MT" /D "_DLL" /D _X86_=1 /D WINVER=0x0400 /D "NDEBUG"
	/D try=__try /D except=__except /D leave=__leave /D finally=__finally
	$< 
<<

parser.obj : parser.cpp parser.h puller.h
puller.obj : puller.cpp parser.h puller.h
mp3parse.obj : mp3parse.cpp mp3parse.h guidmp3p.h parser.h mp3.h puller.h

