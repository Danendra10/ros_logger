#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include <map>

using namespace std;

namespace color {
const map<string, string> color_foreground = {
    {"Default", "39"},      {"Black", "30"},      {"Red", "31"},
    {"Green", "32"},        {"Yellow", "33"},     {"Blue", "34"},
    {"Magenta", "35"},      {"Cyan", "36"},       {"Light Gray", "37"},
    {"Dark Gray", "90"},    {"Light Red", "91"},  {"Light Green", "92"},
    {"Light Yellow", "93"}, {"Light Blue", "94"}, {"Light Magenta", "95"},
    {"Light Cyan", "96"},   {"White", "97"},
};

const map<string, string> color_background = {
    {"Default", "49"},       {"Black", "40"},       {"Red", "41"},
    {"Green", "42"},         {"Yellow", "43"},      {"Blue", "44"},
    {"Magenta", "45"},       {"Cyan", "46"},        {"Light Gray", "47"},
    {"Dark Gray", "100"},    {"Light Red", "101"},  {"Light Green", "102"},
    {"Light Yellow", "103"}, {"Light Blue", "104"}, {"Light Magenta", "105"},
    {"Light Cyan", "106"},   {"White", "107"},
};

const map<string, string> format_set = {
    {"Default", "0"}, {"Bold", "1"},    {"Dim", "2"},    {"Underlined", "4"},
    {"Blink", "5"},   {"Reverse", "7"}, {"Hidden", "8"},
};

const map<string, string> format_reset = {
    {"Default", "0"}, {"Bold", "21"},    {"Dim", "22"},    {"Underlined", "24"},
    {"Blink", "25"},  {"Reverse", "27"}, {"Hidden", "28"},
};

//=================================================================================================

string rize(string _text, string _color_foreground = "Default",
            string _color_background = "Default",
            string _format_set = "Default", string _format_reset = "Default") {
  if (color_foreground.find(_color_foreground) == color_foreground.end())
    _color_foreground = "Default";
  if (color_background.find(_color_background) == color_background.end())
    _color_background = "Default";
  if (format_set.find(_format_set) == format_set.end())
    _format_set = "Default";
  if (format_reset.find(_format_reset) == format_reset.end())
    _format_reset = "Default";

  string control_code = "\033[";

  return control_code + format_set.at(_format_reset) + ";" +
         color_foreground.at(_color_foreground) + ";" +
         color_background.at(_color_background) + "m" + _text + control_code +
         format_reset.at(_format_reset) + "m";
};

string rize(string _text, unsigned int _x, unsigned int _y,
            string _color_foreground = "Default",
            string _color_background = "Default",
            string _format_set = "Default", string _format_reset = "Default") {
  if (color_foreground.find(_color_foreground) == color_foreground.end())
    _color_foreground = "Default";
  if (color_background.find(_color_background) == color_background.end())
    _color_background = "Default";
  if (format_set.find(_format_set) == format_set.end())
    _format_set = "Default";
  if (format_reset.find(_format_reset) == format_reset.end())
    _format_reset = "Default";

  string control_code = "\033[";

  return control_code + to_string(_y) + ";" + to_string(_x) + "H" +
         control_code + format_set.at(_format_reset) + ";" +
         color_foreground.at(_color_foreground) + ";" +
         color_background.at(_color_background) + "m" + _text + control_code +
         format_reset.at(_format_reset) + "m";
};

} // namespace color

#endif // COLOR_H_
