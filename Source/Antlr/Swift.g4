grammar Swift;

top_level : statement* ;

statement :
expression ';'?
;

// GRAMMAR OF EXPRESSIONS

expression : primary_expression ;

primary_expression : member=identifier '(' ')'
| parentexp=primary_expression '.' member=identifier '(' ')'
| literal_expression ;

literal_expression : literal ;

// GRAMMAR OF LITERALS

literal : numeric_literal | boolean_literal | nil_literal  ;

numeric_literal
: ('-')? integer_literal
//| negate_prefix_operator? Floating_point_literal
;

boolean_literal : 'true' | 'false' ;

nil_literal : 'nil' ;

// GRAMMAR OF AN IDENTIFIER

identifier : Identifier ;

Identifier : Identifier_head Identifier_characters? ;

fragment Identifier_head : [a-zA-Z]
| '_'
| '\u00A8' | '\u00AA' | '\u00AD' | '\u00AF' | [\u00B2-\u00B5] | [\u00B7-\u00BA]
| [\u00BC-\u00BE] | [\u00C0-\u00D6] | [\u00D8-\u00F6] | [\u00F8-\u00FF]
| [\u0100-\u02FF] | [\u0370-\u167F] | [\u1681-\u180D] | [\u180F-\u1DBF]
| [\u1E00-\u1FFF]
| [\u200B-\u200D] | [\u202A-\u202E] | [\u203F-\u2040] | '\u2054' | [\u2060-\u206F]
| [\u2070-\u20CF] | [\u2100-\u218F] | [\u2460-\u24FF] | [\u2776-\u2793]
| [\u2C00-\u2DFF] | [\u2E80-\u2FFF]
| [\u3004-\u3007] | [\u3021-\u302F] | [\u3031-\u303F] | [\u3040-\uD7FF]
| [\uF900-\uFD3D] | [\uFD40-\uFDCF] | [\uFDF0-\uFE1F] | [\uFE30-\uFE44]
| [\uFE47-\uFFFD]
/*
| U+10000–U+1FFFD | U+20000–U+2FFFD | U+30000–U+3FFFD | U+40000–U+4FFFD
| U+50000–U+5FFFD | U+60000–U+6FFFD | U+70000–U+7FFFD | U+80000–U+8FFFD
| U+90000–U+9FFFD | U+A0000–U+AFFFD | U+B0000–U+BFFFD | U+C0000–U+CFFFD
| U+D0000–U+DFFFD or U+E0000–U+EFFFD
*/
;

fragment Identifier_character : [0-9]
| [\u0300-\u036F] | [\u1DC0-\u1DFF] | [\u20D0-\u20FF] | [\uFE20-\uFE2F]
| Identifier_head
;

fragment Identifier_characters : Identifier_character+ ;

// GRAMMAR OF INTEGER LITERAL

integer_literal :
Decimal_literal
| Pure_decimal_digits
;

Decimal_literal		: [0-9] [0-9_]* ;
Pure_decimal_digits : [0-9]+ ;
fragment Decimal_digit : [0-9] ;
fragment Decimal_literal_character : Decimal_digit | '_'  ;
fragment Decimal_literal_characters : Decimal_literal_character+ ;

// GRAMMAR OF A STRING LITERAL





/* We're going to ignore all white space characters */
WS : [ \n\r\t\u000B\u000C\u0000]+ -> channel(HIDDEN) ;
