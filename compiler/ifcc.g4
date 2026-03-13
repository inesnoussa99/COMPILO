grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' statement* '}' ;

statement 
    : 'return' expr ';'                         # ReturnStmt
    | 'int' VAR ';'                             # Declaration
    | 'int' VAR '[' expr ']' ';'                # ArrayDeclaration
    | VAR '=' expr ';'                          # VarAssignment
    | VAR '[' index=expr ']' '=' val=expr ';'   # ArrayAssignment
    | 'if' '(' expr ')' thenStmt=statement 
      ('else' elseStmt=statement)?              # IfStmt
    | '{' statements=statement* '}'             # BlocStmt
    ;

expr : '(' expr ')'                         # ParExpr
     | OU=('!'|'~'|'-') expr                # UnaryExpr
     | expr OM=('*'|'/'|'%') expr           # MultExpr
     | expr OA=('+'|'-') expr               # AddExpr
     | expr OS=('<<'|'>>') expr             # ShiftExpr
     | expr OR=('<'|'>'|'<='|'>=') expr     # RelationalExpr
     | expr OE=('=='|'!=') expr             # EqualityExpr
     | expr '&' expr                        # BitwiseAndExpr
     | expr '^' expr                        # BitwiseXorExpr
     | expr '|' expr                        # BitwiseOrExpr
     | expr '&&' expr                       # LogicalAndExpr
     | expr '||' expr                       # LogicalOrExpr
     | VAR                                  # VarExpr
     | CONST                                # ConstExpr
     | VAR '[' expr ']'                     # ArrayExpr 
     ;

RETURN : 'return' ;
CONST  : [0-9]+ ;
VAR    : [a-zA-Z_] [a-zA-Z0-9_]* ;

COMMENT   : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' (~'\n')* '\n' -> skip ;
WS        : [ \t\r\n]+ -> channel(HIDDEN);
LINE_COMMENT  : '//' ~[\r\n]* -> skip ;