# SA-MP TextDraw String Width

[![sampctl](https://img.shields.io/badge/sampctl-samp--td--string--width-2f2f2f.svg?style=for-the-badge)](https://github.com/kristoisberg/samp-td-string-width)

**Notice:** This repository is not being actively maintained anymore. If anyone wishes to continue the development of the project, please create a fork of the repository and release future versions there.

About two years ago an user called Alcatrik came up with a concept of calculating the width of textdraw strings in [this thread](https://forum.sa-mp.com/showthread.php?t=618883). In those two years a few functions using this concept appeared in that thread, but all of them had major flaws. The first one by Crayder didn't include the first 32 characters of the ASCII table. The next one by Freaksten fixed that flaw, but neither of the functions also didn't take into account that there are four different textdraw fonts and just used the first array in `fonts.dat`.

About two or three months ago I needed a correct version of that function so I started digging into the data in `fonts.dat`. The first discovery I made is that fonts 2 and 3 are actually subfonts of fonts 0 and 1 (fun fact: you can actually access the characters of fonts 2 and 3 from fonts 0 and 1 by using values larger than 175 as characters). I manually reassembled the data into four arrays, but soon after that I temporarily abandoned the project I collected this data for.

A few days ago I mentioned the data I had collected and Y_Less sent me a [repository](https://github.com/On3d4y/TextDrawColour.inc) that contained a function that generated the same dataset automatically. I decided to compare the two datasets and found out that they had different widths for 16 characters, which I re-measured manually. Both got about half of the 16 widths right and half of them wrong.

Another mistake that all existing functions did was presuming that characters 1-31 are always rendered as regular whitespace. In reality, the widths of the invisible characters differed in font 2 and the characters in font 3 actually have two different widths. One of them is the visual width: most of the characters don't actually render as whitespace, instead of this you see either one or two stripes with varying widths. The other width is the "physical" width, which is either 0 (the stripes overlap with the next character or two) or a relatively large number, up to 255.

Now, after multiple days of work that contained manually reassembling data, manually measuring almost 100 characters and a lot more, this library is ready. What could it be used for? I personally needed this to calculate the width of buttons based on their strings. The previously mentioned repository uses code similar to this to achieve full colouring of textdraws. A few more usages can be found from the original topic explaining the concept.

## Installation

Simply install to your project:

```bash
sampctl package install kristoisberg/samp-td-string-width
```

Include in your code and begin using the library:

```pawn
#include <td-string-width>
```

## Usage

- `GetTextDrawCharacterWidth(character, font, bool:proportional = true)`
  - Returns the width of a single character.
- `GetTextDrawStringWidth(const string[], font, outline = 0, bool:proportional = true)`
  - Finds the longest line in the string and returns the width of it. Skips everything between `~` characters except `~n~`, which indicates the start of a new line. Odd number of `~` characters returns the width of "Error: unmatched tilde".
- `GetTextDrawLineWidth(const string[], font, outline = 0, bool:proportional = true)`
  - Works just like `GetTextDrawStringWidth`, but presumes that the string only contains one line. Skips `~n~` just like everything else between `~` characters.

## Testing

To test, simply run the package:

```bash
sampctl package run
```
