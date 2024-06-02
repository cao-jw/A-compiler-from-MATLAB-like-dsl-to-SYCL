// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "parser.y"

#include<iostream>
#include<string>
#include "Scanner1.hpp"
#include "ast.hpp"
#include <vector>
#include <map>
NBlock* startnode;

std::map<NBlock, NIdentifier> symbol; 

#line 53 "Parser1.cpp"


#include "Parser1.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 23 "parser.y"
namespace par {
#line 132 "Parser1.cpp"

  /// Build a parser object.
  Parser::Parser (yyscan_t scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.copy< NArrayIndex* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.copy< NArrayType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.copy< NAssignment* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.copy< NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.copy< NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.copy< NForStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.copy< NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.copy< NIfStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.copy< NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comparison: // comparison
        value.copy< SYMBOL_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.copy< VALUE_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< std::vector<NStatement*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.move< NArrayIndex* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.move< NArrayType* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assign: // assign
        value.move< NAssignment* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.move< NBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.move< NExpression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.move< NForStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< NIdentifier* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.move< NIfStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< NStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< NVariableDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.move< NWhileStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_comparison: // comparison
        value.move< SYMBOL_TYPE > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.move< VALUE_TYPE > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<NStatement*> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.YY_MOVE_OR_COPY< NArrayIndex* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.YY_MOVE_OR_COPY< NArrayType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.YY_MOVE_OR_COPY< NAssignment* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.YY_MOVE_OR_COPY< NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.YY_MOVE_OR_COPY< NForStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.YY_MOVE_OR_COPY< NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.YY_MOVE_OR_COPY< NIfStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.YY_MOVE_OR_COPY< NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.YY_MOVE_OR_COPY< NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comparison: // comparison
        value.YY_MOVE_OR_COPY< SYMBOL_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.YY_MOVE_OR_COPY< VALUE_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< std::vector<NStatement*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.move< NArrayIndex* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.move< NArrayType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.move< NAssignment* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.move< NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.move< NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.move< NForStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.move< NIfStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.move< NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comparison: // comparison
        value.move< SYMBOL_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.move< VALUE_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<NStatement*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.copy< NArrayIndex* > (that.value);
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.copy< NArrayType* > (that.value);
        break;

      case symbol_kind::S_assign: // assign
        value.copy< NAssignment* > (that.value);
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.copy< NBlock* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.copy< NExpression* > (that.value);
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.copy< NForStatement* > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.copy< NIdentifier* > (that.value);
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.copy< NIfStatement* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< NStatement* > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< NVariableDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.copy< NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_comparison: // comparison
        value.copy< SYMBOL_TYPE > (that.value);
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.copy< VALUE_TYPE > (that.value);
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< std::vector<NStatement*> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.move< NArrayIndex* > (that.value);
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.move< NArrayType* > (that.value);
        break;

      case symbol_kind::S_assign: // assign
        value.move< NAssignment* > (that.value);
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.move< NBlock* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.move< NExpression* > (that.value);
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.move< NForStatement* > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.move< NIdentifier* > (that.value);
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.move< NIfStatement* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< NStatement* > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< NVariableDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.move< NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_comparison: // comparison
        value.move< SYMBOL_TYPE > (that.value);
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.move< VALUE_TYPE > (that.value);
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.move< double > (that.value);
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<NStatement*> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        yylhs.value.emplace< NArrayIndex* > ();
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        yylhs.value.emplace< NArrayType* > ();
        break;

      case symbol_kind::S_assign: // assign
        yylhs.value.emplace< NAssignment* > ();
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        yylhs.value.emplace< NBlock* > ();
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< NExpression* > ();
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        yylhs.value.emplace< NForStatement* > ();
        break;

      case symbol_kind::S_ident: // ident
        yylhs.value.emplace< NIdentifier* > ();
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        yylhs.value.emplace< NIfStatement* > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< NStatement* > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        yylhs.value.emplace< NVariableDeclaration* > ();
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        yylhs.value.emplace< NWhileStatement* > ();
        break;

      case symbol_kind::S_comparison: // comparison
        yylhs.value.emplace< SYMBOL_TYPE > ();
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        yylhs.value.emplace< VALUE_TYPE > ();
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< std::vector<NStatement*> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // prog: block
#line 75 "parser.y"
                  {yylhs.value.as < NBlock* > () = yystack_[0].value.as < NBlock* > (); startnode = yystack_[0].value.as < NBlock* > ();}
#line 1118 "Parser1.cpp"
    break;

  case 3: // stmts: stmt
#line 78 "parser.y"
                 {std::vector<NStatement*> sts = {}; sts.push_back(yystack_[0].value.as < NStatement* > ());yylhs.value.as < std::vector<NStatement*> > () = sts;}
#line 1124 "Parser1.cpp"
    break;

  case 4: // stmts: stmts stmt
#line 79 "parser.y"
                       {std::vector<NStatement*> sts = yystack_[1].value.as < std::vector<NStatement*> > (); sts.push_back(yystack_[0].value.as < NStatement* > ()); yylhs.value.as < std::vector<NStatement*> > () = sts;}
#line 1130 "Parser1.cpp"
    break;

  case 5: // stmt: var_decl
#line 82 "parser.y"
                     {yylhs.value.as < NStatement* > () = yystack_[0].value.as < NVariableDeclaration* > ();yylhs.value.as < NStatement* > ()->nodetype = yystack_[0].value.as < NVariableDeclaration* > ()->nodetype;}
#line 1136 "Parser1.cpp"
    break;

  case 6: // stmt: expr
#line 83 "parser.y"
                 {yylhs.value.as < NStatement* > () = new NExpressionStatement(yystack_[0].value.as < NExpression* > ());yylhs.value.as < NStatement* > ()->nodetype = yystack_[0].value.as < NExpression* > ()->nodetype;}
#line 1142 "Parser1.cpp"
    break;

  case 7: // stmt: if_stmt
#line 84 "parser.y"
                   {yylhs.value.as < NStatement* > () = yystack_[0].value.as < NIfStatement* > ();yylhs.value.as < NStatement* > ()->nodetype = yystack_[0].value.as < NIfStatement* > ()->nodetype;}
#line 1148 "Parser1.cpp"
    break;

  case 8: // stmt: for_stmt
#line 85 "parser.y"
                    {yylhs.value.as < NStatement* > () = yystack_[0].value.as < NForStatement* > ();yylhs.value.as < NStatement* > ()->nodetype = yystack_[0].value.as < NForStatement* > ()->nodetype;}
#line 1154 "Parser1.cpp"
    break;

  case 9: // stmt: while_stmt
#line 86 "parser.y"
                      {yylhs.value.as < NStatement* > () = yystack_[0].value.as < NWhileStatement* > ();yylhs.value.as < NStatement* > ()->nodetype = yystack_[0].value.as < NWhileStatement* > ()->nodetype;}
#line 1160 "Parser1.cpp"
    break;

  case 10: // block: TLBRACE stmts TRBRACE
#line 89 "parser.y"
                                   {yylhs.value.as < NBlock* > () = new NBlock(yystack_[1].value.as < std::vector<NStatement*> > ());}
#line 1166 "Parser1.cpp"
    break;

  case 11: // primary_typename: TYLL
#line 92 "parser.y"
                             {yylhs.value.as < VALUE_TYPE > () = VALUE_TYPE::LL_TYPE;}
#line 1172 "Parser1.cpp"
    break;

  case 12: // primary_typename: TYDOUBLE
#line 93 "parser.y"
                                                     {yylhs.value.as < VALUE_TYPE > () = VALUE_TYPE::DOUBLE_TYPE;}
#line 1178 "Parser1.cpp"
    break;

  case 13: // primary_typename: TYBOOL
#line 94 "parser.y"
                                                   {yylhs.value.as < VALUE_TYPE > () = VALUE_TYPE::BOOL_TYPE;}
#line 1184 "Parser1.cpp"
    break;

  case 14: // array_type: primary_typename TLBRACKET TINTEGER TRBRACKET
#line 97 "parser.y"
                                                                      {std::vector<int> vec = {};vec.push_back(yystack_[1].value.as < long long > ());yylhs.value.as < NArrayType* > () = new NArrayType(yystack_[3].value.as < VALUE_TYPE > (), vec, 1);}
#line 1190 "Parser1.cpp"
    break;

  case 15: // array_type: array_type TLBRACKET TINTEGER TRBRACKET
#line 98 "parser.y"
                                                                {yystack_[3].value.as < NArrayType* > ()->arraydim ++; yystack_[3].value.as < NArrayType* > ()->arraysize.push_back(yystack_[1].value.as < long long > ()); yylhs.value.as < NArrayType* > () = yystack_[3].value.as < NArrayType* > ();}
#line 1196 "Parser1.cpp"
    break;

  case 16: // var_decl: primary_typename ident
#line 100 "parser.y"
                                     {yylhs.value.as < NVariableDeclaration* > () = new NVariableDeclaration(yystack_[1].value.as < VALUE_TYPE > (), yystack_[0].value.as < NIdentifier* > ());}
#line 1202 "Parser1.cpp"
    break;

  case 17: // var_decl: array_type ident
#line 101 "parser.y"
                                           {yylhs.value.as < NVariableDeclaration* > () = new NVariableDeclaration(yystack_[1].value.as < NArrayType* > ()->vt, yystack_[0].value.as < NIdentifier* > ()); yystack_[0].value.as < NIdentifier* > ()->isArray = true;yystack_[0].value.as < NIdentifier* > ()->arraysize = yystack_[1].value.as < NArrayType* > ()->arraysize; yystack_[0].value.as < NIdentifier* > ()->array_dim = yystack_[1].value.as < NArrayType* > ()->arraydim;}
#line 1208 "Parser1.cpp"
    break;

  case 18: // ident: TIDENTIFIER
#line 104 "parser.y"
                        {yylhs.value.as < NIdentifier* > () = new NIdentifier(yystack_[0].value.as < std::string > ());}
#line 1214 "Parser1.cpp"
    break;

  case 19: // numeric: TINTEGER
#line 107 "parser.y"
                     {yylhs.value.as < NExpression* > () = new NInteger(yystack_[0].value.as < long long > ()); yylhs.value.as < NExpression* > ()->nodetype = NInteger_TYPE;}
#line 1220 "Parser1.cpp"
    break;

  case 20: // numeric: TDOUBLE
#line 108 "parser.y"
                            {yylhs.value.as < NExpression* > () = new NDouble(yystack_[0].value.as < double > ()); yylhs.value.as < NExpression* > ()->nodetype = NDouble_TYPE;}
#line 1226 "Parser1.cpp"
    break;

  case 21: // expr: ident
#line 111 "parser.y"
                    {yylhs.value.as < NExpression* > () = yystack_[0].value.as < NIdentifier* > ();yylhs.value.as < NExpression* > ()->nodetype = yystack_[0].value.as < NIdentifier* > ()->nodetype;}
#line 1232 "Parser1.cpp"
    break;

  case 22: // expr: numeric
#line 112 "parser.y"
                    {yylhs.value.as < NExpression* > () = yystack_[0].value.as < NExpression* > ();yylhs.value.as < NExpression* > ()->nodetype = yystack_[0].value.as < NExpression* > ()->nodetype; }
#line 1238 "Parser1.cpp"
    break;

  case 23: // expr: expr comparison expr
#line 113 "parser.y"
                                         {yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[2].value.as < NExpression* > (), yystack_[1].value.as < SYMBOL_TYPE > (), yystack_[0].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1244 "Parser1.cpp"
    break;

  case 24: // expr: expr TMOD expr
#line 114 "parser.y"
                                   {yylhs.value.as < NExpression* > () =  new NBinaryOperator(yystack_[2].value.as < NExpression* > (), SYMBOL_TYPE::TMOD_TYPE, yystack_[0].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1250 "Parser1.cpp"
    break;

  case 25: // expr: expr size_expr TMUL expr size_expr
#line 115 "parser.y"
                                                      {yystack_[4].value.as < NExpression* > ()->nat = yystack_[3].value.as < NArrayType* > ();yystack_[1].value.as < NExpression* > ()->nat = yystack_[0].value.as < NArrayType* > ();yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[4].value.as < NExpression* > (), SYMBOL_TYPE::TMUL_TYPE, yystack_[1].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1256 "Parser1.cpp"
    break;

  case 26: // expr: expr TDIV expr
#line 116 "parser.y"
                                   {yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[2].value.as < NExpression* > (), SYMBOL_TYPE::TDIV_TYPE, yystack_[0].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1262 "Parser1.cpp"
    break;

  case 27: // expr: expr size_expr TPLUS expr size_expr
#line 117 "parser.y"
                                                        {yystack_[4].value.as < NExpression* > ()->nat = yystack_[3].value.as < NArrayType* > ();yystack_[1].value.as < NExpression* > ()->nat = yystack_[0].value.as < NArrayType* > ();yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[4].value.as < NExpression* > (), SYMBOL_TYPE::TPLUS_TYPE, yystack_[1].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1268 "Parser1.cpp"
    break;

  case 28: // expr: expr size_expr TMINUS expr size_expr
#line 118 "parser.y"
                                                         {yystack_[4].value.as < NExpression* > ()->nat = yystack_[3].value.as < NArrayType* > ();yystack_[1].value.as < NExpression* > ()->nat = yystack_[0].value.as < NArrayType* > ();yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[4].value.as < NExpression* > (), SYMBOL_TYPE::TMINUS_TYPE, yystack_[1].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1274 "Parser1.cpp"
    break;

  case 29: // expr: TLPAREN expr TRPAREN
#line 119 "parser.y"
                                         {yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[1].value.as < NExpression* > (),SYMBOL_TYPE::TPAREN_TYPE); yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1280 "Parser1.cpp"
    break;

  case 30: // expr: TMINUS expr
#line 120 "parser.y"
                                            {yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[0].value.as < NExpression* > (),SYMBOL_TYPE::TUMINUS_TYPE); yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1286 "Parser1.cpp"
    break;

  case 31: // expr: full_index
#line 121 "parser.y"
                               {yylhs.value.as < NExpression* > () = yystack_[0].value.as < NArrayIndex* > (); yylhs.value.as < NExpression* > ()->nodetype = yystack_[0].value.as < NArrayIndex* > ()->nodetype;}
#line 1292 "Parser1.cpp"
    break;

  case 32: // expr: expr size_expr MTMUL numeric
#line 122 "parser.y"
                                         { yystack_[3].value.as < NExpression* > ()->nat = yystack_[2].value.as < NArrayType* > (); yylhs.value.as < NExpression* > () = new NBinaryOperator(yystack_[3].value.as < NExpression* > (), SYMBOL_TYPE::MTMUL_TYPE, yystack_[0].value.as < NExpression* > ());yylhs.value.as < NExpression* > ()->nodetype = NODE_TYPE::NBinaryOperator_TYPE;}
#line 1298 "Parser1.cpp"
    break;

  case 33: // expr: assign
#line 123 "parser.y"
                   {yylhs.value.as < NExpression* > () = yystack_[0].value.as < NAssignment* > ();yylhs.value.as < NExpression* > ()->nodetype = yystack_[0].value.as < NAssignment* > ()->nodetype;}
#line 1304 "Parser1.cpp"
    break;

  case 34: // expr: full_index TEQUAL expr
#line 124 "parser.y"
                                   {yylhs.value.as < NExpression* > () = new NArrayAssignment(yystack_[2].value.as < NArrayIndex* > (), yystack_[0].value.as < NExpression* > ()); yylhs.value.as < NExpression* > ()->nodetype = NArrayAssignment_TYPE;}
#line 1310 "Parser1.cpp"
    break;

  case 35: // assign: ident TEQUAL expr
#line 127 "parser.y"
                              {yylhs.value.as < NAssignment* > () = new NAssignment(yystack_[2].value.as < NIdentifier* > (), yystack_[0].value.as < NExpression* > ());}
#line 1316 "Parser1.cpp"
    break;

  case 36: // array_index: ident TLBRACKET expr TRBRACKET
#line 130 "parser.y"
                                              {std::vector<NExpression*> exp = {};exp.push_back(yystack_[1].value.as < NExpression* > ()); yylhs.value.as < NArrayIndex* > () = new NArrayIndex(yystack_[3].value.as < NIdentifier* > (), exp);yylhs.value.as < NArrayIndex* > ()->expressions.back()->nodetype = yystack_[1].value.as < NExpression* > ()->nodetype;}
#line 1322 "Parser1.cpp"
    break;

  case 37: // array_index: array_index TLBRACKET expr TRBRACKET
#line 131 "parser.y"
                                                                 {yystack_[3].value.as < NArrayIndex* > ()->expressions.push_back(yystack_[1].value.as < NExpression* > ()); yylhs.value.as < NArrayIndex* > () = yystack_[3].value.as < NArrayIndex* > ();yylhs.value.as < NArrayIndex* > ()->expressions.back()->nodetype = yystack_[1].value.as < NExpression* > ()->nodetype;}
#line 1328 "Parser1.cpp"
    break;

  case 38: // full_index: array_index size_expr
#line 134 "parser.y"
                                      {yylhs.value.as < NArrayIndex* > () = new NArrayIndex(yystack_[1].value.as < NArrayIndex* > ()->arrayName, yystack_[1].value.as < NArrayIndex* > ()->expressions, yystack_[0].value.as < NArrayType* > ());}
#line 1334 "Parser1.cpp"
    break;

  case 39: // comparison: TCEQ
#line 138 "parser.y"
         { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCEQ_TYPE; }
#line 1340 "Parser1.cpp"
    break;

  case 40: // comparison: TCNE
#line 139 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCNE_TYPE; }
#line 1346 "Parser1.cpp"
    break;

  case 41: // comparison: TCLT
#line 140 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCLT_TYPE; }
#line 1352 "Parser1.cpp"
    break;

  case 42: // comparison: TCLE
#line 141 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCLE_TYPE; }
#line 1358 "Parser1.cpp"
    break;

  case 43: // comparison: TCGT
#line 142 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCGT_TYPE; }
#line 1364 "Parser1.cpp"
    break;

  case 44: // comparison: TCGE
#line 143 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TCGE_TYPE; }
#line 1370 "Parser1.cpp"
    break;

  case 45: // comparison: TAND
#line 144 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TAND_TYPE; }
#line 1376 "Parser1.cpp"
    break;

  case 46: // comparison: TOR
#line 145 "parser.y"
          { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TOR_TYPE; }
#line 1382 "Parser1.cpp"
    break;

  case 47: // comparison: TXOR
#line 146 "parser.y"
           { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TXOR_TYPE; }
#line 1388 "Parser1.cpp"
    break;

  case 48: // comparison: TSHIFTL
#line 147 "parser.y"
              { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TSHIFTL_TYPE; }
#line 1394 "Parser1.cpp"
    break;

  case 49: // comparison: TSHIFTR
#line 148 "parser.y"
              { yylhs.value.as < SYMBOL_TYPE > () = SYMBOL_TYPE::TSHIFTR_TYPE; }
#line 1400 "Parser1.cpp"
    break;

  case 50: // if_stmt: TIF expr block
#line 150 "parser.y"
                            {yylhs.value.as < NIfStatement* > () = new NIfStatement(yystack_[1].value.as < NExpression* > (), yystack_[0].value.as < NBlock* > ());}
#line 1406 "Parser1.cpp"
    break;

  case 51: // if_stmt: TIF expr block TELSE block
#line 151 "parser.y"
                                       {yylhs.value.as < NIfStatement* > () = new NIfStatement(yystack_[3].value.as < NExpression* > (), yystack_[2].value.as < NBlock* > (), yystack_[0].value.as < NBlock* > ());}
#line 1412 "Parser1.cpp"
    break;

  case 52: // if_stmt: TIF expr block TELSE if_stmt
#line 152 "parser.y"
                                         {yylhs.value.as < NIfStatement* > () = new NIfStatement(yystack_[3].value.as < NExpression* > (), yystack_[2].value.as < NBlock* > ());}
#line 1418 "Parser1.cpp"
    break;

  case 53: // for_condition: TFOR TLPAREN ident TEQUAL TINTEGER TCOLON TINTEGER TCOLON TINTEGER TRPAREN
#line 155 "parser.y"
                                                                                          {std::vector<int> ini = {yystack_[5].value.as < long long > ()};std::vector<int> end = {yystack_[1].value.as < long long > ()}; std::vector<int> incre = {yystack_[3].value.as < long long > ()}; std::vector<NIdentifier*> var= {yystack_[7].value.as < NIdentifier* > ()}; yylhs.value.as < NForStatement* > () = new NForStatement(ini, end, incre, var,nullptr);}
#line 1424 "Parser1.cpp"
    break;

  case 54: // for_condition: for_condition TFOR TLPAREN ident TEQUAL TINTEGER TCOLON TINTEGER TCOLON TINTEGER TRPAREN
#line 156 "parser.y"
                                                                                                        {yystack_[10].value.as < NForStatement* > ()->initial.push_back(yystack_[5].value.as < long long > ()); yystack_[10].value.as < NForStatement* > ()->end.push_back(yystack_[1].value.as < long long > ()); yystack_[10].value.as < NForStatement* > ()->increment.push_back(yystack_[3].value.as < long long > ()); yystack_[10].value.as < NForStatement* > ()->forvar.push_back(yystack_[7].value.as < NIdentifier* > ()); yylhs.value.as < NForStatement* > () = yystack_[10].value.as < NForStatement* > ();}
#line 1430 "Parser1.cpp"
    break;

  case 55: // for_stmt: for_condition block
#line 158 "parser.y"
                                    {yystack_[1].value.as < NForStatement* > ()->block = yystack_[0].value.as < NBlock* > ();yylhs.value.as < NForStatement* > () = yystack_[1].value.as < NForStatement* > ();std::cout<<"new for_stmt "<<yylhs.value.as < NForStatement* > ()->block->statements.size()<<std::endl;}
#line 1436 "Parser1.cpp"
    break;

  case 56: // while_stmt: TWHILE TLPAREN expr TRPAREN block
#line 161 "parser.y"
                                                  {yylhs.value.as < NWhileStatement* > () = new NWhileStatement(yystack_[0].value.as < NBlock* > (), yystack_[2].value.as < NExpression* > ());  }
#line 1442 "Parser1.cpp"
    break;

  case 57: // size_expr: TSHIFTL TINTEGER TSHIFTR
#line 164 "parser.y"
                                         {std::vector<int> vec = {};vec.push_back(yystack_[1].value.as < long long > ());yylhs.value.as < NArrayType* > () = new NArrayType(VALUE_TYPE::LL_TYPE, vec, 1);}
#line 1448 "Parser1.cpp"
    break;

  case 58: // size_expr: size_expr TSHIFTL TINTEGER TSHIFTR
#line 165 "parser.y"
                                                   {yystack_[3].value.as < NArrayType* > ()->arraydim ++; yystack_[3].value.as < NArrayType* > ()->arraysize.push_back(yystack_[1].value.as < long long > ()); yylhs.value.as < NArrayType* > () = yystack_[3].value.as < NArrayType* > ();}
#line 1454 "Parser1.cpp"
    break;

  case 59: // size_expr: %empty
#line 166 "parser.y"
                          {std::vector<int> vec = {};yylhs.value.as < NArrayType* > () = new NArrayType(VALUE_TYPE::LL_TYPE, vec, 0);}
#line 1460 "Parser1.cpp"
    break;


#line 1464 "Parser1.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -24;

  const signed char Parser::yytable_ninf_ = -60;

  const short
  Parser::yypact_[] =
  {
     -12,    73,    22,   -24,   -24,   -24,   -24,    34,    11,    24,
     -24,   -24,   -24,    34,    34,     9,   -24,     0,     6,   -24,
      10,   -24,    80,   -24,   -13,    33,   -24,    20,   -24,   -24,
     -24,   107,    30,    34,   116,   222,   -24,   -24,    51,   -24,
      52,   -24,    34,    34,   -24,   -24,   -24,   -24,   -24,   -24,
      34,   -24,   -24,   -24,    34,   -24,    53,    34,    29,    34,
      53,    23,    34,    46,   -24,    79,    67,   143,   -24,    62,
      63,   222,   156,   222,   222,    50,   195,    34,    34,    34,
      44,    85,   183,   222,    30,    19,    86,   -12,   -24,   -24,
     -24,   -24,   195,   195,   195,   -24,    61,   -24,    88,   -24,
     -24,    74,   -24,    13,    13,    23,   -24,    87,    97,    76,
      77,   102,   103,    82,   106,   104,   -24,   115,   -24
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,    18,    20,    19,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     3,     0,     0,     5,
      21,    22,     6,    33,    59,    31,     7,     0,     8,     9,
       1,    59,     0,     0,    59,    30,    10,     4,     0,    16,
       0,    17,     0,     0,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    49,    48,     0,     0,     0,
       0,    38,     0,     0,    55,    50,     0,    59,    29,     0,
       0,    35,    59,    26,    24,     0,    23,     0,     0,     0,
       0,     0,    59,    34,     0,     0,     0,     0,    14,    15,
      36,    57,    59,    59,    59,    32,     0,    37,     0,    51,
      52,     0,    56,    27,    28,    25,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,    54
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -24,   -24,   -24,   113,   -23,   -24,   -24,   -24,   -16,    58,
      -7,   -24,   -24,   -24,   -24,    54,   -24,   -24,   -24,   -19
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     2,    15,    16,     3,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    57,    26,    27,    28,    29,    58
  };

  const signed char
  Parser::yytable_[] =
  {
      31,    39,    41,     4,    64,    61,    34,    35,    65,     4,
       1,    59,     4,     5,     6,     7,    66,     8,     9,    10,
      11,    12,    30,    42,    38,     7,    67,    60,    63,    13,
      40,    32,    36,     4,    43,    71,    72,     4,     5,     6,
      14,     1,     1,    73,    33,    79,    62,    74,     5,     6,
      76,    80,    82,    81,    13,    83,    69,    70,    75,    77,
      78,    79,    99,    81,   102,    14,    84,    80,    98,    81,
      92,    93,    94,   103,   104,   105,     4,     5,     6,     7,
      86,     8,     9,    10,    11,    12,    85,    88,    89,    91,
      96,   101,   109,    13,    44,    45,    46,    47,    48,    49,
     106,   107,   110,   108,    14,   111,   112,   113,   114,   117,
     -59,   115,   -59,    50,    51,    52,    53,    54,   -59,    55,
      56,    44,    45,    46,    47,    48,    49,   116,    37,     1,
      44,    45,    46,    47,    48,    49,   118,    68,    95,   100,
      50,    51,    52,    53,    54,     0,    55,    56,     0,    50,
      51,    52,    53,    54,     0,    55,    56,    44,    45,    46,
      47,    48,    49,     0,    87,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    90,    55,    56,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,     0,    55,    56,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,    97,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,     0,    55,    56,     0,     0,     0,     0,    50,    51,
      52,    53,    54,     0,    55,    56,    44,    45,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
       0,    55,    56
  };

  const signed char
  Parser::yycheck_[] =
  {
       7,    17,    18,     3,    27,    24,    13,    14,    31,     3,
      22,    24,     3,     4,     5,     6,    32,     8,     9,    10,
      11,    12,     0,    13,    24,     6,    33,    40,     8,    20,
      24,    20,    23,     3,    24,    42,    43,     3,     4,     5,
      31,    22,    22,    50,    20,    32,    13,    54,     4,     5,
      57,    38,    59,    40,    20,    62,     5,     5,     5,    30,
      31,    32,    85,    40,    87,    31,    20,    38,    84,    40,
      77,    78,    79,    92,    93,    94,     3,     4,     5,     6,
      13,     8,     9,    10,    11,    12,     7,    25,    25,    39,
       5,     5,     5,    20,    14,    15,    16,    17,    18,    19,
      39,    13,     5,    29,    31,    29,    29,     5,     5,     5,
      30,    29,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    14,    15,    16,    17,    18,    19,    21,    15,    22,
      14,    15,    16,    17,    18,    19,    21,    21,    80,    85,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    33,
      34,    35,    36,    37,    -1,    39,    40,    14,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    33,    34,    35,    36,
      37,    25,    39,    40,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    39,    40,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    14,
      15,    16,    17,    18,    19,    -1,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    39,    40,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    39,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    22,    43,    46,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    20,    31,    44,    45,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    57,    58,    59,    60,
       0,    52,    20,    20,    52,    52,    23,    45,    24,    50,
      24,    50,    13,    24,    14,    15,    16,    17,    18,    19,
      33,    34,    35,    36,    37,    39,    40,    56,    61,    24,
      40,    61,    13,     8,    46,    46,    50,    52,    21,     5,
       5,    52,    52,    52,    52,     5,    52,    30,    31,    32,
      38,    40,    52,    52,    20,     7,    13,    21,    25,    25,
      25,    39,    52,    52,    52,    51,     5,    25,    50,    46,
      57,     5,    46,    61,    61,    61,    39,    13,    29,     5,
       5,    29,    29,     5,     5,    29,    21,     5,    21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    47,    47,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    59,    60,    61,    61,    61
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     4,     4,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     5,     3,     5,     5,     3,
       2,     1,     4,     1,     3,     3,     4,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     5,    10,    11,     2,     5,     3,     4,     0
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TDOUBLE", "TINTEGER", "TIF", "TELSE", "TFOR", "TWHILE", "TYLL",
  "TYDOUBLE", "TYBOOL", "TEQUAL", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT",
  "TCGE", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TLBRACKET",
  "TRBRACKET", "TDOT", "TCOMMA", "TSEMICOLON", "TCOLON", "TPLUS", "TMINUS",
  "TMUL", "TDIV", "TAND", "TOR", "TXOR", "TMOD", "MTMUL", "TSHIFTR",
  "TSHIFTL", "UMINUS", "$accept", "prog", "stmts", "stmt", "block",
  "primary_typename", "array_type", "var_decl", "ident", "numeric", "expr",
  "assign", "array_index", "full_index", "comparison", "if_stmt",
  "for_condition", "for_stmt", "while_stmt", "size_expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    75,    75,    78,    79,    82,    83,    84,    85,    86,
      89,    92,    93,    94,    97,    98,   100,   101,   104,   107,
     108,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   127,   130,   131,   134,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     150,   151,   152,   155,   156,   158,   161,   164,   165,   166
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
    };
    // Last valid token kind.
    const int code_max = 296;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 23 "parser.y"
} // par
#line 1921 "Parser1.cpp"

#line 168 "parser.y"

void par::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
