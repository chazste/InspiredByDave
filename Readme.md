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
So what is wrong with Hello Windows? My answer is either portability or appearance. While watching Dave type I saw the function LoadStringW appear on the screen. Now I would not code an API call with an explicit A or W suffix without a realy good reason and a comment to document the fact. Later after downloading Dave's code from pastebin and looking it over I realized that the code is inconsistant. Some API calls have the explicit W suffix and others don't. The program compiles fine with either setting (Project->Properities->Advanced->Character Set), but when compiled for multi-byte some things are "a little off". For example the Windows caption is a single character.

So what? I hear you saying. Why would anyone intentionally need to write a program in 2021 that targets the multi-byte version of the Windows API? I personally have not compiled a program that I wanted to run on Windows 9X in over 15 years.