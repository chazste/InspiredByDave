# Dave Who?
[Dave Plumber](https://en.wikipedia.org/wiki/David_Plummer_(programmer)) is a retired engineer from [Microsoft](https://www.microsoft.com) that is now working on becoming [YouTube](https://www.youtube.com/channel/UCNzszbnvQeFzObW0ghk0Ckw) famous. He posted a series of videos about tiny programs for Windows:
* [Hello Windows](https://www.youtube.com/watch?v=JlZe2JwrJqM&t=52s)
* [Hello Assembly](https://www.youtube.com/watch?v=b0zxIfJJLAY&t=2s)
* [Program in a QR code](https://www.youtube.com/watch?v=TS0y9roNH-s&t=1s)

# Who Else?
[Steve Gibson](https://www.grc.com/stevegibson.htm) is someone who is already Internet famous and a host of the [Security Now](https://twit.tv/shows/security-now) podcast. For the purpose of this repository though he is someone who gave a "Shout Out" to Dave and drew attention to these little programs. But maybe more importantly he is the author of [SIB](https://www.grc.com/smgassembly.htm) - Small Is Beautiful example Windows assembly program.

[Raymond Chen](https://channel9.msdn.com/Events/Speakers/raymond-chen#:~:text=Raymond%20Chen%20is%20a%20programmer,gives%20him%20the%20heebie%2Djeebies.) Is a Principal Engineer at [Microsoft](https://www.microsoft.com) and blogs about Windows programming (and other things) at [The Old New Thing](https://aka.ms/OldNewThing)
* As it relates to this project his [series](https://devblogs.microsoft.com/oldnewthing/20060727-04/?p=30333) on DLL imports and exports is quite informative. (Specifically this [one](https://devblogs.microsoft.com/oldnewthing/20060721-06/?p=30433))
* [This](https://devblogs.microsoft.com/oldnewthing/20060731-15/?p=30293) post also aludes to the reason that this repository exists at all.

# [Who am I](https://www.youtube.com/watch?v=rEi9wgbob-0)
[Chazste](https://github.com/chazste) Just a programmer that is old enough to have written a lot of assembly "back in the day" but never used a punched card. I really am old enough to have a grey beard and have read the first edition(s) of K&R, "Programming Windows" and "The C++ programming language"

# Why are we here?
I don't know about you, but I was intrigued by Dave's videos. But I saw a problem that I thought should be discussed. Why do we write in assembly anyway? The usual answer is code size and/or performance. But why don't we? Again the usual answer is programmer productivity and code maintance or understandability.

# Hello Windows
Dave used the new project wizard in Visual Stuiod (2019) to decant off the starting point for a simple "Hello World" Windows (Win32) program. He then proceeded to explain how it worked and modify it to actually BE "Hello World for Windows". The only problem was it did not generate a small binary, ultimatly one that fit in a QR code.

[HellowWindows.cpp]() is a real C++ program. It is written in a subset of C++ that should not cause any problems for a C programmer, but won't compile as C code without modification. This also has implications for the program's run-time. We get to have the whole C++ runtime and compiler support libraries. Also as a real Win32 desktop application this project contains a resource script (.rc file) that gets translated and appended to the resulting binary. These things make a program easier to write and help it conform to the user's expectations. But they come at a cost in executable size.

# Hello Windows 2010
For reference I have included a Hello Windows variant generated with Microsoft Visual Studio 2010. This version is very similar to the above except that it is written in the proper subset of C++ that will compile correctly as C as well. You can check it out as well in the solution.

# Hello Assembly
Dave was almost immediatly challanged to make the program smaller and even to make it fit in a QR code. So he reached for the ultimate tool, Assembly language. You will find Dave's code in the HelloAssembly project, crunched down to well under 4 KB as he describes in his video.

This is a very good exaple of writing a Win32 program in assembly. And understanding it is a worthwhile excersise. But what did we gain, and how was it accomplished? If you take a minute to read the code something should jump out at you. There is no algorythm. There is almost no logic. The program prepares parameters for functions, pushes them on the stack and calls the Windows Win32 API. That's it. It is all "boiler plate" code.

When I was in school we were taught that "C is like a high level assembly language." I'm not sure I understood what that meant at the time. But now I would still say that, and mean that if I know the combination of compiler, archetecture and ABI; I know what to expect the code to look like if I disassemble it. That implies (at least to me) that this progam can be written in C. So the question is, can this program be written equally small without resorting to Assembly?

# Hello C
The final project in this solution then is the C translation of Dave's assembly program. It should be a faithful one to one translation back to C, with the exception that I used a ?: operator instead of what appeared to be an if statement in the assembly version. Also I used a switch statement instead of the chained if in WndProc. Again this is natural C code and clues in the optimizer to what we are doing.

This code is simpler than the template versions from Visual Studio. There is no about box and associated logic (and resources). No menu. As a matter of fact just like the assebly vesion, no resouce script at all. This change alone saves approximatly 48 KB from the image size. Pretty good if you are trying to weigh in under 4 KB.

If you watch the video carefully you will see that all the size savings are performmed with the linker. Don't link in the resources, don't bring in the language run-time, define your own entry point, change the section alignment, and merge a couple of sections. With the program written in C we should be able to do all of the same optimizations on the linker command line, and get a similar result.

# Conclusion
On my computer HelloAssembly.exe is 2064 bytes long. HelloC.exe is only 2032 bytes long. That is with passing /Od (optimization disable) to the C compiler. Asking for size optimization cuts off more than 100 more bytes weighing in at 1920 bytes.

What if we turn the optimizer up to 11 on the Assembler? First off "we are the optimizer", so it would require some work. But there is room for improvement before you start to effect the readability of the code. For instance the DLL calls are done in the naive way Ramond describes. Getting rid of the forwarding stubs would save over a hundred bytes right off the bat. However a quick Google did not render a quick fix. Making the code look more like a ternary and a switch most likely could be done without really killing readability and would save a few bytes. Most of the other ideas I have could apply equally to the C code. Things like eliminating the duality of MainEntry and WinMain. 

# How to build
This solution was constructed using Microsoft Visual Studio 2019 (community edition) This version includes the compiler and assembler as well as the necessary includes and libraries. No need for the MASM SDK that Dave refers to for this one. The C/C++ programs should build for x86 and x64 (and ARM but I have not tested that) The assembly version is for 32-bit x86 only. 

I am including a Makefile in the directory for HelloC and HelloAssembly compatible with Microsoft nmake. Go to "Tools->Visual Studio Command Prompt" (You may need to change directories to the project) Then type nmake.

# What else?
I will accept Pull Requests for additonal compilers in the makefiles. Specifically Gcc, Watcom, lcc, clang and the "free" version of bcc32c (nee Borland)

My expectation is that this program is so simple that the compiler will make little difference.

I would also be interested in the smallest Rust version someone can come up with. I looked into this topic a year or two ago, and at that time the command line did not support droping enough of the run-time to get the final exe under 4 KB. Even if you can get it under 32 KB I would be willing to add it to the project. but my purpose here is to show that while knowing Assembly is a good thing, one should write in it only rarely. (Since the High Level Language tools are really good;)