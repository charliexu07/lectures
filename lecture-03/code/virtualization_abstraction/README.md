
EXAMPLES:

cpu.c: just something you can run one instance of first, and
       then a bunch of at once, in order to show that the CPU
       can be VIRTUALIZED. Amazingly, the OS can make it seem
       like you have as many CPUs as you need!
       e.g., prompt> cpu A


mem.c: same thing but showing how you can seemingly access
       the "same" memory location from different programs,
       and yet they each seem to have their own copy. Yes,
       the OS can VIRTUALIZE memory too, providing each
       running program with the illusion of its own memory.

       A little pain to get this to work if the system you
       are using has address-space randomization; if so, 
       run it in the debugger (gdb) which should turn off
       ASLR and make it easy for two separate 'mem' processes
       to use the same virtual addresses.

       For example, on mac OS X, the following sequence is useful:

       prompt> gdb mem
       ...
       (gdb) set disable- disable-randomization
       (gdb) run 0
       ...

	   
	   You will see that everytime you run it , the pointer address is same : how can that be ?

io.c:  I run this on a Mac, and use a dtrace script to show
       how this little program, which does so little to access
       a file from the perspective of C, actually leads to hundreds
       and hundreds of calls within the OS to commit the data to
       disk.
       On Linux try strace io
       
----



After the examples, think about the OS's major role as providing a 
VIRTUAL MACHINE and all this entails. 



