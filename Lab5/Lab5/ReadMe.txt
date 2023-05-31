Ethan Wu, Jasper Sands -- wue@wustl.edu, jaspersands@wustl.edu -- CSE 332 -- Lab 5

We split up the work by having Ethan do a majority of the initial function writing and Jasper doing some of the function writing and 
the debugging and testing.
All extra credit was Jasper

Errors:
- One of the main errors we encountered was within cat command--it was an out of bounds vector subscript, and it was due to us not
originally changing the read function of image file to just return its contents.
- We also didn't look for if the file addition was successful in copy command, which caused a unit test error.
- Additionally, as we tested, we realized that our LS wasn't quite working properly. We it uses tabs to space things, we needed to 
account for the 3 instances of words being < 8 chars, 8 < x < 16 chars, and > 16 chars.
- Other than this, we didn't have too many other errors when we actually got around to building the project

Test Cases:

Help:
	$   help
	cat
	cp
	ds
	ls
	macro
	rm
	tcmacro
	touch
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Help on a specific command:
	help touch
	Touch creates a file, touch can be invoked with the command: touch <filename> [-p]. (optional: use -p to indicate a password protected file.)
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Quit (it worked as expected):
	$   q 

Improper function name:
	$   text.txt
	There is no command with this name.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

LS with no commands:
	$   ls
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

LS with one command:
	$   ls
	text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

LS with three commands:
	$   ls
	image.img               image.txt
	text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

LS with a list of varying sizes:
	$   ls
	actualhugeimage.img     actuallybigimage.img
	image.img               newimage.img
	tex.txt                 text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

LS with -m:
$   ls -m
	actualhugeimage.img     image   0
	actuallybigimage.img    image   0
	image.img               image   0
	newimage.img            image   0
	tex.txt                 text    0
	text.txt                text    0
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Touch without .img or .txt:
	$   touch file.swag
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Touch with an already existing file:
	$   touch text.txt
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Touch with password protection:
	$   touch image.img -p
	What is the password?
	swag
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Touch with a proper file extension:
	$   touch text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Touch a previously created and deleted file:
	$   rm text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	image.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   touch text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	image.txt               text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Copy without proper command line arguments: 
	$   cp text.txt
	Could not copy file.
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Copy with proper command line (with ls after to check if the file is in the system):
	$   cp text.txt image
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	image.txt               text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Copy with the same name:
	$   cp text.txt text
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Ensure copy is a unique file:
	$   cp text.txt newtext
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds newtext.txt
	swiggitysw0ggity
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   cat newtext.txt
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	this is a new file yo
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds newtext.txt
	this is a new file yo
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds text.txt
	swiggitysw0ggity
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Remove non existent file:
	$   rm image
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Proper remove (with ls to check):
	$   rm image.img
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	image.txt               text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Remove a copy:
	$   cp newtext.txt newnew
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   rm newnew.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	image.txt               newtext.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Cat with no append and empty file and display to check:
	$   cat text.txt
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	swiggity
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds text.txt
	swiggity

Cat with image file and proper input:
	$   cat awesomeimage.img
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	X X X X X3
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds awesomeimage.img
	X X
	 X
	X X
	
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Cat with append with display to check:
	$   cat text.txt -a
	swiggity
	Enter data you would like to append to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	sw0ggity
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds text.txt
	swiggitysw0ggity

Cat with improper file name:
	$   cat imag.img
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.


Cat with no append on a non-empty file:
	$   ds newtext.txt
	swiggitysw0ggity
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   cat newtext.txt
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	this is a new file yo
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds newtext.txt
	this is a new file yo
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Cat append on image file:
	$   cat image.img -a
	X X X X X
	Enter data you would like to append to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	this shouldn't work
	:wq
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Cat quit with display check:
	$   cat text.txt -a
	swiggitysw0ggity
	Enter data you would like to append to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	im gonna delete this
	:q
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds text.txt
	swiggitysw0ggity
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Cat and display on a password protected file:
	$   cat protecc.txt
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	versace
	:wq
	Enter password:
	swag
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds protecc.txt
	Enter password:
	swag
	versace
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Display an empty file:
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds text.txt

Display without correct filename:
	$   ds tex.txt
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Display formatted image:
	$   ds image.img
	X X
	 X
	X X

Display image with -d:
	$   ds image.img -d
	X X X X X
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Rename Macro proper input:
	$   ls
	newimage.img            newtext.txt
	protecc.txt             text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   macro newimage.img actuallynewimage
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ls
	actuallynewimage.img    newtext.txt
	protecc.txt             text.txt
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

Rename Macro improper input:
	$   macro newimage actuallynewimage
	Could not copy file.
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

TouchCat Macro improper input:
	$   tcmacro fail.txy
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

TouchCat already existing file:
	$   tcmacro text.txt
	The command failed. Miserably.
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

TouchCat Macro standard input no password:
	$   tcmacro tex.txt
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	fancymacro
	:wq
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds tex.txt
	fancymacro
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.

TouchCat Macro with password:
	$   tcmacro pfile.txt -p
	What is the password?
	swog
	Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
	new file gang
	:wq
	Enter password:
	swog
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
	$   ds pfile.txt
	Enter password:
	swog
	new file gang
	Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.








EXTRA CREDIT

C:\Users\j.d.sands\source\repos\cse332s-sp22-wustl\oop_work-16-21ethanjasper\Lab5\x64\Debug>Lab5.exe
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   touch file.txt
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   chmod file.txt -
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
bob
;wq
:wq
The command failed. Miserably.
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   ds file.txt

Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   chmod file.txt +
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving
bob qf
:wq
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   ds file.txt
bob qf
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.





C:\Users\j.d.sands\source\repos\cse332s-sp22-wustl\oop_work-16-21ethanjasper\Lab5\x64\Debug>Lab5.exe
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   touch file.txt
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   chmod file.txt -
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$   chmod file.txt blah
The command failed. Miserably.
Please either enter a command, <q> to quit, <help> for a list of commands, or <help> followed by a command name for more information about that command.
$
