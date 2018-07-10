// HEADER_GOES_HERE

#include "../types.h"

int cursH;      // weak
int icursH28;   // idb
int cursW;      // idb
int pcursmonst; // idb
int icursW28;   // idb
void *pCursCels;
int icursH;        // weak
char pcursinvitem; // weak
int icursW;        // weak
char pcursitem;    // weak
char pcursobj;     // weak
char pcursplr;     // weak
int cursmx;
int cursmy;
int cursor_monster_2; // weak
int pcurs;            // idb
#define DUNGEON_WIDTH 112
#define DUNGEON_LAST_INDEX 111

/* data */
int InvItemWidth[180] = {
    0, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 23, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56};
int InvItemHeight[180] = {
    0, 29, 32, 32, 32, 32, 32, 32, 32, 32, 32, 35, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 56, 56, 56, 56, 56, 56, 84, 84, 84, 84,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 56, 56, 56,
    56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
    56, 56, 56, 56, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84};

//----- (0040740A) --------------------------------------------------------
void __cdecl InitCursor()
{
  pCursCels = LoadFileInMem("Data\\Inv\\Objcurs.CEL", 0);
  ClearCursor();
}

//----- (00407420) --------------------------------------------------------
void __cdecl FreeCursor()
{
  void *v0; // ecx

  v0 = pCursCels;
  pCursCels = 0;
  mem_free_dbg(v0);
  ClearCursor();
}

//----- (00407437) --------------------------------------------------------
void __fastcall SetICursor(int i)
{
  int v1; // ecx

  v1 = i;
  icursW = InvItemWidth[v1];
  icursH = InvItemHeight[v1];
  icursW28 = icursW / 28;
  icursH28 = icursH / 28;
}
// 4B8CB4: using guessed type int icursH;
// 4B8CBC: using guessed type int icursW;

//----- (0040746B) --------------------------------------------------------
void __fastcall SetCursor(int i)
{
  int v1; // eax

  v1 = InvItemWidth[i];
  pcurs = i;
  cursW = v1;
  cursH = InvItemHeight[i];
  SetICursor(i);
}
// 4B8C9C: using guessed type int cursH;

//----- (00407493) --------------------------------------------------------
void __cdecl InitLevelCursor()
{
  SetCursor(CURSOR_HAND);
  cursmx = ViewX;
  cursmy = ViewY;
  cursor_monster_2 = -1;
  pcursmonst = -1;
  pcursobj = -1;
  pcursitem = -1;
  pcursplr = -1;
  ClearCursor();
}
// 4B8CC0: using guessed type char pcursitem;
// 4B8CC1: using guessed type char pcursobj;
// 4B8CC2: using guessed type char pcursplr;
// 4B8CCC: using guessed type int cursor_monster_2;

//----- (004074D0) --------------------------------------------------------
void __cdecl CheckTown()
{
  int v0; // ecx
  int v1; // eax
  int v2; // esi
  int v3; // edx
  int v4; // ebx
  int v5; // [esp+0h] [ebp-4h]

  v5 = 0;
  if (nummissiles > 0)
  {
    v0 = cursmx;
    v1 = cursmy;
    do
    {
      v2 = missileactive[v5];
      if (missile[v2]._mitype == MIS_TOWN)
      {
        if ((v3 = missile[v2]._mix, modified_mouse_screen_position_y = v3 - 1, v0 == v3 - 1) &&
                v1 == missile[v2]._miy ||
            v0 == v3 && v1 == missile[v2]._miy - 1 ||
            v0 == modified_mouse_screen_position_y && v1 == missile[v2]._miy - 1 ||
            v0 == v3 - 2 && (v1 == missile[v2]._miy - 1 ||
                             v0 == v3 - 2 && v1 == missile[v2]._miy - 2) ||
            v0 == modified_mouse_screen_position_y && v1 == missile[v2]._miy - 2 ||
            v0 == v3 && v1 == missile[v2]._miy)
        {
          trigflag[3] = 1;
          ClearPanel();
          strcpy(infostr, "Town Portal");
          sprintf(tempstr, "from %s", plr[missile[v2]._misource]._pName);
          AddPanelString(tempstr, 1);
          v0 = missile[v2]._mix;
          v1 = missile[v2]._miy;
          cursmx = missile[v2]._mix;
          cursmy = v1;
        }
      }
      ++v5;
    } while (v5 < nummissiles);
  }
}

//----- (004075FD) --------------------------------------------------------
void __cdecl CheckRportal()
{
  int v0; // ecx
  int v1; // eax
  int v2; // esi
  int v3; // edx
  int v4; // ebx
  int v5; // [esp+0h] [ebp-4h]

  v5 = 0;
  if (nummissiles > 0)
  {
    v0 = cursmx;
    v1 = cursmy;
    do
    {
      v2 = missileactive[v5];
      if (missile[v2]._mitype == MIS_RPORTAL)
      {
        if ((v3 = missile[v2]._mix, v4 = v3 - 1, v0 == v3 - 1) &&
                v1 == missile[v2]._miy ||
            v0 == v3 && v1 == missile[v2]._miy - 1 ||
            v0 == v4 && v1 == missile[v2]._miy - 1 ||
            v0 == v3 - 2 && (v1 == missile[v2]._miy - 1 ||
                             v0 == v3 - 2 && v1 == missile[v2]._miy - 2) ||
            v0 == v4 && v1 == missile[v2]._miy - 2 ||
            v0 == v3 && v1 == missile[v2]._miy)
        {
          trigflag[3] = 1;
          ClearPanel();
          strcpy(infostr, "Portal to");
          if (setlevel)
            strcpy(tempstr, "level 15");
          else
            strcpy(tempstr, "The Unholy Altar");
          AddPanelString(tempstr, 1);
          v0 = missile[v2]._mix;
          v1 = missile[v2]._miy;
          cursmx = missile[v2]._mix;
          cursmy = v1;
        }
      }
      ++v5;
    } while (v5 < nummissiles);
  }
}
// 5CF31D: using guessed type char setlevel;

//----- (00407729) --------------------------------------------------------
void __cdecl CheckCursMove()
{

  BOOL off_by_one;                      // eax
  bool player_not_invinsible;           // zf
  char *block_table_row_ptr;            // [esp+Ch] [ebp-18h]
  char item_id;                         // al
  char item_id_2;                       // al
  char item_id_3;                       // al
  char item_selected_flag;              // cl
  char object_id;                       // cl
  char object_id_2;                     // cl
  char object_id_3;                     // cl
  char object_sel_flag;                 // al
  char player_id;                       // cl
  char player_id_2;                     // cl
  char player_id_3;                     // cl
  char selected_item;                   // al
  char selected_item_2;                 // al
  char selected_item_3;                 // al
  char selected_item_4;                 // al
  char selected_object;                 // al
  char selected_object_2;               // al
  char selected_object_3;               // al
  char selected_object_4;               // al
  char selected_player;                 // al
  char selected_player_2;               // al
  char selected_player_3;               // al
  char selected_player_4;               // al
  int *local_player_position_y_ptr_2;   // ecx
  int *local_player_world_y_ptr;        // eax
  int cursor_monster;                   // ecx
  int cursor_offset_y_1;                // eax
  int cursor_player;                    // ecx
  int modified_mouse_screen_position_y; // edx
  int monster_id;                       // edx
  int mouse_screen_position_x;          // esi
  int mouse_screen_position_y;          // edi
  int mouse_x;                          // esi
  int original_tile_array_index;        // [esp+10h] [ebp-14h]
  int player_id_iterator;               // [esp+1Ch] [ebp-8h]
  int selected_monster;                 // eax
  int selected_monster_10;              // eax
  int selected_monster_11;              // eax
  int selected_monster_12;              // eax
  int selected_monster_13;              // eax
  int selected_monster_2;               // eax
  int selected_monster_3;               // eax
  int selected_monster_4;               // eax
  int selected_monster_5;               // eax
  int selected_monster_6;               // eax
  int selected_monster_7;               // eax
  int selected_monster_8;               // eax
  int selected_monster_9;               // eax
  int selected_monster_id;              // eax
  int selected_monster_id_10;           // ecx
  int selected_monster_id_11;           // ecx
  int selected_monster_id_11;           // ecx
  int selected_monster_id_12;           // ecx
  int selected_monster_id_13;           // ecx
  int selected_monster_id_2;            // eax
  int selected_monster_id_3;            // eax
  int selected_monster_id_4;            // eax
  int selected_monster_id_5;            // ecx
  int selected_monster_id_6;            // ecx
  int selected_monster_id_7;            // ecx
  int selected_monster_id_8;            // ecx
  int selected_monster_id_9;            // ecx
  int selected_tile;                    // ecx
  int selected_tile_2;                  // ecx
  int selected_tile_3;                  // [esp+1Ch] [ebp-8h]
  int selected_tile_4;                  // ebx
  int selected_tile_5;                  // ebx
  int selected_tile_6;                  // edx
  int tile_array_index;                 // ebx
  int tile_pixel_x;                     // [esp+Ch] [ebp-18h]
  int tile_pixel_y;                     // ebx
  int tile_x_center;                    // eax
  int world_x;                          // edi
  int world_y;                          // esi
  int world_y_iterator;                 // edx
  mouse_x = MouseX;
  signed int add_to_index;             // [esp+20h] [ebp-4h]
  signed int block_table_row_iterator; // [esp+18h] [ebp-Ch]
  signed int cursor_monster_3;         // eax
  signed int cursor_monster_saved;     // edx
  signed int mouse_y;                  // edi
  signed int res_offset_iterator;      // [esp+14h] [ebp-10h]
  mouse_y = MouseY;
  if (chrflag || questlog)
  {
    if (MouseX >= 160)
    {
      mouse_x = MouseX - 160;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if (invflag || sbookflag)
  {
    if (MouseX <= 320)
    {
      mouse_x = MouseX + 160;
      goto LABEL_10;
    }
  LABEL_9:
    mouse_x = 0;
  }
LABEL_10:
  if (MouseY > 351 && track_isscrolling())
    mouse_y = 351;
  if (!zoomflag)
  {
    mouse_x >>= 1; // if no zoom, divide by two
    mouse_y >>= 1;
  }
  mouse_screen_position_x = mouse_x - ScrollInfo._sxoff;
  mouse_screen_position_y = mouse_y - ScrollInfo._syoff;
  if (ScrollInfo._sdir)
  {
    mouse_screen_position_x += ((plr[myplr]._pVar6 + plr[myplr]._pxvel) >> 8) -
                               (plr[myplr]._pVar6 >> 8);
    mouse_screen_position_y += ((plr[myplr]._pVar7 + plr[myplr]._pyvel) >> 8) -
                               (plr[myplr]._pVar7 >> 8);
  }
  if (mouse_screen_position_x < 0)
    mouse_screen_position_x = 0;
  if (mouse_screen_position_x >= 640)
    mouse_screen_position_x = 640;
  if (mouse_screen_position_y < 0)
    mouse_screen_position_y = 0;
  if (mouse_screen_position_y >= 480)
    mouse_screen_position_y = 480;
  modified_mouse_screen_position_y = mouse_screen_position_y >> 5; // divide by 32
  tile_pixel_y = mouse_screen_position_y & 31;                     // rotate to between 0 and 31
  tile_pixel_x = mouse_screen_position_x & 63;                     // rotate to between 0 and 63
  world_x = (mouse_screen_position_x >> 6) + (mouse_screen_position_y >> 5) + ViewX - (zoomflag != 0 ? 10 : 5);
  tile_x_center = tile_pixel_x >> 1;
  world_y = modified_mouse_screen_position_y + ViewY - (mouse_screen_position_x >> 6);
  if (tile_pixel_y < tile_pixel_x / 2)
    --world_y;
  off_by_one = tile_pixel_y >= 32 - tile_x_center;
  if (off_by_one)
    ++world_x;
  if (world_x < 0)
    world_x = 0;
  if (world_x >= DUNGEON_WIDTH)
    world_x = DUNGEON_LAST_INDEX;
  if (world_y < 0)
    world_y = 0;
  if (world_y >= DUNGEON_WIDTH)
    world_y = DUNGEON_LAST_INDEX;
  if (tile_pixel_y >= tile_pixel_x >> 1)
  {
    if (!off_by_one)
      goto LABEL_49;
    goto LABEL_48;
  }
  if (!off_by_one)
  {
  LABEL_48:
    if (tile_pixel_x < 32)
      goto LABEL_39;
  LABEL_49:
    add_to_index = 0;
    goto LABEL_40;
  }
LABEL_39:
  add_to_index = 1;
LABEL_40:
  cursor_monster = pcursmonst;
  pcursobj = -1;
  pcursitem = -1;
  monster_id = -1;
  cursor_monster_2 = pcursmonst;
  pcursmonst = -1;
  if (pcursinvitem != -1)
    drawsbarflag = 1;
  pcursinvitem = -1;
  pcursplr = -1;
  player_not_invinsible = plr[myplr]._pInvincible == 0;
  uitemflag = 0;
  panelflag = 0;
  trigflag[3] = 0;
  if (!player_not_invinsible)
    return;
  if (pcurs >= CURSOR_FIRSTITEM || spselflag)
  {
    cursmx = world_x;
    cursmy = world_y;
    return;
  }
  if (MouseY > 352)
  {
    CheckPanelInfo();
    return;
  }
  if (doomflag)
    return;
  if (invflag && MouseX > 320)
  {
    pcursinvitem = CheckInvHLight();
    return;
  }
  if (sbookflag && MouseX > 320 || (chrflag || questlog) && MouseX < 320)
    return;
  if (!leveltype)
  {
    if (add_to_index)
    {
      tile_array_index = DUNGEON_WIDTH * world_x;
      original_tile_array_index = DUNGEON_WIDTH * world_x;
      selected_tile = DUNGEON_WIDTH * world_x + world_y;
      selected_monster_id = dMonster[0][selected_tile + 1];
      if (selected_monster_id <= 0)
        goto LABEL_200;
      monster_id = selected_monster_id - 1;
      cursmx = world_x;
      cursmy = world_y + 1;
    }
    else
    {
      tile_array_index = DUNGEON_WIDTH * world_x;
      original_tile_array_index = DUNGEON_WIDTH * world_x;
      selected_tile = DUNGEON_WIDTH * world_x + world_y;
      selected_monster_id_2 = dMonster[1][selected_tile];
      if (selected_monster_id_2 <= 0)
        goto LABEL_200;
      monster_id = selected_monster_id_2 - 1;
      cursmx = world_x + 1;
      cursmy = world_y;
    }
    pcursmonst = monster_id;
  LABEL_200:
    selected_monster_id_3 = dMonster[0][selected_tile];
    if (selected_monster_id_3 > 0)
    {
      monster_id = selected_monster_id_3 - 1;
      cursmx = world_x;
      pcursmonst = selected_monster_id_3 - 1;
      cursmy = world_y;
    }
    selected_monster_id_4 = dMonster[1][selected_tile + 1];
    if (selected_monster_id_4 > 0)
    {
      monster_id = selected_monster_id_4 - 1;
      cursmx = world_x + 1;
      pcursmonst = selected_monster_id_4 - 1;
      cursmy = world_y + 1;
    }
    if (!towner[monster_id]._tSelFlag)
    LABEL_205:
      pcursmonst = -1;
  LABEL_206:
    if (pcursmonst != -1)
    {
    LABEL_305:
      cursor_monster_saved = pcursmonst;
      goto LABEL_306;
    }
  LABEL_207:
    if (add_to_index)
    {
      selected_player = dPlayer[0][tile_array_index + 1 + world_y];
      if (selected_player)
      {
        player_id = selected_player <= 0 ? -1 - selected_player : selected_player - 1;
        if (player_id != myplr && plr[player_id]._pHitPoints)
        {
          cursmx = world_x;
          cursmy = world_y + 1;
          goto LABEL_222;
        }
      }
    }
    else
    {
      selected_player_2 = dPlayer[1][tile_array_index + world_y];
      if (selected_player_2)
      {
        player_id = selected_player_2 <= 0 ? -1 - selected_player_2 : selected_player_2 - 1;
        if (player_id != myplr && plr[player_id]._pHitPoints)
        {
          cursmy = world_y;
          cursmx = world_x + 1;
        LABEL_222:
          pcursplr = player_id;
          goto LABEL_223;
        }
      }
    }
  LABEL_223:
    selected_player_3 = dPlayer[0][tile_array_index + world_y];
    if (selected_player_3)
    {
      player_id_2 = selected_player_3 <= 0 ? -1 - selected_player_3 : selected_player_3 - 1;
      if (player_id_2 != myplr)
      {
        cursmx = world_x;
        cursmy = world_y;
        pcursplr = player_id_2;
      }
    }
    if (dFlags[0][tile_array_index + world_y] & 4)
    {
      cursor_player = 0;
      local_player_world_y_ptr = &plr[0].WorldY;
      do
      {
        if (*(local_player_world_y_ptr - 1) == world_x && *local_player_world_y_ptr == world_y && cursor_player != myplr)
        {
          cursmx = world_x;
          cursmy = world_y;
          pcursplr = cursor_player;
        }
        local_player_world_y_ptr += 5430;
        ++cursor_player;
      } while ((signed int)local_player_world_y_ptr < (signed int)&plr[4].WorldY);
    }
    if (pcurs == CURSOR_RESURRECT)
    {
      res_offset_iterator = -1;
      block_table_row_ptr = &nBlockTable[tile_array_index + 1944 + world_y];
      do
      {
        block_table_row_iterator = -1;
        world_y_iterator = world_y - 1;
        do
        {
          if (block_table_row_ptr[block_table_row_iterator] & 4)
          {
            player_id_iterator = 0;
            local_player_position_y_ptr_2 = &plr[0].WorldY;
            do
            {
              if (*(local_player_position_y_ptr_2 - 1) == world_x + res_offset_iterator && *local_player_position_y_ptr_2 == world_y_iterator && player_id_iterator != myplr)
              {
                cursmx = world_x + res_offset_iterator;
                cursmy = world_y_iterator;
                pcursplr = player_id_iterator;
              }
              ++player_id_iterator;
              local_player_position_y_ptr_2 += 5430;
            } while ((signed int)local_player_position_y_ptr_2 < (signed int)&plr[4].WorldY);
          }
          ++block_table_row_iterator;
          ++world_y_iterator;
        } while (block_table_row_iterator < 2);
        ++res_offset_iterator;
        block_table_row_ptr += DUNGEON_WIDTH;
      } while (res_offset_iterator < 2);
      tile_array_index = original_tile_array_index;
    }
    selected_player_4 = dPlayer[1][tile_array_index + 1 + world_y];
    if (selected_player_4)
    {
      player_id_3 = selected_player_4 <= 0 ? -1 - selected_player_4 : selected_player_4 - 1;
      if (player_id_3 != myplr && plr[player_id_3]._pHitPoints)
      {
        pcursplr = player_id_3;
        cursmx = world_x + 1;
        cursmy = world_y + 1;
      }
    }
    cursor_monster_saved = pcursmonst;
    if (pcursmonst != -1)
    {
    LABEL_285:
      if (pcursplr == -1)
        goto LABEL_286;
    LABEL_306:
      if (pcurs == CURSOR_IDENTIFY)
      {
        pcursobj = -1;
        cursor_monster_saved = -1;
        pcursitem = -1;
        pcursmonst = -1;
        cursmx = world_x;
        cursmy = world_y;
      }
      if (cursor_monster_saved != -1)
      {
        if (monster[cursor_monster_saved]._mFlags & 0x20)
          pcursmonst = -1;
      }
      return;
    }
    if (pcursplr != pcursmonst) /* check in future */
      goto LABEL_306;
    if (add_to_index)
    {
      selected_object = dObject[0][tile_array_index + 1 + world_y];
      if (!selected_object)
        goto LABEL_272;
      object_id = selected_object <= 0 ? -1 - selected_object : selected_object - 1;
      if (SLOBYTE(object[object_id]._oSelFlag) < 2)
        goto LABEL_272;
      cursmx = world_x;
      cursmy = world_y + 1;
    }
    else
    {
      selected_object_2 = dObject[1][tile_array_index + world_y];
      if (!selected_object_2)
        goto LABEL_272;
      object_id = selected_object_2 <= 0 ? -1 - selected_object_2 : selected_object_2 - 1;
      if (SLOBYTE(object[object_id]._oSelFlag) < 2)
        goto LABEL_272;
      cursmy = world_y;
      cursmx = world_x + 1;
    }
    pcursobj = object_id;
  LABEL_272:
    selected_object_3 = dObject[0][tile_array_index + world_y];
    if (selected_object_3)
    {
      object_id_2 = selected_object_3 <= 0 ? -1 - selected_object_3 : selected_object_3 - 1;
      object_sel_flag = object[object_id_2]._oSelFlag;
      if (object_sel_flag == 1 || object_sel_flag == 3)
      {
        cursmx = world_x;
        cursmy = world_y;
        pcursobj = object_id_2;
      }
    }
    selected_object_4 = dObject[1][tile_array_index + 1 + world_y];
    if (!selected_object_4 || (selected_object_4 <= 0 ? (object_id_3 = -1 - selected_object_4) : (object_id_3 = selected_object_4 - 1),
                               SLOBYTE(object[object_id_3]._oSelFlag) < 2))
    {
    LABEL_286:
      if (pcursobj != -1 || pcursmonst != -1)
        goto LABEL_306;
      if (add_to_index)
      {
        selected_item = dItem[0][tile_array_index + 1 + world_y];
        if (selected_item <= 0)
          goto LABEL_296;
        item_id = selected_item - 1;
        if (item[item_id]._iSelFlag < 2)
          goto LABEL_296;
        cursmx = world_x;
        cursmy = world_y + 1;
      }
      else
      {
        selected_item_2 = dItem[1][tile_array_index + world_y];
        if (selected_item_2 <= 0)
          goto LABEL_296;
        item_id = selected_item_2 - 1;
        if (item[item_id]._iSelFlag < 2)
          goto LABEL_296;
        cursmy = world_y;
        cursmx = world_x + 1;
      }
      pcursitem = item_id;
    LABEL_296:
      selected_item_3 = dItem[0][tile_array_index + world_y];
      if (selected_item_3 > 0)
      {
        item_id_2 = selected_item_3 - 1;
        item_selected_flag = item[item_id_2]._iSelFlag;
        if (item_selected_flag == 1 || item_selected_flag == 3)
        {
          cursmx = world_x;
          cursmy = world_y;
          pcursitem = item_id_2;
        }
      }
      selected_item_4 = dItem[1][tile_array_index + 1 + world_y];
      if (selected_item_4 > 0)
      {
        item_id_3 = selected_item_4 - 1;
        if (item[item_id_3]._iSelFlag >= 2)
        {
          pcursitem = item_id_3;
          cursmx = world_x + 1;
          cursmy = world_y + 1;
        }
      }
      if (pcursitem != -1)
        goto LABEL_306;
      cursmx = world_x;
      cursmy = world_y;
      CheckTrigForce();
      CheckTown();
      CheckRportal();
      goto LABEL_305;
    }
    pcursobj = object_id_3;
    cursmx = world_x + 1;
    cursmy = world_y + 1;
    goto LABEL_285;
  }
  if (cursor_monster == -1)
    goto LABEL_128;
  selected_tile_2 = DUNGEON_WIDTH * world_x + world_y;
  selected_tile_3 = DUNGEON_WIDTH * world_x + world_y;
  selected_tile_4 = DUNGEON_WIDTH * world_x + world_y;
  if (add_to_index)
  {
    selected_tile_5 = selected_tile_4;
    selected_monster = dMonster[1][selected_tile_5 + 2];
    if (!selected_monster)
      goto LABEL_74;
    player_not_invinsible = (dFlags[1][selected_tile_2 + 2] & 0x40) == 0;
  }
  else
  {
    selected_tile_5 = selected_tile_4;
    selected_monster = dMonster[2][selected_tile_5 + 1];
    if (!selected_monster)
      goto LABEL_74;
    player_not_invinsible = (dFlags[2][selected_tile_2 + 1] & 0x40) == 0;
  }
  if (!player_not_invinsible)
  {
    selected_monster_id_5 = selected_monster <= 0 ? -1 - selected_monster : selected_monster - 1;
    if (selected_monster_id_5 == cursor_monster_2 &&
        (signed int)(monster[selected_monster_id_5]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[selected_monster_id_5].MData->mSelFlag & 4)
    {
      monster_id = selected_monster_id_5;
      cursmx = world_x + 1;
      cursmy = world_y + 2;
      pcursmonst = selected_monster_id_5;
    }
  }
LABEL_74:
  selected_monster_2 = dMonster[2][selected_tile_5 + 2];
  if (selected_monster_2 && dFlags[2][selected_tile_3 + 2] & 0x40)
  {
    selected_monster_id_6 = selected_monster_2 <= 0 ? -1 - selected_monster_2 : selected_monster_2 - 1;
    if (selected_monster_id_6 == cursor_monster_2 &&
        (signed int)(monster[selected_monster_id_6]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[selected_monster_id_6].MData->mSelFlag & 4)
    {
      monster_id = selected_monster_id_6;
      cursmx = world_x + 2;
      cursmy = world_y + 2;
      pcursmonst = selected_monster_id_6;
    }
  }
  if (add_to_index)
  {
    selected_monster_3 = dMonster[0][selected_tile_5 + 1];
    if (selected_monster_3 && dFlags[0][selected_tile_3 + 1] & 0x40)
    {
      selected_monster_id_7 = selected_monster_3 <= 0 ? -1 - selected_monster_3 : selected_monster_3 - 1;
      if (selected_monster_id_7 == cursor_monster_2 &&
          (signed int)(monster[selected_monster_id_7]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[selected_monster_id_7].MData->mSelFlag & 2)
      {
        cursmx = world_x;
        cursmy = world_y + 1;
        goto LABEL_102;
      }
    }
  }
  else
  {
    selected_monster_4 = dMonster[1][selected_tile_5];
    if (selected_monster_4 && dFlags[1][selected_tile_3] & 0x40)
    {
      selected_monster_id_7 = selected_monster_4 <= 0 ? -1 - selected_monster_4 : selected_monster_4 - 1;
      if (selected_monster_id_7 == cursor_monster_2 &&
          (signed int)(monster[selected_monster_id_7]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[selected_monster_id_7].MData->mSelFlag & 2)
      {
        cursmy = world_y;
        cursmx = world_x + 1;
      LABEL_102:
        monster_id = selected_monster_id_7;
        pcursmonst = selected_monster_id_7;
        goto LABEL_103;
      }
    }
  }
LABEL_103:
  selected_monster_5 = dMonster[0][selected_tile_5];
  if (selected_monster_5 && dFlags[0][selected_tile_3] & 0x40)
  {
    selected_monster_id_8 = selected_monster_5 <= 0 ? -1 - selected_monster_5 : selected_monster_5 - 1;
    if (selected_monster_id_8 == cursor_monster_2 &&
        (signed int)(monster[selected_monster_id_8]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[selected_monster_id_8].MData->mSelFlag & 1)
    {
      monster_id = selected_monster_id_8;
      cursmx = world_x;
      cursmy = world_y;
      pcursmonst = selected_monster_id_8;
    }
  }
  selected_monster_6 = dMonster[1][selected_tile_5 + 1];
  if (selected_monster_6 && dFlags[1][selected_tile_3 + 1] & 0x40)
  {
    selected_monster_id_9 = selected_monster_6 <= 0 ? -1 - selected_monster_6 : selected_monster_6 - 1;
    if (selected_monster_id_9 == cursor_monster_2 &&
        (signed int)(monster[selected_monster_id_9]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[selected_monster_id_9].MData->mSelFlag & 2)
    {
      monster_id = selected_monster_id_9;
      cursmx = world_x + 1;
      cursmy = world_y + 1;
      pcursmonst = selected_monster_id_9;
    }
  }
  if (monster_id == -1)
    goto LABEL_128;
  if (monster[monster_id]._mFlags & 1)
  {
    monster_id = -1;
    cursmx = world_x;
    pcursmonst = -1;
    cursmy = world_y;
  }
  if (monster_id == -1)
    goto LABEL_128;
  if (monster[monster_id]._mFlags & 0x20)
  {
    monster_id = -1;
    pcursmonst = -1;
  }
  if (monster_id == -1)
  {
  LABEL_128:
    tile_array_index = DUNGEON_WIDTH * world_x;
    original_tile_array_index = DUNGEON_WIDTH * world_x;
    if (add_to_index)
    {
      selected_tile_6 = tile_array_index + world_y;
      selected_monster_7 = dMonster[1][selected_tile_6 + 2];
      if (selected_monster_7 && dFlags[1][tile_array_index + 2 + world_y] & 0x40)
      {
        selected_monster_id_10 = selected_monster_7 <= 0 ? -1 - selected_monster_7 : selected_monster_7 - 1;
        if ((signed int)(monster[selected_monster_id_10]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[selected_monster_id_10].MData->mSelFlag & 4)
        {
          cursmx = world_x + 1;
          cursor_offset_y_1 = world_y + 2;
          goto LABEL_145;
        }
      }
    }
    else
    {
      selected_tile_6 = tile_array_index + world_y;
      selected_monster_8 = dMonster[2][selected_tile_6 + 1];
      if (selected_monster_8 && dFlags[2][tile_array_index + 1 + world_y] & 0x40)
      {
        selected_monster_id_10 = selected_monster_8 <= 0 ? -1 - selected_monster_8 : selected_monster_8 - 1;
        if ((signed int)(monster[selected_monster_id_10]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[selected_monster_id_10].MData->mSelFlag & 4)
        {
          cursmx = world_x + 2;
          cursor_offset_y_1 = world_y + 1;
        LABEL_145:
          cursmy = cursor_offset_y_1;
          pcursmonst = selected_monster_id_10;
          goto LABEL_146;
        }
      }
    }
  LABEL_146:
    selected_monster_9 = dMonster[2][selected_tile_6 + 2];
    if (selected_monster_9 && dFlags[2][tile_array_index + 2 + world_y] & 0x40)
    {
      selected_monster_id_11 = selected_monster_9 <= 0 ? -1 - selected_monster_9 : selected_monster_9 - 1;
      if ((signed int)(monster[selected_monster_id_11]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[selected_monster_id_11].MData->mSelFlag & 4)
      {
        pcursmonst = selected_monster_id_11;
        cursmx = world_x + 2;
        cursmy = world_y + 2;
      }
    }
    if (add_to_index)
    {
      selected_monster_10 = dMonster[0][selected_tile_6 + 1];
      if (selected_monster_10 && dFlags[0][tile_array_index + 1 + world_y] & 0x40)
      {
        selected_monster_id_11 = selected_monster_10 <= 0 ? -1 - selected_monster_10 : selected_monster_10 - 1;
        if ((signed int)(monster[selected_monster_id_11]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[selected_monster_id_11].MData->mSelFlag & 2)
        {
          cursmx = world_x;
          cursmy = world_y + 1;
          goto LABEL_171;
        }
      }
    }
    else
    {
      selected_monster_11 = dMonster[1][selected_tile_6];
      if (selected_monster_11 && dFlags[1][tile_array_index + world_y] & 0x40)
      {
        selected_monster_id_11 = selected_monster_11 <= 0 ? -1 - selected_monster_11 : selected_monster_11 - 1;
        if ((signed int)(monster[selected_monster_id_11]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[selected_monster_id_11].MData->mSelFlag & 2)
        {
          cursmy = world_y;
          cursmx = world_x + 1;
        LABEL_171:
          pcursmonst = selected_monster_id_11;
          goto LABEL_172;
        }
      }
    }
  LABEL_172:
    selected_monster_12 = dMonster[0][selected_tile_6];
    if (selected_monster_12 && dFlags[0][tile_array_index + world_y] & 0x40)
    {
      selected_monster_id_12 = selected_monster_12 <= 0 ? -1 - selected_monster_12 : selected_monster_12 - 1;
      if ((signed int)(monster[selected_monster_id_12]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[selected_monster_id_12].MData->mSelFlag & 1)
      {
        cursmx = world_x;
        cursmy = world_y;
        pcursmonst = selected_monster_id_12;
      }
    }
    selected_monster_13 = dMonster[1][selected_tile_6 + 1];
    if (selected_monster_13 && dFlags[1][tile_array_index + 1 + world_y] & 0x40)
    {
      selected_monster_id_13 = selected_monster_13 <= 0 ? -1 - selected_monster_13 : selected_monster_13 - 1;
      if ((signed int)(monster[selected_monster_id_13]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[selected_monster_id_13].MData->mSelFlag & 2)
      {
        pcursmonst = selected_monster_id_13;
        cursmx = world_x + 1;
        cursmy = world_y + 1;
      }
    }
    cursor_monster_3 = pcursmonst;
    if (pcursmonst == -1)
      goto LABEL_207;
    if (monster[pcursmonst]._mFlags & 1)
    {
      cursor_monster_3 = -1;
      cursmx = world_x;
      pcursmonst = -1;
      cursmy = world_y;
    }
    if (cursor_monster_3 == -1)
      goto LABEL_207;
    if (monster[cursor_monster_3]._mFlags & 0x20)
      goto LABEL_205;
    goto LABEL_206;
  }
}
// 4B8968: using guessed type int sbookflag;
// 4B8B84: using guessed type int panelflag;
// 4B8C98: using guessed type int spselflag;
// 4B8CB8: using guessed type char pcursinvitem;
// 4B8CC0: using guessed type char pcursitem;
// 4B8CC1: using guessed type char pcursobj;
// 4B8CC2: using guessed type char pcursplr;
// 4B8CCC: using guessed type int cursor_monster_2;
// 52569C: using guessed type int zoomflag;
// 52575C: using guessed type int doomflag;
// 5BB1ED: using guessed type char leveltype;
// 69BD04: using guessed type int questlog;
