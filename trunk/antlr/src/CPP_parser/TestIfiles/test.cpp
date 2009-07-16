//#line 0 "test.cpp"
#pragma warning(disable:4430)
namespace test_case
{

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
int& rm = n;

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
public:
	void MyFunc();

	class data_1
	{
	public:
		void MyFunc_1();
	}m_data1;
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
			char (*pDim2)[6];
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

int setValue3(int v, int i)
{
	MyTemplate<MyTemplate<char,char>,char> q(0);
	char* p;
	int nSize = (1 + (2-4)*3);
	p = pData;
	return 0;
}

extern int g_count;

namespace test_case_function_typedef
{
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
		int nResult = 0;
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

		myTest<data>* pTest = new myTest<data>();
		pTest->getAlloc()->m_data1.MyFunc_1();
		myTest<data>::Sleep(0);

		data* pData = 0;
		const data* pRaw = dynamic_cast<const data*>(pData);

		typedef myTest<data> *LPDATA;

//		typeid(pTest->getAlloc()).name();
//		typeid(pData).name();

		pTest = LPDATA(pData);
		LPDATA((void*)pData)->getAlloc()->doFoo("wife");
		data("myname", 0).doFoo("myname");

		myTest<data>* pNew = new myTest<data>();
		unsigned char* pStrings = (unsigned char*)new char[100]; 

		data **pDataArray = new data*[10];
		char (*pDim2)[10] = new char[5][10];
		char *str[] = {"China","Japan","English","America","Australia","Canada"}; 
		int aDim2[2][3] = {{1,2, 3}, {2,3, 4}};

		(pTest = new myTest<data>())->Sleep(0);

		delete pTest;
		delete [] pDim2;

		return (int)(char)('a' + 'b');
	}
}


namespace test_case_control_1
{
	void Loop();
	void Control(int in) throw(char*)
	{
		int i = 0;
		if(in == 0)
		{
			i+=1;
			throw "Crash";
		}
		else if(in == 1)
			i+=3;
		else
			i-=1;

		switch(in)
		{
			char ch;
		case 1:
			i+=1;
			break;
		case 2:
			{
				char* ch2 = new char[10];
			}
			break;
		default:
			i*=1;
			break;
		}

		__try
		{
			Loop();
		}
		__except(i=1,0) 
		{
			i = 0;
		}
	}

	void Loop()
	{
		for(int i = 0; i < 10; i++);
		int j = 0;
		for(j = 0; j < 10; j++)
		{
			if(j==3)
				break;
		}
		for(;;);

		while(1)
			if(j++ == 5) break;

		while(j < 5)
		{
			if(j == 0)
				continue;
			j++;
		}

		do 
		{
			if(j++ == 5) goto End;
		}while (4 == j && !(j == 3 || j== 0));
		int* pInt = &j;

		try
		{
			Control(8);
		}
		catch(char* ch1)
		{
			ch1[0];
		}
		catch(...)
		{
			j--;
		}

End:
		j = j << 3;
		j = j & 0x100;
	}
}


namespace test_case_try_exception
{
	void puts(const char*)
	{
	}
	void main()
	{	
		int* p = 0;
		puts("SEH begin");
		__try
		{
			__try
			{
				puts("in try");
				__try
				{
					puts("in try");
					*p = 0;
				}
				__finally
				{
					puts("in finally");
				}
			}
			__except(puts("in filter"), 0)
			{
				puts("in except");
			}
		}
		__except(puts("in filter"), 1)
		{
			puts("in except");
		}
		puts("SEH end");
	}
}

//-class ctor initialize, base class, template
//-class function with scope.
//-class static declaration.
//-namespace
//-function parameter initialize, Function Pointer, typedef,...
//-friend,extern,enum, union
//-class member function pointer, operator reload, operator convertor
//-Statements: assign, if then, do while, for, return, continue, break,
//-Expression: condition expression, arithmetic expression, ++/--/+=/-=/...
//-go to, label
//-throw, catch, __try, __except
//-cout <<, 
//Replace import node with special classes.
//XML exports

namespace test_case_typeid_2
{
	static const char* endl = "\r\n";
	class ostream
	{
	public:
		ostream& operator<<(const char* s)
		{
			return *this;
		}

		ostream& operator<<(bool b)
		{
			return *this;
		}
	};
	ostream cout;

	using namespace test_case_typeid_2;
	int main( void )
	{
		int y = 1 ? 0 : 10;
		// sample 1
//		cout << typeid(1.1f).name() << endl;
		// sample 2
		class Base1
		{
		};
		class Derive1 : public Base1
		{
		};
		Derive1 d1;
		Base1& b1 = d1;
//		cout << typeid(b1).name() << endl; // 输出"class Base1",因为Derive1和Base1之间没有多态性
		// sample 3, 编译时需要加参数 /GR
		class Base2
		{
			virtual void fun( void ) {}
		};
		class Derive2 : public Base2
		{
		};
		Derive2 d2;
		Base2& b2 = d2;
//		cout << typeid(b2).name() << endl; // 输出"class Derive2",因为Derive1和Base1之间有了多态性
		// sample 4
		class Derive22 : public Base2
		{
		};
		// 指针强制转化失败后可以比较指针是否为零，而引用却没办法，所以引用制转化失败后抛出异常
		Derive2* pb1 = dynamic_cast<Derive2*>(&b2);
		cout << (0!=pb1) << endl; // 输出"true",因为b2本身就确实是Derive2
		Derive22* pb2 = dynamic_cast<Derive22*>(&b2);
		cout << (0!=pb2) << endl; // 输出"true",因为b2本身不是Derive2

		try {
			Derive2& rb1 = dynamic_cast<Derive2&>(b2);
			cout << "true" << endl;
		} catch( ... )
		{
			cout << "false" << endl;
		}
		try {
			Derive22& rb2 = dynamic_cast<Derive22&>(b2);
			cout << "true" << endl;
		} catch( ... ) // 应该是 bad_cast,但不知道为什么在VC++6.0中却不行
		{
			cout << "false" << endl;
		}

		return 0;
	}
}

}
