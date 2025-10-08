#ifndef _player_h_
#define _player_h_

extern int Observer;

#endif

//save player stats at end of level to use on the next level
typedef struct player_campaign_save_block
{
	//behaviour block things
	PLAYER_WEAPON_DATA	WeaponSlot[MAX_NO_OF_WEAPON_SLOTS];

	enum WEAPON_SLOT	SelectedWeaponSlot;
	enum WEAPON_SLOT	SwapToWeaponSlot;
	enum WEAPON_SLOT	PreviouslySelectedWeaponSlot;

	int	Health;	 /* in 16.16 */
	int	Energy;	 /* in 16.16 */
	int	Armour;	 /* in 16.16 */
	int	FieldCharge;	 /* in 16.16 */

}PLAYER_CAMPAIGN_SAVE_BLOCK;