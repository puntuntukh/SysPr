format PE console

entry start

include 'win32a.inc'

section '.data' data readable writable



        resStr db 'Result: %d', 0



        array db 4,5,6,7,8,40,50,55,60,65,70,80

        NULL = 0


section '.code' code readable executable

        start:


                mov edx, 0
                mov bl, 0
                mov al, 0
                mov esi, 0



                   lp:
                        mov al, [array + esi]
                        xor al, 34    ; 00100010b
                        and al, 34

                        cmp al, 0

                     jne nextlp

                        add edx, 1

                     nextlp:

                              add esi, 1
                              cmp esi, 11
                   jne lp

                push edx
                push resStr
                call [printf]
                call [getch]

                push NULL
                call [ExitProcess]

section  '.idata' import data readable

        library kernel, 'kernel32.dll',\
                msvcrt, 'msvcrt.dll'

        import kernel,\
                 ExitProcess, 'ExitProcess'


        import msvcrt,\
                 printf, 'printf',\
                 getch, '_getch',\
                 scanf, 'scanf'

