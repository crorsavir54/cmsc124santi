;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname |Problem 2|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;Problem 2
;Rivas / Callao
;Program Description
;    : this program takes a list and reverses its order, still in a form of a list.

(define (my-reverse li)
(begin
        
       (if(not (null? (cdr li)))   ;checks if list the rest of the list is null
        (if (list? (car li))       ; if yes, then checks again if the first element of the list is a list
           (my-reverse (cons (cons (car (cdr li)) (car li))(cdr (cdr li)))) ; if yes then takes the the second element and 'cons' it to the first element 
                                                                            ;             and 'cons' it to the rest of the list, the resulting list will be the argument for the recursive call
           (my-reverse (cons (list (car li)) (cdr li))))                    ; else takes the first element then makes it a list
         (car li) )                ; if the rest of the list(except the first) is not null then return the first element, which is a list. 
         )
   )
 
;(my-reverse (list '1 '2 '3 '4 '5 '6 '7 '8 '9 '10 '11))
