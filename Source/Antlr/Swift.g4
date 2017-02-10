grammar Swift;

top_level : statement* ;

statement :
literal
;

// GRAMMAR OF LITERALS

literal : numeric_literal | boolean_literal | nil_literal  ;

numeric_literal
: ('-')? integer_literal
//| negate_prefix_operator? Floating_point_literal
;

boolean_literal : 'true' | 'false' ;

nil_literal : 'nil' ;

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
