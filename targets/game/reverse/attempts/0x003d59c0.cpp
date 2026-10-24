// ?rva003D59C0@@YGHHPBURva003D59C0Obj@@HH@Z
// partial score=0.7692 date=2026-10-24
// cl: /O2 /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD
struct Rva003D59C0Obj { char pad[12]; unsigned low:3; unsigned:15; signed high:1;unsigned:13; };
int __stdcall rva003D59C0(int,const Rva003D59C0Obj *o,int,int) { if(o->low != 0 && o->low != 1) return 1; return o->high & 1; }
