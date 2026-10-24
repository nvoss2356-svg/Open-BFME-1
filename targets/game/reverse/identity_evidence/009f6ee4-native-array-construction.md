# Native vector-construction iterator, 009F6EE4

The ledger's existing MSVC compiler identity is `??_L@YGXPAXIHP6EX0@Z1@Z`.
The complete entry is RVA 009F6EE4 through RET 20 at +0047, ending +004A.
The adjacent action at 009F6F2E is a 24-byte finally funclet, ending RET at
+0017. Its sole parent call is the iterator at +003D. No parent was inferred
from adjacency: the direct call and the iterator's SEH scope table establish it.

The iterator registers SEH through existing __SEH_prolog and __SEH_epilog,
initializes a completion flag and constructed count, invokes each callback
with ECX = current element, and advances the element pointer by stride.
The completion flag becomes one only after all elements are constructed.
The finally action calls the existing __ArrayUnwind body only on failure.

MSVC 7.1 rejects spelling a free-function pointer with __thiscall (C4234).
A single-inheritance pointer to a no-argument member has the same one-word
representation and ECX callback convention. The source checks its size at
compile time; it invents no element hierarchy or semantic class identity.
The original compiler identity stays unchanged; the existing object-symbol
mapping now names the actual typed C++ emitter instead of a naked dump.

The destructor callback is only forwarded by this implementation, so its
parameter is an opaque `void *` machine address. The constructor callback
that is actually invoked retains the checked member-pointer representation.
The attempted abi-view declarations were rejected because abi_view deliberately
does not decode callback function-pointer decorations, including the canonical
CRT name. No such exemption is retained. Instead the dependency uses a direct
self-addressed `d_009f6d18` reference, the existing pin guard's explicit
address-reference mechanism. It asserts only the independently decoded address
and four-word calling convention, and never a second semantic identity.

The one narrow dependency view is
`?d_009f6d18@@YGXPAXIH0@Z`, referencing canonical
`?__ArrayUnwind@@YGXPAXIHP6EX0@Z@Z` at RVA 009F6D18. Its independent complete
47-byte decode proves stdcall RET 16, four stack words (array, unsigned stride,
signed count, callback), decrement-before-test reverse iteration, pointer
subtraction by stride, and invocation of callback with ECX = element.
The canonical identity remains owned by the existing MSVC CRT archive row.

With /O1, native __try/__finally reproduces all 98 bytes modulo four address
relocations. /O2 emits 140 bytes and /Od 160; /Os also reproduces 98 bytes.
The native compiler creates the cleanup and scope table. The source contains
no inline assembly, byte emission, numeric image address, or manual frame.

The emitted `$T315` scope table also matches all 12 retail bytes at VA
01145890 after binding its one native text-label relocation: the words are
FFFFFFFF, 00000000, 00DF6F2E. Its action is `$L310` at parent offset 004A.
The strict scoped gate verifies both the 74-byte entry and the 24-byte action.
