all: HelloAssembly.exe

HelloAssembly.obj: HelloAssembly.asm
	ml /c /coff HelloAssembly.asm
	
HelloAssembly.exe: HelloAssembly.obj
	link /DEBUG:NONE /subsystem:windows /map /merge:.rdata=.text /merge:.data=.text /align:16 HelloAssembly.obj
	
clean:
	del *.exe *.obj *.ilk *.pdb *.map
