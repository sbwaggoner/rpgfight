#pragma once
#include <iostream>

namespace ufunc {
  bool getYN(std::string message, std::string endval) {
    std::cout << message;

    std::string input;
    getline(std::cin, input);

    return input != endval;
  }

  std::string gen_string(std::string character, int length) {
    std::string str = "";
    for (int x = 0; x < length + 6; x++) {
      str += character;
    }
    return str + "\n";
  }

  std::string wrapText(std::string message) {
    std::string msg = gen_string("*", message.length());
    msg += "*  " + message + "  *\n";
    msg += gen_string("*", message.length());
    return msg + "\n";
  }
}