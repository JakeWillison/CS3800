;Jake Willison
;4/5/21
;Print 4 characters from a stack backwards
;Homework 5

         LDBA    'e',i       ;move e to stack
         STBA    -1,s        
         LDBA    'k',i       ;move k to stack
         STBA    -2,s        
         LDBA    'a',i       ;move a to stack
         STBA    -3,s               
         LDBA    'J',i       ;move J to stack
         STBA    -4,s        
         SUBSP   4,i         ;4 bytes on stack
         LDBA    0,s         ;print J
         STBA    charOut,d   
         LDBA    1,s         ;print a
         STBA    charOut,d   
         LDBA    2,s         ;print k
         STBA    charOut,d   
         LDBA    3,s         ;print e
         STBA    charOut,d   
         ADDSP   4,i         ;pops everything off the stack
         STOP                
         .END                  
