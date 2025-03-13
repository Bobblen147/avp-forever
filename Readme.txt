This is a small update to Barry Duncan (sirlemonhead)'s Avpx source code update for Aliens versus Predator Gold Edition.
http://homepage.eircom.net/~duncandsl/avp/

It is based off of the conversion from Subversion to Github as part of the avp-forever project by Dreamer
https://github.com/dreamer/avp-forever

The goal of the project is to add additional customisation and quality of life features without changing any of the actual gameplay. This is intended to be an enhancement of Avp Gold, not a total conversion.

Note that this is a learning project for a novice c++ developer. As such pull requests that add amazing/complicated new features can't be merged as I cannot review them. I suggest making your own fork if you wish to work with the codebase.


Most new features can be toggled from the config file found here:
documents\My Games\Aliens versus Predator\AliensVsPredator.cfg

Marine 
-Start marine levels with any combination of weapons (including none at all)
-Make marine cudgel selectable with key 0 even if you have ammo for other weapons
-Marine weapon reload any time (default key R)
-Marine weapon jamming can be disabled

Predator
-Override map specific predator inventory and start with any combination of weapons
to enable this, first set PredatorWeaponsOverride=true in the config file

-Predator weapons can now be collected as pickups (use key cards 11,12,13,14,15,16 in the editor to place them)
-Predator previous vision mode key (default R)
-Predator tracking weapons (disc, shoulder cannon) can have their tracking enabled/disabled (default key T)
-Added additional Predator bot types (try PREDOBOT 2,3,4 or 5 in debug mode!)

Gameplay
-Add a cheat unlock target in the Alien bonus mission Invasion to unlock the Terror cheat mode.
-Enable/disable half mouse movement speed when ducking (feature added by sirlemonhead but not included in their latest release)
-Added sentry gun bot spawn command (type SENTRYGUN in debug mode)
-Can enable/disable AI attacking a player of the same species.

Skirmish
-Alien now playable in skirmish mode, tail attack can now target other aliens
-All bot types can now be spawned in debug mode (including predators, sentry guns etc)

Other
-Enable/disable EAX reverb effects
-Temporarily removed the NPC Marine heavy weapon drop sound as it was buggy and would get stuck playing
-Work around a sound bug when breaking armour/light weapon pickups in skirmish by replacing an unused sound

The implementation for the reload and prev vision mode keys are heavily based on the implementation from the Cancer Black mod.
https://github.com/shole/AvP-CancerBlack/tree/df80b44ca7d1e97c6c310d847b1a10172bac0533)



Installing

The most reliable way is to first use the automated installer from
http://homepage.eircom.net/~duncandsl/avp/
To do a full install of AvPx. This will also take care of a number of prerequisites automatically.

Then only copy over the newly compiled files you need
AvPx.exe (or Debug_AvPx.exe for a debug build)
enet.dll
libogg.dll
libvorbis.dll
libvorbisfile.dll
libbinkdec.dll 
libsmackerdec.dll
language.txt (overwriting the existing file)
fastfile/Snd21.ffl (overwriting the existing file)

you can continue using the existing OpenAL32.dll & pthreadVC2.dll from the automatic installer without issue.


Building

The project has been updated to compile with Visual Studio Community 2022.
The project has the following additional prerequisites:

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


Known (pre-existing) bugs

-Starry sky is drawn in front of the scenery if the scenery is sufficiently distant! (see Stranded)
-Stranded cliff textures have an outline around the transparent section (bad bilinear filtering?)
-Animated lava texture in Fury 161 is broken
-In skirmish/multiplayer, the wrong sound is played when destroying armour/lighter weapon pickups
-When killing an NPC marine with a heavy weapon, the weapon drop sound repeats
-EAX reverb / echo levels are way to high on non surround sound setups.
-Walls seem to be a bit stickier than gold edition (easier to snag them). May be related to high FPS?