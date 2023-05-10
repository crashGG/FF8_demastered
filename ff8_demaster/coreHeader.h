#pragma once

#include <sstream>
#include <cstdio>

#include <INIReader.h>
#include "renderer.h"
#include <memory>
#include "debug.h"
#include "mymemory.h"
#include "image.h"


#define EXPORT __declspec(dllexport)

BYTE* InjectJMP(DWORD address, DWORD functionAddress, int JMPsize = 5);
BOOL modPage(DWORD address, int size);
void ReplaceCALLWithNOP(DWORD address);
void InjectDWORD(DWORD address, DWORD value);

//From FFNx : https://github.com/julianxhokaxhiu/FFNx/blob/master/src/patch.h
uint32_t replace_function(uint32_t offset, void *func);
uint32_t get_relative_call(uint32_t base, uint32_t offset);
uint32_t get_absolute_value(uint32_t base, uint32_t offset);
void replace_call(uint32_t offset, void *func);
uint32_t replace_call_function(uint32_t offset, void* func);

inline DWORD IMAGE_BASE;
inline DWORD OPENGL_HANDLE;
inline const char* DIRECT_IO_EXPORT_DIR = "DEMASTER_EXP\\";
inline DWORD DIRECT_IO_EXPORT_DIR_LEN = strlen(DIRECT_IO_EXPORT_DIR);

extern bx::DefaultAllocator texAllocator;

#define UINT unsigned int

void ApplyDirectIO();
void ApplyUVPatch();

void ApplyBattleCharacterPatch();
void ApplyFieldEntityPatch();
void ApplyBattleHookPatch();
void ApplyBattleMonsterPatch();
void ApplyBattleFieldPatch();
void ApplyFieldBackgroundPatch();
void ApplyWorldPatch();
DWORD GetFieldBackgroundReplacementExist();

inline int lastWidth;
inline int lastHeight;
inline UCHAR* lastrgbBuffer;
inline UINT OPENGL_TEXTURES;

inline DWORD* tex_header;
inline DWORD* tex_struct;
inline DWORD* gl_textures;
inline DWORD pixelsPtr;
inline DWORD texturesPtr;

inline DWORD TEX_TYPE;

inline int currentMode;
inline std::string currentModeStr;

DWORD WtpCheck();
void WtpGl();
void FbgGl();

inline DWORD parm1; //arg+8

inline DWORD* langIdent_ESI;

inline int currentStage;
