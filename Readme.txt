This is a small update to Barry Duncan (sirlemonhead)'s Avpx source code update for Aliens versus Predator Gold Edition.
http://homepage.eircom.net/~duncandsl/avp/

It is based off of the conversion from Subversion to Github as part of the avp-forever project by Dreamer
https://github.com/dreamer/avp-forever

The goal of the project is to add additional customisation and quality of life features to the single player experience without changing any of the actual gameplay. This is intended to be an enhancement of Avp Gold, not a total conversion.

Note that this is a learning project for a novice c++ developer. As such pull requests that add amazing/complicated new features can't be merged as I cannot review them. I suggest making your own fork if you wish to work with the codebase.

Source code can be found here
https://github.com/Bobblen147/avp-forever/tree/other/avp-source-code-update


Most new features can be toggled from the config file found here:
documents\My Games\Aliens versus Predator\AliensVsPredator.cfg

Marine Weapons
-Start marine levels with any combination of weapons (including none at all)
-Make marine cudgel selectable with key 0 even if you have ammo for other weapons
-Marine weapon reload any time (default key R)
-Marine weapon jamming can be disabled

Predator Weapons
-Override map specific predator inventory and start with any combination of weapons
to enable this, first set PredatorWeaponsOverride=true in the config file
-Predator weapons can now be collected as pickups (use key cards 11,12,13,14,15,16 in the editor to place them)
-Predator previous vision mode key (default R)
-Predator tracking weapons (disc, shoulder cannon) can have their tracking enabled/disabled (default key T)

Gameplay
-TurnSpeedAdjust config option disables half mouse movement speed when walking (feature added by sirlemonhead)
-all bot types are force loaded automatically when you use debug mode (don't need -lampcrtx anymore)
-Added sentry gun bot spawn command (type SENTRYGUN in debug mode)
-Added facehugger bot spawn command (type FACEHUGGER in debug mode)
-Added alien queen bot spawn command (type QUEENBOT in debug mode)
-Added additional Predator bot subtypes that Rebellion left unused (PREDOBOT 2,3,4 or 5 in debug mode)
-Can enable/disable AI attacking a player of the same species.
-Can force sentry guns to target a human player
-Add a cheat unlock target in the Alien bonus mission Invasion to unlock the Terror cheat mode. (previously only accessibly by hacking your profile)
-EXPERIMENTAL - ENEMYCOUNT debug command adds a live kill counter to the top left of the screen (including both placed and generated enemies)
-EXPERIMENTAL - PICKUPCOUNT debug command adds a live pickup counter to the top left of the screen (includes marine weapons, health, armour and pred field charge)

Skirmish
-Alien now playable in skirmish mode, tail attack can now target other aliens
-All enemy types now supported in skirmish mode, both as placed enemies and spawned in using debug mode
-TAB high score table now includes kill counts for all enemy types
-All single player triggers now work in skirmish
-EXPERIMENTAL - Predator generators added. Enable PredatorGenerators in config file then
place a marine generator in your map and spawn unarmed, molotov or flamer civilians 
-In game species change in debug mode (use MORPH_ALIEN, MORPH_MARINE and MORPH_PREDATOR)
-included a sample skirmish map "Stranded_Preds", to demonstrate these features (remember to enable PredatorGenerators in the config file first)

Custom map making
-Fly mode can be enabled in the console by typing FLYMODE then F6 anytime during play to toggle.
-Observer mode can be enabled in the console by typing OBSERVER (no longer needs debug EXE)
-typing SHOWMODULE will show which module the player is in (no longer needs debug EXE)
-The unused mirror flag is now a 'no collision' flag and can be used to make false walls
-Can play a custom single player level by adding it to the config and just starting a new game as the species you want.

Other
-Enable/disable EAX reverb effects from config
-Added config file option to disable bilinear filtering
-Added config file option to skip the copyright and intro logo videos

Bug fixes
-Partially fixed NPC heavy weapons drop sound repeating bug (needs 60fps or less)
-Work around bad bilinear filtering by slightly altering a couple of textures (thanks Olde)
-Fixed a sound bug when breaking armour/light weapon pickups in skirmish
-Fixed incorrect sound playing in custom maps if correct sound is missing
-Single player AI alien triggers now work in skirmish (aliens don't stay dormant)


Extra credits

The implementation for the reload and prev vision mode keys are heavily based on the implementation from the Cancer Black mod.
https://github.com/shole/AvP-CancerBlack/tree/df80b44ca7d1e97c6c310d847b1a10172bac0533)

Thanks to Olde for much testing, and the avp classic discord for suggestions and encouragement


Installing

Double click the installer to do a full install of AvPx Enhanced. This will also take care of a number of prerequisites automatically.

When the installer asks for a directory you should point it at your Aliens versus Predator folder. This can be a retail install of avp gold or steam/gog classic 2000.

The installer will place a new skirmish map into your avp_rifs/Custom folder called Stranded_Preds.
Don't forget if you want predators to spawn in this map instead of civilians, you must set PredatorGenerators=true in the config file

A default config file AliensVsPredator.cfg is provided and should be placed in
documents\My Games\Aliens versus Predator\ (or you can just let the game generate you one by playing it)

It is highly recommended if you have a high refresh rate monitor to use a 3rd party tool to lock the framerate to 59fps. There are big problems with the AI and physics if you go higher than this!


Building

The project has been updated to compile with Visual Studio Community 2022.
The project has the following additional prerequisites:

The legacy DirectX SDK
currently available here but Microsoft often change these things
https://www.microsoft.com/en-gb/download/details.aspx?id=6812

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


Known (pre-existing) avpx bugs
* means I've applied a fix or workaround in avpx enhanced

-Starry sky is drawn in front of the scenery if the scenery is sufficiently distant (see Stranded)
-Stranded cliff textures have an outline around the transparent section (bad bilinear filtering)*
-Animated lava texture in Fury 161 (& Earthbound animated lights / Vaults predalien sphere) are broken
-Getting hit by a xenoborg sometimes breaks the graphics completely
-Walls seem to be a bit stickier than gold edition (easier to snag them)? May be related to high FPS?
-In skirmish/multiplayer, the wrong sound is played when destroying armour/lighter weapon pickups*
-When killing an NPC marine with a heavy weapon, the weapon drop sound sometimes rapidly repeats*
-EAX reverb / echo levels are way too high on non surround sound setups.*
-Wireframe debug mode just does nothing
-Motionblur and Triptastic cheat modes do not have the blurring effect
-CDSTOP/PLAY in game commands not hooked up, only one cd track is played per level
