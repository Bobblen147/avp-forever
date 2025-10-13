/* Patrick 5/6/97 -------------------------------------------------------------
  AvP Project sound header
  ----------------------------------------------------------------------------*/
#ifndef PSNDPROJ_H
#define PSNDPROJ_H

#include "equipment.h"

/* Andy 12/6/97 --------------------------------------------------------------
  Some background sound defines
----------------------------------------------------------------------------*/
#define BACKGROUND_VOLUME 80
#define BACKGROUND_ATTENUATION 5
#define ZONE_WIDTH_SHIFT 15    // Size of the sound zones (log 2)

#define ZONE_WIDTH 1<<ZONE_WIDTH_SHIFT

/* Patrick 5/6/97 -------------------------------------------------------------
  Enumeration of all the sounds that may be loaded/used in the game. Each
  of these corresponds to a data slot in the GameSounds[] array, and to the Id
  number specified for each sound in the sound data file
  ----------------------------------------------------------------------------*/
//all wavs loaded from common.ffl
typedef enum soundindex
{
	SID_PRED_LAUNCHER,  //TRUE launcher.wav (plasmacaster)
	SID_PRED_FRISBEE,	//TRUE wil_pred_disc_throw.wav (disc)
	SID_PRED_PISTOL,	//TRUE Pred_pistol_fire.wav (pred pistol)
	SID_PRED_SNARL,		//FALSE
	SID_PRED_SCREAM1,	//FALSE
	SID_PRED_LASER,		//TRUE wil_pred_speargun_fire.wav (speargun)
	SID_PULSE_START,	//TRUE pulsesrt.wav (pulse rifle)
	SID_PULSE_LOOP,		//TRUE pulsemid.wav (pulse rifle)
	SID_PULSE_END,		//TRUE pulseend.wav (pulse rifle)
	SID_LIFT_START,		//FALSE

	SID_LIFT_LOOP,		//FALSE
	SID_LIFT_END,		//FALSE
	SID_SWITCH1,		//FALSE
	SID_SWITCH2,		//FALSE
	SID_ALIEN_SCREAM,	//FALSE
	SID_SWIPE,			//FALSE
	SID_SWISH,			//FALSE
	SID_TAIL,			//FALSE
	SID_VISION_ON,		//TRUE visionon.wav (pred vision)
	SID_VISION_LOOP,	//FALSE

	SID_SWIPE2,			//FALSE
	SID_SWIPE3,			//FALSE
	SID_SWIPE4,			//FALSE
	SID_PRED_HISS,		//FALSE
	SID_HIT_FLESH,		//FALSE
	SID_ALIEN_HIT,		//FALSE
	SID_ALIEN_KILL,		//TRUE alienkil.wav (queen death)
	SID_ALIEN_HISS,		//FALSE
	SID_ALIEN_HISS1,	//FALSE
	SID_FIRE,			//TRUE fire1.wav (on fire)

	SID_BUGDIE1,		//FALSE
	SID_BUGDIE2,		//FALSE
	SID_BUGDIE3,		//FALSE
	SID_MARINE_DEATH1,	//FALSE
	SID_MARINE_DEATH2,	//FALSE
	SID_PRED_LOUDROAR,	//FALSE
	SID_MARINE_HIT, 	//FALSE
	SID_ALIEN_HIT2,		//FALSE
	SID_PICKUP,			//TRUE Ed_MarinePickUp_Health.wav (health pickup)
	SID_RICOCH1,		//TRUE wil_bullet_ricochet_01.wav (bullets hitting walls)

	SID_RICOCH2,		//TRUE wil_bullet_ricochet_02.wav (bullets hitting walls)
	SID_RICOCH3,		//TRUE wil_bullet_ricochet_03.wav (bullets hitting walls)
	SID_RICOCH4,		//TRUE wil_bullet_ricochet_04.wav (bullets hitting walls)
	SID_ARMSTART,		//TRUE ArmStart.wav (xenoborg attack)
	SID_ARMMID,			//TRUE ArmMid.wav (xenoborg attack)
	SID_ARMEND,			//TRUE ArmEnd.wav (xenoborg attack)
	SID_PRED_SHORTROAR,	//FALSE
	SID_PRED_SLASH,		//FALSE
	SID_RIP,			//FALSE
	SID_PRED_NEWROAR, 	//TRUE predroar01.wav (medicomp stab)

	SID_SPLASH1,		//TRUE splash1.wav (water)
	SID_SPLASH2,		//TRUE splash2.wav (water)
	SID_SPLASH3,		//TRUE splash3.wav (water)
	SID_SPLASH4,		//TRUE splash4.wav (water)
	SID_POWERUP,		//TRUE PowerUp.wav (xenoborg activate)
	SID_POWERDN,		//TRUE PowerDn.wav (xenoborg deactivate)
	SID_TELETEXT,		//TRUE teletext.wav (console text print)
	SID_TRACKER_CLICK,	//TRUE martracker.wav (motion tracker)
	SID_TRACKER_WHEEP,	//TRUE trackwep.wav (motion tracker)
	SID_ACID_SPRAY,		//TRUE acdspray.wav (facehugger hurt, commented out?)

	SID_DOORSTART,      //TRUE doorstat.wav (door)
	SID_DOORMID,		//TRUE doormid.wav (door)
	SID_DOOREND,		//TRUE doorend.wav (door)
	SID_BORGON,			//TRUE BorgOn.wav (xenoborg activate?)
	SID_SPARKS,			//TRUE Ed_Common_Sparks.wav (xenoborg damaged, broken lights etc)
	SID_STOMP,			//TRUE Stomp.wav (Xenoborg)
	SID_LOADMOVE,		//TRUE loadmove.wav (Xenoborg)
	SID_FHUG_ATTACKLOOP,//TRUE faceattk.wav (facehugger)
	SID_FHUG_MOVE,		//TRUE facemve.wav (facehugger)
	SID_NOAMMO,			//TRUE noammo.wav (Smartgun click, sentrygun slick)

	SID_LONGLOAD,		//FALSE
	SID_NADELOAD,		//FALSE
	SID_NADEFIRE,		//TRUE Ed_PulseGrenade_Launch.wav (pulse grenade fire)
	SID_NADEEXPLODE,	//TRUE Ed_PulseGrenade_Explode.wav (pulse grenade hit, barrels explode)
	SID_SHOTGUN_OLD,	//FALSE (formerly unused SID_SHRTLOAD, now shotgun_old.wav - used by avpx for avp 99 shotgun sound)
	SID_INCIN_START,	//TRUE incinsrt.wav (flamethrower)
	SID_INCIN_LOOP,		//TRUE incinmid.wav (flamethrower)
	SID_INCIN_END,		//TRUE incinend.wav (flamethrower)
	SID_ROCKFIRE,		//TRUE Ed_Grenade_Launch.wav (Grenade launcher fire)
	SID_SHOTGUN,		//TRUE shotgun2.wav (pistols & civie shotgun in gold edition)

	SID_SMART1,			//TRUE Ed_smart_fire_1.wav (Smartgun fire)
	SID_SMART2,			//TRUE Ed_smart_fire_2.wav (Smartgun fire)
	SID_SMART3,			//TRUE Ed_smart_fire_3.wav (Smartgun fire)
	SID_SENTRY_GUN,		//TRUE Ed_SentryGun_Fire_Mid_Lp.wav (sentry gun fire)
	SID_SENTRY_END,		//TRUE Ed_SentryGun_Fire_End.wav (sentry gun fire)
	SID_NICE_EXPLOSION, //TRUE Ed_sadar_explosion01.wav (SADARS, big bangs)
	SID_EXPLOSION,		//TRUE explo1.wav (breaking non flammable objects)
	SID_MINIGUN_END,	//TRUE Ed_minigun_end.wav (minigun fire)
	SID_MINIGUN_LOOP,	//TRUE Ed_minigun_fire.wav (minigun fire)
	SID_SPEARGUN_HITTING_WALL, //TRUE wil_pred_speargun_hit_wall.wav (speargun hits wall)

	SID_FRAG_RICOCHETS,      //90  //TRUE
	SID_PLASMABOLT_DISSIPATE, //TRUE
	SID_PLASMABOLT_HIT, //TRUE
	SID_BLOOD_SPLASH, //FALSE
	SID_ALIEN_JAW_ATTACK,//TRUE
	SID_TRACKER_WHEEP_HIGH, //TRUE
	SID_TRACKER_WHEEP_LOW, //TRUE
	SID_PULSE_RIFLE_FIRING_EMPTY, //TRUE
	SID_THROW_FLARE, //TRUE
	SID_BODY_BEING_HACKED_UP_0, //TRUE

	SID_BODY_BEING_HACKED_UP_1, //100 //TRUE
	SID_BODY_BEING_HACKED_UP_2,//TRUE
	SID_BODY_BEING_HACKED_UP_3,//TRUE
	SID_BODY_BEING_HACKED_UP_4,//TRUE
	SID_CONSOLE_ACTIVATES,//TRUE
	SID_CONSOLE_DEACTIVATES,//TRUE
	SID_CONSOLE_MARINEMESSAGE,//TRUE
	SID_CONSOLE_ALIENMESSAGE,//TRUE
	SID_CONSOLE_PREDATORMESSAGE,//TRUE
	SID_MINIGUN_READY, //FALSE! WIL_MINIGUN_READY used instead.

	SID_MINIGUN_EMPTY, //110 //TRUE
	SID_SMART_MODESWITCH,//TRUE
	SID_GRENADE_BOUNCE,//TRUE
	SID_BURNING_FLARE,//TRUE
	SID_FLAMETHROWER_PILOT_LIGHT,//Not yet...
	SID_MARINE_JUMP_START,//FALSE
	SID_MARINE_JUMP_END,//Not yet!
	SID_MARINE_PICKUP_WEAPON,//TRUE
	SID_MARINE_PICKUP_AMMO,	 //TRUE
	SID_MARINE_PICKUP_ARMOUR,//TRUE

	SID_PREDATOR_PICKUP_FIELDCHARGE,	//TRUE wil_pickup_predator_fieldcharge.wav (field charge pickup)
	SID_PREDATOR_PICKUP_WEAPON,			//FALSE (added pickup1.wav in avpx enhanced to use this)
	SID_PREDATOR_CLOAKING_ACTIVE,		//TRUE Pred_vision_active_lp.wav (pred vision background hum)
	SID_PREDATOR_CLOAKING_DAMAGED,		//FALSE
	SID_PREDATOR_SPEARGUN_EMPTY,		//FALSE
	SID_PREDATOR_PLASMACASTER_TARGET_FOUND,//TRUE
	SID_PREDATOR_PLASMACASTER_TARGET_LOCKED,//TRUE
	SID_PREDATOR_PLASMACASTER_TARGET_LOST,//TRUE
	SID_PREDATOR_PLASMACASTER_CHARGING,//TRUE
	SID_PREDATOR_PLASMACASTER_EMPTY,// In code but never happens

	SID_PREDATOR_DISK_TARGET_LOCKED, //130 //TRUE
	SID_PREDATOR_DISK_FLYING,//TRUE
	SID_PREDATOR_DISK_HITTING_TARGET,//TRUE
	SID_PREDATOR_DISK_HITTING_WALL,//TRUE
	SID_PREDATOR_DISK_BEING_CAUGHT,//TRUE
	SID_PREDATOR_DISK_RECOVERED,//TRUE
	SID_PREDATOR_VOCAL_SNARL_1,//FALSE
	SID_PREDATOR_VOCAL_SNARL_2,//FALSE
	SID_ALIEN_TAILUNFURL, //FALSE
	SID_ALIEN_TAUNT_1, //FALSE

	SID_ALIEN_TAUNT_2,	// 140 //FALSE
	SID_SENTRYGUN_LOCK, //Not at the moment
	SID_SENTRYGUN_SHUTDOWN, //TRUE
	SID_WIL_MINIGUN_READY,	//TRUE
	SID_SADAR_FIRE,//TRUE
	SID_DISC_STICKSINWALL,//TRUE
	SID_PREDATOR_PLASMACASTER_REDTRIANGLES,//TRUE
	SID_WIL_PRED_PISTOL_EXPLOSION,//TRUE
	SID_PROX_GRENADE_READYTOBLOW,//TRUE
	SID_PROX_GRENADE_ACTIVE,	 //TRUE

	SID_MARINE_JUMP_START_2, //150 //FALSE
	SID_MARINE_JUMP_START_3,//FALSE
	SID_MARINE_JUMP_START_4,//FALSE
	SID_ED_GRENADE_EXPLOSION,//TRUE
	SID_ED_GRENADE_PROXEXPLOSION,//TRUE
	SID_ED_MOLOTOV_EXPLOSION,//TRUE
	SID_ED_LARGEWEAPONDROP,//TRUE
	SID_MENUS_SELECT_ITEM,//TRUE
	SID_MENUS_CHANGE_ITEM,//TRUE
	SID_PRED_JUMP_START_1,//FALSE
	SID_PRED_JUMP_START_2,//FALSE
	SID_PRED_JUMP_START_3,//FALSE
	SID_PRED_CLOAKON,//TRUE
	SID_PRED_CLOAKOFF,//TRUE
	SID_PRED_ZOOM_IN,
	SID_PRED_ZOOM_OUT,

	SID_MARINE_SMALLLANDING,
	SID_PRED_SMALLLANDING,
	SID_ED_FACEHUGGERSLAP,
	SID_LIGHT_FLICKER_ON, //TRUE
	SID_ED_SENTRYTURN01,
	SID_PULSE_SWIPE01,
	SID_PULSE_SWIPE02,
	SID_PULSE_SWIPE03,
	SID_PULSE_SWIPE04,
	SID_ED_JETPACK_START,
	SID_ED_JETPACK_MID,
	SID_ED_JETPACK_END,
	SID_GRAPPLE_HIT_WALL,
	SID_GRAPPLE_THROW,
	SID_SENTRYGUNDEST,
	SID_ED_ELEC_DEATH,
	SID_IMAGE,
	SID_IMAGE_OFF,
	SID_PRED_CLOAK_DAMAGE,
	SID_ED_SKEETERLAUNCH,
	SID_ED_SKEETERPLASMAFIRE,
	SID_ED_SKEETERDISC_SPIN,
	SID_ED_SKEETERDISC_HITWALL,
	SID_ED_SKEETERCHARGE,
	SID_INTROWOOSH,

	SID_STARTOF_LOADSLOTS,
	SID_UNUSED_125,
	SID_UNUSED_126,
	SID_UNUSED_127,
	SID_UNUSED_128,
	SID_UNUSED_129,
	SID_UNUSED_130,
	SID_UNUSED_131,
	SID_UNUSED_132,
	SID_UNUSED_133,
	SID_UNUSED_134,
	SID_UNUSED_135,
	SID_UNUSED_136,
	SID_UNUSED_137,
	SID_UNUSED_138,
	SID_UNUSED_139,
	SID_UNUSED_140,
	SID_UNUSED_141,
	SID_UNUSED_142,
	SID_UNUSED_143,
	SID_UNUSED_144,
	SID_UNUSED_145,
	SID_UNUSED_146,
	SID_UNUSED_147,
	SID_UNUSED_148,
	SID_UNUSED_149,
	SID_UNUSED_150,
	SID_UNUSED_151,
	SID_UNUSED_152,
	SID_UNUSED_153,
	SID_UNUSED_154,
	SID_UNUSED_155,
	SID_UNUSED_156,
	SID_UNUSED_157,
	SID_UNUSED_158,
	SID_UNUSED_159,
	SID_UNUSED_160,
	SID_UNUSED_161,
	SID_UNUSED_162,
	SID_UNUSED_163,
	SID_UNUSED_164,
	SID_UNUSED_165,
	SID_UNUSED_166,
	SID_UNUSED_167,
	SID_UNUSED_168,
	SID_UNUSED_169,
	SID_UNUSED_170,
	SID_UNUSED_171,
	SID_UNUSED_172,
	SID_UNUSED_173,
	SID_UNUSED_174,
	SID_UNUSED_175,
	SID_UNUSED_176,
	SID_UNUSED_177,
	SID_UNUSED_178,
	SID_UNUSED_179,
	SID_UNUSED_180,
	SID_UNUSED_181,
	SID_UNUSED_182,
	SID_UNUSED_183,
	SID_UNUSED_184,
	SID_UNUSED_185,
	SID_UNUSED_186,
	SID_UNUSED_187,
	SID_UNUSED_188,
	SID_UNUSED_189,
	SID_UNUSED_190,
	SID_UNUSED_191,
	SID_UNUSED_192,
	SID_UNUSED_193,
	SID_UNUSED_194,
	SID_UNUSED_195,
	SID_UNUSED_196,
	SID_UNUSED_197,
	SID_UNUSED_198,
	SID_UNUSED_199,
	SID_UNUSED_200,
	SID_UNUSED_201,
	SID_UNUSED_202,
	SID_UNUSED_203,
	SID_UNUSED_204,
	SID_UNUSED_205,
	SID_UNUSED_206,
	SID_UNUSED_207,
	SID_UNUSED_208,
	SID_UNUSED_209,
	SID_UNUSED_210,
	SID_UNUSED_211,
	SID_UNUSED_212,
	SID_UNUSED_213,
	SID_UNUSED_214,
	SID_UNUSED_215,
	SID_UNUSED_216,
	SID_UNUSED_217,
	SID_UNUSED_218,
	SID_UNUSED_219,
	SID_UNUSED_220,
	SID_UNUSED_221,
	SID_UNUSED_222,
	SID_UNUSED_223,
	SID_UNUSED_224,
	SID_UNUSED_225,
	SID_UNUSED_226,
	SID_UNUSED_227,
	SID_UNUSED_228,
	SID_UNUSED_229,
	SID_UNUSED_230,
	SID_UNUSED_231,
	SID_UNUSED_232,
	SID_UNUSED_233,
	SID_UNUSED_234,
	SID_UNUSED_235,
	SID_UNUSED_236,
	SID_UNUSED_237,
	SID_UNUSED_238,
	SID_UNUSED_239,

	SID_ENDOF_LOADSLOTS=800,

	SID_MAXIMUM, /* SPECIAL: used to trap out of bounds values */
	SID_NOSOUND  /* SPECIAL: used to specify a null sound */
}SOUNDINDEX;

/* Patrick 5/6/97 -------------------------------------------------------------
  Project level sound function prototypes
  ----------------------------------------------------------------------------*/
extern void DoPlayerSounds(void);
extern void MakeRicochetSound(VECTORCH *position);
extern void DoBackgroundSound(void);
extern void StopBackgroundSound(void);
extern void PlayAlienSwipeSound(void);
extern void PlayAlienTailSound(void);
extern void PlayPredSlashSound(void);
extern void PlayCudgelSound(void);

extern void MenuChangeSound(void);
extern void MenuSelectSound(void);
extern void MenuNotAvailableSound(int *handlePtr);
extern void MenuSliderBarSound(int *handlePtr);
void PlayWeaponClickingNoise(enum WEAPON_ID weaponIDNumber);


/* Patrick 5/6/97 -------------------------------------------------------------
  Sound data loader
  ----------------------------------------------------------------------------*/
/*Moved to psndproj since it now uses a project specific file to find the files -Richard */
extern void LoadSounds(char *soundDirectory);

//loads wav file locally or from network or from fast file as appropriate
extern int FindAndLoadWavFile(int soundNum, const char* wavFileName);

/* Patrick 10/6/97 -------------------------------------------------------------
  Enumeration of CDDA tracks
  ----------------------------------------------------------------------------*/
typedef enum cdtrackid
{
	CDTrack1 = 1,
  CDTrack2,
  CDTrack3,
  CDTrack4,
  CDTrack5,
  CDTrack6,
  CDTrack7,
  CDTrack8,
  CDTrack9,
  CDTrack10,
  CDTrack11,
  CDTrack12,
  CDTrack13,
  CDTrack14,
  CDTrack15,
  CDTrack16,
  CDTrack17,
  CDTrack18,
  CDTrack19,
  CDTrack20,
  CDTrack21,
  CDTrack22,
  CDTrack23,
  CDTrack24,
  CDTrack25,
  CDTrack26,
//  CDTrackMax, /* SPECIAL: used to trap out of bounds values */
} CDTRACKID;

extern int CDTrackMax; //bas maximum cd track on the actual number of tracks

#endif

