/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT_TYPE = 259,
     STRING = 260,
     LLKEY = 261,
     VECTOR = 262,
     QUATERNION = 263,
     LIST = 264,
     STATE = 265,
     EVENT = 266,
     JUMP = 267,
     RETURN = 268,
     STATE_ENTRY = 269,
     STATE_EXIT = 270,
     TOUCH_START = 271,
     TOUCH = 272,
     TOUCH_END = 273,
     COLLISION_START = 274,
     COLLISION = 275,
     COLLISION_END = 276,
     LAND_COLLISION_START = 277,
     LAND_COLLISION = 278,
     LAND_COLLISION_END = 279,
     TIMER = 280,
     CHAT = 281,
     SENSOR = 282,
     NO_SENSOR = 283,
     CONTROL = 284,
     AT_TARGET = 285,
     NOT_AT_TARGET = 286,
     AT_ROT_TARGET = 287,
     NOT_AT_ROT_TARGET = 288,
     MONEY = 289,
     EMAIL = 290,
     RUN_TIME_PERMISSIONS = 291,
     INVENTORY = 292,
     ATTACH = 293,
     DATASERVER = 294,
     MOVING_START = 295,
     MOVING_END = 296,
     REZ = 297,
     OBJECT_REZ = 298,
     LINK_MESSAGE = 299,
     REMOTE_DATA = 300,
     HTTP_RESPONSE = 301,
     HTTP_REQUEST = 302,
     TRANSACTION_RESULT = 303,
     PATH_UPDATE = 304,
     EXPERIENCE_PERMISSIONS = 305,
     EXPERIENCE_PERMISSIONS_DENIED = 306,
     IDENTIFIER = 307,
     STATE_DEFAULT = 308,
     INTEGER_CONSTANT = 309,
     INTEGER_TRUE = 310,
     INTEGER_FALSE = 311,
     FP_CONSTANT = 312,
     STRING_CONSTANT = 313,
     INC_OP = 314,
     DEC_OP = 315,
     ADD_ASSIGN = 316,
     SUB_ASSIGN = 317,
     MUL_ASSIGN = 318,
     DIV_ASSIGN = 319,
     MOD_ASSIGN = 320,
     EQ = 321,
     NEQ = 322,
     GEQ = 323,
     LEQ = 324,
     BOOLEAN_AND = 325,
     BOOLEAN_OR = 326,
     SHIFT_LEFT = 327,
     SHIFT_RIGHT = 328,
     IF = 329,
     ELSE = 330,
     FOR = 331,
     DO = 332,
     WHILE = 333,
     PRINT = 334,
     PERIOD = 335,
     ZERO_VECTOR = 336,
     ZERO_ROTATION = 337,
     TOUCH_INVALID_VECTOR = 338,
     TOUCH_INVALID_TEXCOORD = 339,
     LOWER_THAN_ELSE = 340,
     INITIALIZER = 341
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT_TYPE 259
#define STRING 260
#define LLKEY 261
#define VECTOR 262
#define QUATERNION 263
#define LIST 264
#define STATE 265
#define EVENT 266
#define JUMP 267
#define RETURN 268
#define STATE_ENTRY 269
#define STATE_EXIT 270
#define TOUCH_START 271
#define TOUCH 272
#define TOUCH_END 273
#define COLLISION_START 274
#define COLLISION 275
#define COLLISION_END 276
#define LAND_COLLISION_START 277
#define LAND_COLLISION 278
#define LAND_COLLISION_END 279
#define TIMER 280
#define CHAT 281
#define SENSOR 282
#define NO_SENSOR 283
#define CONTROL 284
#define AT_TARGET 285
#define NOT_AT_TARGET 286
#define AT_ROT_TARGET 287
#define NOT_AT_ROT_TARGET 288
#define MONEY 289
#define EMAIL 290
#define RUN_TIME_PERMISSIONS 291
#define INVENTORY 292
#define ATTACH 293
#define DATASERVER 294
#define MOVING_START 295
#define MOVING_END 296
#define REZ 297
#define OBJECT_REZ 298
#define LINK_MESSAGE 299
#define REMOTE_DATA 300
#define HTTP_RESPONSE 301
#define HTTP_REQUEST 302
#define TRANSACTION_RESULT 303
#define PATH_UPDATE 304
#define EXPERIENCE_PERMISSIONS 305
#define EXPERIENCE_PERMISSIONS_DENIED 306
#define IDENTIFIER 307
#define STATE_DEFAULT 308
#define INTEGER_CONSTANT 309
#define INTEGER_TRUE 310
#define INTEGER_FALSE 311
#define FP_CONSTANT 312
#define STRING_CONSTANT 313
#define INC_OP 314
#define DEC_OP 315
#define ADD_ASSIGN 316
#define SUB_ASSIGN 317
#define MUL_ASSIGN 318
#define DIV_ASSIGN 319
#define MOD_ASSIGN 320
#define EQ 321
#define NEQ 322
#define GEQ 323
#define LEQ 324
#define BOOLEAN_AND 325
#define BOOLEAN_OR 326
#define SHIFT_LEFT 327
#define SHIFT_RIGHT 328
#define IF 329
#define ELSE 330
#define FOR 331
#define DO 332
#define WHILE 333
#define PRINT 334
#define PERIOD 335
#define ZERO_VECTOR 336
#define ZERO_ROTATION 337
#define TOUCH_INVALID_VECTOR 338
#define TOUCH_INVALID_TEXCOORD 339
#define LOWER_THAN_ELSE 340
#define INITIALIZER 341




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "indra.y"
{
	S32								ival;
	F32								fval;
	char							*sval;
	class LLScriptType				*type;
	class LLScriptConstant			*constant;
	class LLScriptIdentifier		*identifier;
	class LLScriptSimpleAssignable	*assignable;
	class LLScriptGlobalVariable	*global;
	class LLScriptEvent				*event;
	class LLScriptEventHandler		*handler;
	class LLScriptExpression		*expression;
	class LLScriptStatement			*statement;
	class LLScriptGlobalFunctions	*global_funcs;
	class LLScriptFunctionDec		*global_decl;
	class LLScriptState				*state;
	class LLScritpGlobalStorage		*global_store;
	class LLScriptScript			*script;
}
/* Line 1529 of yacc.c.  */
#line 241 "indra.y.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE indra_lval;

