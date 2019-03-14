%{
#include "lex-ere.tab.h"
%}
%x CHARACTER_CLASS
%%
"[="	return Open_equal;
"=]"	return Equal_close;
"[."	return Open_dot;
".]"	return Dot_close;
j
"[:"	{
		BEGIN CHARACTER_CLASS;
		return Open_colon;
	}

":]"	{
		BEGIN INITIAL;
		return Colon_close;
	}

<CHARACTER_CLASS>"alnum"	|
<CHARACTER_CLASS>"alpha"	|
<CHARACTER_CLASS>"blank"	|
<CHARACTER_CLASS>"cntrl"	|
<CHARACTER_CLASS>"digit"	|
<CHARACTER_CLASS>"graph"	|
<CHARACTER_CLASS>"lower"	|
<CHARACTER_CLASS>"print"	|
<CHARACTER_CLASS>"punct"	|
<CHARACTER_CLASS>"space"	|
<CHARACTER_CLASS>"upper"	|
<CHARACTER_CLASS>"xdigit"	return class_name;
