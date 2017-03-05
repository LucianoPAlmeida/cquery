enum A {};
enum B {};

template<typename T>
struct Foo {
  struct Inner {};
};

Foo<A>::Inner a;
Foo<B> b;


#if false
// We could store how many template parameters Foo has and then skip that many TypeRefs...,
// if there was still a TypeRef after (and we are not ignoring it) then we know
// that is the variable type.

EnumDecl A
EnumDecl B
ClassTemplate Foo
  TemplateTypeParameter T
  StructDecl Inner
VarDecl a
  TemplateRef Foo
  TypeRef enum A
  TypeRef struct Foo<enum A>::Inner
  CallExpr Inner
VarDecl b
  TemplateRef Foo
  TypeRef enum B
  CallExpr Foo
#endif


/*
OUTPUT:
{
  "types": [{
      "id": 0,
      "usr": "c:@E@A",
      "short_name": "A",
      "qualified_name": "A",
      "definition": "1:1:6",
      "uses": ["*1:1:6", "*1:9:5"]
    }, {
      "id": 1,
      "usr": "c:@E@B",
      "short_name": "B",
      "qualified_name": "B",
      "definition": "1:2:6",
      "uses": ["*1:2:6", "*1:10:5"]
    }, {
      "id": 2,
      "usr": "c:@ST>1#T@Foo",
      "short_name": "Foo",
      "qualified_name": "Foo",
      "definition": "1:5:8",
      "uses": ["*1:5:8", "*1:9:1", "*1:10:1"]
    }, {
      "id": 3,
      "usr": "c:@ST>1#T@Foo@S@Inner",
      "short_name": "Inner",
      "qualified_name": "Foo::Inner",
      "definition": "1:6:10",
      "uses": ["*1:6:10", "*1:9:9"]
    }],
  "functions": [],
  "variables": [{
      "id": 0,
      "usr": "c:@a",
      "short_name": "a",
      "qualified_name": "a",
      "definition": "1:9:15",
      "variable_type": 3,
      "uses": ["1:9:15"]
    }, {
      "id": 1,
      "usr": "c:@b",
      "short_name": "b",
      "qualified_name": "b",
      "definition": "1:10:8",
      "variable_type": 2,
      "uses": ["1:10:8"]
    }]
}

*/









#if false
namespace ns {
  enum VarType {};

  template<typename _>
  struct Holder {
    static constexpr VarType static_var = (VarType)0x0;
  };

  template<typename _>
  const typename VarType Holder<_>::static_var;


  int Foo = Holder<int>::static_var;
  int Foo2 = Holder<int>::static_var;
}
#endif

// TODO: we are not marking interesting usage for a CStyleCastExpr
// TODO: we are resoling templates in a weird way (should be 1 type)
#if false
Namespace ns
  EnumDecl VarType
  ClassTemplate Holder
    TemplateTypeParameter _
    VarDecl static_var
      TypeRef enum ns::VarType
      CStyleCastExpr
        TypeRef enum ns::VarType
        IntegerLiteral
  VarDecl static_var
    TemplateTypeParameter _
    TypeRef enum ns::VarType
    TemplateRef Holder
    TypeRef _
  VarDecl Foo
    UnexposedExpr static_var
      UnexposedExpr static_var
        DeclRefExpr static_var
          TemplateRef Holder
  VarDecl static_var
    TypeRef enum ns::VarType
    TemplateRef Holder
#endif


/*
OUTPUT:
{
  "types": [{
      "id": 0,
      "usr": "c:@N@ns@E@VarType",
      "short_name": "VarType",
      "qualified_name": "ns::VarType",
      "definition": "1:2:8",
      "uses": ["*1:2:8", "*1:6:22", "1:6:44", "*1:10:18"]
    }, {
      "id": 1,
      "usr": "c:@N@ns@ST>1#T@Holder",
      "short_name": "Holder",
      "qualified_name": "ns::Holder",
      "definition": "1:5:10",
      "vars": [0],
      "uses": ["*1:5:10", "*1:10:26", "1:13:13", "1:14:14"]
    }],
  "functions": [],
  "variables": [{
      "id": 0,
      "usr": "c:@N@ns@ST>1#T@Holder@static_var",
      "short_name": "static_var",
      "qualified_name": "ns::Holder::static_var",
      "declaration": "1:6:30",
      "definition": "1:10:37",
      "variable_type": 0,
      "declaring_type": 1,
      "uses": ["1:6:30", "1:10:37"]
    }, {
      "id": 1,
      "usr": "c:@N@ns@Foo",
      "short_name": "Foo",
      "qualified_name": "ns::Foo",
      "definition": "1:13:7",
      "uses": ["1:13:7"]
    }, {
      "id": 2,
      "usr": "c:@N@ns@S@Holder>#I@static_var",
      "short_name": "static_var",
      "qualified_name": "static_var",
      "definition": "1:10:37",
      "variable_type": 0,
      "declaring_type": 2,
      "uses": ["1:13:26", "1:10:37", "1:14:27"]
    }, {
      "id": 3,
      "usr": "c:@N@ns@Foo2",
      "short_name": "Foo2",
      "qualified_name": "ns::Foo2",
      "definition": "1:14:7",
      "uses": ["1:14:7"]
    }]
}
*/

























//#include <string>
//#include <xiosbase>

//#include <sstream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <cstddef>
//#include <sstream>
//#include <iomanip>
//#include <limits>
//#include <vector>
//#include <cstddef>
//#include <tuple>
//#include <type_traits>
//#include <string>
//#include <string>
//#include <type_traits>
//#include <iterator>
//#include <vector>
//#include <string>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//#include <string>
//#include <cstddef>
//#include <cmath>
//#include <limits>
//#include <type_traits>
//#include <set>
//#include <string>
//#include <vector>
//#include <iosfwd>
//#include <streambuf>
//#include <ostream>
//#include <fstream>
//#include <memory>
//#include <vector>
//#include <string>
//#include <stdexcept>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>