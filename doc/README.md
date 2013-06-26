% Txtw User's Guide
% Bastien Dejean
% June 26, 2013

# Synopsis

**txtw** [**-h**|**-v**|**-f** *FONT*|**-s** *SIZE*|**-F** *ALT\_FONT*|**-S** *ALT\_SIZE*] *STRING* ...

# Description

Returns the width in pixels of the given strings for the the given font.

# Options

`-h`
:    Print the synopsis to standard output and exit.

`-v`
:    Print the version information to standard output and exit.

`-f` *FONT*
:   Set the main font.

`-s` *SIZE*
:   Set the size of the main font.

`-F` *ALT\_FONT*
:   Set the alternate font.

`-S` *ALT\_SIZE*
:   Set the size of the alternate font.

# String Syntax

By default the main font is used to compute the width.

The alternate font is used for the parts of the string enclosed between *\\(* and *\\)*.

# Example

    txtw -f 'DejaVu Sans' -s 11 -F SimpleIcons -S 16 'One \(U\) Two \(D\) Three' 
