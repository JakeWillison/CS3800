;Jake Willison
;BubbeSort

         BR      main
length:  .BLOCK  2           ;#2d          
counter: .BLOCK  2           ;#2d
temp:    .BLOCK  2           ;#2d
n1:      .BLOCK  2           ;#2d
n2:      .BLOCK  2           ;#2d
n3:      .BLOCK  2           ;#2d
;

main:    LDWA    22,i       
         STWA    n1,d        
         LDWA    17,i     
         STWA    n2,d        
         LDWA    12,i       
         STWA    n3,d
         LDWA    3,i
         STWA    length,d
         LDWA    1,i
         STWA    counter,d 
;
while:   LDWA    counter,d
         CPWA    length,d
         BRGE    endWhile
if1:     LDWA    n1,d
         CPWA    n2,d
         BRLT    endIf1
         LDWA    n1,d
         STWA    temp,d
         LDWA    n2,d
         STWA    n1,d
         LDWA    temp,d
         STWA    n2,d
endIf1:  LDWA    2,d
if3:     LDWA    n2,d
         CPWA    n3,d
         BRLT    endIf3
         LDWA    n2,d
         STWA    temp,d
         LDWA    n3,d
         STWA    n2,d
         LDWA    temp,d
         STWA    n3,d
endIf3:  LDWA    counter,d
         ADDA    1,i
         STWA    counter,d
         BR      while
endWhile:DECO    n1,d
         STRO    msg,d
         DECO    n2,d
         STRO    msg,d
         DECO    n3,d
         STOP
msg:     .ASCII  ", \x00"
         .END                  