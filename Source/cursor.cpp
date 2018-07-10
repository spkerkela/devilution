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
int dword_4B8CCC; // weak
int pcurs;        // idb
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
  dword_4B8CCC = -1;
  pcursmonst = -1;
  pcursobj = -1;
  pcursitem = -1;
  pcursplr = -1;
  ClearCursor();
}
// 4B8CC0: using guessed type char pcursitem;
// 4B8CC1: using guessed type char pcursobj;
// 4B8CC2: using guessed type char pcursplr;
// 4B8CCC: using guessed type int dword_4B8CCC;

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
  int mouse_x;                          // esi
  signed int mouse_y;                   // edi
  int mouse_screen_position_x;          // esi
  int mouse_screen_position_y;          // edi
  int modified_mouse_screen_position_y; // edx
  int tile_pixel_y;                     // ebx
  int world_x;                          // edi
  int tile_x_center;                    // eax
  int world_y;                          // esi
  BOOL off_by_one;                      // eax
  int cursor_monster;                   // ecx
  int monster_id;                       // edx
  int v12;                              // ecx
  int v13;                              // ebx
  int v14;                              // ebx
  int v15;                              // eax
  bool player_not_invinsible;           // zf
  int v17;                              // ecx
  int v18;                              // eax
  int v19;                              // ecx
  int v20;                              // eax
  int v21;                              // ecx
  int v22;                              // eax
  int v23;                              // eax
  int v24;                              // ecx
  int v25;                              // eax
  int v26;                              // ecx
  int tile_array_index;                 // ebx
  int v28;                              // edx
  int v29;                              // eax
  int v30;                              // ecx
  int v31;                              // eax
  int v32;                              // eax
  int v33;                              // eax
  int v34;                              // ecx
  int v35;                              // eax
  int v36;                              // ecx
  int v37;                              // eax
  int v38;                              // eax
  int v39;                              // ecx
  int v40;                              // eax
  int v41;                              // ecx
  signed int v42;                       // eax
  int selected_tile;                    // ecx
  int selected_monster_id_2;            // eax
  int selected_monster_id;              // eax
  int selected_monster_id_3;            // eax
  int selected_monster_id_4;            // eax
  char selected_player_2;               // al
  char player_id;                       // cl
  char selected_player;                 // al
  char selected_player_3;               // al
  char player_id_2;                     // cl
  int cursor_player;                    // ecx
  int *local_player_world_y_ptr;        // eax
  int world_y_iterator;                 // edx
  int *local_player_position_y_ptr_2;   // ecx
  char selected_player_4;               // al
  char player_id_3;                     // cl
  signed int cursor_monster_saved;      // edx
  char selected_object_2;               // al
  char object_id;                       // cl
  char selected_object;                 // al
  char selected_object_3;               // al
  char object_id_2;                     // cl
  char object_sel_flag;                 // al
  char selected_object_4;               // al
  char object_id_3;                     // cl
  char selected_item_2;                 // al
  char item_id;                         // al
  char selected_item;                   // al
  char selected_item_3;                 // al
  char item_id_2;                       // al
  char item_selected_flag;              // cl
  char selected_item_4;                 // al
  char item_id_3;                       // al
  int tile_pixel_x;                     // [esp+Ch] [ebp-18h]
  char *block_table_row_ptr;            // [esp+Ch] [ebp-18h]
  int original_tile_array_index;        // [esp+10h] [ebp-14h]
  signed int res_offset_iterator;       // [esp+14h] [ebp-10h]
  signed int block_table_row_iterator;  // [esp+18h] [ebp-Ch]
  int v81;                              // [esp+1Ch] [ebp-8h]
  int player_id_iterator;               // [esp+1Ch] [ebp-8h]
  signed int add_to_index;              // [esp+20h] [ebp-4h]

  mouse_x = MouseX;
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
  dword_4B8CCC = pcursmonst;
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
  v12 = DUNGEON_WIDTH * world_x + world_y;
  v81 = DUNGEON_WIDTH * world_x + world_y;
  v13 = DUNGEON_WIDTH * world_x + world_y;
  if (add_to_index)
  {
    v14 = v13;
    v15 = dMonster[1][v14 + 2];
    if (!v15)
      goto LABEL_74;
    player_not_invinsible = (dFlags[1][v12 + 2] & 0x40) == 0;
  }
  else
  {
    v14 = v13;
    v15 = dMonster[2][v14 + 1];
    if (!v15)
      goto LABEL_74;
    player_not_invinsible = (dFlags[2][v12 + 1] & 0x40) == 0;
  }
  if (!player_not_invinsible)
  {
    v17 = v15 <= 0 ? -1 - v15 : v15 - 1;
    if (v17 == dword_4B8CCC &&
        (signed int)(monster[v17]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[v17].MData->mSelFlag & 4)
    {
      monster_id = v17;
      cursmx = world_x + 1;
      cursmy = world_y + 2;
      pcursmonst = v17;
    }
  }
LABEL_74:
  v18 = dMonster[2][v14 + 2];
  if (v18 && dFlags[2][v81 + 2] & 0x40)
  {
    v19 = v18 <= 0 ? -1 - v18 : v18 - 1;
    if (v19 == dword_4B8CCC &&
        (signed int)(monster[v19]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[v19].MData->mSelFlag & 4)
    {
      monster_id = v19;
      cursmx = world_x + 2;
      cursmy = world_y + 2;
      pcursmonst = v19;
    }
  }
  if (add_to_index)
  {
    v22 = dMonster[0][v14 + 1];
    if (v22 && dFlags[0][v81 + 1] & 0x40)
    {
      v21 = v22 <= 0 ? -1 - v22 : v22 - 1;
      if (v21 == dword_4B8CCC &&
          (signed int)(monster[v21]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[v21].MData->mSelFlag & 2)
      {
        cursmx = world_x;
        cursmy = world_y + 1;
        goto LABEL_102;
      }
    }
  }
  else
  {
    v20 = dMonster[1][v14];
    if (v20 && dFlags[1][v81] & 0x40)
    {
      v21 = v20 <= 0 ? -1 - v20 : v20 - 1;
      if (v21 == dword_4B8CCC &&
          (signed int)(monster[v21]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[v21].MData->mSelFlag & 2)
      {
        cursmy = world_y;
        cursmx = world_x + 1;
      LABEL_102:
        monster_id = v21;
        pcursmonst = v21;
        goto LABEL_103;
      }
    }
  }
LABEL_103:
  v23 = dMonster[0][v14];
  if (v23 && dFlags[0][v81] & 0x40)
  {
    v24 = v23 <= 0 ? -1 - v23 : v23 - 1;
    if (v24 == dword_4B8CCC &&
        (signed int)(monster[v24]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[v24].MData->mSelFlag & 1)
    {
      monster_id = v24;
      cursmx = world_x;
      cursmy = world_y;
      pcursmonst = v24;
    }
  }
  v25 = dMonster[1][v14 + 1];
  if (v25 && dFlags[1][v81 + 1] & 0x40)
  {
    v26 = v25 <= 0 ? -1 - v25 : v25 - 1;
    if (v26 == dword_4B8CCC &&
        (signed int)(monster[v26]._mhitpoints & 0xFFFFFFC0) > 0 &&
        monster[v26].MData->mSelFlag & 2)
    {
      monster_id = v26;
      cursmx = world_x + 1;
      cursmy = world_y + 1;
      pcursmonst = v26;
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
      v28 = tile_array_index + world_y;
      v32 = dMonster[1][v28 + 2];
      if (v32 && dFlags[1][tile_array_index + 2 + world_y] & 0x40)
      {
        v30 = v32 <= 0 ? -1 - v32 : v32 - 1;
        if ((signed int)(monster[v30]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[v30].MData->mSelFlag & 4)
        {
          cursmx = world_x + 1;
          v31 = world_y + 2;
          goto LABEL_145;
        }
      }
    }
    else
    {
      v28 = tile_array_index + world_y;
      v29 = dMonster[2][v28 + 1];
      if (v29 && dFlags[2][tile_array_index + 1 + world_y] & 0x40)
      {
        v30 = v29 <= 0 ? -1 - v29 : v29 - 1;
        if ((signed int)(monster[v30]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[v30].MData->mSelFlag & 4)
        {
          cursmx = world_x + 2;
          v31 = world_y + 1;
        LABEL_145:
          cursmy = v31;
          pcursmonst = v30;
          goto LABEL_146;
        }
      }
    }
  LABEL_146:
    v33 = dMonster[2][v28 + 2];
    if (v33 && dFlags[2][tile_array_index + 2 + world_y] & 0x40)
    {
      v34 = v33 <= 0 ? -1 - v33 : v33 - 1;
      if ((signed int)(monster[v34]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[v34].MData->mSelFlag & 4)
      {
        pcursmonst = v34;
        cursmx = world_x + 2;
        cursmy = world_y + 2;
      }
    }
    if (add_to_index)
    {
      v37 = dMonster[0][v28 + 1];
      if (v37 && dFlags[0][tile_array_index + 1 + world_y] & 0x40)
      {
        v36 = v37 <= 0 ? -1 - v37 : v37 - 1;
        if ((signed int)(monster[v36]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[v36].MData->mSelFlag & 2)
        {
          cursmx = world_x;
          cursmy = world_y + 1;
          goto LABEL_171;
        }
      }
    }
    else
    {
      v35 = dMonster[1][v28];
      if (v35 && dFlags[1][tile_array_index + world_y] & 0x40)
      {
        v36 = v35 <= 0 ? -1 - v35 : v35 - 1;
        if ((signed int)(monster[v36]._mhitpoints & 0xFFFFFFC0) > 0 &&
            monster[v36].MData->mSelFlag & 2)
        {
          cursmy = world_y;
          cursmx = world_x + 1;
        LABEL_171:
          pcursmonst = v36;
          goto LABEL_172;
        }
      }
    }
  LABEL_172:
    v38 = dMonster[0][v28];
    if (v38 && dFlags[0][tile_array_index + world_y] & 0x40)
    {
      v39 = v38 <= 0 ? -1 - v38 : v38 - 1;
      if ((signed int)(monster[v39]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[v39].MData->mSelFlag & 1)
      {
        cursmx = world_x;
        cursmy = world_y;
        pcursmonst = v39;
      }
    }
    v40 = dMonster[1][v28 + 1];
    if (v40 && dFlags[1][tile_array_index + 1 + world_y] & 0x40)
    {
      v41 = v40 <= 0 ? -1 - v40 : v40 - 1;
      if ((signed int)(monster[v41]._mhitpoints & 0xFFFFFFC0) > 0 &&
          monster[v41].MData->mSelFlag & 2)
      {
        pcursmonst = v41;
        cursmx = world_x + 1;
        cursmy = world_y + 1;
      }
    }
    v42 = pcursmonst;
    if (pcursmonst == -1)
      goto LABEL_207;
    if (monster[pcursmonst]._mFlags & 1)
    {
      v42 = -1;
      cursmx = world_x;
      pcursmonst = -1;
      cursmy = world_y;
    }
    if (v42 == -1)
      goto LABEL_207;
    if (monster[v42]._mFlags & 0x20)
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
// 4B8CCC: using guessed type int dword_4B8CCC;
// 52569C: using guessed type int zoomflag;
// 52575C: using guessed type int doomflag;
// 5BB1ED: using guessed type char leveltype;
// 69BD04: using guessed type int questlog;
