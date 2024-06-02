// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Parser1.hpp
 ** Define the par::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER1_HPP_INCLUDED
# define YY_YY_PARSER1_HPP_INCLUDED
// "%code requires" blocks.
#line 13 "parser.y"

#include "ast.hpp" // 包含你自己定义的类的头文件

#line 53 "Parser1.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 23 "parser.y"
namespace par {
#line 189 "Parser1.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // array_index
      // full_index
      char dummy1[sizeof (NArrayIndex*)];

      // array_type
      // size_expr
      char dummy2[sizeof (NArrayType*)];

      // assign
      char dummy3[sizeof (NAssignment*)];

      // prog
      // block
      char dummy4[sizeof (NBlock*)];

      // numeric
      // expr
      char dummy5[sizeof (NExpression*)];

      // for_condition
      // for_stmt
      char dummy6[sizeof (NForStatement*)];

      // ident
      char dummy7[sizeof (NIdentifier*)];

      // if_stmt
      char dummy8[sizeof (NIfStatement*)];

      // stmt
      char dummy9[sizeof (NStatement*)];

      // var_decl
      char dummy10[sizeof (NVariableDeclaration*)];

      // while_stmt
      char dummy11[sizeof (NWhileStatement*)];

      // comparison
      char dummy12[sizeof (SYMBOL_TYPE)];

      // primary_typename
      char dummy13[sizeof (VALUE_TYPE)];

      // TDOUBLE
      char dummy14[sizeof (double)];

      // TINTEGER
      char dummy15[sizeof (long long)];

      // TIDENTIFIER
      char dummy16[sizeof (std::string)];

      // stmts
      char dummy17[sizeof (std::vector<NStatement*>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    TIDENTIFIER = 258,             // TIDENTIFIER
    TDOUBLE = 259,                 // TDOUBLE
    TINTEGER = 260,                // TINTEGER
    TIF = 261,                     // TIF
    TELSE = 262,                   // TELSE
    TFOR = 263,                    // TFOR
    TWHILE = 264,                  // TWHILE
    TYLL = 265,                    // TYLL
    TYDOUBLE = 266,                // TYDOUBLE
    TYBOOL = 267,                  // TYBOOL
    TEQUAL = 268,                  // TEQUAL
    TCEQ = 269,                    // TCEQ
    TCNE = 270,                    // TCNE
    TCLT = 271,                    // TCLT
    TCLE = 272,                    // TCLE
    TCGT = 273,                    // TCGT
    TCGE = 274,                    // TCGE
    TLPAREN = 275,                 // TLPAREN
    TRPAREN = 276,                 // TRPAREN
    TLBRACE = 277,                 // TLBRACE
    TRBRACE = 278,                 // TRBRACE
    TLBRACKET = 279,               // TLBRACKET
    TRBRACKET = 280,               // TRBRACKET
    TDOT = 281,                    // TDOT
    TCOMMA = 282,                  // TCOMMA
    TSEMICOLON = 283,              // TSEMICOLON
    TCOLON = 284,                  // TCOLON
    TPLUS = 285,                   // TPLUS
    TMINUS = 286,                  // TMINUS
    TMUL = 287,                    // TMUL
    TDIV = 288,                    // TDIV
    TAND = 289,                    // TAND
    TOR = 290,                     // TOR
    TXOR = 291,                    // TXOR
    TMOD = 292,                    // TMOD
    MTMUL = 293,                   // MTMUL
    TSHIFTR = 294,                 // TSHIFTR
    TSHIFTL = 295,                 // TSHIFTL
    UMINUS = 296                   // UMINUS
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 42, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TIDENTIFIER = 3,                       // TIDENTIFIER
        S_TDOUBLE = 4,                           // TDOUBLE
        S_TINTEGER = 5,                          // TINTEGER
        S_TIF = 6,                               // TIF
        S_TELSE = 7,                             // TELSE
        S_TFOR = 8,                              // TFOR
        S_TWHILE = 9,                            // TWHILE
        S_TYLL = 10,                             // TYLL
        S_TYDOUBLE = 11,                         // TYDOUBLE
        S_TYBOOL = 12,                           // TYBOOL
        S_TEQUAL = 13,                           // TEQUAL
        S_TCEQ = 14,                             // TCEQ
        S_TCNE = 15,                             // TCNE
        S_TCLT = 16,                             // TCLT
        S_TCLE = 17,                             // TCLE
        S_TCGT = 18,                             // TCGT
        S_TCGE = 19,                             // TCGE
        S_TLPAREN = 20,                          // TLPAREN
        S_TRPAREN = 21,                          // TRPAREN
        S_TLBRACE = 22,                          // TLBRACE
        S_TRBRACE = 23,                          // TRBRACE
        S_TLBRACKET = 24,                        // TLBRACKET
        S_TRBRACKET = 25,                        // TRBRACKET
        S_TDOT = 26,                             // TDOT
        S_TCOMMA = 27,                           // TCOMMA
        S_TSEMICOLON = 28,                       // TSEMICOLON
        S_TCOLON = 29,                           // TCOLON
        S_TPLUS = 30,                            // TPLUS
        S_TMINUS = 31,                           // TMINUS
        S_TMUL = 32,                             // TMUL
        S_TDIV = 33,                             // TDIV
        S_TAND = 34,                             // TAND
        S_TOR = 35,                              // TOR
        S_TXOR = 36,                             // TXOR
        S_TMOD = 37,                             // TMOD
        S_MTMUL = 38,                            // MTMUL
        S_TSHIFTR = 39,                          // TSHIFTR
        S_TSHIFTL = 40,                          // TSHIFTL
        S_UMINUS = 41,                           // UMINUS
        S_YYACCEPT = 42,                         // $accept
        S_prog = 43,                             // prog
        S_stmts = 44,                            // stmts
        S_stmt = 45,                             // stmt
        S_block = 46,                            // block
        S_primary_typename = 47,                 // primary_typename
        S_array_type = 48,                       // array_type
        S_var_decl = 49,                         // var_decl
        S_ident = 50,                            // ident
        S_numeric = 51,                          // numeric
        S_expr = 52,                             // expr
        S_assign = 53,                           // assign
        S_array_index = 54,                      // array_index
        S_full_index = 55,                       // full_index
        S_comparison = 56,                       // comparison
        S_if_stmt = 57,                          // if_stmt
        S_for_condition = 58,                    // for_condition
        S_for_stmt = 59,                         // for_stmt
        S_while_stmt = 60,                       // while_stmt
        S_size_expr = 61                         // size_expr
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.move< NArrayIndex* > (std::move (that.value));
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.move< NArrayType* > (std::move (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.move< NAssignment* > (std::move (that.value));
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.move< NBlock* > (std::move (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.move< NExpression* > (std::move (that.value));
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.move< NForStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< NIdentifier* > (std::move (that.value));
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.move< NIfStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< NStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< NVariableDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.move< NWhileStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_comparison: // comparison
        value.move< SYMBOL_TYPE > (std::move (that.value));
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.move< VALUE_TYPE > (std::move (that.value));
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.move< long long > (std::move (that.value));
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<NStatement*> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NArrayIndex*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NArrayIndex*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NArrayType*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NArrayType*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NAssignment*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NAssignment*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NBlock*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NBlock*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NExpression*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NExpression*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NForStatement*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NForStatement*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NIdentifier*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NIdentifier*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NIfStatement*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NIfStatement*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NStatement*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NStatement*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NVariableDeclaration*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NVariableDeclaration*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NWhileStatement*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NWhileStatement*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SYMBOL_TYPE&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SYMBOL_TYPE& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VALUE_TYPE&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VALUE_TYPE& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<NStatement*>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<NStatement*>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_array_index: // array_index
      case symbol_kind::S_full_index: // full_index
        value.template destroy< NArrayIndex* > ();
        break;

      case symbol_kind::S_array_type: // array_type
      case symbol_kind::S_size_expr: // size_expr
        value.template destroy< NArrayType* > ();
        break;

      case symbol_kind::S_assign: // assign
        value.template destroy< NAssignment* > ();
        break;

      case symbol_kind::S_prog: // prog
      case symbol_kind::S_block: // block
        value.template destroy< NBlock* > ();
        break;

      case symbol_kind::S_numeric: // numeric
      case symbol_kind::S_expr: // expr
        value.template destroy< NExpression* > ();
        break;

      case symbol_kind::S_for_condition: // for_condition
      case symbol_kind::S_for_stmt: // for_stmt
        value.template destroy< NForStatement* > ();
        break;

      case symbol_kind::S_ident: // ident
        value.template destroy< NIdentifier* > ();
        break;

      case symbol_kind::S_if_stmt: // if_stmt
        value.template destroy< NIfStatement* > ();
        break;

      case symbol_kind::S_stmt: // stmt
        value.template destroy< NStatement* > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.template destroy< NVariableDeclaration* > ();
        break;

      case symbol_kind::S_while_stmt: // while_stmt
        value.template destroy< NWhileStatement* > ();
        break;

      case symbol_kind::S_comparison: // comparison
        value.template destroy< SYMBOL_TYPE > ();
        break;

      case symbol_kind::S_primary_typename: // primary_typename
        value.template destroy< VALUE_TYPE > ();
        break;

      case symbol_kind::S_TDOUBLE: // TDOUBLE
        value.template destroy< double > ();
        break;

      case symbol_kind::S_TINTEGER: // TINTEGER
        value.template destroy< long long > ();
        break;

      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_stmts: // stmts
        value.template destroy< std::vector<NStatement*> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const double& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const long long& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    Parser (yyscan_t scanner_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIDENTIFIER (std::string v)
      {
        return symbol_type (token::TIDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_TIDENTIFIER (const std::string& v)
      {
        return symbol_type (token::TIDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TDOUBLE (double v)
      {
        return symbol_type (token::TDOUBLE, std::move (v));
      }
#else
      static
      symbol_type
      make_TDOUBLE (const double& v)
      {
        return symbol_type (token::TDOUBLE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TINTEGER (long long v)
      {
        return symbol_type (token::TINTEGER, std::move (v));
      }
#else
      static
      symbol_type
      make_TINTEGER (const long long& v)
      {
        return symbol_type (token::TINTEGER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIF ()
      {
        return symbol_type (token::TIF);
      }
#else
      static
      symbol_type
      make_TIF ()
      {
        return symbol_type (token::TIF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TELSE ()
      {
        return symbol_type (token::TELSE);
      }
#else
      static
      symbol_type
      make_TELSE ()
      {
        return symbol_type (token::TELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TFOR ()
      {
        return symbol_type (token::TFOR);
      }
#else
      static
      symbol_type
      make_TFOR ()
      {
        return symbol_type (token::TFOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TWHILE ()
      {
        return symbol_type (token::TWHILE);
      }
#else
      static
      symbol_type
      make_TWHILE ()
      {
        return symbol_type (token::TWHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYLL ()
      {
        return symbol_type (token::TYLL);
      }
#else
      static
      symbol_type
      make_TYLL ()
      {
        return symbol_type (token::TYLL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYDOUBLE ()
      {
        return symbol_type (token::TYDOUBLE);
      }
#else
      static
      symbol_type
      make_TYDOUBLE ()
      {
        return symbol_type (token::TYDOUBLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYBOOL ()
      {
        return symbol_type (token::TYBOOL);
      }
#else
      static
      symbol_type
      make_TYBOOL ()
      {
        return symbol_type (token::TYBOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEQUAL ()
      {
        return symbol_type (token::TEQUAL);
      }
#else
      static
      symbol_type
      make_TEQUAL ()
      {
        return symbol_type (token::TEQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCEQ ()
      {
        return symbol_type (token::TCEQ);
      }
#else
      static
      symbol_type
      make_TCEQ ()
      {
        return symbol_type (token::TCEQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCNE ()
      {
        return symbol_type (token::TCNE);
      }
#else
      static
      symbol_type
      make_TCNE ()
      {
        return symbol_type (token::TCNE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCLT ()
      {
        return symbol_type (token::TCLT);
      }
#else
      static
      symbol_type
      make_TCLT ()
      {
        return symbol_type (token::TCLT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCLE ()
      {
        return symbol_type (token::TCLE);
      }
#else
      static
      symbol_type
      make_TCLE ()
      {
        return symbol_type (token::TCLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCGT ()
      {
        return symbol_type (token::TCGT);
      }
#else
      static
      symbol_type
      make_TCGT ()
      {
        return symbol_type (token::TCGT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCGE ()
      {
        return symbol_type (token::TCGE);
      }
#else
      static
      symbol_type
      make_TCGE ()
      {
        return symbol_type (token::TCGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TLPAREN ()
      {
        return symbol_type (token::TLPAREN);
      }
#else
      static
      symbol_type
      make_TLPAREN ()
      {
        return symbol_type (token::TLPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRPAREN ()
      {
        return symbol_type (token::TRPAREN);
      }
#else
      static
      symbol_type
      make_TRPAREN ()
      {
        return symbol_type (token::TRPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TLBRACE ()
      {
        return symbol_type (token::TLBRACE);
      }
#else
      static
      symbol_type
      make_TLBRACE ()
      {
        return symbol_type (token::TLBRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRBRACE ()
      {
        return symbol_type (token::TRBRACE);
      }
#else
      static
      symbol_type
      make_TRBRACE ()
      {
        return symbol_type (token::TRBRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TLBRACKET ()
      {
        return symbol_type (token::TLBRACKET);
      }
#else
      static
      symbol_type
      make_TLBRACKET ()
      {
        return symbol_type (token::TLBRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRBRACKET ()
      {
        return symbol_type (token::TRBRACKET);
      }
#else
      static
      symbol_type
      make_TRBRACKET ()
      {
        return symbol_type (token::TRBRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TDOT ()
      {
        return symbol_type (token::TDOT);
      }
#else
      static
      symbol_type
      make_TDOT ()
      {
        return symbol_type (token::TDOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCOMMA ()
      {
        return symbol_type (token::TCOMMA);
      }
#else
      static
      symbol_type
      make_TCOMMA ()
      {
        return symbol_type (token::TCOMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSEMICOLON ()
      {
        return symbol_type (token::TSEMICOLON);
      }
#else
      static
      symbol_type
      make_TSEMICOLON ()
      {
        return symbol_type (token::TSEMICOLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCOLON ()
      {
        return symbol_type (token::TCOLON);
      }
#else
      static
      symbol_type
      make_TCOLON ()
      {
        return symbol_type (token::TCOLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TPLUS ()
      {
        return symbol_type (token::TPLUS);
      }
#else
      static
      symbol_type
      make_TPLUS ()
      {
        return symbol_type (token::TPLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMINUS ()
      {
        return symbol_type (token::TMINUS);
      }
#else
      static
      symbol_type
      make_TMINUS ()
      {
        return symbol_type (token::TMINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMUL ()
      {
        return symbol_type (token::TMUL);
      }
#else
      static
      symbol_type
      make_TMUL ()
      {
        return symbol_type (token::TMUL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TDIV ()
      {
        return symbol_type (token::TDIV);
      }
#else
      static
      symbol_type
      make_TDIV ()
      {
        return symbol_type (token::TDIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAND ()
      {
        return symbol_type (token::TAND);
      }
#else
      static
      symbol_type
      make_TAND ()
      {
        return symbol_type (token::TAND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOR ()
      {
        return symbol_type (token::TOR);
      }
#else
      static
      symbol_type
      make_TOR ()
      {
        return symbol_type (token::TOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TXOR ()
      {
        return symbol_type (token::TXOR);
      }
#else
      static
      symbol_type
      make_TXOR ()
      {
        return symbol_type (token::TXOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMOD ()
      {
        return symbol_type (token::TMOD);
      }
#else
      static
      symbol_type
      make_TMOD ()
      {
        return symbol_type (token::TMOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MTMUL ()
      {
        return symbol_type (token::MTMUL);
      }
#else
      static
      symbol_type
      make_MTMUL ()
      {
        return symbol_type (token::MTMUL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSHIFTR ()
      {
        return symbol_type (token::TSHIFTR);
      }
#else
      static
      symbol_type
      make_TSHIFTR ()
      {
        return symbol_type (token::TSHIFTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSHIFTL ()
      {
        return symbol_type (token::TSHIFTL);
      }
#else
      static
      symbol_type
      make_TSHIFTL ()
      {
        return symbol_type (token::TSHIFTL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#else
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 262,     ///< Last index in yytable_.
      yynnts_ = 20,  ///< Number of nonterminal symbols.
      yyfinal_ = 30 ///< Termination state number.
    };


    // User arguments.
    yyscan_t scanner;

  };


#line 23 "parser.y"
} // par
#line 2149 "Parser1.hpp"


// "%code provides" blocks.
#line 28 "parser.y"

    #define YY_DECL \
        int yylex(par::Parser::semantic_type *yylval, yyscan_t yyscanner)
    YY_DECL;

#line 2159 "Parser1.hpp"


#endif // !YY_YY_PARSER1_HPP_INCLUDED
