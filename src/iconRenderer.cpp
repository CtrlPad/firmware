#include <Arduino.h>
#include <base64.hpp>
#include <lvgl.h>
#include <gui.h>

static uint8_t *decodeBase64(const String &encoded, size_t &outLen) {
  const unsigned char *input = (const unsigned char *) encoded.c_str();
  int inputLength = encoded.length();
  int decodedLen = decode_base64_length(input, inputLength);

  uint8_t *decoded = (uint8_t *) malloc(decodedLen);
  decode_base64(input, inputLength, decoded);

  outLen = decodedLen;
  return decoded;
}

void renderIcon(int target, String encodedIconString) {
  size_t len;
  uint8_t *pixels = decodeBase64(encodedIconString, len);
}
