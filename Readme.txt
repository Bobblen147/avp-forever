This is a small update to Barry Duncan (sirlemonhead)'s Avpx source code update for Aliens versus Predator Gold Edition.
http://homepage.eircom.net/~duncandsl/avp/

It is based off of the conversion from Subversion to Github as part of the avp-forever project by Dreamer
https://github.com/dreamer/avp-forever

The project has been updated to compile with Visual Studio Community 2022.

Note that this is a learning project for a novice c++ developer. As such pull requests that add amazing/complicated new features can't be merged as I cannot review them. I suggest making your own fork if you wish to work with the codebase.


New features

Optionally start Marine levels with pistol
Reload key (currently replaces Flashback Weapon key, mapped to R) (enhanced version of implementation from Cancer Black mod https://github.com/shole/AvP-CancerBlack/tree/df80b44ca7d1e97c6c310d847b1a10172bac0533)


The project has the following prerequisites:

The legacy DirectX SDK
currently available here but Microsoft often change these things
https://www.microsoft.com/en-gb/download/details.aspx?id=6812

If you only want to play the game rather than build it then the legacy DirectX runtime should do
https://www.microsoft.com/en-gb/download/details.aspx?id=8109

libogg and libvorbis
https://www.xiph.org/
I compiled libogg-1.3.2 and libvorbis-1.3.7

libbinkdec and libsmackerdec
available from sirlemonhead's website
http://homepage.eircom.net/~duncandsl/avp/

pthreads-win32
https://www.sourceware.org/pthreads-win32/
I used the latest version 2.9.1
WARNING - I encountered this error when building with pthreads and ended up going with the solution of commenting out the timespec definition in pthread.cpp
https://github.com/coapp-packages/pthreads/issues/1

OpenAL-soft
https://www.openal-soft.org/
I used the latest version


Installing

The most reliable way is to first use the automated installer from
http://homepage.eircom.net/~duncandsl/avp/
To do a full install of AvPx.

Then only copy over the newly compiled files you need
AvPx.exe (or Debug_AvPx.exe for a debug build)
enet.dll
libogg.dll
libvorbis.dll
libvorbisfile.dll

you can continue using the existing OpenAL32.dll, pthreadVC2.dll, libbinkdec.dll and libsmackerdec.dll from the automatic installer without issue.



Known (pre-existing) bugs

-Starry sky is drawn in front of the scenery if the scenery is sufficiently distant! (see Stranded)
-EAX reverb / echo levels are way to high (at least on my non surround sound setup)
-Walls seem to be a bit stickier than gold edition (easier to snag them)?