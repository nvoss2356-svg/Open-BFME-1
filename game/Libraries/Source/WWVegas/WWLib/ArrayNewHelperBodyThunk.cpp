// cl: /DNDEBUG /MD /GX- /O1
// Retail MSVC vector-construction iterator at 0x009F6EE4. The ledger keeps
// its compiler ??_L identity. Native SEH emits the 74-byte entry and the
// adjacent 24-byte finally action. The one-word member pointer models the
// private thiscall callback convention without claiming an element identity.
class Rva009F6EE4Element {};
typedef void (Rva009F6EE4Element::*Rva009F6EE4Action)();
typedef char Rva009F6EE4OneWordCallback[
    sizeof(Rva009F6EE4Action) == sizeof(void *) ? 1 : -1];
void __stdcall d_009f6d18(void *, unsigned int, int, void *);

void __stdcall ArrayNewHelperBodyThunk(void *array, unsigned int stride, int count,
    Rva009F6EE4Action construct, void *destroy)
{
    int complete = 0;
    int index;
    __try {
        for (index = 0; index < count; ++index) {
            (((Rva009F6EE4Element *)array)->*construct)();
            array = (char *)array + stride;
        }
        complete = 1;
    }
    __finally {
        if (!complete)
            d_009f6d18(array, stride, index, destroy);
    }
}
