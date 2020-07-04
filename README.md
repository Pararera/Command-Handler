# COMMAND HANDLER FOR ARDUINO

## ABOUT

This library contains functions for parsing commands from the C string. The library doesn't use dynamic memory allocation. 
Supported format is: `cmd1,param1,...,paramN;...;cmdN,...,paramN;` where `;` is command set separator, and `,` is command param separator.
See example sketches for better understanding of the library.

<br/><br/>

## INSTALLATION

<ul>
  <li>Download the library</li>
  <li>Extract files using WinRAR(or similar software) to location <i>C:\Users\{YOUR_USERNAME}\Documents\Arduino\libraries</i></li>
</ul>

<br/><br/>

## USING LIBRARY

In your sketch, at the top add `#include <CommandHandler.h>`. Somewhere below all include files, add `CMDHand {OBJECT_NAME}({CMD_SET_SEPARATOR},{CMD_PARAM_SEPARATOR});`
Recommended command set separator is `;`. Recommended command param separator is `,`.

<br/><br/>

## SETTINGS

There is no settings you can adjust.

<br/><br/>

## FUNCTIONS

### char *find(const char *input, uint8_t const type)

Finds command set or command param in given C string.

<b>Parameters</b>
<ul>
  <li><b>*input</b> - Memory address of first character. C string has to be NULL terminated.</li>
  <li><b>type</b> - <i>CMD_SET</i> for command set, <i>CMD_PARAM</i> for command param.</li>
</ul>

<b>Return</b>
<ul>
  <li>Address of first character</li>
</ul>

<br/>

### uint8_t count(const char *input, uint8_t const type)

Counts number of command sets, or command params in given C string.

<b>Parameters</b>
<ul>
  <li><b>*input</b> (optional) - Memory address of first character. C string has to be NULL terminated.
If not provided, function will use <i>next</i> memory address for selected <i>type</i>.</li>
  <li><b>type</b> - <i>CMD_SET</i> for command set, <i>CMD_PARAM</i> for command param.</li>
</ul>

<b>Return</b>
<ul>
  <li>Number of command sets, or command params</li>
</ul>

<br/>

### char *getNext(uint8_t const type)

Returns memory address of next command set, or command param.

<b>Parameters</b>
<ul>
  <li><b>type</b> - <i>CMD_SET</i> for command set, <i>CMD_PARAM</i> for command param.</li>
</ul>

<b>Return</b>
<ul>
  <li>Memory of <i>next</i> selected <i>type</i></li>
</ul>

<br/>

### char *getNext(uint8_t const type)

Returns memory address of last command set, or command param found in `find` function.

<b>Parameters</b>
<ul>
  <li><b>type</b> - <i>CMD_SET</i> for command set, <i>CMD_PARAM</i> for command param.</li>
</ul>

<b>Return</b>
<ul>
  <li>Memory of <i>last</i> selected <i>type</i></li>
</ul>

<br/><br/>

## KNOWN ISSUES

There is no known issues. If you find issue, open new issue at GitHub.
