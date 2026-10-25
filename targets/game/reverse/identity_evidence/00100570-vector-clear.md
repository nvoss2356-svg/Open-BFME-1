# `0x00100570`: address-derived GeometryRecord vector clear

Retail `0x00100570..0x0010057C` is a complete 13-byte body. It loads the
finish pointer from `[ecx+4]`, loads the begin pointer from `[ecx]`, pushes the
two iterators, calls ILT `0x0001BD38`, and returns. That ILT routes to the
byte-matched `_STL::vector<GeometryRecord>::erase` body at `0x000FF890`; the
exact `GeometryInfo` constructor and the matched copy and destruction helpers
independently establish the 16-byte `GeometryRecord` family.

This proves the operation but not a retail linker name. `tools/ilt_oracle.py`
rejects `?clear@?$vector@UGeometryRecord@@V?$allocator@UGeometryRecord@@@_STL@@@_STL@@QAEXXZ`:
the target lies outside every ILT window for that decoration. The corrected
claim therefore keeps the address in
`?method@Rva00100570GeometryRecordVector@@QAEXXZ` while its clean C++ body
expresses the proven erase of `[begin, finish)`.
