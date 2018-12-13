#include <a_samp>
#tryinclude <PawnPlus>


static const TDCharacterDefaultWidth[4] = {27, 20, 27, 20};

static const TDCharacterWidth[4][176] = {
	{
		 0,  12,  12,  12,  12,  12,  12,  12,
		12,  12,  12,  12,  12,  12,  12,  12,
		12,  12,  12,  12,  12,  12,  12,  12,
		12,  12,  12,  12,  12,  12,  12,  12,
		12,  13,  13,  28,  28,  28,  28,   8,
		17,  17,  30,  28,  28,  12,   9,  21, 
		28,  14,  28,  28,  28,  28,  28,  28,
		28,  28,  13,  13,  30,  30,  30,  30, 
		10,  25,  23,  21,  24,  22,  20,  24, 
		24,  17,  20,  22,  20,  30,  27,  27,
		26,  26,  24,  23,  24,  31,  23,  31, 
		24,  23,  21,  28,  33,  33,  14,  28,  
		10,  11,  12,   9,  11,  10,  10,  12,  
		12,   7,   7,  13,   5,  18,  12,  10, 
		12,  11,  10,  12,   8,  13,  13,  18,  
		17,  13,  12,  30,  30,  37,  35,  37,  
		25,  25,  25,  25,  33,  21,  24,  24,	
		24,  24,  17,  17,  17,  17,  27,  27,	
		27,  27,  31,  31,  31,  31,  11,  11,	
		11,  11,  11,  20,   9,  10,  10,  10,	
		10,   7,   7,   7,   7,  10,  10,  10,
		10,  13,  13,  13,  13,  27,  12,  30	
	}, {
		 0,  15,  15,  15,  15,  15,  15,  15,
		15,  15,  15,  15,  15,  15,  15,  15,
		15,  15,  15,  15,  15,  15,  15,  15,
		15,  15,  15,  15,  15,  15,  15,  15,
		15,   9,  17,  27,  20,  34,  23,  12,	
		12,  12,  21,  20,  12,  14,  12,  15,
		23,  15,  21,  21,  21,  21,  21,  21,	
		20,  21,  12,  12,  24,  24,  24,  19,
		10,  22,  19,  19,  22,  16,  19,  24,	
		22,  11,  16,  21,  15,  28,  24,  27,
		20,  25,  19,  19,  18,  23,  23,  31,	
		23,  19,  21,  21,  13,  35,  11,  21,
		10,  19,  20,  14,  20,  19,  13,  20,
		19,   9,   9,  19,   9,  29,  19,  21,
		19,  19,  15,  15,  14,  18,  19,  27,
		20,  20,  17,  21,  17,  20,  15,  15,
		22,  22,  22,  22,  29,  19,  16,  16,
		16,  16,  11,  11,  11,  11,  27,  27,
		27,  27,  23,  23,  23,  23,  20,  19,
		19,  19,  19,  30,  14,  19,  19,  19,
		19,   9,   9,   9,   9,  21,  21,  21,
		21,  18,  18,  18,  18,  24,  19,  19	
	}, {
		 0,  15,  23,  15,  21,  21,  21,  21,
		21,  21,  20,  21,  12,  12,  24,  24,
		24,  19,  10,  22,  19,  19,  22,  16,
		19,  24,  22,  11,  16,  21,  15,  28,
		12,  13,  13,  28,  37,  28,  30,   8,
		17,  17,  30,  28,  28,  12,   9,  21,
		27,  16,  27,  27,  27,  27,  27,  27,
		27,  27,  18,  13,  30,  30,  30,  30, 
		10,  29,  26,  25,  28,  26,  25,  27,  
		28,  12,  24,  25,  24,  30,  27,  29, 
		26,  26,  25,  26,  25,  26,  28,  32,
		27,  26,  26,  28,  33,  33,  10,  28,
		10,  29,  26,  25,  28,  26,  25,  27, 
		28,  12,  24,  25,  24,  30,  27,  29, 
		26,  26,  25,  26,  25,  26,  28,  32,  
		27,  26,  26,  30,  30,  37,  35,  37, 
		29,  29,  29,  29,  33,  25,  26,  26,	
		26,  26,  14,  14,  14,  14,  29,  29,
		29,  29,  26,  26,  26,  26,  21,  29,
		29,  29,  29,  33,  25,  26,  26,  26,
		26,  14,  14,  14,  14,  29,  29,  29,	
		29,  26,  26,  26,  26,  25,  25,  30
	}, {
		 0,   9,   9,  18,  18,  18,  18,  18,
		18,  18,  18,  19,  19,  19,   0,   9,
		 9,   9,   9,  18,  18,  18,  18,  18,
		18,  18,  18,  19,  19,  19,   0,   9,
		15,  10,  17,  27,  20,  34,  23,  10,
		15,  15,  21,  20,  12,  14,   9,  15,
		20,  18,  19,  19,  21,  19,  19,  19,
		19,  19,  16,  12,  24,  24,  24,  21,
		10,  19,  19,  19,  20,  19,  16,  19,
		19,   9,  19,  20,  14,  29,  19,  19,
		19,  19,  19,  19,  21,  19,  20,  32,	
		21,  19,  19,  21,  13,  35,  10,  21,
		10,  19,  19,  19,  20,  19,  16,  19,	
		19,   9,  19,  20,  14,  29,  19,  19,
		19,  19,  19,  19,  21,  19,  20,  32,	
		21,  19,  19,  21,  17,  20,  15,  15,
		19,  19,  19,  19,  29,  19,  19,  19,
		19,  19,   9,   9,   9,   9,  19,  19,
		19,  19,  19,  19,  19,  19,  19,  19,
		19,  19,  19,  29,  19,  19,  19,  19,
		19,   9,   9,   9,   9,  19,  19,  19,
		19,  19,  19,  19,  19,  21,  21,  19
	}
};

static const TDFont3CharacterInlineWidth[32] = {
     0, 255,   0,   0, 128,  63, 147,  36,
    19,  64,   0,   0,   0,   0,   0,   0,
    32,  68,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0
};


stock GetTextDrawCharacterWidth(character, font, bool:proportional = true) {
	if (!(0 <= font <= 3) || !(0 <= character < 176)) {
		return 0;
	}

	new width;

	if (!proportional || character >= sizeof(TDCharacterWidth[])) {
		width = TDCharacterDefaultWidth[font];
	} else {
		width = TDCharacterWidth[font][character];
	}

	return width;
}


stock GetTextDrawStringWidth(const string[], font, outline = 0, bool:proportional = true) {
    new other, result, width;

    for (new i, length = strlen(string); i < length; i++) {
        if (string[i] == '~') {
            if ((other = strfind(string, "~", .pos = i + 1)) == -1) {
                return GetTextDrawLineWidth("Error: unmatched tilde", font, outline, proportional);
            }

            if (other == i + 2 && string[i + 1] == 'n') {
                if (result < width) {
                    result = width;
                }

                width = 0;
            } 

            i = other + 1;
        } else {
            if (font == 3 && (0 < string[i] < 32) && i != length - 1 && strfind(string, "~n~", .pos = i + 1) != i + 1) {
                width += TDFont3CharacterInlineWidth[string[i]];
            } else {
                width += GetTextDrawCharacterWidth(string[i], font, proportional);
            }
        }
    }

    if (result < width) {
        result = width;
    }

    return result + (outline * 2);
}


stock GetTextDrawLineWidth(const string[], font, outline = 0, bool:proportional = true, start = 0, end = -1) {
    new other, width;

	if (end == -1) {
		end = strlen(string);
	}

    for (; start < end; start++) {
        if (string[start] == '~') {
            if ((other = strfind(string, "~", .pos = start + 1)) == -1) {
                return GetTextDrawLineWidth("Error: unmatched tilde", font, outline, proportional);
            }

            start = other + 1;
        } else {
            if (font == 3 && (0 < string[start] < 32) && start != end - 1) {
                width += TDFont3CharacterInlineWidth[string[start]];
            } else {
                width += GetTextDrawCharacterWidth(string[start], font, proportional);
            }
        }
    }

    return width + (outline * 2);
}


stock GetTextDrawLineCount(const string[]) {
	new count = 1, pos = -3;

	while ((pos = strfind(string, "~n~", true, pos + 3)) != -1) {
		count++;
	}

	return count;
}


static stock _SplitTryToReplace(string[], Float:max_width, Float:letter_size, font, outline, bool:proportional, line_start, previous_space, size, pos, length) {
	if (letter_size * float(GetTextDrawLineWidth(string, font, outline, proportional, line_start, pos)) <= max_width) {
		return 0;
	}

	if (previous_space != -1) {
		if (length + 2 < size) {
			strdel(string, previous_space, previous_space + 1);
			strins(string, "~n~", previous_space, size);
			return 1;
		}

		return -1;
	}

	// todo: splitting long words (with a separate size check of course), return value 2
	return 0;
}


stock bool:SplitTextDrawString(string[], Float:max_width, Float:letter_size, font, outline = 0, bool:proportional = true, size = sizeof(string)) {
	new other, line_start, previous_space = -1, length = strlen(string);

	for (new i; i < length; ) {
		switch (string[i]) {
			case '~': {
				if ((other = strfind(string, "~", .pos = i + 1)) == -1) {
					return false;
				}

				if (other == i + 2 && string[i + 1] == 'n') {
					switch (_SplitTryToReplace(string, max_width, letter_size, font, outline, proportional, line_start, previous_space, size, i, length)) {
						case -1: {
							return true;
						}

						case 1: {
							i += 5;
							length += 2;
							previous_space = -1;
						}

						case 0: {
							i += 3;
						}
					}

					line_start = i;
				} else {
					i = other + 1;
				}
			}

			case ' ': {
				switch (_SplitTryToReplace(string, max_width, letter_size, font, outline, proportional, line_start, previous_space, size, i, length)) {
					case -1: {
						return true;
					}

					case 1: {
						i += 3;
						length += 2;
						line_start = previous_space + 3;
						previous_space = i - 1;
					}

					case 0: {
						previous_space = i;
						i++;
					}
				}
			}

			default: {
				i++;
			}
		}
	}

	_SplitTryToReplace(string, max_width, letter_size, font, outline, proportional, line_start, previous_space, size, length, length);
	return true;
}


#if defined _PawnPlus_included
	stock GetTextDrawStringWidth_s(String:string, font, outline = 0, bool:proportional = true) {
		new ref[1][] = {{}}, size = str_len(string) + 1, Var:var = amx_alloc(size, false);

		amx_to_ref(var, ref);
		str_get(string, ref[0], size);

		new result = GetTextDrawStringWidth(ref[0], font, outline, proportional);

		amx_free(var);
		amx_delete(var);
		return result;
	}


	stock GetTextDrawLineWidth_s(String:string, font, outline = 0, bool:proportional = true, start = 0, end = -1) {
		new ref[1][] = {{}}, size = str_len(string) + 1, Var:var = amx_alloc(size, false);

		amx_to_ref(var, ref);
		str_get(string, ref[0], size);

		new result = GetTextDrawLineWidth(ref[0], font, outline, proportional, start, end);

		amx_free(var);
		amx_delete(var);
		return result;
	}


	stock GetTextDrawLineCount_s(String:string) {
		new ref[1][] = {{}}, size = str_len(string) + 1, Var:var = amx_alloc(size, false);

		amx_to_ref(var, ref);
		str_get(string, ref[0], size);

		new result = GetTextDrawLineCount(ref[0]);

		amx_free(var);
		amx_delete(var);
		return result;
	}


	stock bool:SplitTextDrawString_s(String:string, Float:max_width, Float:letter_size, font, outline = 0, bool:proportional = true) {
		new ref[1][] = {{}}, temp = (str_len(string) + 1) * 2, size = 1;
		
		while (size < temp) {
			size *= 2;
		}

		new Var:var = amx_alloc(size, false);

		amx_to_ref(var, ref);
		str_get(string, ref[0], size);

		new bool:result = SplitTextDrawString(ref[0], max_width, letter_size, font, outline, proportional, size);

		str_set_format(string, ref[0]);

		amx_free(var);
		amx_delete(var);
		return result;
	}
#endif