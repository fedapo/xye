#pragma once

#include <tinyxml2.h>
#include <string>

#define PALETTE_BASE_SIZE 20

using std::string;

void TempMap();

class LevelPack
{
 private:
     static tinyxml2::XMLDocument* Doc;
     static tinyxml2::XMLElement* pack;
     static tinyxml2::XMLElement* CurrentLevel;
     static tinyxml2::XMLElement* FirstLevel;
     static void LoadInformation();

     static void LoadFirstLevel();
     static void LoadNthLevel(unsigned int n);
     static bool defmode;
     static bool kyemode;
     static bool xsbmode;

     static bool HasPrevious();
     static bool HasNext();

     LevelPack() {}
 public:
    static bool FromEditor;
    static void Init();
    static void Clean();
    static void Default(const char* msg = NULL);
    static void Error(const char * msg);

    static string CurrentLevelTitle;
    static unsigned int n;
    static string Author;
    static string Name;
    static string CurrentLevelBye;
    static string LevelError;

    static string OpenFile;
    static unsigned int OpenFileLn;

    static bool HasSolution();
    static string Solution;

    static void SetLevelBye(const char* bye);
    static string Desc;

    static void Load(const char *filename, unsigned int ln=0, const string replay="");
    //static void Load(const char *filename, unsigned int ln);
    //static void Load(const char *filename);
    static void Restart();
    static void Next();
    static void Last();
    static bool GetFileData(const char* filename, string &au, string &ds, string &ti, unsigned int &leveln);

    static bool AllowUndo();
};

void LoadLevel(tinyxml2::XMLElement* level);
struct KyeLevel;
bool LoadKyeFormatTag(tinyxml2::XMLElement* kft, KyeLevel* out);
bool LoadKyeFormat(tinyxml2::XMLElement* kf);



class Level
{
 private:
    Level() {}
 public:

    static unsigned int n;
    static string Author;
    static string Name;
    static string Title;

    static void Reset();


};


enum palette_mode
{
    PM_MULTIPLY,
    PM_RECOLOR
};
struct colorentry
{
    unsigned int id;
    unsigned int color;
    Uint8 R;
    Uint8 G;
    Uint8 B;
    palette_mode pm;
    colorentry* next;
};

class palette
{
 private:
    static colorentry* ls[PALETTE_BASE_SIZE];
    static bool ready;
    static colorentry* GetEntry(int id, bool create=false);
    palette() {}
 public:
    static void SetColor(int id, unsigned int color, palette_mode pm=PM_MULTIPLY);
    static void SetColor(int id, int r, int g, int b, palette_mode pm=PM_MULTIPLY);
    static unsigned int GetColor(int id);
    static void GetColor(int id, Uint8 &R, Uint8 &G,Uint8 &B);
    static void GetColor(int id, Uint8 &R, Uint8 &G,Uint8 &B, palette_mode& pm);
    static void Clear();
};


blockcolor GetElementBlockColor(tinyxml2::XMLElement* el,blockcolor def=B_YELLOW);
edir GetElementDir(tinyxml2::XMLElement* el,edir def=D_LEFT,const char* tag="dir");
