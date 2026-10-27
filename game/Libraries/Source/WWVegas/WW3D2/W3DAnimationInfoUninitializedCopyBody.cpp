// cl: /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// Open-BFME5: the real out-of-line body of
// __uninitialized_copy<const W3DAnimationInfo *, W3DAnimationInfo *>.
// The sibling *UninitializedCopy*.cpp claims the 5-byte incremental-link thunk
// at 0x0001D5F7 that reaches it; this TU carries the body it jumps to. The
// The retail copies require different out-of-line constructors: 0x003AA640's
// target is the 16-byte helper at 0x003A93F0, while 0x00784E70's target is
// _Construct<W3DAnimationInfo> at 0x00784DD0.  Distinct C++ bodies can preserve
// both relocation targets.

// upstream layout: inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include/W3DDevice/GameClient/Module/W3DModelDraw.h
class W3DAnimationInfo
{
public:
	int m_raw[4];
};

struct Elem16;
void gen003A93F0(Elem16 *destination, const Elem16 *source);
void gen00784DD0(Elem16 *destination, const Elem16 *source);

namespace _STL
{
struct __false_type
{
};

template <class In, class Out>
Out __uninitialized_copy(In first, In last, Out result, const __false_type &)
{
	Out current = result;
	while (first != last)
	{
		gen003A93F0(reinterpret_cast<Elem16 *>(current),
			reinterpret_cast<const Elem16 *>(first));
		++first;
		++current;
	}
	return current;
}

template W3DAnimationInfo *__uninitialized_copy<const W3DAnimationInfo *, W3DAnimationInfo *>(
    const W3DAnimationInfo *, const W3DAnimationInfo *, W3DAnimationInfo *, const __false_type &);

W3DAnimationInfo *rva00784E70W3DAnimationInfoUninitializedCopy(
	const W3DAnimationInfo *first, const W3DAnimationInfo *last,
	W3DAnimationInfo *result, const __false_type &)
{
	W3DAnimationInfo *current = result;
	while (first != last)
	{
		gen00784DD0(reinterpret_cast<Elem16 *>(current),
			reinterpret_cast<const Elem16 *>(first));
		++first;
		++current;
	}
	return current;
}
}
