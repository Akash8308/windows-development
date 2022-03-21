class ISum :public IUnknown
{
public:
	virttual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;

};

class ISubtract :public IUknown
{
public:
	virtual HRESULT __stdcall SubtractionOfTwoIntergers(int, int, int*) = 0;
	//pure virtual

};
//CLSID of SumSubtract Component {DBF1278D-20D3-4388-A83D-2F2DE4EF59}
const CLSID CLSID_SumSubtract = { 0x18e6b134, 0x78b3, 0x41fd, 0xb0, 0x4a, 0x7f, 0xa1, 0x8c, 0xe7, 0x6c, 0xbe };

//IID of ISum Interface

const IID IID_Sum = {};

// IID of ISubtractinterface

cosnt IID IID_ISubtract = {};
