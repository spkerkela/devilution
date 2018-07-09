// HEADER_GOES_HERE

#include "../types.h"

void *sgpBackCel;
float interfac_cpp_init_value;
int sgdwProgress;
int progress_id; // idb

int interfac_inf = 0x7F800000; // weak
unsigned char progress_bar_colours[3] = {138u, 43u, 254u};
POINT32 progress_bar_screen_pos[3] = {{53, 37}, {53, 421}, {53, 37}};

//----- (0041B195) --------------------------------------------------------
struct interfac_cpp_init
{
  interfac_cpp_init() { interfac_cpp_init_value = interfac_inf; }
} _interfac_cpp_init;
// 47AE40: using guessed type int interfac_inf;

//----- (0041B1A0) --------------------------------------------------------
void __cdecl interface_msg_pump()
{
  MSG Msg; // [esp+8h] [ebp-1Ch]

  while (PeekMessageA(&Msg, NULL, 0, 0, PM_REMOVE))
  {
    if (Msg.message != WM_QUIT)
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
}

//----- (0041B1DF) --------------------------------------------------------
bool __cdecl IncProgress()
{
  interface_msg_pump();
  sgdwProgress += 15;
  if ((unsigned int)sgdwProgress > 0x216)
    sgdwProgress = 534;
  if (sgpBackCel)
    DrawCutscene();
  return (unsigned int)sgdwProgress >= 0x216;
}

//----- (0041B218) --------------------------------------------------------
void __cdecl DrawCutscene()
{
  unsigned int v0; // esi

  dx_lock_mutex();
  CelDecodeOnly(64, 639, sgpBackCel, 1, 640);
  v0 = 0;
  if (sgdwProgress)
  {
    do
      DrawProgress(progress_bar_screen_pos[progress_id].x + v0++ + 64,
                   progress_bar_screen_pos[progress_id].y + 160, progress_id);
    while (v0 < sgdwProgress);
  }
  dx_unlock_mutex();
  drawpanflag = 255;
  scrollrt_draw_game_screen(0);
}
// 52571C: using guessed type int drawpanflag;

//----- (0041B28D) --------------------------------------------------------
void __fastcall DrawProgress(int screen_x, int screen_y, int progress_id)
{
  _BYTE *v3;     // eax
  signed int v4; // ecx

  v3 = (unsigned char *)gpBuffer + screen_y_times_768[screen_y] + screen_x;
  v4 = 22;
  do
  {
    *v3 = progress_bar_colours[progress_id];
    v3 += 768;
    --v4;
  } while (v4);
}

//----- (0041B2B6) --------------------------------------------------------
void __fastcall ShowProgress(int uMsg)
{
  LRESULT(__stdcall * saveProc)
  (HWND, UINT, WPARAM, LPARAM); // edi
  bool new_game;                // cl
  int next_level;               // eax
  int entry_type;               // edx
  signed int entry_style;       // [esp-4h] [ebp-10h]

  gbSomebodyWonGameKludge = 0;
  plrmsg_delay(1);
  saveProc = SetWindowProc(DisableInputWndProc);
  interface_msg_pump();
  ClearScreenBuffer();
  scrollrt_draw_game_screen(1);
  InitCutscene(uMsg);
  BlackPalette();
  DrawCutscene();
  PaletteFadeIn(8);
  IncProgress();
  stream_update();
  IncProgress();
  switch (uMsg)
  {
  case WM_DIABNEXTLVL:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    FreeGameMem();
    next_level = ++currlevel;
    goto UPDATE_LEVEL_TYPE;
  case WM_DIABPREVLVL:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    IncProgress();
    FreeGameMem();
    leveltype = gnLevelTypeTbl[--currlevel];
    IncProgress();
    entry_type = 1;
    goto SET_NEW_GAME_TO_0;
  case WM_DIABRTNLVL:
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    setlevel = 0;
    FreeGameMem();
    IncProgress();
    GetReturnLvlPos();
    entry_style = 3;
    goto CONTINUE_WITH_ENTRY_STYLE;
  case WM_DIABSETLVL:
    SetReturnLvlPos();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    setlevel = 1;
    leveltype = setlvltype;
    FreeGameMem();
    IncProgress();
    entry_style = 2;
    goto CONTINUE_WITH_ENTRY_STYLE;
  case WM_DIABWARPLVL:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    FreeGameMem();
    GetPortalLevel();
    IncProgress();
    entry_style = 5;
    goto CONTINUE_WITH_ENTRY_STYLE;
  case WM_DIABTOWNWARP:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    FreeGameMem();
    currlevel = plr[myplr].plrlevel;
    leveltype = gnLevelTypeTbl[currlevel];
    IncProgress();
    entry_style = 6;
    goto CONTINUE_WITH_ENTRY_STYLE;
  case WM_DIABTWARPUP:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    FreeGameMem();
    currlevel = plr[myplr].plrlevel;
    leveltype = gnLevelTypeTbl[currlevel];
    IncProgress();
    entry_style = 7;
  CONTINUE_WITH_ENTRY_STYLE:
    entry_type = entry_style;
  SET_NEW_GAME_TO_0:
    new_game = 0;
    goto LOAD_GAME_LEVEL;
  case WM_DIABRETOWN:
    IncProgress();
    if (gbMaxPlayers == 1)
      SaveLevel();
    else
      DeltaSaveLevel();
    FreeGameMem();
    currlevel = plr[myplr].plrlevel;
    next_level = currlevel;
  UPDATE_LEVEL_TYPE:
    leveltype = gnLevelTypeTbl[next_level];
    IncProgress();
    new_game = 0;
    goto SET_ENTRY_TO_0;
  case WM_DIABNEWGAME:
    IncProgress();
    FreeGameMem();
    IncProgress();
    pfile_remove_temp_files();
    new_game = 1;
  SET_ENTRY_TO_0:
    entry_type = 0;
  LOAD_GAME_LEVEL:
    LoadGameLevel(new_game, entry_type);
    goto INCREMENT_PROGRESS;
  case WM_DIABLOADGAME:
    IncProgress();
    LoadGame(1);
  INCREMENT_PROGRESS:
    IncProgress();
    break;
  default:
    break;
  }
  PaletteFadeOut(8);
  FreeInterface();
  SetWindowProc(saveProc);
  NetSendCmdLocParam1(1u, CMD_PLAYER_JOINLEVEL, plr[myplr].WorldX,
                      plr[myplr].WorldY, plr[myplr].plrlevel);
  plrmsg_delay(0);
  ResetPal();
  if (gbSomebodyWonGameKludge && plr[myplr].plrlevel == 16)
    PrepDoEnding();
  gbSomebodyWonGameKludge = 0;
}
// 5BB1ED: using guessed type char leveltype;
// 5CF31C: using guessed type char setlvltype;
// 5CF31D: using guessed type char setlevel;
// 6761B8: using guessed type char gbSomebodyWonGameKludge;
// 679660: using guessed type char gbMaxPlayers;

//----- (0041B5F5) --------------------------------------------------------
void __cdecl FreeInterface()
{
  void *v0; // ecx

  v0 = sgpBackCel;
  sgpBackCel = 0;
  mem_free_dbg(v0);
}

//----- (0041B607) --------------------------------------------------------
void __fastcall InitCutscene(int interface_mode)
{
  int v1;            // eax
  int v2;            // eax
  int v3;            // eax
  int v4;            // eax
  unsigned char *v5; // eax
  char *v6;          // ecx
  int *v7;           // eax
  int v8;            // eax
  int v9;            // eax
  int v10;           // eax
  int v11;           // eax
  int v12;           // eax
  int v13;           // eax
  int v14;           // eax

  switch (interface_mode)
  {
  case WM_DIABNEXTLVL:
    v1 = gnLevelTypeTbl[currlevel];
    if (!v1)
      goto LABEL_31;
    v2 = v1 - 1;
    if (!v2)
      goto LABEL_10;
    v3 = v2 - 1;
    if (!v3)
      goto LABEL_9;
    v4 = v3 - 1;
    if (!v4)
      goto LABEL_29;
    if (v4 != 1)
      goto LABEL_10;
    if (currlevel < 0xFu)
      goto LABEL_28;
    v5 = LoadFileInMem("Gendata\\Cutgate.CEL", 0);
    v6 = "Gendata\\Cutgate.pal";
    goto LABEL_30;
  case WM_DIABPREVLVL:
    v7 = &gnLevelTypeTbl[currlevel];
    if (!*(v7 - 1))
      goto LABEL_31;
    v8 = *v7;
    if (!v8)
      goto LABEL_31;
    v9 = v8 - 1;
    if (!v9)
      goto LABEL_10;
    v10 = v9 - 1;
    if (!v10)
    {
    LABEL_9:
      sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0);
      LoadPalette("Gendata\\Cut2.pal");
      progress_id = 2;
      goto SET_NEW_GAME_TO_0;
    }
    v11 = v10 - 1;
    if (!v11)
      goto LABEL_29;
    if (v11 == 1)
      goto LABEL_28;
  LABEL_10:
    sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0);
    LoadPalette("Gendata\\Cutl1d.pal");
    progress_id = 0;
    goto SET_NEW_GAME_TO_0;
  case WM_DIABRTNLVL:
  case WM_DIABSETLVL:
    if (setlvlnum == SL_BONECHAMB)
      goto LABEL_21;
    if (setlvlnum != SL_VILEBETRAYER)
      goto LABEL_10;
    v5 = LoadFileInMem("Gendata\\Cutportr.CEL", 0);
    v6 = "Gendata\\Cutportr.pal";
    goto LABEL_30;
  case WM_DIABWARPLVL:
    v5 = LoadFileInMem("Gendata\\Cutportl.CEL", 0);
    v6 = "Gendata\\Cutportl.pal";
    goto LABEL_30;
  case WM_DIABTOWNWARP:
  case WM_DIABTWARPUP:
    v12 = gnLevelTypeTbl[plr[myplr].plrlevel];
    if (!v12)
      goto LABEL_31;
    v13 = v12 - 2;
    if (!v13)
    {
    LABEL_21:
      sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0);
      LoadPalette("Gendata\\Cut2.pal");
      progress_id = SL_BONECHAMB;
      goto SET_NEW_GAME_TO_0;
    }
    v14 = v13 - 1;
    if (v14)
    {
      if (v14 != 1)
        goto SET_NEW_GAME_TO_0;
    LABEL_28:
      v5 = LoadFileInMem("Gendata\\Cut4.CEL", 0);
      v6 = "Gendata\\Cut4.pal";
    }
    else
    {
    LABEL_29:
      v5 = LoadFileInMem("Gendata\\Cut3.CEL", 0);
      v6 = "Gendata\\Cut3.pal";
    }
  LABEL_30:
    sgpBackCel = v5;
    LoadPalette(v6);
    progress_id = 1;
  SET_NEW_GAME_TO_0:
    sgdwProgress = 0;
    return;
  case WM_DIABRETOWN:
  LABEL_31:
    v5 = LoadFileInMem("Gendata\\Cuttt.CEL", 0);
    v6 = "Gendata\\Cuttt.pal";
    goto LABEL_30;
  case WM_DIABNEWGAME:
  case WM_DIABLOADGAME:
    v5 = LoadFileInMem("Gendata\\Cutstart.CEL", 0);
    v6 = "Gendata\\Cutstart.pal";
    goto LABEL_30;
  default:
    TermMsg("Unknown progress mode");
    goto SET_NEW_GAME_TO_0;
  }
}
// 5CCB10: using guessed type char setlvlnum;
