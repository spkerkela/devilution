// HEADER_GOES_HERE

#include "../types.h"

int itemactive[127];
int uitemflag;
int itemavail[127];
ItemStruct curruitem;
ItemGetRecordStruct itemrecord[127];
ItemStruct item[128];
char itemhold[3][3];
char byte_641234[28]; /* check if part of above */
int Item2Frm[35];
int UniqueItemFlag[128];
int numitems;
int gnNumGetRecords;

PLStruct PL_Prefix[84] = {
    {"Tin", IPL_TOHIT_CURSE, 6, 10, 3, PLT_WEAP | PLT_BOW | PLT_MISC, 0, 1, 0,
     0, 0, -3},
    {"Brass", IPL_TOHIT_CURSE, 1, 5, 1, PLT_WEAP | PLT_BOW | PLT_MISC, 0, 1, 0,
     0, 0, -2},
    {"Bronze", IPL_TOHIT, 1, 5, 1, PLT_WEAP | PLT_BOW | PLT_MISC, 0, 1, 1, 100,
     500, 2},
    {"Iron", IPL_TOHIT, 6, 10, 4, PLT_WEAP | PLT_BOW | PLT_MISC, 0, 1, 1, 600,
     1000, 3},
    {"Steel", IPL_TOHIT, 11, 15, 6, PLT_WEAP | PLT_BOW | PLT_MISC, 0, 1, 1,
     1100, 1500, 5},
    {"Silver", IPL_TOHIT, 16, 20, 9, PLT_WEAP | PLT_BOW | PLT_MISC, 16, 1, 1,
     1600, 2000, 7},
    {"Gold", IPL_TOHIT, 21, 30, 12, PLT_WEAP | PLT_BOW | PLT_MISC, 16, 1, 1,
     2100, 3000, 9},
    {"Platinum", IPL_TOHIT, 31, 40, 16, PLT_WEAP | PLT_BOW, 16, 1, 1, 3100,
     4000, 11},
    {"Mithril", IPL_TOHIT, 41, 60, 20, PLT_WEAP | PLT_BOW, 16, 1, 1, 4100, 6000,
     13},
    {"Meteoric", IPL_TOHIT, 61, 80, 23, PLT_WEAP | PLT_BOW, 0, 1, 1, 6100,
     10000, 15},
    {"Weird", IPL_TOHIT, 81, 100, 35, PLT_WEAP | PLT_BOW, 0, 1, 1, 10100, 14000,
     17},
    {"Strange", IPL_TOHIT, 101, 150, 60, PLT_WEAP | PLT_BOW, 0, 1, 1, 14100,
     20000, 20},
    {"Useless", IPL_DAMP_CURSE, 100, 100, 5, PLT_WEAP | PLT_BOW, 0, 1, 0, 0, 0,
     -8},
    {"Bent", IPL_DAMP_CURSE, 50, 75, 3, PLT_WEAP | PLT_BOW, 0, 1, 0, 0, 0, -4},
    {"Weak", IPL_DAMP_CURSE, 25, 45, 1, PLT_WEAP | PLT_BOW, 0, 1, 0, 0, 0, -3},
    {"Jagged", IPL_DAMP, 20, 35, 4, PLT_WEAP | PLT_BOW, 0, 1, 1, 250, 450, 3},
    {"Deadly", IPL_DAMP, 36, 50, 6, PLT_WEAP | PLT_BOW, 0, 1, 1, 500, 700, 4},
    {"Heavy", IPL_DAMP, 51, 65, 9, PLT_WEAP | PLT_BOW, 0, 1, 1, 750, 950, 5},
    {"Vicious", IPL_DAMP, 66, 80, 12, PLT_WEAP | PLT_BOW, 1, 1, 1, 1000, 1450,
     8},
    {"Brutal", IPL_DAMP, 81, 95, 16, PLT_WEAP | PLT_BOW, 0, 1, 1, 1500, 1950,
     10},
    {"Massive", IPL_DAMP, 96, 110, 20, PLT_WEAP | PLT_BOW, 0, 1, 1, 2000, 2450,
     13},
    {"Savage", IPL_DAMP, 111, 125, 23, PLT_WEAP | PLT_BOW, 0, 1, 1, 2500, 3000,
     15},
    {"Ruthless", IPL_DAMP, 126, 150, 35, PLT_WEAP | PLT_BOW, 0, 1, 1, 10100,
     15000, 17},
    {"Merciless", IPL_DAMP, 151, 175, 60, PLT_WEAP | PLT_BOW, 0, 1, 1, 15000,
     20000, 20},
    {"Clumsy", IPL_TOHIT_DAMP_CURSE, 50, 75, 5, PLT_WEAP | PLT_STAFF | PLT_BOW,
     0, 1, 0, 0, 0, -7},
    {"Dull", IPL_TOHIT_DAMP_CURSE, 25, 45, 1, PLT_WEAP | PLT_STAFF | PLT_BOW, 0,
     1, 0, 0, 0, -5},
    {"Sharp", IPL_TOHIT_DAMP, 20, 35, 1, PLT_WEAP | PLT_STAFF | PLT_BOW, 0, 1,
     0, 350, 950, 5},
    {"Fine", IPL_TOHIT_DAMP, 36, 50, 6, PLT_WEAP | PLT_STAFF | PLT_BOW, 0, 1, 1,
     1100, 1700, 7},
    {"Warrior's", IPL_TOHIT_DAMP, 51, 65, 10, PLT_WEAP | PLT_STAFF | PLT_BOW, 0,
     1, 1, 1850, 2450, 13},
    {"Soldier's", IPL_TOHIT_DAMP, 66, 80, 15, PLT_WEAP | PLT_STAFF, 0, 1, 1,
     2600, 3950, 17},
    {"Lord's", IPL_TOHIT_DAMP, 81, 95, 19, PLT_WEAP | PLT_STAFF, 0, 1, 1, 4100,
     5950, 21},
    {"Knight's", IPL_TOHIT_DAMP, 96, 110, 23, PLT_WEAP | PLT_STAFF, 0, 1, 1,
     6100, 8450, 26},
    {"Master's", IPL_TOHIT_DAMP, 111, 125, 28, PLT_WEAP | PLT_STAFF, 0, 1, 1,
     8600, 13000, 30},
    {"Champion's", IPL_TOHIT_DAMP, 126, 150, 40, PLT_WEAP | PLT_STAFF, 0, 1, 1,
     15200, 24000, 33},
    {"King's", IPL_TOHIT_DAMP, 151, 175, 28, PLT_WEAP | PLT_STAFF, 0, 1, 1,
     24100, 35000, 38},
    {"Vulnerable", IPL_ACP_CURSE, 51, 100, 3, PLT_ARMO | PLT_SHLD, 0, 1, 0, 0,
     0, -3},
    {"Rusted", IPL_ACP_CURSE, 25, 50, 1, PLT_ARMO | PLT_SHLD, 0, 1, 0, 0, 0,
     -2},
    {"Fine", IPL_ACP, 20, 30, 1, PLT_ARMO | PLT_SHLD, 0, 1, 1, 20, 100, 2},
    {"Strong", IPL_ACP, 31, 40, 3, PLT_ARMO | PLT_SHLD, 0, 1, 1, 120, 200, 3},
    {"Grand", IPL_ACP, 41, 55, 6, PLT_ARMO | PLT_SHLD, 0, 1, 1, 220, 300, 5},
    {"Valiant", IPL_ACP, 56, 70, 10, PLT_ARMO | PLT_SHLD, 0, 1, 1, 320, 400, 7},
    {"Glorious", IPL_ACP, 71, 90, 14, PLT_ARMO | PLT_SHLD, 16, 1, 1, 420, 600,
     9},
    {"Blessed", IPL_ACP, 91, 110, 19, PLT_ARMO | PLT_SHLD, 16, 1, 1, 620, 800,
     11},
    {"Saintly", IPL_ACP, 111, 130, 24, PLT_ARMO | PLT_SHLD, 16, 1, 1, 820, 1200,
     13},
    {"Awesome", IPL_ACP, 131, 150, 28, PLT_ARMO | PLT_SHLD, 16, 1, 1, 1220,
     2000, 15},
    {"Holy", IPL_ACP, 151, 170, 35, PLT_ARMO | PLT_SHLD, 16, 1, 1, 5200, 6000,
     17},
    {"Godly", IPL_ACP, 171, 200, 60, PLT_ARMO | PLT_SHLD, 16, 1, 1, 6200, 7000,
     20},
    {"Red", IPL_FIRERES, 10, 20, 4,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     500, 1500, 2},
    {"Crimson", IPL_FIRERES, 21, 30, 10,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     2100, 3000, 2},
    {"Crimson", IPL_FIRERES, 31, 40, 16,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     3100, 4000, 2},
    {"Garnet", IPL_FIRERES, 41, 50, 20,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     8200, 12000, 3},
    {"Ruby", IPL_FIRERES, 51, 60, 26,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     17100, 20000, 5},
    {"Blue", IPL_LIGHTRES, 10, 20, 4,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     500, 1500, 2},
    {"Azure", IPL_LIGHTRES, 21, 30, 10,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     2100, 3000, 2},
    {"Lapis", IPL_LIGHTRES, 31, 40, 16,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     3100, 4000, 2},
    {"Cobalt", IPL_LIGHTRES, 41, 50, 20,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     8200, 12000, 3},
    {"Sapphire", IPL_LIGHTRES, 51, 60, 26,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     17100, 20000, 5},
    {"White", IPL_MAGICRES, 10, 20, 4,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     500, 1500, 2},
    {"Pearl", IPL_MAGICRES, 21, 30, 10,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     2100, 3000, 2},
    {"Ivory", IPL_MAGICRES, 31, 40, 16,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     3100, 4000, 2},
    {"Crystal", IPL_MAGICRES, 41, 50, 20,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     8200, 12000, 3},
    {"Diamond", IPL_MAGICRES, 51, 60, 26,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     17100, 20000, 5},
    {"Topaz", IPL_ALLRES, 10, 15, 8,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     2000, 5000, 3},
    {"Amber", IPL_ALLRES, 16, 20, 12,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     7400, 10000, 3},
    {"Jade", IPL_ALLRES, 21, 30, 18,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     11000, 15000, 3},
    {"Obsidian", IPL_ALLRES, 31, 40, 24,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     24000, 40000, 4},
    {"Emerald", IPL_ALLRES, 41, 50, 31,
     PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW, 0, 0, 1, 61000, 75000, 7},
    {"Hyena's", IPL_MANA_CURSE, 11, 25, 4, PLT_STAFF | PLT_MISC, 0, 0, 0, 100,
     1000, -2},
    {"Frog's", IPL_MANA_CURSE, 1, 10, 1, PLT_STAFF | PLT_MISC, 1, 0, 0, 0, 0,
     -2},
    {"Spider's", IPL_MANA, 10, 15, 1, PLT_STAFF | PLT_MISC, 1, 0, 1, 500, 1000,
     2},
    {"Raven's", IPL_MANA, 15, 20, 5, PLT_STAFF | PLT_MISC, 0, 0, 1, 1100, 2000,
     3},
    {"Snake's", IPL_MANA, 21, 30, 9, PLT_STAFF | PLT_MISC, 0, 0, 1, 2100, 4000,
     5},
    {"Serpent's", IPL_MANA, 30, 40, 15, PLT_STAFF | PLT_MISC, 0, 0, 1, 4100,
     6000, 7},
    {"Drake's", IPL_MANA, 41, 50, 21, PLT_STAFF | PLT_MISC, 0, 0, 1, 6100,
     10000, 9},
    {"Dragon's", IPL_MANA, 51, 60, 27, PLT_STAFF | PLT_MISC, 0, 0, 1, 10100,
     15000, 11},
    {"Wyrm's", IPL_MANA, 61, 80, 35, PLT_STAFF, 0, 0, 1, 15100, 19000, 12},
    {"Hydra's", IPL_MANA, 81, 100, 60, PLT_STAFF, 0, 0, 1, 19100, 30000, 13},
    {"Angel's", IPL_SPLLVLADD, 1, 1, 15, PLT_STAFF, 16, 0, 1, 25000, 25000, 2},
    {"Arch-Angel's", IPL_SPLLVLADD, 2, 2, 25, PLT_STAFF, 16, 0, 1, 50000, 50000,
     3},
    {"Plentiful", IPL_CHARGES, 2, 2, 4, PLT_STAFF, 0, 0, 1, 2000, 2000, 2},
    {"Bountiful", IPL_CHARGES, 3, 3, 9, PLT_STAFF, 0, 0, 1, 3000, 3000, 3},
    {"Flaming", IPL_FIREDAM, 1, 10, 7, PLT_WEAP | PLT_STAFF, 0, 0, 1, 5000,
     5000, 2},
    {"Lightning", IPL_LIGHTDAM, 2, 20, 18, PLT_WEAP | PLT_STAFF, 0, 0, 1, 10000,
     10000, 2},
    {&empty_string, IPL_INVALID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
PLStruct PL_Suffix[96] = {
    {"quality", IPL_DAMMOD, 1, 2, 2, PLT_WEAP | PLT_BOW, 0, 0, 1, 100, 200, 2},
    {"maiming", IPL_DAMMOD, 3, 5, 7, PLT_WEAP | PLT_BOW, 0, 0, 1, 1300, 1500,
     3},
    {"slaying", IPL_DAMMOD, 6, 8, 15, PLT_WEAP, 0, 0, 1, 2600, 3000, 5},
    {"gore", IPL_DAMMOD, 9, 12, 25, PLT_WEAP, 0, 0, 1, 4100, 5000, 8},
    {"carnage", IPL_DAMMOD, 13, 16, 35, PLT_WEAP, 0, 0, 1, 5100, 10000, 10},
    {"slaughter", IPL_DAMMOD, 17, 20, 60, PLT_WEAP, 0, 0, 1, 10100, 15000, 13},
    {"pain", IPL_GETHIT_CURSE, 2, 4, 4, PLT_ARMO | PLT_SHLD | PLT_MISC, 1, 0, 0,
     0, 0, -4},
    {"tears", IPL_GETHIT_CURSE, 1, 1, 2, PLT_ARMO | PLT_SHLD | PLT_MISC, 1, 0,
     0, 0, 0, -2},
    {"health", IPL_GETHIT, 1, 1, 2, PLT_ARMO | PLT_SHLD | PLT_MISC, 16, 0, 1,
     200, 200, 2},
    {"protection", IPL_GETHIT, 2, 2, 6, PLT_ARMO | PLT_SHLD, 16, 0, 1, 400, 800,
     4},
    {"absorption", IPL_GETHIT, 3, 3, 12, PLT_ARMO | PLT_SHLD, 16, 0, 1, 1001,
     2500, 10},
    {"deflection", IPL_GETHIT, 4, 4, 20, PLT_ARMO, 16, 0, 1, 2500, 6500, 15},
    {"osmosis", IPL_GETHIT, 5, 6, 50, PLT_ARMO, 16, 0, 1, 7500, 10000, 20},
    {"frailty", IPL_STR_CURSE, 6, 10, 3,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -3},
    {"weakness", IPL_STR_CURSE, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -2},
    {"strength", IPL_STR, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 200, 1000,
     2},
    {"might", IPL_STR, 6, 10, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 1200, 2000,
     3},
    {"power", IPL_STR, 11, 15, 11,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 2200, 3000,
     4},
    {"giants", IPL_STR, 16, 20, 17, PLT_ARMO | PLT_WEAP | PLT_BOW | PLT_MISC, 0,
     0, 1, 3200, 5000, 7},
    {"titans", IPL_STR, 21, 30, 23, PLT_WEAP | PLT_MISC, 0, 0, 1, 5200, 10000,
     10},
    {"paralysis", IPL_DEX_CURSE, 6, 10, 3,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -3},
    {"atrophy", IPL_DEX_CURSE, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -2},
    {"dexterity", IPL_DEX, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 200, 1000,
     2},
    {"skill", IPL_DEX, 6, 10, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 1200, 2000,
     3},
    {"accuracy", IPL_DEX, 11, 15, 11,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 2200, 3000,
     4},
    {"precision", IPL_DEX, 16, 20, 17, PLT_ARMO | PLT_WEAP | PLT_BOW | PLT_MISC,
     0, 0, 1, 3200, 5000, 7},
    {"perfection", IPL_DEX, 21, 30, 23, PLT_BOW | PLT_MISC, 0, 0, 1, 5200,
     10000, 10},
    {"the fool", IPL_MAG_CURSE, 6, 10, 3,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 1, 0, 0,
     0, 0, -3},
    {"dyslexia", IPL_MAG_CURSE, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 1, 0, 0,
     0, 0, -2},
    {"magic", IPL_MAG, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     200, 1000, 2},
    {"the mind", IPL_MAG, 6, 10, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     1200, 2000, 3},
    {"brilliance", IPL_MAG, 11, 15, 11,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1,
     2200, 3000, 4},
    {"sorcery", IPL_MAG, 16, 20, 17,
     PLT_ARMO | PLT_WEAP | PLT_STAFF | PLT_BOW | PLT_MISC, 0, 0, 1, 3200, 5000,
     7},
    {"wizardry", IPL_MAG, 21, 30, 23, PLT_STAFF | PLT_MISC, 0, 0, 1, 5200,
     10000, 10},
    {"illness", IPL_VIT_CURSE, 6, 10, 3,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -3},
    {"disease", IPL_VIT_CURSE, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -2},
    {"vitality", IPL_VIT, 1, 5, 1,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 16, 0, 1, 200, 1000,
     2},
    {"zest", IPL_VIT, 6, 10, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 16, 0, 1, 1200, 2000,
     3},
    {"vim", IPL_VIT, 11, 15, 11,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 16, 0, 1, 2200, 3000,
     4},
    {"vigor", IPL_VIT, 16, 20, 17, PLT_ARMO | PLT_WEAP | PLT_BOW | PLT_MISC, 16,
     0, 1, 3200, 5000, 7},
    {"life", IPL_VIT, 21, 30, 23, PLT_MISC, 16, 0, 1, 5200, 10000, 10},
    {"trouble", IPL_ATTRIBS_CURSE, 6, 10, 12,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -10},
    {"the pit", IPL_ATTRIBS_CURSE, 1, 5, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 1, 0, 0, 0, 0, -5},
    {"the sky", IPL_ATTRIBS, 1, 3, 5,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 800, 4000,
     5},
    {"the moon", IPL_ATTRIBS, 4, 7, 11,
     PLT_ARMO | PLT_SHLD | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 4800, 8000,
     10},
    {"the stars", IPL_ATTRIBS, 8, 11, 17,
     PLT_ARMO | PLT_WEAP | PLT_BOW | PLT_MISC, 0, 0, 1, 8800, 12000, 15},
    {"the heavens", IPL_ATTRIBS, 12, 15, 25, PLT_WEAP | PLT_BOW | PLT_MISC, 0,
     0, 1, 12800, 20000, 20},
    {"the zodiac", IPL_ATTRIBS, 16, 20, 30, PLT_MISC, 0, 0, 1, 20800, 40000,
     30},
    {"the vulture", IPL_LIFE_CURSE, 11, 25, 4, PLT_ARMO | PLT_SHLD | PLT_MISC,
     1, 0, 0, 0, 0, -4},
    {"the jackal", IPL_LIFE_CURSE, 1, 10, 1, PLT_ARMO | PLT_SHLD | PLT_MISC, 1,
     0, 0, 0, 0, -2},
    {"the fox", IPL_LIFE, 10, 15, 1, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0, 1,
     100, 1000, 2},
    {"the jaguar", IPL_LIFE, 16, 20, 5, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0, 1,
     1100, 2000, 3},
    {"the eagle", IPL_LIFE, 21, 30, 9, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0, 1,
     2100, 4000, 5},
    {"the wolf", IPL_LIFE, 30, 40, 15, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0, 1,
     4100, 6000, 7},
    {"the tiger", IPL_LIFE, 41, 50, 21, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0, 1,
     6100, 10000, 9},
    {"the lion", IPL_LIFE, 51, 60, 27, PLT_ARMO | PLT_MISC, 0, 0, 1, 10100,
     15000, 11},
    {"the mammoth", IPL_LIFE, 61, 80, 35, PLT_ARMO, 0, 0, 1, 15100, 19000, 12},
    {"the whale", IPL_LIFE, 81, 100, 60, PLT_ARMO, 0, 0, 1, 19100, 30000, 13},
    {"fragility", IPL_DUR_CURSE, 100, 100, 3, PLT_ARMO | PLT_SHLD | PLT_WEAP, 1,
     0, 0, 0, 0, -4},
    {"brittleness", IPL_DUR_CURSE, 26, 75, 1, PLT_ARMO | PLT_SHLD | PLT_WEAP, 1,
     0, 0, 0, 0, -2},
    {"sturdiness", IPL_DUR, 26, 75, 1, PLT_ARMO | PLT_SHLD | PLT_WEAP, 0, 0, 1,
     100, 100, 2},
    {"craftsmanship", IPL_DUR, 51, 100, 6, PLT_ARMO | PLT_SHLD | PLT_WEAP, 0, 0,
     1, 200, 200, 2},
    {"structure", IPL_DUR, 101, 200, 12, PLT_ARMO | PLT_SHLD | PLT_WEAP, 0, 0,
     1, 300, 300, 2},
    {"the ages", IPL_INDESTRUCTIBLE, 0, 0, 25, PLT_ARMO | PLT_SHLD | PLT_WEAP,
     0, 0, 1, 600, 600, 5},
    {"the dark", IPL_LIGHT_CURSE, 4, 4, 6, PLT_ARMO | PLT_WEAP | PLT_MISC, 1, 0,
     0, 0, 0, -3},
    {"the night", IPL_LIGHT_CURSE, 2, 2, 3, PLT_ARMO | PLT_WEAP | PLT_MISC, 1,
     0, 0, 0, 0, -2},
    {"light", IPL_LIGHT, 2, 2, 4, PLT_ARMO | PLT_WEAP | PLT_MISC, 16, 0, 1, 750,
     750, 2},
    {"radiance", IPL_LIGHT, 4, 4, 8, PLT_ARMO | PLT_WEAP | PLT_MISC, 16, 0, 1,
     1500, 1500, 3},
    {"flame", IPL_FIRE_ARROWS, 1, 3, 1, PLT_BOW, 0, 0, 1, 2000, 2000, 2},
    {"fire", IPL_FIRE_ARROWS, 1, 6, 11, PLT_BOW, 0, 0, 1, 4000, 4000, 4},
    {"burning", IPL_FIRE_ARROWS, 1, 16, 35, PLT_BOW, 0, 0, 1, 6000, 6000, 6},
    {"shock", IPL_LIGHT_ARROWS, 1, 6, 13, PLT_BOW, 0, 0, 1, 6000, 6000, 2},
    {"lightning", IPL_LIGHT_ARROWS, 1, 10, 21, PLT_BOW, 0, 0, 1, 8000, 8000, 4},
    {"thunder", IPL_LIGHT_ARROWS, 1, 20, 60, PLT_BOW, 0, 0, 1, 12000, 12000, 6},
    {"many", IPL_DUR, 100, 100, 3, PLT_BOW, 0, 0, 1, 750, 750, 2},
    {"plenty", IPL_DUR, 200, 200, 7, PLT_BOW, 0, 0, 1, 1500, 1500, 3},
    {"thorns", IPL_THORNS, 1, 3, 1, PLT_ARMO | PLT_SHLD, 0, 0, 1, 500, 500, 2},
    {"corruption", IPL_NOMANA, 0, 0, 5, PLT_ARMO | PLT_SHLD | PLT_WEAP, 1, 0, 0,
     -1000, -1000, 2},
    {"thieves", IPL_ABSHALFTRAP, 0, 0, 11, PLT_ARMO | PLT_SHLD | PLT_MISC, 0, 0,
     1, 1500, 1500, 2},
    {"the bear", IPL_KNOCKBACK, 0, 0, 5, PLT_WEAP | PLT_STAFF | PLT_BOW, 1, 0,
     1, 750, 750, 2},
    {"the bat", IPL_STEALMANA, 3, 3, 8, PLT_WEAP, 0, 0, 1, 7500, 7500, 3},
    {"vampires", IPL_STEALMANA, 5, 5, 19, PLT_WEAP, 0, 0, 1, 15000, 15000, 3},
    {"the leech", IPL_STEALLIFE, 3, 3, 8, PLT_WEAP, 0, 0, 1, 7500, 7500, 3},
    {"blood", IPL_STEALLIFE, 5, 5, 19, PLT_WEAP, 0, 0, 1, 15000, 15000, 3},
    {"piercing", IPL_TARGAC, 2, 6, 1, PLT_WEAP | PLT_BOW, 0, 0, 1, 1000, 1000,
     3},
    {"puncturing", IPL_TARGAC, 4, 12, 9, PLT_WEAP | PLT_BOW, 0, 0, 1, 2000,
     2000, 6},
    {"bashing", IPL_TARGAC, 8, 24, 17, PLT_WEAP, 0, 0, 1, 4000, 4000, 12},
    {"readiness", IPL_FASTATTACK, 1, 1, 1, PLT_WEAP | PLT_STAFF | PLT_BOW, 0, 0,
     1, 2000, 2000, 2},
    {"swiftness", IPL_FASTATTACK, 2, 2, 10, PLT_WEAP | PLT_STAFF | PLT_BOW, 0,
     0, 1, 4000, 4000, 4},
    {"speed", IPL_FASTATTACK, 3, 3, 19, PLT_WEAP | PLT_STAFF, 0, 0, 1, 8000,
     8000, 8},
    {"haste", IPL_FASTATTACK, 4, 4, 27, PLT_WEAP | PLT_STAFF, 0, 0, 1, 16000,
     16000, 16},
    {"balance", IPL_FASTRECOVER, 1, 1, 1, PLT_ARMO | PLT_MISC, 0, 0, 1, 2000,
     2000, 2},
    {"stability", IPL_FASTRECOVER, 2, 2, 10, PLT_ARMO | PLT_MISC, 0, 0, 1, 4000,
     4000, 4},
    {"harmony", IPL_FASTRECOVER, 3, 3, 20, PLT_ARMO | PLT_MISC, 0, 0, 1, 8000,
     8000, 8},
    {"blocking", IPL_FASTBLOCK, 1, 1, 5, PLT_SHLD, 0, 0, 1, 4000, 4000, 4},
    {&empty_string, IPL_INVALID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
UItemStruct UniqueItemList[91] = {
    {"The Butcher's Cleaver",
     UITYPE_CLEAVER,
     1u,
     3u,
     3650,
     IPL_STR,
     10,
     10,
     IPL_SETDAM,
     4,
     24,
     IPL_SETDUR,
     10,
     10,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Undead Crown",
     UITYPE_SKCROWN,
     1u,
     3u,
     16650,
     IPL_RNDSTEALLIFE,
     0,
     0,
     IPL_SETAC,
     8,
     8,
     IPL_INVCURS,
     77,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Empyrean Band",
     UITYPE_INFRARING,
     1u,
     4u,
     8000,
     IPL_ATTRIBS,
     2,
     2,
     IPL_LIGHT,
     2,
     2,
     IPL_FASTRECOVER,
     1,
     1,
     IPL_ABSHALFTRAP,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Optic Amulet",
     UITYPE_OPTAMULET,
     1u,
     5u,
     9750,
     IPL_LIGHT,
     2,
     2,
     IPL_LIGHTRES,
     20,
     20,
     IPL_GETHIT,
     1,
     1,
     IPL_MAG,
     5,
     5,
     IPL_INVCURS,
     44,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Ring of Truth",
     UITYPE_TRING,
     1u,
     4u,
     9100,
     IPL_LIFE,
     10,
     10,
     IPL_GETHIT,
     1,
     1,
     IPL_ALLRES,
     10,
     10,
     IPL_INVCURS,
     10,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Harlequin Crest",
     UITYPE_HARCREST,
     1u,
     6u,
     4000,
     IPL_AC_CURSE,
     3,
     3,
     IPL_GETHIT,
     1,
     1,
     IPL_ATTRIBS,
     2,
     2,
     IPL_LIFE,
     7,
     7,
     IPL_MANA,
     7,
     7,
     IPL_INVCURS,
     81,
     0},
    {"Veil of Steel",
     UITYPE_STEELVEIL,
     1u,
     6u,
     63800,
     IPL_ALLRES,
     50,
     50,
     IPL_LIGHT_CURSE,
     2,
     2,
     IPL_ACP,
     60,
     60,
     IPL_MANA_CURSE,
     30,
     30,
     IPL_STR,
     15,
     15,
     IPL_VIT,
     15,
     15},
    {"Arkaine's Valor",
     UITYPE_ARMOFVAL,
     1u,
     4u,
     42000,
     IPL_SETAC,
     25,
     25,
     IPL_VIT,
     10,
     10,
     IPL_GETHIT,
     3,
     3,
     IPL_FASTRECOVER,
     3,
     3,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Griswold's Edge",
     UITYPE_GRISWOLD,
     1u,
     6u,
     42000,
     IPL_FIREDAM,
     1,
     10,
     IPL_TOHIT,
     25,
     25,
     IPL_FASTATTACK,
     2,
     2,
     IPL_KNOCKBACK,
     0,
     0,
     IPL_MANA,
     20,
     20,
     IPL_LIFE_CURSE,
     20,
     20},
    {"Lightforge",
     UITYPE_MACE,
     1u,
     6u,
     26675,
     IPL_LIGHT,
     4,
     4,
     IPL_DAMP,
     150,
     150,
     IPL_TOHIT,
     25,
     25,
     IPL_FIREDAM,
     10,
     20,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_ATTRIBS,
     8,
     8},
    {"The Rift Bow",
     UITYPE_SHORTBOW,
     1u,
     3u,
     1800,
     IPL_RNDARROWVEL,
     0,
     0,
     IPL_DAMMOD,
     2,
     2,
     IPL_DEX_CURSE,
     3,
     3,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Needler",
     UITYPE_SHORTBOW,
     2u,
     4u,
     8900,
     IPL_TOHIT,
     50,
     50,
     IPL_SETDAM,
     1,
     3,
     IPL_FASTATTACK,
     2,
     2,
     IPL_INVCURS,
     158,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Celestial Bow",
     UITYPE_LONGBOW,
     2u,
     4u,
     1200,
     IPL_NOMINSTR,
     0,
     0,
     IPL_DAMMOD,
     2,
     2,
     IPL_SETAC,
     5,
     5,
     IPL_INVCURS,
     133,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Deadly Hunter",
     UITYPE_COMPBOW,
     3u,
     4u,
     8750,
     IPL_3XDAMVDEM,
     10,
     10,
     IPL_TOHIT,
     20,
     20,
     IPL_MAG_CURSE,
     5,
     5,
     IPL_INVCURS,
     108,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Bow of the Dead",
     UITYPE_COMPBOW,
     5u,
     6u,
     2500,
     IPL_TOHIT,
     10,
     10,
     IPL_DEX,
     4,
     4,
     IPL_VIT_CURSE,
     3,
     3,
     IPL_LIGHT_CURSE,
     2,
     2,
     IPL_SETDUR,
     30,
     30,
     IPL_INVCURS,
     108,
     0},
    {"The Blackoak Bow",
     UITYPE_LONGBOW,
     5u,
     4u,
     2500,
     IPL_DEX,
     10,
     10,
     IPL_VIT_CURSE,
     10,
     10,
     IPL_DAMP,
     50,
     50,
     IPL_LIGHT_CURSE,
     1,
     1,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Flamedart",
     UITYPE_HUNTBOW,
     10u,
     4u,
     14250,
     IPL_FIRE_ARROWS,
     0,
     0,
     IPL_FIREDAM,
     1,
     6,
     IPL_TOHIT,
     20,
     20,
     IPL_FIRERES,
     40,
     40,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Fleshstinger",
     UITYPE_LONGBOW,
     13u,
     4u,
     16500,
     IPL_DEX,
     15,
     15,
     IPL_TOHIT,
     40,
     40,
     IPL_DAMP,
     80,
     80,
     IPL_DUR,
     6,
     6,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Windforce",
     UITYPE_WARBOW,
     17u,
     4u,
     37750,
     IPL_STR,
     5,
     5,
     IPL_DAMP,
     200,
     200,
     IPL_KNOCKBACK,
     0,
     0,
     IPL_INVCURS,
     164,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Eaglehorn",
     UITYPE_BATTLEBOW,
     26u,
     5u,
     42500,
     IPL_DEX,
     20,
     20,
     IPL_TOHIT,
     50,
     50,
     IPL_DAMP,
     100,
     100,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_INVCURS,
     108,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Gonnagal's Dirk",
     UITYPE_DAGGER,
     1u,
     5u,
     7040,
     IPL_DEX_CURSE,
     5,
     5,
     IPL_DAMMOD,
     4,
     4,
     IPL_FASTATTACK,
     2,
     2,
     IPL_FIRERES,
     25,
     25,
     IPL_INVCURS,
     54,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Defender",
     UITYPE_SABRE,
     1u,
     3u,
     2000,
     IPL_SETAC,
     5,
     5,
     IPL_VIT,
     5,
     5,
     IPL_TOHIT_CURSE,
     5,
     5,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Gryphons Claw",
     UITYPE_FALCHION,
     1u,
     4u,
     1000,
     IPL_DAMP,
     100,
     100,
     IPL_MAG_CURSE,
     2,
     2,
     IPL_DEX_CURSE,
     5,
     5,
     IPL_INVCURS,
     68,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Black Razor",
     UITYPE_DAGGER,
     1u,
     4u,
     2000,
     IPL_DAMP,
     150,
     150,
     IPL_VIT,
     2,
     2,
     IPL_SETDUR,
     5,
     5,
     IPL_INVCURS,
     53,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Gibbous Moon",
     UITYPE_BROADSWR,
     2u,
     4u,
     6660,
     IPL_ATTRIBS,
     2,
     2,
     IPL_DAMP,
     25,
     25,
     IPL_MANA,
     15,
     15,
     IPL_LIGHT_CURSE,
     3,
     3,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Ice Shank",
     UITYPE_LONGSWR,
     3u,
     3u,
     5250,
     IPL_FIRERES,
     40,
     40,
     IPL_SETDUR,
     15,
     15,
     IPL_STR,
     5,
     10,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Executioner's Blade",
     UITYPE_FALCHION,
     3u,
     5u,
     7080,
     IPL_DAMP,
     150,
     150,
     IPL_LIFE_CURSE,
     10,
     10,
     IPL_LIGHT_CURSE,
     1,
     1,
     IPL_DUR,
     200,
     200,
     IPL_INVCURS,
     58,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Bonesaw",
     UITYPE_CLAYMORE,
     6u,
     6u,
     4400,
     IPL_DAMMOD,
     10,
     10,
     IPL_STR,
     10,
     10,
     IPL_MAG_CURSE,
     5,
     5,
     IPL_DEX_CURSE,
     5,
     5,
     IPL_LIFE,
     10,
     10,
     IPL_MANA_CURSE,
     10,
     10},
    {"Shadowhawk",
     UITYPE_BROADSWR,
     8u,
     4u,
     13750,
     IPL_LIGHT_CURSE,
     2,
     2,
     IPL_STEALLIFE,
     5,
     5,
     IPL_TOHIT,
     15,
     15,
     IPL_ALLRES,
     5,
     5,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Wizardspike",
     UITYPE_DAGGER,
     11u,
     5u,
     12920,
     IPL_MAG,
     15,
     15,
     IPL_MANA,
     35,
     35,
     IPL_TOHIT,
     25,
     25,
     IPL_ALLRES,
     15,
     15,
     IPL_INVCURS,
     50,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Lightsabre",
     UITYPE_SABRE,
     13u,
     4u,
     19150,
     IPL_LIGHT,
     2,
     2,
     IPL_LIGHTDAM,
     1,
     10,
     IPL_TOHIT,
     20,
     20,
     IPL_LIGHTRES,
     50,
     50,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Falcon's Talon",
     UITYPE_SCIMITAR,
     15u,
     5u,
     7867,
     IPL_FASTATTACK,
     4,
     4,
     IPL_TOHIT,
     20,
     20,
     IPL_DAMP_CURSE,
     33,
     33,
     IPL_DEX,
     10,
     10,
     IPL_INVCURS,
     68,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Inferno",
     UITYPE_LONGSWR,
     17u,
     4u,
     34600,
     IPL_FIREDAM,
     2,
     12,
     IPL_LIGHT,
     3,
     3,
     IPL_MANA,
     20,
     20,
     IPL_FIRERES,
     80,
     80,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Doombringer",
     UITYPE_BASTARDSWR,
     19u,
     5u,
     18250,
     IPL_TOHIT,
     25,
     25,
     IPL_DAMP,
     250,
     250,
     IPL_ATTRIBS_CURSE,
     5,
     5,
     IPL_LIFE_CURSE,
     25,
     25,
     IPL_LIGHT_CURSE,
     2,
     2,
     IPL_TOHIT,
     0,
     0},
    {"The Grizzly",
     UITYPE_TWOHANDSWR,
     23u,
     6u,
     50000,
     IPL_STR,
     20,
     20,
     IPL_VIT_CURSE,
     5,
     5,
     IPL_DAMP,
     200,
     200,
     IPL_KNOCKBACK,
     0,
     0,
     IPL_DUR,
     100,
     100,
     IPL_INVCURS,
     160,
     0},
    {"The Grandfather",
     UITYPE_GREATSWR,
     27u,
     6u,
     119800,
     IPL_ONEHAND,
     0,
     0,
     IPL_ATTRIBS,
     5,
     5,
     IPL_TOHIT,
     20,
     20,
     IPL_DAMP,
     70,
     70,
     IPL_LIFE,
     20,
     20,
     IPL_INVCURS,
     161,
     0},
    {"The Mangler",
     UITYPE_LARGEAXE,
     2u,
     5u,
     2850,
     IPL_DAMP,
     200,
     200,
     IPL_DEX_CURSE,
     5,
     5,
     IPL_MAG_CURSE,
     5,
     5,
     IPL_MANA_CURSE,
     10,
     10,
     IPL_INVCURS,
     144,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Sharp Beak",
     UITYPE_LARGEAXE,
     2u,
     4u,
     2850,
     IPL_LIFE,
     20,
     20,
     IPL_MAG_CURSE,
     10,
     10,
     IPL_MANA_CURSE,
     10,
     10,
     IPL_INVCURS,
     143,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"BloodSlayer",
     UITYPE_BROADAXE,
     3u,
     5u,
     2500,
     IPL_DAMP,
     100,
     100,
     IPL_3XDAMVDEM,
     50,
     50,
     IPL_ATTRIBS_CURSE,
     5,
     5,
     IPL_SPLLVLADD,
     -1,
     -1,
     IPL_INVCURS,
     144,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Celestial Axe",
     UITYPE_BATTLEAXE,
     4u,
     4u,
     14100,
     IPL_NOMINSTR,
     0,
     0,
     IPL_TOHIT,
     15,
     15,
     IPL_LIFE,
     15,
     15,
     IPL_STR_CURSE,
     15,
     15,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Wicked Axe",
     UITYPE_LARGEAXE,
     5u,
     6u,
     31150,
     IPL_TOHIT,
     30,
     30,
     IPL_DEX,
     10,
     10,
     IPL_VIT_CURSE,
     10,
     10,
     IPL_GETHIT,
     1,
     6,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_INVCURS,
     143,
     0},
    {"Stonecleaver",
     UITYPE_BROADAXE,
     7u,
     5u,
     23900,
     IPL_LIFE,
     30,
     30,
     IPL_TOHIT,
     20,
     20,
     IPL_DAMP,
     50,
     50,
     IPL_LIGHTRES,
     40,
     40,
     IPL_INVCURS,
     104,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Aguinara's Hatchet",
     UITYPE_SMALLAXE,
     12u,
     3u,
     24800,
     IPL_SPLLVLADD,
     1,
     1,
     IPL_MAG,
     10,
     10,
     IPL_MAGICRES,
     80,
     80,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Hellslayer",
     UITYPE_BATTLEAXE,
     15u,
     5u,
     26200,
     IPL_STR,
     8,
     8,
     IPL_VIT,
     8,
     8,
     IPL_DAMP,
     100,
     100,
     IPL_LIFE,
     25,
     25,
     IPL_MANA_CURSE,
     25,
     25,
     IPL_TOHIT,
     0,
     0},
    {"Messerschmidt's Reaver",
     UITYPE_GREATAXE,
     25u,
     6u,
     58000,
     IPL_DAMP,
     200,
     200,
     IPL_DAMMOD,
     15,
     15,
     IPL_ATTRIBS,
     5,
     5,
     IPL_LIFE_CURSE,
     50,
     50,
     IPL_FIREDAM,
     2,
     12,
     IPL_INVCURS,
     163,
     0},
    {"Crackrust",
     UITYPE_MACE,
     1u,
     5u,
     11375,
     IPL_ATTRIBS,
     2,
     2,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_ALLRES,
     15,
     15,
     IPL_DAMP,
     50,
     50,
     IPL_SPLLVLADD,
     -1,
     -1,
     IPL_TOHIT,
     0,
     0},
    {"Hammer of Jholm",
     UITYPE_MAUL,
     1u,
     4u,
     8700,
     IPL_DAMP,
     4,
     10,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_STR,
     3,
     3,
     IPL_TOHIT,
     15,
     15,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Civerb's Cudgel",
     UITYPE_MACE,
     1u,
     3u,
     2000,
     IPL_3XDAMVDEM,
     35,
     35,
     IPL_DEX_CURSE,
     5,
     5,
     IPL_MAG_CURSE,
     2,
     2,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Celestial Star",
     UITYPE_FLAIL,
     2u,
     5u,
     7810,
     IPL_NOMINSTR,
     0,
     0,
     IPL_LIGHT,
     2,
     2,
     IPL_DAMMOD,
     10,
     10,
     IPL_AC_CURSE,
     8,
     8,
     IPL_INVCURS,
     131,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Baranar's Star",
     UITYPE_MORNSTAR,
     5u,
     6u,
     6850,
     IPL_TOHIT,
     12,
     12,
     IPL_DAMP,
     80,
     80,
     IPL_FASTATTACK,
     1,
     1,
     IPL_VIT,
     4,
     4,
     IPL_DEX_CURSE,
     4,
     4,
     IPL_SETDUR,
     60,
     60},
    {"Gnarled Root",
     UITYPE_SPIKCLUB,
     9u,
     6u,
     9820,
     IPL_TOHIT,
     20,
     20,
     IPL_DAMP,
     300,
     300,
     IPL_DEX,
     10,
     10,
     IPL_MAG,
     5,
     5,
     IPL_ALLRES,
     10,
     10,
     IPL_AC_CURSE,
     10,
     10},
    {"The Cranium Basher",
     UITYPE_MAUL,
     12u,
     6u,
     36500,
     IPL_DAMMOD,
     20,
     20,
     IPL_STR,
     15,
     15,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_MANA_CURSE,
     150,
     150,
     IPL_ALLRES,
     5,
     5,
     IPL_INVCURS,
     122,
     0},
    {"Schaefer's Hammer",
     UITYPE_WARHAMMER,
     16u,
     6u,
     56125,
     IPL_DAMP_CURSE,
     100,
     100,
     IPL_LIGHTDAM,
     1,
     50,
     IPL_LIFE,
     50,
     50,
     IPL_TOHIT,
     30,
     30,
     IPL_LIGHTRES,
     80,
     80,
     IPL_LIGHT,
     1,
     1},
    {"Dreamflange",
     UITYPE_MACE,
     26u,
     5u,
     26450,
     IPL_MAG,
     30,
     30,
     IPL_MANA,
     50,
     50,
     IPL_MAGICRES,
     50,
     50,
     IPL_LIGHT,
     2,
     2,
     IPL_SPLLVLADD,
     1,
     1,
     IPL_TOHIT,
     0,
     0},
    {"Staff of Shadows",
     UITYPE_LONGSTAFF,
     2u,
     5u,
     1250,
     IPL_MAG_CURSE,
     10,
     10,
     IPL_TOHIT,
     10,
     10,
     IPL_DAMP,
     60,
     60,
     IPL_LIGHT_CURSE,
     2,
     2,
     IPL_FASTATTACK,
     1,
     1,
     IPL_TOHIT,
     0,
     0},
    {"Immolator",
     UITYPE_LONGSTAFF,
     4u,
     4u,
     3900,
     IPL_FIRERES,
     20,
     20,
     IPL_FIREDAM,
     4,
     4,
     IPL_MANA,
     10,
     10,
     IPL_VIT_CURSE,
     5,
     5,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Storm Spire",
     UITYPE_WARSTAFF,
     8u,
     4u,
     22500,
     IPL_LIGHTRES,
     50,
     50,
     IPL_LIGHTDAM,
     2,
     8,
     IPL_STR,
     10,
     10,
     IPL_MAG_CURSE,
     10,
     10,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Gleamsong",
     UITYPE_SHORTSTAFF,
     8u,
     4u,
     6520,
     IPL_MANA,
     25,
     25,
     IPL_STR_CURSE,
     3,
     3,
     IPL_VIT_CURSE,
     3,
     3,
     IPL_SPELL,
     10,
     76,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Thundercall",
     UITYPE_COMPSTAFF,
     14u,
     5u,
     22250,
     IPL_TOHIT,
     35,
     35,
     IPL_LIGHTDAM,
     1,
     10,
     IPL_SPELL,
     3,
     76,
     IPL_LIGHTRES,
     30,
     30,
     IPL_LIGHT,
     2,
     2,
     IPL_TOHIT,
     0,
     0},
    {"The Protector",
     UITYPE_SHORTSTAFF,
     16u,
     6u,
     17240,
     IPL_VIT,
     5,
     5,
     IPL_GETHIT,
     5,
     5,
     IPL_SETAC,
     40,
     40,
     IPL_SPELL,
     2,
     86,
     IPL_THORNS,
     1,
     3,
     IPL_INVCURS,
     162,
     0},
    {"Naj's Puzzler",
     UITYPE_LONGSTAFF,
     18u,
     5u,
     34000,
     IPL_MAG,
     20,
     20,
     IPL_DEX,
     10,
     10,
     IPL_ALLRES,
     20,
     20,
     IPL_SPELL,
     23,
     57,
     IPL_LIFE_CURSE,
     25,
     25,
     IPL_TOHIT,
     0,
     0},
    {"Mindcry",
     UITYPE_QUARSTAFF,
     20u,
     4u,
     41500,
     IPL_MAG,
     15,
     15,
     IPL_SPELL,
     13,
     69,
     IPL_ALLRES,
     15,
     15,
     IPL_SPLLVLADD,
     1,
     1,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Rod of Onan",
     UITYPE_WARSTAFF,
     22u,
     3u,
     44167,
     IPL_SPELL,
     21,
     50,
     IPL_DAMP,
     100,
     100,
     IPL_ATTRIBS,
     5,
     5,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Helm of Sprits",
     UITYPE_HELM,
     1u,
     2u,
     7525,
     IPL_STEALLIFE,
     5,
     5,
     IPL_INVCURS,
     77,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Thinking Cap",
     UITYPE_SKULLCAP,
     6u,
     5u,
     2020,
     IPL_MANA,
     30,
     30,
     IPL_SPLLVLADD,
     2,
     2,
     IPL_ALLRES,
     20,
     20,
     IPL_SETDUR,
     1,
     1,
     IPL_INVCURS,
     93,
     0,
     IPL_TOHIT,
     0,
     0},
    {"OverLord's Helm",
     UITYPE_HELM,
     7u,
     6u,
     12500,
     IPL_STR,
     20,
     20,
     IPL_DEX,
     15,
     15,
     IPL_VIT,
     5,
     5,
     IPL_MAG_CURSE,
     20,
     20,
     IPL_SETDUR,
     15,
     15,
     IPL_INVCURS,
     99,
     0},
    {"Fool's Crest",
     UITYPE_HELM,
     12u,
     5u,
     10150,
     IPL_ATTRIBS_CURSE,
     4,
     4,
     IPL_LIFE,
     100,
     100,
     IPL_GETHIT_CURSE,
     1,
     6,
     IPL_THORNS,
     1,
     3,
     IPL_INVCURS,
     80,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Gotterdamerung",
     UITYPE_GREATHELM,
     21u,
     6u,
     54900,
     IPL_ATTRIBS,
     20,
     20,
     IPL_SETAC,
     60,
     60,
     IPL_GETHIT,
     4,
     4,
     IPL_ALLRESZERO,
     0,
     0,
     IPL_LIGHT_CURSE,
     4,
     4,
     IPL_INVCURS,
     85,
     0},
    {"Royal Circlet",
     UITYPE_CROWN,
     27u,
     5u,
     24875,
     IPL_ATTRIBS,
     10,
     10,
     IPL_MANA,
     40,
     40,
     IPL_SETAC,
     40,
     40,
     IPL_LIGHT,
     1,
     1,
     IPL_INVCURS,
     79,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Torn Flesh of Souls",
     UITYPE_RAGS,
     2u,
     5u,
     4825,
     IPL_SETAC,
     8,
     8,
     IPL_VIT,
     10,
     10,
     IPL_GETHIT,
     1,
     1,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_INVCURS,
     92,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Gladiator's Bane",
     UITYPE_STUDARMOR,
     6u,
     4u,
     3450,
     IPL_SETAC,
     25,
     25,
     IPL_GETHIT,
     2,
     2,
     IPL_DUR,
     200,
     200,
     IPL_ATTRIBS_CURSE,
     3,
     3,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"The Rainbow Cloak",
     UITYPE_CLOAK,
     2u,
     6u,
     4900,
     IPL_SETAC,
     10,
     10,
     IPL_ATTRIBS,
     1,
     1,
     IPL_ALLRES,
     10,
     10,
     IPL_LIFE,
     5,
     5,
     IPL_DUR,
     50,
     50,
     IPL_INVCURS,
     138,
     0},
    {"Leather of Aut",
     UITYPE_LEATHARMOR,
     4u,
     5u,
     10550,
     IPL_SETAC,
     15,
     15,
     IPL_STR,
     5,
     5,
     IPL_MAG_CURSE,
     5,
     5,
     IPL_DEX,
     5,
     5,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Wisdom's Wrap",
     UITYPE_ROBE,
     5u,
     6u,
     6200,
     IPL_MAG,
     5,
     5,
     IPL_MANA,
     10,
     10,
     IPL_LIGHTRES,
     25,
     25,
     IPL_SETAC,
     15,
     15,
     IPL_GETHIT,
     1,
     1,
     IPL_INVCURS,
     138,
     0},
    {"Sparking Mail",
     UITYPE_CHAINMAIL,
     9u,
     2u,
     15750,
     IPL_SETAC,
     30,
     30,
     IPL_LIGHTDAM,
     1,
     10,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Scavenger Carapace",
     UITYPE_BREASTPLATE,
     13u,
     4u,
     14000,
     IPL_GETHIT,
     15,
     15,
     IPL_AC_CURSE,
     30,
     30,
     IPL_DEX,
     5,
     5,
     IPL_LIGHTRES,
     40,
     40,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Nightscape",
     UITYPE_CAPE,
     16u,
     6u,
     11600,
     IPL_FASTRECOVER,
     2,
     2,
     IPL_LIGHT_CURSE,
     4,
     4,
     IPL_SETAC,
     15,
     15,
     IPL_DEX,
     3,
     3,
     IPL_ALLRES,
     20,
     20,
     IPL_INVCURS,
     138,
     0},
    {"Naj's Light Plate",
     UITYPE_PLATEMAIL,
     19u,
     6u,
     78700,
     IPL_NOMINSTR,
     0,
     0,
     IPL_MAG,
     5,
     5,
     IPL_MANA,
     20,
     20,
     IPL_ALLRES,
     20,
     20,
     IPL_SPLLVLADD,
     1,
     1,
     IPL_INVCURS,
     159,
     0},
    {"Demonspike Coat",
     UITYPE_FULLPLATE,
     25u,
     5u,
     251175,
     IPL_SETAC,
     100,
     100,
     IPL_GETHIT,
     6,
     6,
     IPL_STR,
     10,
     10,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_FIRERES,
     50,
     50,
     IPL_TOHIT,
     0,
     0},
    {"The Deflector",
     UITYPE_BUCKLER,
     1u,
     5u,
     1500,
     IPL_SETAC,
     7,
     7,
     IPL_ALLRES,
     10,
     10,
     IPL_DAMP_CURSE,
     20,
     20,
     IPL_TOHIT_CURSE,
     5,
     5,
     IPL_INVCURS,
     83,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Split Skull Shield",
     UITYPE_BUCKLER,
     1u,
     6u,
     2025,
     IPL_SETAC,
     10,
     10,
     IPL_LIFE,
     10,
     10,
     IPL_STR,
     2,
     2,
     IPL_LIGHT_CURSE,
     1,
     1,
     IPL_SETDUR,
     15,
     15,
     IPL_INVCURS,
     116,
     0},
    {"Dragon's Breach",
     UITYPE_KITESHIELD,
     2u,
     6u,
     19200,
     IPL_FIRERES,
     25,
     25,
     IPL_STR,
     5,
     5,
     IPL_SETAC,
     20,
     20,
     IPL_MAG_CURSE,
     5,
     5,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_INVCURS,
     117,
     0},
    {"Blackoak Shield",
     UITYPE_SMALLSHIELD,
     4u,
     6u,
     5725,
     IPL_DEX,
     10,
     10,
     IPL_VIT_CURSE,
     10,
     10,
     IPL_SETAC,
     18,
     18,
     IPL_LIGHT_CURSE,
     1,
     1,
     IPL_DUR,
     150,
     150,
     IPL_INVCURS,
     146,
     0},
    {"Holy Defender",
     UITYPE_LARGESHIELD,
     10u,
     6u,
     13800,
     IPL_SETAC,
     15,
     15,
     IPL_GETHIT,
     2,
     2,
     IPL_FIRERES,
     20,
     20,
     IPL_DUR,
     200,
     200,
     IPL_FASTBLOCK,
     1,
     1,
     IPL_INVCURS,
     146,
     0},
    {"Stormshield",
     UITYPE_GOTHSHIELD,
     24u,
     6u,
     49000,
     IPL_SETAC,
     40,
     40,
     IPL_GETHIT_CURSE,
     4,
     4,
     IPL_STR,
     10,
     10,
     IPL_INDESTRUCTIBLE,
     0,
     0,
     IPL_FASTBLOCK,
     1,
     1,
     IPL_INVCURS,
     148,
     0},
    {"Bramble", UITYPE_RING, 1u,          4u, 1000, IPL_ATTRIBS_CURSE,
     2,         2,           IPL_DAMMOD,  3,  3,    IPL_MANA,
     10,        10,          IPL_INVCURS, 9,  0,    IPL_TOHIT,
     0,         0,           IPL_TOHIT,   0,  0},
    {"Ring of Regha",
     UITYPE_RING,
     1u,
     6u,
     4175,
     IPL_MAG,
     10,
     10,
     IPL_MAGICRES,
     10,
     10,
     IPL_LIGHT,
     1,
     1,
     IPL_STR_CURSE,
     3,
     3,
     IPL_DEX_CURSE,
     3,
     3,
     IPL_INVCURS,
     11,
     0},
    {"The Bleeder",
     UITYPE_RING,
     2u,
     4u,
     8500,
     IPL_MAGICRES,
     20,
     20,
     IPL_MANA,
     30,
     30,
     IPL_LIFE_CURSE,
     10,
     10,
     IPL_INVCURS,
     8,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Constricting Ring",
     UITYPE_RING,
     5u,
     3u,
     62000,
     IPL_ALLRES,
     75,
     75,
     IPL_DRAINLIFE,
     0,
     0,
     IPL_INVCURS,
     14,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0},
    {"Ring of Engagement",
     UITYPE_RING,
     11u,
     5u,
     12476,
     IPL_GETHIT,
     1,
     2,
     IPL_THORNS,
     1,
     3,
     IPL_SETAC,
     5,
     5,
     IPL_TARGAC,
     4,
     12,
     IPL_INVCURS,
     13,
     0,
     IPL_TOHIT,
     0,
     0},
    {&empty_string,
     UITYPE_INVALID,
     0u,
     0u,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0,
     IPL_TOHIT,
     0,
     0}};

/* rdata */

ItemDataStruct AllItemsList[157] = {
    {IDROP_REGULAR,
     ICLASS_GOLD,
     ILOC_UNEQUIPABLE,
     168,
     11u,
     UITYPE_NONE,
     "Gold",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     64,
     1u,
     UITYPE_NONE,
     "Short Sword",
     NULL,
     2,
     20,
     2,
     6,
     0,
     0,
     18u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     50,
     50},
    {IDROP_NEVER,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     83,
     5u,
     UITYPE_NONE,
     "Buckler",
     NULL,
     2,
     10,
     0,
     0,
     3,
     3,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     50,
     50},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     66,
     4u,
     UITYPE_SPIKCLUB,
     "Club",
     NULL,
     1,
     20,
     1,
     6,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     20,
     20},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     118,
     3u,
     UITYPE_NONE,
     "Short Bow",
     NULL,
     1,
     30,
     1,
     4,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     100,
     100},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     109,
     10u,
     UITYPE_NONE,
     "Short Staff of Charged Bolt",
     NULL,
     1,
     25,
     2,
     4,
     0,
     0,
     0u,
     20u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_CBOLT,
     0,
     520,
     520},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     106,
     2u,
     UITYPE_CLEAVER,
     "Cleaver",
     NULL,
     10,
     10,
     4,
     24,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     2000,
     2000},
    {IDROP_NEVER,
     ICLASS_ARMOR,
     ILOC_HELM,
     78,
     7u,
     UITYPE_SKCROWN,
     "The Undead Crown",
     NULL,
     0,
     50,
     0,
     0,
     15,
     15,
     0u,
     0u,
     0u,
     ISPL_RNDSTEALLIFE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     10000,
     10000},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_RING,
     18,
     12u,
     UITYPE_INFRARING,
     "Empyrean Band",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     8000,
     8000},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     76,
     0u,
     UITYPE_NONE,
     "Magic Rock",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_AMULET,
     44,
     13u,
     UITYPE_OPTAMULET,
     "Optic Amulet",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     5000,
     5000},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_RING,
     10,
     12u,
     UITYPE_TRING,
     "Ring of Truth",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     126,
     0u,
     UITYPE_NONE,
     "Tavern Sign",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_ARMOR,
     ILOC_HELM,
     93,
     7u,
     UITYPE_HARCREST,
     "Harlequin Crest",
     NULL,
     0,
     15,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     15,
     20},
    {IDROP_NEVER,
     ICLASS_ARMOR,
     ILOC_HELM,
     85,
     7u,
     UITYPE_STEELVEIL,
     "Veil of Steel",
     NULL,
     0,
     60,
     0,
     0,
     18,
     18,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     17,
     0u,
     UITYPE_ELIXIR,
     "Golden Elixir",
     NULL,
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     140,
     0u,
     UITYPE_NONE,
     "Anvil of Fury",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     89,
     0u,
     UITYPE_NONE,
     "Black Mushroom",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     40,
     0u,
     UITYPE_NONE,
     "Brain",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     97,
     0u,
     UITYPE_NONE,
     "Fungal Tome",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     15,
     0u,
     UITYPE_ELIXIR,
     "Spectral Elixir",
     NULL,
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SPECELIX,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     25,
     0u,
     UITYPE_NONE,
     "Blood Stone",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     96,
     0u,
     UITYPE_MAPOFDOOM,
     "Map of the Stars",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_MAPOFDOOM,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_QUEST,
     ILOC_UNEQUIPABLE,
     19,
     0u,
     UITYPE_NONE,
     "Heart",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_EAR,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     32,
     0u,
     UITYPE_NONE,
     "Potion of Healing",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_HEAL,
     SPL_NULL,
     1,
     50,
     50},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     39,
     0u,
     UITYPE_NONE,
     "Potion of Mana",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_MANA,
     SPL_NULL,
     1,
     50,
     50},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Identify",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_IDENTIFY,
     1,
     200,
     200},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Town Portal",
     NULL,
     4,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_TOWN,
     1,
     200,
     200},
    {IDROP_NEVER,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     157,
     8u,
     UITYPE_ARMOFVAL,
     "Arkaine's Valor",
     NULL,
     0,
     40,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     35,
     0u,
     UITYPE_NONE,
     "Potion of Full Healing",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_FULLHEAL,
     SPL_NULL,
     1,
     150,
     150},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     0,
     0u,
     UITYPE_NONE,
     "Potion of Full Mana",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_FULLMANA,
     SPL_NULL,
     1,
     150,
     150},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     61,
     1u,
     UITYPE_GRISWOLD,
     "Griswold's Edge",
     NULL,
     8,
     50,
     4,
     12,
     0,
     0,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     750,
     750},
    {IDROP_NEVER,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     59,
     4u,
     UITYPE_LGTFORGE,
     "Lightforge",
     NULL,
     2,
     32,
     1,
     8,
     0,
     0,
     16u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_UNIQUE,
     SPL_NULL,
     0,
     200,
     200},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     155,
     0u,
     UITYPE_LAZSTAFF,
     "Staff of Lazarus",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Resurrect",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_RESURRECT,
     1,
     250,
     250},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_NEVER, ICLASS_NONE, ILOC_NONE, 0,  0u, UITYPE_NONE,
     NULL,        NULL,        0,         0,  0,  0,
     0,           0,           0u,        0u, 0u, ISPL_NONE,
     IMISC_NONE,  SPL_NULL,    0,         0,  0},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     91,
     7u,
     UITYPE_NONE,
     "Cap",
     "Cap",
     1,
     15,
     0,
     0,
     1,
     3,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     15,
     20},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     90,
     7u,
     UITYPE_SKULLCAP,
     "Skull Cap",
     "Cap",
     4,
     20,
     0,
     0,
     2,
     4,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     25,
     30},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     82,
     7u,
     UITYPE_HELM,
     "Helm",
     "Helm",
     8,
     30,
     0,
     0,
     4,
     6,
     25u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     40,
     70},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     75,
     7u,
     UITYPE_NONE,
     "Full Helm",
     "Helm",
     12,
     35,
     0,
     0,
     6,
     8,
     35u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     90,
     130},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     95,
     7u,
     UITYPE_CROWN,
     "Crown",
     "Crown",
     16,
     40,
     0,
     0,
     8,
     12,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     200,
     300},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_HELM,
     98,
     7u,
     UITYPE_GREATHELM,
     "Great Helm",
     "Helm",
     20,
     60,
     0,
     0,
     10,
     15,
     50u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     400,
     500},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     150,
     6u,
     UITYPE_CAPE,
     "Cape",
     "Cape",
     1,
     12,
     0,
     0,
     1,
     5,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     10,
     50},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     128,
     6u,
     UITYPE_RAGS,
     "Rags",
     "Rags",
     1,
     6,
     0,
     0,
     2,
     6,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     5,
     25},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     149,
     6u,
     UITYPE_CLOAK,
     "Cloak",
     "Cloak",
     2,
     18,
     0,
     0,
     3,
     7,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     40,
     70},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     137,
     6u,
     UITYPE_ROBE,
     "Robe",
     "Robe",
     3,
     24,
     0,
     0,
     4,
     7,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     75,
     125},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     129,
     6u,
     UITYPE_NONE,
     "Quilted Armor",
     "Armor",
     4,
     30,
     0,
     0,
     7,
     10,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     200,
     300},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     135,
     6u,
     UITYPE_LEATHARMOR,
     "Leather Armor",
     "Armor",
     6,
     35,
     0,
     0,
     10,
     13,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     300,
     400},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     127,
     6u,
     UITYPE_NONE,
     "Hard Leather Armor",
     "Armor",
     7,
     40,
     0,
     0,
     11,
     14,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     450,
     550},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     107,
     6u,
     UITYPE_STUDARMOR,
     "Studded Leather Armor",
     "Armor",
     9,
     45,
     0,
     0,
     15,
     17,
     20u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     700,
     800},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     154,
     8u,
     UITYPE_NONE,
     "Ring Mail",
     "Mail",
     11,
     50,
     0,
     0,
     17,
     20,
     25u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     900,
     1100},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     111,
     8u,
     UITYPE_CHAINMAIL,
     "Chain Mail",
     "Mail",
     13,
     55,
     0,
     0,
     18,
     22,
     30u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1250,
     1750},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     114,
     8u,
     UITYPE_NONE,
     "Scale Mail",
     "Mail",
     15,
     60,
     0,
     0,
     23,
     28,
     35u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     2300,
     2800},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     153,
     9u,
     UITYPE_BREASTPLATE,
     "Breast Plate",
     "Plate",
     16,
     80,
     0,
     0,
     20,
     24,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     2800,
     3200},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     136,
     8u,
     UITYPE_NONE,
     "Splint Mail",
     "Mail",
     17,
     65,
     0,
     0,
     30,
     35,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     3250,
     3750},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     103,
     9u,
     UITYPE_PLATEMAIL,
     "Plate Mail",
     "Plate",
     19,
     75,
     0,
     0,
     42,
     50,
     60u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     4600,
     5400},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     103,
     9u,
     UITYPE_NONE,
     "Field Plate",
     "Plate",
     21,
     80,
     0,
     0,
     40,
     45,
     65u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     5800,
     6200},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     152,
     9u,
     UITYPE_NONE,
     "Gothic Plate",
     "Plate",
     23,
     100,
     0,
     0,
     50,
     60,
     80u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     8000,
     10000},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ARMOR,
     151,
     9u,
     UITYPE_FULLPLATE,
     "Full Plate Mail",
     "Plate",
     25,
     90,
     0,
     0,
     60,
     75,
     90u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     6500,
     8000},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     83,
     5u,
     UITYPE_BUCKLER,
     "Buckler",
     "Shield",
     1,
     16,
     0,
     0,
     1,
     5,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     30,
     70},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     105,
     5u,
     UITYPE_SMALLSHIELD,
     "Small Shield",
     "Shield",
     5,
     24,
     0,
     0,
     3,
     8,
     25u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     90,
     130},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     147,
     5u,
     UITYPE_LARGESHIELD,
     "Large Shield",
     "Shield",
     9,
     32,
     0,
     0,
     5,
     10,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     200,
     300},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     113,
     5u,
     UITYPE_KITESHIELD,
     "Kite Shield",
     "Shield",
     14,
     40,
     0,
     0,
     8,
     15,
     50u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     400,
     700},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     132,
     5u,
     UITYPE_GOTHSHIELD,
     "Tower Shield",
     "Shield",
     20,
     50,
     0,
     0,
     12,
     20,
     60u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     850,
     1200},
    {IDROP_REGULAR,
     ICLASS_ARMOR,
     ILOC_ONEHAND,
     148,
     5u,
     UITYPE_GOTHSHIELD,
     "Gothic Shield",
     "Shield",
     23,
     60,
     0,
     0,
     14,
     18,
     80u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     2300,
     2700},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     32,
     0u,
     UITYPE_NONE,
     "Potion of Healing",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_HEAL,
     SPL_NULL,
     1,
     50,
     50},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     35,
     0u,
     UITYPE_NONE,
     "Potion of Full Healing",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_FULLHEAL,
     SPL_NULL,
     1,
     150,
     150},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     39,
     0u,
     UITYPE_NONE,
     "Potion of Mana",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_MANA,
     SPL_NULL,
     1,
     50,
     50},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     0,
     0u,
     UITYPE_NONE,
     "Potion of Full Mana",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_FULLMANA,
     SPL_NULL,
     1,
     150,
     150},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     37,
     0u,
     UITYPE_NONE,
     "Potion of Rejuvenation",
     NULL,
     3,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_REJUV,
     SPL_NULL,
     1,
     120,
     120},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     33,
     0u,
     UITYPE_NONE,
     "Potion of Full Rejuvenation",
     NULL,
     7,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_FULLREJUV,
     SPL_NULL,
     1,
     600,
     600},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     38,
     0u,
     UITYPE_NONE,
     "Elixir of Strength",
     NULL,
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_ELIXSTR,
     SPL_NULL,
     1,
     5000,
     5000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     34,
     0u,
     UITYPE_NONE,
     "Elixir of Magic",
     NULL,
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_ELIXMAG,
     SPL_NULL,
     1,
     5000,
     5000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     36,
     0u,
     UITYPE_NONE,
     "Elixir of Dexterity",
     NULL,
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_ELIXDEX,
     SPL_NULL,
     1,
     5000,
     5000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     31,
     0u,
     UITYPE_NONE,
     "Elixir of Vitality",
     NULL,
     20,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_ELIXVIT,
     SPL_NULL,
     1,
     5000,
     5000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Healing",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_HEAL,
     1,
     50,
     50},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Lightning",
     NULL,
     4,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_LIGHTNING,
     1,
     150,
     150},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Identify",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_IDENTIFY,
     1,
     100,
     100},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Resurrect",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_RESURRECT,
     1,
     250,
     250},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Fire Wall",
     NULL,
     4,
     0,
     0,
     0,
     0,
     0,
     0u,
     17u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_FIREWALL,
     1,
     400,
     400},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Inferno",
     NULL,
     1,
     0,
     0,
     0,
     0,
     0,
     0u,
     19u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_FLAME,
     1,
     100,
     100},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Town Portal",
     NULL,
     4,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_TOWN,
     1,
     200,
     200},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Flash",
     NULL,
     6,
     0,
     0,
     0,
     0,
     0,
     0u,
     21u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_FLASH,
     1,
     500,
     500},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Infravision",
     NULL,
     8,
     0,
     0,
     0,
     0,
     0,
     0u,
     23u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_INFRA,
     1,
     600,
     600},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Phasing",
     NULL,
     6,
     0,
     0,
     0,
     0,
     0,
     0u,
     25u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_RNDTELEPORT,
     1,
     200,
     200},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Mana Shield",
     NULL,
     8,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_MANASHIELD,
     1,
     1200,
     1200},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Flame Wave",
     NULL,
     10,
     0,
     0,
     0,
     0,
     0,
     0u,
     29u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_WAVE,
     1,
     650,
     650},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Fireball",
     NULL,
     8,
     0,
     0,
     0,
     0,
     0,
     0u,
     31u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_FIREBALL,
     1,
     300,
     300},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Stone Curse",
     NULL,
     6,
     0,
     0,
     0,
     0,
     0,
     0u,
     33u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_STONE,
     1,
     800,
     800},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Chain Lightning",
     NULL,
     10,
     0,
     0,
     0,
     0,
     0,
     0u,
     35u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_CHAIN,
     1,
     750,
     750},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Guardian",
     NULL,
     12,
     0,
     0,
     0,
     0,
     0,
     0u,
     47u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_GUARDIAN,
     1,
     950,
     950},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Non Item",
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Nova",
     NULL,
     14,
     0,
     0,
     0,
     0,
     0,
     0u,
     57u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_NOVA,
     1,
     1300,
     1300},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Golem",
     NULL,
     10,
     0,
     0,
     0,
     0,
     0,
     0u,
     51u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_GOLEM,
     1,
     1100,
     1100},
    {IDROP_NEVER,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of None",
     NULL,
     99,
     0,
     0,
     0,
     0,
     0,
     0u,
     61u,
     0u,
     ISPL_NONE,
     IMISC_SCROLLT,
     SPL_NULL,
     1,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Teleport",
     NULL,
     14,
     0,
     0,
     0,
     0,
     0,
     0u,
     81u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_TELEPORT,
     1,
     3000,
     3000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     1,
     0u,
     UITYPE_NONE,
     "Scroll of Apocalypse",
     NULL,
     22,
     0,
     0,
     0,
     0,
     0,
     0u,
     117u,
     0u,
     ISPL_NONE,
     IMISC_SCROLL,
     SPL_APOCA,
     1,
     2000,
     2000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     88,
     0u,
     UITYPE_NONE,
     "Book of ",
     NULL,
     2,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_BOOK,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     88,
     0u,
     UITYPE_NONE,
     "Book of ",
     NULL,
     8,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_BOOK,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     88,
     0u,
     UITYPE_NONE,
     "Book of ",
     NULL,
     14,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_BOOK,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_UNEQUIPABLE,
     88,
     0u,
     UITYPE_NONE,
     "Book of ",
     NULL,
     20,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_BOOK,
     SPL_NULL,
     1,
     0,
     0},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     51,
     1u,
     UITYPE_DAGGER,
     "Dagger",
     "Dagger",
     1,
     16,
     1,
     4,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     60,
     60},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     64,
     1u,
     UITYPE_NONE,
     "Short Sword",
     "Sword",
     1,
     24,
     2,
     6,
     0,
     0,
     18u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     120,
     120},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     62,
     1u,
     UITYPE_FALCHION,
     "Falchion",
     "Sword",
     2,
     20,
     4,
     8,
     0,
     0,
     30u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     250,
     250},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     72,
     1u,
     UITYPE_SCIMITAR,
     "Scimitar",
     "Sword",
     4,
     28,
     3,
     7,
     0,
     0,
     23u,
     0u,
     23u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     200,
     200},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     65,
     1u,
     UITYPE_CLAYMORE,
     "Claymore",
     "Sword",
     5,
     36,
     1,
     12,
     0,
     0,
     35u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     450,
     450},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     56,
     1u,
     UITYPE_NONE,
     "Blade",
     "Blade",
     4,
     30,
     3,
     8,
     0,
     0,
     25u,
     0u,
     30u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     280,
     280},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     67,
     1u,
     UITYPE_SABRE,
     "Sabre",
     "Sabre",
     1,
     45,
     1,
     8,
     0,
     0,
     17u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     170,
     170},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     60,
     1u,
     UITYPE_LONGSWR,
     "Long Sword",
     "Sword",
     6,
     40,
     2,
     10,
     0,
     0,
     30u,
     0u,
     30u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     350,
     350},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     61,
     1u,
     UITYPE_BROADSWR,
     "Broad Sword",
     "Sword",
     8,
     50,
     4,
     12,
     0,
     0,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     750,
     750},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     57,
     1u,
     UITYPE_BASTARDSWR,
     "Bastard Sword",
     "Sword",
     10,
     60,
     6,
     15,
     0,
     0,
     50u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     110,
     1u,
     UITYPE_TWOHANDSWR,
     "Two-Handed Sword",
     "Sword",
     14,
     75,
     8,
     16,
     0,
     0,
     65u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1800,
     1800},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     134,
     1u,
     UITYPE_GREATSWR,
     "Great Sword",
     "Sword",
     17,
     100,
     10,
     20,
     0,
     0,
     75u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     3000,
     3000},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     112,
     2u,
     UITYPE_SMALLAXE,
     "Small Axe",
     "Axe",
     2,
     24,
     2,
     10,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     150,
     150},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     144,
     2u,
     UITYPE_NONE,
     "Axe",
     "Axe",
     4,
     32,
     4,
     12,
     0,
     0,
     22u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     450,
     450},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     142,
     2u,
     UITYPE_LARGEAXE,
     "Large Axe",
     "Axe",
     6,
     40,
     6,
     16,
     0,
     0,
     30u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     750,
     750},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     141,
     2u,
     UITYPE_BROADAXE,
     "Broad Axe",
     "Axe",
     8,
     50,
     8,
     20,
     0,
     0,
     50u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     101,
     2u,
     UITYPE_BATTLEAXE,
     "Battle Axe",
     "Axe",
     10,
     60,
     10,
     25,
     0,
     0,
     65u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1500,
     1500},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     143,
     2u,
     UITYPE_GREATAXE,
     "Great Axe",
     "Axe",
     12,
     75,
     12,
     30,
     0,
     0,
     80u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     2500,
     2500},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     59,
     4u,
     UITYPE_MACE,
     "Mace",
     "Mace",
     2,
     32,
     1,
     8,
     0,
     0,
     16u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     200,
     200},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     63,
     4u,
     UITYPE_MORNSTAR,
     "Morning Star",
     "Mace",
     3,
     40,
     1,
     10,
     0,
     0,
     26u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     300,
     300},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     121,
     4u,
     UITYPE_WARHAMMER,
     "War Hammer",
     "Hammer",
     5,
     50,
     5,
     9,
     0,
     0,
     40u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     600,
     600},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     70,
     4u,
     UITYPE_SPIKCLUB,
     "Spiked Club",
     "Club",
     4,
     20,
     3,
     6,
     0,
     0,
     18u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     225,
     225},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     66,
     4u,
     UITYPE_SPIKCLUB,
     "Club",
     "Club",
     1,
     20,
     1,
     6,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     20,
     20},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_ONEHAND,
     131,
     4u,
     UITYPE_FLAIL,
     "Flail",
     "Flail",
     7,
     36,
     2,
     12,
     0,
     0,
     30u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     500,
     500},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     122,
     4u,
     UITYPE_MAUL,
     "Maul",
     "Maul",
     10,
     50,
     6,
     20,
     0,
     0,
     55u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     900,
     900},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     118,
     3u,
     UITYPE_SHORTBOW,
     "Short Bow",
     "Bow",
     1,
     30,
     1,
     4,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     100,
     100},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     102,
     3u,
     UITYPE_HUNTBOW,
     "Hunter's Bow",
     "Bow",
     3,
     40,
     2,
     5,
     0,
     0,
     20u,
     0u,
     35u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     350,
     350},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     102,
     3u,
     UITYPE_LONGBOW,
     "Long Bow",
     "Bow",
     5,
     35,
     1,
     6,
     0,
     0,
     25u,
     0u,
     30u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     250,
     250},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     133,
     3u,
     UITYPE_COMPBOW,
     "Composite Bow",
     "Bow",
     7,
     45,
     3,
     6,
     0,
     0,
     25u,
     0u,
     40u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     600,
     600},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     167,
     3u,
     UITYPE_NONE,
     "Short Battle Bow",
     "Bow",
     9,
     45,
     3,
     7,
     0,
     0,
     30u,
     0u,
     50u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     750,
     750},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     119,
     3u,
     UITYPE_BATTLEBOW,
     "Long Battle Bow",
     "Bow",
     11,
     50,
     1,
     10,
     0,
     0,
     30u,
     0u,
     60u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     165,
     3u,
     UITYPE_NONE,
     "Short War Bow",
     "Bow",
     15,
     55,
     4,
     8,
     0,
     0,
     35u,
     0u,
     70u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     1500,
     1500},
    {IDROP_DOUBLE,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     119,
     3u,
     UITYPE_WARBOW,
     "Long War Bow",
     "Bow",
     19,
     60,
     1,
     14,
     0,
     0,
     45u,
     0u,
     80u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     2000,
     2000},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     109,
     10u,
     UITYPE_SHORTSTAFF,
     "Short Staff",
     "Staff",
     1,
     25,
     2,
     4,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_NULL,
     0,
     30,
     30},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     123,
     10u,
     UITYPE_LONGSTAFF,
     "Long Staff",
     "Staff",
     4,
     35,
     4,
     8,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_NULL,
     0,
     100,
     100},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     166,
     10u,
     UITYPE_COMPSTAFF,
     "Composite Staff",
     "Staff",
     6,
     45,
     5,
     10,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_NULL,
     0,
     500,
     500},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     109,
     10u,
     UITYPE_QUARSTAFF,
     "Quarter Staff",
     "Staff",
     9,
     55,
     6,
     12,
     0,
     0,
     20u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_WEAPON,
     ILOC_TWOHAND,
     124,
     10u,
     UITYPE_WARSTAFF,
     "War Staff",
     "Staff",
     12,
     75,
     8,
     16,
     0,
     0,
     30u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_STAFF,
     SPL_NULL,
     0,
     1500,
     1500},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_RING,
     12,
     12u,
     UITYPE_RING,
     "Ring",
     "Ring",
     5,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_RING,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_RING,
     12,
     12u,
     UITYPE_RING,
     "Ring",
     "Ring",
     10,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_RING,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_RING,
     12,
     12u,
     UITYPE_RING,
     "Ring",
     "Ring",
     15,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_RING,
     SPL_NULL,
     0,
     1000,
     1000},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_AMULET,
     45,
     13u,
     UITYPE_AMULET,
     "Amulet",
     "Amulet",
     8,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_AMULET,
     SPL_NULL,
     0,
     1200,
     1200},
    {IDROP_REGULAR,
     ICLASS_MISC,
     ILOC_AMULET,
     45,
     13u,
     UITYPE_AMULET,
     "Amulet",
     "Amulet",
     16,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_AMULET,
     SPL_NULL,
     0,
     1200,
     1200},
    {IDROP_NEVER,
     ICLASS_NONE,
     ILOC_INVALID,
     0,
     0u,
     UITYPE_NONE,
     NULL,
     NULL,
     0,
     0,
     0,
     0,
     0,
     0,
     0u,
     0u,
     0u,
     ISPL_NONE,
     IMISC_NONE,
     SPL_NULL,
     0,
     0,
     0}};
unsigned char ItemCAnimTbl[169] = {
    20, 16, 16, 16, 4,  4,  4,  12, 12, 12, 12, 12, 12, 12, 12, 21, 21, 25, 12,
    28, 28, 28, 0,  0,  0,  32, 0,  0,  0,  24, 24, 26, 2,  25, 22, 23, 24, 25,
    27, 27, 29, 0,  0,  0,  12, 12, 12, 12, 12, 0,  8,  8,  0,  8,  8,  8,  8,
    8,  8,  6,  8,  8,  8,  6,  8,  8,  6,  8,  8,  6,  6,  6,  8,  8,  8,  5,
    9,  13, 13, 13, 5,  5,  5,  15, 5,  5,  18, 18, 18, 30, 5,  5,  14, 5,  14,
    13, 16, 18, 5,  5,  7,  1,  3,  17, 1,  15, 10, 14, 3,  11, 8,  0,  1,  7,
    0,  7,  15, 7,  3,  3,  3,  6,  6,  11, 11, 11, 31, 14, 14, 14, 6,  6,  7,
    3,  8,  14, 0,  14, 14, 0,  33, 1,  1,  1,  1,  1,  7,  7,  7,  14, 14, 17,
    17, 17, 0,  34, 1,  0,  3,  17, 8,  8,  6,  1,  3,  3,  11, 3,  4};
char *ItemDropStrs[35] = {
    "Armor2",   "Axe",      "FBttle",   "Bow",      "GoldFlip", "Helmut",
    "Mace",     "Shield",   "SwrdFlip", "Rock",     "Cleaver",  "Staff",
    "Ring",     "CrownF",   "LArmor",   "WShield",  "Scroll",   "FPlateAr",
    "FBook",    "Food",     "FBttleBB", "FBttleDY", "FBttleOR", "FBttleBR",
    "FBttleBL", "FBttleBY", "FBttleWH", "FBttleDB", "FEar",     "FBrain",
    "FMush",    "Innsign",  "Bldstn",   "Fanvil",   "FLazStaf"};
unsigned char ItemAnimLs[35] = {15u, 13u, 16u, 13u, 10u, 13u, 13u, 13u, 13u,
                                10u, 13u, 13u, 13u, 13u, 13u, 13u, 13u, 13u,
                                13u, 1u,  16u, 16u, 16u, 16u, 16u, 16u, 16u,
                                16u, 13u, 12u, 12u, 13u, 13u, 13u, 8u};
int ItemDropSnds[35] = {
    IS_FHARM, IS_FAXE,  IS_FPOT,  IS_FBOW,  IS_GOLD,  IS_FCAP,  IS_FSWOR,
    IS_FSHLD, IS_FSWOR, IS_FROCK, IS_FAXE,  IS_FSTAF, IS_FRING, IS_FCAP,
    IS_FLARM, IS_FSHLD, IS_FSCRL, IS_FHARM, IS_FBOOK, IS_FLARM, IS_FPOT,
    IS_FPOT,  IS_FPOT,  IS_FPOT,  IS_FPOT,  IS_FPOT,  IS_FPOT,  IS_FPOT,
    IS_FBODY, IS_FBODY, IS_FMUSH, IS_ISIGN, IS_FBLST, IS_FANVL, IS_FSTAF};
int ItemInvSnds[35] = {
    IS_IHARM,  IS_IAXE,   IS_IPOT,   IS_IBOW,  IS_GOLD,  IS_ICAP,  IS_ISWORD,
    IS_ISHIEL, IS_ISWORD, IS_IROCK,  IS_IAXE,  IS_ISTAF, IS_IRING, IS_ICAP,
    IS_ILARM,  IS_ISHIEL, IS_ISCROL, IS_IHARM, IS_IBOOK, IS_IHARM, IS_IPOT,
    IS_IPOT,   IS_IPOT,   IS_IPOT,   IS_IPOT,  IS_IPOT,  IS_IPOT,  IS_IPOT,
    IS_IBODY,  IS_IBODY,  IS_IMUSH,  IS_ISIGN, IS_IBLST, IS_IANVL, IS_ISTAF};
int idoppely = 16; // weak
int premiumlvladd[6] = {-1, -1, 0, 0, 1, 2};

//----- (0041F096) --------------------------------------------------------
void __cdecl InitItemGFX() {
  signed int v0;    // esi
  char arglist[64]; // [esp+4h] [ebp-40h]

  v0 = 0;
  do {
    sprintf(arglist, "Items\\%s.CEL", ItemDropStrs[v0]);
    Item2Frm[v0] = (int)LoadFileInMem(arglist, 0);
    ++v0;
  } while (v0 < 35);
  memset(UniqueItemFlag, 0, 0x200u);
}

//----- (0041F0E8) --------------------------------------------------------
bool __fastcall ItemPlace(int x, int y) {
  int v2;      // ecx
  int v3;      // eax
  bool result; // al

  v2 = x;
  v3 = v2 * 112 + y;
  if (dMonster[0][v3] || dPlayer[v2][y] || dItem[v2][y] || dObject[v2][y] ||
      dFlags[v2][y] & 8)
    result = 0;
  else
    result = nSolidTable[dPiece[0][v3]] == 0;
  return result;
}

//----- (0041F13A) --------------------------------------------------------
void __cdecl AddInitItems() {
  int i;  // eax
  int ii; // ebx
  int xx; // esi
  int yy; // eax
  int j;  // eax

  i = random(11, 3) + 3;
  if (i > 0) {
    do {
      ii = itemavail[0];
      itemactive[numitems] = itemavail[0];
      itemavail[0] = itemavail[-numitems + 126];
      do {
        xx = random(12, 80) + 16;
        yy = random(12, 80) + 16;
      } while (!ItemPlace(xx, yy));
      item[ii]._ix = xx;
      item[ii]._iy = yy;
      dItem[xx][yy] = ii + 1;
      j = GetRndSeed();
      item[ii]._iSeed = j;
      SetRndSeed(j);
      if (random(12, 2))
        GetItemAttrs(ii, IDI_HEAL, currlevel);
      else
        GetItemAttrs(ii, IDI_MANA, currlevel);
      item[ii]._iCreateInfo = currlevel + -32768;
      SetupItem(ii);
      item[ii]._iAnimFlag = 0;
      item[ii]._iAnimFrame = item[ii]._iAnimLen;
      item[ii]._iSelFlag = 1;
      DeltaAddItem(ii);
      ++numitems;
      --i;
    } while (i);
  }
}

//----- (0041F24E) --------------------------------------------------------
void __cdecl InitItems() {
  int *v0; // eax
  int v1;  // edx

  GetItemAttrs(0, IDI_GOLD, 1);
  numitems = 0;
  qmemcpy(&golditem, item, sizeof(golditem));
  golditem._iStatFlag = 1;
  v0 = &item[0]._ix;
  do {
    *(v0 - 1) = 0;
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    *((_BYTE *)v0 + 36) = 0;
    v0[11] = 0;
    v0[10] = 0;
    v0 += 92;
  } while ((signed int)v0 < (signed int)&item[128]._ix);
  v1 = 0;
  memset(itemactive, 0, sizeof(itemactive));
  do {
    itemavail[v1] = v1;
    ++v1;
  } while (v1 < 127);
  if (!setlevel) {
    GetRndSeed();
    if (QuestStatus(0))
      SpawnRock();
    if (QuestStatus(10))
      SpawnQuestItem(16, 2 * setpc_x + 27, 2 * setpc_y + 27, 0, 1);
    if (currlevel > 0u && currlevel < 0x10u)
      AddInitItems();
  }
  uitemflag = 0;
}
// 5CF31D: using guessed type char setlevel;

//----- (0041F320) --------------------------------------------------------
void __fastcall CalcPlrItemVals(int p, bool Loadgfx) {
  int v2;         // eax
  int v3;         // ecx
  int v4;         // ebx
  int v5;         // esi
  int *v6;        // edi
  int v7;         // edx
  int v8;         // ecx
  int v9;         // eax
  int v10;        // edx
  int v11;        // eax
  int *v12;       // ecx
  int *v13;       // eax
  int v14;        // eax
  int v15;        // eax
  signed int v16; // ecx
  bool v17;       // zf
  signed int v18; // eax
  signed int v19; // ecx
  signed int v20; // ebx
  char v21;       // dl
  int v22;        // eax
  int v23;        // ecx
  int v24;        // eax
  int v25;        // eax
  int v26;        // edx
  int v27;        // edx
  int v28;        // eax
  int v29;        // ebx
  int v30;        // ecx
  int v31;        // eax
  int v32;        // eax
  int v33;        // ecx
  int i;          // edx
  int v35;        // eax
  signed int v36; // [esp-4h] [ebp-84h]
  __int64 v37;    // [esp+Ch] [ebp-74h]
  BOOL v38;       // [esp+14h] [ebp-6Ch]
  signed int v39; // [esp+18h] [ebp-68h]
  int v40;        // [esp+1Ch] [ebp-64h]
  int v41;        // [esp+20h] [ebp-60h]
  int v42;        // [esp+24h] [ebp-5Ch]
  int v43;        // [esp+28h] [ebp-58h]
  int v44;        // [esp+2Ch] [ebp-54h]
  int v45;        // [esp+30h] [ebp-50h]
  int v46;        // [esp+34h] [ebp-4Ch]
  signed int v47; // [esp+38h] [ebp-48h]
  signed int v48; // [esp+3Ch] [ebp-44h]
  signed int v49; // [esp+40h] [ebp-40h]
  int v50;        // [esp+44h] [ebp-3Ch]
  char v51;       // [esp+48h] [ebp-38h]
  int v52;        // [esp+4Ch] [ebp-34h]
  int v53;        // [esp+50h] [ebp-30h]
  int v54;        // [esp+54h] [ebp-2Ch]
  int v55;        // [esp+58h] [ebp-28h]
  int v56;        // [esp+5Ch] [ebp-24h]
  int v57;        // [esp+60h] [ebp-20h]
  int v58;        // [esp+64h] [ebp-1Ch]
  int v59;        // [esp+68h] [ebp-18h]
  int v60;        // [esp+6Ch] [ebp-14h]
  int v61;        // [esp+70h] [ebp-10h]
  int arglist;    // [esp+74h] [ebp-Ch]
  int v63;        // [esp+78h] [ebp-8h]
  int v64;        // [esp+78h] [ebp-8h]
  signed int r;   // [esp+7Ch] [ebp-4h]

  v2 = 0;
  arglist = p;
  v3 = 0;
  v4 = 0;
  v5 = arglist;
  v38 = Loadgfx;
  v58 = 0;
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v59 = 0;
  v53 = 0;
  v60 = 0;
  v52 = 0;
  v61 = 0;
  v37 = (__int64)0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  v54 = 0;
  r = 10;
  v46 = 0;
  v63 = 0;
  v51 = 0;
  v50 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v42 = 0;
  v6 = &plr[arglist].InvBody[0]._iStatFlag;
  v39 = 7;
  do {
    if (*(v6 - 87) != -1 && *v6) {
      v3 += *(v6 - 38);
      v58 += *(v6 - 36);
      v2 += *(v6 - 37);
      v7 = *(v6 - 33);
      v40 = v3;
      v41 = v2;
      if (v7)
        v37 |= (__int64)1 << ((unsigned char)v7 - 1);
      if (!*((_BYTE *)v6 - 296) || *(v6 - 75)) {
        v57 += *(v6 - 28);
        v56 += *(v6 - 27);
        v8 = *(v6 - 26);
        if (v8) {
          v9 = v8 * *(v6 - 36) / 100;
          if (!v9)
            v9 = 1;
          v55 += v9;
          v2 = v41;
        }
        v4 += *(v6 - 16);
        v59 |= *(v6 - 35);
        v53 += *(v6 - 25);
        v60 += *(v6 - 24);
        v52 += *(v6 - 23);
        v61 += *(v6 - 22);
        v49 += *(v6 - 21);
        v48 += *(v6 - 20);
        v47 += *(v6 - 19);
        v54 += *(v6 - 15);
        r += *(v6 - 14);
        v46 += *(v6 - 17);
        v63 += *(v6 - 18);
        v51 += *((_BYTE *)v6 - 52);
        v50 += *(v6 - 7);
        v45 += *(v6 - 11);
        v44 += *(v6 - 10);
        v43 += *(v6 - 9);
        v42 += *(v6 - 8);
        v3 = v40;
      }
    }
    v6 += 92;
    --v39;
  } while (v39);
  if (!v3 && !v2) {
    v2 = 1;
    v3 = 1;
    if (plr[v5].InvBody[4]._itype == ITYPE_SHIELD &&
        plr[v5].InvBody[4]._iStatFlag)
      v2 = 3;
    if (plr[v5].InvBody[5]._itype == ITYPE_SHIELD &&
        plr[v5].InvBody[5]._iStatFlag)
      v2 = 3;
  }
  plr[v5]._pIMaxDam = v2;
  plr[v5]._pIAC = v58;
  plr[v5]._pIBonusDam = v57;
  plr[v5]._pIBonusToHit = v56;
  plr[v5]._pIBonusAC = v55;
  plr[v5]._pIFlags = v59;
  plr[v5]._pIGetHit = v54;
  plr[v5]._pIMinDam = v3;
  plr[v5]._pIBonusDamMod = v4;
  if (r < 2)
    r = 2;
  if (r > 15)
    r = 15;
  if (plr[v5]._pLightRad != r && arglist == myplr) {
    ChangeLightRadius(plr[v5]._plid, r);
    v10 = 10;
    if (r >= 10)
      v10 = r;
    ChangeVisionRadius(plr[v5]._pvid, v10);
    plr[v5]._pLightRad = r;
  }
  plr[v5]._pStrength = v53 + plr[v5]._pBaseStr;
  v11 = myplr;
  v12 = &plr[myplr]._pStrength;
  if (*v12 <= 0)
    *v12 = 0;
  plr[v5]._pMagic = v60 + plr[v5]._pBaseMag;
  if (plr[v11]._pMagic <= 0)
    plr[v11]._pMagic = 0;
  plr[v5]._pDexterity = v52 + plr[v5]._pBaseDex;
  if (plr[v11]._pDexterity <= 0)
    plr[v11]._pDexterity = 0;
  v13 = &plr[v11]._pVitality;
  plr[v5]._pVitality = v61 + plr[v5]._pBaseVit;
  if (*v13 <= 0)
    *v13 = 0;
  v14 = plr[v5]._pLevel;
  if (_LOBYTE(plr[v5]._pClass) == 1) {
    v15 = (plr[v5]._pStrength + plr[v5]._pDexterity) * v14;
    v16 = 200;
  } else {
    v15 = plr[v5]._pStrength * v14;
    v16 = 100;
  }
  v17 = _LOBYTE(plr[v5]._pRSplType) == 3;
  plr[v5]._pISpells[0] = v37;
  plr[v5]._pISpells[1] = HIDWORD(v37);
  plr[v5]._pDamageMod = v15 / v16;
  if (v17 && !(v37 & ((__int64)1 << (_LOBYTE(plr[v5]._pRSpell) - 1)))) {
    plr[v5]._pRSpell = -1;
    _LOBYTE(plr[v5]._pRSplType) = 4;
    drawpanflag = 255;
  }
  plr[v5]._pISplLvlAdd = v51;
  plr[v5]._pIEnAc = v50;
  if (v59 >= 0) {
    v19 = v49;
    v20 = v48;
    v18 = v47;
  } else {
    v18 = 0;
    v19 = 0;
    v20 = 0;
  }
  if (v18 > 75)
    _LOBYTE(v18) = 75;
  plr[v5]._pMagResist = v18;
  if (v19 > 75)
    _LOBYTE(v19) = 75;
  plr[v5]._pFireResist = v19;
  if (v20 > 75)
    _LOBYTE(v20) = 75;
  v21 = plr[v5]._pClass;
  v22 = v61;
  plr[v5]._pLghtResist = v20;
  if (!v21)
    v22 = 2 * v61;
  if (v21 == 1)
    v22 += v22 >> 1;
  v23 = (v22 << 6) + v46;
  v24 = v60;
  if (v21 == 2)
    v24 = 2 * v60;
  if (v21 == 1)
    v24 += v24 >> 1;
  v64 = (v24 << 6) + v63;
  v25 = v23 + plr[v5]._pHPBase;
  v26 = v23 + plr[v5]._pMaxHPBase;
  plr[v5]._pHitPoints = v25;
  v17 = arglist == myplr;
  plr[v5]._pMaxHP = v26;
  if (v17 && (signed int)(v25 & 0xFFFFFFC0) <= 0)
    SetPlayerHitPoints(arglist, 0);
  plr[v5]._pMana = v64 + plr[v5]._pManaBase;
  plr[v5]._pMaxMana = v64 + plr[v5]._pMaxManaBase;
  plr[v5]._pIFMinDam = v45;
  plr[v5]._pIFMaxDam = v44;
  plr[v5]._pILMinDam = v43;
  plr[v5]._pILMaxDam = v42;
  if (v59 & 1)
    plr[v5]._pInfraFlag = 1;
  else
    plr[v5]._pInfraFlag = 0;
  v27 = plr[v5].InvBody[4]._itype;
  plr[v5]._pBlockFlag = 0;
  v28 = 0;
  plr[v5]._pwtype = 0;
  if (v27 != ITYPE_NONE && plr[v5].InvBody[4]._iClass == 1 &&
      plr[v5].InvBody[4]._iStatFlag)
    v28 = v27;
  v29 = plr[v5].InvBody[5]._itype;
  if (v29 != ITYPE_NONE && plr[v5].InvBody[5]._iClass == 1 &&
      plr[v5].InvBody[5]._iStatFlag)
    v28 = plr[v5].InvBody[5]._itype;
  switch (v28) {
  case ITYPE_SWORD:
    v36 = 2;
    goto LABEL_86;
  case ITYPE_AXE:
    v36 = 5;
    goto LABEL_86;
  case ITYPE_BOW:
    plr[v5]._pwtype = 1;
    v36 = 4;
    goto LABEL_86;
  case ITYPE_MACE:
    v36 = 6;
    goto LABEL_86;
  case ITYPE_STAFF:
    v36 = 8;
  LABEL_86:
    v28 = v36;
    break;
  }
  if (v27 == ITYPE_SHIELD && plr[v5].InvBody[4]._iStatFlag) {
    plr[v5]._pBlockFlag = 1;
    ++v28;
  }
  if (v29 == ITYPE_SHIELD && plr[v5].InvBody[5]._iStatFlag) {
    plr[v5]._pBlockFlag = 1;
    ++v28;
  }
  v30 = plr[v5].InvBody[6]._itype;
  if (v30 == ITYPE_MARMOR && plr[v5].InvBody[6]._iStatFlag)
    v28 += 16;
  if (v30 == ITYPE_HARMOR && plr[v5].InvBody[6]._iStatFlag)
    v28 += 32;
  if (plr[v5]._pgfxnum != v28 && v38) {
    plr[v5]._pgfxnum = v28;
    plr[v5]._pGFXLoad = 0;
    LoadPlrGFX(arglist, 1);
    SetPlrAnims(arglist);
    v31 = plr[0]._pNAnim[plr[v5]._pdir + 5430 * arglist];
    plr[v5]._pAnimFrame = 1;
    plr[v5]._pAnimData = v31;
    plr[v5]._pAnimLen = plr[v5]._pNFrames;
    v32 = plr[v5]._pNWidth;
    plr[v5]._pAnimWidth = v32;
    plr[v5]._pAnimCnt = 0;
    plr[v5]._pAnimDelay = 3;
    plr[v5]._pAnimWidth2 = (v32 - 64) >> 1;
  } else {
    plr[v5]._pgfxnum = v28;
  }
  v33 = nummissiles;
  for (i = 0; i < v33; ++i) {
    v35 = missileactive[i];
    if (missile[v35]._mitype == 13 && missile[v35]._misource == arglist) {
      missile[v35]._miVar1 = plr[v5]._pHitPoints;
      missile[v35]._miVar2 = plr[v5]._pHPBase;
    }
  }
  drawmanaflag = 1;
  drawhpflag = 1;
}
// 52571C: using guessed type int drawpanflag;

//----- (0041F953) --------------------------------------------------------
void __fastcall CalcPlrScrolls(int p) {
  int v1;            // esi
  int v2;            // eax
  int *v3;           // edi
  int v4;            // ebx
  signed __int64 v5; // rax
  int *v6;           // edi
  signed int v7;     // ebx
  signed __int64 v8; // rax
  __int64 v9;        // rax

  v1 = p;
  v2 = plr[p]._pNumInv;
  plr[v1]._pScrlSpells[0] = 0;
  plr[v1]._pScrlSpells[1] = 0;
  if (v2 > 0) {
    v3 = &plr[v1].InvList[0]._iMiscId;
    v4 = v2;
    do {
      if (*(v3 - 53) != -1 && (*v3 == IMISC_SCROLL || *v3 == IMISC_SCROLLT) &&
          v3[34]) {
        v5 = (__int64)1 << (*((_BYTE *)v3 + 4) - 1);
        plr[v1]._pScrlSpells[0] |= v5;
        plr[v1]._pScrlSpells[1] |= HIDWORD(v5);
      }
      v3 += 92;
      --v4;
    } while (v4);
  }
  v6 = &plr[v1].SpdList[0]._iMiscId;
  v7 = 8;
  do {
    if (*(v6 - 53) != -1 && (*v6 == IMISC_SCROLL || *v6 == IMISC_SCROLLT) &&
        v6[34]) {
      v8 = (__int64)1 << (*((_BYTE *)v6 + 4) - 1);
      plr[v1]._pScrlSpells[0] |= v8;
      plr[v1]._pScrlSpells[1] |= HIDWORD(v8);
    }
    v6 += 92;
    --v7;
  } while (v7);
  if (_LOBYTE(plr[v1]._pRSplType) == 2) {
    v9 = 1 << (_LOBYTE(plr[v1]._pRSpell) - 1);
    if (!(plr[v1]._pScrlSpells[1] & HIDWORD(v9) |
          plr[v1]._pScrlSpells[0] & (unsigned int)v9)) {
      plr[v1]._pRSpell = -1;
      _LOBYTE(plr[v1]._pRSplType) = 4;
      drawpanflag = 255;
    }
  }
}
// 52571C: using guessed type int drawpanflag;

//----- (0041FA4A) --------------------------------------------------------
void __fastcall CalcPlrStaff(int pnum) {
  int v1;            // esi
  bool v2;           // zf
  signed __int64 v3; // rax

  v1 = pnum;
  v2 = plr[pnum].InvBody[4]._itype == ITYPE_NONE;
  plr[v1]._pISpells[0] = 0;
  plr[v1]._pISpells[1] = 0;
  if (!v2 && plr[v1].InvBody[4]._iStatFlag &&
      plr[v1].InvBody[4]._iCharges > 0) {
    v3 = (__int64)1 << (_LOBYTE(plr[v1].InvBody[4]._iSpell) - 1);
    plr[v1]._pISpells[0] = v3;
    plr[v1]._pISpells[1] = HIDWORD(v3);
  }
}

//----- (0041FA97) --------------------------------------------------------
void __fastcall CalcSelfItems(int pnum) {
  PlayerStruct *v1; // ecx
  int v2;           // edx
  int v3;           // esi
  int v4;           // edi
  int *v5;          // eax
  signed int v6;    // ebx
  bool v7;          // zf
  char *v8;         // eax
  signed int v9;    // [esp+Ch] [ebp-10h]
  signed int v10;   // [esp+10h] [ebp-Ch]
  int v11;          // [esp+14h] [ebp-8h]
  signed int v12;   // [esp+18h] [ebp-4h]

  v1 = &plr[pnum];
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = &v1->InvBody[0]._iStatFlag;
  v6 = 7;
  do {
    if (*(v5 - 87) != -1) {
      v7 = *(v5 - 75) == 0;
      *v5 = 1;
      if (!v7) {
        v2 += *(v5 - 25);
        v3 += *(v5 - 24);
        v4 += *(v5 - 23);
      }
    }
    v5 += 92;
    --v6;
  } while (v6);
  v11 = v4;
  do {
    v9 = 0;
    v8 = &v1->InvBody[0]._iMinStr;
    v10 = 7;
    do {
      if (*((_DWORD *)v8 - 86) != -1 && *((_DWORD *)v8 + 1)) {
        v12 = 1;
        if (v2 + v1->_pBaseStr < *v8)
          v12 = 0;
        if (v3 + v1->_pBaseMag < (unsigned char)v8[1])
          v12 = 0;
        if (v11 + v1->_pBaseDex < v8[2])
          v12 = 0;
        if (!v12) {
          v7 = *((_DWORD *)v8 - 74) == 0;
          v9 = 1;
          *((_DWORD *)v8 + 1) = 0;
          if (!v7) {
            v2 -= *((_DWORD *)v8 - 24);
            v3 -= *((_DWORD *)v8 - 23);
            v11 -= *((_DWORD *)v8 - 22);
          }
        }
      }
      v8 += 368;
      --v10;
    } while (v10);
  } while (v9);
}

//----- (0041FB91) --------------------------------------------------------
void __fastcall CalcPlrItemMin(int pnum) {
  PlayerStruct *v1; // ecx
  PlayerStruct *v2; // esi
  ItemStruct *v3;   // edi
  int v4;           // ebp
  ItemStruct *v6;   // edi
  signed int v7;    // ebp

  v1 = &plr[pnum];
  v2 = v1;
  v3 = v1->InvList;
  if (v1->_pNumInv) {
    v4 = v1->_pNumInv;
    do {
      v3->_iStatFlag = ItemMinStats(v2, v3);
      ++v3;
      --v4;
    } while (v4);
  }
  v6 = v2->SpdList;
  v7 = 8;
  do {
    if (v6->_itype != -1) {
      v6->_iStatFlag = ItemMinStats(v2, v6);
    }
    ++v6;
    --v7;
  } while (v7);
}

//----- (0041FBF6) --------------------------------------------------------
bool __fastcall ItemMinStats(PlayerStruct *p, ItemStruct *x) {
  if (p->_pStrength < x->_iMinStr || p->_pMagic < x->_iMinMag ||
      p->_pDexterity < x->_iMinDex)
    return 0;
  else
    return 1;
}

//----- (0041FC2C) --------------------------------------------------------
void __fastcall CalcPlrBookVals(int p) {
  int v1;            // esi
  int v2;            // ebx
  int *v3;           // edi
  int v5;            // esi
  int *v6;           // edi
  int v7;            // eax
  unsigned char v8;  // cl
  unsigned char v9;  // cl
  int v10;           // eax
  int v12;           // [esp+Ch] [ebp-Ch]
  int v13;           // [esp+10h] [ebp-8h]
  unsigned char v14; // [esp+17h] [ebp-1h]

  v1 = p;
  if (!currlevel) {
    v2 = 1;
    if (witchitem[1]._itype != -1) {
      v3 = &witchitem[1]._iStatFlag;
      do {
        WitchBookLevel(v2);
        *v3 = StoreStatOk((ItemStruct *)(v3 - 89));
        v3 += 92;
        ++v2;
      } while (*(v3 - 87) != -1);
    }
  }
  v5 = v1;
  v12 = 0;
  if (plr[v5]._pNumInv > 0) {
    v6 = &plr[v5].InvList[0]._iSpell;
    do {
      if (!*(v6 - 54) && *(v6 - 1) == 24) {
        v7 = *v6;
        v8 = spelldata[*v6].sMinInt;
        *((_BYTE *)v6 + 129) = v8;
        v13 = plr[0]._pSplLvl[v7 + v5 * 21720];
        if (plr[0]._pSplLvl[v7 + v5 * 21720]) {
          do {
            v9 = 20 * v8 / 100 + v8;
            --v13;
            v14 = v9;
            v10 = v9 + 20 * v9 / 100;
            v8 = -1;
            if (v10 <= 255)
              v8 = v14;
            else
              v13 = 0;
          } while (v13);
          *((_BYTE *)v6 + 129) = v8;
        }
        v6[33] = ItemMinStats(&plr[v5], (ItemStruct *)(v6 - 56));
      }
      ++v12;
      v6 += 92;
    } while (v12 < plr[v5]._pNumInv);
  }
}

//----- (0041FD3E) --------------------------------------------------------
void __fastcall CalcPlrInv(int p, bool Loadgfx) {
  CalcPlrItemMin(p);
  CalcSelfItems(p);
  CalcPlrItemVals(p, Loadgfx);
  CalcPlrItemMin(p);
  if (p == myplr) {
    CalcPlrBookVals(p);
    CalcPlrScrolls(p);
    CalcPlrStaff(p);
    if (p == myplr && !currlevel)
      RecalcStoreStats();
  }
}

//----- (0041FD98) --------------------------------------------------------
void __fastcall SetPlrHandItem(ItemStruct *h, int idata) {
  ItemDataStruct *pAllItem; // edi

  pAllItem = &AllItemsList[idata];
  memset(h, 0, 0x170u);
  h->_itype = pAllItem->itype;
  h->_iCurs = pAllItem->iCurs;
  strcpy(h->_iName, pAllItem->iName);
  strcpy(h->_iIName, pAllItem->iName);
  h->_iLoc = pAllItem->iLoc;
  h->_iClass = pAllItem->iClass;
  h->_iMinDam = pAllItem->iMinDam;
  h->_iMaxDam = pAllItem->iMaxDam;
  h->_iAC = pAllItem->iMinAC;
  h->_iMiscId = pAllItem->iMiscId;
  h->_iSpell = pAllItem->iSpell;

  if (pAllItem->iMiscId == IMISC_STAFF)
    h->_iCharges = 40;

  h->_iMaxCharges = h->_iCharges;
  h->_iDurability = pAllItem->iDurability;
  h->_iMaxDur = pAllItem->iDurability;
  h->_iMinStr = pAllItem->iMinStr;
  h->_iMinMag = pAllItem->iMinMag;
  h->_iMinDex = pAllItem->iMinDex;
  h->_ivalue = pAllItem->iValue;
  h->_iPrePower = -1;
  h->_iSufPower = -1;
  h->_iMagical = 0;
  h->_iIvalue = pAllItem->iValue;
  h->IDidx = idata;
}

//----- (0041FE98) --------------------------------------------------------
void __fastcall GetPlrHandSeed(ItemStruct *h) { h->_iSeed = GetRndSeed(); }

//----- (0041FEA4) --------------------------------------------------------
void __fastcall GetGoldSeed(int pnum, ItemStruct *h) {
  int v3;         // edi
  signed int v4;  // esi
  int v5;         // eax
  int i;          // ecx
  int v7;         // edx
  ItemStruct *v8; // ecx

  v3 = pnum;
  do {
    v4 = 1;
    v5 = GetRndSeed();
    for (i = 0; i < numitems; ++i) {
      if (item[itemactive[i]]._iSeed == v5)
        v4 = 0;
    }
    if (v3 == myplr) {
      v7 = plr[v3]._pNumInv;
      if (v7 > 0) {
        v8 = plr[v3].InvList;
        do {
          if (v8->_iSeed == v5)
            v4 = 0;
          ++v8;
          --v7;
        } while (v7);
      }
    }
  } while (!v4);
  h->_iSeed = v5;
}

//----- (0041FF16) --------------------------------------------------------
void __fastcall SetPlrHandSeed(ItemStruct *h, int iseed) { h->_iSeed = iseed; }

//----- (0041FF19) --------------------------------------------------------
void __fastcall SetPlrHandGoldCurs(ItemStruct *h) {
  int v1; // eax

  v1 = h->_ivalue;
  if (v1 < 2500) {
    if (v1 > 1000)
      h->_iCurs = 5;
    else
      h->_iCurs = 4;
  } else {
    h->_iCurs = 6;
  }
}

//----- (0041FF4E) --------------------------------------------------------
void __fastcall CreatePlrItems(int p) {
  int v1;          // ebx
  int *v2;         // eax
  signed int v3;   // ecx
  int *v4;         // eax
  signed int v5;   // ecx
  int *v6;         // eax
  signed int v7;   // ecx
  int player_numa; // [esp+Ch] [ebp-4h]

  player_numa = p;
  v1 = p;
  v2 = &plr[p].InvBody[0]._itype;
  v3 = 7;
  do {
    *v2 = -1;
    v2 += 92;
    --v3;
  } while (v3);
  memset(plr[v1].InvGrid, 0, 0x28u);
  v4 = &plr[v1].InvList[0]._itype;
  v5 = 40;
  do {
    *v4 = -1;
    v4 += 92;
    --v5;
  } while (v5);
  plr[v1]._pNumInv = 0;
  v6 = &plr[v1].SpdList[0]._itype;
  v7 = 8;
  do {
    *v6 = -1;
    v6 += 92;
    --v7;
  } while (v7);
  switch (_LOBYTE(plr[v1]._pClass)) {
  case UI_WARRIOR:
    SetPlrHandItem(&plr[v1].InvBody[4], IDI_WARRIOR);
    GetPlrHandSeed(&plr[v1].InvBody[4]);
    SetPlrHandItem(&plr[v1].InvBody[5], IDI_WARRSHLD);
    GetPlrHandSeed(&plr[v1].InvBody[5]);
    SetPlrHandItem(&plr[v1].HoldItem, IDI_WARRCLUB);
    GetPlrHandSeed(&plr[v1].HoldItem);
    AutoPlace(player_numa, 0, 1, 3, 1);
    goto LABEL_13;
  case UI_ROGUE:
    SetPlrHandItem(&plr[v1].InvBody[4], IDI_ROGUE);
    GetPlrHandSeed(&plr[v1].InvBody[4]);
  LABEL_13:
    SetPlrHandItem(plr[v1].SpdList, IDI_HEAL);
    GetPlrHandSeed(plr[v1].SpdList);
    SetPlrHandItem(&plr[v1].SpdList[1], IDI_HEAL);
    goto LABEL_14;
  case UI_SORCERER:
    SetPlrHandItem(&plr[v1].InvBody[4], IDI_SORCEROR);
    GetPlrHandSeed(&plr[v1].InvBody[4]);
    SetPlrHandItem(plr[v1].SpdList, IDI_MANA);
    GetPlrHandSeed(plr[v1].SpdList);
    SetPlrHandItem(&plr[v1].SpdList[1], IDI_MANA);
  LABEL_14:
    GetPlrHandSeed(&plr[v1].SpdList[1]);
    break;
  }
  SetPlrHandItem(&plr[v1].HoldItem, IDI_GOLD);
  GetPlrHandSeed(&plr[v1].HoldItem);
  plr[v1].HoldItem._iCurs = 4;
  plr[v1].HoldItem._ivalue = 100;
  plr[v1]._pGold = 100;
  qmemcpy((char *)&plr[0].InvList[plr[v1]._pNumInv++] + v1 * 21720,
          &plr[v1].HoldItem, 0x170u);
  plr[v1].InvGrid[30] = plr[v1]._pNumInv;
  CalcPlrItemVals(player_numa, 0);
}

//----- (004200F8) --------------------------------------------------------
bool __fastcall ItemSpaceOk(int i, int j) {
  int v2;  // eax
  int v3;  // esi
  char v4; // cl
  int v5;  // ecx
  char v6; // cl
  bool v7; // sf
  char v8; // cl
  char v9; // al

  if (i < 0)
    return 0;
  if (i >= 112)
    return 0;
  if (j < 0)
    return 0;
  if (j >= 112)
    return 0;
  v2 = i;
  v3 = 112 * i + j;
  if (dMonster[0][v3] || dPlayer[v2][j] || dItem[v2][j])
    return 0;
  v4 = dObject[v2][j];
  if (v4) {
    v5 = v4 <= 0 ? -1 - v4 : v4 - 1;
    if (object[v5]._oSolidFlag)
      return 0;
  }
  v6 = dObject[v2 + 1][j + 1];
  v7 = v6 < 0;
  if (v6 > 0) {
    if (_LOBYTE(object[v6 - 1]._oSelFlag)) /* check */
      return 0;
    v7 = v6 < 0;
  }
  if (!v7 || !_LOBYTE(object[-(v6 + 1)]._oSelFlag)) {
    v8 = dObject[v2 + 1][j];
    if (v8 <= 0)
      return nSolidTable[dPiece[0][v3]] == 0;
    v9 = dObject[v2][j + 1];
    if (v9 <= 0 || !_LOBYTE(object[v8 - 1]._oSelFlag) ||
        !_LOBYTE(object[v9 - 1]._oSelFlag))
      return nSolidTable[dPiece[0][v3]] == 0;
  }
  return 0;
}

//----- (004201F2) --------------------------------------------------------
bool __fastcall GetItemSpace(int x, int y, char inum) {
  int v3;        // eax
  int v4;        // edx
  char(*v5)[3];  // edi
  int v6;        // ebx
  char(*v7)[3];  // esi
  signed int v9; // esi
  char(*v10)[3]; // eax
  int v11;       // ecx
  int v12;       // eax
  int v14;       // ecx
  int v15;       // edx
  int v16;       // eax
  int v17;       // esi
  int v18;       // ecx
  int v19;       // [esp+8h] [ebp-Ch]
  int v20;       // [esp+Ch] [ebp-8h]
  char(*v21)[3]; // [esp+10h] [ebp-4h]

  v3 = y;
  v19 = y;
  v4 = y - 1;
  v20 = x;
  v5 = itemhold;
  if (v4 <= v19 + 1) {
    v21 = itemhold;
    do {
      v6 = x - 1;
      if ((unsigned char)(__OFSUB__(x - 1, x + 1) ^ 1) | (x - 1 == x + 1)) {
        v7 = v21;
        do {
          *(_DWORD *)v7 = ItemSpaceOk(v6, v4);
          v7 += 4;
          ++v6;
        } while (v6 <= v20 + 1);
        v3 = v19;
        x = v20;
      }
      v21 = (char(*)[3])((char *)v21 + 4);
      ++v4;
    } while (v4 <= v3 + 1);
  }
  v9 = 0;
  do {
    v10 = v5;
    v11 = 3;
    do {
      if (*(_DWORD *)v10)
        v9 = 1;
      v10 += 4;
      --v11;
    } while (v11);
    v5 = (char(*)[3])((char *)v5 + 4);
  } while ((signed int)v5 < (signed int)&itemhold[3][0]);
  _LOBYTE(v11) = 13;
  v12 = random(v11, 15) + 1;
  if (!v9)
    return 0;
  v14 = 0;
  v15 = 0;
  if (v12 > 0) {
    while (1) {
      if (*(_DWORD *)&itemhold[0][4 * (v15 + 2 * v14 + v14)])
        --v12;
      if (v12 <= 0)
        break;
      if (++v14 == 3) {
        v14 = 0;
        if (++v15 == 3)
          v15 = 0;
      }
    }
  }
  v16 = v14 + v20 - 1;
  v17 = v15 + v19 - 1;
  v18 = inum;
  item[v18]._ix = v16;
  dItem[v16][v17] = inum + 1;
  item[v18]._iy = v17;
  return 1;
}

//----- (004202E8) --------------------------------------------------------
void __fastcall GetSuperItemSpace(int x, int y, char inum) {
  signed int v4;  // edi
  signed int v5;  // ebx
  int v6;         // edx
  int v7;         // esi
  int v9;         // eax
  int v10;        // [esp+Ch] [ebp-10h]
  int v11;        // [esp+10h] [ebp-Ch]
  signed int v12; // [esp+14h] [ebp-8h]
  signed int v13; // [esp+18h] [ebp-4h]

  v11 = y;
  v10 = x;
  if (!GetItemSpace(x, y, inum)) {
    v13 = 2;
    v4 = -2;
    do {
      v5 = v4;
      if (v4 <= v13) {
        while (2) {
          v12 = v4;
          v6 = v5 + v11;
          v7 = v4 + v10;
          do {
            if (ItemSpaceOk(v7, v6)) {
              v9 = inum;
              item[v9]._ix = v7;
              item[v9]._iy = v6;
              dItem[v7][v6] = inum + 1;
              return;
            }
            ++v12;
            ++v7;
          } while (v12 <= v13);
          if (++v5 <= v13)
            continue;
          break;
        }
      }
      ++v13;
      --v4;
    } while (v4 > -50);
  }
}

//----- (00420376) --------------------------------------------------------
void __fastcall GetSuperItemLoc(int x, int y, int *xx, int *yy) {
  signed int v4;  // edi
  signed int v5;  // ebx
  int v6;         // esi
  int v8;         // [esp+Ch] [ebp-10h]
  int v9;         // [esp+10h] [ebp-Ch]
  signed int v10; // [esp+14h] [ebp-8h]
  signed int v11; // [esp+18h] [ebp-4h]

  v9 = y;
  v8 = x;
  v11 = 1;
  v4 = -1;
  while (1) {
    v5 = v4;
    if (v4 <= v11)
      break;
  LABEL_7:
    ++v11;
    if (--v4 <= -50)
      return;
  }
LABEL_3:
  v10 = v4;
  *yy = v5 + v9;
  v6 = v4 + v8;
  while (1) {
    *xx = v6;
    if (ItemSpaceOk(v6, *yy))
      break;
    ++v10;
    ++v6;
    if (v10 > v11) {
      if (++v5 <= v11)
        goto LABEL_3;
      goto LABEL_7;
    }
  }
}

//----- (004203E0) --------------------------------------------------------
void __fastcall CalcItemValue(int i) {
  int v1;  // ecx
  int v2;  // esi
  bool v3; // sf
  int v4;  // esi

  v1 = i;
  v2 = item[v1]._iVMult1 + item[v1]._iVMult2;
  v3 = v2 < 0;
  if (v2 > 0) {
    v2 *= item[v1]._ivalue;
    v3 = v2 < 0;
  }
  if (v3)
    v2 = item[v1]._ivalue / v2;
  v4 = item[v1]._iVAdd1 + item[v1]._iVAdd2 + v2;
  if (v4 <= 0)
    v4 = 1;
  item[v1]._iIvalue = v4;
}

//----- (0042042C) --------------------------------------------------------
void __fastcall GetBookSpell(int i, int lvl) {
  int v2;          // edi
  int v3;          // esi
  int v4;          // eax
  int v5;          // edx
  signed int v6;   // ecx
  int v7;          // esi
  const char **v8; // ebx
  int v9;          // eax
  char v10;        // al
  int v11;         // [esp+8h] [ebp-4h]

  v2 = lvl;
  v3 = i;
  if (!lvl)
    v2 = lvl + 1;
  _LOBYTE(i) = 14;
  v4 = random(i, 37) + 1;
LABEL_13:
  v6 = 1;
  while (v4 > 0) {
    v5 = spelldata[v6].sBookLvl;
    if (v5 != -1 && v2 >= v5) {
      --v4;
      v11 = v6;
    }
    ++v6;
    if (gbMaxPlayers == 1) {
      if (v6 == SPL_RESURRECT)
        v6 = SPL_TELEKINESIS;
      if (v6 == SPL_HEALOTHER)
        v6 = SPL_FLARE;
    }
    if (v6 == 37)
      goto LABEL_13;
  }
  v7 = v3;
  v8 = (const char **)&spelldata[v11].sNameText;
  strcat(item[v7]._iName, *v8);
  strcat(item[v7]._iIName, *v8);
  item[v7]._iSpell = v11;
  item[v7]._iMinMag = spelldata[v11].sMinInt;
  v9 = spelldata[v11].sBookCost;
  item[v7]._ivalue += v9;
  item[v7]._iIvalue += v9;
  v10 = spelldata[v11].sType;
  if (v10 == STYPE_FIRE)
    item[v7]._iCurs = 87; // Red Book
  if (v10 == STYPE_LIGHTNING)
    item[v7]._iCurs = 88; // Blue Book
  if (v10 == STYPE_MAGIC)
    item[v7]._iCurs = 86; // Black Book
}
// 679660: using guessed type char gbMaxPlayers;

//----- (00420514) --------------------------------------------------------
void __fastcall GetStaffPower(int i, int lvl, int bs, unsigned char onlygood) {
  int v4;         // esi
  int v5;         // ebx
  int v6;         // edx
  int v7;         // ecx
  int v9;         // edi
  int v10;        // ecx
  int v11;        // ST14_4
  int v12;        // esi
  char *v13;      // edi
  int l[256];     // [esp+Ch] [ebp-484h]
  char istr[128]; // [esp+40Ch] [ebp-84h]
  int ia;         // [esp+48Ch] [ebp-4h]
  char *v17;      // [esp+49Ch] [ebp+Ch]

  v4 = lvl;
  ia = i;
  _LOBYTE(i) = 15;
  v5 = -1;
  if (!random(i, 10) || onlygood) {
    v6 = 0;
    v7 = 0;
    if (PL_Prefix[0].PLPower != -1) {
      do {
        if (PL_Prefix[v7].PLIType & 0x100 && PL_Prefix[v7].PLMinLvl <= v4 &&
            (!onlygood || PL_Prefix[v7].PLOk)) {
          l[v6++] = v7;
          if (PL_Prefix[v7].PLDouble)
            l[v6++] = v7;
        }
        ++v7;
      } while (PL_Prefix[v7].PLPower != -1);
      if (v6) {
        _LOBYTE(v7) = 16;
        v5 = l[random(v7, v6)];
        v9 = ia;
        v17 = item[ia]._iIName;
        sprintf(istr, "%s %s", PL_Prefix[v5].PLName, item[ia]._iIName);
        strcpy(v17, istr);
        v10 = ia;
        v11 = PL_Prefix[v5].PLMultVal;
        item[v9]._iMagical = 1;
        SaveItemPower(v10, PL_Prefix[v5].PLPower, PL_Prefix[v5].PLParam1,
                      PL_Prefix[v5].PLParam2, PL_Prefix[v5].PLMinVal,
                      PL_Prefix[v5].PLMaxVal, v11);
        item[v9]._iPrePower = PL_Prefix[v5].PLPower;
      }
    }
  }
  v12 = ia;
  v13 = item[ia]._iIName;
  if (!control_WriteStringToBuffer(item[ia]._iIName)) {
    strcpy(v13, AllItemsList[item[v12].IDidx].iSName);
    if (v5 != -1) {
      sprintf(istr, "%s %s", PL_Prefix[v5].PLName, v13);
      strcpy(v13, istr);
    }
    sprintf(istr, "%s of %s", v13, spelldata[bs].sNameText);
    strcpy(v13, istr);
    if (!item[v12]._iMagical)
      strcpy(item[v12]._iName, v13);
  }
  CalcItemValue(ia);
}
// 420514: using guessed type int var_484[256];

//----- (004206E5) --------------------------------------------------------
void __fastcall GetStaffSpell(int i, int lvl, unsigned char onlygood) {
  int l;         // esi
  int rv;        // eax
  int s;         // ecx
  int minc;      // ebx
  int maxc;      // edx
  int v;         // eax
  char istr[64]; // [esp+4h] [ebp-4Ch]
  int bs;        // [esp+4Ch] [ebp-4h]

  if (random(17, 4)) {
    l = lvl >> 1;
    if (!l)
      l = 1;
    rv = random(18, 37) + 1;
  LABEL_15:
    s = 1;
    while (rv > 0) {
      if (spelldata[s].sStaffLvl != -1 && l >= spelldata[s].sStaffLvl) {
        --rv;
        bs = s;
      }
      ++s;
      if (gbMaxPlayers == 1) {
        if (s == SPL_RESURRECT)
          s = SPL_TELEKINESIS;
        if (s == SPL_HEALOTHER)
          s = SPL_FLARE;
      }
      if (s == 37)
        goto LABEL_15;
    }
    sprintf(istr, "%s of %s", item[i]._iName, spelldata[bs].sNameText);
    if (!control_WriteStringToBuffer(istr))
      sprintf(istr, "Staff of %s", spelldata[bs].sNameText);
    strcpy(item[i]._iName, istr);
    strcpy(item[i]._iIName, istr);
    minc = spelldata[bs].sStaffMin;
    maxc = spelldata[bs].sStaffMax - minc + 1;
    item[i]._iSpell = bs;
    v = random(19, maxc) + minc;
    item[i]._iMinMag = spelldata[bs].sMinInt;
    item[i]._iCharges = v;
    item[i]._iMaxCharges = v;
    v = (v * spelldata[bs].sStaffCost) / 5;
    item[i]._ivalue += v;
    item[i]._iIvalue += v;
    GetStaffPower(i, lvl, bs, onlygood);
  } else {
    GetItemPower(i, lvl >> 1, lvl, 256, onlygood);
  }
}
// 679660: using guessed type char gbMaxPlayers;

//----- (0042084A) --------------------------------------------------------
void __fastcall GetItemAttrs(int i, int idata, int lvl) {
  int rndv; // eax

  item[i]._itype = AllItemsList[idata].itype;
  item[i]._iCurs = AllItemsList[idata].iCurs;
  strcpy(item[i]._iName, AllItemsList[idata].iName);
  strcpy(item[i]._iIName, AllItemsList[idata].iName);
  item[i]._iLoc = AllItemsList[idata].iLoc;
  item[i]._iClass = AllItemsList[idata].iClass;
  item[i]._iMinDam = AllItemsList[idata].iMinDam;
  item[i]._iMaxDam = AllItemsList[idata].iMaxDam;
  item[i]._iMiscId = AllItemsList[idata].iMiscId;
  item[i]._iAC =
      AllItemsList[idata].iMinAC +
      random(20, AllItemsList[idata].iMaxAC - AllItemsList[idata].iMinAC + 1);
  item[i]._iFlags = AllItemsList[idata].iFlags;
  item[i]._iSpell = AllItemsList[idata].iSpell;
  item[i]._ivalue = AllItemsList[idata].iValue;
  item[i]._iIvalue = AllItemsList[idata].iValue;
  item[i]._iMagical = 0;
  item[i]._iDurability = AllItemsList[idata].iDurability;
  item[i]._iMaxDur = AllItemsList[idata].iDurability;
  item[i]._iVAdd1 = 0;
  item[i]._iMinStr = AllItemsList[idata].iMinStr;
  item[i]._iMinMag = AllItemsList[idata].iMinMag;
  item[i]._iMinDex = AllItemsList[idata].iMinDex;
  item[i]._iVMult1 = 0;
  item[i]._iVAdd2 = 0;
  item[i]._iVMult2 = 0;
  item[i]._iPLDam = 0;
  item[i]._iPLToHit = 0;
  item[i]._iPLAC = 0;
  item[i]._iPLStr = 0;
  item[i]._iPLMag = 0;
  item[i]._iPLDex = 0;
  item[i]._iPLVit = 0;
  item[i]._iCharges = 0;
  item[i]._iMaxCharges = 0;
  item[i]._iPLFR = 0;
  item[i]._iPLLR = 0;
  item[i]._iPLMR = 0;
  item[i].IDidx = idata;
  item[i]._iPLDamMod = 0;
  item[i]._iPLGetHit = 0;
  item[i]._iPLLight = 0;
  item[i]._iSplLvlAdd = 0;
  item[i]._iPrePower = -1;
  item[i]._iSufPower = -1;
  item[i]._iRequest = 0;
  item[i]._iFMinDam = 0;
  item[i]._iFMaxDam = 0;
  item[i]._iLMinDam = 0;
  item[i]._iLMaxDam = 0;
  item[i]._iPLEnAc = 0;
  item[i]._iPLMana = 0;
  item[i]._iPLHP = 0;

  if (AllItemsList[idata].iMiscId == IMISC_BOOK)
    GetBookSpell(i, lvl);

  if (item[i]._itype == ITYPE_GOLD) {
    if (gnDifficulty) /* clean this up, NORMAL */
      rndv = lvl;
    else
      rndv = 5 * currlevel + random(21, 10 * currlevel);

    if (gnDifficulty == DIFF_NIGHTMARE)
      rndv = 5 * (currlevel + 16) + random(21, 10 * (currlevel + 16));
    if (gnDifficulty == DIFF_HELL)
      rndv = 5 * (currlevel + 32) + random(21, 10 * (currlevel + 32));

    if (leveltype == 4)
      rndv += rndv >> 3;
    if (rndv > 5000)
      rndv = 5000;

    item[i]._ivalue = rndv;

    if (rndv < 2500)
      item[i]._iCurs = (rndv > 1000) + 4;
    else
      item[i]._iCurs = 6;
  }
}
// 5BB1ED: using guessed type char leveltype;

//----- (00420B17) --------------------------------------------------------
int __fastcall RndPL(int param1, int param2) {
  return param1 + random(22, param2 - param1 + 1);
}

//----- (00420B28) --------------------------------------------------------
int __fastcall PLVal(int pv, int p1, int p2, int minv, int maxv) {
  if (p1 == p2)
    return minv;
  if (minv == maxv)
    return minv;
  return minv + (maxv - minv) * (100 * (pv - p1) / (p2 - p1)) / 100;
}

//----- (00420B68) --------------------------------------------------------
void __fastcall SaveItemPower(int i, int power, int param1, int param2,
                              int minval, int maxval, int multval) {
  int v7;         // edi
  int v8;         // esi
  int v9;         // eax
  int v10;        // ebx
  int *v11;       // eax
  int *v12;       // eax
  int v13;        // edi
  int v14;        // eax
  int v15;        // edi
  int v16;        // eax
  int v17;        // eax
  int v18;        // ecx
  int v19;        // edx
  int v20;        // edi
  int *v21;       // edx
  int v22;        // eax
  int v23;        // eax
  int v24;        // eax
  int v25;        // eax
  int v26;        // eax
  int v27;        // eax
  int v28;        // ecx
  int *v29;       // eax
  int v30;        // ecx
  int *v31;       // eax
  int v32;        // ecx
  int v33;        // eax
  int v34;        // ST18_4
  int v35;        // eax
  int v36;        // ecx
  int v37;        // edx
  signed int v38; // ecx
  int v39;        // eax
  int v40;        // eax
  int v41;        // ecx
  int *v42;       // eax
  int v43;        // esi

  v7 = power;
  v8 = i;
  v9 = RndPL(param1, param2);
  v10 = v9;
  switch (v7) {
  case IPL_TOHIT:
    v11 = &item[v8]._iPLToHit;
    goto LABEL_115;
  case IPL_TOHIT_CURSE:
    v12 = &item[v8]._iPLToHit;
    goto LABEL_62;
  case IPL_DAMP:
    v11 = &item[v8]._iPLDam;
    goto LABEL_115;
  case IPL_DAMP_CURSE:
    v12 = &item[v8]._iPLDam;
    goto LABEL_62;
  case IPL_TOHIT_DAMP:
    v10 = RndPL(param1, param2);
    v13 = v8;
    item[v13]._iPLDam += v10;
    if (param1 == 20)
      v14 = RndPL(1, 5);
    else
      v14 = param1;
    if (param1 == 36)
      v14 = RndPL(6, 10);
    if (param1 == 51)
      v14 = RndPL(11, 15);
    if (param1 == 66)
      v14 = RndPL(16, 20);
    if (param1 == 81)
      v14 = RndPL(21, 30);
    if (param1 == 96)
      v14 = RndPL(31, 40);
    if (param1 == 111)
      v14 = RndPL(41, 50);
    if (param1 == 126)
      v14 = RndPL(51, 75);
    if (param1 == 151)
      v14 = RndPL(76, 100);
    item[v13]._iPLToHit += v14;
    break;
  case IPL_TOHIT_DAMP_CURSE:
    v15 = v8;
    item[v15]._iPLDam -= v9;
    if (param1 == 25)
      v16 = RndPL(1, 5);
    else
      v16 = param1;
    if (param1 == 50)
      v16 = RndPL(6, 10);
    item[v15]._iPLToHit -= v16;
    break;
  case IPL_ACP:
    v11 = &item[v8]._iPLAC;
    goto LABEL_115;
  case IPL_ACP_CURSE:
    v12 = &item[v8]._iPLAC;
    goto LABEL_62;
  case IPL_FIRERES:
    v11 = &item[v8]._iPLFR;
    goto LABEL_115;
  case IPL_LIGHTRES:
    v11 = &item[v8]._iPLLR;
    goto LABEL_115;
  case IPL_MAGICRES:
    v11 = &item[v8]._iPLMR;
    goto LABEL_115;
  case IPL_ALLRES:
    v17 = v8;
    item[v17]._iPLFR += v10;
    v18 = item[v8]._iPLFR;
    item[v17]._iPLLR += v10;
    item[v17]._iPLMR += v10;
    v19 = item[v8]._iPLLR;
    v20 = item[v8]._iPLMR;
    if (v18 < 0)
      item[v17]._iPLFR = 0;
    if (v19 < 0)
      item[v17]._iPLLR = 0;
    if (v20 < 0)
      item[v17]._iPLMR = 0;
    break;
  case IPL_SPLLVLADD:
    item[v8]._iSplLvlAdd = v9;
    break;
  case IPL_CHARGES:
    v21 = &item[v8]._iCharges;
    v22 = param1 * *v21;
    *v21 = v22;
    item[v8]._iMaxCharges = v22;
    break;
  case IPL_FIREDAM:
    v24 = v8;
    item[v24]._iFlags |= 0x10u;
    goto LABEL_77;
  case IPL_LIGHTDAM:
    v25 = v8;
    item[v25]._iFlags |= 0x20u;
    goto LABEL_79;
  case IPL_STR:
    v11 = &item[v8]._iPLStr;
    goto LABEL_115;
  case IPL_STR_CURSE:
    v12 = &item[v8]._iPLStr;
    goto LABEL_62;
  case IPL_MAG:
    v11 = &item[v8]._iPLMag;
    goto LABEL_115;
  case IPL_MAG_CURSE:
    v12 = &item[v8]._iPLMag;
    goto LABEL_62;
  case IPL_DEX:
    v11 = &item[v8]._iPLDex;
    goto LABEL_115;
  case IPL_DEX_CURSE:
    v12 = &item[v8]._iPLDex;
    goto LABEL_62;
  case IPL_VIT:
    v11 = &item[v8]._iPLVit;
    goto LABEL_115;
  case IPL_VIT_CURSE:
    v12 = &item[v8]._iPLVit;
    goto LABEL_62;
  case IPL_ATTRIBS:
    v26 = v8;
    item[v26]._iPLStr += v10;
    item[v26]._iPLMag += v10;
    item[v26]._iPLDex += v10;
    item[v26]._iPLVit += v10;
    break;
  case IPL_ATTRIBS_CURSE:
    v27 = v8;
    item[v27]._iPLStr -= v10;
    item[v27]._iPLMag -= v10;
    item[v27]._iPLDex -= v10;
    item[v27]._iPLVit -= v10;
    break;
  case IPL_GETHIT_CURSE:
    v11 = &item[v8]._iPLGetHit;
    goto LABEL_115;
  case IPL_GETHIT:
    v12 = &item[v8]._iPLGetHit;
    goto LABEL_62;
  case IPL_LIFE:
    v28 = v9 << 6;
    v29 = &item[v8]._iPLHP;
    goto LABEL_73;
  case IPL_LIFE_CURSE:
    v30 = v9 << 6;
    v31 = &item[v8]._iPLHP;
    goto LABEL_75;
  case IPL_MANA:
    item[v8]._iPLMana += v9 << 6;
    goto LABEL_92;
  case IPL_MANA_CURSE:
    item[v8]._iPLMana -= v9 << 6;
    goto LABEL_92;
  case IPL_DUR:
    v32 = v8;
    v33 = item[v8]._iMaxDur;
    v34 = v33;
    v35 = v10 * v33 / 100;
    item[v32]._iDurability += v35;
    item[v32]._iMaxDur = v35 + v34;
    break;
  case IPL_DUR_CURSE:
    v36 = v8;
    v37 = item[v8]._iMaxDur - v9 * item[v8]._iMaxDur / 100;
    item[v8]._iMaxDur = v37;
    if (v37 < 1)
      item[v36]._iMaxDur = 1;
    item[v36]._iDurability = item[v36]._iMaxDur;
    break;
  case IPL_INDESTRUCTIBLE:
    v38 = 255;
    goto LABEL_119;
  case IPL_LIGHT:
    v28 = param1;
    v29 = &item[v8]._iPLLight;
  LABEL_73:
    *v29 += v28;
    break;
  case IPL_LIGHT_CURSE:
    v30 = param1;
    v31 = &item[v8]._iPLLight;
  LABEL_75:
    *v31 -= v30;
    break;
  case IPL_FIRE_ARROWS:
    v24 = v8;
    item[v24]._iFlags |= 8u;
  LABEL_77:
    item[v24]._iFMinDam = param1;
    item[v24]._iFMaxDam = param2;
    break;
  case IPL_LIGHT_ARROWS:
    v25 = v8;
    _HIBYTE(item[v8]._iFlags) |= 2u;
  LABEL_79:
    item[v25]._iLMinDam = param1;
    item[v25]._iLMaxDam = param2;
    break;
  case IPL_INVCURS:
    item[v8]._iCurs = param1;
    break;
  case IPL_THORNS:
    _HIBYTE(item[v8]._iFlags) |= 4u;
    break;
  case IPL_NOMANA:
    _HIBYTE(item[v8]._iFlags) |= 8u;
    goto LABEL_92;
  case IPL_NOHEALPLR:
    BYTE1(item[v8]._iFlags) |= 1u;
    break;
  case IPL_ABSHALFTRAP:
    _HIBYTE(item[v8]._iFlags) |= 0x10u;
    break;
  case IPL_KNOCKBACK:
    BYTE1(item[v8]._iFlags) |= 8u;
    break;
  case IPL_NOHEALMON:
    BYTE1(item[v8]._iFlags) |= 0x10u;
    break;
  case IPL_STEALMANA:
    if (param1 == 3)
      BYTE1(item[v8]._iFlags) |= 0x20u;
    if (param1 == 5)
      BYTE1(item[v8]._iFlags) |= 0x40u;
  LABEL_92:
    drawmanaflag = 1;
    break;
  case IPL_STEALLIFE:
    if (param1 == 3)
      BYTE1(item[v8]._iFlags) |= 0x80u;
    if (param1 == 5)
      BYTE2(item[v8]._iFlags) |= 1u;
    drawhpflag = 1;
    break;
  case IPL_TARGAC:
    v11 = &item[v8]._iPLEnAc;
    goto LABEL_115;
  case IPL_FASTATTACK:
    if (param1 == 1)
      BYTE2(item[v8]._iFlags) |= 2u;
    if (param1 == 2)
      BYTE2(item[v8]._iFlags) |= 4u;
    if (param1 == 3)
      BYTE2(item[v8]._iFlags) |= 8u;
    if (param1 == 4)
      BYTE2(item[v8]._iFlags) |= 0x10u;
    break;
  case IPL_FASTRECOVER:
    if (param1 == 1)
      BYTE2(item[v8]._iFlags) |= 0x20u;
    if (param1 == 2)
      BYTE2(item[v8]._iFlags) |= 0x40u;
    if (param1 == 3)
      BYTE2(item[v8]._iFlags) |= 0x80u;
    break;
  case IPL_FASTBLOCK:
    _HIBYTE(item[v8]._iFlags) |= 1u;
    break;
  case IPL_DAMMOD:
    v11 = &item[v8]._iPLDamMod;
  LABEL_115:
    *v11 += v10;
    break;
  case IPL_RNDARROWVEL:
    item[v8]._iFlags |= 4u;
    break;
  case IPL_SETDAM:
    v39 = v8;
    item[v39]._iMinDam = param1;
    item[v39]._iMaxDam = param2;
    break;
  case IPL_SETDUR:
    v38 = param1;
  LABEL_119:
    v40 = v8;
    item[v40]._iDurability = v38;
    item[v40]._iMaxDur = v38;
    break;
  case IPL_NOMINSTR:
    item[v8]._iMinStr = 0;
    break;
  case IPL_SPELL:
    v23 = v8;
    item[v23]._iSpell = param1;
    item[v23]._iCharges = param1;
    item[v23]._iMaxCharges = param2;
    break;
  case IPL_FASTSWING:
    BYTE2(item[v8]._iFlags) |= 8u;
    break;
  case IPL_ONEHAND:
    item[v8]._iLoc = ILOC_ONEHAND;
    break;
  case IPL_3XDAMVDEM:
    _HIBYTE(item[v8]._iFlags) |= 0x40u;
    break;
  case IPL_ALLRESZERO:
    _HIBYTE(item[v8]._iFlags) |= 0x80u;
    break;
  case IPL_DRAINLIFE:
    item[v8]._iFlags |= 0x40u;
    break;
  case IPL_RNDSTEALLIFE:
    item[v8]._iFlags |= 2u;
    break;
  case IPL_INFRAVISION:
    item[v8]._iFlags |= 1u;
    break;
  case IPL_SETAC:
    item[v8]._iAC = v9;
    break;
  case IPL_ADDACLIFE:
    item[v8]._iPLHP =
        (plr[myplr]._pIBonusAC + plr[myplr]._pIAC + plr[myplr]._pDexterity / 5)
        << 6;
    break;
  case IPL_ADDMANAAC:
    item[v8]._iAC += (plr[myplr]._pMaxManaBase >> 6) / 10;
    break;
  case IPL_FIRERESCLVL:
    v41 = 30 - plr[myplr]._pLevel;
    v42 = &item[v8]._iPLFR;
    *v42 = v41;
    if (v41 < 0)
      *v42 = 0;
    break;
  case IPL_AC_CURSE:
    v12 = &item[v8]._iAC;
  LABEL_62:
    *v12 -= v10;
    break;
  default:
    break;
  }
  v43 = v8;
  if (item[v43]._iVAdd1 || item[v43]._iVMult1) {
    item[v43]._iVAdd2 = PLVal(v10, param1, param2, minval, maxval);
    item[v43]._iVMult2 = multval;
  } else {
    item[v43]._iVAdd1 = PLVal(v10, param1, param2, minval, maxval);
    item[v43]._iVMult1 = multval;
  }
}

//----- (004215EF) --------------------------------------------------------
void __fastcall GetItemPower(int i, int minlvl, int maxlvl, int flgs,
                             int onlygood) {
  // int v6; // ecx
  int pre; // esi
  // int v9; // ecx
  unsigned char goe; // bl
  int v11;           // edx
  int v14;           // ecx
  int l[256];        // [esp+4h] [ebp-494h]
  char istr[128];    // [esp+404h] [ebp-94h]
  int post;          // [esp+488h] [ebp-10h]
  int sufidx;        // [esp+48Ch] [ebp-Ch]
  int preidx;        // [esp+490h] [ebp-8h]

  pre = random(23, 4);
  post = random(23, 3);
  if (pre && !post) {
    if (random(23, 2))
      post = 1;
    else
      pre = 0;
  }
  preidx = -1;
  sufidx = -1;
  goe = 0;
  if (!onlygood) {
    if (random(0, 3))
      onlygood = 1;
  }
  if (!pre) {
    v11 = 0;
    if (PL_Prefix[0].PLPower != -1) {
      v14 = 0;
      do {
        if (flgs & PL_Prefix[v14].PLIType) {
          if (PL_Prefix[v14].PLMinLvl >= minlvl &&
              PL_Prefix[v14].PLMinLvl <= maxlvl &&
              (!onlygood || PL_Prefix[v14].PLOk) &&
              (flgs != 256 || PL_Prefix[v14].PLPower != 15)) {
            l[v11++] = v14;
            if (PL_Prefix[v14].PLDouble)
              l[v11++] = v14;
          }
        }
        v14++;
      } while (PL_Prefix[v14].PLPower != -1);
      if (v11) {
        preidx = l[random(23, v11)];
        sprintf(istr, "%s %s", PL_Prefix[preidx].PLName, item[i]._iIName);
        strcpy(item[i]._iIName, istr);
        item[i]._iMagical = 1;
        SaveItemPower(i, PL_Prefix[preidx].PLPower, PL_Prefix[preidx].PLParam1,
                      PL_Prefix[preidx].PLParam2, PL_Prefix[preidx].PLMinVal,
                      PL_Prefix[preidx].PLMaxVal, PL_Prefix[preidx].PLMultVal);
        goe = PL_Prefix[preidx].PLGOE;
        item[i]._iPrePower = PL_Prefix[preidx].PLPower;
      }
    }
  }
  if (post) {
    v11 = 0;
    if (PL_Suffix[0].PLPower != -1) {
      v14 = 0;
      do {
        if (flgs & PL_Suffix[v14].PLIType) {
          if (PL_Suffix[v14].PLMinLvl >= minlvl &&
              PL_Suffix[v14].PLMinLvl <= maxlvl &&
              (goe | PL_Suffix[v14].PLGOE) != 0x11 &&
              (!onlygood || PL_Suffix[v14].PLOk))
            l[v11++] = v14;
        }
        v14++;
      } while (PL_Suffix[v14].PLPower != -1);
      if (v11) {
        sufidx = l[random(23, v11)];
        sprintf(istr, "%s of %s", item[i]._iIName, PL_Suffix[sufidx].PLName);
        strcpy(item[i]._iIName, istr);
        item[i]._iMagical = 1;
        SaveItemPower(i, PL_Suffix[sufidx].PLPower, PL_Suffix[sufidx].PLParam1,
                      PL_Suffix[sufidx].PLParam2, PL_Suffix[sufidx].PLMinVal,
                      PL_Suffix[sufidx].PLMaxVal, PL_Suffix[sufidx].PLMultVal);
        item[i]._iSufPower = PL_Suffix[sufidx].PLPower;
      }
    }
  }
  if (!control_WriteStringToBuffer(item[i]._iIName)) {
    strcpy(item[i]._iIName, AllItemsList[item[i].IDidx].iSName);
    if (preidx != -1) {
      sprintf(istr, "%s %s", PL_Prefix[preidx].PLName, item[i]._iIName);
      strcpy(item[i]._iIName, istr);
    }
    if (sufidx != -1) {
      sprintf(istr, "%s of %s", item[i]._iIName, PL_Suffix[sufidx].PLName);
      strcpy(item[i]._iIName, istr);
    }
  }
  if (preidx != -1 || sufidx != -1)
    CalcItemValue(i);
}
// 4215EF: using guessed type int var_494[256];

//----- (0042191C) --------------------------------------------------------
void __fastcall GetItemBonus(int i, int idata, int minlvl, int maxlvl,
                             int onlygood) {
  if (item[i]._iClass != ICLASS_GOLD) {
    if (minlvl > 25)
      minlvl = 25;

    switch (item[i]._itype) {
    case ITYPE_SWORD:
    case ITYPE_AXE:
    case ITYPE_MACE:
      GetItemPower(i, minlvl, maxlvl, 0x1000, onlygood);
      break;
    case ITYPE_BOW:
      GetItemPower(i, minlvl, maxlvl, 0x10, onlygood);
      break;
    case ITYPE_SHIELD:
      GetItemPower(i, minlvl, maxlvl, 0x10000, onlygood);
      break;
    case ITYPE_LARMOR:
    case ITYPE_HELM:
    case ITYPE_MARMOR:
    case ITYPE_HARMOR:
      GetItemPower(i, minlvl, maxlvl, 0x100000, onlygood);
      break;
    case ITYPE_STAFF:
      GetStaffSpell(i, maxlvl, onlygood);
      break;
    case ITYPE_RING:
    case ITYPE_AMULET:
      GetItemPower(i, minlvl, maxlvl, 1, onlygood);
      break;
    default:
      return;
    }
  }
}

//----- (004219C1) --------------------------------------------------------
void __fastcall SetupItem(int i) {
  int it; // eax
  int il; // eax

  it = ItemCAnimTbl[item[i]._iCurs];
  item[i]._iAnimWidth = 96;
  item[i]._iAnimWidth2 = 16;
  il = ItemAnimLs[it];
  item[i]._iAnimData = Item2Frm[it];
  item[i]._iAnimLen = il;
  item[i]._iIdentified = 0;
  item[i]._iPostDraw = 0;

  if (!plr[myplr].pLvlLoad) {
    item[i]._iSelFlag = 0;
    il = 1;
    item[i]._iAnimFlag = 1;
  } else {
    item[i]._iAnimFlag = 0;
    item[i]._iSelFlag = 1;
  }

  item[i]._iAnimFrame = il;
}

//----- (00421A4B) --------------------------------------------------------
int __fastcall RndItem(int m) {
  int ri;       // esi
  int i;        // edx
  int ril[512]; // [esp+4h] [ebp-800h]

  if (monster[m].MData->mTreasure & 0x8000)
    return -1 - (monster[m].MData->mTreasure & 0xFFF);
  if (monster[m].MData->mTreasure & 0x4000)
    return 0;

  if (random(24, 100) > 40)
    return 0;
  if (random(24, 100) > 25)
    return 1;

  ri = 0;
  i = 0;
  if (AllItemsList[0].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd == 2 &&
          monster[m].mLevel >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      if (AllItemsList[i].iRnd && monster[m].mLevel >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      if (AllItemsList[i].iSpell == SPL_RESURRECT && gbMaxPlayers == 1)
        --ri;
      if (AllItemsList[i].iSpell == SPL_HEALOTHER && gbMaxPlayers == 1)
        --ri;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }

  return ril[random(24, ri)] + 1;
}
// 679660: using guessed type char gbMaxPlayers;
// 421A4B: using guessed type int var_800[512];

//----- (00421B32) --------------------------------------------------------
int __fastcall RndUItem(int m) {
  int ri;       // edx
  int i;        // ebp
  bool okflag;  // edi
  int ril[512]; // [esp+0h] [ebp-800h]

  if (m != -1) {
    if (monster[m].MData->mTreasure < 0 && gbMaxPlayers == 1)
      return -1 - (monster[m].MData->mTreasure & 0xFFF);
  }
  ri = 0;
  i = 0;
  if (AllItemsList[0].iLoc != -1) {
    do {
      okflag = 1;
      if (!AllItemsList[i].iRnd)
        okflag = 0;
      if (m == -1) {
        if (2 * currlevel - AllItemsList[i].iMinMLvl < 0)
          okflag = 0;
      } else {
        if (monster[m].mLevel - AllItemsList[i].iMinMLvl < 0)
          okflag = 0;
      }
      if (!AllItemsList[i].itype)
        okflag = 0;
      if (AllItemsList[i].itype == ITYPE_GOLD)
        okflag = 0;
      if (AllItemsList[i].itype == ITYPE_0E)
        okflag = 0;
      if (AllItemsList[i].iMiscId == IMISC_BOOK)
        okflag = 1;
      if (AllItemsList[i].iSpell == SPL_RESURRECT && gbMaxPlayers == 1)
        okflag = 0;
      if (AllItemsList[i].iSpell == SPL_HEALOTHER && gbMaxPlayers == 1)
        okflag = 0;
      if (okflag)
        ril[ri++] = i;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }

  return ril[random(25, ri)];
}
// 679660: using guessed type char gbMaxPlayers;
// 421B32: using guessed type int var_800[512];

//----- (00421C2A) --------------------------------------------------------
int __cdecl RndAllItems() {
  int ri;       // esi
  int i;        // edi
  int ril[512]; // [esp+0h] [ebp-800h]

  if (random(26, 100) > 25)
    return 0;

  ri = 0;
  i = 0;
  if (AllItemsList[0].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd && 2 * currlevel >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      if (AllItemsList[i].iSpell == SPL_RESURRECT && gbMaxPlayers == 1)
        --ri;
      if (AllItemsList[i].iSpell == SPL_HEALOTHER && gbMaxPlayers == 1)
        --ri;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(26, ri)];
}
// 679660: using guessed type char gbMaxPlayers;
// 421C2A: using guessed type int var_800[512];

//----- (00421CB7) --------------------------------------------------------
int __fastcall RndTypeItems(int itype, int imid) {
  int i;        // edi
  bool okflag;  // esi
  int ril[512]; // [esp+4h] [ebp-80Ch]
  int ri;       // [esp+80Ch] [ebp-4h]

  ri = 0;
  i = 0;

  if (AllItemsList[0].iLoc != -1) {
    do {
      okflag = 1;
      if (!AllItemsList[i].iRnd)
        okflag = 0;
      if (2 * currlevel < AllItemsList[i].iMinMLvl)
        okflag = 0;
      if (AllItemsList[i].itype != itype)
        okflag = 0;
      if (imid != -1 && AllItemsList[i].iMiscId != imid)
        okflag = 0;
      if (okflag)
        ril[ri++] = i;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }

  return ril[random(27, ri)];
}
// 421CB7: using guessed type int var_80C[512];

//----- (00421D41) --------------------------------------------------------
int __fastcall CheckUnique(int i, int lvl, int uper, bool recreate) {
  int numu;      // ebx
  int j;         // esi
  int idata;     // eax
  char uok[128]; // [esp+8h] [ebp-84h]

  if (random(28, 100) > uper)
    return -1;
  numu = 0;
  memset(uok, 0, 0x80u);

  if (UniqueItemList[0].UIItemId == -1)
    return -1;
  j = 0;
  do {
    if (UniqueItemList[j].UIItemId == AllItemsList[item[i].IDidx].iItemId &&
        lvl >= UniqueItemList[j].UIMinLvl &&
        (recreate || !UniqueItemFlag[j] || gbMaxPlayers != 1)) {
      uok[j] = 1;
      ++numu;
    }
    j++;
  } while (UniqueItemList[j].UIItemId != -1);
  if (!numu)
    return -1;

  random(29, 10);
  idata = 0;
  if (numu > 0) {
    while (1) {
      if (uok[idata])
        --numu;
      if (numu <= 0)
        break;
      if (++idata == 128)
        idata = 0;
    }
  }
  return idata;
}
// 679660: using guessed type char gbMaxPlayers;
// 421D41: using guessed type char var_84[128];

//----- (00421E11) --------------------------------------------------------
void __fastcall GetUniqueItem(int i, int uid) {
  UniqueItemFlag[uid] = 1;
  SaveItemPower(i, UniqueItemList[uid].UIPower1, UniqueItemList[uid].UIParam1,
                UniqueItemList[uid].UIParam2, 0, 0, 1);

  if (UniqueItemList[uid].UINumPL > 1)
    SaveItemPower(i, UniqueItemList[uid].UIPower2, UniqueItemList[uid].UIParam3,
                  UniqueItemList[uid].UIParam4, 0, 0, 1);
  if (UniqueItemList[uid].UINumPL > 2)
    SaveItemPower(i, UniqueItemList[uid].UIPower3, UniqueItemList[uid].UIParam5,
                  UniqueItemList[uid].UIParam6, 0, 0, 1);
  if (UniqueItemList[uid].UINumPL > 3)
    SaveItemPower(i, UniqueItemList[uid].UIPower4, UniqueItemList[uid].UIParam7,
                  UniqueItemList[uid].UIParam8, 0, 0, 1);
  if (UniqueItemList[uid].UINumPL > 4)
    SaveItemPower(i, UniqueItemList[uid].UIPower5, UniqueItemList[uid].UIParam9,
                  UniqueItemList[uid].UIParam10, 0, 0, 1);
  if (UniqueItemList[uid].UINumPL > 5)
    SaveItemPower(i, UniqueItemList[uid].UIPower6,
                  UniqueItemList[uid].UIParam11, UniqueItemList[uid].UIParam12,
                  0, 0, 1);

  strcpy(item[i]._iIName, UniqueItemList[uid].UIName);
  item[i]._iIvalue = UniqueItemList[uid].UIValue;

  if (item[i]._iMiscId == IMISC_UNIQUE)
    item[i]._iSeed = uid;

  item[i]._iCreateInfo |= 0x0200;
  item[i]._iUid = uid;
  item[i]._iMagical = 2;
}

//----- (00421F5C) --------------------------------------------------------
void __fastcall SpawnUnique(int uid, int x, int y) {
  int ii;    // esi
  int itype; // edx

  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itype = 0;
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];

    if (AllItemsList[0].iItemId != UniqueItemList[uid].UIItemId) {
      while (AllItemsList[itype].iItemId != UniqueItemList[uid].UIItemId) {
        itype++;
      }
    }

    GetItemAttrs(ii, itype, currlevel);
    GetUniqueItem(ii, uid);
    SetupItem(ii);
    ++numitems;
  }
}
// 421F5C: could not find valid save-restore pair for esi

//----- (00421FE6) --------------------------------------------------------
void __fastcall ItemRndDur(int ii) {
  if (item[ii]._iDurability && item[ii]._iDurability != 255)
    item[ii]._iDurability =
        random(0, item[ii]._iMaxDur >> 1) + (item[ii]._iMaxDur >> 2) + 1;
}

//----- (00422024) --------------------------------------------------------
void __fastcall SetupAllItems(int ii, int idx, int iseed, int lvl, int uper,
                              int onlygood, int recreate, int pregen) {
  int iblvl; // edi
  int uid;   // eax

  item[ii]._iSeed = iseed;
  SetRndSeed(iseed);
  GetItemAttrs(ii, idx, lvl >> 1);
  item[ii]._iCreateInfo = lvl;

  if (pregen)
    item[ii]._iCreateInfo = lvl | 0x8000;
  if (onlygood)
    item[ii]._iCreateInfo |= 0x40;

  if (uper == 15)
    item[ii]._iCreateInfo |= 0x80;
  else if (uper == 1)
    item[ii]._iCreateInfo |= 0x0100;

  if (item[ii]._iMiscId == IMISC_UNIQUE) {
    if (item[ii]._iLoc != ILOC_UNEQUIPABLE)
      GetUniqueItem(ii, iseed);
  } else {
    iblvl = -1;
    if (random(32, 100) > 10 && random(33, 100) > lvl ||
        (iblvl = lvl, lvl == -1)) {

      if (item[ii]._iMiscId != IMISC_STAFF || (iblvl = lvl, lvl == -1)) {
        if (item[ii]._iMiscId != IMISC_RING || (iblvl = lvl, lvl == -1)) {
          if (item[ii]._iMiscId == IMISC_AMULET)
            iblvl = lvl;
        }
      }
    }
    if (onlygood)
      iblvl = lvl;
    if (uper == 15)
      iblvl = lvl + 4;
    if (iblvl != -1) {
      uid = CheckUnique(ii, iblvl, uper, recreate);
      if (uid == -1) {
        GetItemBonus(ii, idx, iblvl >> 1, iblvl, onlygood);
      } else {
        GetUniqueItem(ii, uid);
        item[ii]._iCreateInfo |= 0x0200;
      }
    }
    if (item[ii]._iMagical != 2)
      ItemRndDur(ii);
  }
  SetupItem(ii);
}

//----- (0042217A) --------------------------------------------------------
void __fastcall SpawnItem(int m, int x, int y, unsigned char sendmsg) {
  int ii;       // edi
  int onlygood; // [esp+Ch] [ebp-Ch]
  int idx;      // [esp+14h] [ebp-4h]

  if (!monster[m]._uniqtype &&
      (monster[m].MData->mTreasure >= 0 || gbMaxPlayers == 1)) {
    if (quests[1]._qactive == 2 && quests[1]._qvar1 == 5) {
      idx = 18; // Brain
      quests[1]._qvar1 = 6;
      goto LABEL_13;
    }
    idx = RndItem(m);
    if (!idx)
      return;
    if (idx > 0) {
      onlygood = 0;
      idx--;
      goto LABEL_13;
    }
  LABEL_10:
    SpawnUnique(-1 - idx, x, y);
    return;
  }
  idx = RndUItem(m);
  if (idx < 0)
    goto LABEL_10;
  onlygood = 1;
LABEL_13:
  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];

    if (!monster[m]._uniqtype)
      SetupAllItems(ii, idx, GetRndSeed(), monster[m].MData->mLevel, 1,
                    onlygood, 0, 0);
    else
      SetupAllItems(ii, idx, GetRndSeed(), monster[m].MData->mLevel, 15,
                    onlygood, 0, 0);

    ++numitems;
    if (sendmsg)
      NetSendCmdDItem(0, ii);
  }
}
// 679660: using guessed type char gbMaxPlayers;

//----- (00422290) --------------------------------------------------------
void __fastcall CreateItem(int uid, int x, int y) {
  int ii;  // esi
  int idx; // edx

  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    idx = 0;
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];

    if (AllItemsList[0].iItemId != UniqueItemList[uid].UIItemId) {
      while (AllItemsList[idx].iItemId != UniqueItemList[uid].UIItemId) {
        idx++;
      }
    }

    GetItemAttrs(ii, idx, currlevel);
    GetUniqueItem(ii, uid);
    SetupItem(ii);
    ++numitems;
    item[ii]._iMagical = 2;
  }
}
// 422290: could not find valid save-restore pair for esi

//----- (0042232B) --------------------------------------------------------
void __fastcall CreateRndItem(int x, int y, unsigned char onlygood,
                              unsigned char sendmsg, int delta) {
  int idx; // edi
  int ii;  // esi

  if (onlygood)
    idx = RndUItem(-1);
  else
    idx = RndAllItems();

  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];
    SetupAllItems(ii, idx, GetRndSeed(), 2 * currlevel, 1, onlygood, 0, delta);

    if (sendmsg)
      NetSendCmdDItem(0, ii);
    if (delta)
      DeltaAddItem(ii);

    ++numitems;
  }
}

//----- (004223D0) --------------------------------------------------------
void __fastcall SetupAllUseful(int ii, int iseed, int lvl) {
  int idx; // esi

  item[ii]._iSeed = iseed;
  SetRndSeed(iseed);
  idx = 25 - (random(34, 2) != 0);

  if (lvl > 1) {
    if (!random(34, 3))
      idx = 27; // unique?
  }

  GetItemAttrs(ii, idx, lvl);
  item[ii]._iCreateInfo = lvl + 0x180;
  SetupItem(ii);
}

//----- (0042243D) --------------------------------------------------------
void __fastcall CreateRndUseful(int pnum, int x, int y, unsigned char sendmsg) {
  int ii; // esi

  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];
    SetupAllUseful(ii, GetRndSeed(), currlevel);

    if (sendmsg)
      NetSendCmdDItem(0, ii);

    ++numitems;
  }
}

//----- (004224A6) --------------------------------------------------------
void __fastcall CreateTypeItem(int x, int y, unsigned char onlygood, int itype,
                               int imisc, int sendmsg, int delta) {
  int idx; // edi
  int ii;  // esi

  if (itype == ITYPE_GOLD)
    idx = 0;
  else
    idx = RndTypeItems(itype, imisc);

  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];
    SetupAllItems(ii, idx, GetRndSeed(), 2 * currlevel, 1, onlygood, 0, delta);

    if (sendmsg)
      NetSendCmdDItem(0, ii);
    if (delta)
      DeltaAddItem(ii);

    ++numitems;
  }
}

//----- (0042254A) --------------------------------------------------------
void __fastcall RecreateItem(int ii, int idx, unsigned short ic, int iseed,
                             int ivalue) {
  int uper;     // esi
  int onlygood; // edx
  int recreate; // ebx
  int pregen;   // edi

  if (idx) {
    if (ic) {
      if (ic & 0x7C00) {
        RecreateTownItem(ii, idx, ic, iseed, ivalue);
      } else if ((ic & 0x0180) == 0x0180) {
        SetupAllUseful(ii, iseed, ic & 0x3F);
      } else {
        uper = 0;
        onlygood = 0;
        recreate = 0;
        pregen = 0;
        if (ic & 0x0100)
          uper = 1;
        if (ic & 0x80)
          uper = 15;
        if (ic & 0x40)
          onlygood = 1;
        if (ic & 0x0200)
          recreate = 1;
        if (ic & 0x8000)
          pregen = 1;
        SetupAllItems(ii, idx, iseed, ic & 0x3F, uper, onlygood, recreate,
                      pregen);
      }
    } else {
      SetPlrHandItem(&item[ii], idx);
      SetPlrHandSeed(&item[ii], iseed);
    }
  } else {
    SetPlrHandItem(&item[ii], IDI_GOLD);
    item[ii]._iSeed = iseed;
    item[ii]._iCreateInfo = ic;
    item[ii]._ivalue = ivalue;
    if (ivalue < 2500) {
      if (ivalue > 1000)
        item[ii]._iCurs = 5;
      else
        item[ii]._iCurs = 4;
    } else {
      item[ii]._iCurs = 6;
    }
  }
}

//----- (0042265C) --------------------------------------------------------
void __fastcall RecreateEar(int ii, unsigned short ic, int iseed,
                            unsigned char Id, int dur, int mdur, int ch,
                            int mch, int ivalue, int ibuff) {
  SetPlrHandItem(&item[ii], IDI_EAR);
  tempstr[0] = (ic >> 8) & 0x7F;
  tempstr[1] = ic & 0x7F;
  tempstr[2] = (iseed >> 24) & 0x7F;
  tempstr[3] = (iseed >> 16) & 0x7F;
  tempstr[4] = (iseed >> 8) & 0x7F;
  tempstr[5] = iseed & 0x7F;
  tempstr[6] = Id & 0x7F;
  tempstr[7] = dur & 0x7F;
  tempstr[8] = mdur & 0x7F;
  tempstr[9] = ch & 0x7F;
  tempstr[10] = mch & 0x7F;
  tempstr[11] = (ivalue >> 8) & 0x7F;
  tempstr[12] = (ibuff >> 24) & 0x7F;
  tempstr[13] = (ibuff >> 16) & 0x7F;
  tempstr[14] = (ibuff >> 8) & 0x7F;
  tempstr[15] = ibuff & 0x7F;
  tempstr[16] = '\0';
  sprintf(item[ii]._iName, "Ear of %s", tempstr);
  item[ii]._iCurs = ((ivalue >> 6) & 3) + 19;
  item[ii]._iCreateInfo = ic;
  item[ii]._ivalue = ivalue & 0x3F;
  item[ii]._iSeed = iseed;
}

//----- (00422795) --------------------------------------------------------
void __fastcall SpawnQuestItem(int itemid, int x, int y, int randarea,
                               int selflag) {
  int i;       // ebx
  BOOL failed; // eax
  int j;       // esi
  int v12;     // ebx
  int v13;     // esi
  int tries;   // [esp+10h] [ebp-4h]

  if (randarea) {
    tries = 0;
    while (1) {
    LABEL_3:
      if (++tries > 1000 && randarea > 1)
        --randarea;

      x = random(0, 112);
      y = random(0, 112);
      i = 0;
      failed = 0;
      if (randarea <= 0)
        break;
      while (!failed) {
        for (j = 0; j < randarea; j++) {
          if (failed)
            break;

          failed = ItemSpaceOk(i + x, j + y) == 0;
        }

        if (++i >= randarea) {
          if (failed)
            goto LABEL_3;
          goto LABEL_13;
        }
      }
    }
  }
LABEL_13:
  if (numitems < 127) {
    v12 = itemavail[0];
    v13 = itemavail[0];
    item[v13]._ix = x;
    itemactive[numitems] = v12;
    item[v13]._iy = y;
    itemavail[0] = itemavail[-numitems + 126]; /* double check */
    dItem[x][y] = v12 + 1;
    GetItemAttrs(v12, itemid, currlevel);
    SetupItem(v12);
    item[v13]._iPostDraw = 1;
    if (selflag) {
      item[v13]._iAnimFlag = 0;
      item[v13]._iSelFlag = selflag;
      item[v13]._iAnimFrame = item[v13]._iAnimLen;
    }
    ++numitems;
  }
}

//----- (004228B1) --------------------------------------------------------
void __cdecl SpawnRock() {
  BOOL v0; // edx
  int v1;  // eax
  int v2;  // ecx
  BOOL v3; // ebx
  int v4;  // ebx
  int v5;  // ecx
  int v6;  // esi
  int *v7; // edx
  int v8;  // eax
  int v9;  // edi
  int v10; // ST04_4
  // int v11; // [esp+8h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  if (nobjects > 0) {
    v2 = 0; // v11; /* chceck */
    while (!v0) {
      v2 = objectactive[v1];
      v3 = object[objectactive[v1++]]._otype == OBJ_STAND;
      v0 = v3;
      if (v1 >= nobjects) {
        if (!v3)
          return;
        break;
      }
    }
    v4 = itemavail[0];
    v5 = v2;
    v6 = itemavail[0];
    v7 = &itemavail[-numitems + 126];
    itemactive[numitems] = itemavail[0];
    v8 = object[v5]._ox;
    item[v6]._ix = v8;
    v9 = object[v5]._oy;
    itemavail[0] = *v7;
    dItem[v8][v9] = v4 + 1;
    v10 = currlevel;
    item[v6]._iy = v9;
    GetItemAttrs(v4, IDI_ROCK, v10);
    SetupItem(v4);
    ++numitems;
    item[v6]._iSelFlag = 2;
    item[v6]._iPostDraw = 1;
    item[v6]._iAnimFrame = 11;
  }
}

//----- (00422989) --------------------------------------------------------
void __fastcall RespawnItem(int i, bool FlipFlag) {
  int it; // ecx
  int il; // eax

  item[i]._iAnimWidth = 96;
  item[i]._iAnimWidth2 = 16;
  it = ItemCAnimTbl[item[i]._iCurs];
  il = ItemAnimLs[it];
  item[i]._iAnimLen = il;
  item[i]._iAnimData = Item2Frm[it];
  item[i]._iPostDraw = 0;
  item[i]._iRequest = 0;

  if (FlipFlag) {
    item[i]._iSelFlag = 0;
    il = 1;
    item[i]._iAnimFlag = 1;
  } else {
    item[i]._iAnimFlag = 0;
    item[i]._iSelFlag = 1;
  }

  item[i]._iAnimFrame = il;

  if (item[i]._iCurs == 76) // Magic Rock
  {
    item[i]._iSelFlag = 1;
    PlaySfxLoc(ItemDropSnds[it], item[i]._ix, item[i]._iy);
  }
  if (item[i]._iCurs == 126) // Tavern Sign
    item[i]._iSelFlag = 1;
  if (item[i]._iCurs == 140) // Anvil of Fury
    item[i]._iSelFlag = 1;
}

//----- (00422A50) --------------------------------------------------------
void __fastcall DeleteItem(int ii, int i) {
  int v2;  // eax
  bool v3; // zf
  bool v4; // sf

  v2 = numitems - 1;
  v3 = numitems == 1;
  v4 = numitems - 1 < 0;
  itemavail[-numitems + 127] = ii;
  numitems = v2;
  if (!v4 && !v3 && i != v2)
    itemactive[i] = itemactive[v2];
}

//----- (00422A84) --------------------------------------------------------
void __cdecl ItemDoppel() {
  int idoppelx;  // esi
  ItemStruct *i; // edx

  if (gbMaxPlayers != 1) {
    for (idoppelx = 16; idoppelx < 96; idoppelx++) {
      if (dItem[idoppelx][idoppely]) {
        i = &item[dItem[idoppelx][idoppely] - 1];
        if (i->_ix != idoppelx || i->_iy != idoppely)
          dItem[idoppelx][idoppely] = 0;
      }
    }

    if (idoppely++ == 95)
      idoppely = 16;
  }
}
// 492EAC: using guessed type int idoppely;
// 679660: using guessed type char gbMaxPlayers;

//----- (00422ADE) --------------------------------------------------------
void __cdecl ProcessItems() {
  int i;  // edi
  int ii; // esi

  for (i = 0; i < numitems; i++) {
    ii = itemactive[i];
    if (item[ii]._iAnimFlag) {
      item[ii]._iAnimFrame++;
      if (item[ii]._iCurs == 76) // Magic Rock
      {
        if (item[ii]._iSelFlag == 1 && item[ii]._iAnimFrame == 11)
          item[ii]._iAnimFrame = 1;
        if (item[ii]._iSelFlag == 2 && item[ii]._iAnimFrame == 21)
          item[ii]._iAnimFrame = 11;
      } else {
        if (item[ii]._iAnimFrame == item[ii]._iAnimLen >> 1)
          PlaySfxLoc(ItemDropSnds[ItemCAnimTbl[item[ii]._iCurs]], item[ii]._ix,
                     item[ii]._iy);

        if (item[ii]._iAnimFrame >= item[ii]._iAnimLen) {
          item[ii]._iAnimFlag = 0;
          item[ii]._iAnimFrame = item[ii]._iAnimLen;
          item[ii]._iSelFlag = 1;
        }
      }
    }
  }
  ItemDoppel();
}

//----- (00422BB2) --------------------------------------------------------
void __cdecl FreeItemGFX() {
  int i;    // esi
  void *v1; // ecx

  for (i = 0; i < 35; i++) {
    v1 = (void *)Item2Frm[i];
    Item2Frm[i] = 0;
    mem_free_dbg(v1);
  }
}

//----- (00422BCF) --------------------------------------------------------
void __fastcall GetItemFrm(int i) {
  item[i]._iAnimData = Item2Frm[ItemCAnimTbl[item[i]._iCurs]];
}

//----- (00422BF0) --------------------------------------------------------
void __fastcall GetItemStr(int i) {
  int nGold; // esi

  if (item[i]._itype == ITYPE_GOLD) {
    nGold = item[i]._ivalue;
    sprintf(infostr, "%i gold %s", nGold, get_pieces_str(nGold));
  } else {
    if (!item[i]._iIdentified)
      strcpy(infostr, item[i]._iName);
    else
      strcpy(infostr, item[i]._iIName);

    if (item[i]._iMagical == 1)
      infoclr = COL_BLUE;
    if (item[i]._iMagical == 2)
      infoclr = COL_GOLD;
  }
}
// 4B883C: using guessed type int infoclr;

//----- (00422C63) --------------------------------------------------------
void __fastcall CheckIdentify(int pnum, int cii) {
  ItemStruct *pi; // esi

  pi = &plr[pnum].InvBody[cii];
  pi->_iIdentified = 1;

  CalcPlrInv(pnum, 1);

  if (pnum == myplr)
    SetCursor(CURSOR_HAND);
}

//----- (00422C9C) --------------------------------------------------------
void __fastcall DoRepair(int pnum, int cii) {
  PlayerStruct *p; // eax
  ItemStruct *pi;  // esi

  p = &plr[pnum];
  pi = &p->InvBody[cii];

  PlaySfxLoc(IS_REPAIR, p->WorldX, p->WorldY);
  RepairItem(pi, p->_pLevel);
  CalcPlrInv(pnum, 1);

  if (pnum == myplr)
    SetCursor(CURSOR_HAND);
}

//----- (00422CF6) --------------------------------------------------------
void __fastcall RepairItem(ItemStruct *i, int lvl) {
  int rep; // edi
  int d;   // eax

  if (i->_iDurability != i->_iMaxDur) {
    if (i->_iMaxDur > 0) {
      rep = 0;
      while (1) {
        rep += lvl + random(37, lvl);
        d = i->_iMaxDur / (lvl + 9);

        if (d < 1)
          d = 1;
        if (i->_iMaxDur == d)
          break;

        i->_iMaxDur -= d;

        if (rep + i->_iDurability >= i->_iMaxDur) {
          i->_iDurability += rep;
          if (i->_iDurability > i->_iMaxDur)
            i->_iDurability = i->_iMaxDur;
          return;
        }
      }
    }
    i->_itype = -1;
  }
}

//----- (00422D6C) --------------------------------------------------------
void __fastcall DoRecharge(int pnum, int cii) {
  PlayerStruct *p; // eax
  ItemStruct *pi;  // esi

  p = &plr[pnum];
  pi = &p->InvBody[cii];

  if (pi->_itype == ITYPE_STAFF && pi->_iSpell) {
    RechargeItem(pi,
                 random(38, p->_pLevel / spelldata[pi->_iSpell].sBookLvl) + 1);
    CalcPlrInv(pnum, 1);
  }

  if (pnum == myplr)
    SetCursor(CURSOR_HAND);
}

//----- (00422DDD) --------------------------------------------------------
void __fastcall RechargeItem(ItemStruct *i, int r) {
  if (i->_iCharges != i->_iMaxCharges) {
    while (1) {
      if (i->_iMaxCharges-- == 1)
        break;

      i->_iCharges += r;

      if (i->_iCharges >= i->_iMaxCharges) {
        if (i->_iCharges > i->_iMaxCharges)
          i->_iCharges = i->_iMaxCharges;
        return;
      }
    }
  }
}

//----- (00422E14) --------------------------------------------------------
void __fastcall PrintItemOil(char IDidx) {
  switch (IDidx) {
  case IMISC_FULLHEAL:
    strcpy(tempstr, "fully recover life");
    break;
  case IMISC_HEAL:
    strcpy(tempstr, "recover partial life");
    break;
  case IMISC_OLDHEAL:
    strcpy(tempstr, "recover life");
    break;
  case IMISC_DEADHEAL:
    strcpy(tempstr, "deadly heal");
    break;
  case IMISC_MANA:
    strcpy(tempstr, "recover mana");
    break;
  case IMISC_FULLMANA:
    strcpy(tempstr, "fully recover mana");
    break;
  case IMISC_ELIXSTR:
    strcpy(tempstr, "increase strength");
    break;
  case IMISC_ELIXMAG:
    strcpy(tempstr, "increase magic");
    break;
  case IMISC_ELIXDEX:
    strcpy(tempstr, "increase dexterity");
    break;
  case IMISC_ELIXVIT:
    strcpy(tempstr, "increase vitality");
    break;
  case IMISC_ELIXWEAK:
  case IMISC_ELIXDIS:
    strcpy(tempstr, "decrease strength");
    break;
  case IMISC_ELIXCLUM:
    strcpy(tempstr, "decrease dexterity");
    break;
  case IMISC_ELIXSICK:
    strcpy(tempstr, "decrease vitality");
    break;
  case IMISC_REJUV:
    strcpy(tempstr, "recover life and mana");
    break;
  case IMISC_FULLREJUV:
    strcpy(tempstr, "fully recover life and mana");
    break;
  default:
    return;
  }

  AddPanelString(tempstr, 1);
}

//----- (00422EF4) --------------------------------------------------------
void __fastcall PrintItemPower(char plidx, ItemStruct *x) {
  ItemStruct *v2; // esi
  int *v3;        // esi
  int *v4;        // esi
  int v5;         // esi
  const char *v6; // [esp-4h] [ebp-Ch]
  const char *v7; // [esp-4h] [ebp-Ch]
  const char *v8; // [esp-4h] [ebp-Ch]
  const char *v9; // [esp-4h] [ebp-Ch]

  v2 = x;
  switch (plidx) {
  case IPL_TOHIT:
  case IPL_TOHIT_CURSE:
    sprintf(tempstr, "chance to hit : %+i%%", x->_iPLToHit);
    return;
  case IPL_DAMP:
  case IPL_DAMP_CURSE:
    sprintf(tempstr, "%+i%% damage", x->_iPLDam);
    return;
  case IPL_TOHIT_DAMP:
  case IPL_TOHIT_DAMP_CURSE:
    sprintf(tempstr, "to hit: %+i%%, %+i%% damage", x->_iPLToHit, x->_iPLDam);
    return;
  case IPL_ACP:
  case IPL_ACP_CURSE:
    sprintf(tempstr, "%+i%% armor", x->_iPLAC);
    return;
  case IPL_FIRERES:
    if (x->_iPLFR < 75)
      sprintf(tempstr, "Resist Fire : %+i%%", x->_iPLFR);
    if (v2->_iPLFR >= 75) {
      v6 = "Resist Fire : 75%% MAX";
      goto LABEL_11;
    }
    return;
  case IPL_LIGHTRES:
    if (x->_iPLLR < 75)
      sprintf(tempstr, "Resist Lightning : %+i%%", x->_iPLLR);
    if (v2->_iPLLR >= 75) {
      v6 = "Resist Lightning : 75%% MAX";
      goto LABEL_11;
    }
    return;
  case IPL_MAGICRES:
    if (x->_iPLMR < 75)
      sprintf(tempstr, "Resist Magic : %+i%%", x->_iPLMR);
    if (v2->_iPLMR >= 75) {
      v6 = "Resist Magic : 75%% MAX";
      goto LABEL_11;
    }
    return;
  case IPL_ALLRES:
    if (x->_iPLFR < 75)
      sprintf(tempstr, "Resist All : %+i%%", x->_iPLFR);
    if (v2->_iPLFR >= 75) {
      v6 = "Resist All : 75%% MAX";
    LABEL_11:
      sprintf(tempstr, v6);
    }
    return;
  case IPL_SPLLVLADD:
    if (x->_iSplLvlAdd == 1)
      strcpy(tempstr, "spells are increased 1 level");
    if (v2->_iSplLvlAdd == 2)
      strcpy(tempstr, "spells are increased 2 levels");
    if (v2->_iSplLvlAdd < 1) {
      v7 = "spells are decreased 1 level";
      goto LABEL_81;
    }
    return;
  case IPL_CHARGES:
    v8 = "Extra charges";
    goto LABEL_104;
  case IPL_FIREDAM:
    sprintf(tempstr, "Fire hit damage: %i-%i", x->_iFMinDam, x->_iFMaxDam);
    return;
  case IPL_LIGHTDAM:
    sprintf(tempstr, "Lightning hit damage: %i-%i", x->_iLMinDam, x->_iLMaxDam);
    return;
  case IPL_STR:
  case IPL_STR_CURSE:
    sprintf(tempstr, "%+i to strength", x->_iPLStr);
    return;
  case IPL_MAG:
  case IPL_MAG_CURSE:
    sprintf(tempstr, "%+i to magic", x->_iPLMag);
    return;
  case IPL_DEX:
  case IPL_DEX_CURSE:
    sprintf(tempstr, "%+i to dexterity", x->_iPLDex);
    return;
  case IPL_VIT:
  case IPL_VIT_CURSE:
    sprintf(tempstr, "%+i to vitality", x->_iPLVit);
    return;
  case IPL_ATTRIBS:
  case IPL_ATTRIBS_CURSE:
    sprintf(tempstr, "%+i to all attributes", x->_iPLStr);
    return;
  case IPL_GETHIT_CURSE:
  case IPL_GETHIT:
    sprintf(tempstr, "%+i damage from enemies", x->_iPLGetHit);
    return;
  case IPL_LIFE:
  case IPL_LIFE_CURSE:
    sprintf(tempstr, "Hit Points : %+i", x->_iPLHP >> 6);
    return;
  case IPL_MANA:
  case IPL_MANA_CURSE:
    sprintf(tempstr, "Mana : %+i", x->_iPLMana >> 6);
    return;
  case IPL_DUR:
    v8 = "high durability";
    goto LABEL_104;
  case IPL_DUR_CURSE:
    v8 = "decreased durability";
    goto LABEL_104;
  case IPL_INDESTRUCTIBLE:
    v8 = "indestructible";
    goto LABEL_104;
  case IPL_LIGHT:
    sprintf(tempstr, "+%i%% light radius", 10 * x->_iPLLight);
    return;
  case IPL_LIGHT_CURSE:
    sprintf(tempstr, "-%i%% light radius", -10 * x->_iPLLight);
    return;
  case IPL_FIRE_ARROWS:
    sprintf(tempstr, "fire arrows damage: %i-%i", x->_iFMinDam, x->_iFMaxDam);
    return;
  case IPL_LIGHT_ARROWS:
    sprintf(tempstr, "lightning arrows damage %i-%i", x->_iLMinDam,
            x->_iLMaxDam);
    return;
  case IPL_INVCURS:
    v8 = " ";
    goto LABEL_104;
  case IPL_THORNS:
    v8 = "attacker takes 1-3 damage";
    goto LABEL_104;
  case IPL_NOMANA:
    v8 = "user loses all mana";
    goto LABEL_104;
  case IPL_NOHEALPLR:
    v8 = "you can't heal";
    goto LABEL_104;
  case IPL_ABSHALFTRAP:
    v8 = "absorbs half of trap damage";
    goto LABEL_104;
  case IPL_KNOCKBACK:
    v8 = "knocks target back";
    goto LABEL_104;
  case IPL_NOHEALMON:
    v8 = "hit monster doesn't heal";
    goto LABEL_104;
  case IPL_STEALMANA:
    v3 = &x->_iFlags;
    if (x->_iFlags & 0x2000)
      strcpy(tempstr, "hit steals 3% mana");
    if (!(*((_BYTE *)v3 + 1) & 0x40))
      return;
    v7 = "hit steals 5% mana";
    goto LABEL_81;
  case IPL_STEALLIFE:
    v4 = &x->_iFlags;
    if ((x->_iFlags & 0x8000) != 0)
      strcpy(tempstr, "hit steals 3% life");
    if (!(*((_BYTE *)v4 + 2) & 1))
      return;
    v7 = "hit steals 5% life";
    goto LABEL_81;
  case IPL_TARGAC:
    v8 = "damages target's armor";
    goto LABEL_104;
  case IPL_FASTATTACK:
    if (x->_iFlags & 0x20000)
      strcpy(tempstr, "quick attack");
    if (v2->_iFlags & 0x40000)
      strcpy(tempstr, "fast attack");
    if (v2->_iFlags & 0x80000)
      strcpy(tempstr, "faster attack");
    if (!(v2->_iFlags & 0x100000))
      return;
    v7 = "fastest attack";
    goto LABEL_81;
  case IPL_FASTRECOVER:
    if (x->_iFlags & 0x200000)
      strcpy(tempstr, "fast hit recovery");
    if (v2->_iFlags & 0x400000)
      strcpy(tempstr, "faster hit recovery");
    if ((v2->_iFlags & 0x800000) != 0) {
      v7 = "fastest hit recovery";
    LABEL_81:
      strcpy(tempstr, v7);
    }
    return;
  case IPL_FASTBLOCK:
    v8 = "fast block";
    goto LABEL_104;
  case IPL_DAMMOD:
    sprintf(tempstr, "adds %i points to damage", x->_iPLDamMod);
    return;
  case IPL_RNDARROWVEL:
    v8 = "fires random speed arrows";
    goto LABEL_104;
  case IPL_SETDAM:
    v9 = "unusual item damage";
    goto LABEL_98;
  case IPL_SETDUR:
    v8 = "altered durability";
    goto LABEL_104;
  case IPL_NOMINSTR:
    v8 = "no strength requirement";
    goto LABEL_104;
  case IPL_SPELL:
    sprintf(tempstr, "%i %s charges", x->_iMaxCharges,
            spelldata[x->_iSpell].sNameText);
    return;
  case IPL_FASTSWING:
    v8 = "Faster attack swing";
    goto LABEL_104;
  case IPL_ONEHAND:
    v8 = "one handed sword";
    goto LABEL_104;
  case IPL_3XDAMVDEM:
    v8 = "+200% damage vs. demons";
    goto LABEL_104;
  case IPL_ALLRESZERO:
    v8 = "All Resistance equals 0";
    goto LABEL_104;
  case IPL_DRAINLIFE:
    v8 = "constantly lose hit points";
    goto LABEL_104;
  case IPL_RNDSTEALLIFE:
    v8 = "life stealing";
    goto LABEL_104;
  case IPL_INFRAVISION:
    v8 = "see with infravision";
    goto LABEL_104;
  case IPL_SETAC:
  case IPL_AC_CURSE:
    sprintf(tempstr, "armor class: %i", x->_iAC);
    return;
  case IPL_ADDACLIFE:
    v8 = "Armor class added to life";
    goto LABEL_104;
  case IPL_ADDMANAAC:
    v8 = "10% of mana added to armor";
    goto LABEL_104;
  case IPL_FIRERESCLVL:
    v5 = x->_iPLFR;
    if (v5 > 0) {
      if (v5 >= 1)
        sprintf(tempstr, "Resist Fire : %+i%%", v5);
    } else {
      v9 = " ";
    LABEL_98:
      sprintf(tempstr, v9);
    }
    break;
  default:
    v8 = "Another ability (NW)";
  LABEL_104:
    strcpy(tempstr, v8);
    break;
  }
}

//----- (00423530) --------------------------------------------------------
void __cdecl DrawUBack() {
  char *v0;      // edi
  signed int v1; // edx
  signed int v2; // ecx
  int v3;        // edi
  signed int v4; // ecx
  _BYTE *v5;     // edi
  signed int v6; // ecx

  CelDecodeOnly(88, 487, pSTextBoxCels, 1, 271);
  v0 = &gpBuffer->row[324].pixels[27];
  v1 = 148;
  do {
    v2 = 132;
    do {
      *v0 = 0;
      v0 += 2;
      --v2;
    } while (v2);
    *v0 = 0;
    v3 = (int)(v0 - 1032);
    v4 = 132;
    do {
      v5 = (_BYTE *)(v3 + 1);
      *v5 = 0;
      v3 = (int)(v5 + 1);
      --v4;
    } while (v4);
    v0 = (char *)(v3 - 1032);
    --v1;
  } while (v1);
  v6 = 132;
  do {
    *v0 = 0;
    v0 += 2;
    --v6;
  } while (v6);
  *v0 = 0;
}

//----- (0042358C) --------------------------------------------------------
void __fastcall PrintUString(int x, int y, int cjustflag, char *str, int col) {
  char *v5;          // edi
  int v6;            // ebx
  size_t v7;         // eax
  int v8;            // esi
  int v9;            // ecx
  signed int v10;    // eax
  int v11;           // edx
  int v12;           // eax
  unsigned char v13; // al
  int v14;           // edi
  int v15;           // [esp+Ch] [ebp-4h]
  int a3;            // [esp+18h] [ebp+8h]

  v5 = str;
  v6 = screen_y_times_768[SStringY[y] + 204] + x + 96;
  v7 = strlen(str);
  v8 = 0;
  v9 = 0;
  v15 = v7;
  if (cjustflag) {
    v10 = 0;
    if (v15 <= 0)
      goto LABEL_16;
    do {
      v11 = (unsigned char)str[v9++];
      v10 += fontkern[fontframe[fontidx[v11]]] + 1;
    } while (v9 < v15);
    if (v10 < 257)
    LABEL_16:
      v8 = (257 - v10) >> 1;
    v6 += v8;
  }
  v12 = 0;
  a3 = 0;
  if (v15 > 0) {
    while (1) {
      v13 = fontframe[fontidx[(unsigned char)v5[v12]]];
      v14 = v13;
      v8 += fontkern[v13] + 1;
      if (v13) {
        if (v8 <= 257)
          CPrintString(v6, v13, col);
      }
      v6 += fontkern[v14] + 1;
      v12 = a3++ + 1;
      if (a3 >= v15)
        break;
      v5 = str;
    }
  }
}

//----- (0042365B) --------------------------------------------------------
void __fastcall DrawULine(int y) {
  char *v1;      // esi
  char *v2;      // edi
  signed int v3; // edx

  v1 = &gpBuffer->row[25].pixels[26];
  v2 = &gpBuffer->row_unused_1[0]
            .pixels[screen_y_times_768[SStringY[y] + 198] + 26];
  v3 = 3;
  do {
    qmemcpy(v2, v1, 0x10A); /* find real fix */
    v1 += 264;
    v2 += 264;
    *v2 = *v1;
    v1 += 504;
    v2 += 504;
    --v3;
  } while (v3);
}

//----- (004236A6) --------------------------------------------------------
void __cdecl DrawUniqueInfo() {
  int v0; // esi
  int v1; // esi
  int v2; // edi

  if (!chrflag && !questlog) {
    v0 = curruitem._iUid;
    DrawUBack();
    v1 = v0;
    PrintUString(0, 2, 1, UniqueItemList[v1].UIName, 3);
    DrawULine(5);
    PrintItemPower(UniqueItemList[v1].UIPower1, &curruitem);
    v2 = 14 - (char)UniqueItemList[v1].UINumPL;
    PrintUString(0, v2, 1, tempstr, 0);
    if (UniqueItemList[v1].UINumPL > 1) {
      PrintItemPower(UniqueItemList[v1].UIPower2, &curruitem);
      PrintUString(0, v2 + 2, 1, tempstr, 0);
    }
    if (UniqueItemList[v1].UINumPL > 2) {
      PrintItemPower(UniqueItemList[v1].UIPower3, &curruitem);
      PrintUString(0, v2 + 4, 1, tempstr, 0);
    }
    if (UniqueItemList[v1].UINumPL > 3) {
      PrintItemPower(UniqueItemList[v1].UIPower4, &curruitem);
      PrintUString(0, v2 + 6, 1, tempstr, 0);
    }
    if (UniqueItemList[v1].UINumPL > 4) {
      PrintItemPower(UniqueItemList[v1].UIPower5, &curruitem);
      PrintUString(0, v2 + 8, 1, tempstr, 0);
    }
    if (UniqueItemList[v1].UINumPL > 5) {
      PrintItemPower(UniqueItemList[v1].UIPower6, &curruitem);
      PrintUString(0, v2 + 10, 1, tempstr, 0);
    }
  }
}
// 69BD04: using guessed type int questlog;

//----- (004237DC) --------------------------------------------------------
void __fastcall PrintItemMisc(ItemStruct *x) {
  if (x->_iMiscId == IMISC_SCROLL) {
    strcpy(tempstr, "Right-click to read");
    AddPanelString(tempstr, 1);
  }
  if (x->_iMiscId == IMISC_SCROLLT) {
    strcpy(tempstr, "Right-click to read, then");
    AddPanelString(tempstr, 1);
    strcpy(tempstr, "left-click to target");
    AddPanelString(tempstr, 1);
  }
  if (x->_iMiscId >= IMISC_USEFIRST && x->_iMiscId <= IMISC_USELAST) {
    PrintItemOil(x->_iMiscId);
    strcpy(tempstr, "Right click to use");
    AddPanelString(tempstr, 1);
  }
  if (x->_iMiscId == IMISC_BOOK) {
    strcpy(tempstr, "Right click to read");
    AddPanelString(tempstr, 1);
  }
  if (x->_iMiscId == IMISC_MAPOFDOOM) {
    strcpy(tempstr, "Right click to view");
    AddPanelString(tempstr, 1);
  }
  if (x->_iMiscId == IMISC_EAR) {
    sprintf(tempstr, "Level : %i", x->_ivalue);
    AddPanelString(tempstr, 1);
  }
}

//----- (004238D4) --------------------------------------------------------
void __fastcall PrintItemDetails(ItemStruct *x) {
  ItemStruct *v1;   // ebp
  char v2;          // cl
  char v3;          // cl
  char v4;          // al
  unsigned char v5; // al
  char v6;          // al

  v1 = x;
  if (x->_iClass == 1) {
    if (x->_iMaxDur == 255)
      sprintf(tempstr, "damage: %i-%i  Indestructible", x->_iMinDam,
              x->_iMaxDam);
    else
      sprintf(tempstr, "damage: %i-%i  Dur: %i/%i", x->_iMinDam, x->_iMaxDam,
              x->_iDurability, x->_iMaxDur);
    AddPanelString(tempstr, 1);
  }
  if (v1->_iClass == 2) {
    if (v1->_iMaxDur == 255)
      sprintf(tempstr, "armor: %i  Indestructible", v1->_iAC);
    else
      sprintf(tempstr, "armor: %i  Dur: %i/%i", v1->_iAC, v1->_iDurability,
              v1->_iMaxDur);
    AddPanelString(tempstr, 1);
  }
  if (v1->_iMiscId == IMISC_STAFF && v1->_iMaxCharges) {
    sprintf(tempstr, "dam: %i-%i  Dur: %i/%i", v1->_iMinDam, v1->_iMaxDam,
            v1->_iDurability, v1->_iMaxDur);
    sprintf(tempstr, "Charges: %i/%i", v1->_iCharges, v1->_iMaxCharges);
    AddPanelString(tempstr, 1);
  }
  v2 = v1->_iPrePower;
  if (v2 != -1) {
    PrintItemPower(v2, v1);
    AddPanelString(tempstr, 1);
  }
  v3 = v1->_iSufPower;
  if (v3 != -1) {
    PrintItemPower(v3, v1);
    AddPanelString(tempstr, 1);
  }
  if (v1->_iMagical == 2) {
    AddPanelString("unique item", 1);
    uitemflag = 1;
    qmemcpy(&curruitem, v1, sizeof(curruitem));
  }
  PrintItemMisc(v1);
  if ((unsigned char)v1->_iMinMag + v1->_iMinDex + v1->_iMinStr) {
    strcpy(tempstr, "Required:");
    v4 = v1->_iMinStr;
    if (v4)
      sprintf(tempstr, "%s %i Str", tempstr, v4);
    v5 = v1->_iMinMag;
    if (v5)
      sprintf(tempstr, "%s %i Mag", tempstr, v5);
    v6 = v1->_iMinDex;
    if (v6)
      sprintf(tempstr, "%s %i Dex", tempstr, v6);
    AddPanelString(tempstr, 1);
  }
  pinfoflag = 1;
}
// 4B8824: using guessed type int pinfoflag;

//----- (00423AE1) --------------------------------------------------------
void __fastcall PrintItemDur(ItemStruct *x) {
  ItemStruct *v1;   // esi
  int v2;           // eax
  char v3;          // al
  unsigned char v4; // al
  char v5;          // al

  v1 = x;
  if (x->_iClass == 1) {
    if (x->_iMaxDur == 255)
      sprintf(tempstr, "damage: %i-%i  Indestructible", x->_iMinDam,
              x->_iMaxDam);
    else
      sprintf(tempstr, "damage: %i-%i  Dur: %i/%i", x->_iMinDam, x->_iMaxDam,
              x->_iDurability, x->_iMaxDur);
    AddPanelString(tempstr, 1);
    if (v1->_iMiscId == IMISC_STAFF && v1->_iMaxCharges) {
      sprintf(tempstr, "Charges: %i/%i", v1->_iCharges, v1->_iMaxCharges);
      AddPanelString(tempstr, 1);
    }
    if (v1->_iMagical)
      AddPanelString("Not Identified", 1);
  }
  if (v1->_iClass == 2) {
    if (v1->_iMaxDur == 255)
      sprintf(tempstr, "armor: %i  Indestructible", v1->_iAC);
    else
      sprintf(tempstr, "armor: %i  Dur: %i/%i", v1->_iAC, v1->_iDurability,
              v1->_iMaxDur);
    AddPanelString(tempstr, 1);
    if (v1->_iMagical)
      AddPanelString("Not Identified", 1);
    if (v1->_iMiscId == IMISC_STAFF && v1->_iMaxCharges) {
      sprintf(tempstr, "Charges: %i/%i", v1->_iCharges, v1->_iMaxCharges);
      AddPanelString(tempstr, 1);
    }
  }
  v2 = v1->_itype;
  if (v2 == ITYPE_RING || v2 == ITYPE_AMULET)
    AddPanelString("Not Identified", 1);
  PrintItemMisc(v1);
  if ((unsigned char)v1->_iMinMag + v1->_iMinDex + v1->_iMinStr) {
    strcpy(tempstr, "Required:");
    v3 = v1->_iMinStr;
    if (v3)
      sprintf(tempstr, "%s %i Str", tempstr, v3);
    v4 = v1->_iMinMag;
    if (v4)
      sprintf(tempstr, "%s %i Mag", tempstr, v4);
    v5 = v1->_iMinDex;
    if (v5)
      sprintf(tempstr, "%s %i Dex", tempstr, v5);
    AddPanelString(tempstr, 1);
  }
  pinfoflag = 1;
}
// 4B8824: using guessed type int pinfoflag;

//----- (00423CE0) --------------------------------------------------------
void __fastcall UseItem(int p, int Mid, int spl) {
  int v3;           // esi
  int v4;           // edx
  int v5;           // edx
  int v6;           // edx
  int v7;           // edx
  int v8;           // edx
  int v9;           // esi
  int v10;          // esi
  int v11;          // edi
  unsigned int v12; // edi
  char v13;         // al
  int v14;          // edi
  int v15;          // ecx
  int *v16;         // eax
  int *v17;         // eax
  int v18;          // esi
  int v19;          // esi
  int v20;          // edx
  int v21;          // edx
  int v22;          // edx
  int v23;          // edx
  int v24;          // edx
  int v25;          // edi
  char *v26;        // eax
  int v27;          // edx
  int *v28;         // ecx
  int v29;          // eax
  int *v30;         // ecx
  int v31;          // edi
  int v32;          // edi
  int v33;          // eax
  int v34;          // ecx
  int v35;          // eax
  bool v36;         // zf
  int v37;          // ecx
  int v38;          // eax
  int v39;          // edx
  int v40;          // eax
  int v41;          // edx
  int v42;          // esi
  int v43;          // edi
  unsigned int v44; // edi
  char v45;         // al
  int v46;          // edi
  int v47;          // ecx
  int *v48;         // eax
  int v49;          // ecx
  int *v50;         // eax
  int v51;          // edi
  int v52;          // edx
  unsigned int v53; // edi
  char v54;         // al
  int v55;          // edi
  int v56;          // ecx
  int *v57;         // eax
  int *v58;         // eax
  int v59;          // esi
  int v60;          // edx
  int v61;          // esi
  int v62;          // edi
  unsigned int v63; // edi
  char v64;         // al
  int v65;          // edi
  int v66;          // ecx
  int *v67;         // eax
  int *v68;         // eax
  int v69;          // esi
  int v70;          // edx
  int pa;           // [esp+Ch] [ebp-4h]

  v3 = p;
  pa = p;
  if (Mid > 28) {
    v70 = Mid - 42;
    if (!v70) {
      doom_init();
      return;
    }
    if (v70 != 2)
      return;
    ModifyPlrStr(p, 3);
    ModifyPlrMag(v3, 3);
    ModifyPlrDex(v3, 3);
    v60 = 3;
  LABEL_82:
    ModifyPlrVit(v3, v60);
    return;
  }
  if (Mid == 28)
    goto LABEL_71;
  if (Mid <= 12) {
    if (Mid == 12) {
      ModifyPlrDex(p, 1);
      return;
    }
    v4 = Mid - 2;
    if (!v4) {
      v19 = p;
      plr[v19]._pHitPoints = plr[v19]._pMaxHP;
      plr[v19]._pHPBase = plr[p]._pMaxHPBase;
    LABEL_25:
      drawhpflag = 1;
      return;
    }
    v5 = v4 - 1;
    if (v5) {
      v6 = v5 - 3;
      if (v6) {
        v7 = v6 - 1;
        if (v7) {
          v8 = v7 - 3;
          if (v8) {
            if (v8 == 1)
              ModifyPlrMag(p, 1);
          } else {
            ModifyPlrStr(p, 1);
          }
          return;
        }
        v9 = p;
        if (plr[p]._pIFlags & 0x8000000)
          return;
        plr[v9]._pMana = plr[v9]._pMaxMana;
        plr[v9]._pManaBase = plr[v9]._pMaxManaBase;
      LABEL_41:
        drawmanaflag = 1;
        return;
      }
      v10 = p;
      _LOBYTE(p) = 40;
      v11 = plr[v10]._pMaxMana >> 8;
      v12 = (v11 & 0xFFFFFFFE) + 2 * random(p, v11);
      v13 = plr[v10]._pClass;
      v14 = 32 * v12;
      if (v13 == 2)
        v14 *= 2;
      if (v13 == 1)
        v14 += v14 >> 1;
      if (!(plr[v10]._pIFlags & 0x8000000)) {
        v15 = plr[v10]._pMaxMana;
        v16 = &plr[v10]._pMana;
        *v16 += v14;
        if (plr[v10]._pMana > v15)
          *v16 = v15;
        v17 = &plr[v10]._pManaBase;
        v18 = plr[v10]._pMaxManaBase;
        *v17 += v14;
        if (*v17 > v18)
          *v17 = v18;
        goto LABEL_41;
      }
      return;
    }
  LABEL_71:
    v61 = p;
    _LOBYTE(p) = 39;
    v62 = plr[v61]._pMaxHP >> 8;
    v63 = (v62 & 0xFFFFFFFE) + 2 * random(p, v62);
    v64 = plr[v61]._pClass;
    v65 = 32 * v63;
    if (!v64)
      v65 *= 2;
    if (v64 == 1)
      v65 += v65 >> 1;
    v66 = plr[v61]._pMaxHP;
    v67 = &plr[v61]._pHitPoints;
    *v67 += v65;
    if (plr[v61]._pHitPoints > v66)
      *v67 = v66;
    v68 = &plr[v61]._pHPBase;
    v69 = plr[v61]._pMaxHPBase;
    *v68 += v65;
    if (*v68 > v69)
      *v68 = v69;
    goto LABEL_25;
  }
  v20 = Mid - 13;
  if (!v20) {
    v60 = 1;
    goto LABEL_82;
  }
  v21 = v20 - 5;
  if (v21) {
    v22 = v21 - 1;
    if (v22) {
      v23 = v22 - 2;
      if (v23) {
        v24 = v23 - 1;
        if (v24) {
          if (v24 != 2)
            return;
          v25 = p;
          *(_QWORD *)plr[p]._pMemSpells |= (__int64)1
                                           << ((unsigned char)spl - 1);
          v26 = &plr[p]._pSplLvl[spl];
          if (*v26 < 15)
            ++*v26;
          v27 = plr[v25]._pMaxMana;
          v28 = &plr[v25]._pMana;
          v29 = spelldata[spl].sManaCost << 6;
          *v28 += v29;
          if (plr[v25]._pMana > v27)
            *v28 = v27;
          v30 = &plr[v25]._pManaBase;
          v31 = plr[v25]._pMaxManaBase;
          *v30 += v29;
          if (*v30 > v31)
            *v30 = v31;
          if (pa == myplr)
            CalcPlrBookVals(pa);
          goto LABEL_41;
        }
        v32 = spl;
        if (!spelldata[spl].sTargeted) {
          ClrPlrPath(p);
          v33 = v3;
          plr[v33].destParam1 = cursmx;
          v34 = cursmy;
          plr[v33]._pSpell = spl;
          plr[v33]._pSplType = 4;
          plr[v33]._pSplFrom = 3;
          plr[v33].destAction = 12;
          plr[v33].destParam2 = v34;
          return;
        }
      } else {
        v32 = spl;
        if (!spelldata[spl].sTargeted) {
          ClrPlrPath(p);
          v37 = cursmx;
          v38 = v3;
          v39 = cursmy;
          v36 = v3 == myplr;
          plr[v38]._pSpell = spl;
          plr[v38]._pSplType = 4;
          plr[v38]._pSplFrom = 3;
          plr[v38].destAction = 12;
          plr[v38].destParam1 = v37;
          plr[v38].destParam2 = v39;
          if (v36 && spl == SPL_NOVA)
            NetSendCmdLoc(1u, CMD_NOVA, v37, v39);
          return;
        }
      }
      v35 = p;
      v36 = p == myplr;
      plr[v35]._pTSpell = v32;
      _LOBYTE(plr[v35]._pTSplType) = 4;
      if (v36)
        SetCursor(CURSOR_TELEPORT);
      return;
    }
    v40 = p;
    plr[v40]._pHitPoints = plr[p]._pMaxHP;
    plr[v40]._pHPBase = plr[p]._pMaxHPBase;
    v36 = (plr[p]._pIFlags & 0x8000000) == 0;
    drawhpflag = 1;
    if (v36) {
      v41 = plr[v40]._pMaxMana;
      drawmanaflag = 1;
      plr[v40]._pMana = v41;
      plr[v40]._pManaBase = plr[v40]._pMaxManaBase;
    }
  } else {
    v42 = p;
    _LOBYTE(p) = 39;
    v43 = plr[v42]._pMaxHP >> 8;
    v44 = (v43 & 0xFFFFFFFE) + 2 * random(p, v43);
    v45 = plr[v42]._pClass;
    v46 = 32 * v44;
    if (!v45)
      v46 *= 2;
    if (v45 == 1)
      v46 += v46 >> 1;
    v47 = plr[v42]._pMaxHP;
    v48 = &plr[v42]._pHitPoints;
    *v48 += v46;
    if (plr[v42]._pHitPoints > v47)
      *v48 = v47;
    v49 = plr[v42]._pMaxHPBase;
    v50 = &plr[v42]._pHPBase;
    *v50 += v46;
    if (plr[v42]._pHPBase > v49)
      *v50 = v49;
    v51 = plr[v42]._pMaxMana >> 8;
    v52 = plr[v42]._pMaxMana >> 8;
    _LOBYTE(v49) = 40;
    drawhpflag = 1;
    v53 = (v51 & 0xFFFFFFFE) + 2 * random(v49, v52);
    v54 = plr[v42]._pClass;
    v55 = 32 * v53;
    if (v54 == 2)
      v55 *= 2;
    if (v54 == 1)
      v55 += v55 >> 1;
    if (!(plr[v42]._pIFlags & 0x8000000)) {
      v56 = plr[v42]._pMaxMana;
      v57 = &plr[v42]._pMana;
      *v57 += v55;
      if (plr[v42]._pMana > v56)
        *v57 = v56;
      v58 = &plr[v42]._pManaBase;
      v59 = plr[v42]._pMaxManaBase;
      *v58 += v55;
      if (*v58 > v59)
        *v58 = v59;
      drawmanaflag = 1;
    }
  }
}

//----- (004241D7) --------------------------------------------------------
bool __fastcall StoreStatOk(ItemStruct *h) {
  bool sf; // al

  sf = 1;
  if (plr[myplr]._pStrength < h->_iMinStr || plr[myplr]._pMagic < h->_iMinMag ||
      plr[myplr]._pDexterity < h->_iMinDex)
    sf = 0;
  return sf;
}

//----- (0042421C) --------------------------------------------------------
bool __fastcall SmithItemOk(int i) {
  unsigned char v1; // cl
  bool rv;          // eax

  v1 = AllItemsList[i].itype;
  rv = 1;
  if (!v1 || v1 == ITYPE_GOLD || v1 == ITYPE_0E || v1 == ITYPE_STAFF ||
      v1 == ITYPE_RING || v1 == ITYPE_AMULET)
    rv = 0;
  return rv;
}

//----- (00424252) --------------------------------------------------------
int __fastcall RndSmithItem(int lvl) {
  int ri;       // edx
  int i;        // edi
  int ril[512]; // [esp+4h] [ebp-804h]

  ri = 0;
  i = 1;
  if (AllItemsList[1].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd && SmithItemOk(i) &&
          lvl >= AllItemsList[i].iMinMLvl) {
        ril[ri++] = i;
        if (AllItemsList[i].iRnd == 2)
          ril[ri++] = i;
      }
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(50, ri)] + 1;
}
// 424252: using guessed type int var_804[512];

//----- (004242C1) --------------------------------------------------------
void __fastcall BubbleSwapItem(ItemStruct *a, ItemStruct *b) {
  ItemStruct h; // [esp+8h] [ebp-170h]

  qmemcpy(&h, a, sizeof(h));
  qmemcpy(a, b, sizeof(ItemStruct));
  qmemcpy(b, &h, sizeof(ItemStruct));
}

//----- (004242F5) --------------------------------------------------------
void __cdecl SortSmith() {
  int v0;        // esi
  int *v1;       // eax
  signed int v2; // ecx
  int *v3;       // eax
  int v4;        // ebx
  int v5;        // edi

  v0 = 0;
  if (smithitem[1]._itype != -1) {
    v1 = &smithitem[1]._itype;
    do {
      v1 += 92;
      ++v0;
    } while (*v1 != -1);
  }
  v2 = 0;
  while (v0 > 0 && !v2) {
    v2 = 1;
    if (v0 > 0) {
      v3 = &smithitem[0].IDidx;
      v4 = v0;
      do {
        v5 = (int)(v3 + 92);
        if (*v3 > v3[92]) {
          BubbleSwapItem((ItemStruct *)(v3 - 90), (ItemStruct *)(v3 + 2));
          v2 = 0;
        }
        --v4;
        v3 = (int *)v5;
      } while (v4);
    }
    --v0;
  }
}

//----- (00424351) --------------------------------------------------------
void __fastcall SpawnSmith(int lvl) {
  int v3;         // ebp
  ItemStruct *v4; // ebx
  int v9;         // [esp+Ch] [ebp-8h]

  v3 = random(50, 10) + 10;
  if (v3 > 0) {
    v4 = smithitem;
    v9 = v3;
    while (1) {
      do {
        item[0]._iSeed = GetRndSeed();
        SetRndSeed(item[0]._iSeed);
        GetItemAttrs(0, RndSmithItem(lvl) - 1, lvl);
      } while (item[0]._iIvalue > 140000);
      qmemcpy(v4, item, sizeof(ItemStruct));
      v4->_iCreateInfo = lvl | 0x400;
      v4->_iIdentified = 1;
      v4->_iStatFlag = StoreStatOk(v4);
      ++v4;
      if (!--v9)
        break;
    }
  }
  if (v3 < 20) {
    do {
      smithitem[v3]._itype = -1;
      v3++;
    } while (v3 < 20);
  }
  SortSmith();
}

//----- (00424420) --------------------------------------------------------
bool __fastcall PremiumItemOk(int i) {
  unsigned char v1; // cl
  bool rv;          // eax

  v1 = AllItemsList[i].itype;
  rv = 1;
  if (!v1 || v1 == ITYPE_GOLD || v1 == ITYPE_0E || v1 == ITYPE_STAFF)
    rv = 0;
  if (gbMaxPlayers != 1 && (v1 == ITYPE_RING || v1 == ITYPE_AMULET)) {
    rv = 0;
  }
  return rv;
}
// 679660: using guessed type char gbMaxPlayers;

//----- (0042445F) --------------------------------------------------------
int __fastcall RndPremiumItem(int minlvl, int maxlvl) {
  int ri;       // edx
  int i;        // edi
  int ril[512]; // [esp+8h] [ebp-804h]

  ri = 0;
  i = 1;
  if (AllItemsList[1].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd) {
        if (PremiumItemOk(i)) {
          if (AllItemsList[i].iMinMLvl >= minlvl &&
              AllItemsList[i].iMinMLvl <= maxlvl)
            ril[ri++] = i;
        }
      }
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(50, ri)] + 1;
}
// 42445F: using guessed type int ril[512];

//----- (004244C6) --------------------------------------------------------
void __fastcall SpawnOnePremium(int i, int plvl) {
  int itype;           // esi
  ItemStruct holditem; // [esp+Ch] [ebp-178h]

  qmemcpy(&holditem, item, sizeof(ItemStruct));
  if (plvl > 30)
    plvl = 30;
  if (plvl < 1)
    plvl = 1;
  do {
    item[0]._iSeed = GetRndSeed();
    SetRndSeed(item[0]._iSeed);
    itype = RndPremiumItem(plvl >> 2, plvl) - 1;
    GetItemAttrs(0, itype, plvl);
    GetItemBonus(0, itype, plvl >> 1, plvl, 1);
  } while (item[0]._iIvalue > 140000);
  qmemcpy(&premiumitem[i], item, sizeof(ItemStruct));
  premiumitem[i]._iCreateInfo = plvl | 0x800;
  premiumitem[i]._iIdentified = 1;
  premiumitem[i]._iStatFlag = StoreStatOk(&premiumitem[i]);
  qmemcpy(item, &holditem, sizeof(ItemStruct));
}

//----- (004245A0) --------------------------------------------------------
void __fastcall SpawnPremium(int lvl) {
  int i; // eax

  if (numpremium < 6) {
    for (i = 0; i < 6; i++) {
      if (premiumitem[i]._itype == -1)
        SpawnOnePremium(i, premiumlevel + premiumlvladd[i]);
    }
    numpremium = 6;
  }
  for (i = premiumlevel; premiumlevel < lvl; i = premiumlevel) {
    qmemcpy(premiumitem, &premiumitem[2], sizeof(ItemStruct));
    qmemcpy(&premiumitem[1], &premiumitem[3], sizeof(ItemStruct));
    qmemcpy(&premiumitem[2], &premiumitem[4], sizeof(ItemStruct));
    premiumlevel = i + 1;
    SpawnOnePremium(3, premiumlvladd[3] + i + 1);
    qmemcpy(&premiumitem[4], &premiumitem[5], sizeof(ItemStruct));
    SpawnOnePremium(5, premiumlvladd[5] + premiumlevel);
  }
}
// 69FB38: using guessed type int talker;

//----- (0042466C) --------------------------------------------------------
bool __fastcall WitchItemOk(int i) {
  bool rv;          // eax
  unsigned char v3; // dl
  int v4;           // edx
  int v5;           // ecx

  rv = 0;
  v3 = AllItemsList[i].itype;
  if (!v3)
    rv = 1;
  if (v3 == ITYPE_STAFF)
    rv = 1;
  v4 = AllItemsList[i].iMiscId;
  if (v4 == IMISC_MANA)
    rv = 0;
  if (v4 == IMISC_FULLMANA)
    rv = 0;
  if (v4 == IMISC_FULLHEAL)
    rv = 0;
  if (v4 == IMISC_HEAL)
    rv = 0;
  v5 = AllItemsList[i].iSpell;
  if (v5 == SPL_TOWN)
    rv = 0;
  if (v5 == SPL_RESURRECT && gbMaxPlayers == 1)
    rv = 0;
  if (v5 == SPL_HEALOTHER && gbMaxPlayers == 1)
    rv = 0;
  return rv;
}
// 679660: using guessed type char gbMaxPlayers;

//----- (004246D2) --------------------------------------------------------
int __fastcall RndWitchItem(int lvl) {
  int ri;       // ebx
  int i;        // edi
  int ril[512]; // [esp+8h] [ebp-804h]

  ri = 0;
  i = 1;
  if (AllItemsList[1].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd && WitchItemOk(i) &&
          lvl >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(51, ri)] + 1;
}
// 4246D2: using guessed type int var_804[512];

//----- (00424735) --------------------------------------------------------
void __cdecl SortWitch() {
  signed int v0; // esi
  int *v1;       // eax
  signed int v2; // ecx
  int *v3;       // eax
  int v4;        // ebx
  int v5;        // edi

  v0 = 3;
  if (witchitem[4]._itype != -1) {
    v1 = &witchitem[4]._itype;
    do {
      v1 += 92;
      ++v0;
    } while (*v1 != -1);
  }
  v2 = 0;
  while (v0 > 3 && !v2) {
    v2 = 1;
    if (v0 > 3) {
      v3 = &witchitem[3].IDidx;
      v4 = v0 - 3;
      do {
        v5 = (int)(v3 + 92);
        if (*v3 > v3[92]) {
          BubbleSwapItem((ItemStruct *)(v3 - 90), (ItemStruct *)(v3 + 2));
          v2 = 0;
        }
        --v4;
        v3 = (int *)v5;
      } while (v4);
    }
    --v0;
  }
}

//----- (00424795) --------------------------------------------------------
void __fastcall WitchBookLevel(int ii) {
  int slvl; // edi

  if (witchitem[ii]._iMiscId == IMISC_BOOK) {
    witchitem[ii]._iMinMag = spelldata[witchitem[ii]._iSpell].sMinInt;
    slvl = plr[myplr]._pSplLvl[witchitem[ii]._iSpell];
    if (slvl) {
      do {
        witchitem[ii]._iMinMag += 20 * witchitem[ii]._iMinMag / 100;
        --slvl;
        if (witchitem[ii]._iMinMag > 255) {
          witchitem[ii]._iMinMag = -1;
          slvl = 0;
        }
      } while (slvl);
    }
  }
}

//----- (00424815) --------------------------------------------------------
void __fastcall SpawnWitch(int lvl) {
  int v2;          // ebp
  int itype;       // esi
  int iblvl;       // eax
  signed int ii;   // [esp+10h] [ebp-8h]
  ItemStruct *itm; // [esp+14h] [ebp-4h]

  GetItemAttrs(0, IDI_MANA, 1);
  qmemcpy(witchitem, item, sizeof(ItemStruct));
  witchitem[0]._iCreateInfo = lvl;
  witchitem[0]._iStatFlag = 1;
  GetItemAttrs(0, IDI_FULLMANA, 1);
  qmemcpy(&witchitem[1], item, sizeof(ItemStruct));
  witchitem[1]._iCreateInfo = lvl;
  witchitem[1]._iStatFlag = 1;
  GetItemAttrs(0, IDI_PORTAL, 1);
  qmemcpy(&witchitem[2], item, sizeof(ItemStruct));
  witchitem[2]._iCreateInfo = lvl;
  witchitem[2]._iStatFlag = 1;
  v2 = random(51, 8) + 10;
  ii = 3;
  if (v2 > 3) {
    itm = &witchitem[3];
    while (1) {
      item[0]._iSeed = GetRndSeed();
      SetRndSeed(item[0]._iSeed);
      itype = RndWitchItem(lvl) - 1;
      GetItemAttrs(0, itype, lvl);
      if (random(51, 100) > 5 || (iblvl = 2 * lvl, iblvl == -1)) {
        if (item[0]._iMiscId != IMISC_STAFF)
          continue;
        iblvl = 2 * lvl;
        if (iblvl == -1)
          continue;
      }
      GetItemBonus(0, itype, iblvl >> 1, iblvl, 1);
      if (item[0]._iIvalue <= 140000) {
        qmemcpy(itm, item, sizeof(ItemStruct));
        itm->_iIdentified = 1;
        itm->_iCreateInfo = lvl | 0x2000;
        WitchBookLevel(ii);
        ++ii;
        itm->_iStatFlag = StoreStatOk(itm);
        ++itm;
        if (ii >= v2)
          break;
      }
    }
  }
  if (v2 < 20) {
    do {
      witchitem[v2]._itype = -1;
      v2++;
    } while (v2 < 20);
  }
  SortWitch();
}

//----- (004249A4) --------------------------------------------------------
int __fastcall RndBoyItem(int lvl) {
  int ri;       // edx
  int i;        // edi
  int ril[512]; // [esp+8h] [ebp-800h]

  ri = 0;
  i = 1;
  if (AllItemsList[1].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd && PremiumItemOk(i) &&
          lvl >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(49, ri)] + 1;
}
// 4249A4: using guessed type int var_800[512];

//----- (00424A03) --------------------------------------------------------
void __fastcall SpawnBoy(int lvl) {
  int itype; // esi

  if (boylevel<lvl>> 1 || boyitem._itype == -1) {
    do {
      item[0]._iSeed = GetRndSeed();
      SetRndSeed(item[0]._iSeed);
      itype = RndBoyItem(lvl) - 1;
      GetItemAttrs(0, itype, lvl);
      GetItemBonus(0, itype, lvl, 2 * lvl, 1);
    } while (item[0]._iIvalue > 90000);
    qmemcpy(&boyitem, item, sizeof(boyitem));
    boyitem._iCreateInfo = lvl | 0x10;
    boyitem._iIdentified = 1;
    boyitem._iStatFlag = StoreStatOk(&boyitem);
    boylevel = lvl >> 1;
  }
}
// 6A8A3C: using guessed type int boylevel;

//----- (00424A9B) --------------------------------------------------------
bool __fastcall HealerItemOk(int i) {
  int v1;      // ecx
  bool result; // eax
  int v3;      // esi

  v1 = i;
  result = 0;
  if (AllItemsList[v1].itype)
    return 0;
  v3 = AllItemsList[v1].iMiscId;
  if (v3 == IMISC_SCROLL && AllItemsList[v1].iSpell == SPL_HEAL)
    result = 1;
  if (v3 != IMISC_SCROLLT)
    goto LABEL_12;
  if (AllItemsList[v1].iSpell == SPL_RESURRECT && gbMaxPlayers != 1)
    result = 0;
  if (AllItemsList[v1].iSpell != SPL_HEALOTHER) {
  LABEL_12:
    if (gbMaxPlayers != 1)
      goto LABEL_21;
    goto LABEL_13;
  }
  if (gbMaxPlayers != 1) {
    result = 1;
    goto LABEL_12;
  }
LABEL_13:
  if (v3 == IMISC_ELIXSTR)
    result = 1;
  if (v3 == IMISC_ELIXMAG)
    result = 1;
  if (v3 == IMISC_ELIXDEX)
    result = 1;
  if (v3 == IMISC_ELIXVIT)
    result = 1;
LABEL_21:
  if (v3 == IMISC_FULLHEAL)
    result = 1;
  if (v3 == IMISC_REJUV)
    result = 1;
  if (v3 == IMISC_FULLREJUV)
    result = 1;
  if (v3 == IMISC_HEAL)
    result = 0;
  if (v3 == IMISC_FULLHEAL)
    result = 0;
  if (v3 == IMISC_MANA)
    result = 0;
  if (v3 == IMISC_FULLMANA)
    return 0;
  return result;
}
// 679660: using guessed type char gbMaxPlayers;

//----- (00424B49) --------------------------------------------------------
int __fastcall RndHealerItem(int lvl) {
  int ri;       // ebx
  int i;        // edi
  int ril[512]; // [esp+8h] [ebp-804h]

  ri = 0;
  i = 1;
  if (AllItemsList[1].iLoc != -1) {
    do {
      if (AllItemsList[i].iRnd && HealerItemOk(i) &&
          lvl >= AllItemsList[i].iMinMLvl)
        ril[ri++] = i;
      ++i;
    } while (AllItemsList[i].iLoc != -1);
  }
  return ril[random(50, ri)] + 1;
}
// 424B49: using guessed type int var_804[512];

//----- (00424BAC) --------------------------------------------------------
void __cdecl SortHealer() {
  signed int v0; // esi
  int *v1;       // eax
  signed int v2; // ecx
  int *v3;       // eax
  int v4;        // ebx
  int v5;        // edi

  v0 = 2;
  if (healitem[3]._itype != -1) {
    v1 = &healitem[3]._itype;
    do {
      v1 += 92;
      ++v0;
    } while (*v1 != -1);
  }
  v2 = 0;
  while (v0 > 2 && !v2) {
    v2 = 1;
    if (v0 > 2) {
      v3 = &healitem[2].IDidx;
      v4 = v0 - 2;
      do {
        v5 = (int)(v3 + 92);
        if (*v3 > v3[92]) {
          BubbleSwapItem((ItemStruct *)(v3 - 90), (ItemStruct *)(v3 + 2));
          v2 = 0;
        }
        --v4;
        v3 = (int *)v5;
      } while (v4);
    }
    --v0;
  }
}

//----- (00424C0C) --------------------------------------------------------
void __fastcall SpawnHealer(int lvl) {
  int v3;         // eax
  ItemStruct *v4; // ebp
  signed int v8;  // [esp-4h] [ebp-20h]
  int v10;        // [esp+14h] [ebp-8h]

  GetItemAttrs(0, IDI_HEAL, 1);
  qmemcpy(healitem, item, sizeof(ItemStruct));
  healitem[0]._iCreateInfo = lvl;
  healitem[0]._iStatFlag = 1;
  GetItemAttrs(0, IDI_FULLHEAL, 1);
  qmemcpy(&healitem[1], item, sizeof(ItemStruct));
  healitem[1]._iCreateInfo = lvl;
  healitem[1]._iStatFlag = 1;
  if (gbMaxPlayers == 1) {
    v8 = 2;
  } else {
    GetItemAttrs(0, IDI_RESURRECT, 1);
    qmemcpy(&healitem[2], item, sizeof(ItemStruct));
    healitem[2]._iCreateInfo = lvl;
    healitem[2]._iStatFlag = 1;
    v8 = 3;
  }
  v3 = random(50, 8) + 10;
  if (v8 < v3) {
    v4 = &healitem[v8];
    v10 = v3 - v8;
    do {
      item[0]._iSeed = GetRndSeed();
      SetRndSeed(item[0]._iSeed);
      GetItemAttrs(0, RndHealerItem(lvl) - 1, lvl);
      qmemcpy(v4, item, sizeof(ItemStruct));
      v4->_iCreateInfo = lvl | 0x4000;
      v4->_iIdentified = 1;
      v4->_iStatFlag = StoreStatOk(v4);
      ++v4;
      --v10;
    } while (v10);
  }
  if (v3 < 20) {
    do {
      healitem[v3]._itype = -1;
      v3++;
    } while (v3 < 20);
  }
  SortHealer();
}
// 679660: using guessed type char gbMaxPlayers;

//----- (00424D57) --------------------------------------------------------
void __cdecl SpawnStoreGold() {
  GetItemAttrs(0, IDI_GOLD, 1);
  qmemcpy(&golditem, item, sizeof(golditem));
  golditem._iStatFlag = 1;
}

//----- (00424D80) --------------------------------------------------------
void __fastcall RecreateSmithItem(int ii, int idx, int plvl, int iseed) {
  SetRndSeed(iseed);
  GetItemAttrs(ii, RndSmithItem(plvl) - 1, plvl);
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = plvl | 0x400;
  item[ii]._iIdentified = 1;
}

//----- (00424DD1) --------------------------------------------------------
void __fastcall RecreatePremiumItem(int ii, int idx, int lvl, int iseed) {
  int itype; // edi

  SetRndSeed(iseed);
  itype = RndPremiumItem(lvl >> 2, lvl) - 1;
  GetItemAttrs(ii, itype, lvl);
  GetItemBonus(ii, itype, lvl >> 1, lvl, 1);
  item[ii]._iCreateInfo = lvl | 0x800;
  item[ii]._iSeed = iseed;
  item[ii]._iIdentified = 1;
}

//----- (00424E3C) --------------------------------------------------------
void __fastcall RecreateBoyItem(int ii, int idx, int lvl, int iseed) {
  int itype; // edi

  SetRndSeed(iseed);
  itype = RndBoyItem(lvl) - 1;
  GetItemAttrs(ii, itype, lvl);
  GetItemBonus(ii, itype, lvl, 2 * lvl, 1);
  item[ii]._iCreateInfo = lvl | 0x1000;
  item[ii]._iSeed = iseed;
  item[ii]._iIdentified = 1;
}

//----- (00424EA1) --------------------------------------------------------
void __fastcall RecreateWitchItem(int ii, int idx, int lvl, int iseed) {
  int itype; // edi
  int iblvl; // eax

  if (idx == IDI_MANA || idx == IDI_FULLMANA || idx == IDI_PORTAL) {
    GetItemAttrs(ii, idx, lvl);
  } else {
    SetRndSeed(iseed);
    itype = RndWitchItem(lvl) - 1;
    GetItemAttrs(ii, itype, lvl);
    iblvl = 2 * lvl;
    if (iblvl != -1 &&
        (random(51, 100) <= 5 || item[ii]._iMiscId == IMISC_STAFF)) {
      GetItemBonus(ii, itype, iblvl >> 1, iblvl, 1);
    }
  }
  item[ii]._iCreateInfo = lvl | 0x2000;
  item[ii]._iSeed = iseed;
  item[ii]._iIdentified = 1;
}

//----- (00424F52) --------------------------------------------------------
void __fastcall RecreateHealerItem(int ii, int idx, int lvl, int iseed) {
  if (idx != IDI_HEAL && idx != IDI_FULLHEAL && idx != IDI_RESURRECT) {
    SetRndSeed(iseed);
    idx = RndHealerItem(lvl) - 1;
  }
  GetItemAttrs(ii, idx, lvl);
  item[ii]._iCreateInfo = lvl | 0x4000;
  item[ii]._iSeed = iseed;
  item[ii]._iIdentified = 1;
}

//----- (00424FB8) --------------------------------------------------------
void __fastcall RecreateTownItem(int ii, int idx, unsigned short icreateinfo,
                                 int iseed, int ivalue) {
  if (icreateinfo & 0x400)
    RecreateSmithItem(ii, idx, icreateinfo & 0x3F, iseed);
  else if (icreateinfo & 0x800)
    RecreatePremiumItem(ii, idx, icreateinfo & 0x3F, iseed);
  else if (icreateinfo & 0x1000)
    RecreateBoyItem(ii, idx, icreateinfo & 0x3F, iseed);
  else if (icreateinfo & 0x2000)
    RecreateWitchItem(ii, idx, icreateinfo & 0x3F, iseed);
  else if (icreateinfo & 0x4000)
    RecreateHealerItem(ii, idx, icreateinfo & 0x3F, iseed);
}

//----- (0042501F) --------------------------------------------------------
void __cdecl RecalcStoreStats() {
  int i;

  for (i = 0; i < 20; i++) {
    if (smithitem[i]._itype != -1)
      smithitem[i]._iStatFlag = StoreStatOk(&smithitem[i]);
    if (witchitem[i]._itype != -1)
      witchitem[i]._iStatFlag = StoreStatOk(&witchitem[i]);
    if (healitem[i]._itype != -1)
      healitem[i]._iStatFlag = StoreStatOk(&healitem[i]);
  }

  for (i = 0; i < 6; i++) {
    if (premiumitem[i]._itype != -1)
      premiumitem[i]._iStatFlag = StoreStatOk(&premiumitem[i]);
  }

  boyitem._iStatFlag = StoreStatOk(&boyitem);
}
// 6A6BB8: using guessed type int stextscrl;
// 6AA700: using guessed type int stextdown;

//----- (004250C0) --------------------------------------------------------
int __cdecl ItemNoFlippy() {
  int r; // ecx

  r = itemactive[numitems - 1];
  item[r]._iAnimFlag = 0;
  item[r]._iAnimFrame = item[r]._iAnimLen;
  item[r]._iSelFlag = 1;

  return r;
}

//----- (004250EF) --------------------------------------------------------
void __fastcall CreateSpellBook(int x, int y, int ispell, bool sendmsg,
                                int delta) {
  int ii;    // edi
  int idx;   // [esp+8h] [ebp-8h]
  bool done; // [esp+Ch] [ebp-4h]

  done = 0;
  idx = RndTypeItems(0, 24);
  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];
    do {
      SetupAllItems(ii, idx, GetRndSeed(), 2 * currlevel, 1, 1, 0, delta);
      if (item[ii]._iMiscId == IMISC_BOOK && item[ii]._iSpell == ispell)
        done = 1;
    } while (!done);
    if (sendmsg)
      NetSendCmdDItem(0, ii);
    if (delta)
      DeltaAddItem(ii);
    ++numitems;
  }
}

//----- (004251B8) --------------------------------------------------------
void __fastcall CreateMagicItem(int x, int y, int imisc, int icurs, int sendmsg,
                                int delta) {
  int ii;    // esi
  int idx;   // ebx
  bool done; // [esp+Ch] [ebp-4h]

  done = 0;
  idx = RndTypeItems(imisc, 0);
  if (numitems < 127) {
    ii = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemactive[numitems] = ii;
    itemavail[0] = itemavail[-numitems + 126];
    do {
      SetupAllItems(ii, idx, GetRndSeed(), 2 * currlevel, 1, 1, 0, delta);
      if (item[ii]._iCurs == icurs)
        done = 1;
    } while (!done);
    if (sendmsg)
      NetSendCmdDItem(0, ii);
    if (delta)
      DeltaAddItem(ii);
    ++numitems;
  }
}

//----- (0042526E) --------------------------------------------------------
bool __fastcall GetItemRecord(int dwSeed, int CI, int indx) {
  int v3;                   // edi
  int *v4;                  // ebx
  int v6;                   // [esp+Ch] [ebp-18h]
  DWORD v7;                 // [esp+10h] [ebp-14h]
  int *v8;                  // [esp+14h] [ebp-10h]
  unsigned short *v9;       // [esp+18h] [ebp-Ch]
  ItemGetRecordStruct *v10; // [esp+1Ch] [ebp-8h]
  short v11;                // [esp+20h] [ebp-4h]

  v11 = CI;
  v6 = dwSeed;
  v3 = 0;
  v7 = GetTickCount();
  if (gnNumGetRecords <= 0)
    return 1;
  v8 = &itemrecord[0].nIndex;
  v9 = &itemrecord[0].wCI;
  v10 = itemrecord;
  v4 = &itemrecord[0].dwTimestamp;
  while (v7 - *v4 > 6000) {
    NextItemRecord(v3);
    --v10;
    v9 -= 8;
    --v3;
    v4 -= 4;
    v8 -= 4;
  LABEL_8:
    ++v10;
    v9 += 8;
    v8 += 4;
    ++v3;
    v4 += 4;
    if (v3 >= gnNumGetRecords)
      return 1;
  }
  if (v6 != v10->nSeed || v11 != *v9 || indx != *v8)
    goto LABEL_8;
  return 0;
}

//----- (00425311) --------------------------------------------------------
void __fastcall NextItemRecord(int i) {
  int v1; // eax

  v1 = gnNumGetRecords-- - 1;
  if (gnNumGetRecords) {
    itemrecord[i].nIndex = itemrecord[v1].nIndex;
    itemrecord[i].nSeed = itemrecord[v1].nSeed;
    itemrecord[i].wCI = itemrecord[v1].wCI;
    itemrecord[i].dwTimestamp = itemrecord[v1].dwTimestamp;
  }
}

//----- (00425357) --------------------------------------------------------
void __fastcall SetItemRecord(int dwSeed, int CI, int indx) {
  int i; // ecx

  if (gnNumGetRecords != 127) {
    i = gnNumGetRecords++;
    itemrecord[i].dwTimestamp = GetTickCount();
    itemrecord[i].nSeed = dwSeed;
    itemrecord[i].wCI = CI;
    itemrecord[i].nIndex = indx;
  }
}

//----- (0042539E) --------------------------------------------------------
void __fastcall PutItemRecord(int seed, int ci, int index) {
  int v3;                  // edi
  int *v4;                 // ebx
  int v5;                  // [esp+Ch] [ebp-18h]
  DWORD v6;                // [esp+10h] [ebp-14h]
  int *v7;                 // [esp+14h] [ebp-10h]
  unsigned short *v8;      // [esp+18h] [ebp-Ch]
  ItemGetRecordStruct *v9; // [esp+1Ch] [ebp-8h]
  short v10;               // [esp+20h] [ebp-4h]

  v10 = ci;
  v5 = seed;
  v3 = 0;
  v6 = GetTickCount();
  if (gnNumGetRecords > 0) {
    v7 = &itemrecord[0].nIndex;
    v8 = &itemrecord[0].wCI;
    v9 = itemrecord;
    v4 = &itemrecord[0].dwTimestamp;
    do {
      if (v6 - *v4 <= 6000) {
        if (v5 == v9->nSeed && v10 == *v8 && index == *v7) {
          NextItemRecord(v3);
          return;
        }
      } else {
        NextItemRecord(v3);
        --v9;
        v8 -= 8;
        --v3;
        v4 -= 4;
        v7 -= 4;
      }
      ++v9;
      v8 += 8;
      v7 += 4;
      ++v3;
      v4 += 4;
    } while (v3 < gnNumGetRecords);
  }
}
