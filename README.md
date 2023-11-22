<pre style="color: white !important; background-color: black !important;">
 _ _ _     _            
| (_) |__ | | __ _  ___ 
| | | '_ \| |/ _` |/ __|
| | | |_) | | (_| | (__ 
|_|_|_.__/|_|\__,_|\___|
</pre>


☦️ This software was written in the name of the __Father__ and of the __Son__ and of the __Holy Spirit__; Amen. 

About
===
liblac is the Linear Algebra Library (written in C). This is purely a personal project and is not 
at all intended for commercial or production use. No serious attempts at optimization have been 
made. If you are looking for a more robust linear algebra library written in C, please check out 
[GLM](https://github.com/g-truc/glm). 

Philosophy
===
The reason I created this library was primarily for learning purposes. To complement this, I've 
sprinkled in additional comments explaining some of the more complex concepts on top of the vanilla 
API docs generated by Doxygen. The library is minimally obfuscated at the expense of performance. 
There are certainly much more efficient algorithms for doing vector and matrix mathematics, especially
with modern hardware features such as SIMD. These tend to make code less portable, however, which 
was a minor consideration as well. You will notice that the APIs are written in a functional manner
(although not purely functional). This is to say that the mutation of input parameters is generally
avoided, except for the output parameter. This places the responsibility of managing 
owners on you, the maintainer, not on the library. Each API function is named following a specific 
convention. Each API function begins with lac_, which is intentionally done to reduce namespace 
collisions and to differentiate from other libraries. Additionally, each API function follows a 
verb-subject structure. This makes it easy to anticipate the names of similar functionality. For 
example, given that there is a function called lac_add_vec3(), is follows that there exists a function 
called lac_subtract_vec3(). Parameters are ordered as follows: 

1. First class input data members
2. First class output data members
3. Second class input data members

First class data members are directly related to the subject of the function i.e. the operands of the 
operation. Second class data members include parameters that affect the operation in some way, but 
that are only loosely related to the subject. Examples include scaling constants, angles for rotation,
boolean flags, etc. 

Installation
===
In order to use liblac for your application(s) run the following command:

```shell
sudo make install
```

This installs both the shared object/dll and archive/static versions of the library in 
/usr/lib/ by default. If you want to change the installation directory, run the following 
command instead: 

```shell
sudo make LIB_DIR=/full/path/to/install/ install
```

If you want to simply build the binaries but not copy them to an installation directory,
run the following command instead:

```shell
sudo make all
```

This will place both the shared object/dll and archive/static versions of the library in 
the repo's bin directory. 

In order to use the library within your application, ensure that either the installation 
directory is checked by the linker (for ld this is either /lib/ or /usr/lib/), or alternatively
ensure that the installation directory is present in $LD_LIBRARY_PATH. If using the shared 
object version, ensure that you provide -llac as an option to your compiler. If using GCC, you 
can specify the -L flag followed by the installation directory to have GCC check for files 
specified with -l.
