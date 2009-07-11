//#line 0 "test.cpp"
#pragma warning(disable:4430)
namespace test_case
{
/*

char s3[256] = {0};
char s4[2][120];

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

class data
{
public:
	data(const char*, int) {}
	~data() {}

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

*/
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
*/
/*
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
	bool (isdigit)();
	
	int first, getname(int id);
	int (digits)[1][1];

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
*/

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

//-class ctor initialize, base class, template
//-class function with scope.
//-class static declaration.
//-namespace
//-function parameter initialize, Function Pointer, typedef,...
//-friend,extern,enum, union
//class member function 
//Statements: assign, if then, do while, for, return, continue, break,
//Expression: condition expression, arithmetic expression, ++/--/+=/-=/...
//go to, label
//throw, catch
//cout <<, operator reload
//Replace import node with special classes.
//XML exports
}
