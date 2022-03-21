#include<Windows.h>
#include"ClassFactoryDLLServerWithRegFile.h"

// class declarations

class CSumSubtract :Pulic ISum, ISubtract
{
Private:
	long m_cRef;
Public:
	// constryctir metthod declarations
	SCumSubtract(void);
	~CSumSubrtac(void);

	HRESUL __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

};

class CSumSutractClassFactory :pulic IClassFactory
{
private:
	long m_cRef;
public:
	CSumSutractClassFactory(void);
	~CSumSutractClassFactory(void);

	HRESULT __stdcall QueryInterface(REFIID, VOID**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	HRESULT __stdcall CreateIntance(IUnknown*, REFIID, void**);
	HRESULT __stdcall Lockserver(BOOL);

};

// global variable declarations
long glNumberOfActiveComponents = 0;
long glNumberOfServerLocks = 0;
 // DLLMain

BOOL WINAPI DLLMain(HINTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
	//code
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH;
			break;
		case DLL_PROCESS_DETACH;
			break;

	}
	return(TRUE);
}

CSumSubtract::CSumSubtract(void)
{
	//code
	m_cRef = 1; //hardcoded initialization to anticipatte possible failure of QueryInterface()
	InterLockedIncrement(&glNumberOfActiveComponents); // inc global counter

}

//Implement of CSumSubtract's Destructor Method
CSumSubtract::~CSumSubtract(void)
{
	//code
	InterLockedDecrement(&glNumberOfActiveComponents);

}

HRESULT CSuSubtract::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid == IID_IUnknown)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISum)
		*ppc = static_cast<ISum*>(this);
	else if (riid == IID_ISubtract)
		*ppv = static_cast<ISubtract*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);

	}
	reinterpert_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);

}

ULONG CSumSubtract::AddRef(void);
{
	//code 
	InterLockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CSumSubtract::Release(void)
{
	//code
	InterLockedDecremment(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}
	return(m_cRef);
}

//Impleentation Od ISum's Methods
HRESULT CSumSubtract::SummOfTwoIntegers(int num1, int num2, int* pSum)
{
	//code
	*pSum = num1 + num2; 
	return(S_OK);

}

HRESULT CSumSubtract::SutractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	//code
	*pSubtract = num1 - nu2;
	return(S_OK);

}

CSumSubtractClassFactory::CSuSutractClassFactory(void)
{
	//code
	
}

HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	//code
	if (riid = IID_INknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);

	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);

}
OLONG CSumSubtractClassFactory::AddRef(void);
{
	InterlockedIncreent(&_cRef);
	return(c_ref);

}

ULONG CSuSutractClassFactory::Release(void)
{
	InterlockedDecreent(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}
	return(m_cRef);

}

HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declaration
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hr;
	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);
	pCSumSubtract = new CSumSubtract;
	if (pCSumSubtract == NULL)
		return(E_OUTOFMEMORY)
		//get the request interface
		hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();
	return(hr);

}

HRESULT CSumSubtractClassFactory::LockServer(BOOL flock)
{
	//code
	if (flock)
		InterlockedIncrement(&glNumberOfActiveServerLocks);
	else
		InterlockedDecrement(&glNumberOfActiceServerLocks);
	return(S_OK);


}

HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//variable declarations
	CSumSutractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hr;
	if (rclsid != CLSID_SumSubtract)
		return(CLASS_E_CLASSNOTAVAILABLE);
	//create class factory
	pCSumSubtractClassFactory = new CSumSutractClassFactory;
	if (pCSumSubtractClassFactory == NULL)
		return(E_OUTOFMEMORY);
	hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release();
	return(hr) :
}

HRESULT __stdcall DllCanUnloadNow(void)
{
	//code
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);

}













