#ifndef _RAYLIB_SPDLOG_
#define _RAYLIB_SPDLOG_

#include <raylib.h>
#include <spdlog/spdlog.h>

namespace raylib_spdlog {

void SpdLogCallback(int msgType, const char *text, va_list args) {
  char buffer[512];
  vsnprintf(buffer, sizeof(buffer), text, args);

  switch (msgType) {
    case LOG_TRACE:
      spdlog::trace(buffer);
      break;
    case LOG_DEBUG:
      spdlog::debug(buffer);
      break;
    case LOG_INFO:
      spdlog::info(buffer);
      break;
    case LOG_WARNING:
      spdlog::warn(buffer);
      break;
    case LOG_ERROR:
      spdlog::error(buffer);
      break;
    case LOG_FATAL:
      spdlog::critical(buffer);
      break;
    default:
      spdlog::info("Unknown log level: [{}] {}", msgType, buffer);
      break;
  }
}

}  // namespace raylib_spdlog

#endif  // _RAYLIB_SPDLOG_
