// cl: /EHs-c-
// Eight more bodies in two shapes.
//
// 0x00783A50, 0x008925F0, 0x00892CA0 and 0x00893990 test a pointer member,
// run it past a __cdecl check, and only when that check answers zero hand the
// same member to a second __cdecl call. The member is RE-READ for the second
// call rather than kept in a register, which is what a plain member expression
// gives once a call sits between the two uses.
//
// 0x008AB8E0, 0x008BD820, 0x008BD880 and 0x008BD8E0 are destructors of classes
// that own one child at +0x10. The vptr store lands between the test and the
// branch. The child is released with an explicit destructor call followed by a
// two-argument free carrying the size, which is the class-level
// operator delete(void *, size_t) form -- the size sixteen is sizeof of the
// child, not a constant the body computes.

class Rva00894D90Accessor
{
public:
	static unsigned int decrement(unsigned int *value);	// retail 0x00894D90
};

__declspec(noinline) void bfmeDropA(void *p);		// retail 0x00895320
int bfmeCheckB(void *p);					// retail 0x00894DB0
__declspec(noinline) void bfmeDropB(void *p);		// retail 0x008961C0

extern void (*TheBfmeFree)(void *p, unsigned int bytes);	// 0x01337830

class BfmeChildA
{
public:
	~BfmeChildA(void);					// retail 0x008976E0

	void operator delete(void *p, unsigned int bytes) { TheBfmeFree(p, bytes); }

private:
	char m_bfmePad[0x10];
};

class BfmeChildB
{
public:
	~BfmeChildB(void);					// retail 0x0089CC70

	void operator delete(void *p, unsigned int bytes) { TheBfmeFree(p, bytes); }

private:
	char m_bfmePad[0x10];
};

class BfmeDropObjectA
{
public:
	~BfmeDropObjectA(void);

	void operator delete(void *p, unsigned int bytes) { TheBfmeFree(p, bytes); }

private:
	char m_bfmePad[0x18];
};

class BfmeDropObjectB
{
public:
	~BfmeDropObjectB(void);

	void operator delete(void *p, unsigned int bytes) { TheBfmeFree(p, bytes); }

private:
	char m_bfmePad[0x10];
};


class Gen_00783A50
{
public:
	void bfmeCleanup(void);

private:
	void *m_bfmeItem;
};

class Gen_008925F0
{
public:
	void bfmeCleanup(void);

private:
	void *m_bfmeItem;
};

class Gen_00892CA0
{
public:
	void bfmeCleanup(void);

private:
	void *m_bfmeItem;
};

class Gen_00893990
{
public:
	void bfmeCleanup(void);

private:
	void *m_bfmeItem;
};

class Gen_008AB8E0
{
public:
	~Gen_008AB8E0(void);

	virtual void bfmeSlot0(void);

private:
	char m_bfmeHead[0x10 - 4];
	BfmeChildA *m_bfmeChild;				// +0x10
};

class Gen_008BD820
{
public:
	~Gen_008BD820(void);

	virtual void bfmeSlot0(void);

private:
	char m_bfmeHead[0x10 - 4];
	BfmeChildB *m_bfmeChild;				// +0x10
};

class Gen_008BD880
{
public:
	~Gen_008BD880(void);

	virtual void bfmeSlot0(void);

private:
	char m_bfmeHead[0x10 - 4];
	BfmeChildB *m_bfmeChild;				// +0x10
};

class Gen_008BD8E0
{
public:
	~Gen_008BD8E0(void);

	virtual void bfmeSlot0(void);

private:
	char m_bfmeHead[0x10 - 4];
	BfmeChildB *m_bfmeChild;				// +0x10
};

// ?bfmeDropA@@YAXPAX@Z
__declspec(noinline) void bfmeDropA(void *p)
{
	delete (BfmeDropObjectA *)p;
}

// ?bfmeDropB@@YAXPAX@Z
__declspec(noinline) void bfmeDropB(void *p)
{
	delete (BfmeDropObjectB *)p;
}

// ?bfmeCleanup@Gen_00783A50@@QAEXXZ
void Gen_00783A50::bfmeCleanup(void)
{
	if (m_bfmeItem)
	{
		if (Rva00894D90Accessor::decrement((unsigned int *)m_bfmeItem) == 0)
			bfmeDropA(m_bfmeItem);
	}
}

// ?bfmeCleanup@Gen_008925F0@@QAEXXZ
void Gen_008925F0::bfmeCleanup(void)
{
	if (m_bfmeItem)
	{
		if (bfmeCheckB(m_bfmeItem) == 0)
			bfmeDropB(m_bfmeItem);
	}
}

// ?bfmeCleanup@Gen_00892CA0@@QAEXXZ
void Gen_00892CA0::bfmeCleanup(void)
{
	if (m_bfmeItem)
	{
		if (bfmeCheckB(m_bfmeItem) == 0)
			bfmeDropB(m_bfmeItem);
	}
}

// ?bfmeCleanup@Gen_00893990@@QAEXXZ
void Gen_00893990::bfmeCleanup(void)
{
	if (m_bfmeItem)
	{
		if (bfmeCheckB(m_bfmeItem) == 0)
			bfmeDropB(m_bfmeItem);
	}
}

// ??1Gen_008AB8E0@@QAE@XZ
Gen_008AB8E0::~Gen_008AB8E0(void)
{
	delete m_bfmeChild;
}

// ??1Gen_008BD820@@QAE@XZ
Gen_008BD820::~Gen_008BD820(void)
{
	delete m_bfmeChild;
}

// ??1Gen_008BD880@@QAE@XZ
Gen_008BD880::~Gen_008BD880(void)
{
	delete m_bfmeChild;
}

// ??1Gen_008BD8E0@@QAE@XZ
Gen_008BD8E0::~Gen_008BD8E0(void)
{
	delete m_bfmeChild;
}

class Gen_008C6BC0
{
public:
	void bfmeReset();
};

class Gen0089C880
{
public:
	void handle();
};

struct Rva008AE770Stack;
extern Rva008AE770Stack Rva008AE770TheStack;
extern void *g_Rva01337A28Index;
extern int g_bfmeB1038;
extern int g_bfmeRegisterClass1015;

struct Rva00899AF0View
{
	virtual void slot00();
	virtual void slot04();
	virtual void slot08();
};

class Rva89A2C0Derived; extern Rva89A2C0Derived *g_Va013379B4;
class BfmeThingVDW; extern BfmeThingVDW *g_Va013379FC;
class Rva89A540Derived; extern Rva89A540Derived *g_Va013379AC;
struct Rva00899C20Registry; extern Rva00899C20Registry *g_Va013387D8;
struct BfmeMap1024; extern BfmeMap1024 *g_bfmeMap1024;
class Rva89AA20Derived; extern Rva89AA20Derived *g_Va01337A00;
class Rva008A9B00; extern Rva008A9B00 *g_Va013379F0;
class BfmeA1029;
extern BfmeA1029 *g_Va013379EC;
extern BfmeA1029 *g_Va013379C4;
extern BfmeA1029 *g_Va013379C8;
extern BfmeA1029 *g_Va013379F8;
extern BfmeA1029 *g_Va013379B8;
extern BfmeA1029 *g_Va013379B0;
extern BfmeA1029 *g_Va01337A2C;

// Keep the index lifetime inside the conditional cleanup. Inlining this
// helper reproduces retail's conditional EDI save rather than a prologue save.
static __forceinline void dispose00899AF0(Gen0089C880 *index)
{
	index->handle();
	delete (BfmeChildA *)index;
}

// The original API name is unknown. Entry 0x00899AF0 is called by 0x00894A90;
// its complete body ends with RET at +0x128 followed by INT3 padding.
void d_00899af0()
{
	((Gen_008C6BC0 *)&Rva008AE770TheStack)->bfmeReset();
	if (g_Rva01337A28Index)
	{
		dispose00899AF0((Gen0089C880 *)g_Rva01337A28Index);
		g_Rva01337A28Index = 0;
	}
	((Rva00899AF0View *)g_Va013379B4)->slot08();
	((Rva00899AF0View *)g_Va013379FC)->slot08();
	((Rva00899AF0View *)g_Va013379AC)->slot08();
	((Rva00899AF0View *)g_Va013387D8)->slot08();
	((Rva00899AF0View *)g_bfmeMap1024)->slot08();
	((Rva00899AF0View *)g_Va01337A00)->slot08();
	((Rva00899AF0View *)g_Va013379F0)->slot08();
	TheBfmeFree((void *)g_bfmeB1038, 0x3C0);
	((Rva00899AF0View *)g_Va013379EC)->slot08(); g_Va013379EC = 0;
	((Rva00899AF0View *)g_Va013379C4)->slot08(); g_Va013379C4 = 0;
	((Rva00899AF0View *)g_Va013379C8)->slot08(); g_Va013379C8 = 0;
	((Rva00899AF0View *)g_Va013379F8)->slot08(); g_Va013379F8 = 0;
	((Rva00899AF0View *)g_Va013379B8)->slot08(); g_Va013379B8 = 0;
	((Rva00899AF0View *)g_Va013379B0)->slot08(); g_Va013379B0 = 0;
	((Rva00899AF0View *)g_Va01337A2C)->slot08(); g_Va01337A2C = 0;
	((Rva00899AF0View *)g_bfmeRegisterClass1015)->slot08(); g_bfmeRegisterClass1015 = 0;
}
