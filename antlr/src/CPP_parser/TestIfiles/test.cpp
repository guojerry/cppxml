#line 0 "test.h"

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

namespace test_case_template_1
{

	template<typename T>
	class Another
	{
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
*/
//-class ctor initialize, base class, template
//class function with scope.
//class static declaration.
//Function Pointer, enum, union, typedef, 
//Statements: assign, if then, do while, for, return, continue, break,
//Expression: condition expression, arithmetic expression, ++/--/+=/-=/...
//go to, label
//throw, catch
//namespace
//cout <<, operator reload
//function parameter initialize, ...
//Replace import node with special classes.
//XML exports
}
