# Change Log

v1.0.1

- Changed NullOStream so that NullBuffer is a member and changed logger.cpp
  so that CreateNullLogger() contains a static variable of type NullBuffer.
  These changes avoid issues with unpredictable static initialization order.

v1.0.0

- Initial Release
