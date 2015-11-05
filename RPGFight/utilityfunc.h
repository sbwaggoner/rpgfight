#pragma once
#include <iostream>

using namespace std;
namespace ufunc {
  bool getYN(string message, string endval) {
    cout << message;

    string input;
    getline(cin, input);

    return input != endval;
  }

  string gen_string(string character, int length) {
    string str = "";
    for (int x = 0; x < length + 6; x++) {
      str += character;
    }
    return str + "\n";
  }

  string wrapText(string message) {
    string msg = gen_string("*", message.length());
    msg += "*  " + message + "  *\n";
    msg += gen_string("*", message.length());
    return msg + "\n";
  }
}