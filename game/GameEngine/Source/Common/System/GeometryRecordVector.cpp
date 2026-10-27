// cl: /EHsc /Igame/Libraries/Source/WWVegas/WWLib
// stlport
// Open-BFME: canonical GeometryRecord vector specialization used by the
// GeometryInfo constructor at retail 0x00100580.
//
// The exact constructor supplies vector<GeometryRecord>'s +0x38 owner and
// calls erase through ILT 0x0001BD38.  The thunk routes to the 76-byte body at
// 0x000FF890.  Its 0x10-byte stride agrees with GeometryRecord's three scalar
// fields and one-pointer AsciiString member.

#include <vector>

#include "ascii_string.h"

struct GeometryRecord
{
	int m_first;
	int m_second;
	int m_third;
	AsciiString m_name;
	~GeometryRecord();
};

template class _STL::vector<GeometryRecord>;

// Retail 0x00100570 forwards this vector's [begin, finish) range to the
// canonical GeometryRecord erase specialization.  No retail ILT slot names
// the clear specialization, so the callable identity remains RVA-derived.
class Rva00100570GeometryRecordVector
{
public:
	void method();

private:
	GeometryRecord *m_begin;
	GeometryRecord *m_finish;
	GeometryRecord *m_end;
};

void Rva00100570GeometryRecordVector::method()
{
	_STL::vector<GeometryRecord> *records =
		reinterpret_cast<_STL::vector<GeometryRecord> *>(this);
	records->erase(m_begin, m_finish);
}
