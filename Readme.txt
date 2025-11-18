This is a small update to Barry Duncan (sirlemonhead)'s Avpx source code update for Aliens versus Predator Gold Edition.
http://homepage.eircom.net/~duncandsl/avp/

It is based off of the conversion from Subversion to Github as part of the avp-forever project by Dreamer
https://github.com/dreamer/avp-forever

The goal of the project is to add additional customisation and quality of life features to the single player experience without changing any of the actual gameplay. This is intended to be an enhancement of Avp Gold, not a total conversion.

The mod can be installed into a retail copy of avp gold or a steam/gog classic 2000 install. Only the data is required, the mod uses its own EXE. Multiplayer is sadly not supported but skirmish very much is.

Note that this is a learning project for a novice c++ developer. As such pull requests that add amazing/complicated new features can't be merged as I cannot review them. I suggest making your own fork if you wish to work with the codebase.

Source code can be found here
https://github.com/Bobblen147/avp-forever/tree/other/avp-source-code-update


Features marked as "config file toggle" can be enabled/disabled from the config file found here:
documents\My Games\Aliens versus Predator\AliensVsPredator.cfg

Marine Weapons
-Start marine levels with any combination of weapons (including none at all) "config file toggle"
-Make marine cudgel selectable with key 0 even if you have ammo for other weapons "config file toggle"
-Marine weapon reload any time (default key R)
-Marine weapon jamming can be disabled "config file toggle"

Predator Weapons
-Override map specific predator inventory and start with any combination of weapons
to enable this, first set PredatorWeaponsOverride=true in the config file "config file toggle"
-Predator weapons can now be collected as pickups (use key cards 11,12,13,14,15,16 in the editor to place them), pred weapon pickups will glow white when using pred tech vision
-Predator previous vision mode key (default R)
-Predator tracking weapons (disc, shoulder cannon) can have their tracking enabled/disabled (default key T)
-Predator can charge wrist blades indefinitely

Skirmish Enhancements
-Alien now playable in skirmish mode, tail attack can now target other aliens
-All enemy types now supported in skirmish mode, both as placed enemies and spawned in using debug mode
-TAB high score table now includes kill counts for all enemy types
-All single player triggers now work in skirmish
-Water effects (waterfall, rain, water pools) are still loaded if a single player map is moved to the Custom folder to play as a skirmish
-EXPERIMENTAL - Predator generators added. Enable PredatorGenerators in config file then
place a marine generator in your map and spawn unarmed, molotov or flamer civilians "config file toggle"
-included a sample skirmish map "Stranded_Preds", to demonstrate these features (remember to enable PredatorGenerators in the config file first)

General Gameplay
-TurnSpeedAdjust config option disables half mouse movement speed when walking (feature added by sirlemonhead) "config file toggle"
-Debug Mode can be enabled from the config file (as well as using the shortcut like normal) "config file toggle"
-all bot types are force loaded automatically when you use debug mode (don't need -lampcrtx anymore)
-Add a cheat unlock target in the Alien bonus mission Invasion to unlock the Terror cheat mode. (previously only accessibly by hacking your profile)
-Impossible Mission difficulty level no longer requires a cheat mode to select. Unlocking a level on director's cut will unlock impossible mission too.
-Bonus levels can now be played on any difficulty level instead of forcing Realistic
-Cheat modes can now be played on any appropriate map, marine fall damage is disabled for the Free Fall cheat to make it (a bit) fairer
-Predator HUD now shows the extra ticks of health and field charge that were previously hidden, can be toggled with PredatorHUDShowExtraTicks "config file toggle"

NPC Changes
-Added sentry gun, facehugger and alien queen bot spawn commands (type SENTRYGUN, FACEHUGGER or QUEENBOT in debug mode)
-The Queen has modified AI so she will target hostile NPCs as well as the player (EXPERIMENTAL)
-Added additional Predator bot subtypes that Rebellion left unused (PREDOBOT 2,3,4 or 5 in debug mode)
-Can enable/disable AI attacking a player of the same species. "config file toggle"
-Can force sentry guns to target a human player "config file toggle"
-Added a TougherNPCs config file toggle which makes marines fire on sight & almost never miss. It also gives every pred NPC a speargun and a rapid fire 
shoulder cannon, and facehuggers now move silently for an extra challenge. "config file toggle"

Campaign Mode
-Starting a game in Campaign Mode from the main menu will allow you to play all a species' single player missions consecutively 
-A campaign can also be started from the Cheat Modes menu, allowing you to play a whole campaign with a cheat
-Campaigns can be played with health/armour/weapons retained or reset at the start of each level by setting CampaignRetainPlayerStats in the config file. "config file toggle"
-The default setting is that weapons/armour/health are retained 
-Saves are supported in campaign mode. If you load a save after starting a new campaign, you will continue the campaign from the loaded level. 
-Any save can be loaded this way, it doesn't have to be a save you made in campaign mode.

Custom Single Player Map
-A new menu allows you to load any map in your Custom folder as a single player map
-Some single player maps are supplied with custom graphics which will display when you select them
-Saving is supported for custom single player maps (with the same rules as saving the normal game)

New Debug Console Commands
-ENEMYCOUNT debug command adds a live enemy counter to the top left of the screen (including both placed and generated enemies) that decreases as they are killed
-PICKUPCOUNT debug command adds a live pickup counter to the top left of the screen (includes marine weapons, health, armour and pred field charge)
-SENTRYGUN, FACEHUGGER, QUEENBOT, PREDOBOT 2,3,4 or 5. New bot spawns (see Gameplay section above)
-DIFFICULTY debug command shows the current difficulty as a number (0=training,1=realistic,2=directors cut,3=impossible)
-SHOWHEALTH debug command shows your current health and armour (in fixed point and converted to a readable value)
-MORPH_ALIEN, MORPH_MARINE and MORPH_PREDATOR change species in game in skirmish mode
-FLYMODE, OBSERVER, SHOWMODULE, SHOWCOORDS, PAINTBALL debug commands to aid custom map making (see custom map section below)

Custom map making
-Fly mode / no clip mode can be enabled in the console by typing FLYMODE then F6 anytime during play to toggle.
-Observer mode can be enabled in the console by typing OBSERVER (no longer needs debug EXE)
-typing SHOWMODULE will show which module the player is in (no longer needs debug EXE)
-typing SHOWCOORDS will show the game coordinates of the player (no longer needs debug EXE)
-typing PAINTBALL will enable decal placement mode, see the mod tools documentation for how to use it (no longer needs debug EXE)
-The unused mirror flag is now a 'no collision' flag and can be used to make false walls

Other
-Enable/disable EAX reverb effects from config
-Added config file option to disable bilinear filtering
-Added config file option to skip the copyright and intro logo videos
-Can now enable the following features to get the game to act more like the original 1999 release
	AvP99TitleScreen: restores the starfield title screen, original avp logo and intro music (acquire IntroSound.smk and add to new FMVsOld folder)
	Avp99FMVs: will play the original US actor FMVs instead of the gold edition ones (grab them from moddb and add to new FMVsOld folder)
	DisableSkeeterPistols: cannot pickup skeeter or pistol weapons, specialists of this type disabled in multiplayer
-The original Avp 99 shotgun sound has also been restored for NPCs that use shotguns. In Avp Gold / Classic they reused the pistol sound effect.

Bug fixes
-Partially fixed NPC heavy weapons drop sound repeating bug (needs 60fps or less)
-Work around bad bilinear filtering by slightly altering a couple of textures (thanks Olde)
-Fixed incorrect sound playing in custom maps if correct sound is missing (also fixes broken skirmish pickup sound)
-Single player AI alien triggers now work in skirmish (aliens don't stay dormant)
-Fudged hud scaling to look better at 1920x1080 (still broken on ultrawide / UHD resolutions)
-Starry sky now correctly renders behind the scenery and can be seen through windows
-Particle effects / alien vision auras can now be seen through windows
-All placed decals (blood spatter etc) are now visible
-Background music properly cycles through tracks / cd player console commands work

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

avpx only
-Starry sky is drawn in front of the scenery if the scenery is sufficiently distant (eg Stranded)*
-Can't see starry sky through a window (eg tyrargo, orbital)* 
-Can't see particles/coronas/auras through windows & in mirrors (eg derelict start, temple labs, escape)*
-Animated lava texture in Fury 161 (& Earthbound animated tunnel lights / Vaults predalien sphere) are broken
-Vertical movement for tracking weapons is broken if looking too high/low (eg waterfall pred, use shoulder cannon on marine below at the start)
-Tapping the mouse to fire multiple shots is broken (try firing single shots with marine pistol, keyboard is fine, it's just the mouse)
-Coronas are occasionally drawn in front of the HUD and very thin walls
-Some placed decals are missing (Pred waterfall, there should be a big puddle of blood at the start, not just spatter)*
-Stranded cliff textures have an outline around the transparent section (bad bilinear filtering)*
-Walls seem to be a bit stickier than gold edition (much easier to snag them)? May be related to high FPS?
-In skirmish/multiplayer, the wrong sound is played when destroying armour/lighter weapon pickups*
-Wireframe debug mode doesn't work at all
-Motionblur and Triptastic cheat modes do not have the blurring effect
-Only one cd track is played (always looping) per level instead of looping through all 5, (also CD console commands not hooked up)*
-EAX reverb / echo levels are way too high on non surround sound setups.*

avp gold & avpx
-Getting hit by a xenoborg sometimes breaks the graphics completely, resulting in glitching and a black screen
-When killing an NPC marine with a heavy weapon, the weapon drop sound sometimes rapidly repeats* (fast processor bug?)
-Collisions with NPCs (and NPC vs NPC collisions) can occasionally cause crashes, also you shouldn't really be able to fling NPCs around by pushing them (fast processor bug?)


