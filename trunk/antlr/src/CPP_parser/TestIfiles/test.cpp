//#line 0 "test.cpp"
#pragma warning(disable:4430)
namespace test_case
{
/*
char s3[256] = {0};
char s4[2][120];

extern int e_int = 0;
int k, l = 3, m;
static int i;
int j = 3;
char *a, b;
int n = 3*(3 + (2 - 1));
char* p = new char[12];
char* pData = (char*)new char[12];
char* s1 = "my name";
char s2[] = "my name";
int& m = n;
*/
class data
{
public:
	data(const char*, int) {}
	~data() {}

public:
	bool doFoo(const char* input)
	{
		return true;
	}
protected:
	void MyFunc();

	class data_1
	{
	public:
		void MyFunc_1();
	};
private:
	//test member_declarator case 1
	unsigned char s1:3;
	unsigned char s2:5;
};

void data::MyFunc()
{
}

void data::data_1::MyFunc_1()
{

}
/*
namespace test_case_template_1
{

	template<typename T>
	class Another
	{
		template<class Basic>
		Another(Basic an) {}
	};

	template <class Key,  class T, class Compare = Another<Key>,  template <class> class Alloc = Another>
	class YetAnother
	{
	public:
		YetAnother();
		~YetAnother();
		void Function1();
		Alloc<T> at;
		static char* m_str;
	};

	template<class Key,  class T, class Compare,  template <class> class Alloc>
	void YetAnother<Key, T, Compare, Alloc>::Function1()
	{}

	template<class Key,  class T, class Compare,  template <class> class Alloc>
	YetAnother<Key, T, Compare, Alloc>::~YetAnother()
	{}
	

	template<class Key,  class T, class Compare,  template <class> class Alloc>
	char* YetAnother<Key, T, Compare, Alloc>::m_str = "What's the problem";

	template<typename T, class S = Another<T>, typename R = int[], typename X = Another<T>*>
	class Third
	{
	public:
		Third()	{}
		~Third() {}
	};
}

template<class Key,  class T, class Compare,  template <class> class Alloc>
test_case_template_1::YetAnother<Key, T, Compare, Alloc>::YetAnother()
{
}


namespace test_case_template_2
{
	template<class R, typename A1, typename A2>
	R CallLua(A1 a1, A2 a2)
	{
		return R(a1, a2);
	}
}

template<typename T, class S>
class MyTemplate
{
public:
	MyTemplate(T* pData)
		: m_pData(pData),m_pS(0) {}
	virtual ~MyTemplate() {}

private:
	T* m_pData;
	S* m_pS;
};

namespace test_case_declaration_1
{
	MyTemplate<int, int> returnTemplate(int a, char* b = 0)
	{
		return MyTemplate<int, int>(0);
	}

	void setname(const char* sname);
	bool fourth, (isdigit)(const char* ch);
	
	int first, getname(int id);
	int (fifth),(digits)[1][1];

	class TestDeclaration
	{
	public:
		virtual void what() = 0;
		virtual int second(), getline(int id) = 0, (getvalue)(char ch);
		virtual defaultreturn();
		virtual defaultreturn2()
		{
			return 0;
		}
	};
}

namespace test_case_interface_1
{
	struct IUnknown
	{
	public:
		virtual ~IUnknown() = 0;
	};

	struct IInterface : virtual public IUnknown, public MyTemplate<MyTemplate<int,int>, int>
	{
	public:
		virtual ~IInterface() = 0;

		virtual void Connect(const char* pAddr, unsigned short uPort) = 0;
		virtual void DisConnect() = 0;
	};
}

data d1("my name", 10 + 3);

void setValue1(char *v);
int setValue2(char *v, int i);

typedef struct tagGoods
{
	int nSize;
	short nPort;
	long lAddress;
}GOODS, *LPGOODS;
LPGOODS v;

MyTemplate<char> s_q;

int setValue3(int v, int i)
{
	MyTemplate<MyTemplate<char,char>,char> q;
	char* p;
	int nSize = (1 + (2-4)*3);
	p = pData;
}

//test K&R function declaration
const char* originalFunc(param1, param2)
char param1;char* param2; 
{
	printf("param1:%c\nparam2:%s\n", param1, param2);
	return "originalFunc";
}

extern int g_count;

namespace test_case_function_typedef
{
	class STUDENT;
	typedef struct tagSTUDENT
	{
		int nID;
		char szName[256];
		typedef struct tagScore
		{
			int nMath;
			int nEnglish;
		}SCORE,*LPSCORE;
		SCORE oScore;
	}STUDENT,*LPSTUDENT;
	STUDENT st;

	struct tagIP
	{
		int nIP;
	} aIP;
	struct tagIP bIp = aIP;

	int callback(int idx, void* pParam)
	{
		return 0;
	}

	typedef int INT;
	typedef int (*CALLBACK)(int idx, void* pParam);
	int (*cb2)(int idx, void* pParam) = callback;
	CALLBACK cb = callback;

	int sum(int a, int b){return a+b;}
	int subtract(int a, int b){return a-b;}
	int mul(int a, int b){return a*b;}
	int div(int a, int b){return a/b;}

	int (*p[4]) (int x, int y) = {
		sum, subtract, mul, div
	} ;
	void printf(const char* format, ...);
}

namespace test_case_enum_union
{
	class Display;
	Display* g_display;

	typedef enum tagMediaType{
		ePhoto = 1,
		eMusic = 2,
		eAll = ePhoto | eMusic,
	}MEDIATYPE;

	MEDIATYPE eMedia;

	enum
	{
		eVisible,
		eUnVisible,
	}vis;
	typedef struct in_addr 
	{
		union {
			struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
			struct { unsigned short s_w1,s_w2; } S_un_w;
			unsigned long S_addr;
		} S_un;
	}INADDR;
}

namespace test_case_template_memberfunctor_declartor
{
	typedef int HRESULT;
	typedef unsigned int WPARAM;
	typedef unsigned int LPARAM;

	template<typename A1, typename A2, typename A3>
	class invoker
	{
	public:
		virtual ~invoker() {}
		virtual HRESULT operator()(A1 _a1, A2 _a2, A3 _a3) const = 0;
		virtual bool is_functor() const = 0;
		virtual bool operator==(const invoker& ink) = 0;
	};

	template<class _Ty, typename T1, typename T2, typename T3>
	class mem_functor : public invoker<T1, T2, T3>
	{
	public:
		explicit mem_functor(HRESULT (_Ty::*_Pm)(T1, T2, T3), _Ty* _This)
			: _Ptr(_Pm), _param(_This){}

		virtual HRESULT operator()(T1 _a1, T2 _a2, T3 _a3) const
		{
			return 0; 
		}

		virtual bool is_functor() const
		{
			return false; 
		}

		virtual bool operator==(const invoker<T1, T2, T3>& ink)
		{ 
		}
	private:
		HRESULT (_Ty::*_Ptr)(T1, T2, T3);
		_Ty* _param;
	};

	template<typename A1, typename A2, typename A3>
	class functor_t : public invoker<A1, A2, A3>
	{
	public:
		typedef HRESULT (*Functor)(A1, A2, A3);
		explicit functor_t(Functor _Pm)
			: _Ptr(_Pm){}
		virtual HRESULT operator()(A1 _a1, A2 _a2, A3 _a3) const
		{
			return _Ptr(_a1, _a2, _a3); 
		}

		virtual bool is_functor() const
		{
			return true; 
		}

		virtual bool operator==(const invoker<A1,A2,A3>& ink)
		{ 
		}
	private:
		Functor _Ptr;
	};

	typedef int IRctEventParam;

	__declspec(dllexport) int myExportFunction();

	class __declspec(dllexport) CRctEvetnHandler
	{
	public:
		typedef HRESULT (*Functor)(WPARAM, LPARAM, IRctEventParam*);
		CRctEvetnHandler() 
			: functor(0)	{}
		virtual ~CRctEvetnHandler()
		{
		}

		template<class _Ty>
		CRctEvetnHandler(HRESULT (_Ty::*_Pm)(WPARAM, LPARAM, IRctEventParam*), _Ty* _This, unsigned long _a1)
		{
		}
		CRctEvetnHandler(HRESULT (*_Pm)(WPARAM, LPARAM, IRctEventParam*), unsigned long _a1)
		{
		}
	public:
	private:
		invoker<WPARAM, LPARAM, IRctEventParam*>* functor;
		IRctEventParam* parameter;
		unsigned long _name;
	};
}

namespace test_case_declaration_2
{
	class MyConvertion
	{
	public:
		template<typename T>
		inline operator T*();

		inline operator int();
		inline operator()()
		{
		}
		operator[](int i);
		void* operator*()
		{
			return 0;
		}
		const MyConvertion& operator=(int i)
		{
		}
	};
	inline MyConvertion::operator int()
	{
		return 0;
	}
	inline bool operator==(MyConvertion& a1, MyConvertion& a2)
	{
		return false;
	}
	
}
*/

namespace test_case_basic_statement
{
	template<class _Alloc>
	class myTest
	{
	public:
		_Alloc* getAlloc()
		{
			return alloc;
		}
		static void Sleep(int seconds)
		{
		}
		
		_Alloc* alloc;
	};

	int stricmp(register const char *s1, register const char *s2)
	{
		while (*s1 == *s2++)
		{
			if (*s1++ == 0)
				return (0);
			else
				continue;
		}
		return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
	}

	int main(int argc, char** argv)
	{
/*		int nResult = 0;
		int nInput = 3;
		nResult = 10 + (nInput++ - nResult++);

		++nResult;
		nInput++;
		data aData(0, 1);
		bool bEmpty = false;

		bEmpty = aData.doFoo("sd");

		int myarray[10][5];
		myarray[0][3] = 0;

		stricmp("myname", "myage");

		myTest<data>* pTest;
		pTest->getAlloc()->doFoo("baby");
		myTest<data>::Sleep(0);

*/		data* pData;
//		const data* pRaw = dynamic_cast<const data*>(pData);

		typedef data *LPDATA;

//		typeid(pTest->getAlloc()).name();
//		typeid(pData).name();

//		pRaw = LPDATA(pData);
		LPDATA((void*)pData)->doFoo("wife");
		data("myname", 0).doFoo("myname");

		return (int)(char)('a' + 'b');
	}
}

//-class ctor initialize, base class, template
//-class function with scope.
//-class static declaration.
//-namespace
//-function parameter initialize, Function Pointer, typedef,...
//-friend,extern,enum, union
//-class member function pointer, operator reload, operator convertor
//Statements: assign, if then, do while, for, return, continue, break,
//Expression: condition expression, arithmetic expression, ++/--/+=/-=/...
//go to, label
//throw, catch
//cout <<, 
//Replace import node with special classes.
//XML exports

/*
namespace test_case_typeid_2
{
#include <iostream>
	using namespace std;
	int main( void )
	{
		// sample 1
		cout << typeid(1.1f).name() << endl;
		// sample 2
		class Base1
		{
		};
		class Derive1 : public Base1
		{
		};
		Derive1 d1;
		Base1& b1 = d1;
		cout << typeid(b1).name() << endl; // ���"class Base1",��ΪDerive1��Base1֮��û�ж�̬��
		// sample 3, ����ʱ��Ҫ�Ӳ��� /GR
		class Base2
		{
			virtual void fun( void ) {}
		};
		class Derive2 : public Base2
		{
		};
		Derive2 d2;
		Base2& b2 = d2;
		cout << typeid(b2).name() << endl; // ���"class Derive2",��ΪDerive1��Base1֮�����˶�̬��
		// sample 4
		class Derive22 : public Base2
		{
		};
		// ָ��ǿ��ת��ʧ�ܺ���ԱȽ�ָ���Ƿ�Ϊ�㣬������ȴû�취������������ת��ʧ�ܺ��׳��쳣
		Derive2* pb1 = dynamic_cast<Derive2*>(&b2);
		cout << boolalpha << (0!=pb1) << endl; // ���"true",��Ϊb2�����ȷʵ��Derive2
		Derive22* pb2 = dynamic_cast<Derive22*>(&b2);
		cout << boolalpha << (0!=pb2) << endl; // ���"true",��Ϊb2������Derive2

		try {
			Derive2& rb1 = dynamic_cast<Derive2&>(b2);
			cout << "true" << endl;
		} catch( bad_cast )
		{
			cout << "false" << endl;
		}
		try {
			Derive22& rb2 = dynamic_cast<Derive22&>(b2);
			cout << "true" << endl;
		} catch( ... ) // Ӧ���� bad_cast,����֪��Ϊʲô��VC++6.0��ȴ����
		{
			cout << "false" << endl;
		}

		return 0;
	}
}
*/
}
