c l a s s   t r e e   {  
 p u b l i c :  
     t r e e ( i n t   _ n )   {  
         n   =   _ n ;  
     }  
     v o i d   g e t _ t r e e ( )   {  
         g . c l e a r ( ) ;   g . r e s i z e ( n ) ;  
         e d g e s . c l e a r ( ) ;   e d g e s . r e s i z e ( n ) ;  
         f o r   ( i n t   i   =   1 ;   i   <   n ;   i + + )   {  
             i n t   u ,   v ;  
             c i n   > >   u   > >   v ;  
             u - - ;   v - - ;  
             a s s e r t ( u   > =   0   & &   v   > =   0   & &   u   <   n   & &   v   <   n ) ;  
             g [ u ] . p u s h _ b a c k ( e d g e ( u ,   v ) ) ;  
             g [ v ] . p u s h _ b a c k ( e d g e ( v ,   u ) ) ;  
         }  
     }  
     s t r u c t   e d g e   {  
         i n t   f r o m ,   t o ,   d i s ;  
         e d g e ( )   {  
             f r o m   =   t o   =   d i s   =   - 1 ;  
         }  
         e d g e ( i n t   f ,   i n t   t )   {  
             f r o m   =   f ;   t o   =   t ;   d i s   =   1 ;  
         }    
         e d g e ( i n t   f ,   i n t   t ,   i n t   c )   {  
             f r o m   =   f ;   t o   =   t ;   d i s   =   c ;  
         }  
     } ;  
     s t a t i c   i n t   n ;  
     s t a t i c   v e c t o r < v e c t o r < e d g e > >   g ;  
     s t a t i c   v e c t o r < e d g e >   e d g e s ;  
 } ;                                                                                                                                    
 i n t   t r e e : : n   =   { } ;  
 v e c t o r < t r e e : : e d g e >   t r e e : : e d g e s   =   v e c t o r < t r e e : : e d g e >   ( ) ;  
 v e c t o r < v e c t o r < t r e e : : e d g e > >   t r e e : : g   =   v e c t o r < v e c t o r < t r e e : : e d g e > >   ( ) ;  
 