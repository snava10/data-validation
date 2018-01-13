grammar ValidationSchema;

/*
 * Parser Rules
 */

schema                  :   prolog body;
prolog                  :   version_dec global_directives;
version_dec             :   (VERSION10 | VERSION11);
global_directives       :   separator_directive? quoted_directive? 
                            total_columns_directive? permit_empty_directive?                            
                            (no_header_directive | ignore_column_name_case_directive)?;

separator_directive     :   DIRECTIVE_PREFIX SEPARATOR (tab_expr | 
                            char_literal_expr);
tab_expr                :   TAB;
char_literal_expr       :   CHARACTER_LITERAL;
quoted_directive        :   DIRECTIVE_PREFIX QUOTED;
total_columns_directive :   DIRECTIVE_PREFIX TOTAL_COLUMNS 
                            positive_integer_literal;
permit_empty_directive  :   DIRECTIVE_PREFIX PERMIT_EMPTY;
no_header_directive     :   DIRECTIVE_PREFIX NO_HEADER;
ignore_column_name_case_directive   :   DIRECTIVE_PREFIX 
                                        IGNORE_COLUMN_NAME_CASE;

body                    :   body_part*;
body_part               :   comment* column_definition comment*;
comment                 :   SINGLE_LINE_COMMENT | MULTI_LINE_COMMENT;
column_definition       :   (column_identifier | quoted_column_identifier) COLON
                            column_rule;
column_identifier       :   positive_integer_literal              #index
                        |   IDENTIFIER                            #name
                        ;
quoted_column_identifier:   STRING_LITERAL;
column_rule             :   column_validation_expr* column_directives;
column_directives       :   optional_directive? match_is_false_directive?
                            ignore_case_directive? warning_directive?;
optional_directive      :   DIRECTIVE_PREFIX OPTIONAL;
match_is_false_directive:   DIRECTIVE_PREFIX MATCH_IS_FALSE;
ignore_case_directive   :   DIRECTIVE_PREFIX IGNORE_CASE;
warning_directive       :   DIRECTIVE_PREFIX WARNING;
column_validation_expr  :   non_combinatorial_expr | combinatorial_expr;
combinatorial_expr      :   or_expr | and_expr;
or_expr                 :   non_combinatorial_expr OR column_validation_expr;
and_expr                :   non_combinatorial_expr AND column_validation_expr;
non_combinatorial_expr  :   non_conditional_expr | conditional_expr;
non_conditional_expr    :   single_expr | parenthesized_expr; //| external_sigle_expr

single_expr             :   explicit_context_expr? 
                            (is_expr | any_expr | not_expr | in_expr | 
                             starts_with_expr | ends_with_expr | reg_exp_expr |
                             range_expr | length_expr | empty_expr | not_empty_expr | 
                             unique_expr | uri_expr | uuid4_expr | 
                             positive_integer_expr | upper_case_expr | 
                             lower_case_expr | identical_expr | date_expr);

date_expr               :   DATE (date_format_expr | date_range_expr)?;
date_format_expr        :   OPEN_BRACKET STRING_LITERAL CLOSE_BRACKET;
date_range_expr         :   OPEN_BRACKET update_literal COMA update_literal CLOSE_BRACKET;

explicit_context_expr   :   column_ref FORWARD_SLASH;
column_ref              :   DOLLAR (column_identifier | quoted_column_identifier)
                        ;
string_provider         :   column_ref | STRING_LITERAL | concat_expr | 
                            no_ext_expr
                        ;
concat_expr             :   CONCAT OPEN_BRACKET string_provider 
                            (COMA string_provider)+ CLOSE_BRACKET;
conditional_expr        :   if_expr | switch_expr;
if_expr                 :   IF OPEN_BRACKET
                            (combinatorial_expr | non_conditional_expr) COMA 
                            column_validation_expr+ (COMA column_validation_expr+)? 
                            CLOSE_BRACKET;
switch_expr             :   SWITCH OPEN_BRACKET switch_case_expr+ 
                            (COMA column_validation_expr+)?
                            CLOSE_BRACKET;
switch_case_expr        :   OPEN_BRACKET (combinatorial_expr | non_conditional_expr) COMA 
                            column_validation_expr+ CLOSE_BRACKET;
parenthesized_expr      :   OPEN_BRACKET column_validation_expr+ CLOSE_BRACKET;
no_ext_expr             :   NO_EXT OPEN_BRACKET string_provider CLOSE_BRACKET;

is_expr                 :   IS OPEN_BRACKET string_provider CLOSE_BRACKET;
any_expr                :   ANY OPEN_BRACKET 
                            (string_provider (COMA string_provider)*)
                            CLOSE_BRACKET;

not_expr                :   NOT OPEN_BRACKET string_provider CLOSE_BRACKET;
in_expr                 :   IN OPEN_BRACKET string_provider CLOSE_BRACKET;

starts_with_expr        :   STARTS_WITH OPEN_BRACKET string_provider CLOSE_BRACKET;
ends_with_expr          :   ENDS_WITH OPEN_BRACKET string_provider CLOSE_BRACKET;

reg_exp_expr            :   REGEX OPEN_BRACKET STRING_LITERAL CLOSE_BRACKET;
range_expr              :   RANGE OPEN_BRACKET (numeric_or_any COMA numeric_literal | 
                                               
                            numeric_literal COMA numeric_or_any) CLOSE_BRACKET;
numeric_or_any          :   numeric_literal | WILDCARD_LITERAL;
length_expr             :   LENGTH OPEN_BRACKET (positive_integer_or_any COMA)? 
                            positive_integer_or_any CLOSE_BRACKET;
positive_integer_or_any :   positive_integer_literal | WILDCARD_LITERAL;
empty_expr              :   EMPTY;
not_empty_expr          :   NOT_EMPTY;
unique_expr             :   UNIQUE (OPEN_BRACKET column_ref (COMA column_ref)* CLOSE_BRACKET)?;
uri_expr                :   URI;

uuid4_expr              :   UUID4;
positive_integer_expr   :   POSITIVE_INTEGER;
upper_case_expr         :   UPPER_CASE;
lower_case_expr         :   LOWER_CASE;
identical_expr          :   IDENTICAL;

numeric_literal         :   MINUS? (positive_integer_literal | positive_float_literal);
positive_integer_literal:   INTEGER;
positive_float_literal  :   NUMERIC_LITERAL;

update_literal          :    positive_integer_literal MINUS positive_integer_literal MINUS
                             positive_integer_literal
                        ;

/*
 * Lexer Rules
 */

//Keywords
OR                      :   'or';
AND                     :   'and';
ANY                     :   'any';
NOT                     :   'not';
IN                      :   'in';
STARTS_WITH             :   'startsWith';
ENDS_WITH               :   'endsWith';
REGEX                   :   'regex';
RANGE                   :   'range';
LENGTH                  :   'length';
CONCAT                  :   'concat';
NO_EXT                  :   'noExt';
IS                      :   'is';
SEPARATOR               :   'separator';
VERSION10               :   'version 1.0';
VERSION11               :   'version 1.1';
QUOTED                  :   'quoted';
TOTAL_COLUMNS           :   'totalColumns';
PERMIT_EMPTY            :   'permitEmpty';
NO_HEADER               :   'noHeader';
IGNORE_COLUMN_NAME_CASE :   'ignoreColumnNameCase';
OPTIONAL                :   'optional';
MATCH_IS_FALSE          :   'matchIsFalse';
IGNORE_CASE             :   'ignoreCase';
WARNING                 :   'warning';
PART_UK_DATE            :   'partUkDate';
EMPTY                   :   'empty';
NOT_EMPTY               :   'notEmpty';
UNIQUE                  :   'unique';
URI                     :   'uri';
DATE                    :   'date';
UUID4                   :   'uuid' | 'uuid4';
PARTIAL                 :   'partial';
UPPER_CASE              :   'upperCase';
LOWER_CASE              :   'lowerCase';
IDENTICAL               :   'identical';
POSITIVE_INTEGER        :   'positiveInteger';
IF                      :   'if';
SWITCH                  :   'switch';
fragment SINGLE_QUOTE   :   '\'';

//Symbols
DIRECTIVE_PREFIX        :   '@';
DOLLAR                  :   '$';
FORWARD_SLASH           :   '/';
COMA                    :   ',';
OPEN_BRACKET            :   '(';
CLOSE_BRACKET           :   ')';
WILDCARD_LITERAL        :   '*';
COLON                   :   ':';
T                       :   'T';
DOT                     :   '.';
MINUS                   :   '-';

//Regex
TAB                                 :   'TAB';
CHARACTER_LITERAL                   :   SINGLE_QUOTE . SINGLE_QUOTE; //TODO Review

fragment DIGIT                      :   '0'..'9';
INTEGER                             :   DIGIT+;
NUMERIC_LITERAL                     :   INTEGER(DOT INTEGER)?;

SINGLE_LINE_COMMENT                 :   '//' ~('\r' | '\n')*;
MULTI_LINE_COMMENT                  :   '/*' .*? '*/'; //TODO fix this to be a reg expr
IDENTIFIER                          :   [a-z|A-Z][a-zA-Z0-9_]*; //TODO Review
STRING_LITERAL                      :    '"'.*?'"';

WS
	:	(' ' | '\t' | '\r' | '\n')+ -> channel(HIDDEN)
	;
