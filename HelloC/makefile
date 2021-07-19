all: HelloC.exe

HelloC.obj: HelloC.c
	cl /Od /c /Fa /GS- HelloC.c
	
HelloC.exe: HelloC.obj
	link /NODEFAULTLIB:LIBCMT.lib /ENTRY:MainEntry /DEBUG:NONE /subsystem:windows /map /merge:.rdata=.text /merge:.data=.text /align:16 HelloC.obj

clean:
	del *.exe *.obj *.ilk *.pdb *.map
